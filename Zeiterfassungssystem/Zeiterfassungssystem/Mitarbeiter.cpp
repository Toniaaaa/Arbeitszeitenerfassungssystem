#include "Mitarbeiter.h"


Mitarbeiter::Mitarbeiter(String ^ vorname, String ^ nachname, Abteilung ^ abteilung, String ^ personalnummer, String ^ passwort, Int32 monatsstunden) :
	Angestellter(vorname, nachname, abteilung, personalnummer, passwort, monatsstunden)
{
}

bool Mitarbeiter::istVorgesetzter()
{
	return false;
}
