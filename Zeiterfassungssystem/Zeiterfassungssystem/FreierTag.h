#pragma once
#include <ctime>

using namespace System;

[Serializable]
ref class FreierTag
{

private:
	DateTime datum;
	Boolean eingerechnet;
	Boolean istFeiertag;

public:
	//Konstruktor und Destruktor
	FreierTag(DateTime datum, Boolean feiertag);
	~FreierTag();

	//Einfache Getter und Setter
	inline DateTime getDatum() { return datum; }
	inline Boolean getEingerechnet() { return eingerechnet; }
	inline Boolean getIstFeiertag() { return istFeiertag; }
	inline void setEingerechnet(Boolean eingerechnet) { this->eingerechnet = eingerechnet; }
	
};

