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

	//Berechnet die Kalenderwoche des �bergebenen Tags
	Int32 berechneKW(DateTime^ tag);

	//Gibt den ersten Tag dieser Kalenderwoche zur�ck
	DateTime^ ersterTagDieserWoche();
};

