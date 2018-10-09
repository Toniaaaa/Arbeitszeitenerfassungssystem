#include "Angestellter.h"
#include "Vorgesetzter.h"
#include "Mitarbeiter.h"

Angestellter::Angestellter(String ^ vorname, String ^ nachname, Abteilung ^ abteilung, String ^ personalnummer, array<Byte>^ passwort, Int32 wochenstunden, Int32 urlaubstage)
{
	this->vorname = vorname;
	this->nachname = nachname;
	this->abteilung = abteilung;
	this->personalnummer = personalnummer;
	this->passwort = passwort;
	this->wochenstunden = wochenstunden;
	this->urlaubstage = urlaubstage;
	this->urlaubstageGespart = 0;
	krankheitsTage = gcnew List<FreierTag^>;
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

Angestellter::Angestellter(Vorgesetzter^ vorgesetzterAlt)
{
	this->vorname = vorgesetzterAlt->getVorname();
	this->nachname = vorgesetzterAlt->getNachname();
	this->abteilung = vorgesetzterAlt->getAbteilung();
	this->personalnummer = vorgesetzterAlt->getPersonalnummer();
	this->passwort = vorgesetzterAlt->getPasswort();
	this->wochenstunden = vorgesetzterAlt->getWochensstunden();
	this->urlaubstage = vorgesetzterAlt->getUrlaubstage();
	this->urlaubstageGespart = vorgesetzterAlt->getUrlaubstageGespart();
	this->krankheitsTage = vorgesetzterAlt->getKrankheitstage();
	this->listeEreignisse = vorgesetzterAlt->getListeEreignisse();
	this->listegesamtstunden = vorgesetzterAlt->getListeGesamtstunden();
	this->antragsInfos = gcnew List<String^>;
	this->wochenZeitErreicht = vorgesetzterAlt->getWochenZeitErreicht();
	this->arbeitsStunden = vorgesetzterAlt->getArbeitsStunden();
	this->arbeitsMinuten = vorgesetzterAlt->getArbeitsMinuten();
	this->ueberStunden = vorgesetzterAlt->getUeberStunden();
	this->ueberMinuten = vorgesetzterAlt->getUeberMinuten();
	this->ueberStundenGesamt = vorgesetzterAlt->getUeberstundenGesamt();
	this->listeUrlaubstage = vorgesetzterAlt->getListeUrlaubstage();
	this->letzterLogin = vorgesetzterAlt->getLetzterLogin();
	this->kalender = gcnew Kalender();
	this->jahresurlaub = vorgesetzterAlt->getJahresurlaub();
	this->vergleichen = gcnew FreierTagComparer;
}

Angestellter::Angestellter(Mitarbeiter^ mitarbeiterAlt)
{
	this->vorname = mitarbeiterAlt->getVorname();
	this->nachname = mitarbeiterAlt->getNachname();
	this->abteilung = mitarbeiterAlt->getAbteilung();
	this->personalnummer = mitarbeiterAlt->getPersonalnummer();
	this->passwort = mitarbeiterAlt->getPasswort();
	this->wochenstunden = mitarbeiterAlt->getWochensstunden();
	this->urlaubstage = mitarbeiterAlt->getUrlaubstage();
	this->urlaubstageGespart = mitarbeiterAlt->getUrlaubstageGespart();
	this->krankheitsTage = mitarbeiterAlt->getKrankheitstage();
	this->listeEreignisse = mitarbeiterAlt->getListeEreignisse();
	this->listegesamtstunden = mitarbeiterAlt->getListeGesamtstunden();
	this->antragsInfos = gcnew List<String^>;
	this->wochenZeitErreicht = mitarbeiterAlt->getWochenZeitErreicht();
	this->arbeitsStunden = mitarbeiterAlt->getArbeitsStunden();
	this->arbeitsMinuten = mitarbeiterAlt->getArbeitsMinuten();
	this->ueberStunden = mitarbeiterAlt->getUeberStunden();
	this->ueberMinuten = mitarbeiterAlt->getUeberMinuten();
	this->ueberStundenGesamt = mitarbeiterAlt->getUeberstundenGesamt();
	this->listeUrlaubstage = mitarbeiterAlt->getListeUrlaubstage();
	this->letzterLogin = mitarbeiterAlt->getLetzterLogin();
	this->kalender = gcnew Kalender();
	this->jahresurlaub = mitarbeiterAlt->getJahresurlaub();
	this->vergleichen = gcnew FreierTagComparer;
}

//Gibt den restlichen Jahresurlaub zurück, den der Angestellte noch nicht eingereicht hat.
Int32 Angestellter::getRestUrlaub() 
{
	Int32 urlaubstageDiesesJahr = 0;
	//Die Urlaubstage, die für dieses Jahr schon verplant sind, werden gezählt.
	for (int i = 0; i < listeUrlaubstage->Count; i++) {
		if (listeUrlaubstage[i]->getDatum().Year == DateTime::Now.Year && !listeUrlaubstage[i]->getIstFeiertag()) {
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

//Gibt die DateTime des Arbeitanfangs zurück, falls der Arbeitstag noch nicht beendet wurde. Sonst wird der nullptr zurückgegeben.
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

//Fügt der Liste der Krankheitstage den übergebenen Tag hinzu
void Angestellter::addKrankheitstag(DateTime tag)
{
	//Fügt einen neuen Krankheitstag mit dem übergebenen Datum hinzu... 
	krankheitsTage->Add(gcnew FreierTag(tag, false));
	//...und sortiert die Liste der Krankheitstage nach dem Datum
	krankheitsTage->Sort(vergleichen);
}

//Entfernt einen übergebenen Tag aus der Liste der Krankheitstage
void Angestellter::removeKrankheitstag(DateTime tag)
{
	for (int i = krankheitsTage->Count - 1; i >= 0; i--) {
		if (krankheitsTage[i]->getDatum() == tag) {
			krankheitsTage->RemoveAt(i);
			break;
		}
	}
}

//Gibt den TimeStamp (DateTime) des Pausenstarts zurück, falls gerade eine Pause läuft, sonst nullptr zurück.
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
		TimeSpan^ pause = getPausezeit(false);
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

//Berechnet die gesamtzeit der Pausen des aktuellen Arbeitstags und gibt diese als TimeSpan zurück
TimeSpan ^ Angestellter::getPausezeit(Boolean tagBeendet)
{
	TimeSpan^ result = nullptr;

	if (!tagBeendet) {
	Int32 index = getArbeitsAnfangIndex();
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
	}
	else {
		Int32 index = getArbeitsAnfangIndexNachArbeitstag();
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
		}
	}
	return result;
}

//Gibt die Pausenzeit zurück, die noch zur gesetzlich vorgeschriebenen Pause fehlt.
TimeSpan^ Angestellter::genugPause() 
{
	TimeSpan^ fehlendePause = gcnew TimeSpan(0, 0, 0);
	//berechnet heutige Arbeitszeit
	TimeSpan^ arbeit = berechneArbeitsstunden(getArbeitsAnfangIndexNachArbeitstag());
	//berechnet heutige Pausen
	TimeSpan^ pausen = getPausezeit(true);
	//Fall: Es wurden mehr als 9 Stunden gearbeitet
	if (*arbeit > TimeSpan(9, 0, 0)) {
		fehlendePause = TimeSpan::operator-(TimeSpan(0, 45, 0), *pausen);
	}
	//Fall: Es wurden zwichen 6 und 9 Stunden gearbeitet
	else if (*arbeit > *(gcnew TimeSpan(6, 0, 0))) {
		fehlendePause = TimeSpan::operator-(TimeSpan(0, 30, 0), *pausen);
	} 
	return fehlendePause;
}

//Berechnet die gesamte Arbeitszeit ab bestimmten Arbeitsanfangs (anfangsEreignisIndex) bis zum Ende dieses Tages und gibt sie als TimeSpan zurück.
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

/*Sucht den Index des letzten Arbeitsanfangs (also letztes Ereignis ARBEIT_START) in der Ereignisliste und gibt sie zurück, falls der Arbeitstag noch
* nicht beendet wurde und gibt diesen zurück. Ansonsten wird -1 zurückgegeben.
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

/*Sucht den Index des Arbeitsanfangs (also Ereignis ARBEIT_START) des letzten BEENDETEN Arbeitstages in der Ereignisliste und gibt diesen zurück. 
Ansonsten wird -1 zurückgegeben.*/
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

/*Trägt alle Tage innerhalb der Zeitspanne, die kein Wochenende oder Feiertage sind und noch nicht in der Liste der Urlaubstage stehen, 
in die Liste der Urlaubstage ein.*/
void Angestellter::nehmeUrlaub(DateTime beginn, DateTime ende)
{
	while (beginn <= ende) {
		//Prüfe, ob dieser Tag ein Urlaubstag, Krankheitstag, Samstag oder Sonntag ist
		if (!istUrlaubstag(beginn) && !istKrankheitstag(beginn) && beginn.DayOfWeek != DayOfWeek::Saturday && beginn.DayOfWeek != DayOfWeek::Sunday) {
			//Tag wird der Liste hinzugefügt und ein Tag den genommenen Urlaubstagen hinzugefügt.
			this->addUrlaubstag(beginn);
			if (urlaubstageGespart > 0) {
				urlaubstageGespart--;
			}
		}
		beginn = beginn.AddDays(1.0);
	}
}

/*Trägt alle Tage innerhalb der Zeitspanne, die kein Wochenende oder Feiertage sind, in die Liste der Krankheitstage ein. Urlaubstage in diesem Zeitraum werden entfernt.*/
void Angestellter::krankMelden(DateTime beginn, DateTime ende)
{
	//Alle Tage von Beginn bis Ende werden durchlaufen
	while (beginn <= ende) {
		//Prüfen: Ist der Tag ein Feiertag oder ein Urlaubstag ist (also in der Urlaubstage-Liste und evtl. istFeiertag = true)
		if (Int32 index = indexVonUrlaubstag(beginn) != -1) {
			//Wenn der Tag ein normaler Urlaubstag ist, wird er aus der Urlaubstage-Liste entfernt.
			if (!istFeiertag(beginn)) {
				loescheUrlaubstage(beginn, beginn, "Ist jetzt ein Krankheitstag.");
			}
		}
		//Prüfe, ob dieser Tag bereits ein gespeicherter Krankheitstag, ein Feiertag, Samstag oder Sonntag ist
		if (!istKrankheitstag(beginn) && !istFeiertag(beginn) && beginn.DayOfWeek != DayOfWeek::Saturday && beginn.DayOfWeek != DayOfWeek::Sunday) {
			//Wenn er das alles nicht ist, wird er der Liste der Krankheitstag hinzugefügt.
			this->addKrankheitstag(beginn);
		}
		beginn = beginn.AddDays(1.0);
	}
}

//Berechnet die Anzahl der Tage in einem Intervall ohne Wochenenden und Feiertage
Int32 Angestellter::berechneArbeitstage(DateTime beginn, DateTime ende)
{
	Int32 anzArbeitstage = 0;

	while (beginn <= ende) {
		//Prüfe, ob dieser Tag ein Feiertag, Samstag oder Sonntag ist
		if (!istFeiertag(beginn) && beginn.DayOfWeek != DayOfWeek::Saturday && beginn.DayOfWeek != DayOfWeek::Sunday) {
			//Tag wird der Liste hinzugefügt und ein Tag den genommenen Urlaubstagen hinzugefügt.
			anzArbeitstage++;
		}
		beginn = beginn.AddDays(1.0);
	}

	return anzArbeitstage;
}

//Berechnet die Anzahl der Tage in einem Intervall ohne Wochenenden und Feiertage
Int32 Angestellter::berechneUrlaubstage(DateTime beginn, DateTime ende)
{
	Int32 anzUrlaubstage = 0;

	while (beginn <= ende) {
		//Prüfe, ob dieser Tag ein Samstag oder Sonntag ist
		if (!istUrlaubstag(beginn) && !istKrankheitstag(beginn) && beginn.DayOfWeek != DayOfWeek::Saturday && beginn.DayOfWeek != DayOfWeek::Sunday) {
			//Tag wird der Liste hinzugefügt und ein Tag den genommenen Urlaubstagen hinzugefügt.
			anzUrlaubstage++;
		}
		beginn = beginn.AddDays(1.0);
	}

	return anzUrlaubstage;
}

//Fügt der Liste der Urlaubstage einen Urlaubstag (DateTime) hinzu.
void Angestellter::addUrlaubstag(DateTime tag)
{
	//Fügt einen neuen Urlaubstag mit dem übergebenen Datum hinzu... 
	listeUrlaubstage->Add(gcnew FreierTag(tag, false));
	//...und sortiert die Liste der Urlaubstage nach dem Datum der Urlaubstage
	listeUrlaubstage->Sort(vergleichen);
}

//Fügt der Liste der Urlaubstage einen Feiertag (DateTime) hinzu.
void Angestellter::addFeiertag(DateTime tag)
{
	//Fügt einen neuen Urlaubstag mit dem übergebenen Datum hinzu... 
	listeUrlaubstage->Add(gcnew FreierTag(tag, true));
	//Wenn es sich nicht um einen der 5 Standard-Feiertage handelt, wird der Angestellte über das Hinzufügen eines neuen Feiertags informiert
	if (!(tag.Day == 1 && tag.Month == 1) && !(tag.Day == 1 && tag.Month == 5) && !(tag.Day == 3 && tag.Month == 10) && !(tag.Day == 25 && tag.Month == 12) && 
		!(tag.Day == 26 && tag.Month == 12)) {
		this->addAntragsInfo(tag.ToString("dddd, dd. MMMM yyyy") + " wurde als neuer Feiertag zu Ihrem Urlaub hinzugefügt!");
	}
	//...und sortiert die Liste der Urlaubstage nach dem Datum der Urlaubstage
	listeUrlaubstage->Sort(vergleichen);
}

//Entfernt einen bestimmten Urlaubstag, dessen Datum mit der übergebenen DateTime übereinstimmt, aus der Liste der Urlaubstage
void Angestellter::removeUrlaubstag(DateTime tag)
{
	for (int i = listeUrlaubstage->Count - 1; i >= 0; i--) {
		if (listeUrlaubstage[i]->getDatum() == tag) {
			listeUrlaubstage->RemoveAt(i);
			break;
		}
	}
}

//Prüft, ob das Datum eines Eintrag in der Liste der Urlaubstage mit der übergebenen DateTime übereinstimmt. 
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

//Prüft, ob das Datum eines Eintrag in der Liste der Urlaubstage mit der übergebenen DateTime übereinstimmt und ob es ein Feiertag ist. 
Boolean Angestellter::istFeiertag(DateTime tag)
{
	Boolean istFeiertag = false;
	for (int i = listeUrlaubstage->Count - 1; i >= 0; i--) {
		if (listeUrlaubstage[i]->getDatum() == tag && listeUrlaubstage[i]->getIstFeiertag()) {
			istFeiertag = true;
			break;
		}
	}
	return istFeiertag;
}

//Prüft, ob das Datum eines Eintrag in der Liste der Krankheitstag mit der übergebenen DateTime übereinstimmt. 
Boolean Angestellter::istKrankheitstag(DateTime tag)
{
	Boolean istKrankheitstag = false;
	for (int i = krankheitsTage->Count - 1; i >= 0; i--) {
		if (krankheitsTage[i]->getDatum() == tag) {
			istKrankheitstag = true;
			break;
		}
	}
	return istKrankheitstag;
}

//Gibt den Index eines Urlaubstags zurück, falls dieser in der Liste der Urlaubstage vorhanden ist.
Int32 Angestellter::indexVonUrlaubstag(DateTime tag)
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

//Gibt den Index eines Urlaubstags zurück, falls dieser in der Liste der Urlaubstage vorhanden ist.
Int32 Angestellter::indexVonKrankheitstag(DateTime tag)
{
	Int32 index = -1;
	for (int i = krankheitsTage->Count - 1; i >= 0; i--) {
		if (krankheitsTage[i]->getDatum().Date == tag) {
			index = i;
			break;
		}
	}
	return index;
}

//Prüft, ob der angestellte in dieser Woche bereits eingeloggt war, indem die Kalenderwoche des letzten Logins mit der KW von heute verglichen wird.
Boolean Angestellter::dieseWocheEingeloggt() {
	Boolean eingeloggt = false;
	if (kalender->berechneKW(letzterLogin) == kalender->berechneKW(DateTime::Today)) {
		eingeloggt = true;
	}
	return eingeloggt;
}

//Zieht die übergebene Anzahl von Stunden und Minuten von der noch offenen WochenArbeitszeit ab.
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
		ueberStunden = 0;
		ueberMinuten = 0;
	}
}

/*Gibt eine um die angegebenen Stunden und Minuten reduzierte Arbeitszeit zurück, ohne diese zu verändern. 
Wenn die Wochenarbeitszeit erreicht wird, werden die Ueberstunden zurückgegeben, außerdem wird Sekunde = 1, sonst immer 0.*/
TimeSpan Angestellter::getReduzierteZeit(Int32 stunden, Int32 minuten) {
	
	TimeSpan^ reduzierteZeit;
	Int32 arbeitsStd = arbeitsStunden;
	Int32 arbeitsMin = arbeitsMinuten;
	Int32 ueberStd = ueberStunden;
	Int32 ueberMin = ueberMinuten;

	/*1. Fall: Es wurden bereits Überstunden gezählt (also Wochen-Arbeitszeit war schon erreicht). Die übergebenen Stunden und Minuten 
	werden von den Überstunden subtrahiert.*/
	if (wochenZeitErreicht && (ueberStd > 0 || ueberMin > 0)) {
		ueberStd += stunden;
		if (ueberMin + minuten > 59) {
			ueberStd++;
			ueberMin = ueberMin + minuten - 60;
		}
		else if (ueberMin + minuten < 0) {
			ueberStd--;
			ueberMin = ueberMin + minuten + 60;
		}
		else {
			ueberMin += minuten;
		}
		if (ueberStd >= 0) {
			reduzierteZeit = gcnew TimeSpan(ueberStd, ueberMin, 1);
		}
		//2. Fall: Die Wochen-Arbeitszeit wurde durch den Zeitabzug doch nicht mehr erreicht
		else {
			arbeitsStd = (ueberMin == 0) ? -ueberStd : -ueberStd - 1; //-1, weil die Arbeitsstunden von 00:00 auf 1:01 springen. Mit -1 ist das korrigiert.
			arbeitsMin = (ueberMin == 0) ? 0 : 60 - ueberMin;
			reduzierteZeit = gcnew TimeSpan(arbeitsStd, arbeitsMin, 0);
		}
	}
	//3. Fall: Es wurden noch keine Überstunden gezählt (also Wochen-Arbeitszeit noch nicht erreicht)
	else {
		arbeitsStd -= stunden;
		if (arbeitsMin - minuten < 0) {
			arbeitsStd--;
			arbeitsMin = arbeitsMin - minuten + 60;
		}
		else if (arbeitsMin - minuten > 59) {
			arbeitsStd++;
			arbeitsMin = arbeitsMin - minuten - 60;
		}
		else {
			arbeitsMin -= minuten;
		}
		if (arbeitsStd >= 0) {
			reduzierteZeit = gcnew TimeSpan(arbeitsStd, arbeitsMin, 0);
		}
		//Fall: Die Wochen-Arbeitszeit wurde durch den Zeitabzug erreicht
		else {
			ueberStd = (arbeitsMin == 0) ? -arbeitsStd : -arbeitsStd - 1; //-1, weil die Arbeitsstunden von 00:00 auf 1:01 springen. Mit -1 ist das korrigiert.
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

	//Urlaubstage, die aus dem letzten Jahr stammen, verfallen, wenn sie nicht bis März genommen wurden
	if (urlaubstageGespart != 0 && heute->Month >= 4) {
		urlaubstage -= urlaubstageGespart;
		urlaubstageGespart = 0;
	}
}

// Wenn eine neue Woche startet, wird die Arbeitszeit zurueckgesetzt
void Angestellter::neueWoche()
{
	//Prüfe: Letzter Login mehr als eine Woche zurückliegend -> Die dazwischen liegenden Wochen wurde noch nicht abgerechnet
	if (kalender->berechneKW(letzterLogin) < kalender->berechneKW(DateTime::Now) - 1) {
		Int32 anzTageGefehlt = 0;
		//Suche den Montag nach dem letzten Login
		DateTime von = *kalender->ersterTagDieserWoche();
		DateTime bis = von;
		while (kalender->berechneKW(von) > kalender->berechneKW(letzterLogin) + 1) {
			von = von.AddDays(-7.0);
		}
		//Zähle Tage, an denen der Angestellte nicht anwesend war und die keine Urlaubstage, Krankheitstage oder Wochenenden waren.
		while (von < bis) {
			if (von.DayOfWeek != DayOfWeek::Saturday && von.DayOfWeek != DayOfWeek::Sunday && !istUrlaubstag(von) && !istKrankheitstag(von)) {
				anzTageGefehlt++;
			}
			von = von.AddDays(1.0);
		}
		//Für Wochen, in denen der Arbeitnehmer nicht anwesend war, wird anteilig Zeit abgezogen
		Int32 gesamtminuten = anzTageGefehlt * (wochenstunden * 60 / 5);
		Int32 gesamtstunden = gesamtminuten / 60;
		gesamtminuten -= gesamtstunden * 60;
		this->setUeberstundenGesamt(-gesamtstunden, -gesamtminuten);
	}
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

//Wenn ein Tag aufgrund der Überschreitung der 23:59 Uhr-Grenze automatisch beendet werden musste
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
	this->setAktuellenStatus("Schön, dass Sie da sind!");

	return richtigeArbeitszeit;
}

/*Prüft, ob in dieser Woche freie Tage (Urlaubs- oder Feiertage vorhanden sind, die noch nicht in die Wochenarbeitszeit eingerechnet wurde.
Falls ja, werden diese noch eingerechnet und als eingerechnet markiert (über Boolean).*/
void Angestellter::freieTagePruefen(Unternehmen^ unternehmen)
{
	Int32 anzFreieTage = 0;

	// Kalenderwoche von heute berechnen
	DateTime^ heute = DateTime::Now.Date;
	Int32 kWHeute = kalender->berechneKW(*heute);
	DateTime^ tagDynamisch = kalender->ersterTagDieserWoche();
	Int32 kWDynamisch = kWHeute;

	//Prüfe: Neuer Feiertag? Wenn ja: Urlaubstag-Liste hinzufügen.
	for (int i = 0; i < unternehmen->getFeiertage()->Count; i++) {
		Boolean schonInListe = false;
		for (int j = 0; j < listeUrlaubstage->Count; j++) {
			if (listeUrlaubstage[j]->getDatum() == unternehmen->getFeiertage()[i]->getDatum()) {
				schonInListe = true;
			}
		}
		if (!schonInListe) {
			this->addFeiertag(unternehmen->getFeiertage()[i]->getDatum());
		}
	}
	
	//Exception-Handling, weil evtl. eine Null-Reference-Exception auftreten kann.
	try {
		//Solangen der Tag in der aktuellen Woche liegt, wird gepürft.
		while (kWDynamisch == kWHeute) {
			//Prüfe: Ist der Tag ein Urlaubstag
			if (this->istUrlaubstag(*tagDynamisch)) {
				Int32 index = this->indexVonUrlaubstag(*tagDynamisch);
				if (!listeUrlaubstage[index]->getEingerechnet()) {
					anzFreieTage++;
					listeUrlaubstage[index]->setEingerechnet(true);
				}
			}
			//Prüfe: Ist der Tag ein Krankheitstag
			if (this->istKrankheitstag(*tagDynamisch)) {
				Int32 index = this->indexVonKrankheitstag(*tagDynamisch);
				if (!krankheitsTage[index]->getEingerechnet()) {
					anzFreieTage++;
					krankheitsTage[index]->setEingerechnet(true);
				}
			}
			tagDynamisch = tagDynamisch->AddDays(1.0);
			kWDynamisch = kalender->berechneKW(*tagDynamisch);
		}
	}
	catch (System::NullReferenceException ^) {
		anzFreieTage = 0;
	}
	
	//Stunden und Minuten berechnen, die in dieser Woche durch die freien Tage weniger gearbeitet werden müssen
	Double tagesArbeitszeit = (Double) wochenstunden / 5;
	Double abzugArbeitszeit = tagesArbeitszeit * anzFreieTage;
	Int32 wenigerStunden = (Int32)abzugArbeitszeit;
	Int32 wenigerMinuten = (Int32) (abzugArbeitszeit - wenigerStunden) * 60;
	
	//Diese Zeit von den ArbeitsStunden und Minuten dieser Woche abziehen
	if (anzFreieTage > 0) {
		this->zieheZeitAb(wenigerStunden, wenigerMinuten);
	}

	//Jetzt werden die Krankmeldungen geprüft, die weiter zurückliegen als nur diese Woche (max 6 Wochen zurückliegend wird geprüft).
	//Exception-Handling, weil evtl. eine Null-Reference-Exception auftreten kann.
	anzFreieTage = 0;
	tagDynamisch = kalender->ersterTagDieserWoche()->AddDays(-3.0);
	kWDynamisch = kalender->berechneKW(tagDynamisch);

	try {
		//Solangen der Tag nicht länger als 6 Wochen zurückliegt, wird geprüft.
		while (kWDynamisch >= kWHeute - 6) {
			//Prüfe: Ist der Tag ein Krankheitstag
			if (this->istKrankheitstag(*tagDynamisch)) {
				Int32 index = this->indexVonKrankheitstag(*tagDynamisch);
				if (!krankheitsTage[index]->getEingerechnet()) {
					anzFreieTage++;
					krankheitsTage[index]->setEingerechnet(true);
				}
			}
			tagDynamisch = tagDynamisch->AddDays(-1.0);
			kWDynamisch = kalender->berechneKW(*tagDynamisch);
		}
	}
	catch (System::NullReferenceException ^) {
		anzFreieTage = 0;
	}
	//Stunden und Minuten berechnen, die in dieser Woche durch die freien Tage weniger gearbeitet werden müssen
	abzugArbeitszeit = tagesArbeitszeit * anzFreieTage;
	wenigerStunden = (Int32)abzugArbeitszeit;
	wenigerMinuten = (Int32) (abzugArbeitszeit - wenigerStunden) * 60;

	if (anzFreieTage > 0) {
		setUeberstundenGesamt(wenigerStunden, wenigerMinuten);
	}
}

/*Entfernt Urlaubstage in einem bestimten Zeitraum (Datum von - Datum bis) aus der Liste der Urlaubstage und erstellt eine Nachricht
für den Betroffenen Angestellten, die alle Urlaubstage enthält, die entfernt wurden.*/
void Angestellter::loescheUrlaubstage(DateTime von, DateTime bis, String^ kommentar)
{
	String^ urlaubEntferntString = "Ihre Urlaubstage\n\n";
	Int32 anzGeloeschteTageDieseWoche = 0;
	Int32 anzGeloeschteTageVergangenheit = 0;
	//Alle Tage im Zeitraum von - bis werden durchlaufen
	while (von <= bis) {
		for (int i = 0; i < listeUrlaubstage->Count; i++) {
			//Urlaubstage in diesem Zeitraum werden aus der Liste entfernt und zur Nachricht hinzugefügt
			if (listeUrlaubstage[i]->getDatum().Equals(von) && !listeUrlaubstage[i]->getIstFeiertag()) {
				//Die Anzahl der Urlaubstage, die in der aktuellen Woche gelöscht werden, wird gezählt
				if (kalender->berechneKW(DateTime::Now) == kalender->berechneKW(von) && listeUrlaubstage[i]->getEingerechnet()) {
					anzGeloeschteTageDieseWoche++;
				}
				//Die Anzahl der Urlaubstage, die in vergangenen Wochen gelöscht werden, wird gezählt
				else if (kalender->berechneKW(DateTime::Now) > kalender->berechneKW(von) && listeUrlaubstage[i]->getEingerechnet()) {
					anzGeloeschteTageVergangenheit++;
				}
				removeUrlaubstag(von);
				urlaubEntferntString += von.ToString("dddd, dd. MMMM yyyy") + "\n";
			}
		}
		von = von.AddDays(1.0);
	}
	urlaubEntferntString += "\nmussten leider gestrichen werden.\n\nKommentar: " + kommentar 
		+ "\n\nBei Fragen wenden Sie sich bitte an Ihren Vorgesetzten.";
	antragsInfos->Add(urlaubEntferntString);

	//Wochenzeit wieder draufrechnen
	Int32 gesamtminuten = anzGeloeschteTageDieseWoche * (wochenstunden * 60 / 5);
	Int32 gesamtstunden = gesamtminuten / 60;
	gesamtminuten -= gesamtstunden * 60;
	this->zieheZeitAb(-gesamtstunden, -gesamtminuten);

	//Für Tage in der Vergangenheit werden die Überstunden korrigiert
	gesamtminuten = anzGeloeschteTageVergangenheit * (wochenstunden * 60 / 5);
	gesamtstunden = gesamtminuten / 60;
	gesamtminuten -= gesamtstunden * 60;
	this->setUeberstundenGesamt(-gesamtstunden, -gesamtminuten);
}

void Angestellter::loescheKrankheitstage(DateTime von, DateTime bis, String^ kommentar)
{
	String^ krankheitstageEntferntString = "Ihre Krankheitstage\n\n";
	Int32 anzGeloeschteTageDieseWoche = 0;
	Int32 anzGeloeschteTageVergangenheit = 0;
	//Alle Tage im Zeitraum von - bis werden durchlaufen
	while (von <= bis) {
		for (int i = 0; i < krankheitsTage->Count; i++) {
			//Krankheitstage in diesem Zeitraum werden aus der Liste entfernt und zur Nachricht hinzugefügt
			if (krankheitsTage[i]->getDatum().Equals(von)) {
				//Die Anzahl der Krankheitstage, die in der aktuellen Woche gelöscht werden, wird gezählt
				if (kalender->berechneKW(DateTime::Now) == kalender->berechneKW(von) && krankheitsTage[i]->getEingerechnet()) {
					anzGeloeschteTageDieseWoche++;
				}
				//Die Anzahl der Krankheitstage, die weiter in der Vergangenheit liegen, wird gezählt
				else if (kalender->berechneKW(DateTime::Now) > kalender->berechneKW(von) && krankheitsTage[i]->getEingerechnet()) {
					anzGeloeschteTageVergangenheit++;
				}
				removeKrankheitstag(von);
				krankheitstageEntferntString += von.ToString("dddd, dd. MMMM yyyy") + "\n";
			}
		}
		von = von.AddDays(1.0);
	}
	krankheitstageEntferntString += "\nmussten leider gestrichen werden.\n\nKommentar: " + kommentar
		+ "\n\nBei Fragen wenden Sie sich bitte an Ihren Vorgesetzten.";
	antragsInfos->Add(krankheitstageEntferntString);

	//Wochenzeit wieder draufrechnen
	Int32 gesamtminuten = anzGeloeschteTageDieseWoche * (wochenstunden * 60 / 5);
	Int32 gesamtstunden = gesamtminuten / 60;
	gesamtminuten -= gesamtstunden * 60;
	this->zieheZeitAb(-gesamtstunden, -gesamtminuten);

	//Für Tage in der Vergangenheit werden die Überstunden korrigiert
	gesamtminuten = anzGeloeschteTageVergangenheit * (wochenstunden * 60 / 5);
	gesamtstunden = gesamtminuten / 60;
	gesamtminuten -= gesamtstunden * 60;
	this->setUeberstundenGesamt(-gesamtstunden, -gesamtminuten);
}

/*Gibt einen String^ zurück, der das Datum mit Wochentag aller Urlaubstage eines Angestellten und (falls true übergeben wird) aller Feiertage dieses Jahr getrennt 
ausgibt. Bei Übergabe von false nur die Urlaubs- ohne Feiertage*/
String^ Angestellter::freieTageAnzeigen(Boolean mitFeiertagen) {
	String^ urlaubstageString = mitFeiertagen ? "Ihre Urlaubstage:\n\n" : "Urlaubstage von " + vorname + " " + nachname + ":\n\n";
	//Die Liste der Urlaubstage wird durchlaufen
	for (int i = 0; i < listeUrlaubstage->Count; i++) {
		//Alle Urlaubstage aus diesem oder späteren Jahren werden dem String hinzugefügt
		if (listeUrlaubstage[i]->getDatum().Year >= DateTime::Now.Year && !listeUrlaubstage[i]->getIstFeiertag()) {
			urlaubstageString += listeUrlaubstage[i]->getDatum().ToString("dddd, dd. MMMM yyyy") + "\n";
		}
	}
	//Urlaubstage zählen, die keine Feiertage sind
	Int32 anzahlUrlaubstage = 0;
	for (int i = 0; i < listeUrlaubstage->Count; i++) {
		if (!listeUrlaubstage[i]->getIstFeiertag()) {
			anzahlUrlaubstage++;
		}
	}
	//Wenn für dieses Jahr keine Urlaubstage in der Liste stehen:
	if (anzahlUrlaubstage == 0) {
		urlaubstageString += "Noch keine bestätigten Urlaubstage.\n";
	}
	if (mitFeiertagen) {
		urlaubstageString += "\nFeiertage " + Convert::ToString(DateTime::Now.Year) + ":\n\n";
		//Liste der Feiertage wird durchlaufen
		for (int i = 0; i < listeUrlaubstage->Count; i++) {
			//Alle Feiertag dieses Jahres werden dem String hinzugefügt
			if (listeUrlaubstage[i]->getDatum().Year == DateTime::Now.Year && listeUrlaubstage[i]->getIstFeiertag()) {
				urlaubstageString += listeUrlaubstage[i]->getDatum().ToString("dddd, dd. MMMM yyyy") + "\n";
			}
		}
	}
	return urlaubstageString;
}

/*Gibt einen String^ zurück, der das Datum mit Wochentag aller Krankheitstage eines Angestellten anzeigt*/
String^ Angestellter::krankheitstageAnzeigen() {
	String^ krankheitstageString = "Krankheitstage von " + vorname + " " + nachname + ":\n\n";
	Int32 anzahl = 0;
	//Die Liste der Urlaubstage wird durchlaufen
	for (int i = 0; i < krankheitsTage->Count; i++) {
		//Alle Urlaubstage aus diesem Jahr werden dem String hinzugefügt
		if (krankheitsTage[i]->getDatum().Year == DateTime::Now.Year) {
			krankheitstageString += krankheitsTage[i]->getDatum().ToString("dddd, dd. MMMM yyyy") + "\n";
			anzahl++;
		}
	}
	//Wenn für dieses Jahr keine Krankheitstage in der Liste stehen:
	if (anzahl == 0) {
		krankheitstageString += "Noch keine Krankheitstage.\n";
	}
	return krankheitstageString;
}

//Es wird eine Nachricht zu einem Änderungsantrag als Antwort erstellt und den AntragsInfos hinzugefügt
void Angestellter::aenderungAntwort(String^ tag, String^ kommentar, Boolean bestaetigt) {
	
	String^ textZumAntrag;
	//Fall: Änderungsantrag wurde bestätigt
	if (bestaetigt) {
		textZumAntrag = "Ihr Änderungsantrag betreffend " + tag + " wurde bestätigt und wird korrigiert.";
		if (kommentar->Length > 0) {
			textZumAntrag += "\n\nKommentar:\n" + kommentar;
		}
	}
	//Fall: Änderungsantrag wurde abgelehnt
	else {
		textZumAntrag = "Ihr Änderungsantrag betreffend " + tag + " wurde abgelehnt.";
		if (kommentar->Length > 0) {
			textZumAntrag += "\n\nKommentar:\n" + kommentar;
		}
	}
	this->addAntragsInfo(textZumAntrag);
}