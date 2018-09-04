#pragma once

using namespace System;

[Serializable]
ref class Urlaubsantrag
{
private:

	//Membervariablen:
	DateTime m_Anfang;
	DateTime m_Ende;

public:

	//Konstruktoren und Destruktor:
	Urlaubsantrag(DateTime anfang, DateTime ende);
	~Urlaubsantrag();

	//Getter und Setter
	inline DateTime getAnfang() { return m_Anfang; }
	inline DateTime getEnde() { return m_Ende; }
	void setAnfang(DateTime anfang);
	void setEnde(DateTime ende);

	//Weitere Methoden:
	Int32 berechneTage(DateTime^ anfang, DateTime^ ende);

};

