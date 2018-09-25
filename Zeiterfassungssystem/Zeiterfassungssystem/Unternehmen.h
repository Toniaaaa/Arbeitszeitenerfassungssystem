#pragma once
#include "FreierTag.h"
#include"FreierTagComparer.h"

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
	FreierTagComparer^ vergleichen;
	Unternehmen();

public:
	static String^ SPEICHERORT = "Rebellion.dat";
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
	void erstelleRegelFeiertage(Int32 jahr);
	void stelleFeiertageZurueck(Int32 jahre);
	Boolean istFeiertag(DateTime tag);
	Int32 indexVon(DateTime tag);
	String^ feiertageAnzeigen();
};
