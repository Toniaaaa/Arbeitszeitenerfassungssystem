#include "Kalender.h"

Kalender::Kalender()
{

}

Kalender::~Kalender()
{

}

//Kalenderwoche eines Tages berechnen 
Int32 Kalender::berechneKW(DateTime^ tag)
{
	CultureInfo^ meinCI = gcnew CultureInfo("de");
	Calendar^ meinKalender = meinCI->Calendar;
	CalendarWeekRule^ meineCWR = meinCI->DateTimeFormat->CalendarWeekRule;
	DayOfWeek^ meinErsterWochentag = meinCI->DateTimeFormat->FirstDayOfWeek;
	return meinKalender->GetWeekOfYear(*tag, *meineCWR, *meinErsterWochentag);
}