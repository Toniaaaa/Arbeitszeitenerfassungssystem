#pragma once
#include "Unternehmen.h"

namespace Zeiterfassungssystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für FeiertagsFenster
	/// </summary>
	public ref class FeiertagsFenster : public System::Windows::Forms::Form
	{

	private:
		Unternehmen^ unternehmen;

	public:
		FeiertagsFenster(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~FeiertagsFenster()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DateTimePicker^  neuerFeiertagDTP;
	private: System::Windows::Forms::Label^  aenderungsantragLbl;
	private: System::Windows::Forms::Button^  hinzufuegenBtn;
	private: System::Windows::Forms::Button^  abbrechenBtn;
	private: System::Windows::Forms::Button^  entfernenBtn;
	private: System::Windows::Forms::Button^  anzeigenBtn;

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
			this->neuerFeiertagDTP = (gcnew System::Windows::Forms::DateTimePicker());
			this->aenderungsantragLbl = (gcnew System::Windows::Forms::Label());
			this->hinzufuegenBtn = (gcnew System::Windows::Forms::Button());
			this->abbrechenBtn = (gcnew System::Windows::Forms::Button());
			this->entfernenBtn = (gcnew System::Windows::Forms::Button());
			this->anzeigenBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// neuerFeiertagDTP
			// 
			this->neuerFeiertagDTP->Location = System::Drawing::Point(51, 116);
			this->neuerFeiertagDTP->Name = L"neuerFeiertagDTP";
			this->neuerFeiertagDTP->Size = System::Drawing::Size(191, 20);
			this->neuerFeiertagDTP->TabIndex = 0;
			// 
			// aenderungsantragLbl
			// 
			this->aenderungsantragLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->aenderungsantragLbl->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->aenderungsantragLbl->Location = System::Drawing::Point(44, 9);
			this->aenderungsantragLbl->Name = L"aenderungsantragLbl";
			this->aenderungsantragLbl->Size = System::Drawing::Size(198, 80);
			this->aenderungsantragLbl->TabIndex = 3;
			this->aenderungsantragLbl->Text = L"Feierttag";
			this->aenderungsantragLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// hinzufuegenBtn
			// 
			this->hinzufuegenBtn->Location = System::Drawing::Point(12, 160);
			this->hinzufuegenBtn->Name = L"hinzufuegenBtn";
			this->hinzufuegenBtn->Size = System::Drawing::Size(122, 37);
			this->hinzufuegenBtn->TabIndex = 1;
			this->hinzufuegenBtn->Text = L"Hinzufügen";
			this->hinzufuegenBtn->UseVisualStyleBackColor = true;
			this->hinzufuegenBtn->Click += gcnew System::EventHandler(this, &FeiertagsFenster::hinzufuegenBtn_Click);
			// 
			// abbrechenBtn
			// 
			this->abbrechenBtn->Location = System::Drawing::Point(150, 212);
			this->abbrechenBtn->Name = L"abbrechenBtn";
			this->abbrechenBtn->Size = System::Drawing::Size(122, 37);
			this->abbrechenBtn->TabIndex = 4;
			this->abbrechenBtn->Text = L"Abbrechen";
			this->abbrechenBtn->UseVisualStyleBackColor = true;
			this->abbrechenBtn->Click += gcnew System::EventHandler(this, &FeiertagsFenster::abbrechenBtn_Click);
			// 
			// entfernenBtn
			// 
			this->entfernenBtn->Location = System::Drawing::Point(150, 160);
			this->entfernenBtn->Name = L"entfernenBtn";
			this->entfernenBtn->Size = System::Drawing::Size(122, 37);
			this->entfernenBtn->TabIndex = 2;
			this->entfernenBtn->Text = L"Entfernen";
			this->entfernenBtn->UseVisualStyleBackColor = true;
			this->entfernenBtn->Click += gcnew System::EventHandler(this, &FeiertagsFenster::entfernenBtn_Click);
			// 
			// anzeigenBtn
			// 
			this->anzeigenBtn->Location = System::Drawing::Point(12, 212);
			this->anzeigenBtn->Name = L"anzeigenBtn";
			this->anzeigenBtn->Size = System::Drawing::Size(122, 37);
			this->anzeigenBtn->TabIndex = 3;
			this->anzeigenBtn->Text = L"Feiertage anzeigen";
			this->anzeigenBtn->UseVisualStyleBackColor = true;
			this->anzeigenBtn->Click += gcnew System::EventHandler(this, &FeiertagsFenster::anzeigenBtn_Click);
			// 
			// FeiertagsFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->anzeigenBtn);
			this->Controls->Add(this->entfernenBtn);
			this->Controls->Add(this->abbrechenBtn);
			this->Controls->Add(this->hinzufuegenBtn);
			this->Controls->Add(this->aenderungsantragLbl);
			this->Controls->Add(this->neuerFeiertagDTP);
			this->Name = L"FeiertagsFenster";
			this->Text = L"Feiertag hinzufügen";
			this->ResumeLayout(false);

		}
#pragma endregion

	//ABBRECHEN-BUTTON
	private: System::Void abbrechenBtn_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		//Fenster wird geschlossen und CANCEL gesendet
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
	}

	//Setze Unternehmen
	public: void setUnternehmen(Unternehmen^ unternehmen)
	{
		this->unternehmen = unternehmen;
	}

	//Anzeige zurücksetzen
	public: void clear() 
	{
		this->neuerFeiertagDTP->Value = DateTime::Today;
	}

	//HINZUFÜGEN-BUTTON
	private: System::Void hinzufuegenBtn_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//Fall: Ausgewählter Tag liegt NICHT in der Zukunft
		if (this->neuerFeiertagDTP->Value.Date <= DateTime::Today) {
			//Feiertag kann nicht hinzugefügt werden
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Bitte wählen Sie ein Datum in der Zukunft!", "Hinzufügen nicht möglich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		//Fall: Ausgewählter Tag liegt in der Zukunft
		else {
			//Sicherheitsabfrage mit nochmaliger Anzeige des Feiertages
			String^ hinzuText = "Sind Sie sicher, dass Sie folgendes Datum als neuen Feiertag hinzufügen möchten?\n\n" + neuerFeiertagDTP->Value.ToString("dddd, dd. MMMM yyyy");
			//Fall: Antort Ja
			if (MessageBox::Show(hinzuText, "Wirklich hinzufuegen?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				//Falls der Feiertag schon eingetragen ist, wird der Tag NICHT noch einmal hinzugefügt
				if (unternehmen->istFeiertag(neuerFeiertagDTP->Value.Date)) {
					MessageBox::Show("Dieser Feiertag existiert bereits!", "Hinzufügen nicht möglich", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				//Feiertag wird hinzugefügt, falls er noch nicht im Unternehmen existiert
				else {
					unternehmen->addFeiertag(neuerFeiertagDTP->Value.Date);
					this->DialogResult = System::Windows::Forms::DialogResult::OK;
				}
			}
		}
	}

	//ENTFERNEN-BUTTON
	private: System::Void entfernenBtn_Click(System::Object^  sender, System::EventArgs^  e) {

		//Fall: Ausgewählter Tag liegt NICHT in der Zukunft
		if (this->neuerFeiertagDTP->Value.Date <= DateTime::Today) {
			//Feiertag kann nicht entfernt werden
			this->DialogResult = System::Windows::Forms::DialogResult::None;
			MessageBox::Show("Bitte wählen Sie ein Datum in der Zukunft!", "Entfernen nicht möglich!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			//Sicherheitsabfrage mit nochmaliger Anzeige des Feiertages
			String^ hinzuText = "Sind Sie sicher, dass Sie folgendes Datum als Feiertag entfernen möchten?\n\n" + neuerFeiertagDTP->Value.ToString("dddd, dd. MMMM yyyy");
			//Fall: Antwort ist Ja
			if (MessageBox::Show(hinzuText, "Wirklich entfernen?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				//Wenn der Feiertag, der entfernt werden soll, exisitiert, wird er entfernt
				if (unternehmen->istFeiertag(neuerFeiertagDTP->Value.Date)) {
					unternehmen->removeFeiertag(neuerFeiertagDTP->Value.Date);
					this->DialogResult = System::Windows::Forms::DialogResult::OK;
				}
				//Wenn der Feiertag, der entfernt werden soll, nicht exisitert, wird ein Fehler gemeldet
				else {
					MessageBox::Show("Dieser Feiertag existiert nicht!", "Entfernen nicht möglich", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}
	}

	//ANZEIGEN Button
	private: System::Void anzeigenBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		//Alle Feiertage des Unternehmens, die in der Liste sind und in diesem Jahr oder einem zukünftigen Jahr liegen, werden aufgelistet
		String^ feiertageString = unternehmen->feiertageAnzeigen();
		MessageBox::Show(feiertageString, "Ihre Feiertage", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
};
}
