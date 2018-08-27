#pragma once
#include "Angestellter.h"

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;

ref class Vorgesetzter : 
	public Angestellter
{
public:
	Vorgesetzter(String^ vorname, String^ nachname, Abteilung^ abteilung, String^ personalnummer, String^ passwort, Int32 monatsstunden);

	bool istVorgesetzter() override;
};

