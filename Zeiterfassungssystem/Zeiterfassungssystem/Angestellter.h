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
	Int32 sekunde;
	Int32 minute;
	Int32 stunde;
	Int32 pauseSekunde;
	Int32 pauseMinute;
	Int32 pauseStunde;

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
	
	Ereignis^ getEreignis(Int32 index);
	Int32 getAnzahlEreignisse();
	Int32 getAnzahlArbeitstage();

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

	// Ereignislisteauswertungsmethodensammlung

	DateTime^ getArbeitsAnfang(); // null wenn arbeitstag (noch) nicht begonnen
	DateTime^ getPauseAnfang(); // null wenn pause gerade nicht läuft
	TimeSpan^ getAktuelleArbeitszeit();
	TimeSpan^ getAktuellePausenzeit();
	void setAktuelleArbeitszeit(Int32 sekunde, Int32 minute, Int32 stunde);
	void setAktuellePausenzeit(Int32 pauseSekunde, Int32 pauseMinute, Int32 pauseStunde);
};
