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
