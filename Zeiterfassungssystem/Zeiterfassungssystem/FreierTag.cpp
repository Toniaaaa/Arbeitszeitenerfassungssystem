#include "FreierTag.h"

FreierTag::FreierTag(DateTime datum, Boolean feiertag)
{
	this->datum = datum.Date;
	this->eingerechnet = false;
	this->istFeiertag = feiertag;
}

FreierTag::~FreierTag()
{
}
