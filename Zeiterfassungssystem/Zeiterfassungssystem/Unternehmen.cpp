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
	Abteilung^ administration;
	Vorgesetzter^ admin = gcnew Vorgesetzter("Admin", "istrator", administration, "1", "1234", 169, 28);
	administration = gcnew Abteilung("1", admin);
	admin->setAbteilung(administration);
	Mitarbeiter^ mitarbeiter = gcnew Mitarbeiter("Antonia", "Sensen", administration, "288740", "hallo", 40, 28);
	administration->fuegeMitarbeiterHinzu(mitarbeiter);
	mitarbeiter->setAbteilung(administration);
	abteilungen->Add(administration);
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
