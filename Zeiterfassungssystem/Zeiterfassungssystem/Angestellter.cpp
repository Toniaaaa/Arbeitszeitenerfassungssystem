#include "Angestellter.h"

Angestellter::Angestellter(String ^ vorname, String ^ nachname, Abteilung ^ abteilung, String ^ personalnummer, String ^ passwort, Int32 wochenstunden, Int32 urlaubstage)
{
	this->vorname = vorname;
	this->nachname = nachname;
	this->abteilung = abteilung;
	this->personalnummer = personalnummer;
	this->passwort = passwort;
	this->wochenstunden = wochenstunden;
	this->urlaubstage = urlaubstage;
	this->urlaubstageGespart = 0;
	listeEreignisse = gcnew List<Ereignis^>;
	listegesamtstunden = gcnew List<Double>;
	antragsInfos = gcnew List<String^>;
	this->wochenZeitErreicht = false;
	this->arbeitsStunden = wochenstunden;
	this->arbeitsMinuten = 0;
	this->ueberStunden = 0;
	this->ueberMinuten = 0;
	this->ueberStundenGesamt = 0.0;
	this->listeUrlaubstage = gcnew List<FreierTag^>;
	this->letzterLogin = DateTime::Now;
	this->kalender = gcnew Kalender();
	this->jahresurlaub = urlaubstage;
	this->vergleichen = gcnew FreierTagComparer;
}

//Gibt den restlichen Jahresurlaub zur�ck, den der Angestellte noch nicht eingereicht hat.
Int32 Angestellter::getRestUrlaub() 
{
	Int32 urlaubstageDiesesJahr = 0;
	//Die Urlaubstage, die f�r dieses Jahr schon verplant sind, werden gez�hlt.
	for (int i = 0; i < listeUrlaubstage->Count; i++) {
		if (listeUrlaubstage[i]->getDatum().Year == DateTime::Now.Year) {
			urlaubstageDiesesJahr++;
		}
	}
	return urlaubstage - urlaubstageDiesesJahr;
}

//Fuegt der Liste von Ereignissen ein Ereignis hinzu
void Angestellter::fuegeEreignisHinzu(Ereignis^ ereignis)
{
	listeEreignisse->Add(ereignis);
}

void Angestellter::removeEreignis(Int32 index)
{
	listeEreignisse->RemoveAt(index);
}

//Fuegt der Liste von Antragsinfos eine Info hinzu
void Angestellter::addAntragsInfo(String^ info)
{
	antragsInfos->Add(info);
}

void Angestellter::removeAntragsInfo(Int32 index)
{
	antragsInfos->RemoveAt(index);
}

//Gibt die DateTime des Arbeitanfangs zur�ck, falls der Arbeitstag noch nicht beendet wurde. Sonst wird der nullptr zur�ckgegeben.
DateTime ^ Angestellter::getArbeitsAnfang()
{
	Int32 index = getArbeitsAnfangIndex();
	if (index != -1) {
		return listeEreignisse[index]->getTimestamp();
	}
	else {
		return nullptr;
	}
}

//Gibt den TimeStamp (DateTime) des Pausenstarts zur�ck, falls gerade eine Pause l�uft, sonst nullptr zur�ck.
DateTime ^ Angestellter::getPauseAnfang()
{
	DateTime^ pauseanfang = nullptr;
	//Wenn letztes Ereignis in der liste pausestart ist dann gebe davon den TimeStamp zurueck
	if (getAnzahlEreignisse() > 0 && listeEreignisse[getAnzahlEreignisse() - 1]->getTyp() == PAUSE_START) {
		pauseanfang = listeEreignisse[getAnzahlEreignisse() - 1]->getTimestamp();
	}
	return pauseanfang;
}

//Gibt die aktuelle Arbeitszeit zurueck, berechnet durch differenz von Now und arbeitsanfangszeitpunkt, pausen werden mit abgezogen.
TimeSpan ^ Angestellter::getAktuelleArbeitszeit()
{
	//berechnet anhand des Arbeitsanfang index die aktuelle Arbeitszeit bis zu dem Aufruf zeitpunkt
	Int32 arbeitsanfang = getArbeitsAnfangIndex();

	//Wenn es einen Arbeitsanfang gibt dann ziehe von dem aktuellen Zeitstempel den arbeitsanfang ab
	TimeSpan^ result = nullptr;
	if (arbeitsanfang != -1) {
		result = DateTime::Now - *(listeEreignisse[arbeitsanfang]->getTimestamp());

		//Zudem noch die Pausezeit abziehen
		TimeSpan^ pause = getPausezeit();
		result = TimeSpan::operator-(*result, *pause);
	}
	return result;
}

//Gibt die aktuelle Pausenzeit ab Pausenanfang zurueck ansonsten nullptr
TimeSpan ^ Angestellter::getAktuellePausenzeit()
{
	//gibt akuelle Pausenzeit zurueck
	return DateTime::Now - *getPauseAnfang();
}

//Berechnet die gesamtzeit der Pausen des aktuellen Arbeitstags und gibt diese als TimeSpan zur�ck
TimeSpan ^ Angestellter::getPausezeit()
{
	Int32 index = getArbeitsAnfangIndex();
	TimeSpan^ result = nullptr;

	//wenn es einen Index gibt dann erstelle neuen TimeSpan
	if (index != -1) {
		result = gcnew TimeSpan();

		//Naechster Pausenstart wird gesucht und zwischengespeichert
		DateTime^ pausestart = nullptr;
		for (int i = index + 1; i < getAnzahlEreignisse(); i++) {
			if (listeEreignisse[i]->getTyp() == PAUSE_START) {
				pausestart = listeEreignisse[i]->getTimestamp();
			}
			//Wenn Pauseende vorhanden dann berechne Gesamtpause
			else if (listeEreignisse[i]->getTyp() == PAUSE_ENDE) {
				TimeSpan^ pause = *(listeEreignisse[i]->getTimestamp()) - *(pausestart);
				result = TimeSpan::operator+(*result, *pause);
				pausestart = nullptr;
			}
		}

		//hier wird die aktuelle zeit bis zum aufrufzeitpunkt berechnet wenn noch kein pausenende
		if (pausestart != nullptr) {
			TimeSpan^ pause = DateTime::Now - *(pausestart);
			result = TimeSpan::operator+(*result, *pause);
		}
	}
	return result;
}

//Berechnet die gesamte Arbeitszeit ab bestimmten Arbeitsanfangs (anfangsEreignisIndex) bis zum Ende dieses Tages und gibt sie als TimeSpan zur�ck.
TimeSpan ^ Angestellter::berechneArbeitsstunden(Int32 anfangsEreignisIndex)
{
	//der anfang ist das DateTime beim uebergebenen anfangsindex
	DateTime^ anfang = listeEreignisse[anfangsEreignisIndex]->getTimestamp();
	TimeSpan^ gesamtPause = gcnew TimeSpan();
	//ende erstmal auf now
	DateTime^ ende = DateTime::Now;

	DateTime^ pausestart = nullptr;

	//wenn noch kein pausenende  vorhanden dann nehme TimeStamps aus Liste und nehme das als ende
	for (int i = anfangsEreignisIndex + 1; i < getAnzahlEreignisse(); i++) {
		if (listeEreignisse[i]->getTyp() == PAUSE_START) {
			pausestart = listeEreignisse[i]->getTimestamp();
		}
		//wenn pause ende vorhanden dann berechne gesamtpause
		else if (listeEreignisse[i]->getTyp() == PAUSE_ENDE) {
			TimeSpan^ pause = *(listeEreignisse[i]->getTimestamp()) - *(pausestart);
			gesamtPause = TimeSpan::operator+(*gesamtPause, *pause);
			pausestart = nullptr;
		}
		//stopp wenn arbeitsende gefunden
		else if (listeEreignisse[i]->getTyp() == ARBEIT_ENDE) {
			ende = listeEreignisse[i]->getTimestamp();
			break;
		}
	}

	//wenn es einen pausenstart gibt dann berechne pause mit ende als endpunkt
	if (pausestart != nullptr) {
		TimeSpan^ pause = *ende - *pausestart;
		gesamtPause = TimeSpan::operator+(*gesamtPause, *pause);
	}
	//gebe berechnete zeit zurueck
	return TimeSpan::operator-(*ende - *anfang, *gesamtPause);
}

/*Sucht den Index des letzten Arbeitsanfangs (also letztes Ereignis ARBEIT_START) in der Ereignisliste und gibt sie zur�ck, falls der Arbeitstag noch
* nicht beendet wurde und gibt diesen zur�ck. Ansonsten wird -1 zur�ckgegeben.
*/
Int32 Angestellter::getArbeitsAnfangIndex()
{
	//Zu anfang index -1 
	Int32 arbeitsanfang = -1;
	//durchlaufe liste rueckwaerts wenn letztes ereignis arbeitsende dann stopp
	for (int i = getAnzahlEreignisse() - 1; i >= 0; i--) {
		if (listeEreignisse[i]->getTyp() == ARBEIT_ENDE) {
			break;
		}
		//wenn letztes ereignis arbeitsstart dann gebe den index zurueck
		if (listeEreignisse[i]->getTyp() == ARBEIT_START) {
			arbeitsanfang = i;
			break;
		}
	}
	return arbeitsanfang;
}

/*Sucht den Index des Arbeitsanfangs (also Ereignis ARBEIT_START) des letzten BEENDETEN Arbeitstages in der Ereignisliste und gibt diesen zur�ck. 
Ansonsten wird -1 zur�ckgegeben.*/
Int32 Angestellter::getArbeitsAnfangIndexNachArbeitstag()
{
	//Zu anfang index -1 
	Int32 arbeitsanfang = -1;
	//durchlaufe liste rueckwaerts wenn letztes ereignis arbeitsende dann stopp
	for (int i = getAnzahlEreignisse() - 2; i >= 0; i--) {
		if (listeEreignisse[i]->getTyp() == ARBEIT_ENDE) {
			break;
		}
		//wenn letztes ereignis arbeitsstart dann gebe den index zurueck
		if (listeEreignisse[i]->getTyp() == ARBEIT_START) {
			arbeitsanfang = i;
			break;
		}
	}
	return arbeitsanfang;
}

//Zeiht die Arbeitszeit des letzten beendeten Arbeitstags von der WochenArbeitszeit ab.
void Angestellter::speichereArbeitszeit()
{
	Int32 arbeitsAnfangHeute = getArbeitsAnfangIndexNachArbeitstag();
	TimeSpan^ arbeitsZeitHeute = berechneArbeitsstunden(arbeitsAnfangHeute);
	zieheZeitAb(arbeitsZeitHeute->Hours, arbeitsZeitHeute->Minutes);
}

void Angestellter::setUeberstundenGesamt(Int32 stunden, Int32 minuten) 
{
	ueberStundenGesamt += stunden + (minuten / 60);
}

/*Tr�gt alle Tage innerhalb der Zeitspanne, die kein Wochenende oder Feiertage sind und noch nicht in der Liste der Urlaubstage stehen, 
in die Liste der Urlaubstage ein.*/
void Angestellter::nehmeUrlaub(DateTime beginn, DateTime ende, List<FreierTag^>^ feiertage)
{
	while (beginn <= ende) {
		//Pr�fe, ob dieser Tag bereits ein Feiertag ist
		Boolean istFeiertag = false;
		for (int i = 0; i < feiertage->Count; i++) {
			if (beginn == feiertage[i]->getDatum()) {
				istFeiertag = true;
				break;
			}
		}
		//Pr�fe, ob dieser Tag bereits ein genommener Urlaubstag ist
		Boolean istUrlaubstag = false;
		for (int i = 0; i < listeUrlaubstage->Count; i++) {
			if (beginn == listeUrlaubstage[i]->getDatum()) {
				istUrlaubstag = true;
				break;
			}
		}
		//Pr�fe, ob dieser Tag ein Samstag oder Sonntag ist
		if (!istFeiertag && !istUrlaubstag && beginn.DayOfWeek != DayOfWeek::Saturday && beginn.DayOfWeek != DayOfWeek::Sunday) {
			//Tag wird der Liste hinzugef�gt und ein Tag den genommenen Urlaubstagen hinzugef�gt.
			listeUrlaubstage->Add(gcnew FreierTag(beginn));
			if (urlaubstageGespart > 0) {
				urlaubstageGespart--;
			}
		}
		beginn = beginn.AddDays(1.0);
	}
}

//Berechnet die Anzahl der Tage in einem Intervall ohne Wochenenden und Feiertage
Int32 Angestellter::berechneUrlaubstage(DateTime beginn, DateTime ende, List<FreierTag^>^ feiertage)
{
	Int32 anzUrlaubstage = 0;

	while (beginn <= ende) {
		//Pr�fe, ob dieser Tag bereits ein Feiertag ist
		Boolean istFeiertag = false;
		for (int i = 0; i < feiertage->Count; i++) {
			if (beginn == feiertage[i]->getDatum()) {
				istFeiertag = true;
				break;
			}
		}
		//Pr�fe, ob dieser Tag bereits ein genommener Urlaubstag ist
		Boolean istUrlaubstag = false;
		for (int i = 0; i < listeUrlaubstage->Count; i++) {
			if (beginn == listeUrlaubstage[i]->getDatum()) {
				istUrlaubstag = true;
				break;
			}
		}
		//Pr�fe, ob dieser Tag ein Samstag oder Sonntag ist
		if (!istFeiertag && !istUrlaubstag && beginn.DayOfWeek != DayOfWeek::Saturday && beginn.DayOfWeek != DayOfWeek::Sunday) {
			//Tag wird der Liste hinzugef�gt und ein Tag den genommenen Urlaubstagen hinzugef�gt.
			anzUrlaubstage++;
		}
		beginn = beginn.AddDays(1.0);
	}

	return anzUrlaubstage;
}

//F�gt der Liste der Urlaubstage einen Tag (DateTime) hinzu.
void Angestellter::addUrlaubstag(DateTime tag)
{
	//F�gt einen neuen Urlaubstag mit dem �bergebenen Datum hinzu... 
	listeUrlaubstage->Add(gcnew FreierTag(tag));
	//...und sortiert die Liste der Urlaubstage nach dem Datum der Urlaubstage
	listeUrlaubstage->Sort(vergleichen);
}

//Entfernt einen bestimmten Urlaubstag, dessen Datum mit der �bergebenen DateTime �bereinstimmt, aus der Liste der Urlaubstage
void Angestellter::removeUrlaubstag(DateTime tag)
{
	for (int i = listeUrlaubstage->Count - 1; i >= 0; i--) {
		if (listeUrlaubstage[i]->getDatum() == tag) {
			listeUrlaubstage->RemoveAt(i);
			break;
		}
	}
}

//Loescht ALLE Eintr�ge aus der Liste der Urlaubstage
void Angestellter::loescheAlleUrlaubstage()
{
	for (int i = listeUrlaubstage->Count - 1; i >= 0; i--) {
		listeUrlaubstage->RemoveAt(i);
	}
}

//Pr�ft, ob das Datum eines Eintrag in der Liste der Urlaubstage mit der �bergebenen DateTime �bereinstimmt. 
Boolean Angestellter::istUrlaubstag(DateTime tag)
{
	Boolean istUrlaubstag = false;
	for (int i = listeUrlaubstage->Count - 1; i >= 0; i--) {
		if (listeUrlaubstage[i]->getDatum() == tag) {
			istUrlaubstag = true;
			break;
		}
	}
	return istUrlaubstag;
}

//Gibt den Index eines Urlaubstags zur�ck, falls dieser in der Liste der Urlaubstage vorhanden ist.
Int32 Angestellter::indexVon(DateTime tag)
{
	Int32 index = -1;
	for (int i = listeUrlaubstage->Count - 1; i >= 0; i--) {
		if (listeUrlaubstage[i]->getDatum().Date == tag) {
			index = i;
			break;
		}
	}
	return index;
}

//Pr�ft, ob der angestellte in dieser Woche bereits eingeloggt war, indem die Kalenderwoche des letzten Logins mit der KW von heute verglichen wird.
Boolean Angestellter::dieseWocheEingeloggt() {
	Boolean eingeloggt = false;
	if (kalender->berechneKW(letzterLogin) == kalender->berechneKW(DateTime::Today)) {
		eingeloggt = true;
	}
	return eingeloggt;
}

//Zieht die �bergebene Anzahl von Stunden und Minuten von der noch offenen WochenArbeitszeit ab.
void Angestellter::zieheZeitAb(Int32 stunden, Int32 minuten) {

	TimeSpan zeit = getReduzierteZeit(stunden, minuten);
	wochenZeitErreicht = zeit.Seconds;

	if (wochenZeitErreicht) {
		ueberStunden = zeit.Hours + 24 * zeit.Days;
		ueberMinuten = zeit.Minutes;
		arbeitsStunden = 0;
		arbeitsMinuten = 0;
	}
	else {
		arbeitsMinuten = zeit.Minutes;
		arbeitsStunden = zeit.Hours + 24 * zeit.Days;
	}
}

/*Gibt eine um die angegebenen Stunden und Minuten reduzierte Arbeitszeit zur�ck, ohne diese zu ver�ndern. 
Wenn die Wochenarbeitszeit erreicht wird, werden die Ueberstunden zur�ckgegeben, au�erdem wird Sekunde = 1, sonst immer 0.*/
TimeSpan Angestellter::getReduzierteZeit(Int32 stunden, Int32 minuten) {
	
	TimeSpan^ reduzierteZeit;
	Int32 arbeitsStd = arbeitsStunden;
	Int32 arbeitsMin = arbeitsMinuten;
	Int32 ueberStd = ueberStunden;
	Int32 ueberMin = ueberMinuten;

	/*1. Fall: Es wurden bereits �berstunden gez�hlt (also Wochen-Arbeitszeit war schon erreicht). Die �bergebenen Stunden und Minuten 
	werden von den �berstunden subtrahiert.*/
	if (wochenZeitErreicht) {
		ueberStd -= stunden;
		if (ueberMin - minuten < 0) {
			ueberStd--;
			ueberMin = ueberMin - minuten + 60;
		}
		else {
			ueberMin -= minuten;
		}
		if (ueberStd >= 0) {
			reduzierteZeit = reduzierteZeit = gcnew TimeSpan(ueberStd, ueberMin, 1);
		}
		//2. Fall: Die Wochen-Arbeitszeit wurde durch den Zeitabzug doch nicht mehr erreicht
		else {
			arbeitsStd = -ueberStd - 1; //-1, weil die Arbeitsstunden von 00:00 auf 1:01 springen. Mit -1 ist das korrigiert.
			arbeitsMin = (ueberMin == 0) ? 0 : 60 - ueberMin;
			reduzierteZeit = gcnew TimeSpan(arbeitsStd, arbeitsMin, 0);
		}
	}
	//3. Fall: Es wurden noch keine �berstunden gez�hlt (also Wochen-Arbeitszeit noch nicht erreicht)
	else {
		arbeitsStd -= stunden;
		if (arbeitsMin - minuten < 0) {
			arbeitsStd--;
			arbeitsMin = arbeitsMin - minuten + 60;
		}
		else {
			arbeitsMin -= minuten;
		}
		if (arbeitsStd >= 0) {
			reduzierteZeit = gcnew TimeSpan(arbeitsStd, arbeitsMin, 0);
		}
		//Fall: Die Wochen-Arbeitszeit wurde durch den Zeitabzug erreicht
		else {
			ueberStd = -arbeitsStd - 1; //-1, weil die Arbeitsstunden von 00:00 auf 1:01 springen. Mit -1 ist das korrigiert.
			ueberMin = (arbeitsMin == 0) ? 0 : 60 - arbeitsMin;
			reduzierteZeit = gcnew TimeSpan(ueberStd, ueberMin, 1);
		}
	}

	return *reduzierteZeit;
}

/*Wenn eine neues Jahr startet, werden die Urlaubstage zurueckgesetzt. Resturlaub aus dem vergangenen Jahr wird 3 Monate lang gespeichert
und kann noch genommen werden.*/
void Angestellter::stelleUraubstageZurueck(Int32 jahre)
{
	DateTime^ heute = DateTime::Today;

	//Wenn seit dem letzten Arbeitstag ein neues Jahr angefangen hat
	if (letzterLogin.Year > heute->Year) {
		//Urlaubstage verfallen nach 3 Monaten
		urlaubstageGespart = this->getRestUrlaub();
		urlaubstage = jahresurlaub + urlaubstageGespart;

		//Gespeicherte Arbeitszeiten verfallen nach angegebener Zahl Jahren
		Int32 i = 0;
		//Kein Exception-Handling notwendig, da letzterLogin kein Nullpointer sein kann (siehe oben) und daher auch schon mindesten ein Ereignis existieren muss.
		while (heute->Year - this->getEreignis(i)->getTimestamp()->Year > jahre) {
			this->removeEreignis(i);
			i++;
		}
	}

	//Urlaubstage, die aus dem letzten Jahr stammen, verfallen, wenn sie nicht bis M�rz genommen wurden
	if (urlaubstageGespart != 0 && heute->Month >= 4) {
		urlaubstage -= urlaubstageGespart;
		urlaubstageGespart = 0;
	}
}

// Wenn eine neue Woche startet, wird die Arbeitszeit zurueckgesetzt
void Angestellter::neueWoche()
{
	//Pr�fen, ob sich der Angestellte in dieser Woche schon eingeloggt hat. Wenn nicht: Zur�cksetzen der Wochen-Arbeitszeit, da eine neue Woche begonnen hat.
	if (!this->dieseWocheEingeloggt()) {
		//Wenn der Mitarbeiter in der letzten Woche seine Arbeitszeit nicht erreicht hat, wird ihm das von seinen �berstunden wieder abgezogen
		if (!wochenZeitErreicht) {
			this->setUeberstundenGesamt(-arbeitsStunden, -arbeitsMinuten);
		}
		else {
			this->setUeberstundenGesamt(ueberStunden, ueberMinuten);
		}
		//Wochenarbeitszeit wird wieder auf ihre Anfangswerte zur�ckgesetzt
		wochenZeitErreicht = false;
		arbeitsStunden = wochenstunden;
		arbeitsMinuten = 0;
		ueberStunden = 0;
		ueberMinuten = 0;
	}
}

//Wenn ein Tag aufgrund der �berschreitung der 23:59 Uhr-Grenze automatisch beendet werden musste
TimeSpan^ Angestellter::neuerTag() {

	DateTime^ tag = this->getArbeitsAnfang();
	//Das Arbeitsende wird mit dem Datum des Arbeitsanfangs auf 23:59:59 gesetzt und als ARBEIT_ENDE-Ereignis in die Liste gespeichert. 
	DateTime^ autoEnde = gcnew DateTime(tag->Year, tag->Month, tag->Day, 23, 59, 59, 0);
	Ereignis^ arbeitsende = gcnew Ereignis(ARBEIT_ENDE, autoEnde);
	this->fuegeEreignisHinzu(arbeitsende);

	//Die Arbeitszeit dieses Arbeitstages wird berechnet...
	TimeSpan^ richtigeArbeitszeit;
	Int32 index = getArbeitsAnfangIndexNachArbeitstag();
	richtigeArbeitszeit = this->berechneArbeitsstunden(index);

	//...und dann von der Wochen-Arbeitszeit abgezogen.
	this->zieheZeitAb(richtigeArbeitszeit->Hours, richtigeArbeitszeit->Minutes);
	this->setAktuellenStatus("Sch�n, dass Sie da sind!");

	return richtigeArbeitszeit;
}

/*Pr�ft, ob in dieser Woche freie Tage (Urlaubs- oder Feiertage vorhanden sind, die noch nicht in die Wochenarbeitszeit eingerechnet wurde.
Falls ja, werden diese noch eingerechnet und als eingerechnet markiert (�ber Boolean).*/
void Angestellter::freieTagePruefen(Unternehmen^ unternehmen)
{
	Int32 anzFreieTage = 0;

	// Kalenderwoche von heute berechnen
	DateTime^ heute = DateTime::Now.Date;
	Int32 kWHeute = kalender->berechneKW(*heute);
	DateTime^ tagDynamisch = heute;
	Int32 kWDynamisch = kWHeute;

	//Exception-Handling, weil evtl. eine Null-Reference-Exception auftreten kann.
	try {
		//Solangen der Tag in der aktuellen Woche liegt, wird gep�rft.
		while (kWDynamisch == kWHeute) {
			//Pr�fe: Ist der Tag ein Feiertag
			if (unternehmen->istFeiertag(*tagDynamisch)) {
				Int32 index = unternehmen->indexVon(*tagDynamisch);
				if (!unternehmen->getFeiertage()[index]->getEingerechnet()) {
					anzFreieTage++;
					unternehmen->getFeiertage()[index]->setEingerechnet(true);
				}
			}
			//Pr�fe: Ist der Tag ein Urlaubstag
			if (this->istUrlaubstag(*tagDynamisch)) {
				Int32 index = this->indexVon(*tagDynamisch);
				if (!listeUrlaubstage[index]->getEingerechnet()) {
					anzFreieTage++;
					listeUrlaubstage[index]->setEingerechnet(true);
				}
			}
			tagDynamisch = tagDynamisch->AddDays(1.0);
			kWDynamisch = kalender->berechneKW(*tagDynamisch);
		}
	}
	catch (System::NullReferenceException ^e) {
		//Keine Aktion notwendig
	}

	//Stunden und Minuten berechnen, die in dieser Woche durch die freien Tage weniger gearbeitet werden m�ssen
	Double tagesArbeitszeit = (Double) wochenstunden / 5;
	Double abzugArbeitszeit = tagesArbeitszeit * anzFreieTage;
	Int32 wenigerStunden = (Int32)abzugArbeitszeit;
	Int32 wenigerMinuten = (abzugArbeitszeit - wenigerStunden) * 60;

	//Diese Zeit von den ArbeitsStunden und Minuten dieser Woche abziehen
	this->zieheZeitAb(wenigerStunden, wenigerMinuten);
}

/*Entfernt Urlaubstage in einem bestimten Zeitraum (Datum von - Datum bis) aus der Liste der Urlaubstage und erstellt eine Nachricht
f�r den Betroffenen Angestellten, die alle Urlaubstage enth�lt, die entfernt wurden.*/
void Angestellter::loescheUrlaubstage(DateTime von, DateTime bis, String^ kommentar)
{
	String^ urlaubEntferntString = "Ihre Urlaubstage\n\n";
	//Alle Tage im Zeitraum von - bis werden durchlaufen
	while (von <= bis) {
		for (int i = 0; i < listeUrlaubstage->Count; i++) {
			//Urlaubstage in diesem Zeitraum werden aus der Liste entfernt und zur Nachricht hinzugef�gt
			if (listeUrlaubstage[i]->getDatum().Equals(von)) {
				removeUrlaubstag(von);
				urlaubEntferntString += von.ToString("dddd, dd. MMMM yyyy") + "\n";
			}
		}
		von = von.AddDays(1.0);
	}
	urlaubEntferntString += "\nmussten leider gestrichen werden.\n\nKommentar: " + kommentar 
		+ "\n\nBei Fragen wenden Sie sich bitte an Ihren Vorgesetzten.";
	antragsInfos->Add(urlaubEntferntString);
}

/*Gibt einen String^ zur�ck, der das Datum mit Wochentag aller Urlaubstage eines Angestellten und (falls true �bergeben wird) aller Feiertage dieses Jahr getrennt 
ausgibt. Bei �bergabe von false nur die Urlaubs- ohne Feiertage*/
String^ Angestellter::freieTageAnzeigen(List<FreierTag^>^ feiertage) {
	String^ urlaubstageString = feiertage!=nullptr ? "Ihre Urlaubstage:\n\n" : "Urlaubstage von " + vorname + " " + nachname + ":\n\n";
	//Die Liste der Urlaubstage wird durchlaufen
	for (int i = 0; i < listeUrlaubstage->Count; i++) {
		//Alle Urlaubstage aus diesem oder sp�teren Jahren werden dem String hinzugef�gt
		if (listeUrlaubstage[i]->getDatum().Year >= DateTime::Now.Year) {
			urlaubstageString += listeUrlaubstage[i]->getDatum().ToString("dddd, dd. MMMM yyyy") + "\n";
		}
	}
	//Wenn f�r dieses Jahr keine Urlaubstage in der Liste stehen:
	if (listeUrlaubstage->Count == 0) {
		urlaubstageString += "Sie haben noch keine best�tigten Urlaubstage.\n";
	}
	if (feiertage != nullptr) {
		urlaubstageString += "\nFeiertage " + Convert::ToString(DateTime::Now.Year) + ":\n\n";
		//Liste der Feiertage wird durchlaufen
		for (int i = 0; i < feiertage->Count; i++) {
			//Alle Feiertag dieses Jahres werden dem String hinzugef�gt
			if (feiertage[i]->getDatum().Year == DateTime::Now.Year) {
				urlaubstageString += feiertage[i]->getDatum().ToString("dddd, dd. MMMM yyyy") + "\n";
			}
		}
	}
	return urlaubstageString;
}

//Es wird eine Nachricht zu einem �nderungsantrag als Antwort erstellt und den AntragsInfos hinzugef�gt
void Angestellter::aenderungAntwort(String^ tag, String^ kommentar, Boolean bestaetigt) {
	
	String^ textZumAntrag;
	//Fall: �nderungsantrag wurde best�tigt
	if (bestaetigt) {
		textZumAntrag = "Ihr �nderungsantrag betreffend " + tag + " wurde best�tigt und wird korrigiert.";
		if (kommentar->Length > 0) {
			textZumAntrag += "\n\nKommentar:\n" + kommentar;
		}
	}
	//Fall: �nderungsantrag wurde abgelehnt
	else {
		textZumAntrag = "Ihr �nderungsantrag betreffend " + tag + " wurde abgelehnt.";
		if (kommentar->Length > 0) {
			textZumAntrag += "\n\nKommentar:\n" + kommentar;
		}
	}
	this->addAntragsInfo(textZumAntrag);
}