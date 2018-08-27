#include "Angestellter.h"



Angestellter::Angestellter(String ^ vorname, String ^ nachname, Abteilung ^ abteilung, String ^ personalnummer, String ^ passwort, Int32 monatsstunden)
{
	this->vorname = vorname;
	this->nachname = nachname;
	this->abteilung = abteilung;
	this->personalnummer = personalnummer;
	this->passwort = passwort;
	this->monatsstunden = monatsstunden;
	listeEvents = gcnew List<Ereignis^>;
}

Abteilung ^ Angestellter::getAbteilung()
{
	return abteilung;
}


