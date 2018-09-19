#pragma once

using namespace System;
using namespace System::Globalization;

[Serializable]
ref class Kalender
{
public:
	Kalender();
	~Kalender();
	Int32 berechneKW(DateTime tag);
};

