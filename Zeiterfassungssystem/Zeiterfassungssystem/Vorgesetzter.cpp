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

//Gibt zur�ck, dass dieser Angestellte ein Vorgesetzter ist
bool Vorgesetzter::istVorgesetzter()
{
	return true;
}

//F�gt der Liste von �nderungsantr�gen einen neuen �bergebenen Antrag hinzu
void Vorgesetzter::addAenderungsantrag(Aenderungsantrag^ neuerAntrag)
{
	listeAenderungsantraege->Add(neuerAntrag);
}

//Entfernt einen �nderungsantrag an der �bergebenen Stelle aus der Liste
void Vorgesetzter::removeAenderungsantrag(Int32 index)
{
	listeAenderungsantraege->RemoveAt(index);
}

//F�gt der Liste von Urlaubsantr�gen einen neuen �bergebenen Antrag hinzu
void Vorgesetzter::addUrlaubsantrag(Urlaubsantrag^ neuerAntrag)
{
	listeUrlaubsantraege->Add(neuerAntrag);
}

//Entfernt einen Urlaubsantrag an der �bergebenen Stelle aus der Liste
void Vorgesetzter::removeUrlaubsantrag(Int32 index)
{
	listeUrlaubsantraege->RemoveAt(index);
}