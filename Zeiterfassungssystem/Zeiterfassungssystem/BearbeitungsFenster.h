#pragma once
#include "Unternehmen.h"
#include "Angestellter.h"
#include "Abteilung.h"
#include "Vorgesetzter.h"
#include "Mitarbeiter.h"

namespace Zeiterfassungssystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;
	//ref class StartseiteVorgesetzte;
	/// <summary>
	/// Zusammenfassung für RegistrierungsFenster
	/// </summary>

	public ref class BearbeitungsFenster : public System::Windows::Forms::Form
	{

			


	public:

		BearbeitungsFenster(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~BearbeitungsFenster()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::TextBox^  txt_name;
	private: System::Windows::Forms::TextBox^  txt_vorname;
	private: System::Windows::Forms::TextBox^  txt_personalnummer;
	private: System::Windows::Forms::TextBox^  txt_passwort;
	private: System::Windows::Forms::ComboBox^  txt_abteilung;
	private: System::Windows::Forms::TextBox^  txt_urlaubstage;
	private: System::Windows::Forms::TextBox^  txt_arbeitsstunden;
	private: System::Windows::Forms::ComboBox^  txt_Rolle;
	private: System::Windows::Forms::Label^  lbl_name;
	private: System::Windows::Forms::Label^  lbl_vorname;
	private: System::Windows::Forms::Label^  lbl_abteilung;
	private: System::Windows::Forms::Label^  lbl_personalnummer;
	private: System::Windows::Forms::Label^  lbl_passwort;
	private: System::Windows::Forms::Label^  lbl_arbeitsstunden;
	private: System::Windows::Forms::Label^  lbl_urlaubstage;
	private: System::Windows::Forms::Label^  lbl_rolle;
	private: System::Windows::Forms::Button^  btn_mitarbeiter_hinzufuegen;
	private: System::Windows::Forms::Label^  lbl_bearbeitung;
	private: System::Windows::Forms::Button^  btn_loeschen;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txt_vorname = (gcnew System::Windows::Forms::TextBox());
			this->txt_personalnummer = (gcnew System::Windows::Forms::TextBox());
			this->txt_passwort = (gcnew System::Windows::Forms::TextBox());
			this->txt_abteilung = (gcnew System::Windows::Forms::ComboBox());
			this->txt_arbeitsstunden = (gcnew System::Windows::Forms::TextBox());
			this->txt_urlaubstage = (gcnew System::Windows::Forms::TextBox());
			this->txt_Rolle = (gcnew System::Windows::Forms::ComboBox());
			this->btn_mitarbeiter_hinzufuegen = (gcnew System::Windows::Forms::Button());
			this->lbl_name = (gcnew System::Windows::Forms::Label());
			this->lbl_vorname = (gcnew System::Windows::Forms::Label());
			this->lbl_abteilung = (gcnew System::Windows::Forms::Label());
			this->lbl_personalnummer = (gcnew System::Windows::Forms::Label());
			this->lbl_passwort = (gcnew System::Windows::Forms::Label());
			this->lbl_arbeitsstunden = (gcnew System::Windows::Forms::Label());
			this->lbl_urlaubstage = (gcnew System::Windows::Forms::Label());
			this->lbl_rolle = (gcnew System::Windows::Forms::Label());
			this->lbl_bearbeitung = (gcnew System::Windows::Forms::Label());
			this->txt_name = (gcnew System::Windows::Forms::TextBox());
			this->btn_loeschen = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txt_vorname
			// 
			this->txt_vorname->Location = System::Drawing::Point(161, 207);
			this->txt_vorname->Name = L"txt_vorname";
			this->txt_vorname->Size = System::Drawing::Size(351, 22);
			this->txt_vorname->TabIndex = 2;
			// 
			// txt_personalnummer
			// 
			this->txt_personalnummer->Location = System::Drawing::Point(161, 147);
			this->txt_personalnummer->Name = L"txt_personalnummer";
			this->txt_personalnummer->Size = System::Drawing::Size(351, 22);
			this->txt_personalnummer->TabIndex = 0;
			this->txt_personalnummer->TextChanged += gcnew System::EventHandler(this, &BearbeitungsFenster::txt_personalnummer_TextChanged);
			// 
			// txt_passwort
			// 
			this->txt_passwort->Location = System::Drawing::Point(161, 267);
			this->txt_passwort->Name = L"txt_passwort";
			this->txt_passwort->PasswordChar = '*';
			this->txt_passwort->Size = System::Drawing::Size(351, 22);
			this->txt_passwort->TabIndex = 4;
			// 
			// txt_abteilung
			// 
			this->txt_abteilung->FormattingEnabled = true;
			this->txt_abteilung->Location = System::Drawing::Point(161, 236);
			this->txt_abteilung->Name = L"txt_abteilung";
			this->txt_abteilung->Size = System::Drawing::Size(351, 24);
			this->txt_abteilung->TabIndex = 3;
			// 
			// txt_arbeitsstunden
			// 
			this->txt_arbeitsstunden->Location = System::Drawing::Point(161, 297);
			this->txt_arbeitsstunden->Name = L"txt_arbeitsstunden";
			this->txt_arbeitsstunden->Size = System::Drawing::Size(351, 22);
			this->txt_arbeitsstunden->TabIndex = 5;
			// 
			// txt_urlaubstage
			// 
			this->txt_urlaubstage->Location = System::Drawing::Point(161, 327);
			this->txt_urlaubstage->Name = L"txt_urlaubstage";
			this->txt_urlaubstage->Size = System::Drawing::Size(351, 22);
			this->txt_urlaubstage->TabIndex = 6;
			// 
			// txt_Rolle
			// 
			this->txt_Rolle->FormattingEnabled = true;
			this->txt_Rolle->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Mitarbeiter", L"Vorgesetzter" });
			this->txt_Rolle->Location = System::Drawing::Point(161, 361);
			this->txt_Rolle->Name = L"txt_Rolle";
			this->txt_Rolle->Size = System::Drawing::Size(349, 24);
			this->txt_Rolle->TabIndex = 7;
			// 
			// btn_mitarbeiter_hinzufuegen
			// 
			this->btn_mitarbeiter_hinzufuegen->Location = System::Drawing::Point(161, 408);
			this->btn_mitarbeiter_hinzufuegen->Name = L"btn_mitarbeiter_hinzufuegen";
			this->btn_mitarbeiter_hinzufuegen->Size = System::Drawing::Size(171, 35);
			this->btn_mitarbeiter_hinzufuegen->TabIndex = 8;
			this->btn_mitarbeiter_hinzufuegen->Text = L"Ändern";
			this->btn_mitarbeiter_hinzufuegen->UseVisualStyleBackColor = true;
			this->btn_mitarbeiter_hinzufuegen->Click += gcnew System::EventHandler(this, &BearbeitungsFenster::btn_mitarbeiter_hinzufuegen_Click);
			// 
			// lbl_name
			// 
			this->lbl_name->AutoSize = true;
			this->lbl_name->Location = System::Drawing::Point(16, 184);
			this->lbl_name->Name = L"lbl_name";
			this->lbl_name->Size = System::Drawing::Size(45, 17);
			this->lbl_name->TabIndex = 8;
			this->lbl_name->Text = L"Name";
			// 
			// lbl_vorname
			// 
			this->lbl_vorname->AutoSize = true;
			this->lbl_vorname->Location = System::Drawing::Point(14, 212);
			this->lbl_vorname->Name = L"lbl_vorname";
			this->lbl_vorname->Size = System::Drawing::Size(65, 17);
			this->lbl_vorname->TabIndex = 9;
			this->lbl_vorname->Text = L"Vorname";
			// 
			// lbl_abteilung
			// 
			this->lbl_abteilung->AutoSize = true;
			this->lbl_abteilung->Location = System::Drawing::Point(15, 243);
			this->lbl_abteilung->Name = L"lbl_abteilung";
			this->lbl_abteilung->Size = System::Drawing::Size(67, 17);
			this->lbl_abteilung->TabIndex = 13;
			this->lbl_abteilung->Text = L"Abteilung";
			// 
			// lbl_personalnummer
			// 
			this->lbl_personalnummer->AutoSize = true;
			this->lbl_personalnummer->Location = System::Drawing::Point(12, 152);
			this->lbl_personalnummer->Name = L"lbl_personalnummer";
			this->lbl_personalnummer->Size = System::Drawing::Size(115, 17);
			this->lbl_personalnummer->TabIndex = 14;
			this->lbl_personalnummer->Text = L"Personalnummer";
			// 
			// lbl_passwort
			// 
			this->lbl_passwort->AutoSize = true;
			this->lbl_passwort->Location = System::Drawing::Point(15, 272);
			this->lbl_passwort->Name = L"lbl_passwort";
			this->lbl_passwort->Size = System::Drawing::Size(65, 17);
			this->lbl_passwort->TabIndex = 17;
			this->lbl_passwort->Text = L"Passwort";
			// 
			// lbl_arbeitsstunden
			// 
			this->lbl_arbeitsstunden->AutoSize = true;
			this->lbl_arbeitsstunden->Location = System::Drawing::Point(15, 302);
			this->lbl_arbeitsstunden->Name = L"lbl_arbeitsstunden";
			this->lbl_arbeitsstunden->Size = System::Drawing::Size(103, 17);
			this->lbl_arbeitsstunden->TabIndex = 20;
			this->lbl_arbeitsstunden->Text = L"Arbeitsstunden";
			// 
			// lbl_urlaubstage
			// 
			this->lbl_urlaubstage->AutoSize = true;
			this->lbl_urlaubstage->Location = System::Drawing::Point(16, 330);
			this->lbl_urlaubstage->Name = L"lbl_urlaubstage";
			this->lbl_urlaubstage->Size = System::Drawing::Size(85, 17);
			this->lbl_urlaubstage->TabIndex = 21;
			this->lbl_urlaubstage->Text = L"Urlaubstage";
			// 
			// lbl_rolle
			// 
			this->lbl_rolle->AutoSize = true;
			this->lbl_rolle->Location = System::Drawing::Point(16, 361);
			this->lbl_rolle->Name = L"lbl_rolle";
			this->lbl_rolle->Size = System::Drawing::Size(40, 17);
			this->lbl_rolle->TabIndex = 32;
			this->lbl_rolle->Text = L"Rolle";
			// 
			// lbl_bearbeitung
			// 
			this->lbl_bearbeitung->AutoSize = true;
			this->lbl_bearbeitung->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_bearbeitung->Location = System::Drawing::Point(153, 42);
			this->lbl_bearbeitung->Name = L"lbl_bearbeitung";
			this->lbl_bearbeitung->Size = System::Drawing::Size(236, 44);
			this->lbl_bearbeitung->TabIndex = 34;
			this->lbl_bearbeitung->Text = L"Bearbeitung";
			// 
			// txt_name
			// 
			this->txt_name->Location = System::Drawing::Point(161, 179);
			this->txt_name->Name = L"txt_name";
			this->txt_name->Size = System::Drawing::Size(351, 22);
			this->txt_name->TabIndex = 1;
			// 
			// btn_loeschen
			// 
			this->btn_loeschen->Location = System::Drawing::Point(341, 408);
			this->btn_loeschen->Name = L"btn_loeschen";
			this->btn_loeschen->Size = System::Drawing::Size(171, 35);
			this->btn_loeschen->TabIndex = 35;
			this->btn_loeschen->Text = L"Löschen";
			this->btn_loeschen->UseVisualStyleBackColor = true;
			this->btn_loeschen->Click += gcnew System::EventHandler(this, &BearbeitungsFenster::btn_loeschen_Click);
			// 
			// BearbeitungsFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(524, 456);
			this->Controls->Add(this->btn_loeschen);
			this->Controls->Add(this->txt_name);
			this->Controls->Add(this->lbl_bearbeitung);
			this->Controls->Add(this->lbl_rolle);
			this->Controls->Add(this->lbl_urlaubstage);
			this->Controls->Add(this->lbl_arbeitsstunden);
			this->Controls->Add(this->lbl_passwort);
			this->Controls->Add(this->lbl_personalnummer);
			this->Controls->Add(this->lbl_abteilung);
			this->Controls->Add(this->lbl_vorname);
			this->Controls->Add(this->lbl_name);
			this->Controls->Add(this->btn_mitarbeiter_hinzufuegen);
			this->Controls->Add(this->txt_Rolle);
			this->Controls->Add(this->txt_urlaubstage);
			this->Controls->Add(this->txt_arbeitsstunden);
			this->Controls->Add(this->txt_abteilung);
			this->Controls->Add(this->txt_passwort);
			this->Controls->Add(this->txt_personalnummer);
			this->Controls->Add(this->txt_vorname);
			this->Name = L"BearbeitungsFenster";
			this->Text = L"Bearbeitung";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &BearbeitungsFenster::BearbeitungsFenster_FormClosing);
			this->Load += gcnew System::EventHandler(this, &BearbeitungsFenster::BearbeitungsFenster_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		Unternehmen ^ unternehmen;
		Angestellter^ angestellter;
		List<Angestellter^>^ angestellte = gcnew List<Angestellter^>;
		void clear() {
			this->txt_name->Text = "";
			this->txt_vorname->Text = "";
			this->txt_personalnummer->Text = "";
			this->txt_passwort->Text = "";
			this->txt_abteilung->Text = "";
			this->txt_arbeitsstunden->Text = "";
			this->txt_urlaubstage->Text = "";
			this->txt_Rolle->Text = "";
		}
	public: 
		void setUnternehmen(Unternehmen^ unternehmen) {
			this->unternehmen = unternehmen;
		}
		void setAngestellten(Angestellter^ angestellter) {
			this->angestellter = angestellter;
		}
		String^ getPersonalnummerVergleich() {
			return this->txt_personalnummer->Text;
		}

	private: System::Void BearbeitungsFenster_Load(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void txt_personalnummer_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		angestellte = unternehmen->getAlleAngestellte();
		

		for (int i = 0; i < angestellte->Count; i++) {
			if (angestellte[i]->getPersonalnummer()->Equals(getPersonalnummerVergleich())) {
				setAngestellten(angestellte[i]);
				txt_name->Text = angestellte[i]->getNachname();
				txt_vorname->Text = angestellte[i]->getVorname();
				txt_abteilung->Text = angestellte[i]->getAbteilung()->getAbteilungsnummer();
				txt_passwort->Text = angestellte[i]->getPasswort();
				txt_arbeitsstunden->Text = Convert::ToString(angestellte[i]->getWochensstunden());
				txt_urlaubstage->Text = Convert::ToString(angestellte[i]->getUrlaubstage());
				if (!angestellte[i]->istVorgesetzter()) {
					txt_Rolle->Text = "Mitarbeiter";
				}
				else {
					txt_Rolle->Text = "Vorgesetzter";
				}


			}
		}
	
	}

	private: System::Void btn_mitarbeiter_hinzufuegen_Click(System::Object^  sender, System::EventArgs^  e) {
		bool fehler = false;
		int parse;
		//Eingabepprüfung im Eventhandler
		if (this->txt_name->Text->Length == 0) {

			this->DialogResult = System::Windows::Forms::DialogResult::None;
			fehler = true;
		}

		else if (this->txt_vorname->Text->Length == 0) {

			this->DialogResult = System::Windows::Forms::DialogResult::None;
			fehler = true;
		}

		else if (this->txt_personalnummer->Text->Length == 0) {

			this->DialogResult = System::Windows::Forms::DialogResult::None;
			fehler = true;
		}

		else if (this->txt_passwort->Text->Length == 0) {

			this->DialogResult = System::Windows::Forms::DialogResult::None;
			fehler = true;
		}

		else if (this->txt_arbeitsstunden->Text->Length == 0) {

			this->DialogResult = System::Windows::Forms::DialogResult::None;
			fehler = true;
		}

		else if (this->txt_urlaubstage->Text->Length == 0) {

			this->DialogResult = System::Windows::Forms::DialogResult::None;
			fehler = true;
		}
		else if (this->txt_Rolle->Text->Length == 0) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			fehler = true;
		}
		//ÄNDERUNG
		if (fehler) {
			System::Windows::Forms::MessageBox::Show("Bitte füllen Sie alle Felder aus!", "Fehler!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			
			angestellter->setNachname(txt_name->Text);
			angestellter->setVorname(txt_vorname->Text);
			angestellter->setPersonalnummer(txt_personalnummer->Text);
			angestellter->setPasswort(txt_passwort->Text);
			angestellter->setWochenstunden(Convert::ToInt32(txt_arbeitsstunden->Text));
			angestellter->setUrlaubstage(Convert::ToInt32(txt_urlaubstage->Text));
			for (int k = 0; k < unternehmen->getAnzahlAbteilungen(); k++) {
				if (txt_abteilung->Text->Equals(unternehmen->getAbteilung(k)->getAbteilungsnummer())) {
					angestellter->setAbteilung(unternehmen->getAbteilung(k));

				}

			}
			if (txt_Rolle->Text->Equals("Vorgesetzter")) {
				Abteilung^ abteilung = angestellter->getAbteilung();
				abteilung->setVorgesetzter(gcnew Vorgesetzter(txt_vorname->Text,txt_name->Text,angestellter->getAbteilung(),txt_personalnummer->Text, txt_passwort->Text, Convert::ToInt32(txt_arbeitsstunden->Text), Convert::ToInt32(txt_urlaubstage->Text)));
				for (int i = 0; i < abteilung->getAnzahlMitarbeiter(); i++) {
					if (angestellter->getPersonalnummer()->Equals(abteilung->getMitarbeiter(i)->getPersonalnummer())) {
						abteilung->removeMitarbeiter(i);
					}
				}
				
			}
			else {

				
			}
			MessageBox::Show("Erfolgreich", "Angestellten Daten erfolgreich geändert!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->clear();

		}
	}
	private: System::Void BearbeitungsFenster_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		this->clear();
	}
private: System::Void btn_loeschen_Click(System::Object^  sender, System::EventArgs^  e) {

	for (int i = 0; i < angestellter->getAbteilung()->getAnzahlMitarbeiter(); i++) {
		if (angestellte[i]->getPersonalnummer()->Equals(getPersonalnummerVergleich())) {
			angestellte[i]->getAbteilung()->removeMitarbeiter(i);
			unternehmen->getAlleAngestellte()->RemoveAt(i);
		}
	}
}
};
}
