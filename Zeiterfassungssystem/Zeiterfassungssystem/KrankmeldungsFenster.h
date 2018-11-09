#pragma once
#include "Angestellter.h"

namespace Zeiterfassungssystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für KrankmeldungsFenster
	/// </summary>
	public ref class KrankmeldungsFenster : public System::Windows::Forms::Form
	{

	private:
		Angestellter^ angestellter;
		Int32 anzahlKrankheitstage;

	private: System::Windows::Forms::Label^  kommentarLbl;
	private: System::Windows::Forms::TextBox^  kommentarTxt;
	private: System::Windows::Forms::Button^  anzeigenBtn;
	private: System::Windows::Forms::Label^  krankheitstageLbl;

	public:
		KrankmeldungsFenster(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~KrankmeldungsFenster()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DateTimePicker^  krankheitBeginnDTP;
	private: System::Windows::Forms::Label^  krankmeldungLbl;
	private: System::Windows::Forms::Button^  einreichenBtn;
	private: System::Windows::Forms::Label^  ersterTagLbl;
	private: System::Windows::Forms::DateTimePicker^  krankheitEndeDTP;
	private: System::Windows::Forms::Button^  abbrechenBtn;
	private: System::Windows::Forms::Label^  letzterTagLbl;
	private: System::Windows::Forms::Label^  krankheitstageSchriftLbl;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(KrankmeldungsFenster::typeid));
			this->krankheitBeginnDTP = (gcnew System::Windows::Forms::DateTimePicker());
			this->krankmeldungLbl = (gcnew System::Windows::Forms::Label());
			this->einreichenBtn = (gcnew System::Windows::Forms::Button());
			this->ersterTagLbl = (gcnew System::Windows::Forms::Label());
			this->krankheitEndeDTP = (gcnew System::Windows::Forms::DateTimePicker());
			this->abbrechenBtn = (gcnew System::Windows::Forms::Button());
			this->letzterTagLbl = (gcnew System::Windows::Forms::Label());
			this->krankheitstageSchriftLbl = (gcnew System::Windows::Forms::Label());
			this->kommentarLbl = (gcnew System::Windows::Forms::Label());
			this->kommentarTxt = (gcnew System::Windows::Forms::TextBox());
			this->krankheitstageLbl = (gcnew System::Windows::Forms::Label());
			this->anzeigenBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// krankheitBeginnDTP
			// 
			this->krankheitBeginnDTP->Location = System::Drawing::Point(203, 108);
			this->krankheitBeginnDTP->Name = L"krankheitBeginnDTP";
			this->krankheitBeginnDTP->Size = System::Drawing::Size(200, 20);
			this->krankheitBeginnDTP->TabIndex = 0;
			this->krankheitBeginnDTP->ValueChanged += gcnew System::EventHandler(this, &KrankmeldungsFenster::krankheitsBeginnDTP_ValueChanged);
			// 
			// krankmeldungLbl
			// 
			this->krankmeldungLbl->AutoSize = true;
			this->krankmeldungLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->krankmeldungLbl->Location = System::Drawing::Point(97, 36);
			this->krankmeldungLbl->Name = L"krankmeldungLbl";
			this->krankmeldungLbl->Size = System::Drawing::Size(236, 37);
			this->krankmeldungLbl->TabIndex = 2;
			this->krankmeldungLbl->Text = L"Krankmeldung";
			// 
			// einreichenBtn
			// 
			this->einreichenBtn->Location = System::Drawing::Point(26, 332);
			this->einreichenBtn->Name = L"einreichenBtn";
			this->einreichenBtn->Size = System::Drawing::Size(115, 37);
			this->einreichenBtn->TabIndex = 3;
			this->einreichenBtn->Text = L"Einreichen";
			this->einreichenBtn->UseVisualStyleBackColor = true;
			this->einreichenBtn->Click += gcnew System::EventHandler(this, &KrankmeldungsFenster::Einreichen_Click);
			// 
			// ersterTagLbl
			// 
			this->ersterTagLbl->AutoSize = true;
			this->ersterTagLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ersterTagLbl->Location = System::Drawing::Point(22, 108);
			this->ersterTagLbl->Name = L"ersterTagLbl";
			this->ersterTagLbl->Size = System::Drawing::Size(154, 20);
			this->ersterTagLbl->TabIndex = 5;
			this->ersterTagLbl->Text = L"Erster Krankheitstag";
			// 
			// krankheitEndeDTP
			// 
			this->krankheitEndeDTP->Location = System::Drawing::Point(203, 154);
			this->krankheitEndeDTP->Name = L"krankheitEndeDTP";
			this->krankheitEndeDTP->Size = System::Drawing::Size(200, 20);
			this->krankheitEndeDTP->TabIndex = 1;
			this->krankheitEndeDTP->ValueChanged += gcnew System::EventHandler(this, &KrankmeldungsFenster::krankheitsEndeDTP_ValueChanged);
			// 
			// abbrechenBtn
			// 
			this->abbrechenBtn->Location = System::Drawing::Point(288, 332);
			this->abbrechenBtn->Name = L"abbrechenBtn";
			this->abbrechenBtn->Size = System::Drawing::Size(115, 37);
			this->abbrechenBtn->TabIndex = 4;
			this->abbrechenBtn->Text = L"Abbrechen";
			this->abbrechenBtn->UseVisualStyleBackColor = true;
			this->abbrechenBtn->Click += gcnew System::EventHandler(this, &KrankmeldungsFenster::abbrechenBtn_Click);
			// 
			// letzterTagLbl
			// 
			this->letzterTagLbl->AutoSize = true;
			this->letzterTagLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->letzterTagLbl->Location = System::Drawing::Point(22, 154);
			this->letzterTagLbl->Name = L"letzterTagLbl";
			this->letzterTagLbl->Size = System::Drawing::Size(161, 20);
			this->letzterTagLbl->TabIndex = 11;
			this->letzterTagLbl->Text = L"Letzter Krankheitstag";
			// 
			// krankheitstageSchriftLbl
			// 
			this->krankheitstageSchriftLbl->AutoSize = true;
			this->krankheitstageSchriftLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->krankheitstageSchriftLbl->Location = System::Drawing::Point(22, 203);
			this->krankheitstageSchriftLbl->Name = L"krankheitstageSchriftLbl";
			this->krankheitstageSchriftLbl->Size = System::Drawing::Size(116, 20);
			this->krankheitstageSchriftLbl->TabIndex = 12;
			this->krankheitstageSchriftLbl->Text = L"Krankheitstage";
			// 
			// kommentarLbl
			// 
			this->kommentarLbl->AutoSize = true;
			this->kommentarLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->kommentarLbl->Location = System::Drawing::Point(22, 246);
			this->kommentarLbl->Name = L"kommentarLbl";
			this->kommentarLbl->Size = System::Drawing::Size(91, 20);
			this->kommentarLbl->TabIndex = 15;
			this->kommentarLbl->Text = L"Kommentar";
			// 
			// kommentarTxt
			// 
			this->kommentarTxt->Location = System::Drawing::Point(26, 279);
			this->kommentarTxt->Margin = System::Windows::Forms::Padding(2);
			this->kommentarTxt->Name = L"kommentarTxt";
			this->kommentarTxt->Size = System::Drawing::Size(377, 20);
			this->kommentarTxt->TabIndex = 2;
			// 
			// krankheitstageLbl
			// 
			this->krankheitstageLbl->AutoSize = true;
			this->krankheitstageLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->krankheitstageLbl->Location = System::Drawing::Point(208, 203);
			this->krankheitstageLbl->Name = L"krankheitstageLbl";
			this->krankheitstageLbl->Size = System::Drawing::Size(58, 20);
			this->krankheitstageLbl->TabIndex = 16;
			this->krankheitstageLbl->Text = L"0 Tage";
			// 
			// anzeigenBtn
			// 
			this->anzeigenBtn->Location = System::Drawing::Point(156, 332);
			this->anzeigenBtn->Name = L"anzeigenBtn";
			this->anzeigenBtn->Size = System::Drawing::Size(115, 37);
			this->anzeigenBtn->TabIndex = 17;
			this->anzeigenBtn->Text = L"Krankmeldungen anzeigen";
			this->anzeigenBtn->UseVisualStyleBackColor = true;
			this->anzeigenBtn->Click += gcnew System::EventHandler(this, &KrankmeldungsFenster::anzeigenBtn_Click);
			// 
			// KrankmeldungsFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(433, 381);
			this->Controls->Add(this->anzeigenBtn);
			this->Controls->Add(this->krankheitstageLbl);
			this->Controls->Add(this->kommentarTxt);
			this->Controls->Add(this->kommentarLbl);
			this->Controls->Add(this->krankheitstageSchriftLbl);
			this->Controls->Add(this->letzterTagLbl);
			this->Controls->Add(this->abbrechenBtn);
			this->Controls->Add(this->krankheitEndeDTP);
			this->Controls->Add(this->ersterTagLbl);
			this->Controls->Add(this->einreichenBtn);
			this->Controls->Add(this->krankmeldungLbl);
			this->Controls->Add(this->krankheitBeginnDTP);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"KrankmeldungsFenster";
			this->Text = L"Krankmeldung";
			this->Load += gcnew System::EventHandler(this, &KrankmeldungsFenster::KrankmeldungsFenster_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public:

		//Properties für das Auslesen der eingegebenen Daten
		property DateTime p_Anfang
		{
			DateTime get() {
				return this->krankheitBeginnDTP->Value.Date;
			}
		}

		property DateTime p_Ende
		{
			DateTime get() {
				return this->krankheitEndeDTP->Value.Date;
			}
		}

		property Int32 p_Tage
		{
			Int32 get() {
				return this->anzahlKrankheitstage;
			}

			void set(Int32 tage) {
				this->krankheitstageLbl->Text = Convert::ToString(tage);
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
			this->krankheitBeginnDTP->Value = DateTime::Now.Date;
			this->krankheitEndeDTP->Value = DateTime::Now.Date;
			this->kommentarTxt->Text = "";
		}

		//Angestellter wird gesetzt
		void setAngestellter(Angestellter^ angestellterUebergabe)
		{
			this->angestellter = angestellterUebergabe;
		}

	//Beim Klick auf "Einreichen" wird das Fenster geschlossen und OK gesendet, falls:
	//Der Beginn nicht nach dem Ende liegt und der Beginn nicht in der Vergangenheit liegt.
	private: System::Void Einreichen_Click(System::Object^  sender, System::EventArgs^  e)
	{

		//Fall: Ende liegt vor Beginn
		if (DateTime::Compare(p_Anfang, p_Ende) > 0) {
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Ihr Krankheitsende darf nicht vor Ihrem Krankheitsbeginn liegen!\nBitte korrigieren Sie die Eingaben!", "Absenden nicht möglich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		//Alles ist OK
		else {
			//OK senden und Fenster schließen
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}

	}

	//ABBRECHEN-BUTTON
	private: System::Void abbrechenBtn_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//Fenster wird geschlossen und Cancel gesendet
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
	}

	//Während Fenster lädt
	private: System::Void KrankmeldungsFenster_Load(System::Object^  sender, System::EventArgs^  e)
	{
		anzahlKrankheitstage = 1;
		krankheitstageLbl->Text = "1 Tag";
	}

	//Wenn die Auswahl in der Beginn-Combobox geändert wurde
	private: System::Void krankheitsBeginnDTP_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		//Anzahl der Krankheitstage im gewählten Intervall wird berechnet (ohne Wochenenden und Feiertage)
		anzahlKrankheitstage = angestellter->berechneArbeitstage(p_Anfang, p_Ende);
		//Anzeige der Krankheitstage setzen
		if (anzahlKrankheitstage == 1) {
			this->krankheitstageLbl->Text = "1 Tag";
		}
		else {
			this->krankheitstageLbl->Text = Convert::ToString(anzahlKrankheitstage) + " Tage";
		}
	}

	//Wenn die Auswahl in der Ende-Combobox geändert wurde
	private: System::Void krankheitsEndeDTP_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		//Anzahl der Urlabstage im gewählten Intervall wird berechnet (ohne Wochenenden und Feiertage)
		anzahlKrankheitstage = angestellter->berechneArbeitstage(p_Anfang, p_Ende);
		//Anzeige der Krankheitstage setzen
		if (anzahlKrankheitstage == 1) {
			this->krankheitstageLbl->Text = "1 Tag";
		}
		else {
			this->krankheitstageLbl->Text = Convert::ToString(anzahlKrankheitstage) + " Tage";
		}
	}

	//Klick auf den Anzeigen-Button
	private: System::Void anzeigenBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		//Alle Krankheitstage der Person anzeigen
		String^ urlaubstageString = angestellter->krankheitstageAnzeigen();
		MessageBox::Show(urlaubstageString, "Ihre Krankheitstage", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
};
}

