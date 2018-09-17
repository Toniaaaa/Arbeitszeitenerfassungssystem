#pragma once

#include <ctime>

using namespace System;

enum EreignisTyp {
	EINGELOGGT,
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

