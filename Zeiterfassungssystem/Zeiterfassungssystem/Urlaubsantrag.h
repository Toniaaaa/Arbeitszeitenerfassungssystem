#pragma once
#include "Angestellter.h"

using namespace System;

[Serializable]
ref class Urlaubsantrag
{
private:

	//Membervariablen:
	Angestellter^ m_Antragsteller;
	DateTime m_Anfang;
	DateTime m_Ende;
	Int32 m_Tage;
	String^ m_KommentarAntragsteller;
	String^ m_KommentarVorgesetzter;

public:

	//Konstruktoren und Destruktor:
	Urlaubsantrag(Angestellter^ antragsteller, DateTime anfang, DateTime ende, Int32 Tage, String^ kommentarAntragsteller);
	~Urlaubsantrag();

	//Getter und Setter
	inline Angestellter^ getAntragsteller() { return m_Antragsteller; }
	inline DateTime getAnfang() { return m_Anfang; }
	inline DateTime getEnde() { return m_Ende; }
	inline int getTage() { return m_Tage; }
	inline String^ getKommentarAntragsteller() { return m_KommentarAntragsteller; }
	inline String^ getKommentarVorgesetzter() { return m_KommentarVorgesetzter; }

	void setKommentarAntragsteller(String^ kommentar);
	void setKommentarVorgesetzter(String^ kommentar);

	//Weitere Methoden:
	Int32 berechneTage(DateTime^ anfang, DateTime^ ende);

};

