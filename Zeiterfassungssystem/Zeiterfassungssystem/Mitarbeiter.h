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
private:
	Vorgesetzter^ vorgesetzter;

public:
	Mitarbeiter(String^ vorname, String^ nachname, Abteilung^ abteilung, String^ personalnummer, array<Byte>^ passwort, Int32 wochenstunden, Int32 urlaubstage, Vorgesetzter^ vorgesetzter);
	Mitarbeiter(Vorgesetzter^ vorgesetzerAlt, Vorgesetzter^ vorgesetzterNeu);

	inline Vorgesetzter^ getVorgesetzter() { return vorgesetzter; }

	void setVorgesetzter(Vorgesetzter^ vorgesetzter);

	bool istVorgesetzter() override;
};