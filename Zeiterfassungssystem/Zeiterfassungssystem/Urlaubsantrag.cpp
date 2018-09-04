#include "Urlaubsantrag.h"

using namespace System;

Urlaubsantrag::Urlaubsantrag(DateTime anfang, DateTime ende) {
	this->m_Anfang = anfang;
	this->m_Ende = ende;
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

Int32 Urlaubsantrag::berechneTage(DateTime^ anfang, DateTime^ ende) {
	
	return 0;
}
