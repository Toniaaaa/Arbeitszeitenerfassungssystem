#pragma once

#include <ctime>

using namespace System;

enum EreignisTyp {
	// NICHTN ÄNDERN
	// viele Teile der Logik basieren darauf, dass es nur diese vier Arten an Ereignissen gibt
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
};

