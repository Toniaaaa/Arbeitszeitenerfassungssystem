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
	using namespace System::Media;

	/// <summary>
	/// Zusammenfassung f�r UrlaubLoeschenFenster
	/// </summary>
	public ref class UrlaubLoeschenFenster : public System::Windows::Forms::Form
	{

	private:
		Int32 vergleichDaten;
		Int32 vergleichMitHeute;
		Angestellter^ angestellter;
		Unternehmen^ unternehmen;

	private: System::Windows::Forms::Button^  anzeigenBtn;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  angestellterCBox;


	public:
		UrlaubLoeschenFenster(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~UrlaubLoeschenFenster()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::DateTimePicker^  urlaubBeginnDTP;
	private: System::Windows::Forms::Label^  urlaubsabtragLbl;
	private: System::Windows::Forms::Button^  loeschenBtn;
	private: System::Windows::Forms::Label^  urlaubBeginnLbl;
	private: System::Windows::Forms::DateTimePicker^  urlaubEndeDTP;
	private: System::Windows::Forms::Button^  abbrechenBtn;
	private: System::Windows::Forms::Label^  label1;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode f�r die Designerunterst�tzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor ge�ndert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->urlaubBeginnDTP = (gcnew System::Windows::Forms::DateTimePicker());
			this->urlaubsabtragLbl = (gcnew System::Windows::Forms::Label());
			this->loeschenBtn = (gcnew System::Windows::Forms::Button());
			this->urlaubBeginnLbl = (gcnew System::Windows::Forms::Label());
			this->urlaubEndeDTP = (gcnew System::Windows::Forms::DateTimePicker());
			this->abbrechenBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->anzeigenBtn = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->angestellterCBox = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// urlaubBeginnDTP
			// 
			this->urlaubBeginnDTP->Location = System::Drawing::Point(304, 232);
			this->urlaubBeginnDTP->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->urlaubBeginnDTP->Name = L"urlaubBeginnDTP";
			this->urlaubBeginnDTP->Size = System::Drawing::Size(298, 26);
			this->urlaubBeginnDTP->TabIndex = 0;
			// 
			// urlaubsabtragLbl
			// 
			this->urlaubsabtragLbl->AutoSize = true;
			this->urlaubsabtragLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->urlaubsabtragLbl->Location = System::Drawing::Point(148, 58);
			this->urlaubsabtragLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->urlaubsabtragLbl->Name = L"urlaubsabtragLbl";
			this->urlaubsabtragLbl->Size = System::Drawing::Size(359, 55);
			this->urlaubsabtragLbl->TabIndex = 2;
			this->urlaubsabtragLbl->Text = L"Urlaub l�schen";
			// 
			// loeschenBtn
			// 
			this->loeschenBtn->Location = System::Drawing::Point(39, 385);
			this->loeschenBtn->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->loeschenBtn->Name = L"loeschenBtn";
			this->loeschenBtn->Size = System::Drawing::Size(175, 57);
			this->loeschenBtn->TabIndex = 4;
			this->loeschenBtn->Text = L"Tage l�schen";
			this->loeschenBtn->UseVisualStyleBackColor = true;
			this->loeschenBtn->Click += gcnew System::EventHandler(this, &UrlaubLoeschenFenster::Loeschen_Click);
			// 
			// urlaubBeginnLbl
			// 
			this->urlaubBeginnLbl->AutoSize = true;
			this->urlaubBeginnLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->urlaubBeginnLbl->Location = System::Drawing::Point(33, 229);
			this->urlaubBeginnLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->urlaubBeginnLbl->Name = L"urlaubBeginnLbl";
			this->urlaubBeginnLbl->Size = System::Drawing::Size(199, 29);
			this->urlaubBeginnLbl->TabIndex = 5;
			this->urlaubBeginnLbl->Text = L"Erster Urlaubstag";
			// 
			// urlaubEndeDTP
			// 
			this->urlaubEndeDTP->Location = System::Drawing::Point(304, 301);
			this->urlaubEndeDTP->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->urlaubEndeDTP->Name = L"urlaubEndeDTP";
			this->urlaubEndeDTP->Size = System::Drawing::Size(298, 26);
			this->urlaubEndeDTP->TabIndex = 1;
			// 
			// abbrechenBtn
			// 
			this->abbrechenBtn->Location = System::Drawing::Point(428, 385);
			this->abbrechenBtn->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->abbrechenBtn->Name = L"abbrechenBtn";
			this->abbrechenBtn->Size = System::Drawing::Size(175, 57);
			this->abbrechenBtn->TabIndex = 5;
			this->abbrechenBtn->Text = L"Abbrechen";
			this->abbrechenBtn->UseVisualStyleBackColor = true;
			this->abbrechenBtn->Click += gcnew System::EventHandler(this, &UrlaubLoeschenFenster::abbrechenBtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(34, 298);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(207, 29);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Letzter Urlaubstag";
			// 
			// anzeigenBtn
			// 
			this->anzeigenBtn->Location = System::Drawing::Point(232, 385);
			this->anzeigenBtn->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->anzeigenBtn->Name = L"anzeigenBtn";
			this->anzeigenBtn->Size = System::Drawing::Size(175, 57);
			this->anzeigenBtn->TabIndex = 17;
			this->anzeigenBtn->Text = L"Urlaubstage anzeigen";
			this->anzeigenBtn->UseVisualStyleBackColor = true;
			this->anzeigenBtn->Click += gcnew System::EventHandler(this, &UrlaubLoeschenFenster::anzeigenBtn_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(33, 164);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(141, 29);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Angestellter";
			// 
			// angestellterCBox
			// 
			this->angestellterCBox->FormattingEnabled = true;
			this->angestellterCBox->Location = System::Drawing::Point(304, 164);
			this->angestellterCBox->Name = L"angestellterCBox";
			this->angestellterCBox->Size = System::Drawing::Size(299, 28);
			this->angestellterCBox->TabIndex = 19;
			this->angestellterCBox->SelectedIndexChanged += gcnew System::EventHandler(this, &UrlaubLoeschenFenster::angestellterCBox_SelectedIndexChanged);
			// 
			// UrlaubLoeschenFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(650, 467);
			this->Controls->Add(this->angestellterCBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->anzeigenBtn);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->abbrechenBtn);
			this->Controls->Add(this->urlaubEndeDTP);
			this->Controls->Add(this->urlaubBeginnLbl);
			this->Controls->Add(this->loeschenBtn);
			this->Controls->Add(this->urlaubsabtragLbl);
			this->Controls->Add(this->urlaubBeginnDTP);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"UrlaubLoeschenFenster";
			this->Text = L"Urlaubsantrag";
			this->Load += gcnew System::EventHandler(this, &UrlaubLoeschenFenster::UrlaubLoeschenFenster_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public:

		//Properties f�r das Auslesen der eingegebenen Daten
		property DateTime p_Anfang
		{
			DateTime get() {
				return this->urlaubBeginnDTP->Value.Date;
			}
		}

		property DateTime p_Ende
		{
			DateTime get() {
				return this->urlaubEndeDTP->Value.Date;
			}
		}
		property Angestellter^ p_Angestellter
		{
			Angestellter^ get() {
				return unternehmen->getAlleAngestellte()[angestellterCBox->SelectedIndex];
			}
		}

		//Leere Anzeigen
		void clear()
		{
			this->urlaubBeginnDTP->Value == DateTime::Today.Date;
			this->urlaubEndeDTP->Value == DateTime::Today.Date;
		}

		//Unternehmen wird gesetzt
		void setUnternehmen(Unternehmen^ unternehmen)
		{
			this->unternehmen = unternehmen;
		}

	/*Beim Klick auf "L�schen" wird das Fenster geschlossen und OK gesendet, falls der Beginn nicht nach dem Ende liegt und der 
	Beginn nicht in der Vergangenheit liegt:*/
	private: System::Void Loeschen_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//Vergleich der Daten wird in Integern gespeichert
		vergleichDaten = DateTime::Compare(p_Anfang, p_Ende);
		vergleichMitHeute = DateTime::Compare(DateTime::Today.Date, p_Anfang);

		if (vergleichDaten > 0) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Das Urlaubsende muss nach dem Urlaubsbeginn liegen!\nBitte korrigieren Sie die Eingaben!", "Absenden nicht m�glich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (vergleichMitHeute > 0) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Der Urlaubsbeginn darf nicht in der Vergangenheit liegen!\nBitte korrigieren Sie die Eingaben!", "Absenden nicht m�glich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (angestellter = nullptr) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Bitte w�hlen Sie einen Angestellten aus!", "Absenden nicht m�glich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close(); //Fenster wird nur geschlossen, wenn alle Angaben gemacht wurden und OK sind.
		}
	}

	//Wenn abbrechen gedrueckt schliesse Fenster
	private: System::Void abbrechenBtn_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
	}

	private: System::Void UrlaubLoeschenFenster_Load(System::Object^  sender, System::EventArgs^  e)
	{
		for (int i = 0; i < unternehmen->getAlleAngestellte()->Count; i++) {
			angestellterCBox->Items->Add(unternehmen->getAlleAngestellte()[i]->getVorname() + " " + unternehmen->getAlleAngestellte()[i]->getNachname());
		}
	}

	private: System::Void anzeigenBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		if (angestellter != nullptr) {
			String^ urlaubstageString = "Urlaubstage:\n\n";
			for (int i = 0; i < angestellter->getListeUrlaubstage()->Count; i++) {
				if (angestellter->getListeUrlaubstage()[i]->getDatum().Year >= DateTime::Now.Year) {
					urlaubstageString += angestellter->getListeUrlaubstage()[i]->getDatum().ToString("dddd, dd. MMMM yyyy") + "\n";
				}
			}
			if (angestellter->getListeUrlaubstage()->Count == 0) {
				urlaubstageString += "Noch keine best�tigten Urlaubstage.\n";
			}
			MessageBox::Show(urlaubstageString, "Ihre freien Tage", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show("Bitte w�hlen Sie einen Angestellten aus!", "Anzeigen nicht m�glich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void angestellterCBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		angestellter = unternehmen->getAlleAngestellte()[angestellterCBox->SelectedIndex];
	}
};
}

