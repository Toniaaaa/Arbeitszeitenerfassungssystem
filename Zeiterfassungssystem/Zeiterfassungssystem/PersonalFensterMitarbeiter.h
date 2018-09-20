#pragma once
#include "Angestellter.h"
#include "Unternehmen.h"

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
			this->clm_Status = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_nachname = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Vorname = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->clm_Status, this->clm_nachname,
					this->clm_Vorname
			});
			this->listView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listView1->GridLines = true;
			this->listView1->Location = System::Drawing::Point(0, 0);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(622, 290);
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
			this->clm_Vorname->Width = 133;
			// 
			// PersonalFensterMitarbeiter
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(622, 290);
			this->Controls->Add(this->listView1);
			this->Name = L"PersonalFensterMitarbeiter";
			this->Text = L"PersonalFensterMitarbeiter";
			this->Load += gcnew System::EventHandler(this, &PersonalFensterMitarbeiter::PersonalFensterMitarbeiter_Load_1);
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		Unternehmen ^ unternehmenAkt;

	public: void setUnternehmen(Unternehmen^ unternehmen) {
		this->unternehmenAkt = unternehmen;
	}

	
	private: System::Void PersonalFensterMitarbeiter_Load_1(System::Object^  sender, System::EventArgs^  e) {
		List<Angestellter^>^ angestellte = unternehmenAkt->getAlleAngestellte();
		listView1->Refresh();

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



				item->SubItems->Add(angestellte[i]->getNachname());
				item->SubItems->Add(angestellte[i]->getVorname());
				listView1->Items->Add(item);
			}
		}
	}
};
}
