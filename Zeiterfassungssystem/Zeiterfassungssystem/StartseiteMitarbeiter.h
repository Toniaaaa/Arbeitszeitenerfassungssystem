#pragma once
#include <ctime>
namespace Zeiterfassungssystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für StartseiteMitarbeiter
	/// </summary>
	public ref class StartseiteMitarbeiter : public System::Windows::Forms::Form
	{
	public:
		StartseiteMitarbeiter(void)
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
		~StartseiteMitarbeiter()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btn_kommen;
	protected:
	private: System::Windows::Forms::Button^  btn_gehen;
	private: System::Windows::Forms::Button^  btn_pause;
	private: System::Windows::Forms::Label^  lbl_begruessung;
	private: System::Windows::Forms::Label^  lbl_name;
	private: System::Windows::Forms::Label^  lbl_date;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  lbl_time;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(StartseiteMitarbeiter::typeid));
			this->btn_kommen = (gcnew System::Windows::Forms::Button());
			this->btn_gehen = (gcnew System::Windows::Forms::Button());
			this->btn_pause = (gcnew System::Windows::Forms::Button());
			this->lbl_begruessung = (gcnew System::Windows::Forms::Label());
			this->lbl_name = (gcnew System::Windows::Forms::Label());
			this->lbl_date = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lbl_time = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btn_kommen
			// 
			this->btn_kommen->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_kommen.Image")));
			this->btn_kommen->Location = System::Drawing::Point(12, 195);
			this->btn_kommen->Name = L"btn_kommen";
			this->btn_kommen->Size = System::Drawing::Size(269, 126);
			this->btn_kommen->TabIndex = 0;
			this->btn_kommen->UseVisualStyleBackColor = true;
			// 
			// btn_gehen
			// 
			this->btn_gehen->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_gehen.Image")));
			this->btn_gehen->Location = System::Drawing::Point(613, 195);
			this->btn_gehen->Name = L"btn_gehen";
			this->btn_gehen->Size = System::Drawing::Size(269, 126);
			this->btn_gehen->TabIndex = 1;
			this->btn_gehen->UseVisualStyleBackColor = true;
			// 
			// btn_pause
			// 
			this->btn_pause->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_pause.Image")));
			this->btn_pause->Location = System::Drawing::Point(313, 195);
			this->btn_pause->Name = L"btn_pause";
			this->btn_pause->Size = System::Drawing::Size(269, 126);
			this->btn_pause->TabIndex = 2;
			this->btn_pause->UseVisualStyleBackColor = true;
			// 
			// lbl_begruessung
			// 
			this->lbl_begruessung->AutoSize = true;
			this->lbl_begruessung->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_begruessung->Location = System::Drawing::Point(406, 9);
			this->lbl_begruessung->Name = L"lbl_begruessung";
			this->lbl_begruessung->Size = System::Drawing::Size(91, 38);
			this->lbl_begruessung->TabIndex = 3;
			this->lbl_begruessung->Text = L"Hallo";
			this->lbl_begruessung->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbl_name
			// 
			this->lbl_name->AutoSize = true;
			this->lbl_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_name->Location = System::Drawing::Point(262, 47);
			this->lbl_name->Name = L"lbl_name";
			this->lbl_name->Size = System::Drawing::Size(378, 38);
			this->lbl_name->TabIndex = 4;
			this->lbl_name->Text = L"Anzeige Mitarbeitername";
			this->lbl_name->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbl_date
			// 
			this->lbl_date->AutoSize = true;
			this->lbl_date->Location = System::Drawing::Point(802, 9);
			this->lbl_date->Name = L"lbl_date";
			this->lbl_date->Size = System::Drawing::Size(80, 17);
			this->lbl_date->TabIndex = 5;
			this->lbl_date->Text = L"01.01.2000";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &StartseiteMitarbeiter::timer1_Tick);
			// 
			// lbl_time
			// 
			this->lbl_time->AutoSize = true;
			this->lbl_time->Location = System::Drawing::Point(804, 34);
			this->lbl_time->Name = L"lbl_time";
			this->lbl_time->Size = System::Drawing::Size(64, 17);
			this->lbl_time->TabIndex = 6;
			this->lbl_time->Text = L"00:00:00";
			// 
			// StartseiteMitarbeiter
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(894, 503);
			this->Controls->Add(this->lbl_time);
			this->Controls->Add(this->lbl_date);
			this->Controls->Add(this->lbl_name);
			this->Controls->Add(this->lbl_begruessung);
			this->Controls->Add(this->btn_pause);
			this->Controls->Add(this->btn_gehen);
			this->Controls->Add(this->btn_kommen);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"StartseiteMitarbeiter";
			this->Text = L"Deine Startseite";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	timer1->Start();
	lbl_date->Text = DateTime::Now.ToLongDateString();
	lbl_time->Text = DateTime::Now.ToLongTimeString();
}
};
}
