#pragma once
#include"FreierTag.h"

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;

[Serializable]
ref class FreierTagComparer : System::Collections::Generic::IComparer<FreierTag^>
{
public:
	FreierTagComparer();

	//Überschreibt die Compare-Methode des Interfaces und sortiert die FreierTag-Objekte nach ihrem Datum
	int virtual Compare(FreierTag^ x, FreierTag^ y);
};