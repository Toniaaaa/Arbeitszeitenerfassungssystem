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
	/// Zusammenfassung f�r PersonalFenster
	/// </summary>
	public ref class PersonalFenster : public System::Windows::Forms::Form
	{

	public:
		PersonalFenster(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzuf�gen.
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
	private: System::Windows::Forms::ColumnHeader^  clm_Urlaubstage;
	private: System::Windows::Forms::ColumnHeader^  clm_Resturlaub;
	private: System::Windows::Forms::ColumnHeader^  clm_WochenstundenGesamt;
	private: System::Windows::Forms::ColumnHeader^  clm_WochenstundenRest;


	private: System::Windows::Forms::ColumnHeader^  clm_UeberstundenWoche;
	private: System::Windows::Forms::ColumnHeader^  clm_UeberstundenGesamt;
	protected:









	protected:

	protected:

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
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->clm_Status = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Name = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Vorname = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Personalnummer = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Abteilung = (gcnew System::Windows::Forms::ColumnHeader());
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
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(11) {
				this->clm_Status, this->clm_Name,
					this->clm_Vorname, this->clm_Personalnummer, this->clm_Abteilung, this->clm_Urlaubstage, this->clm_Resturlaub, this->clm_WochenstundenGesamt,
					this->clm_WochenstundenRest, this->clm_UeberstundenWoche, this->clm_UeberstundenGesamt
			});
			this->listView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listView1->FullRowSelect = true;
			this->listView1->GridLines = true;
			this->listView1->Location = System::Drawing::Point(0, 0);
			this->listView1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(1485, 679);
			this->listView1->Sorting = System::Windows::Forms::SortOrder::Ascending;
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->VirtualListSize = 8;
			// 
			// clm_Status
			// 
			this->clm_Status->Text = L"Status";
			this->clm_Status->Width = 150;
			// 
			// clm_Name
			// 
			this->clm_Name->Text = L"Name";
			this->clm_Name->Width = 184;
			// 
			// clm_Vorname
			// 
			this->clm_Vorname->Text = L"Vorname";
			this->clm_Vorname->Width = 149;
			// 
			// clm_Personalnummer
			// 
			this->clm_Personalnummer->Text = L"Personalnummer";
			this->clm_Personalnummer->Width = 141;
			// 
			// clm_Abteilung
			// 
			this->clm_Abteilung->Text = L"Abteilung";
			this->clm_Abteilung->Width = 75;
			// 
			// clm_Urlaubstage
			// 
			this->clm_Urlaubstage->Text = L"Urlaubstage gesamt";
			this->clm_Urlaubstage->Width = 135;
			// 
			// clm_Resturlaub
			// 
			this->clm_Resturlaub->Text = L"Resturlaub";
			this->clm_Resturlaub->Width = 82;
			// 
			// clm_WochenstundenGesamt
			// 
			this->clm_WochenstundenGesamt->Text = L"Wochenstunden gesamt";
			this->clm_WochenstundenGesamt->Width = 140;
			// 
			// clm_WochenstundenRest
			// 
			this->clm_WochenstundenRest->Text = L"Wochenstunden Rest";
			this->clm_WochenstundenRest->Width = 155;
			// 
			// clm_UeberstundenWoche
			// 
			this->clm_UeberstundenWoche->Text = L"�berstunden Woche";
			this->clm_UeberstundenWoche->Width = 139;
			// 
			// clm_UeberstundenGesamt
			// 
			this->clm_UeberstundenGesamt->Text = L"�berstunden gesamt";
			this->clm_UeberstundenGesamt->Width = 137;
			// 
			// PersonalFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1485, 679);
			this->Controls->Add(this->listView1);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"PersonalFenster";
			this->Text = L"PersonalFenster";
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
	
	private: System::Void PersonalFenster_Load(System::Object^  sender, System::EventArgs^  e) {
		List<Angestellter^>^ angestellte = unternehmenAkt->getAlleAngestellte();
		listView1->Refresh();

 		for (int i = 0; i < unternehmenAkt->getAlleAngestellte()->Count; i++) {
				if (unternehmenAkt->getAlleAngestellte() != nullptr) {
					ListViewItem^ item = gcnew ListViewItem();
					item->Clone();
					if (angestellte[i]->getStatus()->Equals("Viel Erfolg beim Erledigen Ihrer Aufgaben!")) {
						item->Text = "arbeitet..";
					}
					else if (angestellte[i]->getStatus()->Equals("Geniessen Sie Ihre Pause!")) {
						item->Text = "in der Pause..";
					}
					else if (angestellte[i]->getStatus()->Equals("Sch�n, dass Sie da sind!")) {
						item->Text = "anwesend..";
					}
					else {
						item->Text = "nicht anwesend..";
					}
					
					item->SubItems->Add(angestellte[i]->getNachname());
					item->SubItems->Add(angestellte[i]->getVorname());
					item->SubItems->Add(angestellte[i]->getPersonalnummer());
					item->SubItems->Add(angestellte[i]->getAbteilung()->getAbteilungsnummer());
					item->SubItems->Add(Convert::ToString(angestellte[i]->getUrlaubstage()));
					item->SubItems->Add(Convert::ToString(angestellte[i]->getRestUrlaub()));
					item->SubItems->Add(Convert::ToString(angestellte[i]->getWochensstunden()));
					item->SubItems->Add(Convert::ToString(angestellte[i]->getArbeitsStunden() + ":" + angestellte[i]->getArbeitsMinuten()));
					item->SubItems->Add(Convert::ToString(angestellte[i]->getUeberstundenGesamt()));
					item->SubItems->Add(Convert::ToString(angestellte[i]->getUeberStunden()) + ":" + Convert::ToString(angestellte[i]->getUeberMinuten()));
					listView1->Items->Add(item);

			

			}

		} 
		
	}
			 
private: System::Void PersonalFenster_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	
}
			 
};
}
