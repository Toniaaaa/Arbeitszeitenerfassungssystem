#pragma once
#include "Aenderungsantrag.h"
#include "Angestellter.h"
#include "Ereignis.h"

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
	private: System::Windows::Forms::TextBox^  kommentarVorgesetzterTxt;


	private: System::Windows::Forms::Label^  kommentarLbl;
	private: System::Windows::Forms::Label^  kommentarAntragstellerLbl;


	private: System::Windows::Forms::Label^  grundLbl;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  grundLblTxt;
	private: System::Windows::Forms::Label^  kommentarLbl2;

	public:
		AenderungsbearbeitungsFenster(void)
		{
			InitializeComponent();
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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->grundLblTxt = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// AntragBestaetigenBtn
			// 
			this->AntragBestaetigenBtn->Location = System::Drawing::Point(30, 340);
			this->AntragBestaetigenBtn->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->AntragBestaetigenBtn->Name = L"AntragBestaetigenBtn";
			this->AntragBestaetigenBtn->Size = System::Drawing::Size(109, 40);
			this->AntragBestaetigenBtn->TabIndex = 0;
			this->AntragBestaetigenBtn->Text = L"Bestätigen";
			this->AntragBestaetigenBtn->UseVisualStyleBackColor = true;
			this->AntragBestaetigenBtn->Click += gcnew System::EventHandler(this, &AenderungsbearbeitungsFenster::btn_AntragBestaetigen_Click);
			// 
			// AntragAblehnenBtn
			// 
			this->AntragAblehnenBtn->Location = System::Drawing::Point(192, 340);
			this->AntragAblehnenBtn->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->AntragAblehnenBtn->Name = L"AntragAblehnenBtn";
			this->AntragAblehnenBtn->Size = System::Drawing::Size(115, 40);
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
			this->lbl_Aenderungsanfrage->Location = System::Drawing::Point(5, 19);
			this->lbl_Aenderungsanfrage->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Aenderungsanfrage->Name = L"lbl_Aenderungsanfrage";
			this->lbl_Aenderungsanfrage->Size = System::Drawing::Size(358, 29);
			this->lbl_Aenderungsanfrage->TabIndex = 2;
			this->lbl_Aenderungsanfrage->Text = L"Neue Änderungsanfrage von";
			// 
			// NameMALbl
			// 
			this->NameMALbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NameMALbl->Location = System::Drawing::Point(1, 59);
			this->NameMALbl->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->NameMALbl->Name = L"NameMALbl";
			this->NameMALbl->Size = System::Drawing::Size(362, 26);
			this->NameMALbl->TabIndex = 3;
			this->NameMALbl->Text = L"Beispiel MA";
			this->NameMALbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tagLbl
			// 
			this->tagLbl->AutoSize = true;
			this->tagLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tagLbl->Location = System::Drawing::Point(11, 118);
			this->tagLbl->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->tagLbl->Name = L"tagLbl";
			this->tagLbl->Size = System::Drawing::Size(128, 17);
			this->tagLbl->TabIndex = 4;
			this->tagLbl->Text = L"Tag der Änderung:";
			// 
			// ankunftLbl
			// 
			this->ankunftLbl->AutoSize = true;
			this->ankunftLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ankunftLbl->Location = System::Drawing::Point(11, 144);
			this->ankunftLbl->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ankunftLbl->Name = L"ankunftLbl";
			this->ankunftLbl->Size = System::Drawing::Size(88, 17);
			this->ankunftLbl->TabIndex = 5;
			this->ankunftLbl->Text = L"Ankunft neu:";
			// 
			// gehenLbl
			// 
			this->gehenLbl->AutoSize = true;
			this->gehenLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gehenLbl->Location = System::Drawing::Point(11, 170);
			this->gehenLbl->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->gehenLbl->Name = L"gehenLbl";
			this->gehenLbl->Size = System::Drawing::Size(83, 17);
			this->gehenLbl->TabIndex = 6;
			this->gehenLbl->Text = L"Gehen neu:";
			// 
			// ankunftLblTxt
			// 
			this->ankunftLblTxt->AutoSize = true;
			this->ankunftLblTxt->Location = System::Drawing::Point(163, 148);
			this->ankunftLblTxt->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ankunftLblTxt->Name = L"ankunftLblTxt";
			this->ankunftLblTxt->Size = System::Drawing::Size(34, 13);
			this->ankunftLblTxt->TabIndex = 7;
			this->ankunftLblTxt->Text = L"00:00";
			// 
			// gehenLblTxt
			// 
			this->gehenLblTxt->AutoSize = true;
			this->gehenLblTxt->Location = System::Drawing::Point(163, 174);
			this->gehenLblTxt->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->gehenLblTxt->Name = L"gehenLblTxt";
			this->gehenLblTxt->Size = System::Drawing::Size(34, 13);
			this->gehenLblTxt->TabIndex = 8;
			this->gehenLblTxt->Text = L"00:00";
			// 
			// tagLblTxt
			// 
			this->tagLblTxt->AutoSize = true;
			this->tagLblTxt->Location = System::Drawing::Point(163, 122);
			this->tagLblTxt->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->tagLblTxt->Name = L"tagLblTxt";
			this->tagLblTxt->Size = System::Drawing::Size(61, 13);
			this->tagLblTxt->TabIndex = 11;
			this->tagLblTxt->Text = L"00.00.0000";
			this->tagLblTxt->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// kommentarVorgesetzterTxt
			// 
			this->kommentarVorgesetzterTxt->Location = System::Drawing::Point(14, 305);
			this->kommentarVorgesetzterTxt->Name = L"kommentarVorgesetzterTxt";
			this->kommentarVorgesetzterTxt->Size = System::Drawing::Size(340, 20);
			this->kommentarVorgesetzterTxt->TabIndex = 12;
			// 
			// kommentarLbl2
			// 
			this->kommentarLbl2->AutoSize = true;
			this->kommentarLbl2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->kommentarLbl2->Location = System::Drawing::Point(11, 284);
			this->kommentarLbl2->Name = L"kommentarLbl2";
			this->kommentarLbl2->Size = System::Drawing::Size(165, 18);
			this->kommentarLbl2->TabIndex = 13;
			this->kommentarLbl2->Text = L"Kommentar hinzufügen:";
			// 
			// kommentarLbl
			// 
			this->kommentarLbl->AutoSize = true;
			this->kommentarLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->kommentarLbl->Location = System::Drawing::Point(11, 222);
			this->kommentarLbl->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->kommentarLbl->Name = L"kommentarLbl";
			this->kommentarLbl->Size = System::Drawing::Size(84, 17);
			this->kommentarLbl->TabIndex = 14;
			this->kommentarLbl->Text = L"Kommentar:";
			// 
			// kommentarAntragstellerLbl
			// 
			this->kommentarAntragstellerLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->kommentarAntragstellerLbl->Location = System::Drawing::Point(99, 222);
			this->kommentarAntragstellerLbl->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->kommentarAntragstellerLbl->Name = L"kommentarAntragstellerLbl";
			this->kommentarAntragstellerLbl->Size = System::Drawing::Size(255, 51);
			this->kommentarAntragstellerLbl->TabIndex = 15;
			// 
			// grundLbl
			// 
			this->grundLbl->AutoSize = true;
			this->grundLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grundLbl->Location = System::Drawing::Point(11, 196);
			this->grundLbl->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->grundLbl->Name = L"grundLbl";
			this->grundLbl->Size = System::Drawing::Size(52, 17);
			this->grundLbl->TabIndex = 16;
			this->grundLbl->Text = L"Grund:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(163, 200);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 17;
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(163, 226);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 13);
			this->label4->TabIndex = 18;
			this->label4->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// grundLblTxt
			// 
			this->grundLblTxt->AutoSize = true;
			this->grundLblTxt->Location = System::Drawing::Point(163, 199);
			this->grundLblTxt->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->grundLblTxt->Name = L"grundLblTxt";
			this->grundLblTxt->Size = System::Drawing::Size(0, 13);
			this->grundLblTxt->TabIndex = 19;
			// 
			// AenderungsbearbeitungsFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(366, 392);
			this->Controls->Add(this->grundLblTxt);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
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
			this->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->Name = L"AenderungsbearbeitungsFenster";
			this->Text = L"Neue Anfrage";
			this->Load += gcnew System::EventHandler(this, &AenderungsbearbeitungsFenster::AenderungsbearbeitungsFenster_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: List<Ereignis^>^ ereignisse;
	public: void setEreignisListe(List<Ereignis^>^ ereignisse) {
		this->ereignisse = ereignisse;
	}

	private: System::Void AenderungsbearbeitungsFenster_Load(System::Object^  sender, System::EventArgs^  e) {
		p_Tag = antrag->getTag();
		p_Ankunft = antrag->getAnfang();
		p_Gehen = antrag->getEnde();
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

		property DateTime^ p_Gehen
		{
			void set(DateTime^ p_Gehen) {
				this->gehenLblTxt->Text = p_Gehen->ToString("HH:mm");
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

		void clear()
		{
			this->kommentarVorgesetzterTxt->Text = "";
		}

	private: System::Void btn_AntragBestaetigen_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (MessageBox::Show("Änderungsantrag wirklich bestätigen?", "Antrag bestätigen?", MessageBoxButtons::YesNo,
			MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			antrag->setKommentarVorgesetzter(p_Kommentar);
			textZumAntrag = "Ihr Änderungsantrag betreffend " + tagLblTxt->Text + " wurde bestätigt und wird korrigiert.";
			if (p_Kommentar->Length > 0) {
				textZumAntrag += "\n\nKommentar:\n" + p_Kommentar;
			}
			antrag->getAntragsteller()->addAntragsInfo(textZumAntrag);
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
	}

	private: System::Void btn_AntragAblehnen_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (MessageBox::Show("Änderungsantrag wirklich ablehnen?", "Antrag ablehnen?", MessageBoxButtons::YesNo,
			MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			antrag->setKommentarVorgesetzter(p_Kommentar);
			textZumAntrag = "Ihr Änderungsantrag betreffend " + tagLblTxt + " wurde abgelehnt.";
			if (p_Kommentar->Length > 0) {
				textZumAntrag += "\n\nKommentar:\n" + p_Kommentar;
			}
			antrag->getAntragsteller()->addAntragsInfo(textZumAntrag);
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
	}

	};

}
