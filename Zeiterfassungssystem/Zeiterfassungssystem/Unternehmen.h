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
	//Der spatere Name der Datei
	static String^ SPEICHERORT = "TimeUp.dat";

	//Das Unternehmen wird ueber diese Methode aus der Datei gelesen//geladen
	static Unternehmen^ ladeUnternehmen(String^ file);

	//Das Unternehmen wird in Datei geschrieben
	void speichern();

	Int32 getAnzahlAbteilungen();
	Abteilung^ getAbteilung(Int32 index);
	void removeAbteilung(Int32 index);
	void addAbteilung(Abteilung^ abteilung);
	List<Angestellter^>^ getAlleAngestellte();

	//Prueft die Logindaten gleicht sie ab und gibt den Status zurueck ob Daten passen
	Angestellter^ loginaccept(String^ personalnummer, array<Byte>^ passwort);
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
