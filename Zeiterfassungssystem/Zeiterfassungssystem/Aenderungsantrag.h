#pragma once

ref class Angestellter;
using namespace System;

[Serializable]
ref class Aenderungsantrag
{
private:

	//Membervariablen
	Angestellter^ m_Antragsteller;
	Int32 m_blockindex;
	DateTime^ m_Anfang;
	DateTime^ m_Ende;
	String^ m_Grund;
	String^ m_Kommentar;

public:
	Aenderungsantrag(Angestellter^ antragsteller, Int32 blockindex, DateTime^ anfang, DateTime^ ende, String^ grund, String^ kommentar);
	~Aenderungsantrag();

	//Getter und Setter
	inline DateTime^ getAnfang() { return m_Anfang; }
	inline DateTime^ getEnde() { return m_Ende; }
	inline Int32 getBlockIndex() { return m_blockindex; }
	inline String^ getGrund() { return m_Grund; }
	inline String^ getKommentar() { return m_Kommentar; }
	inline Angestellter^ getAntragsteller() { return m_Antragsteller; }
};