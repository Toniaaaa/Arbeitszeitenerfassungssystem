#pragma once
#include "Angestellter.h"
#include "Abteilung.h"
#include "Mitarbeiter.h"
#include "Unternehmen.h"

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
	protected:
	private: System::Windows::Forms::ColumnHeader^  clm_Name;
	private: System::Windows::Forms::ColumnHeader^  clm_Vorname;
	private: System::Windows::Forms::ColumnHeader^  clm_Personalnummer;
	private: System::Windows::Forms::ColumnHeader^  clm_Abteilung;





	protected:

	protected:

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
			this->clm_Name = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Vorname = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Personalnummer = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Abteilung = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->clm_Name, this->clm_Vorname,
					this->clm_Personalnummer, this->clm_Abteilung
			});
			this->listView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listView1->FullRowSelect = true;
			this->listView1->GridLines = true;
			this->listView1->Location = System::Drawing::Point(0, 0);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(493, 403);
			this->listView1->Sorting = System::Windows::Forms::SortOrder::Ascending;
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->VirtualListSize = 8;
			// 
			// clm_Name
			// 
			this->clm_Name->Text = L"Name";
			this->clm_Name->Width = 150;
			// 
			// clm_Vorname
			// 
			this->clm_Vorname->Text = L"Vorname";
			this->clm_Vorname->Width = 184;
			// 
			// clm_Personalnummer
			// 
			this->clm_Personalnummer->Text = L"Personalnummer";
			this->clm_Personalnummer->Width = 149;
			// 
			// clm_Abteilung
			// 
			this->clm_Abteilung->Text = L"Abteilung";
			// 
			// PersonalFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(493, 403);
			this->Controls->Add(this->listView1);
			this->DoubleBuffered = true;
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

 		for (int i = 0; i < unternehmenAkt->getAlleAngestellte()->Count; i++) {
			if (unternehmenAkt->getAlleAngestellte() != nullptr) {
				ListViewItem^ item = gcnew ListViewItem();
				item->Clone();
				item->Text = angestellte[i]->getNachname();
				item->SubItems->Add(angestellte[i]->getVorname());
				item->SubItems->Add(angestellte[i]->getPersonalnummer());
				item->SubItems->Add(angestellte[i]->getAbteilung()->getAbteilungsnummer());
				listView1->Items->Add(item);

			}

		} 
		
	}
			 
private: System::Void PersonalFenster_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	//listView1->Clear();
}
			 
};
}
