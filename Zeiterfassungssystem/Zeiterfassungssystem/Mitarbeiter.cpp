#include "Mitarbeiter.h"

Mitarbeiter::Mitarbeiter(String ^ vorname, String ^ nachname, Abteilung ^ abteilung, String ^ personalnummer, String ^ passwort, Int32 wochenstunden, Int32 urlaubstage, Vorgesetzter^ vorgesetzter) :
	Angestellter(vorname, nachname, abteilung, personalnummer, passwort, wochenstunden, urlaubstage)
{
	this->vorgesetzter = vorgesetzter;
}

void Mitarbeiter::setVorgesetzter(Vorgesetzter^ vorgesetzter)
{
	this->vorgesetzter = vorgesetzter;
}

bool Mitarbeiter::istVorgesetzter()
{
	return false;
}
