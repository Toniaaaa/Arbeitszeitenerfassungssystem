#pragma once
#include "Aenderungsantrag.h"
#include "AenderungsantragsFenster.h"

namespace Zeiterfassungssystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Zusammenfassung f�r StatistikFenster
	/// </summary>
	public ref class StatistikFenster : public System::Windows::Forms::Form
	{
	private: 
		AenderungsantragsFenster ^ aenderungsantrag;
	private: System::Windows::Forms::Label^  label;
	private: System::Windows::Forms::Label^  lbl_gesamtstunden;

			 Angestellter^ angestellterAkt;
	public:
		StatistikFenster(void)
		{
			InitializeComponent();
			aenderungsantrag = gcnew AenderungsantragsFenster;
			//
			//TODO: Konstruktorcode hier hinzuf�gen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~StatistikFenster()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	protected:
	private: System::Windows::Forms::Button^  btn_aenderungsanfrage;

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->btn_aenderungsanfrage = (gcnew System::Windows::Forms::Button());
			this->label = (gcnew System::Windows::Forms::Label());
			this->lbl_gesamtstunden = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart1->Legends->Add(legend2);
			this->chart1->Location = System::Drawing::Point(46, 37);
			this->chart1->Name = L"chart1";
			series2->ChartArea = L"ChartArea1";
			series2->IsValueShownAsLabel = true;
			series2->Legend = L"Legend1";
			series2->Name = L"Arbeitsstunden";
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(1340, 316);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// btn_aenderungsanfrage
			// 
			this->btn_aenderungsanfrage->Location = System::Drawing::Point(46, 390);
			this->btn_aenderungsanfrage->Name = L"btn_aenderungsanfrage";
			this->btn_aenderungsanfrage->Size = System::Drawing::Size(250, 58);
			this->btn_aenderungsanfrage->TabIndex = 1;
			this->btn_aenderungsanfrage->Text = L"�nderungsanfrage";
			this->btn_aenderungsanfrage->UseVisualStyleBackColor = true;
			this->btn_aenderungsanfrage->Click += gcnew System::EventHandler(this, &StatistikFenster::btn_aenderungsanfrage_Click);
			// 
			// label
			// 
			this->label->AutoSize = true;
			this->label->Location = System::Drawing::Point(352, 411);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(250, 17);
			this->label->TabIndex = 2;
			this->label->Text = L"Arbeitsstunden diesen Monat gesamt: ";
			// 
			// lbl_gesamtstunden
			// 
			this->lbl_gesamtstunden->AutoSize = true;
			this->lbl_gesamtstunden->Location = System::Drawing::Point(617, 411);
			this->lbl_gesamtstunden->Name = L"lbl_gesamtstunden";
			this->lbl_gesamtstunden->Size = System::Drawing::Size(46, 17);
			this->lbl_gesamtstunden->TabIndex = 3;
			this->lbl_gesamtstunden->Text = L"label1";
			// 
			// StatistikFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1412, 523);
			this->Controls->Add(this->lbl_gesamtstunden);
			this->Controls->Add(this->label);
			this->Controls->Add(this->btn_aenderungsanfrage);
			this->Controls->Add(this->chart1);
			this->Name = L"StatistikFenster";
			this->Text = L"StatistikFenster";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &StatistikFenster::StatistikFenster_FormClosing);
			this->Load += gcnew System::EventHandler(this, &StatistikFenster::StatistikFenster_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void StatistikFenster_Load(System::Object^  sender, System::EventArgs^  e) {
		this->chart1->Series["Arbeitsstunden"]->Points->AddXY("Tag", 8);
		int gesamtstunden = 0;
		for (int i = 0; i < 50; i++) {
			this->chart1->Series["Arbeitsstunden"]->Points->AddXY("Tag " + (i+1), i+1);
			gesamtstunden += i + 1;
		}
		lbl_gesamtstunden->Text = gesamtstunden + "";
	}
	private: System::Void btn_aenderungsanfrage_Click(System::Object^  sender, System::EventArgs^  e) {
		aenderungsantrag->ShowDialog(this);
	}
	public: void setAngestellterAkt(Angestellter^ angestellter) {
		this->angestellterAkt = angestellter;
	}
	private: System::Void StatistikFenster_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		this->chart1->Series["Arbeitsstunden"]->Points->Clear();
	}
};
}