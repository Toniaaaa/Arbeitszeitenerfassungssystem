#include "Unternehmen.h"

using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System::IO;

Unternehmen::Unternehmen()
{
	
}

Unternehmen::Unternehmen(String^ file)
{
	abteilungen = gcnew List<Abteilung^>;
	Abteilung^ administration;
	Vorgesetzter^ admin = gcnew Vorgesetzter("Admin", "istrator", administration, "1", "1234", 169);
	administration = gcnew Abteilung("1", admin);
	this->file = file;
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

void Unternehmen::speichern()
{
	FileStream^ filestream = File::Create(file);
	BinaryFormatter^ binary = gcnew BinaryFormatter();
	binary->Serialize(filestream, this);
	filestream->Close();
}

void Unternehmen::laden(Unternehmen^ unternehmen)
{
	FileStream^ filestream = File::OpenRead(file);
	BinaryFormatter^ binary = gcnew BinaryFormatter();
	unternehmen = (Unternehmen^)binary->Deserialize(filestream);
	filestream->Close();
}

String ^ Unternehmen::getFile()
{
	return file;
}

void Unternehmen::setFile(String ^ file)
{
	this->file = file;
}
