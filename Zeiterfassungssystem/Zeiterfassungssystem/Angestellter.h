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
	Int32 wochenstunden;
	Int32 urlaubstage;
	List<Ereignis^>^ listeEreignisse;

public:
	Angestellter(String^ vorname, String^ nachname, Abteilung^ abteilung, String^ personalnummer, String^ passwort, Int32 wochenstunden, Int32 urlaubstage);

	//Getter
	inline String^ getVorname() {return vorname;}
	inline String^ getNachname() {return nachname;}
	Abteilung^ getAbteilung();
	inline String^ getPersonalnummer() {return personalnummer;}
	inline String^ getPasswort() {return passwort;};
	inline Int32 getWochensstunden() {return wochenstunden;}
	inline Int32 getUrlaubstage() {return urlaubstage;}
	List<Ereignis^>^ getAlleEreignisse();
	Ereignis^ getEreignis(Int32 index);
	Int32 getAnzahlEreignisse();

	//Setter
	inline void setVorname(String^ vorname) {this->vorname = vorname;}
	inline void setNachname(String^ nachname) {this->nachname = nachname;}
	inline void setAbteilung(Abteilung^ abteilung) {this->abteilung = abteilung;}
	inline void setPersonalnummer(String^ personalnummer) {this->personalnummer = personalnummer;}
	inline void setPasswort(String^ passwort) {this->passwort = passwort;}
	inline void setWochenstunden(Int32 wochenstunden) {this->wochenstunden = wochenstunden;}
	inline void setUrlaubstage(Int32 urlaubstage) {this->urlaubstage = urlaubstage;}
	virtual bool istVorgesetzter() = 0;
	void fuegeEreignisHinzu(Ereignis^ ereignis);
	void removeEreignis(Int32 index);

};
