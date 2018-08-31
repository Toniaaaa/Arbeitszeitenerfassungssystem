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
	
}

Abteilung ^ Angestellter::getAbteilung()
{
	return abteilung;
}

List<Ereignis^>^ Angestellter::getAlleEreignisse()
{
	return listeEreignisse;
}

Ereignis ^ Angestellter::getEreignis(Int32 index)
{
	return listeEreignisse[index];
}

Int32 Angestellter::getAnzahlEreignisse()
{
	return listeEreignisse->Count;
}

void Angestellter::fuegeArbeitszeitHinzu(Int32 arbeitszeit)
{
	arbeitszeitenliste.Add(arbeitszeit);
}

Int32 Angestellter::getAnzahlArbeitstage()
{
	return arbeitszeitenliste.Count;
}

void Angestellter::fuegeEreignisHinzu(Ereignis^ ereignis)
{
	listeEreignisse->Add(ereignis);
}

void Angestellter::removeEreignis(Int32 index)
{
	listeEreignisse->RemoveAt(index);
}

Int32 Angestellter::berechneZeitstunden()
{
	DateTime anfang;
	DateTime ende;
	DateTime pauseanfang;
	DateTime pauseende;

	for (int i = 0; i < listeEreignisse->Count; i++) {

		if (listeEreignisse[i]->getTyp() == ARBEIT_START) {
			anfang = listeEreignisse[i]->getTimestamp();
		}
		if (listeEreignisse[i]->getTyp() == PAUSE_START) {
			pauseanfang = listeEreignisse[i]->getTimestamp();
		}
	
		if (listeEreignisse[i]->getTyp() == PAUSE_ENDE) {
			pauseende = listeEreignisse[i]->getTimestamp();
		}
		
		if (listeEreignisse[i]->getTyp() == ARBEIT_ENDE) {
			ende = listeEreignisse[i]->getTimestamp();
		}
	}

	
		Int32 pause = DateTime::Compare(pauseanfang, pauseende);
		Int32 arbeitszeit = DateTime::Compare(anfang, ende) - pause;
		return arbeitszeit;
	
}
		
		



