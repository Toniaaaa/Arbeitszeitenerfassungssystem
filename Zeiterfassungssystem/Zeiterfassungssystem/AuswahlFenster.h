#pragma once
#include "BearbeitungsFenster.h"
#include "FeiertagsFenster.h"
#include "UrlaubLoeschenFenster.h"
#include "Angestellter.h"
#include "AbteilungLoeschenFenster.h"
#include "Vorgesetzter.h"

namespace Zeiterfassungssystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für AuswahlFenster
	/// </summary>
	public ref class AuswahlFenster : public System::Windows::Forms::Form
	{

	private: 
		FeiertagsFenster^ feiertagsfenster;
		BearbeitungsFenster^ bearbeitungsfenster;
		UrlaubLoeschenFenster^ urlaubLoeschenfenster;
		AbteilungLoeschenFenster^ abteilungFenster;
		Boolean adminRechte;
	private: System::Windows::Forms::Button^  abteilungBtn; 

	public:
		AuswahlFenster(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~AuswahlFenster()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btn_angestellte;
	private: System::Windows::Forms::Button^  btn_urlaub;
	private: System::Windows::Forms::Button^  btn_feiertag;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AuswahlFenster::typeid));
			this->btn_angestellte = (gcnew System::Windows::Forms::Button());
			this->btn_urlaub = (gcnew System::Windows::Forms::Button());
			this->btn_feiertag = (gcnew System::Windows::Forms::Button());
			this->abteilungBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_angestellte
			// 
			this->btn_angestellte->Location = System::Drawing::Point(25, 33);
			this->btn_angestellte->Margin = System::Windows::Forms::Padding(2);
			this->btn_angestellte->Name = L"btn_angestellte";
			this->btn_angestellte->Size = System::Drawing::Size(100, 49);
			this->btn_angestellte->TabIndex = 0;
			this->btn_angestellte->Text = L"Angestellten bearbeiten";
			this->btn_angestellte->UseVisualStyleBackColor = true;
			this->btn_angestellte->Click += gcnew System::EventHandler(this, &AuswahlFenster::btn_angestellte_Click);
			// 
			// btn_urlaub
			// 
			this->btn_urlaub->Location = System::Drawing::Point(25, 110);
			this->btn_urlaub->Margin = System::Windows::Forms::Padding(2);
			this->btn_urlaub->Name = L"btn_urlaub";
			this->btn_urlaub->Size = System::Drawing::Size(100, 49);
			this->btn_urlaub->TabIndex = 1;
			this->btn_urlaub->Text = L"Freie Tage löschen";
			this->btn_urlaub->UseVisualStyleBackColor = true;
			this->btn_urlaub->Click += gcnew System::EventHandler(this, &AuswahlFenster::btn_urlaub_Click);
			// 
			// btn_feiertag
			// 
			this->btn_feiertag->Location = System::Drawing::Point(175, 33);
			this->btn_feiertag->Margin = System::Windows::Forms::Padding(2);
			this->btn_feiertag->Name = L"btn_feiertag";
			this->btn_feiertag->Size = System::Drawing::Size(100, 49);
			this->btn_feiertag->TabIndex = 2;
			this->btn_feiertag->Text = L"Feiertage bearbeiten";
			this->btn_feiertag->UseVisualStyleBackColor = true;
			this->btn_feiertag->Click += gcnew System::EventHandler(this, &AuswahlFenster::btn_feiertag_Click);
			// 
			// abteilungBtn
			// 
			this->abteilungBtn->Location = System::Drawing::Point(175, 110);
			this->abteilungBtn->Margin = System::Windows::Forms::Padding(2);
			this->abteilungBtn->Name = L"abteilungBtn";
			this->abteilungBtn->Size = System::Drawing::Size(100, 49);
			this->abteilungBtn->TabIndex = 3;
			this->abteilungBtn->Text = L"Abteilung auflösen";
			this->abteilungBtn->UseVisualStyleBackColor = true;
			this->abteilungBtn->Click += gcnew System::EventHandler(this, &AuswahlFenster::abteilungBtn_Click);
			// 
			// AuswahlFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(301, 191);
			this->Controls->Add(this->abteilungBtn);
			this->Controls->Add(this->btn_feiertag);
			this->Controls->Add(this->btn_urlaub);
			this->Controls->Add(this->btn_angestellte);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"AuswahlFenster";
			this->Text = L"Bearbeiten";
			this->Load += gcnew System::EventHandler(this, &AuswahlFenster::AuswahlFenster_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	public:	
	//Setter für die verschiedenen Fenster 
	void setFeiertagsfenster(FeiertagsFenster^ feiertag) {
		this->feiertagsfenster = feiertag;
	}
		
	void setBearbeitungsfenster(BearbeitungsFenster^ bearbeitung) {
		this->bearbeitungsfenster = bearbeitung;
	}
			
	void setUrlaubLoeschenfenster(UrlaubLoeschenFenster^ urlaubFenster) {
		this->urlaubLoeschenfenster = urlaubFenster;
	}

	void setAbteilungLoeschenFenster(AbteilungLoeschenFenster^ abteilungFenster) {
		this->abteilungFenster = abteilungFenster;
	}

	void setAdminRechte(Boolean istAdmin) {
		this->adminRechte = istAdmin;
	}

	private: System::Void btn_angestellte_Click(System::Object^  sender, System::EventArgs^  e) {
		System::Windows::Forms::DialogResult result = bearbeitungsfenster->ShowDialog(this);
		if (result == System::Windows::Forms::DialogResult::OK) {
			this->Close();
		}
	}

	private: System::Void btn_feiertag_Click(System::Object^  sender, System::EventArgs^  e) {
		System::Windows::Forms::DialogResult result = feiertagsfenster->ShowDialog(this);
		feiertagsfenster->clear();
		if (result == System::Windows::Forms::DialogResult::OK) {
			this->Close();
		}
	}

	private: System::Void btn_urlaub_Click(System::Object^  sender, System::EventArgs^  e) {
		System::Windows::Forms::DialogResult result = urlaubLoeschenfenster->ShowDialog(this);
		if (result == System::Windows::Forms::DialogResult::OK && urlaubLoeschenfenster->p_Art->Equals("Urlaub")) {
			String^ urlaubLoeschenString = "Wollen Sie " + urlaubLoeschenfenster->p_Angestellter->getVorname() + " " + urlaubLoeschenfenster->p_Angestellter->getNachname() +
				" wirklich alle Urlaubstage\n\nvon: " + urlaubLoeschenfenster->p_Anfang.ToString("dddd, dd. MMMM yyyy") + "\nbis: " + urlaubLoeschenfenster->p_Ende.ToString("dddd, dd. MMMM yyyy")
				+ "\n\nentfernen?";
			if (MessageBox::Show(urlaubLoeschenString, "Wirklich entfernen?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				urlaubLoeschenfenster->p_Angestellter->loescheUrlaubstage(urlaubLoeschenfenster->p_Anfang, urlaubLoeschenfenster->p_Ende, urlaubLoeschenfenster->p_Kommentar);
			}
		}
		else if (result == System::Windows::Forms::DialogResult::OK && urlaubLoeschenfenster->p_Art->Equals("Krankmeldung")) {
			String^ urlaubLoeschenString = "Wollen Sie " + urlaubLoeschenfenster->p_Angestellter->getVorname() + " " + urlaubLoeschenfenster->p_Angestellter->getNachname() +
				" wirklich alle Krankheitstage\n\nvon: " + urlaubLoeschenfenster->p_Anfang.ToString("dddd, dd. MMMM yyyy") + "\nbis: " + urlaubLoeschenfenster->p_Ende.ToString("dddd, dd. MMMM yyyy")
				+ "\n\nentfernen?";
			if (MessageBox::Show(urlaubLoeschenString, "Wirklich entfernen?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				urlaubLoeschenfenster->p_Angestellter->loescheKrankheitstage(urlaubLoeschenfenster->p_Anfang, urlaubLoeschenfenster->p_Ende, urlaubLoeschenfenster->p_Kommentar);
			}
		}
		urlaubLoeschenfenster->clear();
		this->Close();
	}

	private: System::Void abteilungBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		System::Windows::Forms::DialogResult result = abteilungFenster->ShowDialog(this);
		if (result == System::Windows::Forms::DialogResult::OK) {
			this->Close();
		}
	}

	private: System::Void AuswahlFenster_Load(System::Object^  sender, System::EventArgs^  e) {
		//Wenn der User keine Admin-Rechte hat, kann er bestimmte Buttons nicht nutzen
		if (!adminRechte) {
			abteilungBtn->Enabled = false;
			btn_feiertag->Enabled = false;
		}
	}
};
}
