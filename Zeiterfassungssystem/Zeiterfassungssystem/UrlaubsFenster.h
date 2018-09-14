#pragma once
#include "Angestellter.h"

namespace Zeiterfassungssystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Zusammenfassung für UrlaubsFenster
	/// </summary>
	public ref class UrlaubsFenster : public System::Windows::Forms::Form
	{

	private:

		Int32 vergleichDaten;
		Int32 vergleichMitHeute;
		Angestellter^ angestellter;
		Int32 restUrlaub;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  kommentarTxt;

			 SoundPlayer^ sound;

	public:
		UrlaubsFenster(void)
		{
			sound = gcnew SoundPlayer();
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~UrlaubsFenster()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  tageTxt;
	private: System::Windows::Forms::DateTimePicker^  urlaubBeginnDTP;
	private: System::Windows::Forms::Label^  urlaubsabtragLbl;
	private: System::Windows::Forms::Button^  einreichenBtn;
	private: System::Windows::Forms::Label^  urlaubBeginnLbl;
	private: System::Windows::Forms::DateTimePicker^  urlaubEndeDTP;
	private: System::Windows::Forms::Button^  abbrechenBtn;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;


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
			this->einreichenBtn = (gcnew System::Windows::Forms::Button());
			this->urlaubBeginnLbl = (gcnew System::Windows::Forms::Label());
			this->urlaubEndeDTP = (gcnew System::Windows::Forms::DateTimePicker());
			this->abbrechenBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tageTxt = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->kommentarTxt = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// urlaubBeginnDTP
			// 
			this->urlaubBeginnDTP->Location = System::Drawing::Point(203, 108);
			this->urlaubBeginnDTP->Name = L"urlaubBeginnDTP";
			this->urlaubBeginnDTP->Size = System::Drawing::Size(200, 20);
			this->urlaubBeginnDTP->TabIndex = 0;
			// 
			// urlaubsabtragLbl
			// 
			this->urlaubsabtragLbl->AutoSize = true;
			this->urlaubsabtragLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->urlaubsabtragLbl->Location = System::Drawing::Point(99, 38);
			this->urlaubsabtragLbl->Name = L"urlaubsabtragLbl";
			this->urlaubsabtragLbl->Size = System::Drawing::Size(233, 37);
			this->urlaubsabtragLbl->TabIndex = 2;
			this->urlaubsabtragLbl->Text = L"Urlaubsantrag";
			// 
			// einreichenBtn
			// 
			this->einreichenBtn->Location = System::Drawing::Point(45, 332);
			this->einreichenBtn->Name = L"einreichenBtn";
			this->einreichenBtn->Size = System::Drawing::Size(122, 37);
			this->einreichenBtn->TabIndex = 4;
			this->einreichenBtn->Text = L"Einreichen";
			this->einreichenBtn->UseVisualStyleBackColor = true;
			this->einreichenBtn->Click += gcnew System::EventHandler(this, &UrlaubsFenster::Einreichen_Click);
			// 
			// urlaubBeginnLbl
			// 
			this->urlaubBeginnLbl->AutoSize = true;
			this->urlaubBeginnLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->urlaubBeginnLbl->Location = System::Drawing::Point(22, 108);
			this->urlaubBeginnLbl->Name = L"urlaubBeginnLbl";
			this->urlaubBeginnLbl->Size = System::Drawing::Size(134, 20);
			this->urlaubBeginnLbl->TabIndex = 5;
			this->urlaubBeginnLbl->Text = L"Erster Urlaubstag";
			// 
			// urlaubEndeDTP
			// 
			this->urlaubEndeDTP->Location = System::Drawing::Point(203, 154);
			this->urlaubEndeDTP->Name = L"urlaubEndeDTP";
			this->urlaubEndeDTP->Size = System::Drawing::Size(200, 20);
			this->urlaubEndeDTP->TabIndex = 1;
			// 
			// abbrechenBtn
			// 
			this->abbrechenBtn->Location = System::Drawing::Point(259, 332);
			this->abbrechenBtn->Name = L"abbrechenBtn";
			this->abbrechenBtn->Size = System::Drawing::Size(122, 37);
			this->abbrechenBtn->TabIndex = 5;
			this->abbrechenBtn->Text = L"Abbrechen";
			this->abbrechenBtn->UseVisualStyleBackColor = true;
			this->abbrechenBtn->Click += gcnew System::EventHandler(this, &UrlaubsFenster::abbrechenBtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(22, 154);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(141, 20);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Letzter Urlaubstag";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(22, 203);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(96, 20);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Urlaubstage";
			// 
			// tageTxt
			// 
			this->tageTxt->Location = System::Drawing::Point(203, 203);
			this->tageTxt->Margin = System::Windows::Forms::Padding(2);
			this->tageTxt->Name = L"tageTxt";
			this->tageTxt->Size = System::Drawing::Size(68, 20);
			this->tageTxt->TabIndex = 2;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(22, 246);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(91, 20);
			this->label4->TabIndex = 15;
			this->label4->Text = L"Kommentar";
			// 
			// kommentarTxt
			// 
			this->kommentarTxt->Location = System::Drawing::Point(26, 279);
			this->kommentarTxt->Margin = System::Windows::Forms::Padding(2);
			this->kommentarTxt->Name = L"kommentarTxt";
			this->kommentarTxt->Size = System::Drawing::Size(377, 20);
			this->kommentarTxt->TabIndex = 3;
			// 
			// UrlaubsFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(433, 381);
			this->Controls->Add(this->kommentarTxt);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->tageTxt);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->abbrechenBtn);
			this->Controls->Add(this->urlaubEndeDTP);
			this->Controls->Add(this->urlaubBeginnLbl);
			this->Controls->Add(this->einreichenBtn);
			this->Controls->Add(this->urlaubsabtragLbl);
			this->Controls->Add(this->urlaubBeginnDTP);
			this->Name = L"UrlaubsFenster";
			this->Text = L"Urlaubsantrag";
			this->Load += gcnew System::EventHandler(this, &UrlaubsFenster::UrlaubsFenster_Load);
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

		property Int32 p_Tage
		{
			Int32 get() {
				Int32 tageKonvertiert;
				if (tageTxt->Text->Length > 0) {
					tageKonvertiert = Convert::ToInt32(this->tageTxt->Text);
				}
				else {
					tageKonvertiert = 0;
				}
				return tageKonvertiert;
			}
		}

		property String^ p_Kommentar
		{
			String^ get() {
				return kommentarTxt->Text;
			}
		}

	//NEU: Angestellter wird gesetzt:
	public: void setAngestellter(Angestellter^ angestellterUebergabe)
	{
		angestellter = angestellterUebergabe;
	}

		//Eingaben werden zurückgesetzt
		void clear()
		{
			this->urlaubBeginnDTP->Value = DateTime::Today;
			this->urlaubEndeDTP->Value = DateTime::Today;
			this->tageTxt->Text = "";
			this->kommentarTxt->Text = "";
		}

	//Beim Klick auf "Einreichen" wird das Fenster geschlossen und OK gesendet, falls: Die Tage eingetragen wurden und die Zahl positiv ist,
	//der Beginn nicht nach dem Ende liegt und der Beginn nicht in der Vergangenheit liegt.
	private: System::Void Einreichen_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//Vergleich der Daten wird in Integern gespeichert
		vergleichDaten = DateTime::Compare(p_Anfang, p_Ende);
		vergleichMitHeute = DateTime::Compare(DateTime::Today.Date, p_Anfang);

		if (this->tageTxt->Text->Length == 0) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Bitte tragen Sie die Anzahl der Urlaubstage ein!", "Absenden nicht möglich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		if (!this->tageTxt->Text->Length == 0 && p_Tage <= 0) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Bitte tragen Sie eine gueltige Anzahl Urlaubstage ein!", "Absenden nicht möglich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (vergleichDaten > 0) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Ihr Urlaubsende darf nicht vor Ihrem Urlaubsbeginn liegen!\nBitte korrigieren Sie die Eingaben!", "Absenden nicht möglich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (vergleichMitHeute > 0) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Ihr Urlaubsbeginn darf nicht in der Vergangenheit liegen!\nBitte korrigieren Sie die Eingaben!", "Absenden nicht möglich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (p_Tage > restUrlaub) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Ihre gewuenschten Urlaubstage ueberschreiten Ihren Resturlaub!\nBitte korrigieren Sie die Eingaben!", "Absenden nicht möglich!",
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

	//Waehrend Fenster laed spiele Musik
	private: System::Void UrlaubsFenster_Load(System::Object^  sender, System::EventArgs^  e)
	{
		/*sound->SoundLocation = "Sounds/lacucarachaKurz.wav";
		sound->Load();
		sound->Play();*/
		restUrlaub = angestellter->getRestUrlaub();
	}
	};
}


