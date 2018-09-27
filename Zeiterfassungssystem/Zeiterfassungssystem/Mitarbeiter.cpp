#include "Mitarbeiter.h"

//Konstruktor
Mitarbeiter::Mitarbeiter(String ^ vorname, String ^ nachname, Abteilung ^ abteilung, String ^ personalnummer, String ^ passwort, Int32 wochenstunden, Int32 urlaubstage, Vorgesetzter^ vorgesetzter, Boolean istAdmin) :
	Angestellter(vorname, nachname, abteilung, personalnummer, passwort, wochenstunden, urlaubstage, istAdmin)
{
	this->vorgesetzter = vorgesetzter;
}

//Setter f�r den Vorgesetzten das Mitarbeiters
void Mitarbeiter::setVorgesetzter(Vorgesetzter^ vorgesetzter)
{
	this->vorgesetzter = vorgesetzter;
}

//Gibt zur�ck, dass der Mitarbeiter kein Vorgesetzter ist.
bool Mitarbeiter::istVorgesetzter()
{
	return false;
}
