#pragma once
#include "Urlaubsantrag.h"
#include "Unternehmen.h"

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
		Urlaubsantrag^ antrag;
		String^ textZumAntrag;
		Boolean istOffen;
		Unternehmen^ unternehmen;

	private: System::Windows::Forms::TextBox^  txt_Kommentar;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  lbl_kommentarText;
	private: System::Windows::Forms::Label^  lbl_Kommentar;

	public:
		UrlaubsanfragenbearbeitungsFenster(void)
		{
			InitializeComponent();
			istOffen = false;
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
	private: System::Windows::Forms::Button^  btn_AntragBestaetigen;
	private: System::Windows::Forms::Button^  btn_AntragAblehnen;
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
			this->btn_AntragBestaetigen = (gcnew System::Windows::Forms::Button());
			this->btn_AntragAblehnen = (gcnew System::Windows::Forms::Button());
			this->lbl_Aenderungsanfrage = (gcnew System::Windows::Forms::Label());
			this->lbl_NameMA = (gcnew System::Windows::Forms::Label());
			this->lbl_AnfrageErsterTag = (gcnew System::Windows::Forms::Label());
			this->lbl_AnfrageLetzterUrlaubstag = (gcnew System::Windows::Forms::Label());
			this->lbl_AnfrageAnzahlUrlaubstage = (gcnew System::Windows::Forms::Label());
			this->lbl_ende = (gcnew System::Windows::Forms::Label());
			this->lbl_tage = (gcnew System::Windows::Forms::Label());
			this->lbl_anfang = (gcnew System::Windows::Forms::Label());
			this->txt_Kommentar = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Kommentar = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lbl_kommentarText = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btn_AntragBestaetigen
			// 
			this->btn_AntragBestaetigen->Location = System::Drawing::Point(38, 329);
			this->btn_AntragBestaetigen->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->btn_AntragBestaetigen->Name = L"btn_AntragBestaetigen";
			this->btn_AntragBestaetigen->Size = System::Drawing::Size(109, 40);
			this->btn_AntragBestaetigen->TabIndex = 1;
			this->btn_AntragBestaetigen->Text = L"Bestätigen";
			this->btn_AntragBestaetigen->UseVisualStyleBackColor = true;
			this->btn_AntragBestaetigen->Click += gcnew System::EventHandler(this, &UrlaubsanfragenbearbeitungsFenster::btn_AntragBestaetigen_Click);
			// 
			// btn_AntragAblehnen
			// 
			this->btn_AntragAblehnen->Location = System::Drawing::Point(191, 329);
			this->btn_AntragAblehnen->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->btn_AntragAblehnen->Name = L"btn_AntragAblehnen";
			this->btn_AntragAblehnen->Size = System::Drawing::Size(115, 40);
			this->btn_AntragAblehnen->TabIndex = 2;
			this->btn_AntragAblehnen->Text = L"Ablehnen";
			this->btn_AntragAblehnen->UseVisualStyleBackColor = true;
			this->btn_AntragAblehnen->Click += gcnew System::EventHandler(this, &UrlaubsanfragenbearbeitungsFenster::btn_AntragAblehnen_Click);
			// 
			// lbl_Aenderungsanfrage
			// 
			this->lbl_Aenderungsanfrage->AutoSize = true;
			this->lbl_Aenderungsanfrage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Aenderungsanfrage->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->lbl_Aenderungsanfrage->Location = System::Drawing::Point(12, 26);
			this->lbl_Aenderungsanfrage->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Aenderungsanfrage->Name = L"lbl_Aenderungsanfrage";
			this->lbl_Aenderungsanfrage->Size = System::Drawing::Size(309, 29);
			this->lbl_Aenderungsanfrage->TabIndex = 2;
			this->lbl_Aenderungsanfrage->Text = L"Neue Urlaubsanfrage von";
			// 
			// lbl_NameMA
			// 
			this->lbl_NameMA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_NameMA->Location = System::Drawing::Point(-1, 66);
			this->lbl_NameMA->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_NameMA->Name = L"lbl_NameMA";
			this->lbl_NameMA->Size = System::Drawing::Size(332, 26);
			this->lbl_NameMA->TabIndex = 3;
			this->lbl_NameMA->Text = L"Beispiel MA";
			this->lbl_NameMA->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbl_AnfrageErsterTag
			// 
			this->lbl_AnfrageErsterTag->AutoSize = true;
			this->lbl_AnfrageErsterTag->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_AnfrageErsterTag->Location = System::Drawing::Point(11, 118);
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
			this->lbl_AnfrageLetzterUrlaubstag->Location = System::Drawing::Point(11, 144);
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
			this->lbl_AnfrageAnzahlUrlaubstage->Location = System::Drawing::Point(11, 170);
			this->lbl_AnfrageAnzahlUrlaubstage->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_AnfrageAnzahlUrlaubstage->Name = L"lbl_AnfrageAnzahlUrlaubstage";
			this->lbl_AnfrageAnzahlUrlaubstage->Size = System::Drawing::Size(136, 17);
			this->lbl_AnfrageAnzahlUrlaubstage->TabIndex = 6;
			this->lbl_AnfrageAnzahlUrlaubstage->Text = L"Anzahl Urlaubstage:";
			// 
			// lbl_ende
			// 
			this->lbl_ende->AutoSize = true;
			this->lbl_ende->Location = System::Drawing::Point(163, 148);
			this->lbl_ende->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_ende->Name = L"lbl_ende";
			this->lbl_ende->Size = System::Drawing::Size(61, 13);
			this->lbl_ende->TabIndex = 7;
			this->lbl_ende->Text = L"00.00.0000";
			// 
			// lbl_tage
			// 
			this->lbl_tage->AutoSize = true;
			this->lbl_tage->Location = System::Drawing::Point(163, 174);
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
			this->lbl_anfang->Location = System::Drawing::Point(163, 122);
			this->lbl_anfang->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_anfang->Name = L"lbl_anfang";
			this->lbl_anfang->Size = System::Drawing::Size(61, 13);
			this->lbl_anfang->TabIndex = 11;
			this->lbl_anfang->Text = L"00.00.0000";
			this->lbl_anfang->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// txt_Kommentar
			// 
			this->txt_Kommentar->Location = System::Drawing::Point(17, 292);
			this->txt_Kommentar->Name = L"txt_Kommentar";
			this->txt_Kommentar->Size = System::Drawing::Size(304, 20);
			this->txt_Kommentar->TabIndex = 0;
			// 
			// lbl_Kommentar
			// 
			this->lbl_Kommentar->AutoSize = true;
			this->lbl_Kommentar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Kommentar->Location = System::Drawing::Point(14, 271);
			this->lbl_Kommentar->Name = L"lbl_Kommentar";
			this->lbl_Kommentar->Size = System::Drawing::Size(165, 18);
			this->lbl_Kommentar->TabIndex = 13;
			this->lbl_Kommentar->Text = L"Kommentar hinzufügen:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(11, 196);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 17);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Kommentar:";
			// 
			// lbl_kommentarText
			// 
			this->lbl_kommentarText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_kommentarText->Location = System::Drawing::Point(99, 196);
			this->lbl_kommentarText->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_kommentarText->Name = L"lbl_kommentarText";
			this->lbl_kommentarText->Size = System::Drawing::Size(222, 66);
			this->lbl_kommentarText->TabIndex = 15;
			// 
			// UrlaubsanfragenbearbeitungsFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(331, 381);
			this->Controls->Add(this->lbl_kommentarText);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lbl_Kommentar);
			this->Controls->Add(this->txt_Kommentar);
			this->Controls->Add(this->lbl_anfang);
			this->Controls->Add(this->lbl_tage);
			this->Controls->Add(this->lbl_ende);
			this->Controls->Add(this->lbl_AnfrageAnzahlUrlaubstage);
			this->Controls->Add(this->lbl_AnfrageLetzterUrlaubstag);
			this->Controls->Add(this->lbl_AnfrageErsterTag);
			this->Controls->Add(this->lbl_NameMA);
			this->Controls->Add(this->lbl_Aenderungsanfrage);
			this->Controls->Add(this->btn_AntragAblehnen);
			this->Controls->Add(this->btn_AntragBestaetigen);
			this->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->Name = L"UrlaubsanfragenbearbeitungsFenster";
			this->Text = L"Neue Anfrage";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &UrlaubsanfragenbearbeitungsFenster::UrlaubsanfragenbearbeitungsFenster_FormClosed);
			this->Load += gcnew System::EventHandler(this, &UrlaubsanfragenbearbeitungsFenster::AenderungsbearbeitungsFenster_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void AenderungsbearbeitungsFenster_Load(System::Object^  sender, System::EventArgs^  e) {
		istOffen = true;
		p_Name = antrag->getAntragsteller()->getVorname() + " " + antrag->getAntragsteller()->getNachname();
		p_Tage = antrag->getTage();
		p_Anfang = antrag->getAnfang();
		p_Ende = antrag->getEnde();
		p_Kommentar = antrag->getKommentarAntragsteller();
	}
	
public:
	//Urlaubsantrag setzen
	void setUrlaubsantrag(Urlaubsantrag^ antrag)
	{
		this->antrag = antrag;
	}

	//Unternehmen setzen
	void setUnternehmen(Unternehmen^ unternehmen)
	{
		this->unternehmen = unternehmen;
	}

	//Properties um Werte für diese Seite zu setzen oder auszulesen
	property DateTime^ p_Ende
	{
		void set(DateTime^ p_Ende) {
			this->lbl_ende->Text = p_Ende->ToString("dddd, dd. MMMM yyyy");
		}
	}

	property DateTime^ p_Anfang
	{
		void set(DateTime^ p_Anfang) {
			this->lbl_anfang->Text = p_Anfang->ToString("dddd, dd. MMMM yyyy");
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

	property String^ p_Kommentar
	{
		void set(String^ p_Kommentar) {
			//Fall: Kein Kommentar eingegeben
			if (p_Kommentar->Length == 0) {
				this->lbl_kommentarText->Text = "-----";
			}
			else {
				this->lbl_kommentarText->Text = p_Kommentar;
			}
		}
		String^ get() {
			return txt_Kommentar->Text;
		}
	}

	Boolean getIstOffen() {
		return istOffen;
	}

	//Textfeld leeren
	void clear() 
	{
		this->txt_Kommentar->Text = "";
	}

	//BESTÄTIGEN-BUTTON
	private: System::Void btn_AntragBestaetigen_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		//Sicherheitsabfrage mit Zusammenfassung des Antrags, ob dieser wirklich bestätigt werden soll
		//Fall: Antwort mit Ja
		if (MessageBox::Show("Urlaubsantrag wirklich bestätigen?", "Antrag bestätigen?", MessageBoxButtons::YesNo,
			MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			//Neuer Antworttext wird erstellt
			antrag->setKommentarVorgesetzter(p_Kommentar);
			textZumAntrag = "Ihr Urlaubsantrag über " + antrag->getTage() + " Tage\nvom " + lbl_anfang->Text + "\nbis " + lbl_ende->Text + "\nwurde bestätigt.\nViel Spaß in Ihrem Urlaub.";
			if (p_Kommentar->Length > 0) {
				textZumAntrag += "\n\nKommentar:\n" + p_Kommentar;
			}
			//Info-Nachricht wird dem Antragsteller übermittelt
			antrag->getAntragsteller()->addAntragsInfo(textZumAntrag);
			//Urlaubstage werden dem Antragsteller eingetragen
			antrag->getAntragsteller()->nehmeUrlaub(antrag->getAnfang(), antrag->getEnde(), unternehmen->getFeiertage());
			//Es wird OK gesendet und die Seite geschlossen
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
	}

	//ABLEHNEN-BUTTON
	private: System::Void btn_AntragAblehnen_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		//Sicherheitsabfrage mit Zusammenfassung des Antrags, ob dieser wirklich bestätigt werden soll
		//Fall: Antwort mit Ja
		if (MessageBox::Show("Urlaubsantrag wirklich ablehnen?", "Antrag ablehnen?", MessageBoxButtons::YesNo,
			MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			//Neuer Antworttext wird erstellt
			antrag->setKommentarVorgesetzter(p_Kommentar);
			textZumAntrag = "Ihr Urlaubsantrag über " + antrag->getTage() + " Tage\nvom " + lbl_anfang->Text + "\nbis " + lbl_ende->Text + "\nwurde leider abgelehnt.";
			if (p_Kommentar->Length > 0) {
				textZumAntrag += "\n\nKommentar:\n" + p_Kommentar;
			}
			//Info-Nachricht wird dem Antragsteller übermittelt
			antrag->getAntragsteller()->addAntragsInfo(textZumAntrag);
			//Es wird OK gesendet und die Seite geschlossen
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
	}

	//Wenn das Fenster geschlossen wurde
	private: System::Void UrlaubsanfragenbearbeitungsFenster_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
	{
		//Wird auf False gesetzt.
		istOffen = false;
	}
};

}
