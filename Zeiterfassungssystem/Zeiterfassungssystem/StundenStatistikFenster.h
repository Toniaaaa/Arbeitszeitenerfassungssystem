#pragma once
#include "Angestellter.h"
#include "Ereignis.h"
#include "AenderungsantragsFenster.h"
#include "Vorgesetzter.h"
#include "KrankmeldungsFenster.h"
#include "Kalender.h"


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
		KrankmeldungsFenster^ krankmeldungsfenster;
	public:
		StundenStatistikFenster(void)
		{
			InitializeComponent();
			aenderungsantrag = gcnew AenderungsantragsFenster;
			krankmeldungsfenster = gcnew KrankmeldungsFenster;
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
	private: System::Windows::Forms::Button^  btn_aendern;
	private: System::Windows::Forms::Label^  lbl_gesamteZeit;
	private: System::Windows::Forms::Button^  krankheitBtn;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(StundenStatistikFenster::typeid));
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->clm_Arbeitsang = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_pausenanfang = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Pausenende = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Arbeitsende = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Gesamt = (gcnew System::Windows::Forms::ColumnHeader());
			this->btn_aendern = (gcnew System::Windows::Forms::Button());
			this->lbl_gesamteZeit = (gcnew System::Windows::Forms::Label());
			this->krankheitBtn = (gcnew System::Windows::Forms::Button());
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
			this->btn_aendern->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_aendern->Name = L"btn_aendern";
			this->btn_aendern->Size = System::Drawing::Size(144, 54);
			this->btn_aendern->TabIndex = 0;
			this->btn_aendern->Text = L"Ändern";
			this->btn_aendern->UseVisualStyleBackColor = true;
			this->btn_aendern->Click += gcnew System::EventHandler(this, &StundenStatistikFenster::btn_aendern_Click);
			// 
			// lbl_gesamteZeit
			// 
			this->lbl_gesamteZeit->AutoSize = true;
			this->lbl_gesamteZeit->BackColor = System::Drawing::SystemColors::Window;
			this->lbl_gesamteZeit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_gesamteZeit->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->lbl_gesamteZeit->Location = System::Drawing::Point(1383, 562);
			this->lbl_gesamteZeit->Name = L"lbl_gesamteZeit";
			this->lbl_gesamteZeit->Size = System::Drawing::Size(79, 17);
			this->lbl_gesamteZeit->TabIndex = 2;
			this->lbl_gesamteZeit->Text = L"Gesamtzeit";
			// 
			// krankheitBtn
			// 
			this->krankheitBtn->Location = System::Drawing::Point(201, 544);
			this->krankheitBtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->krankheitBtn->Name = L"krankheitBtn";
			this->krankheitBtn->Size = System::Drawing::Size(144, 54);
			this->krankheitBtn->TabIndex = 1;
			this->krankheitBtn->Text = L"Krankmeldung";
			this->krankheitBtn->UseVisualStyleBackColor = true;
			this->krankheitBtn->Click += gcnew System::EventHandler(this, &StundenStatistikFenster::krankheitBtn_Click);
			// 
			// StundenStatistikFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1591, 699);
			this->Controls->Add(this->krankheitBtn);
			this->Controls->Add(this->lbl_gesamteZeit);
			this->Controls->Add(this->btn_aendern);
			this->Controls->Add(this->listView1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"StundenStatistikFenster";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Arbeitszeit Statistik";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &StundenStatistikFenster::StundenStatistikFenster_FormClosing);
			this->Load += gcnew System::EventHandler(this, &StundenStatistikFenster::StundenStatistikFenster_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		Angestellter^ angestellter;
		Vorgesetzter^ vorgesetzter;
		Kalender^ kalender = gcnew Kalender;

	public:

		void setAktuellenAngestellten(Angestellter^ angestellter) {
			this->angestellter = angestellter;
		}

		void setVorgesetzter(Vorgesetzter^ vorgesetzter) {
			this->vorgesetzter = vorgesetzter;
		}


	private: System::Void StundenStatistikFenster_Load(System::Object^  sender, System::EventArgs^  e) {

		//Liste an ereignissen um passenden Index fuer das Aenderungsfenster zu finden
		ereignisse = gcnew List<Int32>;
		aenderungsantrag->setStatistikFenster(this);
		aenderungsantrag->setAntragssteller(angestellter);
		ListViewItem^ item;

		//wenn noch keine Pause vorhanden erste pause wahr 
		bool erstePause = true;
		//noch keine Pause also false
		bool hattePause = false;
		//zum speichern der gesamtstunden
		TimeSpan^ gesamtStunden = nullptr;
		TimeSpan^ gesamt = gcnew TimeSpan;
		Double^ gesamtezeit;

		//Laufe ueber ereignisse fuege diese an die richtigen Items und speicher index
		for (int i = 0; i < angestellter->getAnzahlEreignisse(); i++) {

			if (angestellter->getEreignis(i)->getTyp() == ARBEIT_START) {
				item = gcnew ListViewItem();
				listView1->Items->Add(item);
				//index in liste gespeichert
				ereignisse->Add(i);
				erstePause = true;
				//berechne gesamtarbeitstunden
				gesamtStunden = angestellter->berechneArbeitsstunden(i);
				gesamt = TimeSpan::operator+(*gesamt, *gesamtStunden);
				item->Text = angestellter->getEreignis(i)->getTimestamp()->ToString();
			}
			if (angestellter->getEreignis(i)->getTyp() == PAUSE_START) {
				hattePause = true;
				//wenn es nicht die erste pause dann fuege es in naechste zeile ein. fuege -1 hinzu da pausen nicht veraendert 
				//werden koennen
				if (!erstePause) {
					item = gcnew ListViewItem();
					listView1->Items->Add(item);
					ereignisse->Add(-1);
					//da Pause arbeitsanfang leer
					item->Text = "";
				}

				item->SubItems->Add(angestellter->getEreignis(i)->getTimestamp()->ToString());
			}

			//wenn pause ende erste pause vorbei
			if (angestellter->getEreignis(i)->getTyp() == PAUSE_ENDE) {
				erstePause = false;
				item->SubItems->Add(angestellter->getEreignis(i)->getTimestamp()->ToString());
			}

			//Wenn arbeitsende dann pausen auch leer nur arbeitsende und gesamtstunden hinzufuegen
			if (angestellter->getEreignis(i)->getTyp() == ARBEIT_ENDE) {
				if (!hattePause) {
					item->SubItems->Add("");
					item->SubItems->Add("");
				}
				hattePause = false;
				item->SubItems->Add(angestellter->getEreignis(i)->getTimestamp()->ToString());
				gesamtezeit = gesamtStunden->TotalSeconds;
				item->SubItems->Add(gesamtStunden->ToString());
			}
		}
		lbl_gesamteZeit->Text = gesamt->TotalHours.ToString("0.00" + " Stunden gesamt");
	}
			 
	
	private: System::Void StundenStatistikFenster_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		listView1->Items->Clear();
	}

	private: System::Void listView1_ItemSelectionChanged(System::Object^  sender, System::Windows::Forms::ListViewItemSelectionChangedEventArgs^  e) {
		selectedEreignis = ereignisse[e->ItemIndex];
	}

	private: System::Void btn_aendern_Click(System::Object^  sender, System::EventArgs^  e) {
		//erkennt die angeklickte Zeile und gibt die passenden Ereignisse weiter
		bool fehler = true;
	
		if (selectedEreignis >= 0) {
			for (int i = selectedEreignis; i < angestellter->getAnzahlEreignisse(); i++) {
				if (angestellter->getEreignis(i)->getTyp() == ARBEIT_ENDE) {
					aenderungsantrag->setSelectedEreignis(selectedEreignis);
					aenderungsantrag->ShowDialog(this);
					fehler = false;
					break;
				}
			}
		}
		else {
			MessageBox::Show("Bitte wählen Sie eine zu ändernde Zeile aus!", "Keine Auswahl getroffen!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			fehler = false;
		}
		aenderungsantrag->clear(); //Textfelder wieder leeren
	
		if (fehler) {
			MessageBox::Show("Das Bearbeiten ist erst nach Beenden des Arbeitstages möglich!", "Bearbeitung nicht möglich!", MessageBoxButtons::OK, MessageBoxIcon::Error);

		}
	}

	//Krankheit-Button geklickt
	private: System::Void krankheitBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		//Das KrankmeldungsFenster wird aufgerufen
		krankmeldungsfenster->setAngestellter(angestellter);
		System::Windows::Forms::DialogResult result = krankmeldungsfenster->ShowDialog(this);

		//Wenn das Fenster OK zurückgibt, wird eine Information an den Arbeitgeber gesendet und die Arbeitstage werden als volle Arbeitstage verrechnet
		if (result == System::Windows::Forms::DialogResult::OK) {
			String^ text = "Wollen Sie wirklich eine Krankmeldung für den Zeitraum\nvom " + krankmeldungsfenster->p_Anfang.ToString("dddd, dd. MMMM yyyy") + "\nbis "
				+ krankmeldungsfenster->p_Ende.ToString("dddd, dd. MMMM yyyy") + " einreichen?";
			if (MessageBox::Show(text, "Krankmeldung", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				DateTime beginn = krankmeldungsfenster->p_Anfang;
				if (beginn.DayOfWeek != DayOfWeek::Saturday && beginn.DayOfWeek != DayOfWeek::Sunday) {
					//Krankheitstage hinzufügen
					angestellter->krankMelden(krankmeldungsfenster->p_Anfang, krankmeldungsfenster->p_Ende);

					//Bestätigung per MessageBox:
					MessageBox::Show("Ihre Krankmeldung wurde erfolgreich gespeichert!", "Einreichen erfolgreich", MessageBoxButtons::OK, MessageBoxIcon::Information);

					//Information an Vorgesetzten
					String^ infoAnVorgesetzten = angestellter->getVorname() + " " + angestellter->getNachname() + " hat eine Krankmeldung\nvom " + krankmeldungsfenster->p_Anfang.ToString("dddd, dd. MMMM yyyy")
						+ "\nbis " + krankmeldungsfenster->p_Ende.ToString("dddd, dd. MMMM yyyy") + "\nüber insgesamt " + krankmeldungsfenster->p_Tage + " Tage eingereicht.";
					vorgesetzter->addAntragsInfo(infoAnVorgesetzten);

				} 
				else {
					MessageBox::Show("Für Samstags und Sonntags wird keine Krankmeldung benötigt!", "Nicht erfordert!", MessageBoxButtons::OK, MessageBoxIcon::Information);

				}
			}
		}
		krankmeldungsfenster->clear();
	}

};
}
