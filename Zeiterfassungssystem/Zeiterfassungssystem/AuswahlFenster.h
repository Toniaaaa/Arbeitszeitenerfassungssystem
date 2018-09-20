#pragma once
#include "RegistrierungsFenster.h"
#include "FeiertagsFenster.h"
#include "UrlaubLoeschenFenster.h"
#include "Angestellter.h"

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
		UrlaubLoeschenFenster^ urlaubLoeschenfenster;

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
			this->btn_angestellte = (gcnew System::Windows::Forms::Button());
			this->btn_urlaub = (gcnew System::Windows::Forms::Button());
			this->btn_feiertag = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_angestellte
			// 
			this->btn_angestellte->Location = System::Drawing::Point(142, 51);
			this->btn_angestellte->Name = L"btn_angestellte";
			this->btn_angestellte->Size = System::Drawing::Size(150, 75);
			this->btn_angestellte->TabIndex = 0;
			this->btn_angestellte->Text = L"Angestellten hinzufügen";
			this->btn_angestellte->UseVisualStyleBackColor = true;
			this->btn_angestellte->Click += gcnew System::EventHandler(this, &AuswahlFenster::btn_angestellte_Click);
			// 
			// btn_urlaub
			// 
			this->btn_urlaub->Location = System::Drawing::Point(142, 152);
			this->btn_urlaub->Name = L"btn_urlaub";
			this->btn_urlaub->Size = System::Drawing::Size(150, 75);
			this->btn_urlaub->TabIndex = 1;
			this->btn_urlaub->Text = L"Urlaub löschen";
			this->btn_urlaub->UseVisualStyleBackColor = true;
			this->btn_urlaub->Click += gcnew System::EventHandler(this, &AuswahlFenster::btn_urlaub_Click);
			// 
			// btn_feiertag
			// 
			this->btn_feiertag->Location = System::Drawing::Point(142, 255);
			this->btn_feiertag->Name = L"btn_feiertag";
			this->btn_feiertag->Size = System::Drawing::Size(150, 75);
			this->btn_feiertag->TabIndex = 2;
			this->btn_feiertag->Text = L"Feiertage bearbeiten";
			this->btn_feiertag->UseVisualStyleBackColor = true;
			this->btn_feiertag->Click += gcnew System::EventHandler(this, &AuswahlFenster::btn_feiertag_Click);
			// 
			// AuswahlFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(447, 385);
			this->Controls->Add(this->btn_feiertag);
			this->Controls->Add(this->btn_urlaub);
			this->Controls->Add(this->btn_angestellte);
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
			
	void setUrlaubLoeschenfenster(UrlaubLoeschenFenster^ urlaubFenster) {
		this->urlaubLoeschenfenster = urlaubFenster;
	}

	private: System::Void btn_angestellte_Click(System::Object^  sender, System::EventArgs^  e) {
		registrierungsfenster->ShowDialog(this);
	}

	private: System::Void btn_feiertag_Click(System::Object^  sender, System::EventArgs^  e) {
		feiertagsfenster->ShowDialog(this);
		feiertagsfenster->clear();
	}

	private: System::Void btn_urlaub_Click(System::Object^  sender, System::EventArgs^  e) {
		System::Windows::Forms::DialogResult result = urlaubLoeschenfenster->ShowDialog(this);
		if (result == System::Windows::Forms::DialogResult::OK) {
			urlaubLoeschenfenster->p_Angestellter->loescheUrlaubstage(urlaubLoeschenfenster->p_Anfang, urlaubLoeschenfenster->p_Ende);
		}
		urlaubLoeschenfenster->clear();
	}
};
}
