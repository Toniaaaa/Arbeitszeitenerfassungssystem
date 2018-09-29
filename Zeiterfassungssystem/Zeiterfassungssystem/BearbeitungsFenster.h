#pragma once
#include "Unternehmen.h"
#include "Angestellter.h"
#include "Abteilung.h"
#include "Vorgesetzter.h"
#include "Mitarbeiter.h"
#include "VorgesetztenAuswahlFenster.h"

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
	/// Zusammenfassung f�r RegistrierungsFenster
	/// </summary>

	public ref class BearbeitungsFenster : public System::Windows::Forms::Form
	{
	private:
		VorgesetztenAuswahlFenster^ vorgesetztenFenster;

	public:

		BearbeitungsFenster(void)
		{
			InitializeComponent();
			vorgesetztenFenster = gcnew VorgesetztenAuswahlFenster;
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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::CheckBox^  adminCBox;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->adminCBox = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// txt_vorname
			// 
			this->txt_vorname->Location = System::Drawing::Point(121, 168);
			this->txt_vorname->Margin = System::Windows::Forms::Padding(2);
			this->txt_vorname->Name = L"txt_vorname";
			this->txt_vorname->Size = System::Drawing::Size(264, 20);
			this->txt_vorname->TabIndex = 2;
			// 
			// txt_personalnummer
			// 
			this->txt_personalnummer->Location = System::Drawing::Point(121, 119);
			this->txt_personalnummer->Margin = System::Windows::Forms::Padding(2);
			this->txt_personalnummer->Name = L"txt_personalnummer";
			this->txt_personalnummer->Size = System::Drawing::Size(264, 20);
			this->txt_personalnummer->TabIndex = 0;
			this->txt_personalnummer->TextChanged += gcnew System::EventHandler(this, &BearbeitungsFenster::txt_personalnummer_TextChanged);
			// 
			// txt_passwort
			// 
			this->txt_passwort->Location = System::Drawing::Point(121, 217);
			this->txt_passwort->Margin = System::Windows::Forms::Padding(2);
			this->txt_passwort->Name = L"txt_passwort";
			this->txt_passwort->PasswordChar = '*';
			this->txt_passwort->Size = System::Drawing::Size(264, 20);
			this->txt_passwort->TabIndex = 4;
			// 
			// txt_abteilung
			// 
			this->txt_abteilung->FormattingEnabled = true;
			this->txt_abteilung->Location = System::Drawing::Point(121, 192);
			this->txt_abteilung->Margin = System::Windows::Forms::Padding(2);
			this->txt_abteilung->Name = L"txt_abteilung";
			this->txt_abteilung->Size = System::Drawing::Size(264, 21);
			this->txt_abteilung->TabIndex = 3;
			// 
			// txt_arbeitsstunden
			// 
			this->txt_arbeitsstunden->Location = System::Drawing::Point(121, 241);
			this->txt_arbeitsstunden->Margin = System::Windows::Forms::Padding(2);
			this->txt_arbeitsstunden->Name = L"txt_arbeitsstunden";
			this->txt_arbeitsstunden->Size = System::Drawing::Size(264, 20);
			this->txt_arbeitsstunden->TabIndex = 5;
			// 
			// txt_urlaubstage
			// 
			this->txt_urlaubstage->Location = System::Drawing::Point(121, 266);
			this->txt_urlaubstage->Margin = System::Windows::Forms::Padding(2);
			this->txt_urlaubstage->Name = L"txt_urlaubstage";
			this->txt_urlaubstage->Size = System::Drawing::Size(264, 20);
			this->txt_urlaubstage->TabIndex = 6;
			// 
			// txt_Rolle
			// 
			this->txt_Rolle->FormattingEnabled = true;
			this->txt_Rolle->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Mitarbeiter", L"Vorgesetzter" });
			this->txt_Rolle->Location = System::Drawing::Point(122, 313);
			this->txt_Rolle->Margin = System::Windows::Forms::Padding(2);
			this->txt_Rolle->Name = L"txt_Rolle";
			this->txt_Rolle->Size = System::Drawing::Size(263, 21);
			this->txt_Rolle->TabIndex = 8;
			this->txt_Rolle->SelectedIndexChanged += gcnew System::EventHandler(this, &BearbeitungsFenster::txt_Rolle_SelectedIndexChanged);
			// 
			// btn_mitarbeiter_hinzufuegen
			// 
			this->btn_mitarbeiter_hinzufuegen->Location = System::Drawing::Point(121, 358);
			this->btn_mitarbeiter_hinzufuegen->Margin = System::Windows::Forms::Padding(2);
			this->btn_mitarbeiter_hinzufuegen->Name = L"btn_mitarbeiter_hinzufuegen";
			this->btn_mitarbeiter_hinzufuegen->Size = System::Drawing::Size(128, 28);
			this->btn_mitarbeiter_hinzufuegen->TabIndex = 9;
			this->btn_mitarbeiter_hinzufuegen->Text = L"�ndern";
			this->btn_mitarbeiter_hinzufuegen->UseVisualStyleBackColor = true;
			this->btn_mitarbeiter_hinzufuegen->Click += gcnew System::EventHandler(this, &BearbeitungsFenster::btn_mitarbeiter_hinzufuegen_Click);
			// 
			// lbl_name
			// 
			this->lbl_name->AutoSize = true;
			this->lbl_name->Location = System::Drawing::Point(8, 145);
			this->lbl_name->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_name->Name = L"lbl_name";
			this->lbl_name->Size = System::Drawing::Size(35, 13);
			this->lbl_name->TabIndex = 8;
			this->lbl_name->Text = L"Name";
			// 
			// lbl_vorname
			// 
			this->lbl_vorname->AutoSize = true;
			this->lbl_vorname->Location = System::Drawing::Point(8, 171);
			this->lbl_vorname->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_vorname->Name = L"lbl_vorname";
			this->lbl_vorname->Size = System::Drawing::Size(49, 13);
			this->lbl_vorname->TabIndex = 9;
			this->lbl_vorname->Text = L"Vorname";
			// 
			// lbl_abteilung
			// 
			this->lbl_abteilung->AutoSize = true;
			this->lbl_abteilung->Location = System::Drawing::Point(8, 195);
			this->lbl_abteilung->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_abteilung->Name = L"lbl_abteilung";
			this->lbl_abteilung->Size = System::Drawing::Size(51, 13);
			this->lbl_abteilung->TabIndex = 13;
			this->lbl_abteilung->Text = L"Abteilung";
			// 
			// lbl_personalnummer
			// 
			this->lbl_personalnummer->AutoSize = true;
			this->lbl_personalnummer->Location = System::Drawing::Point(8, 122);
			this->lbl_personalnummer->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_personalnummer->Name = L"lbl_personalnummer";
			this->lbl_personalnummer->Size = System::Drawing::Size(85, 13);
			this->lbl_personalnummer->TabIndex = 14;
			this->lbl_personalnummer->Text = L"Personalnummer";
			// 
			// lbl_passwort
			// 
			this->lbl_passwort->AutoSize = true;
			this->lbl_passwort->Location = System::Drawing::Point(8, 220);
			this->lbl_passwort->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_passwort->Name = L"lbl_passwort";
			this->lbl_passwort->Size = System::Drawing::Size(50, 13);
			this->lbl_passwort->TabIndex = 17;
			this->lbl_passwort->Text = L"Passwort";
			// 
			// lbl_arbeitsstunden
			// 
			this->lbl_arbeitsstunden->AutoSize = true;
			this->lbl_arbeitsstunden->Location = System::Drawing::Point(8, 244);
			this->lbl_arbeitsstunden->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_arbeitsstunden->Name = L"lbl_arbeitsstunden";
			this->lbl_arbeitsstunden->Size = System::Drawing::Size(77, 13);
			this->lbl_arbeitsstunden->TabIndex = 20;
			this->lbl_arbeitsstunden->Text = L"Arbeitsstunden";
			// 
			// lbl_urlaubstage
			// 
			this->lbl_urlaubstage->AutoSize = true;
			this->lbl_urlaubstage->Location = System::Drawing::Point(8, 269);
			this->lbl_urlaubstage->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_urlaubstage->Name = L"lbl_urlaubstage";
			this->lbl_urlaubstage->Size = System::Drawing::Size(64, 13);
			this->lbl_urlaubstage->TabIndex = 21;
			this->lbl_urlaubstage->Text = L"Urlaubstage";
			// 
			// lbl_rolle
			// 
			this->lbl_rolle->AutoSize = true;
			this->lbl_rolle->Location = System::Drawing::Point(8, 316);
			this->lbl_rolle->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_rolle->Name = L"lbl_rolle";
			this->lbl_rolle->Size = System::Drawing::Size(31, 13);
			this->lbl_rolle->TabIndex = 32;
			this->lbl_rolle->Text = L"Rolle";
			// 
			// lbl_bearbeitung
			// 
			this->lbl_bearbeitung->AutoSize = true;
			this->lbl_bearbeitung->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_bearbeitung->Location = System::Drawing::Point(115, 34);
			this->lbl_bearbeitung->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_bearbeitung->Name = L"lbl_bearbeitung";
			this->lbl_bearbeitung->Size = System::Drawing::Size(187, 36);
			this->lbl_bearbeitung->TabIndex = 34;
			this->lbl_bearbeitung->Text = L"Bearbeitung";
			// 
			// txt_name
			// 
			this->txt_name->Location = System::Drawing::Point(121, 145);
			this->txt_name->Margin = System::Windows::Forms::Padding(2);
			this->txt_name->Name = L"txt_name";
			this->txt_name->Size = System::Drawing::Size(264, 20);
			this->txt_name->TabIndex = 1;
			// 
			// btn_loeschen
			// 
			this->btn_loeschen->Location = System::Drawing::Point(257, 358);
			this->btn_loeschen->Margin = System::Windows::Forms::Padding(2);
			this->btn_loeschen->Name = L"btn_loeschen";
			this->btn_loeschen->Size = System::Drawing::Size(128, 28);
			this->btn_loeschen->TabIndex = 10;
			this->btn_loeschen->Text = L"L�schen";
			this->btn_loeschen->UseVisualStyleBackColor = true;
			this->btn_loeschen->Click += gcnew System::EventHandler(this, &BearbeitungsFenster::btn_loeschen_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 293);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(105, 13);
			this->label1->TabIndex = 36;
			this->label1->Text = L"Administrator-Rechte";
			// 
			// adminCBox
			// 
			this->adminCBox->AutoSize = true;
			this->adminCBox->Enabled = false;
			this->adminCBox->Location = System::Drawing::Point(121, 294);
			this->adminCBox->Name = L"adminCBox";
			this->adminCBox->Size = System::Drawing::Size(15, 14);
			this->adminCBox->TabIndex = 7;
			this->adminCBox->UseVisualStyleBackColor = true;
			// 
			// BearbeitungsFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(393, 397);
			this->Controls->Add(this->adminCBox);
			this->Controls->Add(this->label1);
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
			this->Margin = System::Windows::Forms::Padding(2);
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
		Abteilung^ abteilung;
		String^ rolle;

		//clear Methoden zum bereinigen der Textboxen
		void clear() {
			this->txt_name->Text = "";
			this->txt_vorname->Text = "";
			this->txt_personalnummer->Text = "";
			this->txt_passwort->Text = "";
			this->txt_abteilung->Text = "";
			this->txt_arbeitsstunden->Text = "";
			this->txt_urlaubstage->Text = "";
			this->txt_Rolle->Text = "";
			this->txt_abteilung->Items->Clear();
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

		String^ getAbteilung() {
			return this->txt_abteilung->Text;
		}

		String^ getRolle() {
			return this->txt_Rolle->Text;
		}
		
		String^ getPersonalnummer() {
			return this->txt_personalnummer->Text;
		}

	private: System::Void BearbeitungsFenster_Load(System::Object^  sender, System::EventArgs^  e) {
		this->adminCBox->Enabled = false;
	}

	private: System::Void txt_personalnummer_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		//Wenn man anfaengt die Personalnummer zu schreiben wird diese abgeglichen und die Textbooxen werden mit den anderen
		//Daten automatisch bef�llt
		angestellte = unternehmen->getAlleAngestellte();
		Boolean gefunden = false;
		for (int i = 0; i < angestellte->Count; i++) {
			if (angestellte[i]->getPersonalnummer()->Equals(getPersonalnummerVergleich())) {
				setAngestellten(angestellte[i]);
				txt_name->Text = angestellte[i]->getNachname();
				txt_vorname->Text = angestellte[i]->getVorname();
				txt_abteilung->Text = angestellte[i]->getAbteilung()->getAbteilungsnummer();
				txt_passwort->Text = angestellte[i]->getPasswort();
				txt_arbeitsstunden->Text = Convert::ToString(angestellte[i]->getWochensstunden());
				txt_urlaubstage->Text = Convert::ToString(angestellte[i]->getJahresurlaub());
				if (angestellte[i]->istVorgesetzter()) {
					Vorgesetzter^ v = (Vorgesetzter^) angestellte[i];
					adminCBox->Enabled = true;
					adminCBox->Checked = v->getIstAdmin();
				}
				else {
					adminCBox->Enabled = false;
					adminCBox->Checked = false;
				}
				//Abteilungsauswahl wird mit passenden Abteilungen bef�llt 
				for (int i = 0; i < unternehmen->getAnzahlAbteilungen(); i++) {
					txt_abteilung->Items->Add(unternehmen->getAbteilung(i)->getAbteilungsnummer());
				}

				if (!angestellte[i]->istVorgesetzter()) {
					txt_Rolle->Text = "Mitarbeiter";
					rolle = "Mitarbeiter";
				}
				else {
					txt_Rolle->Text = "Vorgesetzter";
					rolle = "Vorgesetzter";
				}
				gefunden = true;
			}
		}
		if (!gefunden) {
			this->txt_name->Text = "";
			this->txt_vorname->Text = "";
			this->txt_passwort->Text = "";
			this->txt_abteilung->Text = "";
			this->txt_arbeitsstunden->Text = "";
			this->txt_urlaubstage->Text = "";
			this->txt_Rolle->Text = "";
			this->txt_abteilung->Items->Clear();
		}
		if (txt_personalnummer->Text == "") {
			this->clear();
		}
	}

	private: System::Void btn_mitarbeiter_hinzufuegen_Click(System::Object^  sender, System::EventArgs^  e) {
		bool fehlerAbteilung = true;
		bool fehlerPersonal = false;
		bool info = true;
		int parse;
		Vorgesetzter^ vorgesetzter;
		Abteilung^ abteilung;

		//Wenn Abteilung noch nicht existiert und Rolle mitarbeiter sein soll kommt ein Hinweis da es keine Abteilung ohne Vorgesetzten geben kann
		for (int i = 0; i < unternehmen->getAnzahlAbteilungen(); i++) {
			if ((getAbteilung()->Equals(unternehmen->getAbteilung(i)->getAbteilungsnummer())) || getRolle()->Equals("Vorgesetzter")) {
				fehlerAbteilung = false;
			}
		}

		//Eingabeppr�fung im Eventhandler
		if (this->txt_name->Text->Length == 0 || this->txt_vorname->Text->Length == 0 || this->txt_personalnummer->Text->Length == 0 || this->txt_passwort->Text->Length == 0
			|| this->txt_arbeitsstunden->Text->Length == 0 || this->txt_urlaubstage->Text->Length == 0 || this->txt_Rolle->Text->Length == 0 || this->txt_abteilung->Text->Length == 0) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			System::Windows::Forms::MessageBox::Show("Bitte f�llen Sie alle Felder aus!", "Fehlgeschlagen!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (fehlerAbteilung) {
			System::Windows::Forms::MessageBox::Show("Die Abteilung existiert noch nicht, f�gen Sie zuerst einen Vorgesetzten hinzu!", "Fehlgeschlagen!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			txt_abteilung->Text = "";
		}
		else if (fehlerPersonal) {
			System::Windows::Forms::MessageBox::Show("Die Personalnummer existiert schon, bitte geben Sie eine neue ein!", "Fehlgeschlagen!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			txt_personalnummer->Clear();
		}
		else if (!System::Text::RegularExpressions::Regex::IsMatch(txt_name->Text, "^[a-zA-Z]*$")) {
			System::Windows::Forms::MessageBox::Show("Das Textfeld \"Name\" aktzeptiert nur Buchstaben!", "Fehlgeschlagen!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			txt_name->Clear();
		}
		else if (!System::Text::RegularExpressions::Regex::IsMatch(txt_vorname->Text, "^[a-zA-Z]*$")) {
			System::Windows::Forms::MessageBox::Show("Das Textfeld \"Vorname\" aktzeptiert nur Buchstaben!", "Fehlgeschlagen!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			txt_vorname->Clear();
		}
		else if (!System::Text::RegularExpressions::Regex::IsMatch(txt_abteilung->Text, "^[a-zA-Z]*$")) {
			System::Windows::Forms::MessageBox::Show("Das Textfeld \"Abteilung\" aktzeptiert nur Buchstaben!", "Fehlgeschlagen!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			txt_abteilung->Text = "";
		}
		else if (!System::Text::RegularExpressions::Regex::IsMatch(txt_personalnummer->Text, "^[0-9]+$")) {
			System::Windows::Forms::MessageBox::Show("Das Textfeld \"Personalnummer\" aktzeptiert nur Zahlen!", "Fehlgeschlagen!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			txt_personalnummer->Clear();
		}
		else if (!System::Text::RegularExpressions::Regex::IsMatch(txt_arbeitsstunden->Text, "^[0-9]+$")) {
			System::Windows::Forms::MessageBox::Show("Das Textfeld \"Arbeitsstunden\" akzeptiert nur Zahlen!", "Fehlgeschlagen!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			txt_arbeitsstunden->Clear();
		}
		else if (!System::Text::RegularExpressions::Regex::IsMatch(txt_urlaubstage->Text, "^[0-9]+$")) {
			System::Windows::Forms::MessageBox::Show("Das Textfeld \"Urlaubstage\" aktzeptiert nur Zahlen!", "Fehlgeschlagen!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			txt_urlaubstage->Clear();
		}
		else if (int::Parse(txt_urlaubstage->Text) < 28) {
			System::Windows::Forms::MessageBox::Show("Urlaubstage sind laut Gesetz immer gr��er 28 zu w�hlen!", "Fehlgeschlagen!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			txt_urlaubstage->Clear();
		}

		/*for (int i = 0; i < unternehmen->getAnzahlAbteilungen(); i++) {
			if (!(txt_abteilung->Text->Equals(unternehmen->getAbteilungen()[i]->getAbteilungsnummer())) && txt_Rolle->Text->Equals("Mitarbeiter")) {
				System::Windows::Forms::MessageBox::Show("Die Abteilung existiert noch nicht, f�gen Sie zuerst einen Vorgesetzten hinzu!", "Fehlgeschlagen!",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				txt_abteilung->Text = "";
				fehler = true;
			}
		}*/

		else {
			angestellter->setNachname(txt_name->Text);
			angestellter->setVorname(txt_vorname->Text);
			angestellter->setPersonalnummer(txt_personalnummer->Text);
			angestellter->setPasswort(txt_passwort->Text);
			angestellter->setWochenstunden(Convert::ToInt32(txt_arbeitsstunden->Text));
			angestellter->setUrlaubstage(Convert::ToInt32(txt_urlaubstage->Text));
			if (angestellter->istVorgesetzter()) {
				Vorgesetzter^ v = (Vorgesetzter^) angestellter;
				v->setIstAdmin(adminCBox->Checked);
			}
			for (int k = 0; k < unternehmen->getAnzahlAbteilungen(); k++) {
				if (txt_abteilung->Text->Equals(unternehmen->getAbteilung(k)->getAbteilungsnummer())) {
					angestellter->setAbteilung(unternehmen->getAbteilung(k));
				}
			}

			if (txt_Rolle->Text->Equals("Vorgesetzter") && rolle->Equals("Mitarbeiter")) {
				//Sicherheitsabfrage
				String^ frageText = "Wollen Sie " + angestellter->getVorname() + " " + angestellter->getNachname() + " wirklich zum neuen Vorgesetzten der Abteilung "
					+ txt_abteilung->Text + " bestimmen?";
				if (MessageBox::Show(frageText, "Wirklich Vorgesetzten wechseln?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
					Boolean abteilungNichtVorhanden = true;
					Abteilung^ alteAbteilung = angestellter->getAbteilung();
					for (int i = 0; i < unternehmen->getAnzahlAbteilungen(); i++) {
						if (txt_abteilung->Text->Equals(unternehmen->getAbteilung(i)->getAbteilungsnummer())) {
							abteilungNichtVorhanden = false;
						}
					}
					if (abteilungNichtVorhanden) {
						Abteilung^ abteilungNeu = gcnew Abteilung(txt_abteilung->Text, nullptr);
						angestellter->setAbteilung(abteilungNeu);
						unternehmen->addAbteilung(abteilungNeu);
					}
					abteilung = angestellter->getAbteilung();
					vorgesetzter = gcnew Vorgesetzter((Mitarbeiter^)angestellter, adminCBox->Checked); //Hier neuen Konstruktor verwendet, damit keine Daten verloren gehen.
					if (abteilungNichtVorhanden) {
						abteilung->setVorgesetzter(vorgesetzter);
					}
					else {
						Mitarbeiter^ ehemVorgesetzter = gcnew Mitarbeiter(abteilung->getVorgesetzter(), vorgesetzter); //Alter Vorgesetzter wird als Mitarbeiter gespeichert.
						abteilung->fuegeMitarbeiterHinzu(ehemVorgesetzter); //Alter Vorgesetzter wird der Abteilung als MA hinzugefuegt
						abteilung->setVorgesetzter(vorgesetzter);
					}
					for (int i = 0; i < alteAbteilung->getAnzahlMitarbeiter(); i++) {
						if (angestellter->getPersonalnummer()->Equals(alteAbteilung->getMitarbeiter(i)->getPersonalnummer())) {
							alteAbteilung->removeMitarbeiter(i);
						}
					}
					if (txt_Rolle->Text->Equals("Vorgesetzter") && rolle->Equals("Vorgesetzter")) {
						for (int i = 0; i < unternehmen->getAnzahlAbteilungen(); i++) {
							if (!(txt_abteilung->Text->Equals(unternehmen->getAbteilungen()[i]->getAbteilungsnummer()))) {
								angestellter = vorgesetzter;
								Abteilung^ abteilungNeu = gcnew Abteilung(txt_abteilung->Text, vorgesetzter);
								angestellter->setAbteilung(abteilungNeu);
								unternehmen->addAbteilung(abteilung);
							}
						}
					}
				}
			}
			if (txt_Rolle->Text->Equals("Mitarbeiter") && rolle->Equals("Vorgesetzter")) {
				//Sicherheitsabfrage
				String^ abfrage = "Wollen Sie den Vorgesetzten " + txt_vorname->Text + " " + txt_name->Text + " wirklich als Mitarbeiter setzen?";
				if (MessageBox::Show(abfrage, "Wirklich degradieren?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
					Vorgesetzter^ vorgesetzterAlt = nullptr;
					for (int i = 0; i < unternehmen->getAlleAngestellte()->Count; i++) {
						if (unternehmen->getAlleAngestellte()[i]->getPersonalnummer()->Equals(txt_personalnummer->Text)) {
							vorgesetzterAlt = (Vorgesetzter^)unternehmen->getAlleAngestellte()[i];
							break;
						}
					}
					vorgesetztenFenster->setUnternehmen(unternehmen);
					vorgesetztenFenster->setVorgesetzterAlt(vorgesetzterAlt);
					vorgesetztenFenster->setVorgesetztenAltBehalten(true);
					vorgesetztenFenster->ShowDialog(this);
					info = false;
				}
			}
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			if (info) {
				MessageBox::Show("Angestellten Daten erfolgreich ge�ndert!", "Erfolgreich", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			this->Close();
		}
	}

	private: System::Void BearbeitungsFenster_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		this->clear();
	}

	private: System::Void btn_loeschen_Click(System::Object^  sender, System::EventArgs^  e) {
		//Sicherheitsabfrage
		String^ abfrage = "Wollen Sie den Angestellten " + txt_vorname->Text + " " + txt_name->Text + " wirklich l�schen?";
		if (MessageBox::Show(abfrage, "Wirklich l�schen?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			//Wenn loeschen button geklickt wird der passende Mitarbeiter aus der abteilung geloescht
			if (!angestellter->istVorgesetzter()) {
				abteilung = angestellter->getAbteilung();
				for (int i = 0; i < abteilung->getAnzahlMitarbeiter(); i++) {
					if (angestellter->getPersonalnummer()->Equals(abteilung->getMitarbeiter(i)->getPersonalnummer())) {
						abteilung->removeMitarbeiter(i);
					}
				}
			}
			else {
				Vorgesetzter^ vorgesetzterAlt = nullptr;
				for (int i = 0; i < unternehmen->getAlleAngestellte()->Count; i++) {
					if (unternehmen->getAlleAngestellte()[i]->getPersonalnummer()->Equals(txt_personalnummer->Text)) {
						vorgesetzterAlt = (Vorgesetzter^) unternehmen->getAlleAngestellte()[i];
						break;
					}
				}
				vorgesetztenFenster->setUnternehmen(unternehmen);
				vorgesetztenFenster->setVorgesetzterAlt(vorgesetzterAlt);
				vorgesetztenFenster->setVorgesetztenAltBehalten(false);
				vorgesetztenFenster->ShowDialog(this);
			}
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
	}

	private: System::Void txt_Rolle_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (txt_Rolle->Text->Equals("Mitarbeiter")) {
			adminCBox->Enabled = false;
			adminCBox->Checked = false;
		}
		else if (txt_Rolle->Text->Equals("Vorgesetzter")) {
			adminCBox->Enabled = true;
		}
	}
};
}
