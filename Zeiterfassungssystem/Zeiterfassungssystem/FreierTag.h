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
	FreierTag(DateTime datum);
	~FreierTag();

	inline DateTime getDatum() { return datum; }
	inline Boolean getEingerechnet() { return eingerechnet; }
	inline void setEingerechnet(Boolean eingerechnet) { this->eingerechnet = eingerechnet; }
	
};

