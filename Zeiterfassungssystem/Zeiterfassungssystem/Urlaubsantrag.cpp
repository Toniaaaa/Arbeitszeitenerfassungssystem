#include "Urlaubsantrag.h"

using namespace System;

Urlaubsantrag::Urlaubsantrag(Angestellter^ antragsteller, DateTime anfang, DateTime ende, Int32 tage) {
	this->m_Antragsteller = antragsteller;
	this->m_Anfang = anfang;
	this->m_Ende = ende;
	this->m_Tage = tage;
}

Urlaubsantrag::~Urlaubsantrag() {

}

//Setter
void Urlaubsantrag::setKommentar(String^ kommentar)
{
	this->m_Kommentar = kommentar;
}

Int32 Urlaubsantrag::berechneTage(DateTime^ anfang, DateTime^ ende) {
	
	return 0;
}
