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
	ref class StartseiteVorgesetzte;
	/// <summary>
	/// Zusammenfassung für RegistrierungsFenster
	/// </summary>

	public ref class RegistrierungsFenster : public System::Windows::Forms::Form
	{
	private:
		Unternehmen ^ unternehmen;
		StartseiteVorgesetzte^ startseitevorgesetzte;
		Vorgesetzter^ vorgesetzter;
	public:

		RegistrierungsFenster(void)
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
		~RegistrierungsFenster()
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
			this->txt_name = (gcnew System::Windows::Forms::TextBox());
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
			this->SuspendLayout();
			// 
			// txt_name
			// 
			this->txt_name->Location = System::Drawing::Point(161, 152);
			this->txt_name->Name = L"txt_name";
			this->txt_name->Size = System::Drawing::Size(351, 22);
			this->txt_name->TabIndex = 2;
			// 
			// txt_vorname
			// 
			this->txt_vorname->Location = System::Drawing::Point(161, 180);
			this->txt_vorname->Name = L"txt_vorname";
			this->txt_vorname->Size = System::Drawing::Size(351, 22);
			this->txt_vorname->TabIndex = 1;
			// 
			// txt_personalnummer
			// 
			this->txt_personalnummer->Location = System::Drawing::Point(161, 239);
			this->txt_personalnummer->Name = L"txt_personalnummer";
			this->txt_personalnummer->Size = System::Drawing::Size(351, 22);
			this->txt_personalnummer->TabIndex = 0;
			// 
			// txt_passwort
			// 
			this->txt_passwort->Location = System::Drawing::Point(161, 267);
			this->txt_passwort->Name = L"txt_passwort";
			this->txt_passwort->Size = System::Drawing::Size(351, 22);
			this->txt_passwort->TabIndex = 19;
			// 
			// txt_abteilung
			// 
			this->txt_abteilung->FormattingEnabled = true;
			this->txt_abteilung->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Verwaltung", L"IT Sicherheit", L"Software Entwicklung" });
			this->txt_abteilung->Location = System::Drawing::Point(161, 209);
			this->txt_abteilung->Name = L"txt_abteilung";
			this->txt_abteilung->Size = System::Drawing::Size(351, 24);
			this->txt_abteilung->TabIndex = 25;
			// 
			// txt_arbeitsstunden
			// 
			this->txt_arbeitsstunden->Location = System::Drawing::Point(161, 297);
			this->txt_arbeitsstunden->Name = L"txt_arbeitsstunden";
			this->txt_arbeitsstunden->Size = System::Drawing::Size(351, 22);
			this->txt_arbeitsstunden->TabIndex = 23;
			// 
			// txt_urlaubstage
			// 
			this->txt_urlaubstage->Location = System::Drawing::Point(161, 327);
			this->txt_urlaubstage->Name = L"txt_urlaubstage";
			this->txt_urlaubstage->Size = System::Drawing::Size(351, 22);
			this->txt_urlaubstage->TabIndex = 22;
			// 
			// btn_mitarbeiter_hinzufuegen
			// 
			this->btn_mitarbeiter_hinzufuegen->Location = System::Drawing::Point(161, 408);
			this->btn_mitarbeiter_hinzufuegen->Name = L"btn_mitarbeiter_hinzufuegen";
			this->btn_mitarbeiter_hinzufuegen->Size = System::Drawing::Size(171, 35);
			this->btn_mitarbeiter_hinzufuegen->TabIndex = 16;
			this->btn_mitarbeiter_hinzufuegen->Text = L"Hinzufügen";
			this->btn_mitarbeiter_hinzufuegen->UseVisualStyleBackColor = true;
			this->btn_mitarbeiter_hinzufuegen->Click += gcnew System::EventHandler(this, &RegistrierungsFenster::btn_mitarbeiter_hinzufuegen_Click);
			// 
			// lbl_name
			// 
			this->lbl_name->AutoSize = true;
			this->lbl_name->Location = System::Drawing::Point(16, 157);
			this->lbl_name->Name = L"lbl_name";
			this->lbl_name->Size = System::Drawing::Size(45, 17);
			this->lbl_name->TabIndex = 8;
			this->lbl_name->Text = L"Name";
			// 
			// lbl_vorname
			// 
			this->lbl_vorname->AutoSize = true;
			this->lbl_vorname->Location = System::Drawing::Point(14, 185);
			this->lbl_vorname->Name = L"lbl_vorname";
			this->lbl_vorname->Size = System::Drawing::Size(65, 17);
			this->lbl_vorname->TabIndex = 9;
			this->lbl_vorname->Text = L"Vorname";
			// 
			// lbl_abteilung
			// 
			this->lbl_abteilung->AutoSize = true;
			this->lbl_abteilung->Location = System::Drawing::Point(15, 216);
			this->lbl_abteilung->Name = L"lbl_abteilung";
			this->lbl_abteilung->Size = System::Drawing::Size(67, 17);
			this->lbl_abteilung->TabIndex = 13;
			this->lbl_abteilung->Text = L"Abteilung";
			// 
			// lbl_personalnummer
			// 
			this->lbl_personalnummer->AutoSize = true;
			this->lbl_personalnummer->Location = System::Drawing::Point(15, 244);
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
			// txt_Rolle
			// 
			this->txt_Rolle->FormattingEnabled = true;
			this->txt_Rolle->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Mitarbeiter", L"Vorgesetzter" });
			this->txt_Rolle->Location = System::Drawing::Point(161, 361);
			this->txt_Rolle->Name = L"txt_Rolle";
			this->txt_Rolle->Size = System::Drawing::Size(349, 24);
			this->txt_Rolle->TabIndex = 33;
			// 
			// lbl_Registrierung
			// 
			this->lbl_Registrierung->AutoSize = true;
			this->lbl_Registrierung->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Registrierung->Location = System::Drawing::Point(153, 42);
			this->lbl_Registrierung->Name = L"lbl_Registrierung";
			this->lbl_Registrierung->Size = System::Drawing::Size(260, 44);
			this->lbl_Registrierung->TabIndex = 34;
			this->lbl_Registrierung->Text = L"Registrierung";
			// 
			// RegistrierungsFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(524, 456);
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
			this->Controls->Add(this->txt_name);
			this->Name = L"RegistrierungsFenster";
			this->Text = L"Registrierung";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void registrierungsFenster_Load(System::Object^  sender, System::EventArgs^  e) {
	}
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

		//Methode zum Zurücksetzen der Textfelder
		void clear() {
			this->txt_name->Text = "";
			this->txt_vorname->Text = "";
			this->txt_personalnummer->Text = "";
			this->txt_passwort->Text = "";
			this->txt_arbeitsstunden->Text = "";
			this->txt_urlaubstage->Text = "";
		}

	public: void setUnternehmen(Unternehmen^ unternehmen) {
		this->unternehmen = unternehmen;
	}

	private: System::Void btn_mitarbeiter_hinzufuegen_Click(System::Object^  sender, System::EventArgs^  e) {
		bool fehler = false;

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

		else {

			this->DialogResult = System::Windows::Forms::DialogResult::OK;

		}
		//ÄNDERUNG
		if (fehler) {
			System::Windows::Forms::MessageBox::Show("Bitte füllen Sie alle Felder aus!", "Fehler!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			if (this->txt_Rolle->SelectedItem->ToString()->Equals("Mitarbeiter")) {
				//vorgesetzter = getVorgesetzter();
				Abteilung^ abteilung = gcnew Abteilung(txt_abteilung->Text, vorgesetzter);
				Mitarbeiter^ mitarbeiter = gcnew Mitarbeiter(txt_vorname->Text, txt_name->Text, abteilung, txt_personalnummer->Text, txt_passwort->Text, Int32::Parse(txt_arbeitsstunden->Text), Int32::Parse(txt_urlaubstage->Text));
				mitarbeiter->setAbteilung(abteilung);
				abteilung->fuegeMitarbeiterHinzu(mitarbeiter);
				this->Close();
			}
			else {
				Abteilung^ abteilungvorgesetzter = gcnew Abteilung(txt_abteilung->Text, vorgesetzter);
				Vorgesetzter^ vorgesetzter = gcnew Vorgesetzter(txt_vorname->Text, txt_name->Text, abteilungvorgesetzter, txt_personalnummer->Text, txt_passwort->Text, Int32::Parse(txt_arbeitsstunden->Text), Int32::Parse(txt_urlaubstage->Text));
				this->Close();
			}
		}

	}
	};
}
