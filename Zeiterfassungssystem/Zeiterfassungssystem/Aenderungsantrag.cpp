#include "Aenderungsantrag.h"

Aenderungsantrag::Aenderungsantrag(Angestellter^ antragsteller, Int32 blockindex, DateTime^ tag, DateTime^ anfang, DateTime^ ende, String^ grund, String^ kommentar)
{
	this->m_Antragsteller = antragsteller;
	this->m_Anfang = anfang;
	this->m_Ende = ende;
	this->m_Tag = tag;
	this->m_Kommentar = kommentar;
	this->m_Grund = grund;
	this->m_blockindex = m_blockindex;
}

Aenderungsantrag::~Aenderungsantrag()
{
}

//Setter

void Aenderungsantrag::setAnfang(DateTime^ anfang)
{
	this->m_Anfang = anfang;
}

void Aenderungsantrag::setEnde(DateTime^ ende)
{
	this->m_Ende = ende;
}

void Aenderungsantrag::setTag(DateTime^ tag)
{
	this->m_Tag = tag;
}

void Aenderungsantrag::setKommentar(String^ kommentar)
{
	this->m_Kommentar = kommentar;
}

void Aenderungsantrag::setGrund(String^ grund)
{
	this->m_Grund = grund;
}

void Aenderungsantrag::setAntragsteller(Angestellter^ antragsteller)
{
	this->m_Antragsteller = antragsteller;
}