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

public:

	//Konstruktoren und Destruktor:
	Urlaubsantrag(Angestellter^ antragsteller, DateTime anfang, DateTime ende, Int32 Tage);
	~Urlaubsantrag();

	//Getter und Setter
	inline Angestellter^ getAntragsteller() { return m_Antragsteller; }
	inline DateTime getAnfang() { return m_Anfang; }
	inline DateTime getEnde() { return m_Ende; }
	inline int getTage() { return m_Tage; }
	void setAntragsteller(Angestellter^ antragsteller);
	void setAnfang(DateTime anfang);
	void setEnde(DateTime ende);
	void setTage(Int32 tage);

	//Weitere Methoden:
	Int32 berechneTage(DateTime^ anfang, DateTime^ ende);

};

