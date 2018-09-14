#pragma once
#include "Urlaubsantrag.h"

namespace Zeiterfassungssystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für AenderungsbearbeitungsFenster
	/// </summary>
	public ref class UrlaubsanfragenbearbeitungsFenster : public System::Windows::Forms::Form
	{
	private:
		bool anfrage;
		Urlaubsantrag^ antrag;

	public:
		UrlaubsanfragenbearbeitungsFenster(void)
		{
			InitializeComponent();

			anfrage = false;
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~UrlaubsanfragenbearbeitungsFenster()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btn_AenderungBestaetigen;
	private: System::Windows::Forms::Button^  btn_AenderungAblehnen;
	private: System::Windows::Forms::Label^  lbl_Aenderungsanfrage;
	private: System::Windows::Forms::Label^  lbl_NameMA;
	private: System::Windows::Forms::Label^  lbl_AnfrageErsterTag;
	private: System::Windows::Forms::Label^  lbl_AnfrageLetzterUrlaubstag;
	private: System::Windows::Forms::Label^  lbl_AnfrageAnzahlUrlaubstage;
	private: System::Windows::Forms::Label^  lbl_ende;
	private: System::Windows::Forms::Label^  lbl_tage;
	private: System::Windows::Forms::Label^  lbl_anfang;

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
			this->btn_AenderungBestaetigen = (gcnew System::Windows::Forms::Button());
			this->btn_AenderungAblehnen = (gcnew System::Windows::Forms::Button());
			this->lbl_Aenderungsanfrage = (gcnew System::Windows::Forms::Label());
			this->lbl_NameMA = (gcnew System::Windows::Forms::Label());
			this->lbl_AnfrageErsterTag = (gcnew System::Windows::Forms::Label());
			this->lbl_AnfrageLetzterUrlaubstag = (gcnew System::Windows::Forms::Label());
			this->lbl_AnfrageAnzahlUrlaubstage = (gcnew System::Windows::Forms::Label());
			this->lbl_ende = (gcnew System::Windows::Forms::Label());
			this->lbl_tage = (gcnew System::Windows::Forms::Label());
			this->lbl_anfang = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btn_AenderungBestaetigen
			// 
			this->btn_AenderungBestaetigen->Location = System::Drawing::Point(30, 257);
			this->btn_AenderungBestaetigen->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->btn_AenderungBestaetigen->Name = L"btn_AenderungBestaetigen";
			this->btn_AenderungBestaetigen->Size = System::Drawing::Size(85, 40);
			this->btn_AenderungBestaetigen->TabIndex = 0;
			this->btn_AenderungBestaetigen->Text = L"Bestätigen";
			this->btn_AenderungBestaetigen->UseVisualStyleBackColor = true;
			// 
			// btn_AenderungAblehnen
			// 
			this->btn_AenderungAblehnen->Location = System::Drawing::Point(179, 257);
			this->btn_AenderungAblehnen->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->btn_AenderungAblehnen->Name = L"btn_AenderungAblehnen";
			this->btn_AenderungAblehnen->Size = System::Drawing::Size(85, 40);
			this->btn_AenderungAblehnen->TabIndex = 1;
			this->btn_AenderungAblehnen->Text = L"Ablehnen";
			this->btn_AenderungAblehnen->UseVisualStyleBackColor = true;
			// 
			// lbl_Aenderungsanfrage
			// 
			this->lbl_Aenderungsanfrage->AutoSize = true;
			this->lbl_Aenderungsanfrage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Aenderungsanfrage->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->lbl_Aenderungsanfrage->Location = System::Drawing::Point(26, 16);
			this->lbl_Aenderungsanfrage->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Aenderungsanfrage->Name = L"lbl_Aenderungsanfrage";
			this->lbl_Aenderungsanfrage->Size = System::Drawing::Size(261, 58);
			this->lbl_Aenderungsanfrage->TabIndex = 2;
			this->lbl_Aenderungsanfrage->Text = L"Neue Urlaubsanfrage\r\n              von ";
			// 
			// lbl_NameMA
			// 
			this->lbl_NameMA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_NameMA->Location = System::Drawing::Point(1, 88);
			this->lbl_NameMA->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_NameMA->Name = L"lbl_NameMA";
			this->lbl_NameMA->Size = System::Drawing::Size(295, 26);
			this->lbl_NameMA->TabIndex = 3;
			this->lbl_NameMA->Text = L"Beispiel MA";
			this->lbl_NameMA->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbl_AnfrageErsterTag
			// 
			this->lbl_AnfrageErsterTag->AutoSize = true;
			this->lbl_AnfrageErsterTag->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_AnfrageErsterTag->Location = System::Drawing::Point(9, 129);
			this->lbl_AnfrageErsterTag->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_AnfrageErsterTag->Name = L"lbl_AnfrageErsterTag";
			this->lbl_AnfrageErsterTag->Size = System::Drawing::Size(123, 17);
			this->lbl_AnfrageErsterTag->TabIndex = 4;
			this->lbl_AnfrageErsterTag->Text = L"Erster Urlaubstag:";
			// 
			// lbl_AnfrageLetzterUrlaubstag
			// 
			this->lbl_AnfrageLetzterUrlaubstag->AutoSize = true;
			this->lbl_AnfrageLetzterUrlaubstag->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_AnfrageLetzterUrlaubstag->Location = System::Drawing::Point(11, 157);
			this->lbl_AnfrageLetzterUrlaubstag->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_AnfrageLetzterUrlaubstag->Name = L"lbl_AnfrageLetzterUrlaubstag";
			this->lbl_AnfrageLetzterUrlaubstag->Size = System::Drawing::Size(129, 17);
			this->lbl_AnfrageLetzterUrlaubstag->TabIndex = 5;
			this->lbl_AnfrageLetzterUrlaubstag->Text = L"Letzter Urlaubstag:";
			// 
			// lbl_AnfrageAnzahlUrlaubstage
			// 
			this->lbl_AnfrageAnzahlUrlaubstage->AutoSize = true;
			this->lbl_AnfrageAnzahlUrlaubstage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_AnfrageAnzahlUrlaubstage->Location = System::Drawing::Point(11, 185);
			this->lbl_AnfrageAnzahlUrlaubstage->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_AnfrageAnzahlUrlaubstage->Name = L"lbl_AnfrageAnzahlUrlaubstage";
			this->lbl_AnfrageAnzahlUrlaubstage->Size = System::Drawing::Size(136, 17);
			this->lbl_AnfrageAnzahlUrlaubstage->TabIndex = 6;
			this->lbl_AnfrageAnzahlUrlaubstage->Text = L"Anzahl Urlaubstage:";
			// 
			// lbl_ende
			// 
			this->lbl_ende->AutoSize = true;
			this->lbl_ende->Location = System::Drawing::Point(189, 157);
			this->lbl_ende->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_ende->Name = L"lbl_ende";
			this->lbl_ende->Size = System::Drawing::Size(61, 13);
			this->lbl_ende->TabIndex = 7;
			this->lbl_ende->Text = L"00.00.0000";
			// 
			// lbl_tage
			// 
			this->lbl_tage->AutoSize = true;
			this->lbl_tage->Location = System::Drawing::Point(189, 185);
			this->lbl_tage->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_tage->Name = L"lbl_tage";
			this->lbl_tage->Size = System::Drawing::Size(19, 13);
			this->lbl_tage->TabIndex = 8;
			this->lbl_tage->Text = L"00";
			this->lbl_tage->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lbl_anfang
			// 
			this->lbl_anfang->AutoSize = true;
			this->lbl_anfang->Location = System::Drawing::Point(189, 136);
			this->lbl_anfang->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_anfang->Name = L"lbl_anfang";
			this->lbl_anfang->Size = System::Drawing::Size(61, 13);
			this->lbl_anfang->TabIndex = 11;
			this->lbl_anfang->Text = L"00.00.0000";
			this->lbl_anfang->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// UrlaubsanfragenbearbeitungsFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(297, 324);
			this->Controls->Add(this->lbl_anfang);
			this->Controls->Add(this->lbl_tage);
			this->Controls->Add(this->lbl_ende);
			this->Controls->Add(this->lbl_AnfrageAnzahlUrlaubstage);
			this->Controls->Add(this->lbl_AnfrageLetzterUrlaubstag);
			this->Controls->Add(this->lbl_AnfrageErsterTag);
			this->Controls->Add(this->lbl_NameMA);
			this->Controls->Add(this->lbl_Aenderungsanfrage);
			this->Controls->Add(this->btn_AenderungAblehnen);
			this->Controls->Add(this->btn_AenderungBestaetigen);
			this->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->Name = L"UrlaubsanfragenbearbeitungsFenster";
			this->Text = L"Neue Anfrage";
			this->Load += gcnew System::EventHandler(this, &UrlaubsanfragenbearbeitungsFenster::AenderungsbearbeitungsFenster_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void AenderungsbearbeitungsFenster_Load(System::Object^  sender, System::EventArgs^  e) {
		p_Name = antrag->getAntragsteller()->getVorname() + " " + antrag->getAntragsteller()->getNachname();
		p_Tage = antrag->getTage();
		p_Anfang = antrag->getAnfang();
		p_Ende = antrag->getEnde();
	}
	
public:
	void setUrlaubsantrag(Urlaubsantrag^ antrag)
	{
		this->antrag = antrag;
	}

	property DateTime^ p_Ende
	{
		void set(DateTime^ p_Ende) {
			this->lbl_ende->Text = p_Ende->ToString("dd.mm.yyyy");
		}
	}

	property DateTime^ p_Anfang
	{
		void set(DateTime^ p_Anfang) {
			this->lbl_anfang->Text = p_Anfang->ToString("dd.mm.yyyy");
		}
	}

	property Int32 p_Tage
	{
		void set(Int32 p_Tage) {
			this->lbl_tage->Text = p_Tage.ToString();
		}
	}

	property String^ p_Name
	{
		void set(String^ p_Name) {
			this->lbl_NameMA->Text = p_Name;
		}
	}
};

}
