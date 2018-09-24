#include "FreierTagComparer.h"

FreierTagComparer::FreierTagComparer()
{
}

//Überschreibt die Compare-Methode des Interfaces und sortiert die FreierTag-Objekte nach ihrem Datum.
int FreierTagComparer::Compare(FreierTag^ x, FreierTag^ y)
{
	return DateTime::Compare(x->getDatum(), y->getDatum());
}
