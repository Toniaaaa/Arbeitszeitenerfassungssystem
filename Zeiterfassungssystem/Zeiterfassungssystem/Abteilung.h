#pragma once
#include "Vorgesetzter.h"
#include "Angestellter.h"

using namespace System;
using namespace System::Collections::Generic;

ref class Abteilung
{
private:
	String ^ abteilungsNummer;
	Vorgesetzter^ vorgesetzter;
	List<Angestellter^>^ angestelltenListe;

public:
	Abteilung(String^ abteilungsnummer, Vorgesetzter^ vorgesetzer);
	String^ getAbteilungsnummer();
	Vorgesetzter^ getVorgesetzter();

	void setVorgesetzter(Vorgesetzter^ vorgesetzter);


};

