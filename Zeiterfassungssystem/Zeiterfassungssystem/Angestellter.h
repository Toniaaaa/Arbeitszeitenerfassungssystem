#pragma once

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;

ref class Angestellter 
{
private:
	String^ vorname;
	String^ nachname;
	Abteilung^ abteilung;
	String^ personalnummer;
	String^ passwort;
	Int32^ monatsstunden;
	List <Events^>^ listeEvents;

public:
	Angestellter(String^ vorname, String^ nachname, Abteilung^ abteilung, String^ personalnummer, String^ passwort, Int32^ monatsstunden);

	inline String^ getVorname() {return vorname;}
	
	inline String^ getNachname() {return nachname;}

	Abteilung^ getAbteilung();

	inline String^ personalnummer() { return personalnummer; }
	inline String^ passwort() { return passwort; };
	inline Int32^ monatsstunden() { return monatsstunden; }




};