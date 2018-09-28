#include "Vorgesetzter.h"
#include "Mitarbeiter.h"

//Konstruktor
Vorgesetzter::Vorgesetzter(String ^ vorname, String ^ nachname, Abteilung ^ abteilung, String ^ personalnummer, String ^ passwort, Int32 wochenstunden, Int32 urlaubstage, Boolean istAdmin) :
	Angestellter(vorname, nachname, abteilung, personalnummer, passwort, wochenstunden, urlaubstage)
{
	listeAenderungsantraege = gcnew List<Aenderungsantrag^>;
	listeUrlaubsantraege = gcnew List<Urlaubsantrag^>;
	this->istAdmin = istAdmin;
}

Vorgesetzter::Vorgesetzter(Mitarbeiter^ mitarbeiterAlt) : Angestellter(mitarbeiterAlt)
{
	listeAenderungsantraege = gcnew List<Aenderungsantrag^>;
	listeUrlaubsantraege = gcnew List<Urlaubsantrag^>;
	this->istAdmin = false;
}

//Gibt zurück, dass dieser Angestellte ein Vorgesetzter ist
bool Vorgesetzter::istVorgesetzter()
{
	return true;
}

//Fügt der Liste von Änderungsanträgen einen neuen übergebenen Antrag hinzu
void Vorgesetzter::addAenderungsantrag(Aenderungsantrag^ neuerAntrag)
{
	listeAenderungsantraege->Add(neuerAntrag);
}

//Entfernt einen Änderungsantrag an der übergebenen Stelle aus der Liste
void Vorgesetzter::removeAenderungsantrag(Int32 index)
{
	listeAenderungsantraege->RemoveAt(index);
}

//Fügt der Liste von Urlaubsanträgen einen neuen übergebenen Antrag hinzu
void Vorgesetzter::addUrlaubsantrag(Urlaubsantrag^ neuerAntrag)
{
	listeUrlaubsantraege->Add(neuerAntrag);
}

//Entfernt einen Urlaubsantrag an der übergebenen Stelle aus der Liste
void Vorgesetzter::removeUrlaubsantrag(Int32 index)
{
	listeUrlaubsantraege->RemoveAt(index);
}