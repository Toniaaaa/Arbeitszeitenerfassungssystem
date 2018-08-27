#pragma once
#include "Vorgesetzter.h"
#include "Angestellter.h"
#include "Mitarbeiter.h"

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;

ref class Abteilung
{
private:
	String ^ abteilungsNummer;
	Vorgesetzter^ vorgesetzter;
	List<Mitarbeiter^>^ mitarbeiter;

public:
	Abteilung(String^ abteilungsnummer, Vorgesetzter^ vorgesetzer);

	String^ getAbteilungsnummer();
	Vorgesetzter^ getVorgesetzter();
	void setVorgesetzter(Vorgesetzter^ vorgesetzter);
	Mitarbeiter^ getMitarbeiter(Int32 index);
	void fuegeMitarbeiterHinzu(Mitarbeiter^ mitarbeiter);
	Int32 getAnzahlMitarbeiter();
	void removeMitarbeiter(Int32 index);



};

