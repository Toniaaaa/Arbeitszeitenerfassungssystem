#pragma once
#include "Abteilung.h"

using namespace System;
using namespace System::Collections::Generic;
ref class Unternehmen
{
private:
	List<Abteilung^>^ abteilungen;
	String^ file;

public:
	Unternehmen(String^ file);
	Int32 getAnzahlAbteilungen();
	Abteilung^ getAbteilung(Int32 index);
	void removeAbteilung(Int32 index);
	void addAbteilung(Abteilung^ abteilung);
	List<Angestellter^>^ getAlleAngestellte();
	void speichern();
	void laden(Unternehmen^ unternehmen);
	String^ getFile();
	void setFile(String^ file);
};

