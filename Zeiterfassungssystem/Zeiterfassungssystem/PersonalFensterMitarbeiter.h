#pragma once
#include "Angestellter.h"
#include "Unternehmen.h"
#include "Abteilung.h"

namespace Zeiterfassungssystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für PersonalFensterMitarbeiter
	/// </summary>
	public ref class PersonalFensterMitarbeiter : public System::Windows::Forms::Form
	{
	public:
		PersonalFensterMitarbeiter(void)
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
		~PersonalFensterMitarbeiter()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^  listView1;
	protected:
	private: System::Windows::Forms::ColumnHeader^  clm_Status;
	private: System::Windows::Forms::ColumnHeader^  clm_nachname;
	private: System::Windows::Forms::ColumnHeader^  clm_Vorname;
	private: System::Windows::Forms::ColumnHeader^  clm_Abteilung;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PersonalFensterMitarbeiter::typeid));
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->clm_Status = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_nachname = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Vorname = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Abteilung = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->clm_Status, this->clm_nachname,
					this->clm_Vorname, this->clm_Abteilung
			});
			this->listView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listView1->FullRowSelect = true;
			this->listView1->GridLines = true;
			this->listView1->Location = System::Drawing::Point(0, 0);
			this->listView1->Margin = System::Windows::Forms::Padding(2);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(620, 274);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// clm_Status
			// 
			this->clm_Status->Text = L"Status";
			this->clm_Status->Width = 135;
			// 
			// clm_nachname
			// 
			this->clm_nachname->Text = L"Nachname";
			this->clm_nachname->Width = 163;
			// 
			// clm_Vorname
			// 
			this->clm_Vorname->Text = L"Vorname";
			this->clm_Vorname->Width = 166;
			// 
			// clm_Abteilung
			// 
			this->clm_Abteilung->Text = L"Abteilung";
			this->clm_Abteilung->Width = 152;
			// 
			// PersonalFensterMitarbeiter
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(620, 274);
			this->Controls->Add(this->listView1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"PersonalFensterMitarbeiter";
			this->Text = L"PersonalFensterMitarbeiter";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &PersonalFensterMitarbeiter::PersonalFensterMitarbeiter_FormClosing);
			this->Load += gcnew System::EventHandler(this, &PersonalFensterMitarbeiter::PersonalFensterMitarbeiter_Load_1);
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		Unternehmen ^ unternehmenAkt;

	public: void setUnternehmen(Unternehmen^ unternehmen) {
		this->unternehmenAkt = unternehmen;
	}

	public: void clear() {
		listView1->Items->Clear();
	}

	private: System::Void PersonalFensterMitarbeiter_Load_1(System::Object^  sender, System::EventArgs^  e) {
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
				catch (NullReferenceException ^e) {
					item->Text = "nicht anwesend..";
					item->ForeColor = System::Drawing::Color::Red;
				}

				//Auch der Name, Vorname und Abteilung wird befüllt
				item->SubItems->Add(angestellte[i]->getNachname());
				item->SubItems->Add(angestellte[i]->getVorname());
				item->SubItems->Add(angestellte[i]->getAbteilung()->getAbteilungsnummer());
				listView1->Items->Add(item);
			}
		}
	}

	private: System::Void PersonalFensterMitarbeiter_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		this->clear();
	}
};
}
