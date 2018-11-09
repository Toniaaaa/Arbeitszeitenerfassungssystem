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
		/// Erforderliche Methode f�r die Designerunterst�tzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor ge�ndert werden.
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
			this->bestaetigenBtn->Text = L"Aufl�sen";
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
			this->label1->Text = L"Welche Abteilung m�chten Sie aufl�sen\?";
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
			this->Text = L"Abteilung l�schen";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &AbteilungLoeschenFenster::AbteilungLoeschenFenster_FormClosing);
			this->Load += gcnew System::EventHandler(this, &AbteilungLoeschenFenster::AbteilungLoeschenFenster_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	//Klick auf Best�tigen-Button:
	private: System::Void bestaetigenBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		
		//Wenn der Nutzer keine Admin-Rechte hat, kann er keine Abteilungen entfernen
		if (!istAdmin) {
			this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			MessageBox::Show("Sie besitzen leider keine Administrator-Rechte!\nNur Administratoren k�nnen Abteilungen entfernen!", 
				"Keine Abteilung ausgew�hlt", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		//Fall: keine Abteilung ausgew�hlt -> Meldung, muss noch ausgew�hlt werden
		else if (!ausgewaehlt) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Bitte waehlen Sie eine Abteilung aus!", "Keine Abteilung ausgew�hlt", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		//Fall: Nur noch eine Abteilung im Unternehmen -> Meldung, L�schen nicht m�glich
		else if (unternehmen->getAnzahlAbteilungen() < 2) {
			this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			MessageBox::Show("Das Unternehmen besitzt nur eine Abteilung!\nEs k�nnen nicht alle Abteilungen gel�scht werden!",
				"Keine Abteilung ausgew�hlt", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		//Fall: Der User will die eigene Abteilung l�schen -> Meldung, L�schen nicht m�glich
		else if (user->getAbteilung()->Equals(abteilungen[auswahlCBox->SelectedIndex])) {
			this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			MessageBox::Show("Sie k�nnen Ihre eigene Abteilung nicht l�schen!", "Eigene Abteilung l�schen", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		//Wenn alles OK:
		else {
			ausgewaehlteAbteilung = abteilungen[auswahlCBox->SelectedIndex];
			//Sicherheitsabfrage
			String^ abfrage = "Wollen Sie die Abteilung " + ausgewaehlteAbteilung->getAbteilungsnummer() + " wirklich aufl�sen?";
			if (MessageBox::Show(abfrage, "Wirklich l�schen?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {

				//Es wird eine "Ersatzabteilung" f�r die MA der zu l�schenden Abteilung gesetzt (normalerweise Abteilung 0, falls diese nicht gel�scht wird, sonst 1)
				Abteilung^ abteilung = nullptr;
				if (!ausgewaehlteAbteilung->getAbteilungsnummer()->Equals(abteilungen[0]->getAbteilungsnummer())) {
					abteilung = abteilungen[0];
				}
				else {
					abteilung = abteilungen[1];
				}

				//Abfrage, ob der Vorgesetzte gel�scht oder behalten werden soll
				if (MessageBox::Show("Wollen Sie den Vorgesetzten der Abteilung als Mitarbeiter behalten?", "Mitarbeiter behalten?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
					behalten = true;
					//Der Vorgesetzte wird in Mitarbeiter seiner neuen Abteilung umgewandelt und der Vorgesetzte seiner neuen Abteilung als sein neuer Vorgesetzter gesetzt
					vorgesetzterAlt = ausgewaehlteAbteilung->getVorgesetzter();
					Vorgesetzter^ vorgesetzterNeu = abteilung->getVorgesetzter();
					neuerMA = gcnew Mitarbeiter(vorgesetzterAlt, vorgesetzterNeu);
					neuerMA->setAbteilung(abteilung);
					//Informationsnachricht wird erstellt und hinzugef�gt
					neuerMA->addAntragsInfo("�nderung im Unternehmen:\n\nIhre Abteilung wurde aufgel�st und Sie wurden in die Abteilung " + abteilung->getAbteilungsnummer() + " versetzt.\n"
						+ "Ihr neuer Vorgesetzter ist " + neuerMA->getVorgesetzter()->getVorname() + " " + neuerMA->getVorgesetzter()->getNachname());
					abteilung->fuegeMitarbeiterHinzu(neuerMA);
				}

				//Alle Mitarbeiter der zu l�schenden Abteilung werden in die Ersatzabteilung verschoben
				for (int i = 0; i < unternehmen->getAnzahlAbteilungen(); i++) {
					if (ausgewaehlteAbteilung->getAbteilungsnummer()->Equals(abteilungen[i]->getAbteilungsnummer())) {
						for (int j = 0; j < abteilungen[i]->getAnzahlMitarbeiter(); j++) {
							Mitarbeiter^ mitarbeiter = abteilungen[i]->getMitarbeiter(j);
							mitarbeiter->setAbteilung(abteilung);
							mitarbeiter->setVorgesetzter(abteilung->getVorgesetzter());
							mitarbeiter->addAntragsInfo("�nderung im Unternehmen:\n\nIhre Abteilung wurde gel�scht und Sie wurden in die Abteilung " + abteilung->getAbteilungsnummer() + " versetzt.\n"
								+ "Ihr neuer Vorgesetzter ist " + mitarbeiter->getVorgesetzter()->getVorname() + " " + mitarbeiter->getVorgesetzter()->getNachname());
							abteilung->fuegeMitarbeiterHinzu(mitarbeiter);
						}
						//Die Abteilung wird gel�scht
						unternehmen->getAbteilungen()->RemoveAt(i);
					}
				}

				//Infotext f�r die MessageBox wird erstellt. Zwei Varianten f�r L�schen oder Behalten des Vorgesetzten.
				String^ infoText = nullptr;
				if (behalten) {
					infoText = "Sie haben die Abteilung " + ausgewaehlteAbteilung->getAbteilungsnummer() + " erfolgreich aufgel�st!\n" + neuerMA->getVorname() + " " 
						+ neuerMA->getNachname() + " ist jetzt Mitarbeiter der Abteilung " + neuerMA->getAbteilung()->getAbteilungsnummer() + "." + "\nAlle Mitarbeiter wurden in die Abteilung "
						+ abteilung->getAbteilungsnummer() + " verschoben.";
				}
				else {
					infoText = "Sie haben die Abteilung " + ausgewaehlteAbteilung->getAbteilungsnummer() + " erfolgreich gel�scht!\nDer Vorgesetzte wurde gel�scht." 
						+ "\nAlle Mitarbeiter wurden in die Abteilung " + abteilung->getAbteilungsnummer() + " verschoben.";
				}
				//MessageBox wird erstellt und Fenster geschlossen.
				MessageBox::Show(infoText, "Erfolgreich gel�scht", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->Close();
			}
		}
	}

	//Wenn das Fenster l�dt:
	private: System::Void AbteilungLoeschenFenster_Load(System::Object^  sender, System::EventArgs^  e) {
		//Werte werden auf Startwerte gesetzt.
		abteilungen = unternehmen->getAbteilungen();
		ausgewaehlt = false;
		behalten = false;
		//ComboBox wird gef�llt
		for (int i = 0; i < abteilungen->Count; i++) {
			auswahlCBox->Items->Add(abteilungen[i]->getAbteilungsnummer());
		}
	}

	//Setter f�r das Unternehmen
	public: void setUnternehmen(Unternehmen^ unternehmen) {
		this->unternehmen = unternehmen;
	}

	//Setter f�r die Admin-Rechte des Nutzers
	public: void setUser(Vorgesetzter^ user) {
		this->user = user;
		this->istAdmin = user->getIstAdmin();
	}

	//Wenn in der ComboBox etwas ausgewaehlt wurde
	private: System::Void auswahlCBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		ausgewaehlt = true;
	}

	//Abbrechen-Button wird geklickt: Das Fenster wird ohne weitere Aktion geschlossen und Cancel zur�ckgegeben.
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