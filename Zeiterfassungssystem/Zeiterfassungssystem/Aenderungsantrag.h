#pragma once

ref class Angestellter;
using namespace System;

[Serializable]
ref class Aenderungsantrag
{
private:

	//Membervariablen
	Angestellter^ m_Antragsteller;
	DateTime m_Tag;
	DateTime m_Anfang;
	DateTime m_Ende;
	String^ m_Grund;
	String^ m_KommentarAntragsteller;
	String^ m_KommentarVorgesetzter;

public:
	Aenderungsantrag(Angestellter^ antragsteller, DateTime tag, DateTime anfang, DateTime ende, String^ grund, String^ kommentar);
	~Aenderungsantrag();

	//Getter und Setter
	inline DateTime getAnfang() { return m_Anfang; }
	inline DateTime getEnde() { return m_Ende; }
	inline DateTime getTag() { return m_Tag; }
	inline String^ getGrund() { return m_Grund; }
	inline String^ getKommentarAntragsteller() { return m_KommentarAntragsteller; }
	inline String^ getKommentarVorgesetzter() { return m_KommentarVorgesetzter; }
	inline Angestellter^ getAntragsteller() { return m_Antragsteller; }
	
	void setKommentarVorgesetzter(String^ kommentar);
};
