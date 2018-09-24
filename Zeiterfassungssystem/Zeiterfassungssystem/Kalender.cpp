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
	//"Kultur" wird auf deutsch gestellt
	CultureInfo^ meinCI = gcnew CultureInfo("de");
	//Ein Kalender nach deutschem (mitteleuropäischem) Standard wird erstellt
	Calendar^ meinKalender = meinCI->Calendar;
	//Die Regel, nach der Kalenderwochen gezählt werden, wird so eingestellt, dass die KW1 mit dem ersten Kalendertag beginnt
	CalendarWeekRule^ meineCWR = meinCI->DateTimeFormat->CalendarWeekRule;
	//Der Erste Wochentag wird als Montag gesetzt
	DayOfWeek^ meinErsterWochentag = meinCI->DateTimeFormat->FirstDayOfWeek;
	//Die KW des übergebenen Tages wird berechnet und zurückgegeben
	return meinKalender->GetWeekOfYear(*tag, *meineCWR, *meinErsterWochentag);
}