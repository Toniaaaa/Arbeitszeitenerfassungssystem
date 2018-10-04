#include "Mitarbeiter.h"
#include "Vorgesetzter.h"

//Konstruktor
Mitarbeiter::Mitarbeiter(String ^ vorname, String ^ nachname, Abteilung ^ abteilung, String ^ personalnummer, String ^ passwort, Int32 wochenstunden, Int32 urlaubstage, Vorgesetzter^ vorgesetzter) :
	Angestellter(vorname, nachname, abteilung, personalnummer, passwort, wochenstunden, urlaubstage)
{
	this->vorgesetzter = vorgesetzter;
}

//Konstruktor zum Umwandeln eines Vorgesetzten in einen Mitarbeiter
Mitarbeiter::Mitarbeiter(Vorgesetzter^ vorgesetzterAlt, Vorgesetzter^ vorgesetzterNeu) : Angestellter(vorgesetzterAlt)
{
	this->vorgesetzter = vorgesetzterNeu;
}

//Setter für den Vorgesetzten des Mitarbeiters
void Mitarbeiter::setVorgesetzter(Vorgesetzter^ vorgesetzter)
{
	this->vorgesetzter = vorgesetzter;
}

//Gibt zurück, dass der Mitarbeiter kein Vorgesetzter ist
bool Mitarbeiter::istVorgesetzter()
{
	return false;
}
