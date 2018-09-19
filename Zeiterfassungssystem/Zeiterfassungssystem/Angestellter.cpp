#include "Angestellter.h"
#include "Ereignis.h"

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
	this->urlaubstageGenommen = 0;
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
}

Int32 Angestellter::getRestUrlaub() 
{
	return urlaubstage + urlaubstageGespart - urlaubstageGenommen;
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
	ueberStundenGesamt += (stunden + minuten / 60);
}

//Gibt den Zeitpunkt des letzten Einloggens zurück.
DateTime^ Angestellter::getLetzterArbeitstag() 
{
	DateTime^ result = nullptr;
	if (listeEreignisse->Count > 0) {
		result = listeEreignisse[listeEreignisse->Count - 1]->getTimestamp()->Date;
	}
	return result;
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
		//Prüfe, ob dieser Tag ein Samstag oder Sonntag ist
		if (!istFeiertag && beginn.DayOfWeek != DayOfWeek::Saturday && beginn.DayOfWeek != DayOfWeek::Sunday) {
			//Tag wird der Liste hinzugefügt und ein Tag den genommenen Urlaubstagen hinzugefügt.
			listeUrlaubstage->Add(gcnew FreierTag(beginn));
			urlaubstageGenommen++;
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
		//Prüfe, ob dieser Tag ein Samstag oder Sonntag ist
		if (!istFeiertag && beginn.DayOfWeek != DayOfWeek::Saturday && beginn.DayOfWeek != DayOfWeek::Sunday) {
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

void Angestellter::zieheMinutenAb(Int32 minuten) {
	this->arbeitsMinuten -= minuten;
	if (arbeitsMinuten < 0) {
		this->arbeitsStunden -= (Int32)(-arbeitsMinuten / 60) + 1;
		this->arbeitsMinuten = 60 - ((-arbeitsMinuten) % 60);
	}
}