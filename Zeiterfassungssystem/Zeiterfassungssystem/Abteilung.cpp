#include "Abteilung.h"

Abteilung::Abteilung(String ^ abteilungsnummer, Vorgesetzter ^ vorgesetzer)
{
	this->abteilungsNummer = abteilungsnummer;
	this->vorgesetzter = vorgesetzer;
	mitarbeiter = gcnew List<Mitarbeiter^>;
}


String ^ Abteilung::getAbteilungsnummer()
{
	return abteilungsNummer;
}

Vorgesetzter ^ Abteilung::getVorgesetzter()
{
	return vorgesetzter;
}

void Abteilung::setVorgesetzter(Vorgesetzter ^ vorgesetzter)
{
	this->vorgesetzter = vorgesetzter;
}

Mitarbeiter ^ Abteilung::getMitarbeiter(Int32 index)
{
	return mitarbeiter[index];
}

void Abteilung::fuegeMitarbeiterHinzu(Mitarbeiter ^ mitarbeiter)
{
	this->mitarbeiter->Add(mitarbeiter);
}

Int32 Abteilung::getAnzahlMitarbeiter()
{
	return mitarbeiter->Count;
}

void Abteilung::removeMitarbeiter(Int32 index)
{
	mitarbeiter->RemoveAt(index);
}
