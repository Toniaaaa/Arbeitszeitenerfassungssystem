#pragma once

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
	public:
		StundenStatistikFenster(void)
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
		~StundenStatistikFenster()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^  listView1;
	protected:
	private: System::Windows::Forms::ColumnHeader^  clm_Arbeitsang;
	private: System::Windows::Forms::ColumnHeader^  clm_pausenanfang;
	private: System::Windows::Forms::ColumnHeader^  clm_Pausenende;
	private: System::Windows::Forms::ColumnHeader^  clm_Arbeitsende;

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
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->clm_Arbeitsang, this->clm_pausenanfang,
					this->clm_Pausenende, this->clm_Arbeitsende
			});
			this->listView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listView1->GridLines = true;
			this->listView1->Location = System::Drawing::Point(0, 0);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(955, 518);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
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
			this->clm_Arbeitsende->Width = 399;
			// 
			// StundenStatistikFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(955, 518);
			this->Controls->Add(this->listView1);
			this->Name = L"StundenStatistikFenster";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"StundenStatistikFenster";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
