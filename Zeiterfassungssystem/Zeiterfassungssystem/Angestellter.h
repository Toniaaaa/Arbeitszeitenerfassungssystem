#pragma once

#include "Unternehmen.h"
#include "Aenderungsantrag.h"
#include "Urlaubsantrag.h"
#include "FreierTag.h"
#include "Kalender.h"
#include "Ereignis.h"
#include <ctime>

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
	Int32 jahresurlaub;
	Int32 urlaubstage;
	Int32 urlaubstageGespart;
	List<FreierTag^>^ listeUrlaubstage;
	List<Ereignis^>^ listeEreignisse;
	List<Double>^ listegesamtstunden;
	List<String^>^ antragsInfos;
	String^ status;
	Int32 arbeitsStunden;
	Int32 arbeitsMinuten;
	Int32 ueberStunden;
	Int32 ueberMinuten;
	Boolean wochenZeitErreicht;
	Double ueberStundenGesamt;
	DateTime letzterLogin;
	Kalender^ kalender;

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
	inline Int32 getArbeitsStunden() { return arbeitsStunden; }
	inline Int32 getArbeitsMinuten() { return arbeitsMinuten; }
	inline Int32 getUeberStunden() { return ueberStunden; }
	inline Int32 getUeberMinuten() { return ueberMinuten; }
	inline List<String^>^ getAntragsInfos() { return antragsInfos; }
	inline Int32 getUrlaubstageGespart() { return urlaubstageGespart; }
	inline List<FreierTag^>^ getListeUrlaubstage() { return listeUrlaubstage; }
	inline DateTime getLetzterLogin() { return letzterLogin; }
	inline Int32 getJahresurlaub() { return jahresurlaub; }
	
	Int32 getRestUrlaub();
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
	inline void setUrlaubstageGespart(Int32 urlaubstage) { this->urlaubstageGespart = urlaubstage; }
	inline void setWochenZeitErreicht(Boolean erreicht) {this->wochenZeitErreicht = erreicht;}
	inline void setArbeitsStunden(Int32 stunden) { this->arbeitsStunden = stunden; }
	inline void setArbeitsMinuten(Int32 minuten) { this->arbeitsMinuten = minuten; }
	inline void setUeberStunden(Int32 stunden) { this->ueberStunden = stunden; }
	inline void setUeberMinuten(Int32 minuten) { this->ueberMinuten = minuten; }
	inline void setGesamtstunden(Double gesamtstunden) { this->listegesamtstunden->Add(gesamtstunden); }
	inline void setLetzterLogin(DateTime jetzt) { this->letzterLogin = jetzt; }
	void setUeberstundenGesamt(Int32 stunden, Int32 minuten);
	virtual bool istVorgesetzter() = 0;
	void fuegeEreignisHinzu(Ereignis^ ereignis);
	void removeEreignis(Int32 index);
	void addAntragsInfo(String^ info);
	void removeAntragsInfo(Int32 index);
	void addUrlaubstag(DateTime tag);
	void removeUrlaubstag(DateTime tag);
	void loescheAlleUrlaubstage();

	//Hilfsmethoden
	void setAktuellenStatus(String^ status);
	String^ getStatus();
	void speichereArbeitszeit(Int32 stunden, Int32 minuten, Boolean erreicht);
	void nehmeUrlaub(DateTime beginn, DateTime ende, List<FreierTag^>^ feiertage);
	Int32 berechneUrlaubstage(DateTime beginn, DateTime ende, List<FreierTag^>^ feiertage);
	Int32 indexVon(DateTime tag);
	Boolean istUrlaubstag(DateTime tag);
	void zieheZeitAb(Int32 stunden, Int32 minuten);
	TimeSpan getReduzierteZeit(Int32 stunden, Int32 minuten);
	Boolean dieseWocheEingeloggt();
	void stelleUraubstageZurueck(Int32 jahre);
	void neueWoche();
	void freieTagePruefen(Unternehmen^ unternehmen);

	// Ereignislisteauswertungsmethodensammlung

	DateTime^ getArbeitsAnfang(); // null wenn arbeitstag (noch) nicht begonnen
	DateTime^ getPauseAnfang(); // null wenn pause gerade nicht läuft
	TimeSpan^ getAktuelleArbeitszeit();
	TimeSpan^ getAktuellePausenzeit(); // liefert die Zeit der aktuell laufenden Pause
	TimeSpan^ getPausezeit(); // liefert die Zeit der bisherigen Pausen seit letztem Arbeitsbeginn
	TimeSpan^ berechneArbeitsstunden(Int32 anfangsEreignisIndex);

private:
	Int32 getArbeitsAnfangIndex();
};
