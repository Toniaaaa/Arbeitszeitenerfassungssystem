#pragma once
#include "RegistrierungsFenster.h"
#include "AbteilungsFenster.h"
#include "FeiertagsFenster.h"

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
		RegistrierungsFenster^ registrierungsfenster;
		AbteilungsFenster^ abteilungsfenster;

	public:
		AuswahlFenster(void)
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
		~AuswahlFenster()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btn_angestellte;
	private: System::Windows::Forms::Button^  btn_abteilung;
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
			this->btn_angestellte = (gcnew System::Windows::Forms::Button());
			this->btn_abteilung = (gcnew System::Windows::Forms::Button());
			this->btn_feiertag = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_angestellte
			// 
			this->btn_angestellte->Location = System::Drawing::Point(95, 33);
			this->btn_angestellte->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_angestellte->Name = L"btn_angestellte";
			this->btn_angestellte->Size = System::Drawing::Size(98, 40);
			this->btn_angestellte->TabIndex = 0;
			this->btn_angestellte->Text = L"Angestellter";
			this->btn_angestellte->UseVisualStyleBackColor = true;
			this->btn_angestellte->Click += gcnew System::EventHandler(this, &AuswahlFenster::btn_angestellte_Click);
			// 
			// btn_abteilung
			// 
			this->btn_abteilung->Location = System::Drawing::Point(95, 99);
			this->btn_abteilung->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_abteilung->Name = L"btn_abteilung";
			this->btn_abteilung->Size = System::Drawing::Size(98, 40);
			this->btn_abteilung->TabIndex = 1;
			this->btn_abteilung->Text = L"Abteilung";
			this->btn_abteilung->UseVisualStyleBackColor = true;
			this->btn_abteilung->Click += gcnew System::EventHandler(this, &AuswahlFenster::btn_abteilung_Click);
			// 
			// btn_feiertag
			// 
			this->btn_feiertag->Location = System::Drawing::Point(95, 164);
			this->btn_feiertag->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_feiertag->Name = L"btn_feiertag";
			this->btn_feiertag->Size = System::Drawing::Size(98, 40);
			this->btn_feiertag->TabIndex = 2;
			this->btn_feiertag->Text = L"Feiertag";
			this->btn_feiertag->UseVisualStyleBackColor = true;
			this->btn_feiertag->Click += gcnew System::EventHandler(this, &AuswahlFenster::btn_feiertag_Click);
			// 
			// AuswahlFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(298, 250);
			this->Controls->Add(this->btn_feiertag);
			this->Controls->Add(this->btn_abteilung);
			this->Controls->Add(this->btn_angestellte);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"AuswahlFenster";
			this->Text = L"Hinzufügen";
			this->ResumeLayout(false);

		}
#pragma endregion

	public:	

	void setFeiertagsfenster(FeiertagsFenster^ feiertag) {
		this->feiertagsfenster = feiertag;
	}
		
	void setRegistrierungsfenster(RegistrierungsFenster^ registrierung) {
		this->registrierungsfenster = registrierung;
	}
			
	void setAbteilungsfenster(AbteilungsFenster^ abteilungsfenster) {
		this->abteilungsfenster = abteilungsfenster;
	}

	private: System::Void btn_angestellte_Click(System::Object^  sender, System::EventArgs^  e) {

		registrierungsfenster->ShowDialog(this);
	}
	private: System::Void btn_abteilung_Click(System::Object^  sender, System::EventArgs^  e) {

		abteilungsfenster->ShowDialog(this);
	}
	private: System::Void btn_feiertag_Click(System::Object^  sender, System::EventArgs^  e) {

		feiertagsfenster->ShowDialog(this);
		feiertagsfenster->clear();
	}

};
}
