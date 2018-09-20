#include "Aenderungsantrag.h"

Aenderungsantrag::Aenderungsantrag(Angestellter^ antragsteller, Int32 startIndex, DateTime newStart, DateTime newEnd, String^ grund, String^ kommentar)
{
	this->m_Antragsteller = antragsteller;
	this->startIndex = startIndex;
	this->newStart = newStart;
	this->newEnd = newEnd;
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