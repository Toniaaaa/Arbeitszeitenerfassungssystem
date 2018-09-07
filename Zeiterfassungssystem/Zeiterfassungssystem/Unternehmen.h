#pragma once

using namespace System;
using namespace System::Collections::Generic;

ref class Abteilung;
ref class Angestellter;

[Serializable]
ref class Unternehmen
{
private:
	List<Abteilung^>^ abteilungen;
	String^ file;

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

};
