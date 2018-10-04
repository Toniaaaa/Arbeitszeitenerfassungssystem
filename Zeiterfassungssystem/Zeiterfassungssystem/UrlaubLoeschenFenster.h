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
	/// Zusammenfassung für UrlaubLoeschenFenster
	/// </summary>
	public ref class UrlaubLoeschenFenster : public System::Windows::Forms::Form
	{

	private:
		Int32 vergleichDaten;
		Int32 vergleichMitHeute;
		Angestellter^ angestellter;
		Unternehmen^ unternehmen;
		Boolean adminRechte;

	private: System::Windows::Forms::Button^  anzeigenBtn;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  kommentarTxt;
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
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
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
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->kommentarTxt = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// urlaubBeginnDTP
			// 
			this->urlaubBeginnDTP->Location = System::Drawing::Point(271, 186);
			this->urlaubBeginnDTP->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->urlaubBeginnDTP->Name = L"urlaubBeginnDTP";
			this->urlaubBeginnDTP->Size = System::Drawing::Size(265, 22);
			this->urlaubBeginnDTP->TabIndex = 1;
			// 
			// urlaubsabtragLbl
			// 
			this->urlaubsabtragLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->urlaubsabtragLbl->Location = System::Drawing::Point(1, 46);
			this->urlaubsabtragLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->urlaubsabtragLbl->Name = L"urlaubsabtragLbl";
			this->urlaubsabtragLbl->Size = System::Drawing::Size(577, 44);
			this->urlaubsabtragLbl->TabIndex = 2;
			this->urlaubsabtragLbl->Text = L"Urlaub löschen ";
			this->urlaubsabtragLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// loeschenBtn
			// 
			this->loeschenBtn->Location = System::Drawing::Point(33, 385);
			this->loeschenBtn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->loeschenBtn->Name = L"loeschenBtn";
			this->loeschenBtn->Size = System::Drawing::Size(156, 46);
			this->loeschenBtn->TabIndex = 4;
			this->loeschenBtn->Text = L"Tage löschen";
			this->loeschenBtn->UseVisualStyleBackColor = true;
			this->loeschenBtn->Click += gcnew System::EventHandler(this, &UrlaubLoeschenFenster::Loeschen_Click);
			// 
			// urlaubBeginnLbl
			// 
			this->urlaubBeginnLbl->AutoSize = true;
			this->urlaubBeginnLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->urlaubBeginnLbl->Location = System::Drawing::Point(29, 183);
			this->urlaubBeginnLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->urlaubBeginnLbl->Name = L"urlaubBeginnLbl";
			this->urlaubBeginnLbl->Size = System::Drawing::Size(179, 25);
			this->urlaubBeginnLbl->TabIndex = 5;
			this->urlaubBeginnLbl->Text = L"Erster Tag Zeiraum";
			// 
			// urlaubEndeDTP
			// 
			this->urlaubEndeDTP->Location = System::Drawing::Point(271, 241);
			this->urlaubEndeDTP->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->urlaubEndeDTP->Name = L"urlaubEndeDTP";
			this->urlaubEndeDTP->Size = System::Drawing::Size(265, 22);
			this->urlaubEndeDTP->TabIndex = 2;
			// 
			// abbrechenBtn
			// 
			this->abbrechenBtn->Location = System::Drawing::Point(380, 385);
			this->abbrechenBtn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->abbrechenBtn->Name = L"abbrechenBtn";
			this->abbrechenBtn->Size = System::Drawing::Size(156, 46);
			this->abbrechenBtn->TabIndex = 6;
			this->abbrechenBtn->Text = L"Abbrechen";
			this->abbrechenBtn->UseVisualStyleBackColor = true;
			this->abbrechenBtn->Click += gcnew System::EventHandler(this, &UrlaubLoeschenFenster::abbrechenBtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(31, 239);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(192, 25);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Letzter Tag Zeitraum";
			// 
			// anzeigenBtn
			// 
			this->anzeigenBtn->Location = System::Drawing::Point(205, 385);
			this->anzeigenBtn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->anzeigenBtn->Name = L"anzeigenBtn";
			this->anzeigenBtn->Size = System::Drawing::Size(156, 46);
			this->anzeigenBtn->TabIndex = 5;
			this->anzeigenBtn->Text = L"Urlaubstage anzeigen";
			this->anzeigenBtn->UseVisualStyleBackColor = true;
			this->anzeigenBtn->Click += gcnew System::EventHandler(this, &UrlaubLoeschenFenster::anzeigenBtn_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(29, 132);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(115, 25);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Angestellter";
			// 
			// angestellterCBox
			// 
			this->angestellterCBox->FormattingEnabled = true;
			this->angestellterCBox->Location = System::Drawing::Point(271, 132);
			this->angestellterCBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->angestellterCBox->Name = L"angestellterCBox";
			this->angestellterCBox->Size = System::Drawing::Size(267, 24);
			this->angestellterCBox->TabIndex = 0;
			this->angestellterCBox->SelectedIndexChanged += gcnew System::EventHandler(this, &UrlaubLoeschenFenster::angestellterCBox_SelectedIndexChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(29, 295);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(113, 25);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Kommentar";
			// 
			// kommentarTxt
			// 
			this->kommentarTxt->Location = System::Drawing::Point(35, 334);
			this->kommentarTxt->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->kommentarTxt->Name = L"kommentarTxt";
			this->kommentarTxt->Size = System::Drawing::Size(501, 22);
			this->kommentarTxt->TabIndex = 3;
			// 
			// UrlaubLoeschenFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(577, 442);
			this->Controls->Add(this->kommentarTxt);
			this->Controls->Add(this->label4);
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
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"UrlaubLoeschenFenster";
			this->Text = L"Urlaubsantrag";
			this->Load += gcnew System::EventHandler(this, &UrlaubLoeschenFenster::UrlaubLoeschenFenster_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public:

		//Properties für das Auslesen der eingegebenen Daten
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

		property String^ p_Kommentar
		{
			String^ get() {
				return kommentarTxt->Text;
			}
		}

		//Leere Anzeigen
		void clear()
		{
			this->urlaubBeginnDTP->Value == DateTime::Today.Date;
			this->urlaubEndeDTP->Value == DateTime::Today.Date;
			this->angestellterCBox->Items->Clear();
			this->kommentarTxt->Text = "";
		}

		//Unternehmen wird gesetzt
		void setUnternehmen(Unternehmen^ unternehmen)
		{
			this->unternehmen = unternehmen;
		}

	/*Beim Klick auf "Löschen" wird das Fenster geschlossen und OK gesendet, falls der Beginn nicht nach dem Ende liegt und der 
	Beginn nicht in der Vergangenheit liegt:*/
	private: System::Void Loeschen_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//Vergleich der Daten wird in Integern gespeichert
		vergleichDaten = DateTime::Compare(p_Anfang, p_Ende);
		vergleichMitHeute = DateTime::Compare(DateTime::Today.Date, p_Anfang);

		//Fall: Zeitraum-Ende liegt vor Zeitraum-Beginn
		if (vergleichDaten > 0) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Das Ende des Zeitraums muss nach dem Beginn liegen!\nBitte korrigieren Sie die Eingaben!", "Absenden nicht möglich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		//Fall: Beginn liegt in der Vergangenheit
		else if (vergleichMitHeute > 0) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Sie können keinen Urlaub in der Vergangenheit löschen!\nBitte korrigieren Sie die Eingaben!", "Absenden nicht möglich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		//Fall: Kein Angestellter ausgewählt
		else if (angestellter == nullptr) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Bitte wählen Sie einen Angestellten aus!", "Absenden nicht möglich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		//Fall: Ausgewählter Angestellter ist Vorgesetzter und User hat keine Administratorrechte
		else if (!adminRechte && angestellter->istVorgesetzter()) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Sie haben keine Administratorrechte!\nNur Administratoren dürfen den Urlaub von Vorgesetzten löschen!", "Absenden nicht möglich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		//Alles OK
		else {
			//OK senden und Fenster schließen2	11	1
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close(); //Fenster wird nur geschlossen, wenn alle Angaben gemacht wurden und OK sind.
		}
	}

	//Wenn abbrechen gedrueckt schliesse Fenster
	private: System::Void abbrechenBtn_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
	}

	//Wenn das Fenster geladen wird
	private: System::Void UrlaubLoeschenFenster_Load(System::Object^  sender, System::EventArgs^  e)
	{
		//Alle Angestellten des Unternehmens werden zur Combobox hinzugefügt
		for (int i = 0; i < unternehmen->getAlleAngestellte()->Count; i++) {
			angestellterCBox->Items->Add(unternehmen->getAlleAngestellte()[i]->getVorname() + " " + unternehmen->getAlleAngestellte()[i]->getNachname());
		}
	}

	//ANZEIGEN-BUTTON
	private: System::Void anzeigenBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		//Fall: Angestellter ausgewählt
		if (angestellter != nullptr) {
			//Alle Urlaubstage der ausgewählten Person OHNE Feiertage anzeigen
			String^ urlaubstageString = angestellter->freieTageAnzeigen(false);
			MessageBox::Show(urlaubstageString, "Ihre freien Tage", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		//Fall: KEIN Angestellter ausgewählt
		else {
			MessageBox::Show("Bitte wählen Sie einen Angestellten aus!", "Anzeigen nicht möglich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	//In der Combobox wurde ein Angestellter ausgewählt
	private: System::Void angestellterCBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		//Der Angestellte wird gesetzt als der in der Combobox ausgewählte
		angestellter = unternehmen->getAlleAngestellte()[angestellterCBox->SelectedIndex];
	}

	public: void setAdminRechte(Boolean istAdmin) {
		this->adminRechte = istAdmin;
	}
};
}

