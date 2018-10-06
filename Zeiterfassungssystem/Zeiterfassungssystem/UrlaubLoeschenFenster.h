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
		Boolean adminRechte;
		String^ artAusgewaehlt;

	private: System::Windows::Forms::Button^  anzeigenBtn;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  kommentarTxt;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  artCBox;
	private: System::Windows::Forms::Button^  krankheitstageAnzeigenBtn;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UrlaubLoeschenFenster::typeid));
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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->artCBox = (gcnew System::Windows::Forms::ComboBox());
			this->krankheitstageAnzeigenBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// urlaubBeginnDTP
			// 
			this->urlaubBeginnDTP->Location = System::Drawing::Point(209, 184);
			this->urlaubBeginnDTP->Name = L"urlaubBeginnDTP";
			this->urlaubBeginnDTP->Size = System::Drawing::Size(200, 20);
			this->urlaubBeginnDTP->TabIndex = 2;
			// 
			// urlaubsabtragLbl
			// 
			this->urlaubsabtragLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->urlaubsabtragLbl->Location = System::Drawing::Point(1, 30);
			this->urlaubsabtragLbl->Name = L"urlaubsabtragLbl";
			this->urlaubsabtragLbl->Size = System::Drawing::Size(433, 36);
			this->urlaubsabtragLbl->TabIndex = 2;
			this->urlaubsabtragLbl->Text = L"Freie Tage l�schen ";
			this->urlaubsabtragLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// loeschenBtn
			// 
			this->loeschenBtn->Location = System::Drawing::Point(32, 346);
			this->loeschenBtn->Name = L"loeschenBtn";
			this->loeschenBtn->Size = System::Drawing::Size(85, 37);
			this->loeschenBtn->TabIndex = 5;
			this->loeschenBtn->Text = L"Tage l�schen";
			this->loeschenBtn->UseVisualStyleBackColor = true;
			this->loeschenBtn->Click += gcnew System::EventHandler(this, &UrlaubLoeschenFenster::Loeschen_Click);
			// 
			// urlaubBeginnLbl
			// 
			this->urlaubBeginnLbl->AutoSize = true;
			this->urlaubBeginnLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->urlaubBeginnLbl->Location = System::Drawing::Point(28, 182);
			this->urlaubBeginnLbl->Name = L"urlaubBeginnLbl";
			this->urlaubBeginnLbl->Size = System::Drawing::Size(145, 20);
			this->urlaubBeginnLbl->TabIndex = 5;
			this->urlaubBeginnLbl->Text = L"Erster Tag Zeiraum";
			// 
			// urlaubEndeDTP
			// 
			this->urlaubEndeDTP->Location = System::Drawing::Point(209, 229);
			this->urlaubEndeDTP->Name = L"urlaubEndeDTP";
			this->urlaubEndeDTP->Size = System::Drawing::Size(200, 20);
			this->urlaubEndeDTP->TabIndex = 3;
			// 
			// abbrechenBtn
			// 
			this->abbrechenBtn->Location = System::Drawing::Point(324, 346);
			this->abbrechenBtn->Name = L"abbrechenBtn";
			this->abbrechenBtn->Size = System::Drawing::Size(85, 37);
			this->abbrechenBtn->TabIndex = 8;
			this->abbrechenBtn->Text = L"Abbrechen";
			this->abbrechenBtn->UseVisualStyleBackColor = true;
			this->abbrechenBtn->Click += gcnew System::EventHandler(this, &UrlaubLoeschenFenster::abbrechenBtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(29, 227);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(157, 20);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Letzter Tag Zeitraum";
			// 
			// anzeigenBtn
			// 
			this->anzeigenBtn->Location = System::Drawing::Point(130, 346);
			this->anzeigenBtn->Name = L"anzeigenBtn";
			this->anzeigenBtn->Size = System::Drawing::Size(85, 37);
			this->anzeigenBtn->TabIndex = 6;
			this->anzeigenBtn->Text = L"Urlaubstage anzeigen";
			this->anzeigenBtn->UseVisualStyleBackColor = true;
			this->anzeigenBtn->Click += gcnew System::EventHandler(this, &UrlaubLoeschenFenster::anzeigenBtn_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(28, 140);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(94, 20);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Angestellter";
			// 
			// angestellterCBox
			// 
			this->angestellterCBox->FormattingEnabled = true;
			this->angestellterCBox->Location = System::Drawing::Point(209, 140);
			this->angestellterCBox->Margin = System::Windows::Forms::Padding(2);
			this->angestellterCBox->Name = L"angestellterCBox";
			this->angestellterCBox->Size = System::Drawing::Size(201, 21);
			this->angestellterCBox->TabIndex = 1;
			this->angestellterCBox->SelectedIndexChanged += gcnew System::EventHandler(this, &UrlaubLoeschenFenster::angestellterCBox_SelectedIndexChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(28, 273);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(91, 20);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Kommentar";
			// 
			// kommentarTxt
			// 
			this->kommentarTxt->Location = System::Drawing::Point(32, 304);
			this->kommentarTxt->Margin = System::Windows::Forms::Padding(2);
			this->kommentarTxt->Name = L"kommentarTxt";
			this->kommentarTxt->Size = System::Drawing::Size(377, 20);
			this->kommentarTxt->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(29, 102);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(99, 20);
			this->label3->TabIndex = 21;
			this->label3->Text = L"L�schen von";
			// 
			// artCBox
			// 
			this->artCBox->FormattingEnabled = true;
			this->artCBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Urlaub", L"Krankmeldung" });
			this->artCBox->Location = System::Drawing::Point(209, 101);
			this->artCBox->Margin = System::Windows::Forms::Padding(2);
			this->artCBox->Name = L"artCBox";
			this->artCBox->Size = System::Drawing::Size(201, 21);
			this->artCBox->TabIndex = 0;
			this->artCBox->SelectedIndexChanged += gcnew System::EventHandler(this, &UrlaubLoeschenFenster::artCBox_SelectedIndexChanged);
			// 
			// krankheitstageAnzeigenBtn
			// 
			this->krankheitstageAnzeigenBtn->Location = System::Drawing::Point(228, 346);
			this->krankheitstageAnzeigenBtn->Name = L"krankheitstageAnzeigenBtn";
			this->krankheitstageAnzeigenBtn->Size = System::Drawing::Size(85, 37);
			this->krankheitstageAnzeigenBtn->TabIndex = 7;
			this->krankheitstageAnzeigenBtn->Text = L"Tage krank anzeigen";
			this->krankheitstageAnzeigenBtn->UseVisualStyleBackColor = true;
			this->krankheitstageAnzeigenBtn->Click += gcnew System::EventHandler(this, &UrlaubLoeschenFenster::krankheitstageAnzeigenBtn_Click);
			// 
			// UrlaubLoeschenFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(433, 403);
			this->Controls->Add(this->anzeigenBtn);
			this->Controls->Add(this->krankheitstageAnzeigenBtn);
			this->Controls->Add(this->artCBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->kommentarTxt);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->angestellterCBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->abbrechenBtn);
			this->Controls->Add(this->urlaubEndeDTP);
			this->Controls->Add(this->urlaubBeginnLbl);
			this->Controls->Add(this->loeschenBtn);
			this->Controls->Add(this->urlaubsabtragLbl);
			this->Controls->Add(this->urlaubBeginnDTP);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"UrlaubLoeschenFenster";
			this->Text = L"Urlaub l�schen";
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

		property String^ p_Kommentar
		{
			String^ get() {
				return kommentarTxt->Text;
			}
		}

		property String^ p_Art
		{
			String^ get() {
				return artCBox->Text;
			}
		}

		//Leere Anzeigen
		void clear()
		{
			this->urlaubBeginnDTP->Value = DateTime::Today.Date;
			this->urlaubEndeDTP->Value = DateTime::Today.Date;
			this->angestellterCBox->SelectedIndex = -1;
			this->angestellterCBox->Items->Clear();
			this->kommentarTxt->Text = "";
			this->artCBox->SelectedIndex = -1;
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

		//Fall: Zeitraum-Ende liegt vor Zeitraum-Beginn
		if (vergleichDaten > 0) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Das Ende des Zeitraums muss nach dem Beginn liegen!\nBitte korrigieren Sie die Eingaben!", "Absenden nicht m�glich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		//Fall: Kein Angestellter ausgew�hlt
		else if (angestellter == nullptr) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Bitte w�hlen Sie einen Angestellten aus!", "Absenden nicht m�glich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		//Fall: Keine Art von freien Tagen ausgew�hlt
		else if (artAusgewaehlt == nullptr || (!artAusgewaehlt->Equals("Urlaub") && !artAusgewaehlt->Equals("Krankmeldung"))) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Bitte w�hlen Sie eine zul�ssige Art von freien Tagen, die gel�scht werden sollen, aus!", "Absenden nicht m�glich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		//Fall: Ausgew�hlter Angestellter ist Vorgesetzter und User hat keine Administratorrechte
		else if (!adminRechte && angestellter->istVorgesetzter()) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Sie haben keine Administratorrechte!\nNur Administratoren d�rfen den Urlaub von Vorgesetzten l�schen!", "Absenden nicht m�glich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		//Alles OK
		else {
			//OK senden und Fenster schlie�en
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

		//Alle Angestellten des Unternehmens werden zur Combobox hinzugef�gt
		for (int i = 0; i < unternehmen->getAlleAngestellte()->Count; i++) {
			angestellterCBox->Items->Add(unternehmen->getAlleAngestellte()[i]->getVorname() + " " + unternehmen->getAlleAngestellte()[i]->getNachname());
		}
		
	}

	//ANZEIGEN-BUTTON
	private: System::Void anzeigenBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		//Fall: Angestellter ausgew�hlt
		if (angestellter != nullptr) {
			//Alle Urlaubstage der ausgew�hlten Person OHNE Feiertage anzeigen
			String^ urlaubstageString = angestellter->freieTageAnzeigen(false);
			MessageBox::Show(urlaubstageString, "Ihre freien Tage", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		//Fall: KEIN Angestellter ausgew�hlt
		else {
			MessageBox::Show("Bitte w�hlen Sie einen Angestellten aus!", "Anzeigen nicht m�glich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	//In der Combobox wurde ein Angestellter ausgew�hlt
	private: System::Void angestellterCBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		//Der Angestellte wird gesetzt als der in der Combobox ausgew�hlte
		if (angestellterCBox->SelectedIndex != -1) {
			angestellter = unternehmen->getAlleAngestellte()[angestellterCBox->SelectedIndex];
		}
	}

	//Setter f�r Admin-Rechte
	public: void setAdminRechte(Boolean istAdmin) {
		this->adminRechte = istAdmin;
	}

	//In der Combobox wurde eine Art von freien Tagen ausgew�hlt
	private: System::Void artCBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		artAusgewaehlt = artCBox->Text;
	}

	private: System::Void krankheitstageAnzeigenBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		//Fall: Angestellter ausgew�hlt
		if (angestellter != nullptr) {
			//Alle Urlaubstage der ausgew�hlten Person OHNE Feiertage anzeigen
			String^ urlaubstageString = angestellter->krankheitstageAnzeigen();
			MessageBox::Show(urlaubstageString, "Ihre Krankheitstage", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		//Fall: KEIN Angestellter ausgew�hlt
		else {
			MessageBox::Show("Bitte w�hlen Sie einen Angestellten aus!", "Anzeigen nicht m�glich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
};
}

