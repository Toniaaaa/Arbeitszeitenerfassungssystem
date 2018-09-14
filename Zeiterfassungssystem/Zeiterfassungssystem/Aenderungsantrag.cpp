#include "Aenderungsantrag.h"

Aenderungsantrag::Aenderungsantrag(Angestellter^ antragsteller, DateTime tag, DateTime anfang, DateTime ende, String^ grund, String^ kommentar)
{
	this->m_Antragsteller = antragsteller;
	this->m_Anfang = anfang;
	this->m_Ende = ende;
	this->m_Tag = tag;
	this->m_KommentarAntragsteller = kommentar;
	this->m_Grund = grund;
}

Aenderungsantrag::~Aenderungsantrag()
{
}

void Aenderungsantrag::setKommentarVorgesetzter(String^ kommentar)
{
	this->m_KommentarVorgesetzter = kommentar;
}