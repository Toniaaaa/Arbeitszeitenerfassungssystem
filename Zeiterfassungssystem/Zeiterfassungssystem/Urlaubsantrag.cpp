#include "Urlaubsantrag.h"

using namespace System;

Urlaubsantrag::Urlaubsantrag(Angestellter^ antragsteller, DateTime anfang, DateTime ende, Int32 tage, String^ kommentarAntragsteller) {
	this->m_Antragsteller = antragsteller;
	this->m_Anfang = anfang;
	this->m_Ende = ende;
	this->m_Tage = tage;
	this->m_KommentarAntragsteller = kommentarAntragsteller;
}

Urlaubsantrag::~Urlaubsantrag() {

}

//Setter
void Urlaubsantrag::setKommentarAntragsteller(String^ kommentar)
{
	this->m_KommentarAntragsteller = kommentar;
}

void Urlaubsantrag::setKommentarVorgesetzter(String^ kommentar)
{
	this->m_KommentarVorgesetzter = kommentar;
}