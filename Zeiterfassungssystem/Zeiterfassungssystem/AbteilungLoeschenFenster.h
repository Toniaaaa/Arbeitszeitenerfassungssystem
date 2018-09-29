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
	/// Zusammenfassung f�r AbteilungLoeschenFenster
	/// </summary>
	public ref class AbteilungLoeschenFenster : public System::Windows::Forms::Form
	{
	private:
		Unternehmen^ unternehmen;
		List<Abteilung^>^ abteilungen;
		Vorgesetzter^ vorgesetzterAlt;
		Abteilung^ ausgewaehlteAbteilung;
		Boolean ausgewaehlt;
		Boolean behalten;
		Mitarbeiter^ neuerMA;
		Boolean istAdmin;

	private: System::Windows::Forms::Button^  abbrechenBtn;

	public:
		AbteilungLoeschenFenster(void)
		{
			ausgewaehlteAbteilung = nullptr;
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~AbteilungLoeschenFenster()
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
		/// Erforderliche Methode f�r die Designerunterst�tzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor ge�ndert werden.
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
			this->bestaetigenBtn->TabIndex = 1;
			this->bestaetigenBtn->Text = L"Aufl�sen";
			this->bestaetigenBtn->UseVisualStyleBackColor = true;
			this->bestaetigenBtn->Click += gcnew System::EventHandler(this, &AbteilungLoeschenFenster::bestaetigenBtn_Click);
			// 
			// auswahlCBox
			// 
			this->auswahlCBox->FormattingEnabled = true;
			this->auswahlCBox->Location = System::Drawing::Point(16, 97);
			this->auswahlCBox->Name = L"auswahlCBox";
			this->auswahlCBox->Size = System::Drawing::Size(432, 21);
			this->auswahlCBox->TabIndex = 0;
			this->auswahlCBox->SelectedIndexChanged += gcnew System::EventHandler(this, &AbteilungLoeschenFenster::auswahlCBox_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(436, 41);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Welche Abteilung m�chten Sie aufl�sen\?";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// abbrechenBtn
			// 
			this->abbrechenBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->abbrechenBtn->Location = System::Drawing::Point(266, 153);
			this->abbrechenBtn->Name = L"abbrechenBtn";
			this->abbrechenBtn->Size = System::Drawing::Size(150, 50);
			this->abbrechenBtn->TabIndex = 2;
			this->abbrechenBtn->Text = L"Abbrechen";
			this->abbrechenBtn->UseVisualStyleBackColor = true;
			this->abbrechenBtn->Click += gcnew System::EventHandler(this, &AbteilungLoeschenFenster::abbrechenBtn_Click);
			// 
			// AbteilungLoeschenFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(460, 228);
			this->Controls->Add(this->abbrechenBtn);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->auswahlCBox);
			this->Controls->Add(this->bestaetigenBtn);
			this->Name = L"AbteilungLoeschenFenster";
			this->Text = L"AbteilungLoeschenFenster";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &AbteilungLoeschenFenster::AbteilungLoeschenFenster_FormClosing);
			this->Load += gcnew System::EventHandler(this, &AbteilungLoeschenFenster::AbteilungLoeschenFenster_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void bestaetigenBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		
		if (!istAdmin) {
			this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			MessageBox::Show("Sie besitzen leider keine Administrator-Rechte!\nNur Administratoren k�nnen Abteilungen entfernen!", 
				"Keine Abteilung ausgew�hlt", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		else if (!ausgewaehlt) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Bitte waehlen Sie eine Abteilung aus!", "Keine Abteilung ausgew�hlt", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		else if (unternehmen->getAnzahlAbteilungen() < 2) {
			this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			MessageBox::Show("Das Unternehmen besitzt nur eine Abteilung!\nEs k�nnen nicht alle Abteilungen gel�scht werden!",
				"Keine Abteilung ausgew�hlt", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		else {
			ausgewaehlteAbteilung = abteilungen[auswahlCBox->SelectedIndex];
			String^ abfrage = "Wollen Sie die Abteilung " + ausgewaehlteAbteilung->getAbteilungsnummer() + " wirklich aufl�sen?";
			if (MessageBox::Show(abfrage, "Wirklich l�schen?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {

				Abteilung^ abteilung = nullptr;

				if (MessageBox::Show("Wollen Sie den Vorgesetzten der Abteilung als Mitarbeiter behalten?", "Mitarbeiter behalten?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
					behalten = true;
					vorgesetzterAlt = ausgewaehlteAbteilung->getVorgesetzter();
					Vorgesetzter^ vorgesetzterNeu = nullptr;
					if (!ausgewaehlteAbteilung->getAbteilungsnummer()->Equals(abteilungen[0]->getAbteilungsnummer())) {
						vorgesetzterNeu = abteilungen[0]->getVorgesetzter();
						abteilung = abteilungen[0];
					}
					else {
						vorgesetzterNeu = abteilungen[1]->getVorgesetzter();
						abteilung = abteilungen[1];
					}
					neuerMA = gcnew Mitarbeiter(vorgesetzterAlt, vorgesetzterNeu);
					neuerMA->setAbteilung(abteilung);
					abteilung->fuegeMitarbeiterHinzu(neuerMA);
				}

				for (int i = 0; i < unternehmen->getAnzahlAbteilungen(); i++) {
					if (ausgewaehlteAbteilung->getAbteilungsnummer()->Equals(abteilungen[i]->getAbteilungsnummer())) {
						for (int j = 0; j < abteilungen[i]->getAnzahlMitarbeiter(); j++) {
							abteilungen[i]->getMitarbeiter(j)->setAbteilung(abteilung);
							abteilung->fuegeMitarbeiterHinzu(abteilungen[i]->getMitarbeiter(j));
						}
						unternehmen->getAbteilungen()->RemoveAt(i);
					}
				}

				String^ infoText = nullptr;
				if (behalten) {
					infoText = "Sie haben die Abteilung " + ausgewaehlteAbteilung->getAbteilungsnummer() + " erfolgreich gel�scht!\n" + neuerMA->getVorname() + " " 
						+ neuerMA->getNachname() + " ist jetzt Mitarbeiter der Abteilung " + neuerMA->getAbteilung()->getAbteilungsnummer() +".";
				}
				else {
					infoText = "Sie haben die Abteilung " + ausgewaehlteAbteilung->getAbteilungsnummer() + " erfolgreich gel�scht!\nDer Vorgesetzte wurde gel�scht.";
				}
				MessageBox::Show(infoText, "Erfolgreich bef�rdert", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->Close();
			}
		}
	}

	private: System::Void AbteilungLoeschenFenster_Load(System::Object^  sender, System::EventArgs^  e) {
		abteilungen = unternehmen->getAbteilungen();
		ausgewaehlt = false;
		behalten = false;
		for (int i = 0; i < abteilungen->Count; i++) {
			auswahlCBox->Items->Add(abteilungen[i]->getAbteilungsnummer());
		}
	}

	public: void setUnternehmen(Unternehmen^ unternehmen) {
		this->unternehmen = unternehmen;
	}

	public: void setAdminrechte(Boolean istAdmin) {
		this->istAdmin = istAdmin;
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

	private: System::Void AbteilungLoeschenFenster_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		this->clear();
	}
	};
}