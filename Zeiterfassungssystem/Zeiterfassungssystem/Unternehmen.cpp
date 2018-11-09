#include "Unternehmen.h"
#include "Angestellter.h"
#include "Abteilung.h"
#include "Vorgesetzter.h"
#include "Mitarbeiter.h"

using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System::IO;
using namespace System::Windows::Forms;

//Konstruktor
Unternehmen::Unternehmen()
{
	abteilungen = gcnew List<Abteilung^>;
	feiertage = gcnew List<FreierTag^>;
	this->erstelleRegelFeiertage(DateTime::Now.Year);
	this->erstelleRegelFeiertage((DateTime::Now.Year + 1));
	this->vergleichen = gcnew FreierTagComparer();
}

//L�dt gespeichertes Unternehmen aus einer Datei mit dem �bergebenen Dateinamen
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

//Speichert das Unternehmen in einer Datei
void Unternehmen::speichern()
{
	FileStream^ filestream = File::Create(file);
	BinaryFormatter^ binary = gcnew BinaryFormatter();
	binary->Serialize(filestream, this);
	filestream->Close();
}

//Gibt die Anzahl der Elemente in der Abteilungsliste zur�ck
Int32 Unternehmen::getAnzahlAbteilungen()
{
	Int32 anzAbt;
	try {
		anzAbt = abteilungen->Count;
	}
	catch (NullReferenceException ^) {
		anzAbt = 0;
	}
	return anzAbt;
}

//Gibt eine Abteilung aus der Abteilungsliste an der Stelle index zur�ck
Abteilung ^ Unternehmen::getAbteilung(Int32 index)
{
	return abteilungen[index];
}

//Entfernt eine Abteilung aus der Abteilungsliste an der Stelle index
void Unternehmen::removeAbteilung(Int32 index)
{
	return abteilungen->RemoveAt(index);
}

//F�gt der Abteilungsliste eine �bergebene Abteilung hinzu
void Unternehmen::addAbteilung(Abteilung ^ abteilung)
{
	abteilungen->Add(abteilung);
}

//Gibt eine Liste der Angestellten aller Abteilungen des Unternehmens zur�ck
List<Angestellter^>^ Unternehmen::getAlleAngestellte()
{
	List<Angestellter^>^ angestellte = gcnew List<Angestellter^>;
	
	//Geht alle Abteilungen durch
	for (int i = 0; i < getAnzahlAbteilungen(); i++) {
		Abteilung^ abteilung = getAbteilung(i);
		//F�gt den Vorgesetzten dieser Abteilung hinzu
		angestellte->Add(abteilung->getVorgesetzter());
		//Geht alle Mitarbeiter einer Abteilung durch
		for (int j = 0; j < abteilung->getAnzahlMitarbeiter(); j++) {
			angestellte->Add(abteilung->getMitarbeiter(j));
		}
	}

	return angestellte;
}

//Gibt den Angestellten zur�ck, der Eingeloggt wurde, wenn Benutzername und Passwort �bereinstimmen
Angestellter ^ Unternehmen::loginaccept(String ^ personalnummer, array<Byte>^ passwort)
{
	List<Angestellter^>^ angestellte = getAlleAngestellte();
	Angestellter^ result = nullptr;

	bool gefunden = false;
	for (int i = 0; i < angestellte->Count && !gefunden; i++) {
		Angestellter^ angestellter = angestellte[i];

		if (angestellter->getPersonalnummer()->Equals(personalnummer)) {
			gefunden = true;
			String^ passwortString1;
			for (int i = 0; i < angestellter->getPasswort()->Length; i++) {
				passwortString1 += angestellter->getPasswort()[i];
			}
			String^ passwortString2;
			for (int i = 0; i < passwort->Length; i++) {
				passwortString2 += passwort[i];
			}
			if (passwortString1->Equals(passwortString2)) {
				result = angestellter;
			}
		}
	} 
	return result;
}
//Gibt Liste mit allen Abteilungen zur�ck
List<Abteilung^>^ Unternehmen::getAbteilungen()
{
	List<Abteilung^>^ abteilungRueckgabe;
	try {
		abteilungRueckgabe = abteilungen;
	}
	catch (NullReferenceException ^) {
		abteilungRueckgabe = nullptr;
	}
	return abteilungRueckgabe;
}

//F�gt einen Feiertag zur Liste hinzu (Datum aus dem �bergebenen Parameter)
void Unternehmen::addFeiertag(DateTime tag)
{
	this->feiertage->Add(gcnew FreierTag(tag, true));
	//Sortiert die Feiertagsliste nach Datum
	feiertage->Sort(vergleichen);
}

//Entfernt einen Feiertag aus der Liste der Feiertage, wenn das Datum mit dem �bergebenen Datum �bereinstimmt
void Unternehmen::removeFeiertag(DateTime tag)
{
	//Feiertag aus der Liste der Feiertage entfernen
	for (int i = feiertage->Count - 1; i >= 0; i--) {
		if (feiertage[i]->getDatum() == tag) {
			feiertage->RemoveAt(i);
			break;
		}
	}
	//Feiertag aus der Urlaubstage-Liste aller Angestellten entfernen
	for (int i = 0; i < getAlleAngestellte()->Count; i++) {
		for (int j = 0; j < getAlleAngestellte()[i]->getListeUrlaubstage()->Count; j++) {
			if (getAlleAngestellte()[i]->getListeUrlaubstage()[j]->getDatum() == tag) {
				getAlleAngestellte()[i]->getListeUrlaubstage()->RemoveAt(j);
				getAlleAngestellte()[i]->addAntragsInfo("Der Feiertag " + tag.ToString("dddd, dd. MMMM yyyy") + " wurde entfernt.\nSie m�ssen an diesem Tag arbeiten oder Urlaub nehmen!");
			}
		}
	}
}

//Erstellt alle Feiertage, die in Niedersachsen gelten und ein festes Datum haben und f�gt sie der Liste von Feiertagen hinzu
void Unternehmen::erstelleRegelFeiertage(Int32 jahr)
{
	//Die Daten der Feiertage als Paare in einem Array gespeichert
	array<Int32>^ feiertageRegel = { 1, 1, 1, 5, 3, 10, 25, 12, 26, 12 };
	//Alle Paare des Arrays durchgehen
	for (int i = 0; i < feiertageRegel->Length; i = i + 2) {
		DateTime^ feiertag = gcnew DateTime(jahr, feiertageRegel[i + 1], feiertageRegel[i]);
		//Feiertag nur hinzuf�gen, wenn er noch nicht in der Liste existiert (z.B. durch manuelles Einf�gen)
		FreierTag^ neuerFeiertag = gcnew FreierTag(*feiertag, true);
		if (!feiertage->Contains(neuerFeiertag)) {
			feiertage->Add(neuerFeiertag);
		}
	}
}

//Alle Feiertage, die �lter als drei Jahre sind, werden aus der Liste entfernt. Regelfeiertage des n�chsten Jahres werden hinzugef�gt
void Unternehmen::stelleFeiertageZurueck(Int32 jahre)
{
	//Gehe alle Feiertage der Liste durch
	for (int i = feiertage->Count - 1; i >= 0; i--) {
		//L�sche alle Feiertage, die �lter als drei Jahre sind
		if (feiertage[i]->getDatum().Year < (DateTime::Now.Year - 3)) {
			feiertage->RemoveAt(i);
		}
	}
	//Erstelle alle Feiertage des n�chsten Jahres
	this->erstelleRegelFeiertage((DateTime::Now.Year + 1));
}

//Pr�ft, ob ein �bergebener Tag ein Feiertag ist
Boolean Unternehmen::istFeiertag(DateTime tag) 
{
	Boolean istFeiertag = false;
	//Liste der Feiertage wird durchgegangen
	for (int i = feiertage->Count - 1; i >= 0; i--) {
		//Wenn der �bergebene Tag einem Datum der Liste entspricht, wird der Boolean auf true gesetzt
		if (feiertage[i]->getDatum().Date == tag) {
			istFeiertag = true;
			break;
		}
	}
	return istFeiertag;
}

//Gibt index eines Feiertags zur�ck, wenn er vorhanden ist. Sonst wird -1 zur�ckgegeben
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

//Gibt einen String zur�ck, der alle Feiertage, die in diesem Jahr oder in der Zukunft liegen, zur�ck
String^ Unternehmen::feiertageAnzeigen() {
	String^ feiertageString = "Dies sind die Feiertag in Ihrem Unternehmen:\n\n";
	for (int i = 0; i < feiertage->Count; i++) {
		if (feiertage[i]->getDatum().Year >= DateTime::Now.Year) {
			feiertageString += feiertage[i]->getDatum().ToString("dddd, dd. MMMM yyyy") + "\n";
		}
	}
	return feiertageString;
}