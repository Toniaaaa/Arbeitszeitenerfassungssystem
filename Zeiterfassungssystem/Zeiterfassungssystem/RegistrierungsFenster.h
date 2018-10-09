#pragma once
#include "Mitarbeiter.h"
#include "Vorgesetzter.h"
#include "Angestellter.h"
#include "Abteilung.h"
#include "Unternehmen.h"


namespace Zeiterfassungssystem {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;
	using namespace System::Security::Cryptography; //ZUM HASHEN
	/// <summary>
	/// Zusammenfassung für RegistrierungsFenster
	/// </summary>

	public ref class RegistrierungsFenster : public System::Windows::Forms::Form
	{
	private:
		Unternehmen ^ unternehmen;
		Vorgesetzter^ ersteller;
		SHA512^ verschluesselung; //ZUM HASHEN
	private: System::Windows::Forms::TextBox^  txt_name;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::CheckBox^  adminCBox;
			 
	public:

		RegistrierungsFenster(void)
		{
			this->verschluesselung = gcnew SHA512Managed(); //ZUM HASHEN
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~RegistrierungsFenster()
		{
			if (components)
			{
				delete components;
			}
		}

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
	private: System::Windows::Forms::Label^  lbl_Registrierung;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(RegistrierungsFenster::typeid));
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
			this->lbl_Registrierung = (gcnew System::Windows::Forms::Label());
			this->txt_name = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->adminCBox = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// txt_vorname
			// 
			this->txt_vorname->Location = System::Drawing::Point(182, 225);
			this->txt_vorname->Name = L"txt_vorname";
			this->txt_vorname->Size = System::Drawing::Size(394, 26);
			this->txt_vorname->TabIndex = 1;
			// 
			// txt_personalnummer
			// 
			this->txt_personalnummer->Location = System::Drawing::Point(182, 298);
			this->txt_personalnummer->Name = L"txt_personalnummer";
			this->txt_personalnummer->Size = System::Drawing::Size(394, 26);
			this->txt_personalnummer->TabIndex = 3;
			// 
			// txt_passwort
			// 
			this->txt_passwort->Location = System::Drawing::Point(182, 334);
			this->txt_passwort->Name = L"txt_passwort";
			this->txt_passwort->Size = System::Drawing::Size(394, 26);
			this->txt_passwort->TabIndex = 4;
			// 
			// txt_abteilung
			// 
			this->txt_abteilung->FormattingEnabled = true;
			this->txt_abteilung->Location = System::Drawing::Point(182, 262);
			this->txt_abteilung->Name = L"txt_abteilung";
			this->txt_abteilung->Size = System::Drawing::Size(394, 28);
			this->txt_abteilung->TabIndex = 2;
			// 
			// txt_arbeitsstunden
			// 
			this->txt_arbeitsstunden->Location = System::Drawing::Point(182, 371);
			this->txt_arbeitsstunden->Name = L"txt_arbeitsstunden";
			this->txt_arbeitsstunden->Size = System::Drawing::Size(394, 26);
			this->txt_arbeitsstunden->TabIndex = 5;
			// 
			// txt_urlaubstage
			// 
			this->txt_urlaubstage->Location = System::Drawing::Point(182, 409);
			this->txt_urlaubstage->Name = L"txt_urlaubstage";
			this->txt_urlaubstage->Size = System::Drawing::Size(394, 26);
			this->txt_urlaubstage->TabIndex = 6;
			// 
			// txt_Rolle
			// 
			this->txt_Rolle->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->txt_Rolle->FormattingEnabled = true;
			this->txt_Rolle->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"Mitarbeiter" });
			this->txt_Rolle->Location = System::Drawing::Point(182, 480);
			this->txt_Rolle->Name = L"txt_Rolle";
			this->txt_Rolle->Size = System::Drawing::Size(392, 28);
			this->txt_Rolle->TabIndex = 7;
			this->txt_Rolle->SelectedIndexChanged += gcnew System::EventHandler(this, &RegistrierungsFenster::txt_Rolle_SelectedIndexChanged);
			// 
			// btn_mitarbeiter_hinzufuegen
			// 
			this->btn_mitarbeiter_hinzufuegen->Location = System::Drawing::Point(178, 555);
			this->btn_mitarbeiter_hinzufuegen->Name = L"btn_mitarbeiter_hinzufuegen";
			this->btn_mitarbeiter_hinzufuegen->Size = System::Drawing::Size(192, 43);
			this->btn_mitarbeiter_hinzufuegen->TabIndex = 8;
			this->btn_mitarbeiter_hinzufuegen->Text = L"Hinzufügen";
			this->btn_mitarbeiter_hinzufuegen->UseVisualStyleBackColor = true;
			this->btn_mitarbeiter_hinzufuegen->Click += gcnew System::EventHandler(this, &RegistrierungsFenster::btn_mitarbeiter_hinzufuegen_Click);
			// 
			// lbl_name
			// 
			this->lbl_name->AutoSize = true;
			this->lbl_name->Location = System::Drawing::Point(18, 197);
			this->lbl_name->Name = L"lbl_name";
			this->lbl_name->Size = System::Drawing::Size(51, 20);
			this->lbl_name->TabIndex = 8;
			this->lbl_name->Text = L"Name";
			// 
			// lbl_vorname
			// 
			this->lbl_vorname->AutoSize = true;
			this->lbl_vorname->Location = System::Drawing::Point(15, 231);
			this->lbl_vorname->Name = L"lbl_vorname";
			this->lbl_vorname->Size = System::Drawing::Size(74, 20);
			this->lbl_vorname->TabIndex = 9;
			this->lbl_vorname->Text = L"Vorname";
			// 
			// lbl_abteilung
			// 
			this->lbl_abteilung->AutoSize = true;
			this->lbl_abteilung->Location = System::Drawing::Point(16, 271);
			this->lbl_abteilung->Name = L"lbl_abteilung";
			this->lbl_abteilung->Size = System::Drawing::Size(76, 20);
			this->lbl_abteilung->TabIndex = 13;
			this->lbl_abteilung->Text = L"Abteilung";
			// 
			// lbl_personalnummer
			// 
			this->lbl_personalnummer->AutoSize = true;
			this->lbl_personalnummer->Location = System::Drawing::Point(16, 305);
			this->lbl_personalnummer->Name = L"lbl_personalnummer";
			this->lbl_personalnummer->Size = System::Drawing::Size(129, 20);
			this->lbl_personalnummer->TabIndex = 14;
			this->lbl_personalnummer->Text = L"Personalnummer";
			// 
			// lbl_passwort
			// 
			this->lbl_passwort->AutoSize = true;
			this->lbl_passwort->Location = System::Drawing::Point(16, 340);
			this->lbl_passwort->Name = L"lbl_passwort";
			this->lbl_passwort->Size = System::Drawing::Size(74, 20);
			this->lbl_passwort->TabIndex = 17;
			this->lbl_passwort->Text = L"Passwort";
			// 
			// lbl_arbeitsstunden
			// 
			this->lbl_arbeitsstunden->AutoSize = true;
			this->lbl_arbeitsstunden->Location = System::Drawing::Point(16, 377);
			this->lbl_arbeitsstunden->Name = L"lbl_arbeitsstunden";
			this->lbl_arbeitsstunden->Size = System::Drawing::Size(117, 20);
			this->lbl_arbeitsstunden->TabIndex = 20;
			this->lbl_arbeitsstunden->Text = L"Arbeitsstunden";
			// 
			// lbl_urlaubstage
			// 
			this->lbl_urlaubstage->AutoSize = true;
			this->lbl_urlaubstage->Location = System::Drawing::Point(18, 414);
			this->lbl_urlaubstage->Name = L"lbl_urlaubstage";
			this->lbl_urlaubstage->Size = System::Drawing::Size(96, 20);
			this->lbl_urlaubstage->TabIndex = 21;
			this->lbl_urlaubstage->Text = L"Urlaubstage";
			// 
			// lbl_rolle
			// 
			this->lbl_rolle->AutoSize = true;
			this->lbl_rolle->Location = System::Drawing::Point(18, 485);
			this->lbl_rolle->Name = L"lbl_rolle";
			this->lbl_rolle->Size = System::Drawing::Size(45, 20);
			this->lbl_rolle->TabIndex = 32;
			this->lbl_rolle->Text = L"Rolle";
			// 
			// lbl_Registrierung
			// 
			this->lbl_Registrierung->AutoSize = true;
			this->lbl_Registrierung->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Registrierung->Location = System::Drawing::Point(172, 52);
			this->lbl_Registrierung->Name = L"lbl_Registrierung";
			this->lbl_Registrierung->Size = System::Drawing::Size(305, 52);
			this->lbl_Registrierung->TabIndex = 34;
			this->lbl_Registrierung->Text = L"Registrierung";
			// 
			// txt_name
			// 
			this->txt_name->Location = System::Drawing::Point(182, 191);
			this->txt_name->Name = L"txt_name";
			this->txt_name->Size = System::Drawing::Size(394, 26);
			this->txt_name->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(18, 451);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(160, 20);
			this->label1->TabIndex = 35;
			this->label1->Text = L"Administrator-Rechte";
			// 
			// adminCBox
			// 
			this->adminCBox->AutoSize = true;
			this->adminCBox->Enabled = false;
			this->adminCBox->Location = System::Drawing::Point(182, 449);
			this->adminCBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->adminCBox->Name = L"adminCBox";
			this->adminCBox->Size = System::Drawing::Size(22, 21);
			this->adminCBox->TabIndex = 36;
			this->adminCBox->UseVisualStyleBackColor = true;
			// 
			// RegistrierungsFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(590, 626);
			this->Controls->Add(this->adminCBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txt_name);
			this->Controls->Add(this->lbl_Registrierung);
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
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"RegistrierungsFenster";
			this->Text = L"Registrierung";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &RegistrierungsFenster::RegistrierungsFenster_FormClosing);
			this->Load += gcnew System::EventHandler(this, &RegistrierungsFenster::registrierungsFenster_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//Getter zun Datenaustausch
	public:
		String ^ getName() {
			return this->txt_name->Text;
		}

		String^ getVorname() {
			return this->txt_vorname->Text;
		}

		String^ getAbteilung() {
			return this->txt_abteilung->Text;
		}

		String^ getPersonalnummer() {
			return this->txt_personalnummer->Text;
		}

		String^ getPasswort() {
			return this->txt_passwort->Text;
		}

		Int32^ getArbeitsstunden() {
			return Int32::Parse(this->txt_arbeitsstunden->Text);
		}

		Int32^ getUrlaubstage() {
			return Int32::Parse(this->txt_urlaubstage->Text);
		}

		String^ getRolle() {
			return this->txt_Rolle->Text;
		}

		//Setter setzt den Vorgesetzten. Angestellte, die selber Vorgesetzte sind, bekommen keinen Vorgesetzten zugeordnet.
		void setErsteller(Vorgesetzter^ ersteller)
		{
			this->ersteller = ersteller;
		}

		//Clear-Methode der Textfelder
		void clear() {
			this->txt_name->Text = "";
			this->txt_vorname->Text = "";
			this->txt_personalnummer->Text = "";
			this->txt_passwort->Text = "";
			this->txt_arbeitsstunden->Text = "";
			this->txt_urlaubstage->Text = "";
			this->txt_abteilung->Items->Clear();
			this->txt_abteilung->Text = "";
			this->adminCBox->Checked = false;
			this->txt_Rolle->Items->Clear();
			this->txt_Rolle->Items->Add("Mitarbeiter");
			this->txt_Rolle->Text = "";
			this->adminCBox->Enabled = false;
		}

	public: void setUnternehmen(Unternehmen^ unternehmen) {
		this->unternehmen = unternehmen;
	}
	private: System::Void registrierungsFenster_Load(System::Object^  sender, System::EventArgs^  e) {
		//Hinzufuegen von Abteilungen zur Auswahl
		for (int i = 0; i < unternehmen->getAnzahlAbteilungen(); i++) {
			txt_abteilung->Items->Add(unternehmen->getAbteilung(i)->getAbteilungsnummer());
		}
		//Falls das Unternehmen neu ist
		if (unternehmen->getAlleAngestellte()->Count == 0) {
			//Der erste Mitarbeiter muss ein Administrator sein
			txt_Rolle->Items->RemoveAt(0);
			txt_Rolle->Items->Add("Vorgesetzter");
			txt_abteilung->Text = "Administration";
			adminCBox->Checked = true;
		}
		else if (ersteller != nullptr && ersteller->getIstAdmin()) {
			txt_Rolle->Items->Add("Vorgesetzter");
		}
	}

	private: System::Void btn_mitarbeiter_hinzufuegen_Click(System::Object^  sender, System::EventArgs^  e) {
		bool fehlerleer = false;
		bool fehlerPersonal = false;
		bool abteilungExistiert = false;
		Vorgesetzter^ neuerMitarbeiter;
		array<Byte>^ passwortInBytes = System::Text::Encoding::UTF8->GetBytes(txt_passwort->Text); //Zum HASHEN

		//Prüft, ob die Abteilung schon existiert
		for (int i = 0; i < unternehmen->getAnzahlAbteilungen(); i++) {
			if (getAbteilung()->Equals(unternehmen->getAbteilung(i)->getAbteilungsnummer())) {
				abteilungExistiert = true;
			}
		}

		//Personalnummer wird verglichen mit bestehenden gleiche Personalnummer ist nicht möglich
		for (int i = 0; i < unternehmen->getAlleAngestellte()->Count; i++) {
			if (getPersonalnummer()->Equals(unternehmen->getAlleAngestellte()[i]->getPersonalnummer())) {
				fehlerPersonal = true;
			}
		}

		//Eingabepprüfung
		if (this->txt_name->Text->Length == 0 || this->txt_vorname->Text->Length == 0 || this->txt_personalnummer->Text->Length == 0 || this->txt_passwort->Text->Length == 0 
			|| this->txt_arbeitsstunden->Text->Length == 0 || this->txt_urlaubstage->Text->Length == 0 || this->txt_Rolle->Text->Length == 0 || this->txt_abteilung->Text->Length == 0) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			System::Windows::Forms::MessageBox::Show("Bitte füllen Sie alle Felder aus!", "Fehlgeschlagen!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		//Wenn Abteilung noch nicht existiert und Rolle mitarbeiter sein soll kommt ein Hinweis da es keine Abteilung ohne Vorgesetzten geben kann
		else if (!unternehmen->getAlleAngestellte()->Count == 0 && (!abteilungExistiert && getRolle()->Equals("Mitarbeiter"))) {
			System::Windows::Forms::MessageBox::Show("Die Abteilung existiert noch nicht, fügen Sie zuerst einen Vorgesetzten hinzu!", "Fehlgeschlagen!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (fehlerPersonal) {
			System::Windows::Forms::MessageBox::Show("Die Personalnummer existiert schon, bitte geben Sie eine neue ein!", "Fehlgeschlagen!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			txt_personalnummer->Clear();
		}
		//Überprüfung der Namen, Vornamen, Abteilungen, Personalnummern, Arbeitsstunden und Urlaubstagen über eine Regular Expression 
		else if (!System::Text::RegularExpressions::Regex::IsMatch(txt_name->Text, "^[a-zA-ZäöüßÄÖÜ]*(\\ |\\-)?([a-zA-ZäöüßÄÖÜ]*)?$")) {
			System::Windows::Forms::MessageBox::Show("Das Textfeld \"Name\" aktzeptiert nur Buchstaben!", "Fehlgeschlagen!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			txt_name->Clear();
		}
		else if (!System::Text::RegularExpressions::Regex::IsMatch(txt_vorname->Text, "^[a-zA-ZäöüßÄÖÜ]*(\\ |\\-)?([a-zA-ZäöüßÄÖÜ]*)?$")) {
			System::Windows::Forms::MessageBox::Show("Das Textfeld \"Vorname\" aktzeptiert nur Buchstaben!", "Fehlgeschlagen!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			txt_vorname->Clear();
		}
		else if (!System::Text::RegularExpressions::Regex::IsMatch(txt_abteilung->Text, "^[a-zA-ZäöüßÄÖÜ]*(\\ |\\-)?([a-zA-ZäöüßÄÖÜ]*)?$")) {
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
		//Überprüfung ob Urlaubstage größer 28 sind
		else if (int::Parse(txt_urlaubstage->Text) < 28) {
			System::Windows::Forms::MessageBox::Show("Urlaubstage sind laut Gesetz immer größer 28 zu wählen!", "Fehlgeschlagen!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			txt_urlaubstage->Clear();
		}
		//Überprüfung ob eine Rolle ausgewählt wurde
		else if (!this->txt_Rolle->Text->Equals("Mitarbeiter") && !this->txt_Rolle->Text->Equals("Vorgesetzter")) {
			System::Windows::Forms::MessageBox::Show("Bitte wählen Sie eine der vorgegebenen Rollen aus!", "Fehlgeschlagen!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			txt_Rolle->Text = "";
		}
		//Falls Abteilung schon existiert und die Rolle Vorgsetzter ist, löst der neue Vorgestzte den Alten ab, und der alte Vorgesetzte wird zum Mitarbieter
		else if (abteilungExistiert && getRolle()->Equals("Vorgesetzter")) {
			if (System::Windows::Forms::MessageBox::Show("Sie wollen einen neuen Vorgesetzten einer existierenden Abteilung setzen!\nDadurch wird der aktuelle Vorgesetzte zum Mitarbeiter " +
				"dieser Abteilung.\n\nFortsetzen?", "Vorgesetzten ablösen?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				Abteilung^ abteilungNeu = nullptr;
				for (int i = 0; i < unternehmen->getAnzahlAbteilungen(); i++) {
					if (txt_abteilung->SelectedItem->ToString()->Equals(unternehmen->getAbteilung(i)->getAbteilungsnummer())) {
						abteilungNeu = unternehmen->getAbteilung(i);
					}
				}
				neuerMitarbeiter = gcnew Vorgesetzter(txt_vorname->Text, txt_name->Text, abteilungNeu, txt_personalnummer->Text, verschluesselung->ComputeHash(passwortInBytes), Int32::Parse(txt_arbeitsstunden->Text), Int32::Parse(txt_urlaubstage->Text), this->adminCBox->Checked);
				Mitarbeiter^ ehemVorgesetzter = gcnew Mitarbeiter(abteilungNeu->getVorgesetzter(), neuerMitarbeiter);
				abteilungNeu->fuegeMitarbeiterHinzu(ehemVorgesetzter);
				abteilungNeu->setVorgesetzter(neuerMitarbeiter);
				MessageBox::Show("Sie haben erfolgreich einen Angestellten hinzugefügt", "Hinzufügen erfolgreich", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->Close();
			}
			else {
				txt_abteilung->Text = "";
			}
		}
		else {
			if (this->txt_Rolle->Text->Equals("Mitarbeiter")) {
				Abteilung^ abteilung = nullptr;
				//Abteilung im Unternehmen wird ausgerufen wenn passender Abteilungsname ausgewählt
				for (int i = 0; i < unternehmen->getAnzahlAbteilungen(); i++) {
					if (txt_abteilung->SelectedItem->ToString()->Equals(unternehmen->getAbteilung(i)->getAbteilungsnummer())) {
						abteilung = unternehmen->getAbteilung(i);
					}
				}
				Vorgesetzter^ vorgesetzter = abteilung->getVorgesetzter();
				//da Rolle Mitarbeiter ausgewählt wird ein neuer Mitarbeiter mit eingegebenen Daten erstellt und zur Abteilung und Unternehmen hinzugefügt
				Mitarbeiter^ mitarbeiter = gcnew Mitarbeiter(txt_vorname->Text, txt_name->Text, abteilung, txt_personalnummer->Text, verschluesselung->ComputeHash(passwortInBytes), Int32::Parse(txt_arbeitsstunden->Text), Int32::Parse(txt_urlaubstage->Text), vorgesetzter);
				mitarbeiter->setAbteilung(abteilung);
				abteilung->fuegeMitarbeiterHinzu(mitarbeiter);
				this->DialogResult = System::Windows::Forms::DialogResult::OK;
			}
			else {
				if (System::Windows::Forms::MessageBox::Show("Sie wollen eine neue Abteilung " + txt_abteilung->Text + " mit " + txt_vorname->Text + " " + txt_name->Text 
					+ " als Vorgesetzten erstellen.\nIst das korrekt?", "Neue Abteilung?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
					//Wenn Rolle Vorgesetzter gewählt wird neuer Vorgesetzter mit passender Abteilung erstellt
					Abteilung^ abteilung = gcnew Abteilung(txt_abteilung->Text, nullptr);
					neuerMitarbeiter = gcnew Vorgesetzter(txt_vorname->Text, txt_name->Text, abteilung, txt_personalnummer->Text, verschluesselung->ComputeHash(passwortInBytes), Int32::Parse(txt_arbeitsstunden->Text), Int32::Parse(txt_urlaubstage->Text), this->adminCBox->Checked);
					abteilung->setVorgesetzter(neuerMitarbeiter);
					unternehmen->addAbteilung(abteilung);
					this->DialogResult = System::Windows::Forms::DialogResult::OK;
				}
			}
			MessageBox::Show("Sie haben erfolgreich einen Angestellten hinzugefügt", "Hinzufügen erfolgreich", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close();
		}
	}

	//Eventhandler zum schließen des Fensters
	private: System::Void RegistrierungsFenster_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		this->clear();
	}

	//Wenn die Auswahl der Rolle verändert wird
	private: System::Void txt_Rolle_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		//Wenn die Rolle "Vorgesetzter" ausgewählt ist, kann die Checkbox für Admin-Rechte ausgewählt werden
		if (this->txt_Rolle->SelectedItem->ToString()->Equals("Vorgesetzter") && !unternehmen->getAlleAngestellte()->Count == 0) {
			adminCBox->Enabled = true;
		}
		//Wenn "Mitarbeiter" ausgewählt wird, kann die Checkbox für Admin-Rechte nicht gewählt werden
		else if (this->txt_Rolle->SelectedItem->ToString()->Equals("Mitarbeiter")) {
			adminCBox->Enabled = false;
			adminCBox->Checked = false;
		}
	}
};
}