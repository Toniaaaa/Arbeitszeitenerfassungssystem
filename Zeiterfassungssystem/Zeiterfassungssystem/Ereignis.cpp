#include "Ereignis.h"

Ereignis::Ereignis(EreignisTyp typ, DateTime  timestamp)
{
	this->typ = typ;
	this->timestamp = timestamp;
}

EreignisTyp Ereignis::getTyp()
{
	return typ;
}

DateTime  Ereignis::getTimestamp()
{
	return timestamp;
}
