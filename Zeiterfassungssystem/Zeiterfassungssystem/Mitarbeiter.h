#pragma once
#include "Angestellter.h"

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;
ref class Vorgesetzter;

[Serializable]
ref class Mitarbeiter :
	public Angestellter
{
public:
	Mitarbeiter(String^ vorname, String^ nachname, Abteilung^ abteilung, String^ personalnummer, String^ passwort, Int32 wochenstunden, Int32 urlaubstage);

	bool istVorgesetzter() override;
};