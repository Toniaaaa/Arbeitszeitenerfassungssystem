#include "Angestellter.h"
#include "Ereignis.h"

Angestellter::Angestellter(String ^ vorname, String ^ nachname, Abteilung ^ abteilung, String ^ personalnummer, String ^ passwort, Int32 wochenstunden, Int32 urlaubstage)
{
	this->vorname = vorname;
	this->nachname = nachname;
	this->abteilung = abteilung;
	this->personalnummer = personalnummer;
	this->passwort = passwort;
	this->wochenstunden = wochenstunden;
	this->urlaubstage = urlaubstage;
	listeEreignisse = gcnew List<Ereignis^>;
	this->wochenZeitErreicht = false;
	this->arbeitsStunden = wochenstunden;
	this->arbeitsMinuten = 0;
	this->ueberStunden = 0;
	this->ueberMinuten = 0;
	this->ueberStundenGesamt = 0.0;
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

void Angestellter::beendeArbeitstag(Int32 stunden, Int32 minuten, Boolean erreicht) 
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

DateTime^ Angestellter::getLetzterArbeitstag() 
{
	return this->getArbeitsAnfang()->Date;
}