#pragma once
#include "Angestellter.h"
#include "Abteilung.h"

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;

[Serializable]
ref class Vorgesetzter : 
	public Angestellter
{

public:
	Vorgesetzter(String^ vorname, String^ nachname, Abteilung^ abteilung, String^ personalnummer, String^ passwort, Int32 wochenstunden, Int32 urlaubstage);

	bool istVorgesetzter() override;
};
