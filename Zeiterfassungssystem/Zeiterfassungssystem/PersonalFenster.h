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
			System::Windows::Forms::ListViewItem^  listViewItem1 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3) {
				L"",
					L"", L""
			}, -1));
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->clm_Name = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Vorname = (gcnew System::Windows::Forms::ColumnHeader());
			this->clm_Abteilung = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->clm_Name, this->clm_Vorname,
					this->clm_Abteilung
			});
			this->listView1->Dock = System::Windows::Forms::DockStyle::Fill;
			listViewItem1->IndentCount = 8;
			this->listView1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(1) { listViewItem1 });
			this->listView1->Location = System::Drawing::Point(0, 0);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(493, 403);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
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
			// clm_Abteilung
			// 
			this->clm_Abteilung->Text = L"Abteilung";
			this->clm_Abteilung->Width = 149;
			// 
			// PersonalFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(493, 403);
			this->Controls->Add(this->listView1);
			this->Name = L"PersonalFenster";
			this->Text = L"PersonalFenster";
			this->Load += gcnew System::EventHandler(this, &PersonalFenster::PersonalFenster_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		Unternehmen^ unternehmen;
	/*	public:
			void setUnternehmen(Unternehmen^ unternehmen) {
				this->unternehmen = unternehmen;
			}
	*/	
			 
	private: System::Void PersonalFenster_Load(System::Object^  sender, System::EventArgs^  e) {
		ListViewItem^ item = gcnew ListViewItem();
		/*List<Angestellter^>^ angestellte = unternehmen->getAlleAngestellte();
		
 		for (int i = 0; i < unternehmen->getAlleAngestellte()->Count; i++) {
			if (unternehmen->getAlleAngestellte() != nullptr) {
				item->Text = angestellte[i]->getNachname();
				item->SubItems->Add(angestellte[i]->getVorname());
				item->SubItems->Add(angestellte[i]->getPersonalnummer());
				listView1->Items->Add(item);

			}

		} */
	}
};
}
