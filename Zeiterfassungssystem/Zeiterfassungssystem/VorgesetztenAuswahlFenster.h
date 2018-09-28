#pragma once
#include "Unternehmen.h"
#include "Angestellter.h"
#include "Vorgesetzter.h"
#include "RegistrierungsFenster.h"
#include "Abteilung.h"

namespace Zeiterfassungssystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für VorgesetztenAuswahlFenster
	/// </summary>
	public ref class VorgesetztenAuswahlFenster : public System::Windows::Forms::Form
	{
	private:
		Unternehmen^ unternehmen;
		List<Angestellter^>^ angestelltenAuswahl;
		Vorgesetzter^ vorgesetzterAlt;
		Mitarbeiter^ ausgewaehlterMA;
		Vorgesetzter^ vorgesetzterNeu;
		Boolean ausgewaehlt;
		RegistrierungsFenster^ regFenster;
		Boolean behalten;

	private: System::Windows::Forms::Button^  abbrechenBtn;
			 Abteilung^ abteilung;
	
	public:
		VorgesetztenAuswahlFenster(void)
		{
			regFenster = gcnew RegistrierungsFenster;
			angestelltenAuswahl = gcnew List<Angestellter^>;
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~VorgesetztenAuswahlFenster()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  bestaetigenBtn;
	private: System::Windows::Forms::ComboBox^  auswahlCBox;
	private: System::Windows::Forms::Label^  label1;


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
			this->bestaetigenBtn = (gcnew System::Windows::Forms::Button());
			this->auswahlCBox = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->abbrechenBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// bestaetigenBtn
			// 
			this->bestaetigenBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bestaetigenBtn->Location = System::Drawing::Point(40, 153);
			this->bestaetigenBtn->Name = L"bestaetigenBtn";
			this->bestaetigenBtn->Size = System::Drawing::Size(150, 50);
			this->bestaetigenBtn->TabIndex = 0;
			this->bestaetigenBtn->Text = L"Bestätigen";
			this->bestaetigenBtn->UseVisualStyleBackColor = true;
			this->bestaetigenBtn->Click += gcnew System::EventHandler(this, &VorgesetztenAuswahlFenster::bestaetigenBtn_Click);
			// 
			// auswahlCBox
			// 
			this->auswahlCBox->FormattingEnabled = true;
			this->auswahlCBox->Location = System::Drawing::Point(16, 102);
			this->auswahlCBox->Name = L"auswahlCBox";
			this->auswahlCBox->Size = System::Drawing::Size(432, 21);
			this->auswahlCBox->TabIndex = 1;
			this->auswahlCBox->SelectedIndexChanged += gcnew System::EventHandler(this, &VorgesetztenAuswahlFenster::auswahlCBox_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(436, 56);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Bitte wählen Sie einen neuen Vorgesetzten für diese Abteilung aus!";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// abbrechenBtn
			// 
			this->abbrechenBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->abbrechenBtn->Location = System::Drawing::Point(266, 153);
			this->abbrechenBtn->Name = L"abbrechenBtn";
			this->abbrechenBtn->Size = System::Drawing::Size(150, 50);
			this->abbrechenBtn->TabIndex = 3;
			this->abbrechenBtn->Text = L"Abbrechen";
			this->abbrechenBtn->UseVisualStyleBackColor = true;
			this->abbrechenBtn->Click += gcnew System::EventHandler(this, &VorgesetztenAuswahlFenster::abbrechenBtn_Click);
			// 
			// VorgesetztenAuswahlFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(460, 228);
			this->Controls->Add(this->abbrechenBtn);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->auswahlCBox);
			this->Controls->Add(this->bestaetigenBtn);
			this->Name = L"VorgesetztenAuswahlFenster";
			this->Text = L"VorgesetztenAuswahlFenster";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &VorgesetztenAuswahlFenster::VorgesetztenAuswahlFenster_FormClosing);
			this->Load += gcnew System::EventHandler(this, &VorgesetztenAuswahlFenster::VorgesetztenAuswahlFenster_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void bestaetigenBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		if (!ausgewaehlt) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Bitte waehlen Sie einen Mitarbeiter aus!", "Kein Mitarbeiter ausgewählt", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			ausgewaehlterMA = (Mitarbeiter^)angestelltenAuswahl[auswahlCBox->SelectedIndex];
			for (int i = 0; i < unternehmen->getAnzahlAbteilungen(); i++) {
				if ((vorgesetzterAlt->getAbteilung()->getAbteilungsnummer()->Equals(unternehmen->getAbteilungen()[i]->getAbteilungsnummer()))) {
					abteilung = unternehmen->getAbteilung(i);
					ausgewaehlterMA->setAbteilung(abteilung);
				}
			}
			String^ abfrage = "Wollen Sie " + ausgewaehlterMA->getVorname() + " " + ausgewaehlterMA->getNachname() + " wirklich zum Vorgesetzten der Abteilung " + abteilung->getAbteilungsnummer()
				+ " bestimmen?";
			if (MessageBox::Show(abfrage, "Wirklich löschen?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				vorgesetzterNeu = gcnew Vorgesetzter(ausgewaehlterMA);
				if (behalten) {
					Mitarbeiter^ neuerMA = gcnew Mitarbeiter(vorgesetzterAlt, vorgesetzterNeu);
					abteilung->fuegeMitarbeiterHinzu(neuerMA);
				}
				abteilung->setVorgesetzter(vorgesetzterNeu);
			}
			for (int i = 0; i < abteilung->getAnzahlMitarbeiter(); i++) {
				if (ausgewaehlterMA->getPersonalnummer()->Equals(abteilung->getMitarbeiter(i)->getPersonalnummer())) {
					abteilung->removeMitarbeiter(i);
				}
			}
			String^ infoText = nullptr;
			if (behalten) {
				infoText = "Sie haben erfolgreich " + vorgesetzterNeu->getVorname() + " " + vorgesetzterNeu->getNachname() + " zum Vorgesetzten der Abteilung " + abteilung->getAbteilungsnummer()
					+ " befördert.\n" + vorgesetzterAlt->getVorname() + " " + vorgesetzterAlt->getNachname() + " ist jetzt Mitarbeiter dieser Abteilung.";
			}
			else {
				infoText = "Sie haben erfolgreich " + vorgesetzterNeu->getVorname() + " " + vorgesetzterNeu->getNachname() + " zum Vorgesetzten der Abteilung " + abteilung->getAbteilungsnummer()
					+ " befördert.\n" + vorgesetzterAlt->getVorname() + " " + vorgesetzterAlt->getNachname() + " wurde gelöscht.";
			}
			MessageBox::Show(infoText, "Erfolgreich befördert", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
	}

	private: System::Void VorgesetztenAuswahlFenster_Load(System::Object^  sender, System::EventArgs^  e) {
		List<Angestellter^>^ angestellte = unternehmen->getAlleAngestellte();
		ausgewaehlt = false;
		for (int i = 0; i < angestellte->Count; i++) {
			if (!angestellte[i]->istVorgesetzter()) {
				auswahlCBox->Items->Add(angestellte[i]->getVorname() + " " + angestellte[i]->getNachname() + ", " + angestellte[i]->getPersonalnummer());
				angestelltenAuswahl->Add(angestellte[i]);
			}
		}
	}

	public: void setUnternehmen(Unternehmen^ unternehmen) {
		this->unternehmen = unternehmen;
	}

	public: void setVorgesetzterAlt(Vorgesetzter^ vorgesetzterAlt) {
		this->vorgesetzterAlt = vorgesetzterAlt;
	}

	public: void setVorgesetztenAltBehalten(Boolean behalten) {
		this->behalten = behalten;
	}

	private: System::Void auswahlCBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		ausgewaehlt = true;
	}

	private: System::Void abbrechenBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->Close();
	}

	private: void clear() {
		auswahlCBox->Items->Clear();
	}

	private: System::Void VorgesetztenAuswahlFenster_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		this->clear();
	}
};
}
