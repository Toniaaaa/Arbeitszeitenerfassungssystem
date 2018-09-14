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
private:
	List<Aenderungsantrag^>^ listeAenderungsantraege;
	List<Urlaubsantrag^>^ listeUrlaubsantraege;

public:
	Vorgesetzter(String^ vorname, String^ nachname, Abteilung^ abteilung, String^ personalnummer, String^ passwort, Int32 wochenstunden, Int32 urlaubstage);

	void addUrlaubsantrag(Urlaubsantrag^ neuerAntrag);
	void removeUrlaubsantrag(Int32 index);
	void addAenderungsantrag(Aenderungsantrag^ neuerAntrag);
	void removeAenderungsantrag(Int32 index);

	bool istVorgesetzter() override;
};
