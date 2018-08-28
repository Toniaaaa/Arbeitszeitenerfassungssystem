#include "Vorgesetzter.h"

Vorgesetzter::Vorgesetzter(String ^ vorname, String ^ nachname, Abteilung ^ abteilung, String ^ personalnummer, String ^ passwort, Int32 monatsstunden) :
	Angestellter(vorname, nachname, abteilung, personalnummer, passwort, monatsstunden)
{
	
}

bool Vorgesetzter::istVorgesetzter()
{
	return true;
}
