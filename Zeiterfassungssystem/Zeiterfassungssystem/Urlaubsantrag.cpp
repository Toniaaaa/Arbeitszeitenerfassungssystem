#include "Urlaubsantrag.h"

using namespace System;

Urlaubsantrag::Urlaubsantrag()
{
}

Urlaubsantrag::Urlaubsantrag(DateTime anfang, DateTime ende, Int32 tage) {
	this->m_Anfang = anfang;
	this->m_Ende = ende;
	this->m_Tage = tage;
}

Urlaubsantrag::~Urlaubsantrag() {

}

//Setter
void Urlaubsantrag::setAnfang(DateTime anfang) {
	this->m_Anfang = anfang;
}

void Urlaubsantrag::setEnde(DateTime ende) {
	this->m_Ende = ende;
}

void Urlaubsantrag::setTage(Int32 tage) {
	this->m_Tage = tage;
}

Int32 Urlaubsantrag::berechneTage(DateTime^ anfang, DateTime^ ende) {
	
	return 0;
}
