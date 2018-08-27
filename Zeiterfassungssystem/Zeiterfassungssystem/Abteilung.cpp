#include "Abteilung.h"





Abteilung::Abteilung(String ^ abteilungsnummer, Vorgesetzter ^ vorgesetzer)
{
	this->abteilungsNummer = abteilungsNummer;
	this->vorgesetzter = vorgesetzer;
	angestelltenListe = gcnew List<Angestellter^>;
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
