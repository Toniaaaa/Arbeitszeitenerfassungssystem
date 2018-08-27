#include "Unternehmen.h"

Unternehmen::Unternehmen()
{
	abteilungen = gcnew List<Abteilung^>;
}

Int32 Unternehmen::getAnzahlAbteilungen()
{
	return abteilungen->Count;
}

Abteilung ^ Unternehmen::getAbteilung(Int32 index)
{
	return abteilungen[index];
}

void Unternehmen::removeAbteilung(Int32 index)
{
	return abteilungen->RemoveAt(index);
}

void Unternehmen::addAbteilung(Abteilung ^ abteilung)
{
	abteilungen->Add(abteilung);
}

List<Angestellter^>^ Unternehmen::getAlleAngestellte()
{
	List<Angestellter^>^ angestellte = gcnew List<Angestellter^>;
	

	for (int i = 0; i < getAnzahlAbteilungen(); i++) {
		Abteilung^ abteilung = getAbteilung(i);
		angestellte->Add(abteilung->getVorgesetzter());
	}

	return angestellte;
}
