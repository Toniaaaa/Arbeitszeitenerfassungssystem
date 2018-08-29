#include "Vorgesetzter.h"

Vorgesetzter::Vorgesetzter(String ^ vorname, String ^ nachname, Abteilung ^ abteilung, String ^ personalnummer, String ^ passwort, Int32^ wochenstunden, Int32^ urlaubstage) :
	Angestellter(vorname, nachname, abteilung, personalnummer, passwort, wochenstunden, urlaubstage)
{
	
}

bool Vorgesetzter::istVorgesetzter()
{
	return true;
}
