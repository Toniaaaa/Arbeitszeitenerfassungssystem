#include "Aenderungsantrag.h"

Aenderungsantrag::Aenderungsantrag(Angestellter^ antragsteller, Int32 blockindex, DateTime^ anfang, DateTime^ ende, String^ grund, String^ kommentar)
{
	this->m_Antragsteller = antragsteller;
	this->m_Anfang = anfang;
	this->m_Ende = ende;
	this->m_blockindex = m_blockindex;
	this->m_Kommentar = kommentar;
	this->m_Grund = grund;
}

Aenderungsantrag::~Aenderungsantrag()
{
}
