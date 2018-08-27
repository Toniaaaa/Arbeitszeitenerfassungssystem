#include "Angestellter.h"



Angestellter::Angestellter()
{
}

Angestellter::Angestellter(String ^ vorname, String ^ nachname, Abteilung ^ abteilung, String ^ personalnummer, String ^ passwort, Int32 ^ monatsstunden)
{
	throw gcnew System::NotImplementedException();
}

Abteilung ^ Angestellter::getAbteilung()
{
	return abteilung;
}


