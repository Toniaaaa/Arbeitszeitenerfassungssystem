#include "Angestellter.h"

using namespace System::Windows::Forms;

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
}

Int32 Angestellter::getRestUrlaub() 
{
	Int32 urlaubstageDiesesJahr = 0;
	for (int i = 0; i < listeUrlaubstage->Count; i++) {
		if (listeUrlaubstage[i]->getDatum().Year == DateTime::Now.Year) {
			urlaubstageDiesesJahr++;
		}
	}
	return urlaubstage - urlaubstageDiesesJahr;
}

Abteilung ^ Angestellter::getAbteilung()
{
	return abteilung;
}

Ereignis ^ Angestellter::getEreignis(Int32 index)
{
	return listeEreignisse[index];
}

Int32 Angestellter::getAnzahlEreignisse()
{
	return listeEreignisse->Count;
}

Int32 Angestellter::getAnzahlArbeitstage()
{
	return 0; // TODO
}

void Angestellter::fuegeEreignisHinzu(Ereignis^ ereignis)
{
	listeEreignisse->Add(ereignis);
}

void Angestellter::removeEreignis(Int32 index)
{
	listeEreignisse->RemoveAt(index);
}

void Angestellter::addAntragsInfo(String^ info)
{
	antragsInfos->Add(info);
}

void Angestellter::removeAntragsInfo(Int32 index)
{
	antragsInfos->RemoveAt(index);
}

void Angestellter::setAktuellenStatus(String ^ status)
{
	this->status = status;
}

String ^ Angestellter::getStatus()
{
	return status;
}

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

DateTime ^ Angestellter::getPauseAnfang()
{
	DateTime^ pauseanfang = nullptr;

	if (getAnzahlEreignisse() > 0 && listeEreignisse[getAnzahlEreignisse() - 1]->getTyp() == PAUSE_START) {
		pauseanfang = listeEreignisse[getAnzahlEreignisse() - 1]->getTimestamp();
	}
	return pauseanfang;
}

TimeSpan ^ Angestellter::getAktuelleArbeitszeit()
{
	Int32 arbeitsanfang = getArbeitsAnfangIndex();

	TimeSpan^ result = nullptr;
	if (arbeitsanfang != -1) {
		result = DateTime::Now - *(listeEreignisse[arbeitsanfang]->getTimestamp());

		TimeSpan^ pause = getPausezeit();
		result = TimeSpan::operator-(*result, *pause);
	}
	return result;
}

TimeSpan ^ Angestellter::getAktuellePausenzeit()
{
	return DateTime::Now - *getPauseAnfang();
}

TimeSpan ^ Angestellter::getPausezeit()
{
	Int32 index = getArbeitsAnfangIndex();
	TimeSpan^ result = nullptr;

	if (index != -1) {
		result = gcnew TimeSpan();

		DateTime^ pausestart = nullptr;
		for (int i = index + 1; i < getAnzahlEreignisse(); i++) {
			if (listeEreignisse[i]->getTyp() == PAUSE_START) {
				pausestart = listeEreignisse[i]->getTimestamp();
			}
			else if (listeEreignisse[i]->getTyp() == PAUSE_ENDE) {
				TimeSpan^ pause = *(listeEreignisse[i]->getTimestamp()) - *(pausestart);
				result = TimeSpan::operator+(*result, *pause);
				pausestart = nullptr;
			}
		}

		if (pausestart != nullptr) {
			TimeSpan^ pause = DateTime::Now - *(pausestart);
			result = TimeSpan::operator+(*result, *pause);
		}
	}
	return result;
}

TimeSpan ^ Angestellter::berechneArbeitsstunden(Int32 anfangsEreignisIndex)
{
	DateTime^ anfang = listeEreignisse[anfangsEreignisIndex]->getTimestamp();
	TimeSpan^ gesamtPause = gcnew TimeSpan();
	DateTime^ ende = DateTime::Now;

	DateTime^ pausestart = nullptr;
	for (int i = anfangsEreignisIndex + 1; i < getAnzahlEreignisse(); i++) {
		if (listeEreignisse[i]->getTyp() == PAUSE_START) {
			pausestart = listeEreignisse[i]->getTimestamp();
		}
		else if (listeEreignisse[i]->getTyp() == PAUSE_ENDE) {
			TimeSpan^ pause = *(listeEreignisse[i]->getTimestamp()) - *(pausestart);
			gesamtPause = TimeSpan::operator+(*gesamtPause, *pause);
			pausestart = nullptr;
		}
		else if (listeEreignisse[i]->getTyp() == ARBEIT_ENDE) {
			ende = listeEreignisse[i]->getTimestamp();
			break;
		}
	}

	if (pausestart != nullptr) {
		TimeSpan^ pause = *ende - *pausestart;
		gesamtPause = TimeSpan::operator+(*gesamtPause, *pause);
	}

	return TimeSpan::operator-(*ende - *anfang, *gesamtPause);
}

Int32 Angestellter::getArbeitsAnfangIndex()
{
	Int32 arbeitsanfang = -1;
	for (int i = getAnzahlEreignisse() - 1; i >= 0; i--) {
		if (listeEreignisse[i]->getTyp() == ARBEIT_ENDE) {
			break;
		}
		if (listeEreignisse[i]->getTyp() == ARBEIT_START) {
			arbeitsanfang = i;
			break;
		}
	}
	return arbeitsanfang;
}

void Angestellter::speichereArbeitszeit(Int32 stunden, Int32 minuten, Boolean erreicht)
{
	wochenZeitErreicht = erreicht;
	if (erreicht) {
		arbeitsStunden = 0;
		arbeitsMinuten = 0;
		ueberStunden = stunden;
		ueberMinuten = minuten;
	}
	else {
		arbeitsStunden = stunden;
		arbeitsMinuten = minuten;
	}
}

void Angestellter::setUeberstundenGesamt(Int32 stunden, Int32 minuten) 
{
	ueberStundenGesamt += stunden + (minuten / 60);
}

//Fügt die Anzahl der Urlaubstage den genommenen Tagen hinzu und reduziert damit den Resturlaub
//Trägt alle Tage innerhalb der Zeitspanne, die kein Wochenende oder Feiertage sind, in die Liste der Urlaubstage ein. 
void Angestellter::nehmeUrlaub(DateTime beginn, DateTime ende, List<FreierTag^>^ feiertage)
{
	while (beginn <= ende) {
		//Prüfe, ob dieser Tag bereits ein Feiertag ist
		Boolean istFeiertag = false;
		for (int i = 0; i < feiertage->Count; i++) {
			if (beginn == feiertage[i]->getDatum()) {
				istFeiertag = true;
				break;
			}
		}
		//Prüfe, ob dieser Tag bereits ein genommener Urlaubstag ist
		Boolean istUrlaubstag = false;
		for (int i = 0; i < listeUrlaubstage->Count; i++) {
			if (beginn == listeUrlaubstage[i]->getDatum()) {
				istUrlaubstag = true;
				break;
			}
		}
		//Prüfe, ob dieser Tag ein Samstag oder Sonntag ist
		if (!istFeiertag && !istUrlaubstag && beginn.DayOfWeek != DayOfWeek::Saturday && beginn.DayOfWeek != DayOfWeek::Sunday) {
			//Tag wird der Liste hinzugefügt und ein Tag den genommenen Urlaubstagen hinzugefügt.
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
		//Prüfe, ob dieser Tag bereits ein Feiertag ist
		Boolean istFeiertag = false;
		for (int i = 0; i < feiertage->Count; i++) {
			if (beginn == feiertage[i]->getDatum()) {
				istFeiertag = true;
				break;
			}
		}
		//Prüfe, ob dieser Tag bereits ein genommener Urlaubstag ist
		Boolean istUrlaubstag = false;
		for (int i = 0; i < listeUrlaubstage->Count; i++) {
			if (beginn == listeUrlaubstage[i]->getDatum()) {
				istUrlaubstag = true;
				break;
			}
		}
		//Prüfe, ob dieser Tag ein Samstag oder Sonntag ist
		if (!istFeiertag && !istUrlaubstag && beginn.DayOfWeek != DayOfWeek::Saturday && beginn.DayOfWeek != DayOfWeek::Sunday) {
			//Tag wird der Liste hinzugefügt und ein Tag den genommenen Urlaubstagen hinzugefügt.
			anzUrlaubstage++;
		}
		beginn = beginn.AddDays(1.0);
	}

	return anzUrlaubstage;
}


void Angestellter::addUrlaubstag(DateTime tag)
{
	listeUrlaubstage->Add(gcnew FreierTag(tag));
}

void Angestellter::removeUrlaubstag(DateTime tag)
{
	for (int i = listeUrlaubstage->Count - 1; i >= 0; i--) {
		if (listeUrlaubstage[i]->getDatum() == tag) {
			listeUrlaubstage->RemoveAt(i);
			break;
		}
	}
}

void Angestellter::loescheAlleUrlaubstage()
{
	for (int i = listeUrlaubstage->Count - 1; i >= 0; i--) {
		listeUrlaubstage->RemoveAt(i);
	}
}

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

Boolean Angestellter::dieseWocheEingeloggt() {
	Boolean eingeloggt = false;
	if (kalender->berechneKW(letzterLogin) == kalender->berechneKW(DateTime::Today)) {
		eingeloggt = true;
	}
	return eingeloggt;
}

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

/*Gibt eine um die angegebenen Stunden und Minuten reduzierte Arbeitszeit zurück. Wenn die Wochenarbeitszeit erreicht 
wird, werden die Ueberstunden zurückgegeben, außerdem wird Sekunde = 1, sonst immer 0.*/
TimeSpan Angestellter::getReduzierteZeit(Int32 stunden, Int32 minuten) {
	
	TimeSpan^ reduzierteZeit;
	Int32 arbeitsStd = arbeitsStunden;
	Int32 arbeitsMin = arbeitsMinuten;
	Int32 ueberStd = ueberStunden;
	Int32 ueberMin = ueberMinuten;

	//Fall: Es wurden bereits Überstunden gezählt (also Wochen-Arbeitszeit war schon erreicht)
	if (wochenZeitErreicht) {
		ueberStd -= stunden;
		if (ueberMin + minuten >= 60) {
			ueberStd++;
			ueberMin = ueberMin + minuten - 60;
		}
		else {
			ueberMin -= minuten;
		}
		if (ueberStd >= 0) {
			reduzierteZeit = reduzierteZeit = gcnew TimeSpan(ueberStd, ueberMin, 1);
		}
		//Fall: Die Wochen-Arbeitszeit wurde durch den Zeitabzug doch nicht erreicht
		else {
			arbeitsStd = -ueberStd - 1; //-1, weil die Arbeitsstunden von 00:00 auf 1:01 springen. Mit -1 ist das korrigiert.
			arbeitsMin = (ueberMin == 0) ? 0 : 60 - ueberMin;
			reduzierteZeit = gcnew TimeSpan(arbeitsStd, arbeitsMin, 0);
		}
	}
	//Fall: Es wurden noch keine Überstunden gezählt (also Wochen-Arbeitszeit noch nicht erreicht)
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

// Wenn eine neues Jahr startet, werden die Urlaubstage zurueckgesetzt
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

	//Urlaubstage, die aus dem letzten Jahr stammen, verfallen, wenn sie nicht bis März genommen wurden
	if (urlaubstageGespart != 0 && heute->Month >= 4) {
		urlaubstage -= urlaubstageGespart;
		urlaubstageGespart = 0;
	}
}
// Wenn eine neue Woche startet, wird die Arbeitszeit zurueckgesetzt
void Angestellter::neueWoche()
{
	//Prüfen, ob sich der Angestellte in dieser Woche schon eingeloggt hat. Wenn nicht: Zurücksetzen der Wochen-Arbeitszeit, da eine neue Woche begonnen hat.
	if (!this->dieseWocheEingeloggt()) {
		//Wenn der Mitarbeiter in der letzten Woche seine Arbeitszeit nicht erreicht hat, wird ihm das von seinen Überstunden wieder abgezogen
		if (!wochenZeitErreicht) {
			this->setUeberstundenGesamt(-arbeitsStunden, -arbeitsMinuten);
		}
		else {
			this->setUeberstundenGesamt(ueberStunden, ueberMinuten);
		}
		//Wochenarbeitszeit wird wieder auf ihre Anfangswerte zurückgesetzt
		wochenZeitErreicht = false;
		arbeitsStunden = wochenstunden;
		arbeitsMinuten = 0;
		ueberStunden = 0;
		ueberMinuten = 0;
	}
}

void Angestellter::freieTagePruefen(Unternehmen^ unternehmen)
{
	Int32 anzFreieTage = 0;

	// Kalenderwoche von heute berechnen
	DateTime^ heute = DateTime::Now.Date;
	Int32 kWHeute = kalender->berechneKW(*heute);
	DateTime^ tagDynamisch = heute;
	Int32 kWDynamisch = kWHeute;

	try {
		while (kWDynamisch == kWHeute) {
			if (unternehmen->istFeiertag(*tagDynamisch)) {
				Int32 index = unternehmen->indexVon(*tagDynamisch);
				if (!unternehmen->getFeiertage()[index]->getEingerechnet()) {
					anzFreieTage++;
					unternehmen->getFeiertage()[index]->setEingerechnet(true);
				}
			}
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

	//Stunden und Minuten berechnen, die in dieser Woche durch die freien Tage weniger gearbeitet werden müssen
	Double tagesArbeitszeit = (Double) wochenstunden / 5;
	Double abzugArbeitszeit = tagesArbeitszeit * anzFreieTage;
	Int32 wenigerStunden = (Int32)abzugArbeitszeit;
	Int32 wenigerMinuten = (abzugArbeitszeit - wenigerStunden) * 60;

	//Diese Zeit von den ArbeitsStunden und Minuten dieser Woche abziehen
	this->zieheZeitAb(wenigerStunden, wenigerMinuten);
}

void Angestellter::loescheUrlaubstage(DateTime von, DateTime bis, String^ kommentar)
{
	String^ urlaubEntferntString = "Ihre Urlaubstage\n\n";
	while (von <= bis) {
		for (int i = 0; i < listeUrlaubstage->Count; i++) {
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

String^ Angestellter::freieTageAnzeigen(List<FreierTag^>^ feiertage) {
	String^ urlaubstageString = feiertage!=nullptr ? "Ihre Urlaubstage:\n\n" : "Urlaubstage von " + vorname + " " + nachname + ":\n\n";
	for (int i = 0; i < listeUrlaubstage->Count; i++) {
		if (listeUrlaubstage[i]->getDatum().Year >= DateTime::Now.Year) {
			urlaubstageString += listeUrlaubstage[i]->getDatum().ToString("dddd, dd. MMMM yyyy") + "\n";
		}
	}
	if (listeUrlaubstage->Count == 0) {
		urlaubstageString += "Sie haben noch keine bestätigten Urlaubstage.\n";
	}
	if (feiertage != nullptr) {
		urlaubstageString += "\nFeiertage " + Convert::ToString(DateTime::Now.Year) + ":\n\n";
		for (int i = 0; i < feiertage->Count; i++) {
			if (feiertage[i]->getDatum().Year == DateTime::Now.Year) {
				urlaubstageString += feiertage[i]->getDatum().ToString("dddd, dd. MMMM yyyy") + "\n";
			}
		}
	}
	return urlaubstageString;
}

void Angestellter::aenderungAntwort(String^ tag, String^ kommentar, Boolean bestaetigt) {
	
	String^ textZumAntrag;
	if (bestaetigt) {
		textZumAntrag = "Ihr Änderungsantrag betreffend " + tag + " wurde bestätigt und wird korrigiert.";
		if (kommentar->Length > 0) {
			textZumAntrag += "\n\nKommentar:\n" + kommentar;
		}
	}
	else {
		textZumAntrag = "Ihr Änderungsantrag betreffend " + tag + " wurde abgelehnt.";
		if (kommentar->Length > 0) {
			textZumAntrag += "\n\nKommentar:\n" + kommentar;
		}
	}
	addAntragsInfo(textZumAntrag);
}