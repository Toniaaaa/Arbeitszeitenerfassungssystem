#include "FreierTag.h"

FreierTag::FreierTag(DateTime datum)
{
	this->datum = datum.Date;
	this->eingerechnet = false;
}

FreierTag::~FreierTag()
{
}
