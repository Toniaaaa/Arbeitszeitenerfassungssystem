#include "Mitarbeiter.h"

//Konstruktor
Mitarbeiter::Mitarbeiter(String ^ vorname, String ^ nachname, Abteilung ^ abteilung, String ^ personalnummer, String ^ passwort, Int32 wochenstunden, Int32 urlaubstage, Vorgesetzter^ vorgesetzter) :
	Angestellter(vorname, nachname, abteilung, personalnummer, passwort, wochenstunden, urlaubstage)
{
	this->vorgesetzter = vorgesetzter;
}

//Setter für den Vorgesetzten das Mitarbeiters
void Mitarbeiter::setVorgesetzter(Vorgesetzter^ vorgesetzter)
{
	this->vorgesetzter = vorgesetzter;
}

//Gibt zurück, dass der Mitarbeiter kein Vorgesetzter ist.
bool Mitarbeiter::istVorgesetzter()
{
	return false;
}
