#pragma once
#include "Aenderungsantrag.h"
#include "Angestellter.h"
#include "Ereignis.h"
#include "Kalender.h"
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
	public ref class AenderungsbearbeitungsFenster : public System::Windows::Forms::Form
	{
	private:
		Aenderungsantrag^ antrag;
		String^ textZumAntrag;
		Boolean istOffen;

	private: System::Windows::Forms::TextBox^  kommentarVorgesetzterTxt;
	private: System::Windows::Forms::Label^  kommentarLbl;
	private: System::Windows::Forms::Label^  kommentarAntragstellerLbl;
	private: System::Windows::Forms::Label^  grundLbl;
	private: System::Windows::Forms::Label^  grundLblTxt;


	private: System::Windows::Forms::Label^  gehenAltLbl;
	private: System::Windows::Forms::Label^  ankunftAltLbl;
	private: System::Windows::Forms::Label^  ankunftAltLblTxt;
	private: System::Windows::Forms::Label^  gehenAltLblTxt;

	private: System::Windows::Forms::Label^  kommentarLbl2;

	public:
		AenderungsbearbeitungsFenster(void)
		{
			InitializeComponent();
			istOffen = false;
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~AenderungsbearbeitungsFenster()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  AntragBestaetigenBtn;
	private: System::Windows::Forms::Button^  AntragAblehnenBtn;
	private: System::Windows::Forms::Label^  lbl_Aenderungsanfrage;
	private: System::Windows::Forms::Label^  NameMALbl;
	private: System::Windows::Forms::Label^  tagLbl;
	private: System::Windows::Forms::Label^  ankunftLbl;
	private: System::Windows::Forms::Label^  gehenLbl;
	private: System::Windows::Forms::Label^  ankunftLblTxt;
	private: System::Windows::Forms::Label^  gehenLblTxt;
	private: System::Windows::Forms::Label^  tagLblTxt;


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
			this->AntragBestaetigenBtn = (gcnew System::Windows::Forms::Button());
			this->AntragAblehnenBtn = (gcnew System::Windows::Forms::Button());
			this->lbl_Aenderungsanfrage = (gcnew System::Windows::Forms::Label());
			this->NameMALbl = (gcnew System::Windows::Forms::Label());
			this->tagLbl = (gcnew System::Windows::Forms::Label());
			this->ankunftLbl = (gcnew System::Windows::Forms::Label());
			this->gehenLbl = (gcnew System::Windows::Forms::Label());
			this->ankunftLblTxt = (gcnew System::Windows::Forms::Label());
			this->gehenLblTxt = (gcnew System::Windows::Forms::Label());
			this->tagLblTxt = (gcnew System::Windows::Forms::Label());
			this->kommentarVorgesetzterTxt = (gcnew System::Windows::Forms::TextBox());
			this->kommentarLbl2 = (gcnew System::Windows::Forms::Label());
			this->kommentarLbl = (gcnew System::Windows::Forms::Label());
			this->kommentarAntragstellerLbl = (gcnew System::Windows::Forms::Label());
			this->grundLbl = (gcnew System::Windows::Forms::Label());
			this->grundLblTxt = (gcnew System::Windows::Forms::Label());
			this->gehenAltLbl = (gcnew System::Windows::Forms::Label());
			this->ankunftAltLbl = (gcnew System::Windows::Forms::Label());
			this->ankunftAltLblTxt = (gcnew System::Windows::Forms::Label());
			this->gehenAltLblTxt = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// AntragBestaetigenBtn
			// 
			this->AntragBestaetigenBtn->Location = System::Drawing::Point(43, 592);
			this->AntragBestaetigenBtn->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->AntragBestaetigenBtn->Name = L"AntragBestaetigenBtn";
			this->AntragBestaetigenBtn->Size = System::Drawing::Size(164, 62);
			this->AntragBestaetigenBtn->TabIndex = 0;
			this->AntragBestaetigenBtn->Text = L"Bestätigen";
			this->AntragBestaetigenBtn->UseVisualStyleBackColor = true;
			this->AntragBestaetigenBtn->Click += gcnew System::EventHandler(this, &AenderungsbearbeitungsFenster::btn_AntragBestaetigen_Click);
			// 
			// AntragAblehnenBtn
			// 
			this->AntragAblehnenBtn->Location = System::Drawing::Point(330, 592);
			this->AntragAblehnenBtn->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->AntragAblehnenBtn->Name = L"AntragAblehnenBtn";
			this->AntragAblehnenBtn->Size = System::Drawing::Size(172, 62);
			this->AntragAblehnenBtn->TabIndex = 1;
			this->AntragAblehnenBtn->Text = L"Ablehnen";
			this->AntragAblehnenBtn->UseVisualStyleBackColor = true;
			this->AntragAblehnenBtn->Click += gcnew System::EventHandler(this, &AenderungsbearbeitungsFenster::btn_AntragAblehnen_Click);
			// 
			// lbl_Aenderungsanfrage
			// 
			this->lbl_Aenderungsanfrage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Aenderungsanfrage->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->lbl_Aenderungsanfrage->Location = System::Drawing::Point(8, 29);
			this->lbl_Aenderungsanfrage->Name = L"lbl_Aenderungsanfrage";
			this->lbl_Aenderungsanfrage->Size = System::Drawing::Size(537, 45);
			this->lbl_Aenderungsanfrage->TabIndex = 2;
			this->lbl_Aenderungsanfrage->Text = L"Neue Änderungsanfrage von";
			// 
			// NameMALbl
			// 
			this->NameMALbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NameMALbl->Location = System::Drawing::Point(2, 91);
			this->NameMALbl->Name = L"NameMALbl";
			this->NameMALbl->Size = System::Drawing::Size(543, 40);
			this->NameMALbl->TabIndex = 3;
			this->NameMALbl->Text = L"Beispiel MA";
			this->NameMALbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tagLbl
			// 
			this->tagLbl->AutoSize = true;
			this->tagLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tagLbl->Location = System::Drawing::Point(16, 182);
			this->tagLbl->Name = L"tagLbl";
			this->tagLbl->Size = System::Drawing::Size(191, 25);
			this->tagLbl->TabIndex = 4;
			this->tagLbl->Text = L"Tag der Änderung:";
			// 
			// ankunftLbl
			// 
			this->ankunftLbl->AutoSize = true;
			this->ankunftLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ankunftLbl->Location = System::Drawing::Point(16, 263);
			this->ankunftLbl->Name = L"ankunftLbl";
			this->ankunftLbl->Size = System::Drawing::Size(133, 25);
			this->ankunftLbl->TabIndex = 5;
			this->ankunftLbl->Text = L"Ankunft neu:";
			// 
			// gehenLbl
			// 
			this->gehenLbl->AutoSize = true;
			this->gehenLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gehenLbl->Location = System::Drawing::Point(16, 344);
			this->gehenLbl->Name = L"gehenLbl";
			this->gehenLbl->Size = System::Drawing::Size(124, 25);
			this->gehenLbl->TabIndex = 6;
			this->gehenLbl->Text = L"Gehen neu:";
			// 
			// ankunftLblTxt
			// 
			this->ankunftLblTxt->AutoSize = true;
			this->ankunftLblTxt->Location = System::Drawing::Point(244, 268);
			this->ankunftLblTxt->Name = L"ankunftLblTxt";
			this->ankunftLblTxt->Size = System::Drawing::Size(49, 20);
			this->ankunftLblTxt->TabIndex = 7;
			this->ankunftLblTxt->Text = L"00:00";
			// 
			// gehenLblTxt
			// 
			this->gehenLblTxt->AutoSize = true;
			this->gehenLblTxt->Location = System::Drawing::Point(244, 349);
			this->gehenLblTxt->Name = L"gehenLblTxt";
			this->gehenLblTxt->Size = System::Drawing::Size(49, 20);
			this->gehenLblTxt->TabIndex = 8;
			this->gehenLblTxt->Text = L"00:00";
			// 
			// tagLblTxt
			// 
			this->tagLblTxt->AutoSize = true;
			this->tagLblTxt->Location = System::Drawing::Point(244, 188);
			this->tagLblTxt->Name = L"tagLblTxt";
			this->tagLblTxt->Size = System::Drawing::Size(89, 20);
			this->tagLblTxt->TabIndex = 11;
			this->tagLblTxt->Text = L"00.00.0000";
			this->tagLblTxt->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// kommentarVorgesetzterTxt
			// 
			this->kommentarVorgesetzterTxt->Location = System::Drawing::Point(15, 538);
			this->kommentarVorgesetzterTxt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->kommentarVorgesetzterTxt->Name = L"kommentarVorgesetzterTxt";
			this->kommentarVorgesetzterTxt->Size = System::Drawing::Size(514, 26);
			this->kommentarVorgesetzterTxt->TabIndex = 12;
			// 
			// kommentarLbl2
			// 
			this->kommentarLbl2->AutoSize = true;
			this->kommentarLbl2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->kommentarLbl2->Location = System::Drawing::Point(10, 504);
			this->kommentarLbl2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->kommentarLbl2->Name = L"kommentarLbl2";
			this->kommentarLbl2->Size = System::Drawing::Size(265, 29);
			this->kommentarLbl2->TabIndex = 13;
			this->kommentarLbl2->Text = L"Kommentar hinzufügen:";
			// 
			// kommentarLbl
			// 
			this->kommentarLbl->AutoSize = true;
			this->kommentarLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->kommentarLbl->Location = System::Drawing::Point(16, 426);
			this->kommentarLbl->Name = L"kommentarLbl";
			this->kommentarLbl->Size = System::Drawing::Size(127, 25);
			this->kommentarLbl->TabIndex = 14;
			this->kommentarLbl->Text = L"Kommentar:";
			// 
			// kommentarAntragstellerLbl
			// 
			this->kommentarAntragstellerLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->kommentarAntragstellerLbl->Location = System::Drawing::Point(147, 426);
			this->kommentarAntragstellerLbl->Name = L"kommentarAntragstellerLbl";
			this->kommentarAntragstellerLbl->Size = System::Drawing::Size(382, 78);
			this->kommentarAntragstellerLbl->TabIndex = 15;
			// 
			// grundLbl
			// 
			this->grundLbl->AutoSize = true;
			this->grundLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grundLbl->Location = System::Drawing::Point(16, 386);
			this->grundLbl->Name = L"grundLbl";
			this->grundLbl->Size = System::Drawing::Size(77, 25);
			this->grundLbl->TabIndex = 16;
			this->grundLbl->Text = L"Grund:";
			// 
			// grundLblTxt
			// 
			this->grundLblTxt->AutoSize = true;
			this->grundLblTxt->Location = System::Drawing::Point(253, 390);
			this->grundLblTxt->Name = L"grundLblTxt";
			this->grundLblTxt->Size = System::Drawing::Size(0, 20);
			this->grundLblTxt->TabIndex = 18;
			this->grundLblTxt->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// gehenAltLbl
			// 
			this->gehenAltLbl->AutoSize = true;
			this->gehenAltLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gehenAltLbl->Location = System::Drawing::Point(16, 304);
			this->gehenAltLbl->Name = L"gehenAltLbl";
			this->gehenAltLbl->Size = System::Drawing::Size(111, 25);
			this->gehenAltLbl->TabIndex = 19;
			this->gehenAltLbl->Text = L"Gehen alt:";
			// 
			// ankunftAltLbl
			// 
			this->ankunftAltLbl->AutoSize = true;
			this->ankunftAltLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ankunftAltLbl->Location = System::Drawing::Point(16, 223);
			this->ankunftAltLbl->Name = L"ankunftAltLbl";
			this->ankunftAltLbl->Size = System::Drawing::Size(120, 25);
			this->ankunftAltLbl->TabIndex = 20;
			this->ankunftAltLbl->Text = L"Ankunft alt:";
			// 
			// ankunftAltLblTxt
			// 
			this->ankunftAltLblTxt->AutoSize = true;
			this->ankunftAltLblTxt->Location = System::Drawing::Point(244, 228);
			this->ankunftAltLblTxt->Name = L"ankunftAltLblTxt";
			this->ankunftAltLblTxt->Size = System::Drawing::Size(49, 20);
			this->ankunftAltLblTxt->TabIndex = 21;
			this->ankunftAltLblTxt->Text = L"00:00";
			// 
			// gehenAltLblTxt
			// 
			this->gehenAltLblTxt->AutoSize = true;
			this->gehenAltLblTxt->Location = System::Drawing::Point(244, 309);
			this->gehenAltLblTxt->Name = L"gehenAltLblTxt";
			this->gehenAltLblTxt->Size = System::Drawing::Size(49, 20);
			this->gehenAltLblTxt->TabIndex = 22;
			this->gehenAltLblTxt->Text = L"00:00";
			// 
			// AenderungsbearbeitungsFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(549, 677);
			this->Controls->Add(this->gehenAltLblTxt);
			this->Controls->Add(this->ankunftAltLblTxt);
			this->Controls->Add(this->ankunftAltLbl);
			this->Controls->Add(this->gehenAltLbl);
			this->Controls->Add(this->grundLblTxt);
			this->Controls->Add(this->grundLbl);
			this->Controls->Add(this->kommentarAntragstellerLbl);
			this->Controls->Add(this->kommentarLbl);
			this->Controls->Add(this->kommentarLbl2);
			this->Controls->Add(this->kommentarVorgesetzterTxt);
			this->Controls->Add(this->tagLblTxt);
			this->Controls->Add(this->gehenLblTxt);
			this->Controls->Add(this->ankunftLblTxt);
			this->Controls->Add(this->gehenLbl);
			this->Controls->Add(this->ankunftLbl);
			this->Controls->Add(this->tagLbl);
			this->Controls->Add(this->NameMALbl);
			this->Controls->Add(this->lbl_Aenderungsanfrage);
			this->Controls->Add(this->AntragAblehnenBtn);
			this->Controls->Add(this->AntragBestaetigenBtn);
			this->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->Name = L"AenderungsbearbeitungsFenster";
			this->Text = L"Neue Anfrage";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AenderungsbearbeitungsFenster::AenderungsbearbeitungsFenster_FormClosed);
			this->Load += gcnew System::EventHandler(this, &AenderungsbearbeitungsFenster::AenderungsbearbeitungsFenster_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: List<Ereignis^>^ ereignisse;
			 Int32 ereignis = 0;
			 //AenderungsantragsFenster^ aenderungsfenster;
			 Kalender^ kalender;
			 TimeSpan^ gesamtstundenAlt = nullptr;
			 TimeSpan^ gesamtstundenNeu = nullptr;
	public: 
		void setEreignisListe(List<Ereignis^>^ ereignisse) {
			this->ereignisse = ereignisse;
		}

		void setSelectedEreignis(Int32 ereignisIndex) {
			this->ereignis = ereignis;
		}

		
	public: System::Void AenderungsbearbeitungsFenster_Load(System::Object^  sender, System::EventArgs^  e) {
		istOffen = true;
		p_Tag = antrag->getNewStart()->Date;
		p_AnkunftAlt = antrag->getOldStart();
		p_Ankunft = antrag->getNewStart();
		p_GehenAlt = antrag->getOldEnd();
		p_Gehen = antrag->getNewEnd();
		p_Kommentar = antrag->getKommentarAntragsteller();
		p_Grund = antrag->getGrund();
		p_Name = antrag->getAntragsteller()->getVorname() + " " + antrag->getAntragsteller()->getNachname();
	}

	public:
		void setAenderungsantrag(Aenderungsantrag^ antrag)
		{
			this->antrag = antrag;
		}

		property DateTime^ p_Tag
		{
			void set(DateTime^ p_Tag) {
				this->tagLblTxt->Text = p_Tag->ToString("dddd, dd.MMMM yyyy");
			}
		}

		property DateTime^ p_GehenAlt
		{
			void set(DateTime^ p_GehenAlt) {
				this->gehenAltLblTxt->Text = p_GehenAlt->ToString("HH:mm");
			}
		}

		property DateTime^ p_Gehen
		{
			void set(DateTime^ p_Gehen) {
				this->gehenLblTxt->Text = p_Gehen->ToString("HH:mm");
			}
		}

		property DateTime^ p_AnkunftAlt
		{
			void set(DateTime^ p_AnkunftAlt) {
				this->ankunftAltLblTxt->Text = p_AnkunftAlt->ToString("HH:mm");
			}
		}

		property DateTime^ p_Ankunft
		{
			void set(DateTime^ p_Ankunft) {
				this->ankunftLblTxt->Text = p_Ankunft->ToString("HH:mm");
			}
		}

		property String^ p_Grund
		{
			void set(String^ p_Grund) {
				this->grundLblTxt->Text = p_Grund;
			}
		}

		property String^ p_Name
		{
			void set(String^ p_Name) {
				this->NameMALbl->Text = p_Name;
			}
		}

		property String^ p_Kommentar
		{
			void set(String^ kommentar) {
				if (kommentar->Length == 0) {
					this->kommentarAntragstellerLbl->Text = "-----";
				}
				else {
					this->kommentarAntragstellerLbl->Text = kommentar;
				}
			}
			String^ get() {
				return kommentarVorgesetzterTxt->Text;
			}
		}

		Boolean getIstOffen() {
			return istOffen;
		}

		void clear()
		{
			this->kommentarVorgesetzterTxt->Text = "";
		}

	private: System::Void btn_AntragBestaetigen_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Angestellter^ angestellter = antrag->getAntragsteller();
		if (MessageBox::Show("Änderungsantrag wirklich bestätigen?", "Antrag bestätigen?", MessageBoxButtons::YesNo,
			MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			//Hier werden die alten gesamtstunden berechnet
			for (int i = 0; i < angestellter->getAnzahlEreignisse(); i++) {
				if (antrag->getOldStart()) {
					gesamtstundenAlt = antrag->getAntragsteller()->berechneArbeitsstunden(i);
				}
			}


			antrag->getAntragsteller()->aenderungAntwort(tagLblTxt->Text, p_Kommentar, true);
			antrag->getAntragsteller()->getEreignis(antrag->getStartIndex())->setTimestamp(*antrag->getNewStart());
			for (int i = antrag->getStartIndex(); i < antrag->getAntragsteller()->getAnzahlEreignisse(); i++) {
				if (antrag->getAntragsteller()->getEreignis(i)->getTyp() == ARBEIT_ENDE) {
					antrag->getAntragsteller()->getEreignis(i)->setTimestamp(*antrag->getNewEnd());
					break;
				}
			}
			
			//HIER BITTE GUCKEN
			for (int i = 0; i < angestellter->getAnzahlEreignisse(); i++) {
				if (antrag->getNewStart()) {
					gesamtstundenNeu = antrag->getAntragsteller()->berechneArbeitsstunden(i);
				}
			}
			if (kalender->berechneKW(antrag->getOldStart()) == kalender->berechneKW(antrag->getNewStart())) {
				Int32 stundenAlt = gesamtstundenAlt->Hours;
				Int32 stundenNeu = gesamtstundenNeu->Hours;
				Int32 differenzStunden = stundenNeu - stundenAlt;
				Int32 minutenAlt = gesamtstundenAlt->Minutes;
				Int32 minutenNeu = gesamtstundenNeu->Minutes;
				Int32 differenzMinuten= minutenNeu - minutenAlt;
				antrag->getAntragsteller()->zieheZeitAb(differenzStunden, differenzMinuten);
				
			}
			else {

			}
			
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
	}

	private: System::Void btn_AntragAblehnen_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (MessageBox::Show("Änderungsantrag wirklich ablehnen?", "Antrag ablehnen?", MessageBoxButtons::YesNo,
			MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			antrag->getAntragsteller()->aenderungAntwort(tagLblTxt->Text, p_Kommentar, false);
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
	}

	private: System::Void AenderungsbearbeitungsFenster_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		istOffen = false;
	}
};

}
