#pragma once
#include "Angestellter.h"
#include "Abteilung.h"
#include "Mitarbeiter.h"
#include "Unternehmen.h"
#include "Ereignis.h"

namespace Zeiterfassungssystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Zusammenfassung für PersonalFenster
	/// </summary>
	public ref class PersonalFenster : public System::Windows::Forms::Form
	{

	public:
		PersonalFenster(void)
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
		~PersonalFenster()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::ColumnHeader^  clm_Status;
	private: System::Windows::Forms::ColumnHeader^  clm_Name;
	private: System::Windows::Forms::ColumnHeader^  clm_Vorname;
	private: System::Windows::Forms::ColumnHeader^  clm_Personalnummer;
	private: System::Windows::Forms::ColumnHeader^  clm_Abteilung;
	private: System::Windows::Forms::ColumnHeader^  clm_Rolle;
	private: System::Windows::Forms::ColumnHeader^  clm_Urlaubstage;
	private: System::Windows::Forms::ColumnHeader^  clm_Resturlaub;
	private: System::Windows::Forms::ColumnHeader^  clm_WochenstundenGesamt;
	private: System::Windows::Forms::ColumnHeader^  clm_WochenstundenRest;
	private: System::Windows::Forms::ColumnHeader^  clm_UeberstundenWoche;
	private: System::Windows::Forms::ColumnHeader^  clm_UeberstundenGesamt;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PersonalFenster::typeid));
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->clm_Status = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Name = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Vorname = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Personalnummer = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Abteilung = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Rolle = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Urlaubstage = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Resturlaub = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_WochenstundenGesamt = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_WochenstundenRest = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_UeberstundenWoche = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_UeberstundenGesamt = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(12) {
				this->clm_Status, this->clm_Name,
					this->clm_Vorname, this->clm_Personalnummer, this->clm_Abteilung, this->clm_Rolle, this->clm_Urlaubstage, this->clm_Resturlaub,
					this->clm_WochenstundenGesamt, this->clm_WochenstundenRest, this->clm_UeberstundenWoche, this->clm_UeberstundenGesamt
			});
			this->listView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listView1->FullRowSelect = true;
			this->listView1->GridLines = true;
			this->listView1->Location = System::Drawing::Point(0, 0);
			this->listView1->Margin = System::Windows::Forms::Padding(2);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(1352, 607);
			this->listView1->Sorting = System::Windows::Forms::SortOrder::Ascending;
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->VirtualListSize = 8;
			// 
			// clm_Status
			// 
			this->clm_Status->Text = L"Status";
			this->clm_Status->Width = 128;
			// 
			// clm_Name
			// 
			this->clm_Name->Text = L"Name";
			this->clm_Name->Width = 161;
			// 
			// clm_Vorname
			// 
			this->clm_Vorname->Text = L"Vorname";
			this->clm_Vorname->Width = 126;
			// 
			// clm_Personalnummer
			// 
			this->clm_Personalnummer->Text = L"Personalnummer";
			this->clm_Personalnummer->Width = 93;
			// 
			// clm_Abteilung
			// 
			this->clm_Abteilung->Text = L"Abteilung";
			this->clm_Abteilung->Width = 90;
			// 
			// clm_Rolle
			// 
			this->clm_Rolle->Text = L"Rolle";
			this->clm_Rolle->Width = 90;
			// 
			// clm_Urlaubstage
			// 
			this->clm_Urlaubstage->Text = L"Urlaubstage gesamt";
			this->clm_Urlaubstage->Width = 107;
			// 
			// clm_Resturlaub
			// 
			this->clm_Resturlaub->Text = L"Resturlaub";
			this->clm_Resturlaub->Width = 70;
			// 
			// clm_WochenstundenGesamt
			// 
			this->clm_WochenstundenGesamt->Text = L"Wochenstunden gesamt";
			this->clm_WochenstundenGesamt->Width = 129;
			// 
			// clm_WochenstundenRest
			// 
			this->clm_WochenstundenRest->Text = L"Wochenstunden Rest";
			this->clm_WochenstundenRest->Width = 119;
			// 
			// clm_UeberstundenWoche
			// 
			this->clm_UeberstundenWoche->Text = L"Überstunden Woche";
			this->clm_UeberstundenWoche->Width = 122;
			// 
			// clm_UeberstundenGesamt
			// 
			this->clm_UeberstundenGesamt->Text = L"Überstunden gesamt";
			this->clm_UeberstundenGesamt->Width = 113;
			// 
			// PersonalFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1352, 607);
			this->Controls->Add(this->listView1);
			this->DoubleBuffered = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"PersonalFenster";
			this->Text = L"Personal Übersicht";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &PersonalFenster::PersonalFenster_FormClosing);
			this->Load += gcnew System::EventHandler(this, &PersonalFenster::PersonalFenster_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		Unternehmen^ unternehmenAkt;

		public: void setUnternehmen(Unternehmen^ unternehmen) {
					this->unternehmenAkt = unternehmen;
				}
	
			//Items werden geleert
	private:void clear() {
				listView1->Items->Clear();
			}
			 
	private: System::Void PersonalFenster_Load(System::Object^  sender, System::EventArgs^  e) {
		List<Angestellter^>^ angestellte = unternehmenAkt->getAlleAngestellte();
		listView1->Refresh();

		//Der passende Status und die zugehörige Farbe werden gesucht und Item damit befuellt
 		for (int i = 0; i < unternehmenAkt->getAlleAngestellte()->Count; i++) {
				if (unternehmenAkt->getAlleAngestellte() != nullptr) {
					ListViewItem^ item = gcnew ListViewItem();
					item->Clone();
					try {
						if (angestellte[i]->getStatus()->Equals("Viel Erfolg beim Erledigen Ihrer Aufgaben!")) {
							item->Text = "arbeitet..";
							item->BackColor = System::Drawing::Color::SpringGreen;
						}
						else if (angestellte[i]->getStatus()->Equals("Geniessen Sie Ihre Pause!")) {
							item->Text = "in der Pause..";
							item->ForeColor = System::Drawing::Color::Gray;
						}
						else if (angestellte[i]->getStatus()->Equals("Schön, dass Sie da sind!")) {
							item->Text = "anwesend..";
							item->ForeColor = System::Drawing::Color::Black;
						}
						else {
							item->Text = "nicht anwesend..";
							item->ForeColor = System::Drawing::Color::Red;
						}
					}
					catch (NullReferenceException ^) {
						item->Text = "nicht anwesend..";
						item->ForeColor = System::Drawing::Color::Red;
					}

					//Auch alle anderen Items werden befuellt mit den Daten der Angestellten
					String^ arbeitsMinutenString = Convert::ToString(angestellte[i]->getArbeitsMinuten());
					if (angestellte[i]->getArbeitsMinuten() < 10) {
						arbeitsMinutenString = "0" + Convert::ToString(angestellte[i]->getArbeitsMinuten());
					}

					String^ ueberMinutenString = Convert::ToString(angestellte[i]->getUeberMinuten());
					if (angestellte[i]->getUeberMinuten() < 10) {
						ueberMinutenString = "0" + Convert::ToString(angestellte[i]->getUeberMinuten());
					}

					String^ rolle = angestellte[i]->istVorgesetzter() ? "Vorgesetzter" : "Mitarbeiter";

					item->SubItems->Add(angestellte[i]->getNachname());
					item->SubItems->Add(angestellte[i]->getVorname());
					item->SubItems->Add(angestellte[i]->getPersonalnummer());
					item->SubItems->Add(angestellte[i]->getAbteilung()->getAbteilungsnummer());
					item->SubItems->Add(rolle);
					item->SubItems->Add(Convert::ToString(angestellte[i]->getUrlaubstage()));
					item->SubItems->Add(Convert::ToString(angestellte[i]->getRestUrlaub()));
					item->SubItems->Add(Convert::ToString(angestellte[i]->getWochensstunden()));
					item->SubItems->Add(Convert::ToString(angestellte[i]->getArbeitsStunden() + ":" + arbeitsMinutenString));
					item->SubItems->Add(Convert::ToString(angestellte[i]->getUeberStunden()) + ":" + ueberMinutenString);
					item->SubItems->Add(Convert::ToString(angestellte[i]->getUeberstundenGesamt()));
					listView1->Items->Add(item);
			}

		} 
		
	}
	private: System::Void PersonalFenster_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		this->clear();
	}
};
}