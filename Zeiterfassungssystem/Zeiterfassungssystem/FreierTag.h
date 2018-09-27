#pragma once
#include <ctime>

using namespace System;

[Serializable]
ref class FreierTag
{

private:
	DateTime datum;
	Boolean eingerechnet;

public:
	//Konstruktor und Destruktor
	FreierTag(DateTime datum);
	~FreierTag();

	//Einfache Getter und Setter
	inline DateTime getDatum() { return datum; }
	inline Boolean getEingerechnet() { return eingerechnet; }
	inline void setEingerechnet(Boolean eingerechnet) { this->eingerechnet = eingerechnet; }
	
};

