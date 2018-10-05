#pragma once
#include "RegistrierungsFenster.h"
#include "Unternehmen.h"

namespace Zeiterfassungssystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	/// <summary>
	/// Zusammenfassung für BegruessungsFenster
	/// </summary>
	public ref class BegruessungsFenster : public System::Windows::Forms::Form
	{
	private:
		RegistrierungsFenster^ regFenster;
	private: System::Windows::Forms::Label^  begruessungLbl1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

			 Unternehmen^ unternehmen;

	public:
		BegruessungsFenster(void)
		{
			InitializeComponent();
			regFenster = gcnew RegistrierungsFenster;
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~BegruessungsFenster()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  addBtn;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(BegruessungsFenster::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->addBtn = (gcnew System::Windows::Forms::Button());
			this->begruessungLbl1 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(49, 456);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(205, 100);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Anleitung";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &BegruessungsFenster::button1_Click);
			// 
			// addBtn
			// 
			this->addBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addBtn->Location = System::Drawing::Point(434, 456);
			this->addBtn->Name = L"addBtn";
			this->addBtn->Size = System::Drawing::Size(205, 100);
			this->addBtn->TabIndex = 1;
			this->addBtn->Text = L"Administrator registrieren";
			this->addBtn->UseVisualStyleBackColor = true;
			this->addBtn->Click += gcnew System::EventHandler(this, &BegruessungsFenster::addBtn_Click);
			// 
			// begruessungLbl1
			// 
			this->begruessungLbl1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->begruessungLbl1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->begruessungLbl1->Location = System::Drawing::Point(-1, 53);
			this->begruessungLbl1->Name = L"begruessungLbl1";
			this->begruessungLbl1->Size = System::Drawing::Size(693, 45);
			this->begruessungLbl1->TabIndex = 2;
			this->begruessungLbl1->Text = L"Herzlich Willkommen";
			this->begruessungLbl1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(-1, 368);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(693, 59);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Sie starten das Programm zum ersten Mal. Sie können sich hier mit der Anleitung v"
				L"ertraut machen und den ersten Nutzer hinzufügen.";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(171, 110);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(337, 235);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// BegruessungsFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(693, 574);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->begruessungLbl1);
			this->Controls->Add(this->addBtn);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"BegruessungsFenster";
			this->Text = L"Begrüßung";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	//Öffnen des Benutzerhandbuches
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		try {
			Diagnostics::ProcessStartInfo^ startInfo = gcnew Diagnostics::ProcessStartInfo("BenutzerhandbuchTimeUp.pdf");
			Diagnostics::Process::Start(startInfo);
		}
		catch (System::IO::FileNotFoundException ^e) {
			MessageBox::Show("Das Benutzerhandbuch konnte leider nicht gefunden werden.\nBitte wenden Sie sich an Ihren Administrator!", "Datei nicht gefunden",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	//Öffnen des Registrierungsfensters
	private: System::Void addBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		regFenster->setUnternehmen(unternehmen);
		regFenster->ShowDialog(this);
		this->Close();
	}
		
	//Setter für das Unternehmen
	public: void setUnternehmen(Unternehmen^ unternehmen) {
		this->unternehmen = unternehmen;
	}

	};
}
