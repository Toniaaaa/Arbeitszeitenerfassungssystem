#pragma once

using namespace System;
using namespace System::Globalization;

[Serializable]
ref class Kalender
{
public:
	//Konstruktor und Destruktor
	Kalender();
	~Kalender();

	//Berechnet die Kalenderwoche des übergebenen Tags
	Int32 berechneKW(DateTime^ tag);
	DateTime^ ersterTagDieserWoche();
};

