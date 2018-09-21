#pragma once
#include "Angestellter.h"
#include "Ereignis.h"
#include "AenderungsantragsFenster.h"
#include "Vorgesetzter.h"


namespace Zeiterfassungssystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für StundenStatistikFenster
	/// </summary>
	public ref class StundenStatistikFenster : public System::Windows::Forms::Form
	{
	private:
		List<Int32>^ ereignisse;
		Int32 selectedEreignis = -1;
		AenderungsantragsFenster^ aenderungsantrag;

	private: System::Windows::Forms::Button^  btn_aendern;
	private: System::Windows::Forms::Label^  label1;
			 
	public:
		StundenStatistikFenster(void)
		{
			InitializeComponent();
			aenderungsantrag = gcnew AenderungsantragsFenster;
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~StundenStatistikFenster()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::ColumnHeader^  clm_Arbeitsang;
	private: System::Windows::Forms::ColumnHeader^  clm_pausenanfang;
	private: System::Windows::Forms::ColumnHeader^  clm_Pausenende;
	private: System::Windows::Forms::ColumnHeader^  clm_Arbeitsende;
	private: System::Windows::Forms::ColumnHeader^  clm_Gesamt;

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
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->clm_Arbeitsang = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_pausenanfang = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Pausenende = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Arbeitsende = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Gesamt = (gcnew System::Windows::Forms::ColumnHeader());
			this->btn_aendern = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->clm_Arbeitsang, this->clm_pausenanfang,
					this->clm_Pausenende, this->clm_Arbeitsende, this->clm_Gesamt
			});
			this->listView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listView1->GridLines = true;
			this->listView1->Location = System::Drawing::Point(0, 0);
			this->listView1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(1591, 699);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->ItemSelectionChanged += gcnew System::Windows::Forms::ListViewItemSelectionChangedEventHandler(this, &StundenStatistikFenster::listView1_ItemSelectionChanged);
			this->listView1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &StundenStatistikFenster::listView1_MouseDoubleClick);
			// 
			// clm_Arbeitsang
			// 
			this->clm_Arbeitsang->Text = L"Arbeitsanfang";
			this->clm_Arbeitsang->Width = 201;
			// 
			// clm_pausenanfang
			// 
			this->clm_pausenanfang->Text = L"Pausenanfang";
			this->clm_pausenanfang->Width = 262;
			// 
			// clm_Pausenende
			// 
			this->clm_Pausenende->Text = L"Pausenende";
			this->clm_Pausenende->Width = 250;
			// 
			// clm_Arbeitsende
			// 
			this->clm_Arbeitsende->Text = L"Arbeitsende";
			this->clm_Arbeitsende->Width = 310;
			// 
			// clm_Gesamt
			// 
			this->clm_Gesamt->Text = L"Gesamtstunden";
			this->clm_Gesamt->Width = 160;
			// 
			// btn_aendern
			// 
			this->btn_aendern->Location = System::Drawing::Point(27, 544);
			this->btn_aendern->Name = L"btn_aendern";
			this->btn_aendern->Size = System::Drawing::Size(144, 54);
			this->btn_aendern->TabIndex = 1;
			this->btn_aendern->Text = L"Ändern";
			this->btn_aendern->UseVisualStyleBackColor = true;
			this->btn_aendern->Click += gcnew System::EventHandler(this, &StundenStatistikFenster::btn_aendern_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1249, 581);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"label1";
			// 
			// StundenStatistikFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1591, 699);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_aendern);
			this->Controls->Add(this->listView1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"StundenStatistikFenster";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"StundenStatistikFenster";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &StundenStatistikFenster::StundenStatistikFenster_FormClosing);
			this->Load += gcnew System::EventHandler(this, &StundenStatistikFenster::StundenStatistikFenster_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		Angestellter ^ angestellter;
		Vorgesetzter^ vorgesetzter;

	public:
		void setAktuellenAngestellten(Angestellter^ angestellter) {
			this->angestellter = angestellter;
		}
		void setVorgesetzter(Vorgesetzter^ vorgesetzter) {
			this->vorgesetzter = vorgesetzter;
		}


	private: System::Void StundenStatistikFenster_Load(System::Object^  sender, System::EventArgs^  e) {
		ereignisse = gcnew List<Int32>;
		aenderungsantrag->setStatistikFenster(this);
		aenderungsantrag->setAntragssteller(angestellter);
		ListViewItem^ item;
		bool erstePause = true;
		bool hattePause = false;
		TimeSpan^ gesamtStunden = nullptr;
		TimeSpan^ gesamt = nullptr;
		for (int i = 0; i < angestellter->getAnzahlEreignisse(); i++) {
			
			if (angestellter->getEreignis(i)->getTyp() == ARBEIT_START) {
				item = gcnew ListViewItem();
				listView1->Items->Add(item);
				ereignisse->Add(i);
				erstePause = true;

				gesamtStunden = angestellter->berechneArbeitsstunden(i);

				item->Text = angestellter->getEreignis(i)->getTimestamp()->ToString();
			}
			if (angestellter->getEreignis(i)->getTyp() == PAUSE_START) {
				hattePause = true;
				if (!erstePause) {
					item = gcnew ListViewItem();
					listView1->Items->Add(item);
					ereignisse->Add(-1);
					item->Text = "";
				}

				item->SubItems->Add(angestellter->getEreignis(i)->getTimestamp()->ToString());
			}
					
			if (angestellter->getEreignis(i)->getTyp() == PAUSE_ENDE) {
				erstePause = false;
				item->SubItems->Add(angestellter->getEreignis(i)->getTimestamp()->ToString());
			}
					
			if (angestellter->getEreignis(i)->getTyp() == ARBEIT_ENDE) {
				if (!hattePause) {
					item->SubItems->Add("");
					item->SubItems->Add("");
				}
				hattePause = false;
				item->SubItems->Add(angestellter->getEreignis(i)->getTimestamp()->ToString());
				item->SubItems->Add(gesamtStunden->ToString());
				gesamt += *gesamtStunden;
			}
		}
		label1->Text = Convert::ToString(gesamt);
	}
			 
	
	private: System::Void StundenStatistikFenster_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		listView1->Items->Clear();
	}

	private: System::Void listView1_ItemSelectionChanged(System::Object^  sender, System::Windows::Forms::ListViewItemSelectionChangedEventArgs^  e) {
		
		selectedEreignis = ereignisse[e->ItemIndex];
			
	}
	private: System::Void listView1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

	}
	private: System::Void btn_aendern_Click(System::Object^  sender, System::EventArgs^  e) {

		aenderungsantrag->setSelectedEreignis(selectedEreignis);
		aenderungsantrag->ShowDialog(this);
		aenderungsantrag->clear(); //Textfelder wieder leeren
	}
};
}
