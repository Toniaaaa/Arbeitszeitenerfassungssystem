#include "Aenderungsantrag.h"

Aenderungsantrag::Aenderungsantrag(Angestellter^ antragsteller, Int32 startIndex, DateTime newStart, DateTime newEnd, DateTime oldStart, DateTime oldEnd, String^ grund, String^ kommentar)
{
	this->m_Antragsteller = antragsteller;
	this->startIndex = startIndex;
	this->newStart = newStart;
	this->newEnd = newEnd;
	this->oldStart = oldStart;
	this->oldEnd = oldEnd;
	this->m_KommentarAntragsteller = kommentar;
	this->m_Grund = grund;
}

Aenderungsantrag::~Aenderungsantrag()
{
}