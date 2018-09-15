#pragma once
#include "Angestellter.h"
#include "Mitarbeiter.h"

namespace Zeiterfassungssystem {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für AenderungsantragsFenster
	/// </summary>
	public ref class AenderungsantragsFenster : public System::Windows::Forms::Form
	{

	private:

		Angestellter ^ antragsteller;

	private: System::Windows::Forms::TextBox^  kommentarTxt;
	private: System::Windows::Forms::Label^  gehenLbl;
	private: System::Windows::Forms::TextBox^  ankunftStdTxt;
	private: System::Windows::Forms::TextBox^  gehenStdTxt;
	private: System::Windows::Forms::TextBox^  ankunftMinuteTxt;
	private: System::Windows::Forms::TextBox^  gehenMinuteTxt;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  grundLbl;
	private: System::Windows::Forms::ComboBox^  gruendeAuswahl;



	public:
		AenderungsantragsFenster(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~AenderungsantragsFenster()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DateTimePicker^  tagDTP;
	private: System::Windows::Forms::Label^  aenderungsantragLbl;
	private: System::Windows::Forms::Button^  einreichenBtn;
	private: System::Windows::Forms::Label^  tagLbl;
	private: System::Windows::Forms::Button^  abbrechenBtn;
	private: System::Windows::Forms::Label^  ankunftLbl;
	private: System::Windows::Forms::Label^  kommentarLbl;

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
			this->tagDTP = (gcnew System::Windows::Forms::DateTimePicker());
			this->aenderungsantragLbl = (gcnew System::Windows::Forms::Label());
			this->einreichenBtn = (gcnew System::Windows::Forms::Button());
			this->tagLbl = (gcnew System::Windows::Forms::Label());
			this->abbrechenBtn = (gcnew System::Windows::Forms::Button());
			this->ankunftLbl = (gcnew System::Windows::Forms::Label());
			this->kommentarLbl = (gcnew System::Windows::Forms::Label());
			this->kommentarTxt = (gcnew System::Windows::Forms::TextBox());
			this->gehenLbl = (gcnew System::Windows::Forms::Label());
			this->ankunftStdTxt = (gcnew System::Windows::Forms::TextBox());
			this->gehenStdTxt = (gcnew System::Windows::Forms::TextBox());
			this->ankunftMinuteTxt = (gcnew System::Windows::Forms::TextBox());
			this->gehenMinuteTxt = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->grundLbl = (gcnew System::Windows::Forms::Label());
			this->gruendeAuswahl = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// tagDTP
			// 
			this->tagDTP->Location = System::Drawing::Point(203, 96);
			this->tagDTP->Name = L"tagDTP";
			this->tagDTP->Size = System::Drawing::Size(200, 20);
			this->tagDTP->TabIndex = 0;
			// 
			// aenderungsantragLbl
			// 
			this->aenderungsantragLbl->AutoSize = true;
			this->aenderungsantragLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->aenderungsantragLbl->Location = System::Drawing::Point(74, 32);
			this->aenderungsantragLbl->Name = L"aenderungsantragLbl";
			this->aenderungsantragLbl->Size = System::Drawing::Size(280, 37);
			this->aenderungsantragLbl->TabIndex = 2;
			this->aenderungsantragLbl->Text = L"Änderungsantrag";
			// 
			// einreichenBtn
			// 
			this->einreichenBtn->Location = System::Drawing::Point(61, 426);
			this->einreichenBtn->Name = L"einreichenBtn";
			this->einreichenBtn->Size = System::Drawing::Size(122, 37);
			this->einreichenBtn->TabIndex = 7;
			this->einreichenBtn->Text = L"Einreichen";
			this->einreichenBtn->UseVisualStyleBackColor = true;
			this->einreichenBtn->Click += gcnew System::EventHandler(this, &AenderungsantragsFenster::Einreichen_Click);
			// 
			// tagLbl
			// 
			this->tagLbl->AutoSize = true;
			this->tagLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tagLbl->Location = System::Drawing::Point(18, 96);
			this->tagLbl->Name = L"tagLbl";
			this->tagLbl->Size = System::Drawing::Size(137, 20);
			this->tagLbl->TabIndex = 5;
			this->tagLbl->Text = L"Tag der Änderung";
			// 
			// abbrechenBtn
			// 
			this->abbrechenBtn->Location = System::Drawing::Point(232, 426);
			this->abbrechenBtn->Name = L"abbrechenBtn";
			this->abbrechenBtn->Size = System::Drawing::Size(122, 37);
			this->abbrechenBtn->TabIndex = 8;
			this->abbrechenBtn->Text = L"Abbrechen";
			this->abbrechenBtn->UseVisualStyleBackColor = true;
			this->abbrechenBtn->Click += gcnew System::EventHandler(this, &AenderungsantragsFenster::abbrechenBtn_Click);
			// 
			// ankunftLbl
			// 
			this->ankunftLbl->AutoSize = true;
			this->ankunftLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ankunftLbl->Location = System::Drawing::Point(18, 144);
			this->ankunftLbl->Name = L"ankunftLbl";
			this->ankunftLbl->Size = System::Drawing::Size(96, 20);
			this->ankunftLbl->TabIndex = 11;
			this->ankunftLbl->Text = L"Ankunft Zeit";
			// 
			// kommentarLbl
			// 
			this->kommentarLbl->AutoSize = true;
			this->kommentarLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->kommentarLbl->Location = System::Drawing::Point(18, 264);
			this->kommentarLbl->Name = L"kommentarLbl";
			this->kommentarLbl->Size = System::Drawing::Size(91, 20);
			this->kommentarLbl->TabIndex = 12;
			this->kommentarLbl->Text = L"Kommentar";
			// 
			// kommentarTxt
			// 
			this->kommentarTxt->Location = System::Drawing::Point(22, 287);
			this->kommentarTxt->Multiline = true;
			this->kommentarTxt->Name = L"kommentarTxt";
			this->kommentarTxt->Size = System::Drawing::Size(381, 117);
			this->kommentarTxt->TabIndex = 6;
			// 
			// gehenLbl
			// 
			this->gehenLbl->AutoSize = true;
			this->gehenLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gehenLbl->Location = System::Drawing::Point(18, 180);
			this->gehenLbl->Name = L"gehenLbl";
			this->gehenLbl->Size = System::Drawing::Size(89, 20);
			this->gehenLbl->TabIndex = 14;
			this->gehenLbl->Text = L"Gehen Zeit";
			// 
			// ankunftStdTxt
			// 
			this->ankunftStdTxt->Location = System::Drawing::Point(203, 143);
			this->ankunftStdTxt->Name = L"ankunftStdTxt";
			this->ankunftStdTxt->Size = System::Drawing::Size(40, 20);
			this->ankunftStdTxt->TabIndex = 1;
			// 
			// gehenStdTxt
			// 
			this->gehenStdTxt->Location = System::Drawing::Point(203, 180);
			this->gehenStdTxt->Name = L"gehenStdTxt";
			this->gehenStdTxt->Size = System::Drawing::Size(40, 20);
			this->gehenStdTxt->TabIndex = 3;
			// 
			// ankunftMinuteTxt
			// 
			this->ankunftMinuteTxt->Location = System::Drawing::Point(265, 143);
			this->ankunftMinuteTxt->Name = L"ankunftMinuteTxt";
			this->ankunftMinuteTxt->Size = System::Drawing::Size(40, 20);
			this->ankunftMinuteTxt->TabIndex = 2;
			// 
			// gehenMinuteTxt
			// 
			this->gehenMinuteTxt->Location = System::Drawing::Point(265, 180);
			this->gehenMinuteTxt->Name = L"gehenMinuteTxt";
			this->gehenMinuteTxt->Size = System::Drawing::Size(40, 20);
			this->gehenMinuteTxt->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(249, 146);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(10, 13);
			this->label1->TabIndex = 19;
			this->label1->Text = L":";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(249, 183);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(10, 13);
			this->label3->TabIndex = 20;
			this->label3->Text = L":";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(311, 144);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 20);
			this->label4->TabIndex = 21;
			this->label4->Text = L"Uhr";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(311, 180);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 20);
			this->label5->TabIndex = 22;
			this->label5->Text = L"Uhr";
			// 
			// grundLbl
			// 
			this->grundLbl->AutoSize = true;
			this->grundLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grundLbl->Location = System::Drawing::Point(18, 214);
			this->grundLbl->Name = L"grundLbl";
			this->grundLbl->Size = System::Drawing::Size(155, 20);
			this->grundLbl->TabIndex = 23;
			this->grundLbl->Text = L"Grund der Änderung";
			// 
			// gruendeAuswahl
			// 
			this->gruendeAuswahl->FormattingEnabled = true;
			this->gruendeAuswahl->Location = System::Drawing::Point(203, 216);
			this->gruendeAuswahl->Name = L"gruendeAuswahl";
			this->gruendeAuswahl->Size = System::Drawing::Size(200, 21);
			this->gruendeAuswahl->TabIndex = 5;
			// 
			// AenderungsantragsFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(435, 480);
			this->Controls->Add(this->gruendeAuswahl);
			this->Controls->Add(this->grundLbl);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->gehenMinuteTxt);
			this->Controls->Add(this->ankunftMinuteTxt);
			this->Controls->Add(this->gehenStdTxt);
			this->Controls->Add(this->ankunftStdTxt);
			this->Controls->Add(this->gehenLbl);
			this->Controls->Add(this->kommentarTxt);
			this->Controls->Add(this->kommentarLbl);
			this->Controls->Add(this->ankunftLbl);
			this->Controls->Add(this->abbrechenBtn);
			this->Controls->Add(this->tagLbl);
			this->Controls->Add(this->einreichenBtn);
			this->Controls->Add(this->aenderungsantragLbl);
			this->Controls->Add(this->tagDTP);
			this->Name = L"AenderungsantragsFenster";
			this->Text = L"Aenderungsantrag";
			this->Load += gcnew System::EventHandler(this, &AenderungsantragsFenster::AenderungsantragsFenster_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public:

		//Properties für das Auslesen der eingegebenen Daten
		property DateTime p_Tag
		{
			DateTime get() {
				return this->tagDTP->Value.Date;
			}
		}

		property DateTime p_Ankunft
		{
			DateTime get() {
				Double stunde = Convert::ToDouble(this->ankunftStdTxt->Text);
				Double minute = Convert::ToDouble(this->ankunftMinuteTxt->Text);
				DateTime ankunft = p_Tag;
				ankunft = ankunft.AddHours(stunde);
				ankunft = ankunft.AddMinutes(minute);
				return ankunft;
			}
		}

		property DateTime p_Gehen
		{
			DateTime get() {
				Double stunde = Convert::ToDouble(this->gehenStdTxt->Text);
				Double minute = Convert::ToDouble(this->gehenMinuteTxt->Text);
				DateTime gehen = p_Tag;
				gehen = gehen.AddHours(stunde);
				gehen = gehen.AddMinutes(minute);
				return gehen;
			}
		}

		property String^ p_AntragstellerName
		{
			String^ get() {
				return antragsteller->getVorname() + " " + antragsteller->getNachname();
			}
		}

		property String^ p_Kommentar
		{
			String^ get() {
				return this->kommentarTxt->Text;
			}
		}

		property String^ p_Grund
		{
			String^ get() {
				return this->gruendeAuswahl->SelectedItem->ToString();
			}
		}

		Angestellter^ getAntragsteller()
		{
			return antragsteller;
		}

		//Eingaben werden zurückgesetzt
		void clear()
		{
			this->tagDTP->Value = DateTime::Today;
			this->ankunftStdTxt->Text = "";
			this->ankunftMinuteTxt->Text = "";
			this->gehenStdTxt->Text = "";
			this->gehenMinuteTxt->Text = "";
			this->kommentarTxt->Text = "";
			this->gruendeAuswahl->ResetCursor();
		}

		//Beim Klick auf "Einreichen" wird das Fenster geschlossen und OK gesendet, falls: Die Tage eingetragen wurden und die Zahl positiv ist,
		//der Beginn nicht nach dem Ende liegt und der Beginn nicht in der Vergangenheit liegt.
	private: System::Void Einreichen_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//Vergleich der Daten wird in einem Integer32 gespeichert
		int vergleichMitHeute = DateTime::Compare(p_Tag, DateTime::Today.Date);

		if (this->ankunftStdTxt->Text->Length == 0) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Bitte füllen Sie alle Felder aus!", "Absenden nicht möglich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (this->ankunftMinuteTxt->Text->Length == 0) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Bitte füllen Sie alle Felder aus!", "Absenden nicht möglich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (this->gehenStdTxt->Text->Length == 0) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Bitte füllen Sie alle Felder aus!", "Absenden nicht möglich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (this->gehenMinuteTxt->Text->Length == 0) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Bitte füllen Sie alle Felder aus!", "Absenden nicht möglich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (vergleichMitHeute >= 0) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Sie können eine Änderung nur für einen in der Vergangenheit liegenden Tag beantragen!", "Absenden nicht möglich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close(); //Fenster wird nur geschlossen, wenn alle Angaben gemacht wurden und OK sind.
		}
	}

	private: System::Void abbrechenBtn_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
	}

	private: System::Void AenderungsantragsFenster_Load(System::Object^  sender, System::EventArgs^  e)
	{
		//Fügt der ComboBox gruendeAuswahl verschieden Gründe hinzu, die für den Änderungsantrag hinzugefügt werden
		gruendeAuswahl->Items->Add("Krankheit");
		gruendeAuswahl->Items->Add("Fehler beim LogOut");
		gruendeAuswahl->Items->Add("Fehler beim LogIn");
		gruendeAuswahl->Items->Add("Computer-Absturz");
		gruendeAuswahl->Items->Add("Sonstiges (siehe Kommentar)");
	}

	//Angestellter wird gesetzt:
	public: void setAntragssteller(Angestellter^ antragstellerUebergabe)
	{
		antragsteller = antragstellerUebergabe;
	}
	};
}
