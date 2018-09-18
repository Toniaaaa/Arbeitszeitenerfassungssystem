#pragma once
#include "FreierTag.h"

using namespace System;
using namespace System::Collections::Generic;

ref class Abteilung;
ref class Angestellter;

[Serializable]
ref class Unternehmen
{
private:
	List<Abteilung^>^ abteilungen;
	List<FreierTag^>^ feiertage;
	String^ file;

	Unternehmen();

public:
	static String^ SPEICHERORT = "Rebellion.dat";
	static array<Int32>^ feiertageRegel = {1, 1, 1, 5, 3, 10, 25, 12, 26, 12};
	static Unternehmen^ ladeUnternehmen(String^ file);
	void speichern();

	Int32 getAnzahlAbteilungen();
	Abteilung^ getAbteilung(Int32 index);
	void removeAbteilung(Int32 index);
	void addAbteilung(Abteilung^ abteilung);
	List<Angestellter^>^ getAlleAngestellte();
	Angestellter^ loginaccept(String^ personalnummer, String^ passwort);
	List<Abteilung^>^ getAbteilungen();
	inline List<FreierTag^>^ getFeiertage() { return feiertage; }
	void addFeiertag(DateTime tag);
	void removeFeiertag(DateTime tag);
	void erstelleRegelFeiertage();
	void loescheAlteFeiertage();
	Boolean istFeiertag(DateTime tag);
};
