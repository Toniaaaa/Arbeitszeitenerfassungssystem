#pragma once

#include <ctime>

using namespace System;

//Ueber die Typen koennen spaeter passende Abfragen stattfinden und 
//die passenden Zeitstempel gefunden werden
enum EreignisTyp {
	ARBEIT_START,
	ARBEIT_ENDE,
	PAUSE_START,
	PAUSE_ENDE,
};

[Serializable]
ref class Ereignis
{
private:
	EreignisTyp typ;
	DateTime timestamp;

public:
	Ereignis(EreignisTyp typ, DateTime^ timestamp);

	EreignisTyp getTyp();
	DateTime^ getTimestamp();
	void setTimestamp(DateTime timestamp);
};

