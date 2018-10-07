#pragma once
#include "Unternehmen.h"
#include "StartseiteMitarbeiter.h"
#include "Angestellter.h"
#include "PasswortAendernFenster.h"
#include "StartseiteVorgesetzte.h"
#include "PersonalFenster.h"
#include "BegruessungsFenster.h"

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
	using namespace System::Security::Cryptography; //ZUM HASHEN
	
	/// <summary>
	/// Zusammenfassung für loginFenster
	/// </summary>
	public ref class LoginFenster : public System::Windows::Forms::Form
	{
	private:
		SoundPlayer^ sound;
		Unternehmen^ unternehmen;
		StartseiteMitarbeiter^ startseitemitarbeiter;
		StartseiteVorgesetzte^ startseitevorgesetzte;
		PasswortAendernFenster^ passwortaendernseite;
		PersonalFenster^ personalfenster;
		Angestellter^ angestellter;
		SHA512^ verschluesselung;
		bool loginGedrueckt = false;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  HilfeBtn;


			 BegruessungsFenster^ begruessung;
		
	public:
		LoginFenster(void)
		{
			InitializeComponent();
			sound = gcnew SoundPlayer();
			unternehmen = Unternehmen::ladeUnternehmen(Unternehmen::SPEICHERORT);
			if (unternehmen->getAlleAngestellte()->Count == 0) {
				begruessung = gcnew BegruessungsFenster;
				begruessung->setUnternehmen(unternehmen);
				begruessung->ShowDialog(this);
			}
			startseitemitarbeiter = gcnew StartseiteMitarbeiter();
			startseitevorgesetzte = gcnew StartseiteVorgesetzte();
			passwortaendernseite = gcnew PasswortAendernFenster();
			begruessung = gcnew BegruessungsFenster();
			this->verschluesselung = gcnew SHA512Managed(); //ZUM HASHEN
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginFenster::typeid));
			this->logInButton = (gcnew System::Windows::Forms::Button());
			this->BenutzernameLabel = (gcnew System::Windows::Forms::Label());
			this->KennwortLabel = (gcnew System::Windows::Forms::Label());
			this->passwortvergessenButton = (gcnew System::Windows::Forms::Button());
			this->txt_Benutzername = (gcnew System::Windows::Forms::TextBox());
			this->txt_Kennwort = (gcnew System::Windows::Forms::TextBox());
			this->btn_passwortAendern = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->HilfeBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// logInButton
			// 
			this->logInButton->BackColor = System::Drawing::Color::MediumBlue;
			this->logInButton->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->logInButton->ForeColor = System::Drawing::SystemColors::Control;
			this->logInButton->Location = System::Drawing::Point(30, 184);
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
			this->BenutzernameLabel->Location = System::Drawing::Point(27, 87);
			this->BenutzernameLabel->Name = L"BenutzernameLabel";
			this->BenutzernameLabel->Size = System::Drawing::Size(104, 14);
			this->BenutzernameLabel->TabIndex = 2;
			this->BenutzernameLabel->Text = L"Personalnummer";
			// 
			// KennwortLabel
			// 
			this->KennwortLabel->AutoSize = true;
			this->KennwortLabel->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->KennwortLabel->Location = System::Drawing::Point(27, 132);
			this->KennwortLabel->Name = L"KennwortLabel";
			this->KennwortLabel->Size = System::Drawing::Size(61, 14);
			this->KennwortLabel->TabIndex = 3;
			this->KennwortLabel->Text = L"Kennwort";
			// 
			// passwortvergessenButton
			// 
			this->passwortvergessenButton->Location = System::Drawing::Point(188, 184);
			this->passwortvergessenButton->Name = L"passwortvergessenButton";
			this->passwortvergessenButton->Size = System::Drawing::Size(112, 45);
			this->passwortvergessenButton->TabIndex = 3;
			this->passwortvergessenButton->Text = L"Passwort vergessen\?";
			this->passwortvergessenButton->UseVisualStyleBackColor = true;
			this->passwortvergessenButton->Click += gcnew System::EventHandler(this, &LoginFenster::passwortvergessenButton_Click);
			// 
			// txt_Benutzername
			// 
			this->txt_Benutzername->Location = System::Drawing::Point(188, 84);
			this->txt_Benutzername->Name = L"txt_Benutzername";
			this->txt_Benutzername->Size = System::Drawing::Size(278, 19);
			this->txt_Benutzername->TabIndex = 0;
			// 
			// txt_Kennwort
			// 
			this->txt_Kennwort->Location = System::Drawing::Point(188, 129);
			this->txt_Kennwort->Name = L"txt_Kennwort";
			this->txt_Kennwort->PasswordChar = '*';
			this->txt_Kennwort->Size = System::Drawing::Size(278, 19);
			this->txt_Kennwort->TabIndex = 1;
			// 
			// btn_passwortAendern
			// 
			this->btn_passwortAendern->Location = System::Drawing::Point(354, 184);
			this->btn_passwortAendern->Name = L"btn_passwortAendern";
			this->btn_passwortAendern->Size = System::Drawing::Size(112, 45);
			this->btn_passwortAendern->TabIndex = 4;
			this->btn_passwortAendern->Text = L"Passwort ändern";
			this->btn_passwortAendern->UseVisualStyleBackColor = true;
			this->btn_passwortAendern->Click += gcnew System::EventHandler(this, &LoginFenster::btn_passwortAendern_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(508, 29);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(173, 200);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(24, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(91, 32);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Login";
			// 
			// HilfeBtn
			// 
			this->HilfeBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->HilfeBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HilfeBtn->Location = System::Drawing::Point(430, 31);
			this->HilfeBtn->Name = L"HilfeBtn";
			this->HilfeBtn->Size = System::Drawing::Size(36, 32);
			this->HilfeBtn->TabIndex = 5;
			this->HilfeBtn->Text = L"\?";
			this->HilfeBtn->UseVisualStyleBackColor = true;
			this->HilfeBtn->Click += gcnew System::EventHandler(this, &LoginFenster::HilfeBtn_Click);
			// 
			// LoginFenster
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(693, 248);
			this->Controls->Add(this->HilfeBtn);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
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
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"LoginFenster";
			this->Text = L"Login";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &LoginFenster::LoginFenster_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
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

	private: System::Void logInButton_Click(System::Object^  sender, System::EventArgs^  e) {
		array<Byte>^ passwort = System::Text::Encoding::UTF8->GetBytes(getKennwort()); //ZUM HASHEN
		array<Byte>^ passwortVerschluesselt = verschluesselung->ComputeHash(passwort); //ZUM HASHEN
		/*LogIndaten werden überprüft, ebenfalls die rolle des Angestellten damit sich passendes Fenster öffnet
		* Unternehmen wird uebergeben
		*/
		String^ personalnummer = getBenutzername();
	    angestellter = unternehmen->loginaccept(personalnummer, passwortVerschluesselt);
		if (angestellter != nullptr && angestellter->istVorgesetzter() == false) {
			loginGedrueckt = true;
			startseitemitarbeiter->setAngemeldeterAngestellter((Mitarbeiter^) angestellter);
			startseitemitarbeiter->setUnternehmen(unternehmen);
			startseitemitarbeiter->Show();
			Close();
		}
		else if (angestellter != nullptr && angestellter->istVorgesetzter() == true) {
			loginGedrueckt = true;
			startseitevorgesetzte->setAngemeldeterAngestellter((Vorgesetzter^) angestellter);
			startseitevorgesetzte->setUnternehmen(unternehmen);
			startseitevorgesetzte->Show();
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

	/*HILFE-BUTTON "?"
	Startet den PDF-Reader des Systems und öffnet die Anleitung zum Programm*/
	private: System::Void HilfeBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		try {
			Diagnostics::ProcessStartInfo^ startInfo = gcnew Diagnostics::ProcessStartInfo("BenutzerhandbuchTimeUp.pdf");
			Diagnostics::Process::Start(startInfo);
		}
		catch (System::ComponentModel::Win32Exception ^e) {
			MessageBox::Show("Das Benutzerhandbuch konnte leider nicht gefunden werden.\nBitte wenden Sie sich an Ihren Administrator!", "Datei nicht gefunden",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

};
}
