#pragma once

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;

ref class Abteilung;
ref class Ereignis;

[Serializable]
ref class Angestellter 
{
private:
	String^ vorname;
	String^ nachname;
	Abteilung^ abteilung;
	String^ personalnummer;
	String^ passwort;
	Int32 monatsstunden;
	List<Ereignis^>^ listeEreignisse;//gettter und setter

public:
	Angestellter(String^ vorname, String^ nachname, Abteilung^ abteilung, String^ personalnummer, String^ passwort, Int32 monatsstunden);

	//Getter
	inline String^ getVorname() {return vorname;}
	inline String^ getNachname() {return nachname;}
	Abteilung^ getAbteilung();
	inline String^ getPersonalnummer() { return personalnummer; }
	inline String^ getPasswort() { return passwort; };
	inline Int32 getMonatsstunden() { return monatsstunden; }
	List<Ereignis^>^ getAlleEreignisse();
	Ereignis^ getEreignis(Int32 index);
	Int32^ getAnzahlEreignisse();

	//Setter
	inline void setVorname(String^ vorname) { this->vorname = vorname; }
	inline void setNachname(String^ nachname) { this->nachname = nachname; }
	inline void setAbteilung(Abteilung^ abteilung) { this->abteilung = abteilung; }
	inline void setPersonalnummer(String^ personalnummer) { this->personalnummer = personalnummer; }
	inline void setPasswort(String^ passwort) { this->passwort = passwort; }
	inline void setMonatsstunden(Int32 monatstunden) { this->monatsstunden = monatsstunden; }
	virtual bool istVorgesetzter() = 0;
	void fuegeEreignisHinzu(Ereignis^ ereignis);
	void removeEreignis(Int32 index);

};
