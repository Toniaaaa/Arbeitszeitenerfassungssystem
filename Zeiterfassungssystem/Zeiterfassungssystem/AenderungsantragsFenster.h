#pragma once
#include "Angestellter.h"
#include "Mitarbeiter.h"
//#include "StundenStatistikFenster.h"
#include "Ereignis.h"
#include "AenderungsbearbeitungsFenster.h"
#include "Vorgesetzter.h"
#include <ctype.h>

namespace Zeiterfassungssystem {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	ref class StundenStatistikFenster;
	/// <summary>
	/// Zusammenfassung für AenderungsantragsFenster
	/// </summary>
	public ref class AenderungsantragsFenster : public System::Windows::Forms::Form
	{

	private:

	Angestellter ^ antragsteller;
	StundenStatistikFenster^ stundenstatistik;
	Int32 ereignisIndex;
	Ereignis^ ereignis;
	Ereignis^ ereignisende;
	Boolean ausgewaehlt;

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
	private: System::Windows::Forms::Label^  label2;
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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// aenderungsantragLbl
			// 
			this->aenderungsantragLbl->AutoSize = true;
			this->aenderungsantragLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->aenderungsantragLbl->Location = System::Drawing::Point(99, 39);
			this->aenderungsantragLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->aenderungsantragLbl->Name = L"aenderungsantragLbl";
			this->aenderungsantragLbl->Size = System::Drawing::Size(339, 46);
			this->aenderungsantragLbl->TabIndex = 2;
			this->aenderungsantragLbl->Text = L"Änderungsantrag";
			// 
			// einreichenBtn
			// 
			this->einreichenBtn->Location = System::Drawing::Point(81, 524);
			this->einreichenBtn->Margin = System::Windows::Forms::Padding(4);
			this->einreichenBtn->Name = L"einreichenBtn";
			this->einreichenBtn->Size = System::Drawing::Size(163, 46);
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
			this->tagLbl->Location = System::Drawing::Point(24, 118);
			this->tagLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->tagLbl->Name = L"tagLbl";
			this->tagLbl->Size = System::Drawing::Size(171, 25);
			this->tagLbl->TabIndex = 5;
			this->tagLbl->Text = L"Tag der Änderung";
			// 
			// abbrechenBtn
			// 
			this->abbrechenBtn->Location = System::Drawing::Point(309, 524);
			this->abbrechenBtn->Margin = System::Windows::Forms::Padding(4);
			this->abbrechenBtn->Name = L"abbrechenBtn";
			this->abbrechenBtn->Size = System::Drawing::Size(163, 46);
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
			this->ankunftLbl->Location = System::Drawing::Point(24, 177);
			this->ankunftLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ankunftLbl->Name = L"ankunftLbl";
			this->ankunftLbl->Size = System::Drawing::Size(116, 25);
			this->ankunftLbl->TabIndex = 11;
			this->ankunftLbl->Text = L"Ankunft Zeit";
			// 
			// kommentarLbl
			// 
			this->kommentarLbl->AutoSize = true;
			this->kommentarLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->kommentarLbl->Location = System::Drawing::Point(24, 325);
			this->kommentarLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->kommentarLbl->Name = L"kommentarLbl";
			this->kommentarLbl->Size = System::Drawing::Size(113, 25);
			this->kommentarLbl->TabIndex = 12;
			this->kommentarLbl->Text = L"Kommentar";
			// 
			// kommentarTxt
			// 
			this->kommentarTxt->Location = System::Drawing::Point(29, 353);
			this->kommentarTxt->Margin = System::Windows::Forms::Padding(4);
			this->kommentarTxt->Multiline = true;
			this->kommentarTxt->Name = L"kommentarTxt";
			this->kommentarTxt->Size = System::Drawing::Size(507, 143);
			this->kommentarTxt->TabIndex = 6;
			// 
			// gehenLbl
			// 
			this->gehenLbl->AutoSize = true;
			this->gehenLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gehenLbl->Location = System::Drawing::Point(24, 222);
			this->gehenLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->gehenLbl->Name = L"gehenLbl";
			this->gehenLbl->Size = System::Drawing::Size(108, 25);
			this->gehenLbl->TabIndex = 14;
			this->gehenLbl->Text = L"Gehen Zeit";
			// 
			// ankunftStdTxt
			// 
			this->ankunftStdTxt->Location = System::Drawing::Point(271, 176);
			this->ankunftStdTxt->Margin = System::Windows::Forms::Padding(4);
			this->ankunftStdTxt->Name = L"ankunftStdTxt";
			this->ankunftStdTxt->Size = System::Drawing::Size(52, 22);
			this->ankunftStdTxt->TabIndex = 1;
			// 
			// gehenStdTxt
			// 
			this->gehenStdTxt->Location = System::Drawing::Point(271, 222);
			this->gehenStdTxt->Margin = System::Windows::Forms::Padding(4);
			this->gehenStdTxt->Name = L"gehenStdTxt";
			this->gehenStdTxt->Size = System::Drawing::Size(52, 22);
			this->gehenStdTxt->TabIndex = 3;
			// 
			// ankunftMinuteTxt
			// 
			this->ankunftMinuteTxt->Location = System::Drawing::Point(353, 176);
			this->ankunftMinuteTxt->Margin = System::Windows::Forms::Padding(4);
			this->ankunftMinuteTxt->Name = L"ankunftMinuteTxt";
			this->ankunftMinuteTxt->Size = System::Drawing::Size(52, 22);
			this->ankunftMinuteTxt->TabIndex = 2;
			// 
			// gehenMinuteTxt
			// 
			this->gehenMinuteTxt->Location = System::Drawing::Point(353, 222);
			this->gehenMinuteTxt->Margin = System::Windows::Forms::Padding(4);
			this->gehenMinuteTxt->Name = L"gehenMinuteTxt";
			this->gehenMinuteTxt->Size = System::Drawing::Size(52, 22);
			this->gehenMinuteTxt->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(332, 180);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(12, 17);
			this->label1->TabIndex = 19;
			this->label1->Text = L":";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(332, 225);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(12, 17);
			this->label3->TabIndex = 20;
			this->label3->Text = L":";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(415, 177);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 25);
			this->label4->TabIndex = 21;
			this->label4->Text = L"Uhr";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(415, 222);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(43, 25);
			this->label5->TabIndex = 22;
			this->label5->Text = L"Uhr";
			// 
			// grundLbl
			// 
			this->grundLbl->AutoSize = true;
			this->grundLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grundLbl->Location = System::Drawing::Point(24, 263);
			this->grundLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->grundLbl->Name = L"grundLbl";
			this->grundLbl->Size = System::Drawing::Size(190, 25);
			this->grundLbl->TabIndex = 23;
			this->grundLbl->Text = L"Grund der Änderung";
			// 
			// gruendeAuswahl
			// 
			this->gruendeAuswahl->FormattingEnabled = true;
			this->gruendeAuswahl->Location = System::Drawing::Point(271, 266);
			this->gruendeAuswahl->Margin = System::Windows::Forms::Padding(4);
			this->gruendeAuswahl->Name = L"gruendeAuswahl";
			this->gruendeAuswahl->Size = System::Drawing::Size(265, 24);
			this->gruendeAuswahl->TabIndex = 5;
			this->gruendeAuswahl->SelectedIndexChanged += gcnew System::EventHandler(this, &AenderungsantragsFenster::gruendeAuswahl_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(306, 125);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 17);
			this->label2->TabIndex = 24;
			this->label2->Text = L"label2";
			// 
			// AenderungsantragsFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(580, 591);
			this->Controls->Add(this->label2);
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
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"AenderungsantragsFenster";
			this->Text = L"Aenderungsantrag";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &AenderungsantragsFenster::AenderungsantragsFenster_FormClosing);
			this->Load += gcnew System::EventHandler(this, &AenderungsantragsFenster::AenderungsantragsFenster_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		AenderungsbearbeitungsFenster ^ aenderungsbearbeitung;
	public:

		//Angestellter wird gesetzt:
		void setAntragssteller(Angestellter^ antragstellerUebergabe)
			{
				antragsteller = antragstellerUebergabe;
			}

		void setStatistikFenster(StundenStatistikFenster^ stundenstatistik) {
			this->stundenstatistik = stundenstatistik;
		}
		
		void setSelectedEreignis(Int32 ereignis) {
			this->ereignisIndex = ereignis;
		}
		
		void setAnederungsbearbeitungsFenster(AenderungsbearbeitungsFenster^ aenderungsbearbeitung) {
			this->aenderungsbearbeitung = aenderungsbearbeitung;
		}
		property DateTime p_Ankunft
		{
			DateTime get() {
				Int32 stunde = Convert::ToInt32(this->ankunftStdTxt->Text);
				Int32 minute = Convert::ToInt32(this->ankunftMinuteTxt->Text);
				DateTime ankunft = antragsteller->getEreignis(ereignisIndex)->getTimestamp()->Date;
				ankunft = ankunft.AddHours(stunde);
				ankunft = ankunft.AddMinutes(minute);
				return ankunft;
			}
		}

		property DateTime p_Gehen
		{
			DateTime get() {
				Int32 stunde = Convert::ToInt32(this->gehenStdTxt->Text);
				Int32 minute = Convert::ToInt32(this->gehenMinuteTxt->Text);
				DateTime gehen = antragsteller->getEreignis(ereignisIndex)->getTimestamp()->Date;
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
				if (ausgewaehlt) {
					return this->gruendeAuswahl->SelectedItem->ToString();
				}
			}
		}

		Angestellter^ getAntragsteller()
		{
			return antragsteller;
		}

		//Eingaben werden zurückgesetzt
		void clear()
		{
			//this->txt_Tag->Text = DateTime::Today;
			this->ankunftStdTxt->Text = "";
			this->ankunftMinuteTxt->Text = "";
			this->gehenStdTxt->Text = "";
			this->gehenMinuteTxt->Text = "";
			this->kommentarTxt->Text = "";
			this->gruendeAuswahl->Items->Clear();
		}
		
	//Beim Klick auf "Einreichen" wird das Fenster geschlossen und OK gesendet, falls: Die Tage eingetragen wurden und die Zahl positiv ist,
	//der Beginn nicht nach dem Ende liegt und der Beginn nicht in der Vergangenheit liegt.
	private: System::Void Einreichen_Click(System::Object^  sender, System::EventArgs^  e)
	{
	//Vergleich der Daten wird in einem Integer32 gespeichert
	//	int vergleichMitHeute = DateTime::Compare(p_Tag, DateTime::Today.Date);
		int parse = 0;

		if (this->ankunftStdTxt->Text->Length == 0 || this->ankunftMinuteTxt->Text->Length == 0 || this->gehenStdTxt->Text->Length == 0 || gehenMinuteTxt->Text->Length == 0 || (p_Grund == nullptr && p_Kommentar == nullptr)) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Bitte füllen Sie alle Felder aus!", "Absenden nicht möglich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (!Int32::TryParse(ankunftStdTxt->Text, parse)) {
			MessageBox::Show("Bitte geben Sie eine Zahl ein!", "Stunden angefangen",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (!Int32::TryParse(ankunftMinuteTxt->Text, parse)) {
			MessageBox::Show("Bitte geben Sie eine Zahl ein!", "Minuten angefangen",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (!Int32::TryParse(gehenStdTxt->Text, parse)) {
			MessageBox::Show("Bitte geben Sie eine Zahl ein!", "Stunden gegangen",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (!Int32::TryParse(gehenMinuteTxt->Text, parse)) {
			MessageBox::Show("Bitte geben Sie eine Zahl ein!", "Minuten gegangen",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (int::Parse(ankunftStdTxt->Text) < 0 || int::Parse(ankunftStdTxt->Text) > 23) {
			MessageBox::Show("Bitte geben Sie eine Zahl von 0 - 23 ein.", "Stunden angefangen",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (int::Parse(ankunftMinuteTxt->Text) < 0 || int::Parse(ankunftMinuteTxt->Text) > 59) {
			MessageBox::Show("Bitte geben Sie eine Zahl von 0 - 59 ein.", "Minuten angefangen",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (int::Parse(gehenStdTxt->Text) < 0 || int::Parse(gehenStdTxt->Text) > 23) {
			MessageBox::Show("Bitte geben Sie eine Zahl von 0 - 23 ein.", "Stunden gegangen",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (int::Parse(gehenMinuteTxt->Text) < 0 || int::Parse(gehenMinuteTxt->Text) > 59) {
			MessageBox::Show("Bitte geben Sie eine Zahl von 0 - 59 ein.", "Minuten gegangen",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (!ausgewaehlt) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Bitte waehlen Sie einen Grund für Ihren Antrag aus!", "Absenden nicht möglich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			
			//DateTime^ dateTag = p_Ankunft;
			DateTime datum = p_Ankunft.Date;
			Vorgesetzter^ vorgesetzter = antragsteller->getAbteilung()->getVorgesetzter();
			//Der Aenderungsantrag als String
			String^ aenderungString = "Sie wollen folgende Änderung beantragen:\n\nTag der Änderung: " + datum.ToString("dddd, dd. MMMM yyyy") + "\nNeuer Beginn: "
				+ p_Ankunft.ToString("HH:mm") + "\nNeues Ende: " + p_Gehen.ToString("HH:mm") + "\nGrund: " + p_Grund
				+ "\nKommentar: " + p_Kommentar + "\n\nWollen Sie diesen Antrag einreichen?";

			if (MessageBox::Show(aenderungString, "Antrag einreichen?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				//Neuen Änderungsantrag aus Werten aus dem Änderungsfenster erstellen
				Aenderungsantrag^ a = gcnew Aenderungsantrag(antragsteller, ereignisIndex, p_Ankunft, p_Gehen, *ereignis->getTimestamp(), *ereignisende->getTimestamp(), p_Grund,
					p_Kommentar);
					vorgesetzter->addAenderungsantrag(a);
				MessageBox::Show("Änderungsantrag erfolgreich eingereicht!", "Antrag erfolgreich!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else {
				MessageBox::Show("Ihr Änderungsantrag wurde nicht eingereicht!", "Antrag abgebrochen!",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

			this->clear(); //Textfelder wieder leeren
			this->Close(); //Fenster wird nur geschlossen, wenn alle Angaben gemacht wurden und OK sind.
		}
		
	}

	private: System::Void abbrechenBtn_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Close();
	}

	private: System::Void AenderungsantragsFenster_Load(System::Object^  sender, System::EventArgs^  e)
	{
		//Hier werden die Textboxen mit den ausgewählten Start Uhrzeiten befüllt 
		try {
			ausgewaehlt = false;
			ereignis = antragsteller->getEreignis(ereignisIndex);
			Int32 minute = ereignis->getTimestamp()->Minute;
			Int32 stunde = ereignis->getTimestamp()->Hour;
			DateTime datum = ereignis->getTimestamp()->Date;
			//das Datum wird ins Label geschrieben 
			label2->Text = datum.ToString("dddd, dd. MMMM yyyy");
			ankunftStdTxt->Text = Convert::ToString(stunde);
			ankunftMinuteTxt->Text = Convert::ToString(minute);
			//Laufe weiter bis zum passenden Arbeitsende und befülle End Textboxen passend, dann stopp
			for (int i = ereignisIndex; i < antragsteller->getAnzahlEreignisse(); i++) {
				if (antragsteller->getEreignis(i)->getTyp() == ARBEIT_ENDE) {
					ereignisende = antragsteller->getEreignis(i);
					Int32 minuteende = ereignisende->getTimestamp()->Minute;
					Int32 stundeende = ereignisende->getTimestamp()->Hour;
					gehenStdTxt->Text = Convert::ToString(stundeende);
					gehenMinuteTxt->Text = Convert::ToString(minuteende);
					break;
				}
			}
			//Fügt der ComboBox gruendeAuswahl verschieden Gründe hinzu, die für den Änderungsantrag hinzugefügt werden
			gruendeAuswahl->Items->Add("Krankheit");
			gruendeAuswahl->Items->Add("Fehler beim LogOut");
			gruendeAuswahl->Items->Add("Fehler beim LogIn");
			gruendeAuswahl->Items->Add("Computer-Absturz");
			gruendeAuswahl->Items->Add("Sonstiges (siehe Kommentar)");
			}
		catch (ArgumentOutOfRangeException ^e) {
			this->Close();
			this->clear();
			MessageBox::Show("Bitte wählen Sie einen Tag aus, den sie gerne ändern möchten!", "Kein Tag ausgewählt", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
			
	private: System::Void AenderungsantragsFenster_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		//Items werden bereinigt damit sie nicht immer wieder dahinter gehängt werden
		gruendeAuswahl->Items->Clear();
	}

	private: System::Void gruendeAuswahl_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		ausgewaehlt = true;
	}
};
}
