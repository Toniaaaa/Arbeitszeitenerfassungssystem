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
	int Compare(FreierTag^ x, FreierTag^ y) override;
};