#pragma once
#include "Unternehmen.h"
#include "StartseiteMitarbeiter.h"
#include "Angestellter.h"
#include "PasswortAendernFenster.h"

namespace Zeiterfassungssystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Media;
	//Namespace zum lesen und schreiben
	using namespace System::Runtime::Serialization::Formatters::Binary;
	using namespace System::IO;
	
	/// <summary>
	/// Zusammenfassung für loginFenster
	/// </summary>
	public ref class LoginFenster : public System::Windows::Forms::Form
	{
	private:
		SoundPlayer^ sound;
		Unternehmen^ unternehmen;
		StartseiteMitarbeiter^ startseitemitarbeiter;
		PasswortAendernFenster^ passwortaendernseite;
		Angestellter^ angestellter;
		bool loginGedrueckt = false;
		
	public:
		LoginFenster(void)
		{
			InitializeComponent();
			sound = gcnew SoundPlayer();
			unternehmen = Unternehmen::ladeUnternehmen(Unternehmen::SPEICHERORT);
			startseitemitarbeiter = gcnew StartseiteMitarbeiter;
			passwortaendernseite = gcnew PasswortAendernFenster();
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~LoginFenster()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txt_Kennwort;
	private: System::Windows::Forms::Button^  btn_passwortAendern;
	private: System::Windows::Forms::Button^  logInButton;
	private: System::Windows::Forms::Label^  BenutzernameLabel;
	private: System::Windows::Forms::Label^  KennwortLabel;

	private: System::Windows::Forms::Button^  passwortvergessenButton;
	private: System::Windows::Forms::TextBox^  txt_Benutzername;

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
			this->logInButton = (gcnew System::Windows::Forms::Button());
			this->BenutzernameLabel = (gcnew System::Windows::Forms::Label());
			this->KennwortLabel = (gcnew System::Windows::Forms::Label());
			this->passwortvergessenButton = (gcnew System::Windows::Forms::Button());
			this->txt_Benutzername = (gcnew System::Windows::Forms::TextBox());
			this->txt_Kennwort = (gcnew System::Windows::Forms::TextBox());
			this->btn_passwortAendern = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// logInButton
			// 
			this->logInButton->BackColor = System::Drawing::Color::MediumBlue;
			this->logInButton->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->logInButton->ForeColor = System::Drawing::SystemColors::Control;
			this->logInButton->Location = System::Drawing::Point(30, 152);
			this->logInButton->Name = L"logInButton";
			this->logInButton->Size = System::Drawing::Size(112, 45);
			this->logInButton->TabIndex = 2;
			this->logInButton->Text = L"Einloggen";
			this->logInButton->UseVisualStyleBackColor = false;
			this->logInButton->Click += gcnew System::EventHandler(this, &LoginFenster::logInButton_Click);
			// 
			// BenutzernameLabel
			// 
			this->BenutzernameLabel->AutoSize = true;
			this->BenutzernameLabel->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BenutzernameLabel->Location = System::Drawing::Point(27, 33);
			this->BenutzernameLabel->Name = L"BenutzernameLabel";
			this->BenutzernameLabel->Size = System::Drawing::Size(127, 16);
			this->BenutzernameLabel->TabIndex = 2;
			this->BenutzernameLabel->Text = L"Personalnummer";
			// 
			// KennwortLabel
			// 
			this->KennwortLabel->AutoSize = true;
			this->KennwortLabel->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->KennwortLabel->Location = System::Drawing::Point(27, 81);
			this->KennwortLabel->Name = L"KennwortLabel";
			this->KennwortLabel->Size = System::Drawing::Size(76, 16);
			this->KennwortLabel->TabIndex = 3;
			this->KennwortLabel->Text = L"Kennwort";
			// 
			// passwortvergessenButton
			// 
			this->passwortvergessenButton->Location = System::Drawing::Point(186, 152);
			this->passwortvergessenButton->Name = L"passwortvergessenButton";
			this->passwortvergessenButton->Size = System::Drawing::Size(112, 45);
			this->passwortvergessenButton->TabIndex = 3;
			this->passwortvergessenButton->Text = L"Passwort vergessen\?";
			this->passwortvergessenButton->UseVisualStyleBackColor = true;
			this->passwortvergessenButton->Click += gcnew System::EventHandler(this, &LoginFenster::passwortvergessenButton_Click);
			// 
			// txt_Benutzername
			// 
			this->txt_Benutzername->Location = System::Drawing::Point(198, 33);
			this->txt_Benutzername->Name = L"txt_Benutzername";
			this->txt_Benutzername->Size = System::Drawing::Size(254, 22);
			this->txt_Benutzername->TabIndex = 0;
			// 
			// txt_Kennwort
			// 
			this->txt_Kennwort->Location = System::Drawing::Point(198, 81);
			this->txt_Kennwort->Name = L"txt_Kennwort";
			this->txt_Kennwort->PasswordChar = '*';
			this->txt_Kennwort->Size = System::Drawing::Size(254, 22);
			this->txt_Kennwort->TabIndex = 1;
			// 
			// btn_passwortAendern
			// 
			this->btn_passwortAendern->Location = System::Drawing::Point(340, 152);
			this->btn_passwortAendern->Name = L"btn_passwortAendern";
			this->btn_passwortAendern->Size = System::Drawing::Size(112, 45);
			this->btn_passwortAendern->TabIndex = 4;
			this->btn_passwortAendern->Text = L"Passwort ändern";
			this->btn_passwortAendern->UseVisualStyleBackColor = true;
			this->btn_passwortAendern->Click += gcnew System::EventHandler(this, &LoginFenster::btn_passwortAendern_Click);
			// 
			// LoginFenster
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(517, 421);
			this->Controls->Add(this->btn_passwortAendern);
			this->Controls->Add(this->txt_Kennwort);
			this->Controls->Add(this->txt_Benutzername);
			this->Controls->Add(this->passwortvergessenButton);
			this->Controls->Add(this->KennwortLabel);
			this->Controls->Add(this->BenutzernameLabel);
			this->Controls->Add(this->logInButton);
			this->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::MenuText;
			this->Name = L"LoginFenster";
			this->Text = L"Login";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &LoginFenster::LoginFenster_FormClosed);
			this->Load += gcnew System::EventHandler(this, &LoginFenster::loginFenster_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



	public:
		String ^ getBenutzername() {
			return this->txt_Benutzername->Text;
		}

		String^ getKennwort() {
			return this->txt_Kennwort->Text;
		}

		void clear() {
			this->txt_Benutzername->Text = "";
			this->txt_Kennwort->Text = "";
		}

			 //Beim Laden des Fensters wird eine Sound Datei abgespielt
	private: System::Void loginFenster_Load(System::Object^  sender, System::EventArgs^  e) {
		//sound->SoundLocation = "";
		//sound->Load();
		//sound->Play();
	}

	private: System::Void logInButton_Click(System::Object^  sender, System::EventArgs^  e) {
		//System::Windows::Forms::DialogResult result = startseitemitarbeiter->ShowDialog(this);
		String^ passwort = getKennwort();
		String^ personalnummer = getBenutzername();
	    angestellter = unternehmen->loginaccept(personalnummer, passwort);
		if (angestellter != nullptr) {
			loginGedrueckt = true;
			startseitemitarbeiter->setAngemeldeterAngestelter(angestellter);
			startseitemitarbeiter->setUnternehmen(unternehmen);
			startseitemitarbeiter->Show();
			Close();
		}
		else {
			MessageBox::Show("Personalnummer oder Passwort falsch", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			clear();
		}
		
	}

	private: System::Void passwortvergessenButton_Click(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show("Bitte melden Sie sich bei Ihrem Arbeitgeber für ein neues Passwort!", "Passwort vergessen?!",
		MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	private: System::Void btn_passwortAendern_Click(System::Object^  sender, System::EventArgs^  e) {
		passwortaendernseite->setUnternehmen(unternehmen);
		passwortaendernseite->Show();
	}
	private: System::Void LoginFenster_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		if (!loginGedrueckt) {
			Application::Exit();
		}
	}
};
}