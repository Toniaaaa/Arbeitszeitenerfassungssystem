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
	/// Zusammenfassung für StatistikFenster
	/// </summary>
	public ref class StatistikFenster : public System::Windows::Forms::Form
	{
	private: 
		AenderungsantragsFenster ^ aenderungsantrag;
		Angestellter^ angestellterAkt;
	public:
		StatistikFenster(void)
		{
			InitializeComponent();
			aenderungsantrag = gcnew AenderungsantragsFenster;
			//
			//TODO: Konstruktorcode hier hinzufügen.
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
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->btn_aenderungsanfrage = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(46, 37);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->IsValueShownAsLabel = true;
			series1->Legend = L"Legend1";
			series1->Name = L"Arbeitsstunden";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(568, 316);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// btn_aenderungsanfrage
			// 
			this->btn_aenderungsanfrage->Location = System::Drawing::Point(353, 389);
			this->btn_aenderungsanfrage->Name = L"btn_aenderungsanfrage";
			this->btn_aenderungsanfrage->Size = System::Drawing::Size(250, 58);
			this->btn_aenderungsanfrage->TabIndex = 1;
			this->btn_aenderungsanfrage->Text = L"Änderungsanfrage";
			this->btn_aenderungsanfrage->UseVisualStyleBackColor = true;
			this->btn_aenderungsanfrage->Click += gcnew System::EventHandler(this, &StatistikFenster::btn_aenderungsanfrage_Click);
			// 
			// StatistikFenster
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(642, 523);
			this->Controls->Add(this->btn_aenderungsanfrage);
			this->Controls->Add(this->chart1);
			this->Name = L"StatistikFenster";
			this->Text = L"StatistikFenster";
			this->Load += gcnew System::EventHandler(this, &StatistikFenster::StatistikFenster_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void StatistikFenster_Load(System::Object^  sender, System::EventArgs^  e) {
		this->chart1->Series["Arbeitsstunden"]->Points->AddXY("Tag", 8);
		for (int i = 0; i < angestellterAkt->getAnzahlArbeitstage(); i++) {
			this->chart1->Series["Arbeitsstunden"]->Points->AddXY("Tag" + i, i);
		}

	}
	private: System::Void btn_aenderungsanfrage_Click(System::Object^  sender, System::EventArgs^  e) {
		aenderungsantrag->ShowDialog(this);
	}
	public: void setAngestellterAkt(Angestellter^ angestellter) {
		this->angestellterAkt = angestellter;
	}
	};
}
