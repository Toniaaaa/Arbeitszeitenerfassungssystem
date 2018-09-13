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
	List<Double>^ listegesamtstunden;
	String^ status;
	Int32 arbeitsStunden;
	Int32 arbeitsMinuten;
	Int32 ueberStunden;
	Int32 ueberMinuten;
	Boolean wochenZeitErreicht;
	Double ueberStundenGesamt;

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
	inline Boolean getWochenZeitErreicht() {return wochenZeitErreicht;}
	inline Double getUeberstundenGesamt() { return ueberStundenGesamt; }
	inline Double getGesamtstunden(int index) { return listegesamtstunden[index]; }
	
	
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
	inline void setWochenZeitErreicht(Boolean erreicht) {this->wochenZeitErreicht = erreicht;}
	inline void setArbeitsStunden(Int32 stunden) { this->arbeitsStunden = stunden; }
	inline void setArbeitsMinuten(Int32 minuten) { this->arbeitsMinuten = minuten; }
	inline void setUeberStunden(Int32 stunden) { this->ueberStunden = stunden; }
	inline void setUeberMinuten(Int32 minuten) { this->ueberMinuten = minuten; }
	inline void setGesamtstunden(Double gesamtstunden) { listegesamtstunden->Add(gesamtstunden); }
	void setUeberstundenGesamt(Int32 stunden, Int32 minuten);
	virtual bool istVorgesetzter() = 0;
	void fuegeEreignisHinzu(Ereignis^ ereignis);
	void removeEreignis(Int32 index);

	//Hilfsmethoden
	inline Int32 getArbeitsStunden() { return arbeitsStunden; }
	inline Int32 getArbeitsMinuten() { return arbeitsMinuten; }
	inline Int32 getUeberStunden() { return ueberStunden; }
	inline Int32 getUeberMinuten() { return ueberMinuten; }
	void setAktuellenStatus(String^ status);
	String^ getStatus();
	void beendeArbeitstag(Int32 stunden, Int32 minuten, Boolean erreicht);
	// Ereignislisteauswertungsmethodensammlung

	DateTime^ getLetzterArbeitstag();
	DateTime^ getArbeitsAnfang(); // null wenn arbeitstag (noch) nicht begonnen
	DateTime^ getPauseAnfang(); // null wenn pause gerade nicht läuft
	TimeSpan^ getAktuelleArbeitszeit();
	TimeSpan^ getAktuellePausenzeit(); // liefert die Zeit der aktuell laufenden Pause
	TimeSpan^ getPausezeit(); // liefert die Zeit der bisherigen Pausen seit letztem Arbeitsbeginn
	//arbeitsblock speichert datetime anfang und ende, Timespan pausezeit, Timespan arbeitszeit
	//getarbeitsblöcke gui zeigt die an 

private:
	Int32 getArbeitsAnfangIndex();
};
