#pragma once

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

	protected:

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
			this->btn_angestellte = (gcnew System::Windows::Forms::Button());
			this->btn_abteilung = (gcnew System::Windows::Forms::Button());
			this->btn_feiertag = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_angestellte
			// 
			this->btn_angestellte->Location = System::Drawing::Point(127, 41);
			this->btn_angestellte->Name = L"btn_angestellte";
			this->btn_angestellte->Size = System::Drawing::Size(130, 49);
			this->btn_angestellte->TabIndex = 0;
			this->btn_angestellte->Text = L"Angestellter";
			this->btn_angestellte->UseVisualStyleBackColor = true;
			this->btn_angestellte->Click += gcnew System::EventHandler(this, &AuswahlFenster::btn_angestellte_Click);
			// 
			// btn_abteilung
			// 
			this->btn_abteilung->Location = System::Drawing::Point(127, 122);
			this->btn_abteilung->Name = L"btn_abteilung";
			this->btn_abteilung->Size = System::Drawing::Size(130, 49);
			this->btn_abteilung->TabIndex = 1;
			this->btn_abteilung->Text = L"Abteilung";
			this->btn_abteilung->UseVisualStyleBackColor = true;
			this->btn_abteilung->Click += gcnew System::EventHandler(this, &AuswahlFenster::btn_abteilung_Click);
			// 
			// btn_feiertag
			// 
			this->btn_feiertag->Location = System::Drawing::Point(127, 202);
			this->btn_feiertag->Name = L"btn_feiertag";
			this->btn_feiertag->Size = System::Drawing::Size(130, 49);
			this->btn_feiertag->TabIndex = 2;
			this->btn_feiertag->Text = L"Feiertag";
			this->btn_feiertag->UseVisualStyleBackColor = true;
			this->btn_feiertag->Click += gcnew System::EventHandler(this, &AuswahlFenster::btn_feiertag_Click);
			// 
			// AuswahlFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(398, 308);
			this->Controls->Add(this->btn_feiertag);
			this->Controls->Add(this->btn_abteilung);
			this->Controls->Add(this->btn_angestellte);
			this->Name = L"AuswahlFenster";
			this->Text = L"Hinzufügen";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btn_angestellte_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void btn_abteilung_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void btn_feiertag_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	};
}
