#pragma once

#include <ctime>
#include "Statistikfenster.h"
#include "Vorgesetzter.h"
#include "Unternehmen.h"
#include "RegistrierungsFenster.h"
#include "Ereignis.h"
#include "UrlaubsbearbeitungsFenster.h"



namespace Zeiterfassungssystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Globalization;
	//zum lesen und schreiben
	using namespace System::Runtime::Serialization::Formatters::Binary;
	using namespace System::IO;

	/// <summary>
	/// Zusammenfassung für VorgesetztenSeite
	/// </summary>
	public ref class StartseiteVorgesetzte : public System::Windows::Forms::Form
	{
	private:
		Unternehmen ^ unternehmen;
		Angestellter^ angestellterAkt;
		RegistrierungsFenster^ registrierungsfenster;
		Vorgesetzter^ vorgesetzter;
		StatistikFenster^ statistikfenster;
		UrlaubsanfragenbearbeitungsFenster^ urlaubsbearbeitungsfenster;


	private: System::Windows::Forms::Timer^  timerUhr;
	private: System::Windows::Forms::Label^  datumLbl;
	private: System::Windows::Forms::Label^  arbeitszeitSchriftLbl;
	private: System::Windows::Forms::Label^  resturlaubSchriftLbl;
	private: System::Windows::Forms::Label^  PausenSchriftLbl;
	private: System::Windows::Forms::Label^  nochWochenstundenSchriftLbl;
	private: System::Windows::Forms::Button^  statistikBtn;
	private: System::Windows::Forms::Button^  urlaubBtn;
	private: System::Windows::Forms::Button^  kalenderBtn;
	private: System::Windows::Forms::Label^  nochWochenstundenLbl;
	private: System::Windows::Forms::Label^  pauseLbl;
	private: System::Windows::Forms::Label^  resturlaubLbl;
	private: System::Windows::Forms::CheckBox^  pauseCbox;
	private: System::Windows::Forms::Timer^  timerPause;
	private: System::Windows::Forms::Button^  addBtn;
	private: System::Windows::Forms::Button^  editBtn;
	private: System::Windows::Forms::Button^  personalBtn;
	private: System::Windows::Forms::Label^  uhrzeitLbl;

	public:
		StartseiteVorgesetzte(void)
		{
			InitializeComponent();
			registrierungsfenster = gcnew RegistrierungsFenster;
			statistikfenster = gcnew StatistikFenster;
			urlaubsbearbeitungsfenster = gcnew UrlaubsanfragenbearbeitungsFenster;
			
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~StartseiteVorgesetzte()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  kommenBtn;
	private: System::Windows::Forms::Button^  gehenBtn;
	private: System::Windows::Forms::Label^  halloLbl;
	private: System::Windows::Forms::Label^  nameLbl;
	private: System::Windows::Forms::Timer^  timerArbeitszeit;
	private: System::Windows::Forms::Label^  arbeitszeitLbl;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(StartseiteVorgesetzte::typeid));
			this->kommenBtn = (gcnew System::Windows::Forms::Button());
			this->gehenBtn = (gcnew System::Windows::Forms::Button());
			this->halloLbl = (gcnew System::Windows::Forms::Label());
			this->nameLbl = (gcnew System::Windows::Forms::Label());
			this->timerArbeitszeit = (gcnew System::Windows::Forms::Timer(this->components));
			this->arbeitszeitLbl = (gcnew System::Windows::Forms::Label());
			this->timerUhr = (gcnew System::Windows::Forms::Timer(this->components));
			this->uhrzeitLbl = (gcnew System::Windows::Forms::Label());
			this->datumLbl = (gcnew System::Windows::Forms::Label());
			this->arbeitszeitSchriftLbl = (gcnew System::Windows::Forms::Label());
			this->resturlaubSchriftLbl = (gcnew System::Windows::Forms::Label());
			this->PausenSchriftLbl = (gcnew System::Windows::Forms::Label());
			this->nochWochenstundenSchriftLbl = (gcnew System::Windows::Forms::Label());
			this->statistikBtn = (gcnew System::Windows::Forms::Button());
			this->urlaubBtn = (gcnew System::Windows::Forms::Button());
			this->kalenderBtn = (gcnew System::Windows::Forms::Button());
			this->nochWochenstundenLbl = (gcnew System::Windows::Forms::Label());
			this->pauseLbl = (gcnew System::Windows::Forms::Label());
			this->resturlaubLbl = (gcnew System::Windows::Forms::Label());
			this->pauseCbox = (gcnew System::Windows::Forms::CheckBox());
			this->timerPause = (gcnew System::Windows::Forms::Timer(this->components));
			this->addBtn = (gcnew System::Windows::Forms::Button());
			this->editBtn = (gcnew System::Windows::Forms::Button());
			this->personalBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// kommenBtn
			// 
			this->kommenBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->kommenBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"kommenBtn.Image")));
			this->kommenBtn->Location = System::Drawing::Point(47, 335);
			this->kommenBtn->Margin = System::Windows::Forms::Padding(4);
			this->kommenBtn->Name = L"kommenBtn";
			this->kommenBtn->Size = System::Drawing::Size(267, 160);
			this->kommenBtn->TabIndex = 0;
			this->kommenBtn->UseVisualStyleBackColor = true;
			this->kommenBtn->Click += gcnew System::EventHandler(this, &StartseiteVorgesetzte::kommenBtn_Click);
			// 
			// gehenBtn
			// 
			this->gehenBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->gehenBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gehenBtn.Image")));
			this->gehenBtn->Location = System::Drawing::Point(773, 335);
			this->gehenBtn->Margin = System::Windows::Forms::Padding(4);
			this->gehenBtn->Name = L"gehenBtn";
			this->gehenBtn->Size = System::Drawing::Size(267, 160);
			this->gehenBtn->TabIndex = 1;
			this->gehenBtn->UseVisualStyleBackColor = true;
			this->gehenBtn->Click += gcnew System::EventHandler(this, &StartseiteVorgesetzte::gehenBtn_Click);
			// 
			// halloLbl
			// 
			this->halloLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->halloLbl->AutoSize = true;
			this->halloLbl->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->halloLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->halloLbl->Location = System::Drawing::Point(484, 25);
			this->halloLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->halloLbl->Name = L"halloLbl";
			this->halloLbl->Size = System::Drawing::Size(101, 39);
			this->halloLbl->TabIndex = 3;
			this->halloLbl->Text = L"Hallo";
			this->halloLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// nameLbl
			// 
			this->nameLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->nameLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nameLbl->Location = System::Drawing::Point(7, 81);
			this->nameLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->nameLbl->Name = L"nameLbl";
			this->nameLbl->Size = System::Drawing::Size(1097, 57);
			this->nameLbl->TabIndex = 4;
			this->nameLbl->Text = L"Beispiel-Name eines MA";
			this->nameLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timerArbeitszeit
			// 
			this->timerArbeitszeit->Interval = 1000;
			this->timerArbeitszeit->Tick += gcnew System::EventHandler(this, &StartseiteVorgesetzte::timerArbeitszeit_Tick);
			// 
			// arbeitszeitLbl
			// 
			this->arbeitszeitLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->arbeitszeitLbl->AutoSize = true;
			this->arbeitszeitLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->arbeitszeitLbl->ForeColor = System::Drawing::Color::Red;
			this->arbeitszeitLbl->Location = System::Drawing::Point(401, 549);
			this->arbeitszeitLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->arbeitszeitLbl->Name = L"arbeitszeitLbl";
			this->arbeitszeitLbl->Size = System::Drawing::Size(262, 69);
			this->arbeitszeitLbl->TabIndex = 5;
			this->arbeitszeitLbl->Text = L"00:00:00";
			this->arbeitszeitLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timerUhr
			// 
			this->timerUhr->Enabled = true;
			this->timerUhr->Interval = 1000;
			this->timerUhr->Tick += gcnew System::EventHandler(this, &StartseiteVorgesetzte::timerUhr_Tick);
			// 
			// uhrzeitLbl
			// 
			this->uhrzeitLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->uhrzeitLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 56));
			this->uhrzeitLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->uhrzeitLbl->Location = System::Drawing::Point(1, 217);
			this->uhrzeitLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->uhrzeitLbl->Name = L"uhrzeitLbl";
			this->uhrzeitLbl->Size = System::Drawing::Size(1103, 114);
			this->uhrzeitLbl->TabIndex = 6;
			this->uhrzeitLbl->Text = L"00:00:00";
			this->uhrzeitLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// datumLbl
			// 
			this->datumLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->datumLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->datumLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->datumLbl->Location = System::Drawing::Point(4, 155);
			this->datumLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->datumLbl->Name = L"datumLbl";
			this->datumLbl->Size = System::Drawing::Size(1100, 62);
			this->datumLbl->TabIndex = 7;
			this->datumLbl->Text = L"1. Januar 1900";
			this->datumLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// arbeitszeitSchriftLbl
			// 
			this->arbeitszeitSchriftLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->arbeitszeitSchriftLbl->AutoSize = true;
			this->arbeitszeitSchriftLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->arbeitszeitSchriftLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->arbeitszeitSchriftLbl->Location = System::Drawing::Point(397, 500);
			this->arbeitszeitSchriftLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->arbeitszeitSchriftLbl->Name = L"arbeitszeitSchriftLbl";
			this->arbeitszeitSchriftLbl->Size = System::Drawing::Size(267, 39);
			this->arbeitszeitSchriftLbl->TabIndex = 8;
			this->arbeitszeitSchriftLbl->Text = L"Tagesarbeitszeit";
			// 
			// resturlaubSchriftLbl
			// 
			this->resturlaubSchriftLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->resturlaubSchriftLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->resturlaubSchriftLbl->ForeColor = System::Drawing::SystemColors::ControlText;
			this->resturlaubSchriftLbl->Location = System::Drawing::Point(773, 892);
			this->resturlaubSchriftLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->resturlaubSchriftLbl->Name = L"resturlaubSchriftLbl";
			this->resturlaubSchriftLbl->Size = System::Drawing::Size(313, 31);
			this->resturlaubSchriftLbl->TabIndex = 9;
			this->resturlaubSchriftLbl->Text = L"Resturlaub";
			this->resturlaubSchriftLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// PausenSchriftLbl
			// 
			this->PausenSchriftLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->PausenSchriftLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->PausenSchriftLbl->ForeColor = System::Drawing::SystemColors::ControlText;
			this->PausenSchriftLbl->Location = System::Drawing::Point(396, 892);
			this->PausenSchriftLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->PausenSchriftLbl->Name = L"PausenSchriftLbl";
			this->PausenSchriftLbl->Size = System::Drawing::Size(313, 31);
			this->PausenSchriftLbl->TabIndex = 10;
			this->PausenSchriftLbl->Text = L"Pause heute";
			this->PausenSchriftLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// nochWochenstundenSchriftLbl
			// 
			this->nochWochenstundenSchriftLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->nochWochenstundenSchriftLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->nochWochenstundenSchriftLbl->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->nochWochenstundenSchriftLbl->Location = System::Drawing::Point(19, 892);
			this->nochWochenstundenSchriftLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->nochWochenstundenSchriftLbl->Name = L"nochWochenstundenSchriftLbl";
			this->nochWochenstundenSchriftLbl->Size = System::Drawing::Size(316, 31);
			this->nochWochenstundenSchriftLbl->TabIndex = 11;
			this->nochWochenstundenSchriftLbl->Text = L"Übrige Wochenstunden";
			this->nochWochenstundenSchriftLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// statistikBtn
			// 
			this->statistikBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->statistikBtn->BackColor = System::Drawing::SystemColors::HighlightText;
			this->statistikBtn->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->statistikBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->statistikBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"statistikBtn.Image")));
			this->statistikBtn->Location = System::Drawing::Point(17, 658);
			this->statistikBtn->Margin = System::Windows::Forms::Padding(4);
			this->statistikBtn->Name = L"statistikBtn";
			this->statistikBtn->Size = System::Drawing::Size(313, 94);
			this->statistikBtn->TabIndex = 12;
			this->statistikBtn->UseVisualStyleBackColor = false;
			this->statistikBtn->Click += gcnew System::EventHandler(this, &StartseiteVorgesetzte::statistikBtn_Click);
			// 
			// urlaubBtn
			// 
			this->urlaubBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->urlaubBtn->BackColor = System::Drawing::SystemColors::HighlightText;
			this->urlaubBtn->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->urlaubBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->urlaubBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"urlaubBtn.Image")));
			this->urlaubBtn->Location = System::Drawing::Point(773, 658);
			this->urlaubBtn->Margin = System::Windows::Forms::Padding(4);
			this->urlaubBtn->Name = L"urlaubBtn";
			this->urlaubBtn->Size = System::Drawing::Size(313, 94);
			this->urlaubBtn->TabIndex = 13;
			this->urlaubBtn->UseVisualStyleBackColor = false;
			this->urlaubBtn->Click += gcnew System::EventHandler(this, &StartseiteVorgesetzte::urlaubBtn_Click);
			// 
			// kalenderBtn
			// 
			this->kalenderBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->kalenderBtn->BackColor = System::Drawing::SystemColors::HighlightText;
			this->kalenderBtn->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->kalenderBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->kalenderBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"kalenderBtn.Image")));
			this->kalenderBtn->Location = System::Drawing::Point(396, 658);
			this->kalenderBtn->Margin = System::Windows::Forms::Padding(4);
			this->kalenderBtn->Name = L"kalenderBtn";
			this->kalenderBtn->Size = System::Drawing::Size(313, 94);
			this->kalenderBtn->TabIndex = 14;
			this->kalenderBtn->UseVisualStyleBackColor = false;
			this->kalenderBtn->Click += gcnew System::EventHandler(this, &StartseiteVorgesetzte::kalenderBtn_Click);
			// 
			// nochWochenstundenLbl
			// 
			this->nochWochenstundenLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->nochWochenstundenLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->nochWochenstundenLbl->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->nochWochenstundenLbl->Location = System::Drawing::Point(8, 923);
			this->nochWochenstundenLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->nochWochenstundenLbl->Name = L"nochWochenstundenLbl";
			this->nochWochenstundenLbl->Size = System::Drawing::Size(333, 62);
			this->nochWochenstundenLbl->TabIndex = 15;
			this->nochWochenstundenLbl->Text = L"00:00 Stunden";
			this->nochWochenstundenLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pauseLbl
			// 
			this->pauseLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pauseLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pauseLbl->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pauseLbl->Location = System::Drawing::Point(361, 923);
			this->pauseLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->pauseLbl->Name = L"pauseLbl";
			this->pauseLbl->Size = System::Drawing::Size(360, 62);
			this->pauseLbl->TabIndex = 16;
			this->pauseLbl->Text = L"0:00:00 Stunden";
			this->pauseLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// resturlaubLbl
			// 
			this->resturlaubLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->resturlaubLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resturlaubLbl->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->resturlaubLbl->Location = System::Drawing::Point(743, 923);
			this->resturlaubLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->resturlaubLbl->Name = L"resturlaubLbl";
			this->resturlaubLbl->Size = System::Drawing::Size(344, 62);
			this->resturlaubLbl->TabIndex = 17;
			this->resturlaubLbl->Text = L"0 Tage";
			this->resturlaubLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pauseCbox
			// 
			this->pauseCbox->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pauseCbox->Appearance = System::Windows::Forms::Appearance::Button;
			this->pauseCbox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pauseCbox.Image")));
			this->pauseCbox->Location = System::Drawing::Point(384, 366);
			this->pauseCbox->Margin = System::Windows::Forms::Padding(4);
			this->pauseCbox->Name = L"pauseCbox";
			this->pauseCbox->Size = System::Drawing::Size(320, 98);
			this->pauseCbox->TabIndex = 18;
			this->pauseCbox->UseVisualStyleBackColor = true;
			this->pauseCbox->CheckedChanged += gcnew System::EventHandler(this, &StartseiteVorgesetzte::pauseCbox_CheckedChanged);
			// 
			// timerPause
			// 
			this->timerPause->Interval = 1000;
			this->timerPause->Tick += gcnew System::EventHandler(this, &StartseiteVorgesetzte::timerPause_Tick);
			// 
			// addBtn
			// 
			this->addBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->addBtn->BackColor = System::Drawing::SystemColors::HighlightText;
			this->addBtn->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->addBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->addBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"addBtn.Image")));
			this->addBtn->Location = System::Drawing::Point(21, 774);
			this->addBtn->Margin = System::Windows::Forms::Padding(4);
			this->addBtn->Name = L"addBtn";
			this->addBtn->Size = System::Drawing::Size(313, 94);
			this->addBtn->TabIndex = 19;
			this->addBtn->UseVisualStyleBackColor = false;
			this->addBtn->Click += gcnew System::EventHandler(this, &StartseiteVorgesetzte::addBtn_Click);
			// 
			// editBtn
			// 
			this->editBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->editBtn->BackColor = System::Drawing::SystemColors::HighlightText;
			this->editBtn->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->editBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->editBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"editBtn.Image")));
			this->editBtn->Location = System::Drawing::Point(396, 774);
			this->editBtn->Margin = System::Windows::Forms::Padding(4);
			this->editBtn->Name = L"editBtn";
			this->editBtn->Size = System::Drawing::Size(313, 94);
			this->editBtn->TabIndex = 20;
			this->editBtn->UseVisualStyleBackColor = false;
			this->editBtn->Click += gcnew System::EventHandler(this, &StartseiteVorgesetzte::editBtn_Click);
			// 
			// personalBtn
			// 
			this->personalBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->personalBtn->BackColor = System::Drawing::SystemColors::HighlightText;
			this->personalBtn->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->personalBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->personalBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"personalBtn.Image")));
			this->personalBtn->Location = System::Drawing::Point(773, 774);
			this->personalBtn->Margin = System::Windows::Forms::Padding(4);
			this->personalBtn->Name = L"personalBtn";
			this->personalBtn->Size = System::Drawing::Size(313, 94);
			this->personalBtn->TabIndex = 21;
			this->personalBtn->UseVisualStyleBackColor = false;
			this->personalBtn->Click += gcnew System::EventHandler(this, &StartseiteVorgesetzte::personalBtn_Click);
			// 
			// StartseiteVorgesetzte
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->ClientSize = System::Drawing::Size(1103, 997);
			this->Controls->Add(this->personalBtn);
			this->Controls->Add(this->editBtn);
			this->Controls->Add(this->addBtn);
			this->Controls->Add(this->pauseCbox);
			this->Controls->Add(this->resturlaubLbl);
			this->Controls->Add(this->pauseLbl);
			this->Controls->Add(this->nochWochenstundenLbl);
			this->Controls->Add(this->kalenderBtn);
			this->Controls->Add(this->urlaubBtn);
			this->Controls->Add(this->statistikBtn);
			this->Controls->Add(this->nochWochenstundenSchriftLbl);
			this->Controls->Add(this->PausenSchriftLbl);
			this->Controls->Add(this->resturlaubSchriftLbl);
			this->Controls->Add(this->arbeitszeitSchriftLbl);
			this->Controls->Add(this->datumLbl);
			this->Controls->Add(this->uhrzeitLbl);
			this->Controls->Add(this->arbeitszeitLbl);
			this->Controls->Add(this->nameLbl);
			this->Controls->Add(this->halloLbl);
			this->Controls->Add(this->gehenBtn);
			this->Controls->Add(this->kommenBtn);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"StartseiteVorgesetzte";
			this->Text = L"Zeiterfassung Imperium Startseite Vorgesetzte";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &StartseiteVorgesetzte::StartseiteVorgesetzte_FormClosing);
			this->Load += gcnew System::EventHandler(this, &StartseiteVorgesetzte::StartseiteVorgesetzte_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	
#pragma endregion
		public: void setUnternehmen(Unternehmen^ unternehmen)
		{
			this->unternehmen = unternehmen;
		}

		public: void  setAngemeldeterAngestellter(Angestellter^ angestellter) {
			this->angestellterAkt = angestellter;
		}

		public: Angestellter ^ getVorgesetzter() {
			return angestellterAkt;
		}

	//KOMMEN
	private: System::Void kommenBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		if (angestellterAkt->getArbeitsAnfang() == nullptr) {
			Ereignis^ arbeitsanfang = gcnew Ereignis(ARBEIT_START, DateTime::Now);
			angestellterAkt->fuegeEreignisHinzu(arbeitsanfang);
			timerArbeitszeit->Start();

		} 
		else {
			MessageBox::Show("Bitte beenden Sie Ihren Arbeitstag, bevor Sie einen neuen beginnen!", "Kein Start möglich",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	//PAUSE
	private: System::Void pauseCbox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (angestellterAkt->getArbeitsAnfang() != nullptr) {

			if(angestellterAkt->getPauseAnfang() == nullptr) {
				timerArbeitszeit->Stop();
				timerPause->Start();
				Ereignis^ pausenanfang = gcnew Ereignis(PAUSE_START, DateTime::Now);
				angestellterAkt->fuegeEreignisHinzu(pausenanfang);
				this->pauseCbox->Image = Image::FromFile("Images/pauseIcon3.jpg");
				this->pauseLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				this->arbeitszeitLbl->ForeColor = System::Drawing::Color::Gray;
			}
			else {
				timerArbeitszeit->Start();
				timerPause->Stop();
				Ereignis^ pausenende = gcnew Ereignis(PAUSE_ENDE, DateTime::Now);
				angestellterAkt->fuegeEreignisHinzu(pausenende);
				this->pauseCbox->Image = Image::FromFile("Images/pauseIcon.jpg");
				this->pauseLbl->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
				this->arbeitszeitLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			}
		}
		else {
			MessageBox::Show("Bitte beginnen Sie zuerst Ihre Arbeitszeit, bevor Sie eine Pause starten!", "Keine Pause möglich",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	//GEHEN
	private: System::Void gehenBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		if (angestellterAkt->getPauseAnfang() != nullptr) {
			MessageBox::Show("Bitte beenden Sie zuerst Ihre Pause, bevor Sie gehen!", "Kein Ende möglich",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (angestellterAkt->getArbeitsAnfang() != nullptr) {
			//Timer stoppen
			timerArbeitszeit->Stop();
			timerPause->Stop();

			Ereignis^ arbeitsende = gcnew Ereignis(ARBEIT_ENDE, DateTime::Now);
			angestellterAkt->fuegeEreignisHinzu(arbeitsende);

		}
		else {
			MessageBox::Show("Bitte beginnen Sie zuerst Ihre Arbeitszeit, bevor Sie gehen!", "Kein Ende möglich",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	//STATISTIKFENSTER
	private: System::Void statistikBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		statistikfenster->ShowDialog(this);
	}

	//KALENDERFENSTER
	private: System::Void kalenderBtn_Click(System::Object^  sender, System::EventArgs^  e) {
	}

	//URLAUBSFENSTER
	private: System::Void urlaubBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		urlaubsbearbeitungsfenster->Show();
	}

	//REGISTRIERUNGSFENSTER
	private: System::Void addBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		//registrierungsfenster->setStartseiteVorgesetzte(this);
		registrierungsfenster->setUnternehmen(unternehmen);
		System::Windows::Forms::DialogResult result = registrierungsfenster->ShowDialog(this);
	}
	private: System::Void editBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		
	}
	private: System::Void personalBtn_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	//WÄHREND SEITE LÄD
	private: System::Void StartseiteVorgesetzte_Load(System::Object^  sender, System::EventArgs^  e) {
		if (angestellterAkt->getArbeitsAnfang() == nullptr) {
			// gerade freizeit
		}
		else if (angestellterAkt->getPauseAnfang() == nullptr) {
			// gerade arbeitszeit
			angestellterAkt->getAktuelleArbeitszeit();
		}
		else {
			// gerade pause
		}

		Int32 resturlaub = angestellterAkt->getUrlaubstage();
		nameLbl->Text = angestellterAkt->getVorname() + " " + angestellterAkt->getNachname();
		resturlaubLbl->Text = angestellterAkt->getAnzahlArbeitstage() + " Tage";
	}
	//WENN SEITE GESCHLOSSEN UNTERNEHMEN WIRD GESPEICHERT
	private: System::Void StartseiteVorgesetzte_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		unternehmen->speichern();
		Application::Exit();
	}

	//TIMER ARBEITSZEIT
	private: System::Void timerArbeitszeit_Tick(System::Object^  sender, System::EventArgs^  e) {
	}

	//TIMER UHR
	private: System::Void timerUhr_Tick(System::Object^  sender, System::EventArgs^  e) {
		uhrzeitLbl->Text = DateTime::Now.ToString("HH:mm:ss");
		datumLbl->Text = DateTime::Now.ToString("dddd, dd. MMMM yyyy");
	}

	//TIMER PAUSE
	private: System::Void timerPause_Tick(System::Object^  sender, System::EventArgs^  e) {
	}
};
}



