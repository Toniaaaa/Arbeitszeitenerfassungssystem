#include "Unternehmen.h"
#include "Angestellter.h"
#include "Abteilung.h"
#include "Vorgesetzter.h"
#include "Mitarbeiter.h"

using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System::IO;

Unternehmen::Unternehmen()
{
	abteilungen = gcnew List<Abteilung^>;
	feiertage = gcnew List<FreierTag^>;

	Abteilung^ administration;
	Vorgesetzter^ admin = gcnew Vorgesetzter("Admin", "istrator", administration, "1", "1234", 169, 28);
	administration = gcnew Abteilung("1", admin);
	admin->setAbteilung(administration);
	abteilungen->Add(administration);
	this->erstelleRegelFeiertage(DateTime::Now.Year);
	this->erstelleRegelFeiertage((DateTime::Now.Year + 1));
}

Unternehmen^ Unternehmen::ladeUnternehmen(String^ file) {
	Unternehmen^ result;
	if (File::Exists(file)) {
		FileStream^ filestream = File::OpenRead(file);
		BinaryFormatter^ binary = gcnew BinaryFormatter();
		result = (Unternehmen^)binary->Deserialize(filestream);
		filestream->Close();
	}
	else {
		result = gcnew Unternehmen();
	}
	result->file = file;

	return result;
}

void Unternehmen::speichern()
{
	FileStream^ filestream = File::Create(file);
	BinaryFormatter^ binary = gcnew BinaryFormatter();
	binary->Serialize(filestream, this);
	filestream->Close();
}

Int32 Unternehmen::getAnzahlAbteilungen()
{
	return abteilungen->Count;
}

Abteilung ^ Unternehmen::getAbteilung(Int32 index)
{
	return abteilungen[index];
}

void Unternehmen::removeAbteilung(Int32 index)
{
	return abteilungen->RemoveAt(index);
}

void Unternehmen::addAbteilung(Abteilung ^ abteilung)
{
	abteilungen->Add(abteilung);
}

List<Angestellter^>^ Unternehmen::getAlleAngestellte()
{
	List<Angestellter^>^ angestellte = gcnew List<Angestellter^>;
	
	for (int i = 0; i < getAnzahlAbteilungen(); i++) {
		Abteilung^ abteilung = getAbteilung(i);
		angestellte->Add(abteilung->getVorgesetzter());
		for (int j = 0; j < abteilung->getAnzahlMitarbeiter(); j++) {
			angestellte->Add(abteilung->getMitarbeiter(j));
		}
	}

	return angestellte;
}

Angestellter ^ Unternehmen::loginaccept(String ^ personalnummer, String ^ passwort)
{
	List<Angestellter^>^ angestellte = getAlleAngestellte();
	Angestellter^ result = nullptr;

	bool gefunden = false;
	for (int i = 0; i < angestellte->Count && !gefunden; i++) {
		Angestellter^ angestellter = angestellte[i];

		if (angestellter->getPersonalnummer()->Equals(personalnummer)) {
			gefunden = true;

			if (angestellter->getPasswort()->Equals(passwort)) {
				result = angestellter;
			}
		}
	} 
	return result;
}

List<Abteilung^>^ Unternehmen::getAbteilungen()
{
	return abteilungen;
}

void Unternehmen::addFeiertag(DateTime tag)
{
	this->feiertage->Add(gcnew FreierTag(tag));
}

void Unternehmen::removeFeiertag(DateTime tag)
{
	for (int i = feiertage->Count - 1; i >= 0; i--) {
		if (feiertage[i]->getDatum() == tag) {
			feiertage->RemoveAt(i);
			break;
		}
	};
}

void Unternehmen::erstelleRegelFeiertage(Int32 jahr)
{
	for (int i = 0; i < feiertageRegel->Length; i = i + 2) {
		DateTime^ feiertag = gcnew DateTime(jahr, feiertageRegel[i + 1], feiertageRegel[i]);
		//Feiertag nur hinzufügen, wenn er noch nicht in der Liste existiert (z.B. durch manuelles Einfügen)
		FreierTag^ neuerFeiertag = gcnew FreierTag(*feiertag);
		if (!feiertage->Contains(neuerFeiertag)) {
			feiertage->Add(neuerFeiertag);
		}
	}
}

void Unternehmen::stelleFeiertageZurueck(Int32 jahre)
{
	for (int i = feiertage->Count - 1; i >= 0; i--) {
		if (feiertage[i]->getDatum().Year < (DateTime::Now.Year - 3)) {
			feiertage->RemoveAt(i);
		}
	}
	this->erstelleRegelFeiertage((DateTime::Now.Year + 1));
}

Boolean Unternehmen::istFeiertag(DateTime tag) 
{
	Boolean istFeiertag = false;
	for (int i = feiertage->Count - 1; i >= 0; i--) {
		if (feiertage[i]->getDatum().Date == tag) {
			istFeiertag = true;
			break;
		}
	}
	return istFeiertag;
}

Int32 Unternehmen::indexVon(DateTime tag)
{
	Int32 index = -1;
	for (int i = feiertage->Count - 1; i >= 0; i--) {
		if (feiertage[i]->getDatum().Date == tag) {
			index = i;
			break;
		}
	}
	return index;
}