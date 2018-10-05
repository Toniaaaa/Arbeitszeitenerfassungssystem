#pragma once

#include "Unternehmen.h"
#include "Aenderungsantrag.h"
#include "Urlaubsantrag.h"
#include "FreierTag.h"
#include "Kalender.h"
#include "Ereignis.h"
#include <ctime>
#include "FreierTagComparer.h"

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;

ref class Abteilung;
ref class Ereignis;
ref class Vorgesetzter;
ref class Mitarbeiter;

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
	List<FreierTag^>^ krankheitsTage;
	String^ status;
	Int32 arbeitsStunden;
	Int32 arbeitsMinuten;
	Int32 ueberStunden;
	Int32 ueberMinuten;
	Boolean wochenZeitErreicht;
	Double ueberStundenGesamt;
	DateTime letzterLogin;
	Kalender^ kalender;
	FreierTagComparer^ vergleichen;

public:
	Angestellter(String^ vorname, String^ nachname, Abteilung^ abteilung, String^ personalnummer, String^ passwort, Int32 wochenstunden, Int32 urlaubstage);
	Angestellter(Vorgesetzter^ vorgesetzterAlt);
	Angestellter(Mitarbeiter^ mitarbeiterAlt);

	//Getter
	inline String^ getVorname() {return vorname;}
	inline String^ getNachname() {return nachname;}
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
	inline List<FreierTag^>^ getKrankheitstage() { return krankheitsTage; }
	inline Int32 getUrlaubstageGespart() { return urlaubstageGespart; }
	inline List<FreierTag^>^ getListeUrlaubstage() { return listeUrlaubstage; }
	inline List <Ereignis^>^ getListeEreignisse() { return listeEreignisse; }
	inline List <Double>^ getListeGesamtstunden() { return listegesamtstunden; }
	inline DateTime getLetzterLogin() { return letzterLogin; }
	inline Int32 getJahresurlaub() { return jahresurlaub; }
	inline Abteilung^ getAbteilung() { return abteilung; }
	inline Ereignis^ getEreignis(Int32 index) { return listeEreignisse[index]; }
	inline Int32 getAnzahlEreignisse() { return listeEreignisse->Count; }
	inline String^ getStatus() { return status; }

	Int32 getRestUrlaub();

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
	inline void setAktuellenStatus(String^ status) { this->status = status; }

	void setUeberstundenGesamt(Int32 stunden, Int32 minuten);

	virtual bool istVorgesetzter() = 0;

	//Hinzufügen zu und entfernen aus Listen:
	void fuegeEreignisHinzu(Ereignis^ ereignis);
	void removeEreignis(Int32 index);
	void addAntragsInfo(String^ info);
	void removeAntragsInfo(Int32 index);
	void addUrlaubstag(DateTime tag);
	void addFeiertag(DateTime tag);
	void removeUrlaubstag(DateTime tag);
	void loescheAlleUrlaubstage();
	void loescheUrlaubstage(DateTime von, DateTime bis, String^ kommentar); //Löscht alle Urlaubstage innerhalb des übergebenen Zeitraums
	void loescheKrankheitstage(DateTime von, DateTime bis, String^ kommentar); //Löscht alle Krankheitstage innerhalb des übergebenen Zeitraums
	void addKrankheitstag(DateTime tag);
	void removeKrankheitstag(DateTime tag);

	//Weitere Methoden:
	void aenderungAntwort(String^ tag, String^ kommentar, Boolean bestaetigt);
	String^ freieTageAnzeigen(Boolean mitFeiertagen); //Gibt Aufzählung aller Feier- und Urlaubstage zurück
	String^ krankheitstageAnzeigen(); //Gibt Aufzählung aller Feier- und Urlaubstage zurück
	void speichereArbeitszeit();//Speichert die gesamte Arbeitszeit eines abgeschlossenen Tages in den noch-ArbeitsStunden und Minuten
	void nehmeUrlaub(DateTime beginn, DateTime ende); //Fügt die Tage innerhalb des Zeitraums zu der listeUrlaubstage hinzu, solange die keine Feiertage oder Wochenenden sind
	void krankMelden(DateTime beginn, DateTime ende); //Fügt die Tage innerhalb des Zeitraums zu den Krankheitstagen hinzu, solange die keine Feiertage oder Wochenenden sind und entfernt sie aus den Urlaubstagen
	Int32 berechneArbeitstage(DateTime beginn, DateTime ende); //Berechnet die Anzahl der Urlaubstage innerhalb eines Zeitraums ohne Wochenenden und Feiertage
	Int32 indexVonUrlaubstag(DateTime tag); //Gibt den Index eines Tages in der listeUrlaubstage zurück
	Int32 indexVonKrankheitstag(DateTime tag); //Gibt den Index eines Tages in der Liste der Krankheitstage zurück
	Boolean istUrlaubstag(DateTime tag); //Gibt zurück, ob der Paramter ein Urlaubstag ist oder nicht
	Boolean istKrankheitstag(DateTime tag); //Gibt zurück, ob der Paramter ein Krankheitstag ist oder nicht
	void zieheZeitAb(Int32 stunden, Int32 minuten); //Zieht Zeit von der Noch-Arbeitszeit ab bzw. addiert Überstunden, wenn die Wochen-Arbeitszeit erreicht ist
	TimeSpan getReduzierteZeit(Int32 stunden, Int32 minuten); //Gibt die Noch-Arbeitszeit um die übergebene Zeit reduziert zurück, ohne sie zu ändern
	Boolean dieseWocheEingeloggt(); //Gibt zurück, ob der letzte Login in dieser Woche war
	void stelleUraubstageZurueck(Int32 jahre); //Lösche Urlaubstage, die älter als die übergebene Zahl Jahre sind, und fuegt die festen, regelmäßige Urlaubstage des nächsten Jahres hinzu
	void neueWoche(); //Stellt alle Werte für den Beginn einer neuen Woche ein
	TimeSpan^ neuerTag(); //Beendet einen Arbeitstag nachträglich um 23:59 Uhr des Tages, an dem er begonnen wurde
	void freieTagePruefen(Unternehmen^ unternehmen); //Prüft, ob in dieser Woche ein noch nicht eingerechneter freier Tag vorhanden ist und rechnet die noch-Wochenarbeitszeit entsprechend um
	Int32 getArbeitsAnfangIndex(); //Gibt den Index des Arbeitsanfangs des aktuell noch nicht beendeten Arbeitstages in der Ereignisliste oder den Nullpointer (falls kein Arbeitstag läuft) zurück
	Int32 getArbeitsAnfangIndexNachArbeitstag(); //Gibt den Arbeitsanfang eines gerade beendeten Arbeitstages zurück

	// Ereignislisteauswertungsmethodensammlung
	DateTime^ getArbeitsAnfang(); // null wenn arbeitstag (noch) nicht begonnen
	DateTime^ getPauseAnfang(); // null wenn pause gerade nicht läuft
	TimeSpan^ getAktuelleArbeitszeit();
	TimeSpan^ getAktuellePausenzeit(); // liefert die Zeit der aktuell laufenden Pause
	TimeSpan^ getPausezeit(Boolean tagBeendet); // liefert die Zeit der bisherigen Pausen seit letztem Arbeitsbeginn
	TimeSpan^ berechneArbeitsstunden(Int32 anfangsEreignisIndex); //Berechnet die Arbeitszeit eines Arbeitstages ab dem übergebenen Index in der Ereignisliste ohne Pausen
	TimeSpan^ genugPause(); //Prüft, ob am gerade beendeten Arbeitstag genug Pause gemacht wurde
};