#pragma once

ref class Angestellter;
using namespace System;

[Serializable]
ref class Aenderungsantrag
{
private:

	//Membervariablen
	Angestellter^ m_Antragsteller;

	Int32 startIndex;
	DateTime newStart;
	DateTime newEnd;

	String^ m_Grund;
	String^ m_KommentarAntragsteller;
	String^ m_KommentarVorgesetzter;

public:
	Aenderungsantrag(Angestellter^ antragsteller, Int32 startIndex, DateTime newStart, DateTime newEnd, String^ grund, String^ kommentar);
	~Aenderungsantrag();

	//Getter und Setter
	inline Int32 getStartIndex() { return startIndex; }
	inline DateTime^ getNewStart() { return newStart; }
	inline DateTime^ getNewEnd() { return newEnd; }
	inline String^ getGrund() { return m_Grund; }
	inline String^ getKommentarAntragsteller() { return m_KommentarAntragsteller; }
	inline String^ getKommentarVorgesetzter() { return m_KommentarVorgesetzter; }
	inline Angestellter^ getAntragsteller() { return m_Antragsteller; }
	
	void setKommentarVorgesetzter(String^ kommentar);
};
