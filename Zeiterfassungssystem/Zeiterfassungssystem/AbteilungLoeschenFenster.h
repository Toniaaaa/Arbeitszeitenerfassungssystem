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
	/// Zusammenfassung für AbteilungLoeschenFenster
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
		Vorgesetzter^ user;

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
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AbteilungLoeschenFenster::typeid));
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
			this->bestaetigenBtn->Location = System::Drawing::Point(60, 235);
			this->bestaetigenBtn->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->bestaetigenBtn->Name = L"bestaetigenBtn";
			this->bestaetigenBtn->Size = System::Drawing::Size(225, 77);
			this->bestaetigenBtn->TabIndex = 1;
			this->bestaetigenBtn->Text = L"Auflösen";
			this->bestaetigenBtn->UseVisualStyleBackColor = true;
			this->bestaetigenBtn->Click += gcnew System::EventHandler(this, &AbteilungLoeschenFenster::bestaetigenBtn_Click);
			// 
			// auswahlCBox
			// 
			this->auswahlCBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->auswahlCBox->FormattingEnabled = true;
			this->auswahlCBox->Location = System::Drawing::Point(24, 149);
			this->auswahlCBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->auswahlCBox->Name = L"auswahlCBox";
			this->auswahlCBox->Size = System::Drawing::Size(646, 28);
			this->auswahlCBox->TabIndex = 0;
			this->auswahlCBox->SelectedIndexChanged += gcnew System::EventHandler(this, &AbteilungLoeschenFenster::auswahlCBox_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(18, 49);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(654, 63);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Welche Abteilung möchten Sie auflösen\?";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// abbrechenBtn
			// 
			this->abbrechenBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->abbrechenBtn->Location = System::Drawing::Point(399, 235);
			this->abbrechenBtn->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->abbrechenBtn->Name = L"abbrechenBtn";
			this->abbrechenBtn->Size = System::Drawing::Size(225, 77);
			this->abbrechenBtn->TabIndex = 2;
			this->abbrechenBtn->Text = L"Abbrechen";
			this->abbrechenBtn->UseVisualStyleBackColor = true;
			this->abbrechenBtn->Click += gcnew System::EventHandler(this, &AbteilungLoeschenFenster::abbrechenBtn_Click);
			// 
			// AbteilungLoeschenFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(690, 351);
			this->Controls->Add(this->abbrechenBtn);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->auswahlCBox);
			this->Controls->Add(this->bestaetigenBtn);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"AbteilungLoeschenFenster";
			this->Text = L"Abteilung löschen";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &AbteilungLoeschenFenster::AbteilungLoeschenFenster_FormClosing);
			this->Load += gcnew System::EventHandler(this, &AbteilungLoeschenFenster::AbteilungLoeschenFenster_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	//Klick auf Bestätigen-Button:
	private: System::Void bestaetigenBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		
		//Wenn der Nutzer keine Admin-Rechte hat, kann er keine Abteilungen entfernen
		if (!istAdmin) {
			this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			MessageBox::Show("Sie besitzen leider keine Administrator-Rechte!\nNur Administratoren können Abteilungen entfernen!", 
				"Keine Abteilung ausgewählt", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		//Fall: keine Abteilung ausgewählt -> Meldung, muss noch ausgewählt werden
		else if (!ausgewaehlt) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Bitte waehlen Sie eine Abteilung aus!", "Keine Abteilung ausgewählt", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		//Fall: Nur noch eine Abteilung im Unternehmen -> Meldung, Löschen nicht möglich
		else if (unternehmen->getAnzahlAbteilungen() < 2) {
			this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			MessageBox::Show("Das Unternehmen besitzt nur eine Abteilung!\nEs können nicht alle Abteilungen gelöscht werden!",
				"Keine Abteilung ausgewählt", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		//Fall: Der User will die eigene Abteilung löschen -> Meldung, Löschen nicht möglich
		else if (user->getAbteilung()->Equals(abteilungen[auswahlCBox->SelectedIndex])) {
			this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			MessageBox::Show("Sie können Ihre eigene Abteilung nicht löschen!", "Eigene Abteilung löschen", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		//Wenn alles OK:
		else {
			ausgewaehlteAbteilung = abteilungen[auswahlCBox->SelectedIndex];
			//Sicherheitsabfrage
			String^ abfrage = "Wollen Sie die Abteilung " + ausgewaehlteAbteilung->getAbteilungsnummer() + " wirklich auflösen?";
			if (MessageBox::Show(abfrage, "Wirklich löschen?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {

				//Es wird eine "Ersatzabteilung" für die MA der zu löschenden Abteilung gesetzt (normalerweise Abteilung 0, falls diese nicht gelöscht wird, sonst 1)
				Abteilung^ abteilung = nullptr;
				if (!ausgewaehlteAbteilung->getAbteilungsnummer()->Equals(abteilungen[0]->getAbteilungsnummer())) {
					abteilung = abteilungen[0];
				}
				else {
					abteilung = abteilungen[1];
				}

				//Abfrage, ob der Vorgesetzte gelöscht oder behalten werden soll
				if (MessageBox::Show("Wollen Sie den Vorgesetzten der Abteilung als Mitarbeiter behalten?", "Mitarbeiter behalten?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
					behalten = true;
					//Der Vorgesetzte wird in Mitarbeiter seiner neuen Abteilung umgewandelt und der Vorgesetzte seiner neuen Abteilung als sein neuer Vorgesetzter gesetzt
					vorgesetzterAlt = ausgewaehlteAbteilung->getVorgesetzter();
					Vorgesetzter^ vorgesetzterNeu = abteilung->getVorgesetzter();
					neuerMA = gcnew Mitarbeiter(vorgesetzterAlt, vorgesetzterNeu);
					neuerMA->setAbteilung(abteilung);
					//Informationsnachricht wird erstellt und hinzugefügt
					neuerMA->addAntragsInfo("Änderung im Unternehmen:\n\nIhre Abteilung wurde aufgelöst und Sie wurden in die Abteilung " + abteilung->getAbteilungsnummer() + " versetzt.\n"
						+ "Ihr neuer Vorgesetzter ist " + neuerMA->getVorgesetzter()->getVorname() + " " + neuerMA->getVorgesetzter()->getNachname());
					abteilung->fuegeMitarbeiterHinzu(neuerMA);
				}

				//Alle Mitarbeiter der zu löschenden Abteilung werden in die Ersatzabteilung verschoben
				for (int i = 0; i < unternehmen->getAnzahlAbteilungen(); i++) {
					if (ausgewaehlteAbteilung->getAbteilungsnummer()->Equals(abteilungen[i]->getAbteilungsnummer())) {
						for (int j = 0; j < abteilungen[i]->getAnzahlMitarbeiter(); j++) {
							Mitarbeiter^ mitarbeiter = abteilungen[i]->getMitarbeiter(j);
							mitarbeiter->setAbteilung(abteilung);
							mitarbeiter->setVorgesetzter(abteilung->getVorgesetzter());
							mitarbeiter->addAntragsInfo("Änderung im Unternehmen:\n\nIhre Abteilung wurde gelöscht und Sie wurden in die Abteilung " + abteilung->getAbteilungsnummer() + " versetzt.\n"
								+ "Ihr neuer Vorgesetzter ist " + mitarbeiter->getVorgesetzter()->getVorname() + " " + mitarbeiter->getVorgesetzter()->getNachname());
							abteilung->fuegeMitarbeiterHinzu(mitarbeiter);
						}
						//Die Abteilung wird gelöscht
						unternehmen->getAbteilungen()->RemoveAt(i);
					}
				}

				//Infotext für die MessageBox wird erstellt. Zwei Varianten für Löschen oder Behalten des Vorgesetzten.
				String^ infoText = nullptr;
				if (behalten) {
					infoText = "Sie haben die Abteilung " + ausgewaehlteAbteilung->getAbteilungsnummer() + " erfolgreich aufgelöst!\n" + neuerMA->getVorname() + " " 
						+ neuerMA->getNachname() + " ist jetzt Mitarbeiter der Abteilung " + neuerMA->getAbteilung()->getAbteilungsnummer() + "." + "\nAlle Mitarbeiter wurden in die Abteilung "
						+ abteilung->getAbteilungsnummer() + " verschoben.";
				}
				else {
					infoText = "Sie haben die Abteilung " + ausgewaehlteAbteilung->getAbteilungsnummer() + " erfolgreich gelöscht!\nDer Vorgesetzte wurde gelöscht." 
						+ "\nAlle Mitarbeiter wurden in die Abteilung " + abteilung->getAbteilungsnummer() + " verschoben.";
				}
				//MessageBox wird erstellt und Fenster geschlossen.
				MessageBox::Show(infoText, "Erfolgreich gelöscht", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->Close();
			}
		}
	}

	//Wenn das Fenster lädt:
	private: System::Void AbteilungLoeschenFenster_Load(System::Object^  sender, System::EventArgs^  e) {
		//Werte werden auf Startwerte gesetzt.
		abteilungen = unternehmen->getAbteilungen();
		ausgewaehlt = false;
		behalten = false;
		//ComboBox wird gefüllt
		for (int i = 0; i < abteilungen->Count; i++) {
			auswahlCBox->Items->Add(abteilungen[i]->getAbteilungsnummer());
		}
	}

	//Setter für das Unternehmen
	public: void setUnternehmen(Unternehmen^ unternehmen) {
		this->unternehmen = unternehmen;
	}

	//Setter für die Admin-Rechte des Nutzers
	public: void setUser(Vorgesetzter^ user) {
		this->user = user;
		this->istAdmin = user->getIstAdmin();
	}

	//Wenn in der ComboBox etwas ausgewaehlt wurde
	private: System::Void auswahlCBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		ausgewaehlt = true;
	}

	//Abbrechen-Button wird geklickt: Das Fenster wird ohne weitere Aktion geschlossen und Cancel zurückgegeben.
	private: System::Void abbrechenBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->Close();
	}

	//Leert die ComboBox
	private: void clear() {
		auswahlCBox->SelectedIndex = -1;
		auswahlCBox->Items->Clear();
	}

	//Wenn das Fenster geschlossen wird.
	private: System::Void AbteilungLoeschenFenster_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		//ComboBox leeren
		this->clear();
	}
	};
}