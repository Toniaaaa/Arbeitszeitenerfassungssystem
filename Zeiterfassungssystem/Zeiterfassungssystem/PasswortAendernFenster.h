#pragma once
#include "Angestellter.h"
#include "Unternehmen.h"

namespace Zeiterfassungssystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Security::Cryptography; //ZUM HASHEN
	
	/// <summary>
	/// Zusammenfassung für PasswortAendernFenster
	/// </summary>
	public ref class PasswortAendernFenster : public System::Windows::Forms::Form
	{
	private:
		Unternehmen^ unternehmen;
		SHA512^ hash; //ZUM HASHEN
	public:
		PasswortAendernFenster(void)
		{
			this->hash = gcnew SHA512Managed(); //ZUM HASHEN
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~PasswortAendernFenster()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lbl_PasswortAendern;
	private: System::Windows::Forms::Button^  btn_bestätigen;
	private: System::Windows::Forms::Button^  btn_abbrechen;
	private: System::Windows::Forms::Label^  lbl_benutzername;
	private: System::Windows::Forms::Label^  lbl_altesPasswort;
	private: System::Windows::Forms::Label^  lbl_neuesPasswort;
	private: System::Windows::Forms::Label^  lbl_neuesPasswortbestättigen;
	private: System::Windows::Forms::TextBox^  txt_benutzername;
	private: System::Windows::Forms::TextBox^  txt_altespasswort;
	private: System::Windows::Forms::TextBox^  txt_neuespasswort;
	private: System::Windows::Forms::TextBox^  txt_passwortwiederholen;

	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PasswortAendernFenster::typeid));
			this->btn_bestätigen = (gcnew System::Windows::Forms::Button());
			this->btn_abbrechen = (gcnew System::Windows::Forms::Button());
			this->lbl_benutzername = (gcnew System::Windows::Forms::Label());
			this->lbl_altesPasswort = (gcnew System::Windows::Forms::Label());
			this->lbl_neuesPasswort = (gcnew System::Windows::Forms::Label());
			this->lbl_neuesPasswortbestättigen = (gcnew System::Windows::Forms::Label());
			this->txt_benutzername = (gcnew System::Windows::Forms::TextBox());
			this->txt_altespasswort = (gcnew System::Windows::Forms::TextBox());
			this->txt_neuespasswort = (gcnew System::Windows::Forms::TextBox());
			this->txt_passwortwiederholen = (gcnew System::Windows::Forms::TextBox());
			this->lbl_PasswortAendern = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btn_bestätigen
			// 
			this->btn_bestätigen->Location = System::Drawing::Point(52, 290);
			this->btn_bestätigen->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_bestätigen->Name = L"btn_bestätigen";
			this->btn_bestätigen->Size = System::Drawing::Size(99, 52);
			this->btn_bestätigen->TabIndex = 0;
			this->btn_bestätigen->Text = L"Bestätigen";
			this->btn_bestätigen->UseVisualStyleBackColor = true;
			this->btn_bestätigen->Click += gcnew System::EventHandler(this, &PasswortAendernFenster::btn_bestätigen_Click);
			// 
			// btn_abbrechen
			// 
			this->btn_abbrechen->Location = System::Drawing::Point(229, 290);
			this->btn_abbrechen->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_abbrechen->Name = L"btn_abbrechen";
			this->btn_abbrechen->Size = System::Drawing::Size(99, 52);
			this->btn_abbrechen->TabIndex = 1;
			this->btn_abbrechen->Text = L"Abbrechen";
			this->btn_abbrechen->UseVisualStyleBackColor = true;
			this->btn_abbrechen->Click += gcnew System::EventHandler(this, &PasswortAendernFenster::btn_abbrechen_Click_1);
			// 
			// lbl_benutzername
			// 
			this->lbl_benutzername->AutoSize = true;
			this->lbl_benutzername->Location = System::Drawing::Point(13, 94);
			this->lbl_benutzername->Name = L"lbl_benutzername";
			this->lbl_benutzername->Size = System::Drawing::Size(100, 17);
			this->lbl_benutzername->TabIndex = 2;
			this->lbl_benutzername->Text = L"Benutzername";
			// 
			// lbl_altesPasswort
			// 
			this->lbl_altesPasswort->AutoSize = true;
			this->lbl_altesPasswort->Location = System::Drawing::Point(13, 133);
			this->lbl_altesPasswort->Name = L"lbl_altesPasswort";
			this->lbl_altesPasswort->Size = System::Drawing::Size(100, 17);
			this->lbl_altesPasswort->TabIndex = 3;
			this->lbl_altesPasswort->Text = L"Altes Passwort";
			// 
			// lbl_neuesPasswort
			// 
			this->lbl_neuesPasswort->AutoSize = true;
			this->lbl_neuesPasswort->Location = System::Drawing::Point(12, 181);
			this->lbl_neuesPasswort->Name = L"lbl_neuesPasswort";
			this->lbl_neuesPasswort->Size = System::Drawing::Size(110, 17);
			this->lbl_neuesPasswort->TabIndex = 4;
			this->lbl_neuesPasswort->Text = L"Neues Passwort";
			// 
			// lbl_neuesPasswortbestättigen
			// 
			this->lbl_neuesPasswortbestättigen->AutoSize = true;
			this->lbl_neuesPasswortbestättigen->Location = System::Drawing::Point(12, 224);
			this->lbl_neuesPasswortbestättigen->Name = L"lbl_neuesPasswortbestättigen";
			this->lbl_neuesPasswortbestättigen->Size = System::Drawing::Size(145, 17);
			this->lbl_neuesPasswortbestättigen->TabIndex = 5;
			this->lbl_neuesPasswortbestättigen->Text = L"Passwort wiederholen";
			// 
			// txt_benutzername
			// 
			this->txt_benutzername->Location = System::Drawing::Point(192, 94);
			this->txt_benutzername->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txt_benutzername->Name = L"txt_benutzername";
			this->txt_benutzername->Size = System::Drawing::Size(149, 22);
			this->txt_benutzername->TabIndex = 6;
			// 
			// txt_altespasswort
			// 
			this->txt_altespasswort->Location = System::Drawing::Point(192, 130);
			this->txt_altespasswort->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txt_altespasswort->Name = L"txt_altespasswort";
			this->txt_altespasswort->PasswordChar = '*';
			this->txt_altespasswort->Size = System::Drawing::Size(149, 22);
			this->txt_altespasswort->TabIndex = 7;
			// 
			// txt_neuespasswort
			// 
			this->txt_neuespasswort->Location = System::Drawing::Point(192, 176);
			this->txt_neuespasswort->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txt_neuespasswort->Name = L"txt_neuespasswort";
			this->txt_neuespasswort->PasswordChar = '*';
			this->txt_neuespasswort->Size = System::Drawing::Size(149, 22);
			this->txt_neuespasswort->TabIndex = 8;
			// 
			// txt_passwortwiederholen
			// 
			this->txt_passwortwiederholen->Location = System::Drawing::Point(192, 224);
			this->txt_passwortwiederholen->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txt_passwortwiederholen->Name = L"txt_passwortwiederholen";
			this->txt_passwortwiederholen->PasswordChar = '*';
			this->txt_passwortwiederholen->Size = System::Drawing::Size(149, 22);
			this->txt_passwortwiederholen->TabIndex = 9;
			// 
			// lbl_PasswortAendern
			// 
			this->lbl_PasswortAendern->AutoSize = true;
			this->lbl_PasswortAendern->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_PasswortAendern->Location = System::Drawing::Point(13, 21);
			this->lbl_PasswortAendern->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_PasswortAendern->Name = L"lbl_PasswortAendern";
			this->lbl_PasswortAendern->Size = System::Drawing::Size(334, 46);
			this->lbl_PasswortAendern->TabIndex = 10;
			this->lbl_PasswortAendern->Text = L"Passwort ändern";
			// 
			// PasswortAendernFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(377, 370);
			this->Controls->Add(this->lbl_PasswortAendern);
			this->Controls->Add(this->txt_passwortwiederholen);
			this->Controls->Add(this->txt_neuespasswort);
			this->Controls->Add(this->txt_altespasswort);
			this->Controls->Add(this->txt_benutzername);
			this->Controls->Add(this->lbl_neuesPasswortbestättigen);
			this->Controls->Add(this->lbl_neuesPasswort);
			this->Controls->Add(this->lbl_altesPasswort);
			this->Controls->Add(this->lbl_benutzername);
			this->Controls->Add(this->btn_abbrechen);
			this->Controls->Add(this->btn_bestätigen);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"PasswortAendernFenster";
			this->Text = L"Passwort Ändern";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &PasswortAendernFenster::PasswortAendernFenster_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		String^ getBenutzername() {
			return this->txt_benutzername->Text;
		}

		String^ getAltesPasswort() {
			return this->txt_altespasswort->Text;
		}

		String^ getNeuesPasswort() {
			return this->txt_neuespasswort->Text;
		}

		String^ getPasswortWiederholen() {
			return this->txt_passwortwiederholen->Text;
		}

		void  setUnternehmen(Unternehmen^ unternehmen) {
			this->unternehmen = unternehmen;
		}

		void clear() {
			this->txt_benutzername->Text = "";
			this->txt_altespasswort->Text = "";
			this->txt_neuespasswort->Text = "";
			this->txt_passwortwiederholen->Text = "";
		}
		//Beim Klick auf den Button wird überprüft ob alle Textboxen richtig ausgefüllt ansonsten Hinweis
	private: System::Void btn_bestätigen_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ personalnummer = getBenutzername();
		String^ passwort = getAltesPasswort();
		Angestellter^ angestellter;
		array<Byte>^ passwortBytes = System::Text::Encoding::UTF8->GetBytes(passwort); //ZUM HASHEN
		String^ neuespasswort = getNeuesPasswort();
		array<Byte>^ passwortCrypt = hash->ComputeHash(passwortBytes); //ZUM HASHEN
		array<Byte>^ neuespasswortBytes = System::Text::Encoding::UTF8->GetBytes(neuespasswort); //ZUM HASHEN
		array<Byte>^ neuespasswortCrypt = hash->ComputeHash(neuespasswortBytes); //ZUM HASHEN
		String^ passwortwiederholen = getPasswortWiederholen();
		//prueft ob angestellter und altes Passwort uebereinstimmmen
		angestellter = unternehmen->loginaccept(personalnummer, passwortCrypt);
		if (angestellter == nullptr) {
			MessageBox::Show("Personalnummer oder Passwort falsch", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			clear();
		}
		//wenn alles okay dann wird neues Passwort gespeichert 
		else if (neuespasswort->Equals(passwortwiederholen) && neuespasswort != "") {
			angestellter->setPasswort(neuespasswortCrypt);
			this->clear();
			this->Close();
		}
		else {
			MessageBox::Show("Neues Passwort stimmt nicht überein oder Feld leer!", "Fehler!",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
			txt_neuespasswort->Text = "";
			txt_passwortwiederholen->Text = "";

		}

	}
    //Bei Klick auf den Button wird das Fenster geschlossen
	private: System::Void btn_abbrechen_Click_1(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
		this->clear();
	}
	private: System::Void PasswortAendernFenster_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		this->clear();
	}
};
}
