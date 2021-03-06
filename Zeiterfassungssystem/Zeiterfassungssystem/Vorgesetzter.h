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
	Boolean istAdmin;

public:
	Vorgesetzter(String^ vorname, String^ nachname, Abteilung^ abteilung, String^ personalnummer, array<Byte>^ passwort, Int32 wochenstunden, Int32 urlaubstage, Boolean istAdmin);
	Vorgesetzter(Mitarbeiter^ mitarbeiterAlt, Boolean istAdmin);
	Vorgesetzter(Vorgesetzter^ vorgesetzter);

	void addUrlaubsantrag(Urlaubsantrag^ neuerAntrag);
	void removeUrlaubsantrag(Int32 index);
	void addAenderungsantrag(Aenderungsantrag^ neuerAntrag);
	void removeAenderungsantrag(Int32 index);

	inline List<Urlaubsantrag^>^ getUrlaubsantraege() { return listeUrlaubsantraege; }
	inline List<Aenderungsantrag^>^ getAenderungsantraege() { return listeAenderungsantraege; }

	bool istVorgesetzter() override;
	inline Boolean getIstAdmin() { return istAdmin; }
	inline void setIstAdmin(Boolean istAdmin) { this->istAdmin = istAdmin; }
};