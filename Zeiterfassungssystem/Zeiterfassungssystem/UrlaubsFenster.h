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
	/// Zusammenfassung für UrlaubsFenster
	/// </summary>
	public ref class UrlaubsFenster : public System::Windows::Forms::Form
	{

	private:
		Angestellter^ angestellter;
		Int32 restUrlaub;
		Unternehmen^ unternehmen;
		Int32 anzahlUrlaubstage;
		SoundPlayer^ sound;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  kommentarTxt;
	private: System::Windows::Forms::Label^  urlaubstageLbl;
	private: System::Windows::Forms::Button^  anzeigenBtn;

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

	private: System::Windows::Forms::DateTimePicker^  urlaubBeginnDTP;
	private: System::Windows::Forms::Label^  urlaubsabtragLbl;
	private: System::Windows::Forms::Button^  einreichenBtn;
	private: System::Windows::Forms::Label^  urlaubBeginnLbl;
	private: System::Windows::Forms::DateTimePicker^  urlaubEndeDTP;
	private: System::Windows::Forms::Button^  abbrechenBtn;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  urlaubstageSchriftLbl;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UrlaubsFenster::typeid));
			this->urlaubBeginnDTP = (gcnew System::Windows::Forms::DateTimePicker());
			this->urlaubsabtragLbl = (gcnew System::Windows::Forms::Label());
			this->einreichenBtn = (gcnew System::Windows::Forms::Button());
			this->urlaubBeginnLbl = (gcnew System::Windows::Forms::Label());
			this->urlaubEndeDTP = (gcnew System::Windows::Forms::DateTimePicker());
			this->abbrechenBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->urlaubstageSchriftLbl = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->kommentarTxt = (gcnew System::Windows::Forms::TextBox());
			this->urlaubstageLbl = (gcnew System::Windows::Forms::Label());
			this->anzeigenBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// urlaubBeginnDTP
			// 
			this->urlaubBeginnDTP->Location = System::Drawing::Point(203, 108);
			this->urlaubBeginnDTP->Name = L"urlaubBeginnDTP";
			this->urlaubBeginnDTP->Size = System::Drawing::Size(200, 20);
			this->urlaubBeginnDTP->TabIndex = 0;
			this->urlaubBeginnDTP->ValueChanged += gcnew System::EventHandler(this, &UrlaubsFenster::urlaubBeginnDTP_ValueChanged);
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
			this->einreichenBtn->Location = System::Drawing::Point(26, 332);
			this->einreichenBtn->Name = L"einreichenBtn";
			this->einreichenBtn->Size = System::Drawing::Size(117, 37);
			this->einreichenBtn->TabIndex = 3;
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
			this->urlaubEndeDTP->ValueChanged += gcnew System::EventHandler(this, &UrlaubsFenster::urlaubEndeDTP_ValueChanged);
			// 
			// abbrechenBtn
			// 
			this->abbrechenBtn->Location = System::Drawing::Point(285, 332);
			this->abbrechenBtn->Name = L"abbrechenBtn";
			this->abbrechenBtn->Size = System::Drawing::Size(117, 37);
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
			// urlaubstageSchriftLbl
			// 
			this->urlaubstageSchriftLbl->AutoSize = true;
			this->urlaubstageSchriftLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->urlaubstageSchriftLbl->Location = System::Drawing::Point(22, 203);
			this->urlaubstageSchriftLbl->Name = L"urlaubstageSchriftLbl";
			this->urlaubstageSchriftLbl->Size = System::Drawing::Size(96, 20);
			this->urlaubstageSchriftLbl->TabIndex = 12;
			this->urlaubstageSchriftLbl->Text = L"Urlaubstage";
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
			this->kommentarTxt->TabIndex = 2;
			// 
			// urlaubstageLbl
			// 
			this->urlaubstageLbl->AutoSize = true;
			this->urlaubstageLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->urlaubstageLbl->Location = System::Drawing::Point(208, 203);
			this->urlaubstageLbl->Name = L"urlaubstageLbl";
			this->urlaubstageLbl->Size = System::Drawing::Size(58, 20);
			this->urlaubstageLbl->TabIndex = 16;
			this->urlaubstageLbl->Text = L"0 Tage";
			// 
			// anzeigenBtn
			// 
			this->anzeigenBtn->Location = System::Drawing::Point(157, 332);
			this->anzeigenBtn->Name = L"anzeigenBtn";
			this->anzeigenBtn->Size = System::Drawing::Size(117, 37);
			this->anzeigenBtn->TabIndex = 4;
			this->anzeigenBtn->Text = L"Urlaubstage anzeigen";
			this->anzeigenBtn->UseVisualStyleBackColor = true;
			this->anzeigenBtn->Click += gcnew System::EventHandler(this, &UrlaubsFenster::anzeigenBtn_Click);
			// 
			// UrlaubsFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(433, 381);
			this->Controls->Add(this->anzeigenBtn);
			this->Controls->Add(this->urlaubstageLbl);
			this->Controls->Add(this->kommentarTxt);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->urlaubstageSchriftLbl);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->abbrechenBtn);
			this->Controls->Add(this->urlaubEndeDTP);
			this->Controls->Add(this->urlaubBeginnLbl);
			this->Controls->Add(this->einreichenBtn);
			this->Controls->Add(this->urlaubsabtragLbl);
			this->Controls->Add(this->urlaubBeginnDTP);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
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
				return this->anzahlUrlaubstage;
			}

			void set(Int32 tage) {
				this->urlaubstageLbl->Text = Convert::ToString(tage);
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
		this->urlaubBeginnDTP->Value = DateTime::Today.Date;
		this->urlaubEndeDTP->Value = DateTime::Today.Date;
		this->kommentarTxt->Text = "";
	}

	//Angestellter wird gesetzt
	void setAngestellter(Angestellter^ angestellterUebergabe)
	{
		this->angestellter = angestellterUebergabe;
	}

	//Unternehmen wird gesetzt
	void setUnternehmen(Unternehmen^ unternehmen)
	{
		this->unternehmen = unternehmen;
	}

	//Beim Klick auf "Einreichen" wird das Fenster geschlossen und OK gesendet, falls:
	//Der Beginn nicht nach dem Ende liegt und der Beginn nicht in der Vergangenheit liegt.
	private: System::Void Einreichen_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//Vergleich der Daten wird in Integern gespeichert
		Int32 vergleichDaten = DateTime::Compare(p_Anfang, p_Ende);
		Int32 vergleichMitHeute = DateTime::Compare(DateTime::Today.Date, p_Anfang);

		//Anfang und Ende müssen in diesem Jahr liegen oder in einem der ersten drei Monate des nächsten Jahres
		if (!((p_Anfang.Year == DateTime::Now.Year) || ((p_Anfang.Year == (DateTime::Now.Year + 1)) && (p_Anfang.Month < 4)))) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Sie können leider nur Urlaub für Termine bis März des nächsten Jahres beantragen!\nBitte korrigieren Sie die Eingaben!", "Absenden nicht möglich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		//Fall: Urlaubsende liegt vor Urlaubsbeginn
		else if (vergleichDaten > 0) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Ihr Urlaubsende darf nicht vor Ihrem Urlaubsbeginn liegen!\nBitte korrigieren Sie die Eingaben!", "Absenden nicht möglich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		//Fall: Urlaubsbeginn liegt in der Vergangenheit
		else if (vergleichMitHeute > 0) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Ihr Urlaubsbeginn darf nicht in der Vergangenheit liegen!\nBitte korrigieren Sie die Eingaben!", "Absenden nicht möglich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		//Fall: Urlaub ist länger als der Resturlaub es zulässt
		else if (p_Tage > restUrlaub) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Ihre gewünschten Urlaubstage überschreiten Ihren Resturlaub!\nBitte korrigieren Sie die Eingaben!", "Absenden nicht möglich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		//Alles ist OK
		else {
			//OK senden und Fenster schließen
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close(); //Fenster wird nur geschlossen, wenn alle Angaben gemacht wurden und OK sind.
		}

	}

	//ABBRECHEN-BUTTON
	private: System::Void abbrechenBtn_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//Fenster wird geschlossen und Cancel gesendet
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
	}

	//Während Fenster lädt
	private: System::Void UrlaubsFenster_Load(System::Object^  sender, System::EventArgs^  e)
	{
		//Spielt Musik
		try {
			sound->SoundLocation = "Sounds/lacucarachaKurz.wav";
			sound->Load();
			sound->Play();
		}
		catch (System::IO::FileNotFoundException ^) {
			//Kein Sound, wenn die Datei nicht existiert
		}
		//Setze Werte für Anzeige und Berechnung
		restUrlaub = angestellter->getRestUrlaub();
		anzahlUrlaubstage = 1;
		urlaubstageLbl->Text = "1 Tag";
	}

	//Wenn die Auswahl in der Beginn-Combobox geändert wurde
	private: System::Void urlaubBeginnDTP_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		//Anzahl der Urlabstage im gewählten Intervall wird berechnet (ohne Wochenenden und Feiertage)
		anzahlUrlaubstage = angestellter->berechneUrlaubstage(p_Anfang, p_Ende);
		//Anzeige der Urlaubstage setzen
		if (anzahlUrlaubstage == 1) {
			this->urlaubstageLbl->Text = "1 Tag";
		}
		else {
			this->urlaubstageLbl->Text = Convert::ToString(anzahlUrlaubstage) + " Tage";
		}
	}

	//Wenn die Auswahl in der Ende-Combobox geändert wurde
	private: System::Void urlaubEndeDTP_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		//Anzahl der Urlabstage im gewählten Intervall wird berechnet (ohne Wochenenden und Feiertage)
		anzahlUrlaubstage = angestellter->berechneUrlaubstage(p_Anfang, p_Ende);
		//Anzeige der Urlaubstage setzen
		if (anzahlUrlaubstage == 1) {
			this->urlaubstageLbl->Text = "1 Tag";
		}
		else {
			this->urlaubstageLbl->Text = Convert::ToString(anzahlUrlaubstage) + " Tage";
		}
	}

	//ANZEIGEN-BUTTON
	private: System::Void anzeigenBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		//Urlaubs- und Feiertage für diesen Nutzer werden angezeigt
		String^ urlaubstageString = angestellter->freieTageAnzeigen(true);
		MessageBox::Show(urlaubstageString, "Ihre freien Tage", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

};
}


