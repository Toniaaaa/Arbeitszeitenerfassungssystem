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

	//Ein Kalender nach deutschem (mitteleurop�ischem) Standard wird erstellt
	Calendar^ meinKalender = meinCI->Calendar;

	//Die Regel, nach der Kalenderwochen gez�hlt werden, wird so eingestellt, dass die KW1 mit dem ersten Kalendertag beginnt
	CalendarWeekRule^ meineCWR = meinCI->DateTimeFormat->CalendarWeekRule;

	//Der Erste Wochentag wird als Montag gesetzt
	DayOfWeek^ meinErsterWochentag = meinCI->DateTimeFormat->FirstDayOfWeek;

	//Die KW des �bergebenen Tages wird berechnet und zur�ckgegeben
	return meinKalender->GetWeekOfYear(*tag, *meineCWR, *meinErsterWochentag);
}

//Gibt den ersten Tag dieser Kalenderwoche zur�ck
DateTime^ Kalender::ersterTagDieserWoche()
{
	//Wenn heute Montag ist, wird heute als erster Tag dieser Woche gesetzt
	DateTime^ tag = DateTime::Now.Date;

	//Ansonsten wird nach dem ersten Montag in der Vergangenheit gesucht
	while (tag->DayOfWeek != DayOfWeek::Monday) {
		tag = tag->AddDays(-1.0);
	}
	return tag;
}