#pragma once

#include <ctime>
#include "Statistikfenster.h"
#include "Vorgesetzter.h"
#include "Unternehmen.h"
#include "RegistrierungsFenster.h"
#include "Ereignis.h"
#include "UrlaubsbearbeitungsFenster.h"
#include "PersonalFenster.h"
#include "StundenStatistikFenster.h"
#include "BearbeitungsFenster.h"
#include "KalenderFenster.h"
#include "UrlaubsFenster.h"
#include "AenderungsbearbeitungsFenster.h"

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
		Vorgesetzter^ angestellterAkt;
		RegistrierungsFenster^ registrierungsfenster;
		StatistikFenster^ statistikfenster;
		UrlaubsanfragenbearbeitungsFenster^ urlaubsbearbeitungsfenster;
		PersonalFenster^ personalfenster;
		StundenStatistikFenster^ statistik;
		BearbeitungsFenster^ bearbeitungsfenster;
		UrlaubsFenster^ urlaubsfenster;
		KalenderFenster^ kalenderfenster;
		AenderungsbearbeitungsFenster^ aenderungsfenster;

		Int32 sekunde;
		Int32 minute;
		Int32 stunde;
		Int32 pauseSekunde;
		Int32 pauseMinute;
		Int32 pauseStunde;
		Int32 arbeitsStunden;
		Int32 arbeitsMinuten;
		TimeSpan^ arbeitszeit;
		TimeSpan^ pausenzeit;
		Boolean wochenZeitErreicht;

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
	private: System::Windows::Forms::Label^  nameLbl;
	private: System::Windows::Forms::Label^  lbl_Status;
	private: System::Windows::Forms::Button^  logOutBtn;
	private: System::Windows::Forms::Label^  uhrzeitLbl;

	public:
		StartseiteVorgesetzte(void)
		{
			InitializeComponent();
			registrierungsfenster = gcnew RegistrierungsFenster;
			statistikfenster = gcnew StatistikFenster;
			urlaubsbearbeitungsfenster = gcnew UrlaubsanfragenbearbeitungsFenster;
			personalfenster = gcnew PersonalFenster;
			statistik = gcnew StundenStatistikFenster;
			bearbeitungsfenster = gcnew BearbeitungsFenster;
			kalenderfenster = gcnew KalenderFenster;
			urlaubsfenster = gcnew UrlaubsFenster;
			aenderungsfenster = gcnew AenderungsbearbeitungsFenster;
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
			this->nameLbl = (gcnew System::Windows::Forms::Label());
			this->lbl_Status = (gcnew System::Windows::Forms::Label());
			this->logOutBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// kommenBtn
			// 
			this->kommenBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->kommenBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"kommenBtn.Image")));
			this->kommenBtn->Location = System::Drawing::Point(35, 272);
			this->kommenBtn->Name = L"kommenBtn";
			this->kommenBtn->Size = System::Drawing::Size(200, 130);
			this->kommenBtn->TabIndex = 0;
			this->kommenBtn->UseVisualStyleBackColor = true;
			this->kommenBtn->Click += gcnew System::EventHandler(this, &StartseiteVorgesetzte::kommenBtn_Click);
			// 
			// gehenBtn
			// 
			this->gehenBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->gehenBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gehenBtn.Image")));
			this->gehenBtn->Location = System::Drawing::Point(580, 272);
			this->gehenBtn->Name = L"gehenBtn";
			this->gehenBtn->Size = System::Drawing::Size(200, 130);
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
			this->halloLbl->Location = System::Drawing::Point(368, 21);
			this->halloLbl->Name = L"halloLbl";
			this->halloLbl->Size = System::Drawing::Size(81, 31);
			this->halloLbl->TabIndex = 3;
			this->halloLbl->Text = L"Hallo";
			this->halloLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			this->arbeitszeitLbl->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->arbeitszeitLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->arbeitszeitLbl->ForeColor = System::Drawing::Color::White;
			this->arbeitszeitLbl->Location = System::Drawing::Point(305, 445);
			this->arbeitszeitLbl->Name = L"arbeitszeitLbl";
			this->arbeitszeitLbl->Size = System::Drawing::Size(212, 55);
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
			this->uhrzeitLbl->Location = System::Drawing::Point(1, 176);
			this->uhrzeitLbl->Name = L"uhrzeitLbl";
			this->uhrzeitLbl->Size = System::Drawing::Size(827, 93);
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
			this->datumLbl->Location = System::Drawing::Point(3, 136);
			this->datumLbl->Name = L"datumLbl";
			this->datumLbl->Size = System::Drawing::Size(825, 50);
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
			this->arbeitszeitSchriftLbl->Location = System::Drawing::Point(337, 414);
			this->arbeitszeitSchriftLbl->Name = L"arbeitszeitSchriftLbl";
			this->arbeitszeitSchriftLbl->Size = System::Drawing::Size(142, 31);
			this->arbeitszeitSchriftLbl->TabIndex = 8;
			this->arbeitszeitSchriftLbl->Text = L"Arbeitszeit";
			this->arbeitszeitSchriftLbl->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// resturlaubSchriftLbl
			// 
			this->resturlaubSchriftLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->resturlaubSchriftLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->resturlaubSchriftLbl->ForeColor = System::Drawing::SystemColors::ControlText;
			this->resturlaubSchriftLbl->Location = System::Drawing::Point(575, 725);
			this->resturlaubSchriftLbl->Name = L"resturlaubSchriftLbl";
			this->resturlaubSchriftLbl->Size = System::Drawing::Size(235, 25);
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
			this->PausenSchriftLbl->Location = System::Drawing::Point(297, 725);
			this->PausenSchriftLbl->Name = L"PausenSchriftLbl";
			this->PausenSchriftLbl->Size = System::Drawing::Size(235, 25);
			this->PausenSchriftLbl->TabIndex = 10;
			this->PausenSchriftLbl->Text = L"Pause seit Beginn";
			this->PausenSchriftLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// nochWochenstundenSchriftLbl
			// 
			this->nochWochenstundenSchriftLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->nochWochenstundenSchriftLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->nochWochenstundenSchriftLbl->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->nochWochenstundenSchriftLbl->Location = System::Drawing::Point(14, 725);
			this->nochWochenstundenSchriftLbl->Name = L"nochWochenstundenSchriftLbl";
			this->nochWochenstundenSchriftLbl->Size = System::Drawing::Size(237, 25);
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
			this->statistikBtn->Location = System::Drawing::Point(13, 535);
			this->statistikBtn->Name = L"statistikBtn";
			this->statistikBtn->Size = System::Drawing::Size(235, 76);
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
			this->urlaubBtn->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->urlaubBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"urlaubBtn.Image")));
			this->urlaubBtn->Location = System::Drawing::Point(580, 535);
			this->urlaubBtn->Name = L"urlaubBtn";
			this->urlaubBtn->Size = System::Drawing::Size(235, 76);
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
			this->kalenderBtn->Location = System::Drawing::Point(297, 535);
			this->kalenderBtn->Name = L"kalenderBtn";
			this->kalenderBtn->Size = System::Drawing::Size(235, 76);
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
			this->nochWochenstundenLbl->Location = System::Drawing::Point(6, 750);
			this->nochWochenstundenLbl->Name = L"nochWochenstundenLbl";
			this->nochWochenstundenLbl->Size = System::Drawing::Size(250, 50);
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
			this->pauseLbl->Location = System::Drawing::Point(271, 750);
			this->pauseLbl->Name = L"pauseLbl";
			this->pauseLbl->Size = System::Drawing::Size(270, 50);
			this->pauseLbl->TabIndex = 16;
			this->pauseLbl->Text = L"00:00:00";
			this->pauseLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// resturlaubLbl
			// 
			this->resturlaubLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->resturlaubLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resturlaubLbl->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->resturlaubLbl->Location = System::Drawing::Point(567, 750);
			this->resturlaubLbl->Name = L"resturlaubLbl";
			this->resturlaubLbl->Size = System::Drawing::Size(258, 50);
			this->resturlaubLbl->TabIndex = 17;
			this->resturlaubLbl->Text = L"0 Tage";
			this->resturlaubLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pauseCbox
			// 
			this->pauseCbox->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pauseCbox->Appearance = System::Windows::Forms::Appearance::Button;
			this->pauseCbox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pauseCbox.Image")));
			this->pauseCbox->Location = System::Drawing::Point(288, 297);
			this->pauseCbox->Name = L"pauseCbox";
			this->pauseCbox->Size = System::Drawing::Size(240, 80);
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
			this->addBtn->Location = System::Drawing::Point(16, 629);
			this->addBtn->Name = L"addBtn";
			this->addBtn->Size = System::Drawing::Size(235, 76);
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
			this->editBtn->Location = System::Drawing::Point(297, 629);
			this->editBtn->Name = L"editBtn";
			this->editBtn->Size = System::Drawing::Size(235, 76);
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
			this->personalBtn->Location = System::Drawing::Point(580, 629);
			this->personalBtn->Name = L"personalBtn";
			this->personalBtn->Size = System::Drawing::Size(235, 76);
			this->personalBtn->TabIndex = 21;
			this->personalBtn->UseVisualStyleBackColor = false;
			this->personalBtn->Click += gcnew System::EventHandler(this, &StartseiteVorgesetzte::personalBtn_Click);
			// 
			// nameLbl
			// 
			this->nameLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->nameLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nameLbl->Location = System::Drawing::Point(2, 52);
			this->nameLbl->Name = L"nameLbl";
			this->nameLbl->Size = System::Drawing::Size(823, 46);
			this->nameLbl->TabIndex = 4;
			this->nameLbl->Text = L"Beispiel-Name eines MA";
			this->nameLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbl_Status
			// 
			this->lbl_Status->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Status->ForeColor = System::Drawing::SystemColors::InfoText;
			this->lbl_Status->Location = System::Drawing::Point(1, 108);
			this->lbl_Status->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Status->Name = L"lbl_Status";
			this->lbl_Status->Size = System::Drawing::Size(824, 28);
			this->lbl_Status->TabIndex = 23;
			this->lbl_Status->Text = L"Status";
			this->lbl_Status->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// logOutBtn
			// 
			this->logOutBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logOutBtn.Image")));
			this->logOutBtn->Location = System::Drawing::Point(19, 12);
			this->logOutBtn->Name = L"logOutBtn";
			this->logOutBtn->Size = System::Drawing::Size(122, 44);
			this->logOutBtn->TabIndex = 22;
			this->logOutBtn->UseVisualStyleBackColor = true;
			this->logOutBtn->Click += gcnew System::EventHandler(this, &StartseiteVorgesetzte::logOutBtn_Click);
			// 
			// StartseiteVorgesetzte
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->ClientSize = System::Drawing::Size(827, 810);
			this->Controls->Add(this->logOutBtn);
			this->Controls->Add(this->lbl_Status);
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
			this->Name = L"StartseiteVorgesetzte";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Zeiterfassung Imperium Startseite Vorgesetzte";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &StartseiteVorgesetzte::StartseiteVorgesetzte_FormClosing);
			this->Load += gcnew System::EventHandler(this, &StartseiteVorgesetzte::StartseiteVorgesetzte_Load);
			this->Shown += gcnew System::EventHandler(this, &StartseiteVorgesetzte::StartseiteVorgesetzte_Shown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	
#pragma endregion
		public: void setUnternehmen(Unternehmen^ unternehmen)
		{
			this->unternehmen = unternehmen;
		}

		public: void  setAngemeldeterAngestellter(Vorgesetzter^ angestellter) {
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
			lbl_Status->Text = "Viel Erfolg beim Erledigen Ihrer Aufgaben!";
			angestellterAkt->setAktuellenStatus("Viel Erfolg beim Erledigen Ihrer Aufgaben!");
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
				if (angestellterAkt->getPauseAnfang() != nullptr) {
					this->pauseCbox->Image = Image::FromFile("Images/pauseIcon3.jpg");
					this->pauseLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
					this->arbeitszeitLbl->ForeColor = System::Drawing::Color::Gray;
					lbl_Status->Text = "Geniessen Sie Ihre Pause!";
					angestellterAkt->setAktuellenStatus("Geniessen Sie Ihre Pause!");
				}
			}
			else {
				//angestellterAkt->getAktuelleArbeitszeit();
				timerArbeitszeit->Start();
				timerPause->Stop();
				Ereignis^ pausenende = gcnew Ereignis(PAUSE_ENDE, DateTime::Now);
				angestellterAkt->fuegeEreignisHinzu(pausenende);
				this->pauseCbox->Image = Image::FromFile("Images/pauseIcon.jpg");
				this->pauseLbl->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
				this->arbeitszeitLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				lbl_Status->Text = "Viel Erfolg beim Erledigen Ihrer Aufgaben!";
				angestellterAkt->setAktuellenStatus("Viel Erfolg beim Erledigen Ihrer Aufgaben!");
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
			//Sicherheitsabfrage, ob der Mitarbeiter wirklich gehen moechte
			if (MessageBox::Show("Sind Sie sicher, dass Sie Ihren Arbeitstag beenden möchten?", "Wirklich gehen?", MessageBoxButtons::YesNo,
				MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {

				//Timer stoppen
				timerArbeitszeit->Stop();
				timerPause->Stop();
				angestellterAkt->speichereArbeitszeit(arbeitsStunden, arbeitsMinuten, wochenZeitErreicht);
				String^ text = "Ihr Arbeitstag wurde erfolgreich beendet!\nSie haben heute " + stunde + " Stunden und " + minute + " Minuten gearbeitet.";
				
				pauseSekunde = 0;
				pauseMinute = 0;
				pauseStunde = 0;
				sekunde = 0;
				minute = 0;
				stunde = 0;
				arbeitszeitLbl->Text = uhrzeitString(sekunde, minute, stunde);
				pauseLbl->Text = uhrzeitString(pauseSekunde, pauseMinute, pauseStunde);
				lbl_Status->Text = "Schönen Feierabend!";
				angestellterAkt->setAktuellenStatus("Schönen Feierabend!");
				TimeSpan^ time = angestellterAkt->getAktuelleArbeitszeit();
				Double gesamt = time->TotalHours;
				//angestellterAkt->setGesamtstunden(gesamt);
				Ereignis^ arbeitsende = gcnew Ereignis(ARBEIT_ENDE, DateTime::Now);
				angestellterAkt->fuegeEreignisHinzu(arbeitsende);
				statistikfenster->setTimespan(angestellterAkt->getAktuelleArbeitszeit()); //HIER RICHTIG???
				MessageBox::Show(text, "Arbeitstag beendet", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
		else {
			MessageBox::Show("Bitte beginnen Sie zuerst Ihre Arbeitszeit, bevor Sie gehen!", "Kein Ende möglich",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		//Hier Fehler im Speichern des Balkens (Timespan in Int)
		/*
		DateTime^ heute = DateTime::Now;
		DateTime^ onlydate = heute->Date;
		TimeSpan^ timespan = angestellterAkt->getAktuelleArbeitszeit();
		statistikfenster->chart1->Series["Arbeitsstunden"]->Points->AddXY(onlydate, timespan);
		*/

	}

	//STATISTIKFENSTER
	private: System::Void statistikBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		//statistikfenster->setAngestellterAkt(angestellterAkt);
		//statistikfenster->ShowDialog(this);
		statistik->setAktuellenAngestellten(angestellterAkt);
		statistik->ShowDialog(this);
	}

	//KALENDERFENSTER
	private: System::Void kalenderBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		kalenderfenster->ShowDialog(this);
	}

	//URLAUBSFENSTER
	private: System::Void urlaubBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		urlaubsfenster->setAngestellter(angestellterAkt);
		System::Windows::Forms::DialogResult result = urlaubsfenster->ShowDialog(this);

		//Der Urlaubsantrag als String
		String^ urlaubString = "Beginn: " + urlaubsfenster->p_Anfang.ToString("dddd, dd. MMMM yyyy") + "\nEnde: " + urlaubsfenster->p_Ende.ToString("dddd, dd. MMMM yyyy") 
			+ "\nUrlaubstage: " + urlaubsfenster->p_Tage.ToString() + "\nKommentar: " + urlaubsfenster->p_Kommentar + "\n";

		//Wenn vom Urlaubsfenster OK gegeben wird, wir zunächst eine Abfrage erzeugt, ob der Antrag so in Ordnung ist. Wenn der Mitarbeiter mit "Ja" bestätigt, wird ein neues Objekt vom Typ
		//Urlaubsantrag erstellt. Bei "Nein" wird abgebrochen.
		if (result == System::Windows::Forms::DialogResult::OK) {
			if (MessageBox::Show("Sie wollen folgenden Urlaub beantragen:\n" + urlaubString + "\nWollen Sie diesen Antrag einreichen?", "Antrag einreichen?", MessageBoxButtons::YesNo,
				MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				//Neuen Urlaubsantrag aus Werten aus dem Urlaubsfenster erstellen
				Urlaubsantrag ^u = gcnew Urlaubsantrag(angestellterAkt, urlaubsfenster->p_Anfang, urlaubsfenster->p_Ende, urlaubsfenster->p_Tage, urlaubsfenster->p_Kommentar);
				angestellterAkt->addUrlaubsantrag(u);
				MessageBox::Show("Urlaubsantrag erfolgreich eingereicht!", "Antrag erfolgreich!",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else {
				MessageBox::Show("Ihr Urlaubsantrag wurde nicht eingereicht!", "Antrag abgebrochen!",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

			urlaubsfenster->clear(); //Textfelder wieder leeren

		}
		else {
			MessageBox::Show("Urlaubsantrag konnte nicht erstellt werden!", "Erstellen fehlgeschlagen",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	//REGISTRIERUNGSFENSTER
	private: System::Void addBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		registrierungsfenster->setUnternehmen(unternehmen);
		registrierungsfenster->setVorgesetzter(angestellterAkt);
		System::Windows::Forms::DialogResult result = registrierungsfenster->ShowDialog(this);
	}
	private: System::Void editBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		bearbeitungsfenster->setUnternehmen(unternehmen);
		bearbeitungsfenster->ShowDialog(this);
	}
	private: System::Void personalBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		personalfenster->setUnternehmen(unternehmen);
		personalfenster->ShowDialog(this);
	}

	//LOGOUT
	private: System::Void logOutBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		//Falls der Angestellte den Arbeitstag noch nicht beendet hat, wird eine Sicherheitsabfrage ausgelöst
		if (MessageBox::Show("Wollen Sie sich wirklich ausloggen?", "Wirklich ausloggen?", MessageBoxButtons::YesNo,
			MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			//Falls der Angestellte gerade die Pause aktiviert hat, wird diese zunächst beendet
			Application::Restart();
		}
	}

	//WÄHREND SEITE LÄD
	private: System::Void StartseiteVorgesetzte_Load(System::Object^  sender, System::EventArgs^  e) {

		this->neueWoche();
		this->neuesJahr();

		wochenZeitErreicht = angestellterAkt->getWochenZeitErreicht();

		//Anzeige Noch-Arbeitszeit bzw. Überstunden wird gesetzt
		if (wochenZeitErreicht) {
			arbeitsStunden = angestellterAkt->getUeberStunden();
			arbeitsMinuten = angestellterAkt->getUeberMinuten();
			this->nochWochenstundenLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->nochWochenstundenSchriftLbl->Text = L"Überstunden";
			this->nochWochenstundenSchriftLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		}
		else {
			arbeitsStunden = angestellterAkt->getArbeitsStunden();
			arbeitsMinuten = angestellterAkt->getArbeitsMinuten();
		}

		if (angestellterAkt->getArbeitsAnfang() == nullptr) {

			sekunde = 0;
			minute = 0;
			stunde = 0;
			pauseSekunde = 0;
			pauseMinute = 0;
			pauseStunde = 0;
			angestellterAkt->setAktuellenStatus("Schön, dass Sie da sind!");
			angestellterAkt->getStatus();

		}
		//Fall, dass der Timer nicht beendet wurde, bevor das Fenster geschlossen wurde, also der Timer im Hintergrund lief:
		else {

			// gerade arbeitszeit
			TimeSpan^ arbeitszeit = angestellterAkt->getAktuelleArbeitszeit();
			sekunde = arbeitszeit->Seconds;
			minute = arbeitszeit->Minutes;
			stunde = arbeitszeit->Hours;

			TimeSpan^ pausenzeit = angestellterAkt->getPausezeit();
			pauseSekunde = pausenzeit->Seconds;
			pauseMinute = pausenzeit->Minutes;
			pauseStunde = pausenzeit->Hours;

			//Anzeige Noch-Arbeitszeit bzw. Überstunden wird gesetzt
			//Es wurden bereits Überstunden gezählt (also Wochen-Arbeitszeit war schon erreicht)
			if (wochenZeitErreicht) {
				arbeitsStunden += stunde;
				if (arbeitsMinuten + minute >= 60) {
					arbeitsStunden++;
					arbeitsMinuten = arbeitsMinuten + minute - 60;
				}
				else {
					arbeitsMinuten += minute;
				}

			}
			//Es wurden noch keine Überstunden gezählt (also Wochen-Arbeitszeit noch nicht erreicht)
			else {
				arbeitsStunden -= stunde;
				if (arbeitsMinuten - minute < 0) {
					arbeitsStunden--;
					arbeitsMinuten = arbeitsMinuten - minute + 60;
				}
				else {
					arbeitsMinuten -= minute;
				}

				//Fall, dass die Wochen-Arbeitszeit erreicht wurde, während das Fenster geschlossen war
				if (arbeitsStunden < 0) {
					wochenZeitErreicht = true;
					this->nochWochenstundenLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
					this->nochWochenstundenSchriftLbl->Text = L"Überstunden";
					this->nochWochenstundenSchriftLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
					arbeitsStunden = -arbeitsStunden - 1; //-1, weil die Arbeitsstunden von 00:00 auf 1:01 springen. Mit -1 ist das korrigiert.
					arbeitsMinuten = (arbeitsMinuten == 0) ? arbeitsMinuten : 60 - arbeitsMinuten;
				}
			}

			//Timer wird gestartet
			if (angestellterAkt->getPauseAnfang() != nullptr) {
				timerPause->Start();
			}
			else {
				timerArbeitszeit->Start();
			}
		}

		nochWochenstundenLbl->Text = uhrzeitString(arbeitsMinuten, arbeitsStunden) + " Stunden";
		lbl_Status->Text = angestellterAkt->getStatus();
		arbeitszeitLbl->Text = uhrzeitString(sekunde, minute, stunde);
		pauseLbl->Text = uhrzeitString(pauseSekunde, pauseMinute, pauseStunde);
		nameLbl->Text = angestellterAkt->getVorname() + " " + angestellterAkt->getNachname();
		resturlaubLbl->Text = angestellterAkt->getRestUrlaub() + " Tage";

	}

	//WENN DIE SEITE FERTIG GELADEN WURDE
	private: System::Void StartseiteVorgesetzte_Shown(System::Object^  sender, System::EventArgs^  e) {
		this->pruefeAntraege();
		this->pruefeInfos();
	}

	//SEITE WIRD GESCHLOSSEN
	private: System::Void StartseiteVorgesetzte_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		angestellterAkt->setWochenZeitErreicht(wochenZeitErreicht); //Es wird gespeichert, ob die Wochen-Arbeitszeit bereits erreicht wurde.
		unternehmen->speichern(); //Unternehmen wird gespeichert
		Application::Exit();
	}

	//TIMER ARBEITSZEIT
	private: System::Void timerArbeitszeit_Tick(System::Object^  sender, System::EventArgs^  e) {
		
		sekunde++;

		//Wenn die Wochen-Arbeitszeit überschritten wird, wird der Wert auf True gesetzt. 
		//Dadurch läuft der Abeitszeit-Timer vorwärts und ändert die Farbe.

		if (arbeitsStunden == 0 && arbeitsMinuten == 0 && sekunde == 60) {
			wochenZeitErreicht = true;
			this->nochWochenstundenLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->nochWochenstundenSchriftLbl->Text = L"Überstunden";
			this->nochWochenstundenSchriftLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		}

		if (sekunde == 60) {
			sekunde = 0;
			minute++;
			arbeitsMinuten = wochenZeitErreicht ? arbeitsMinuten + 1 : arbeitsMinuten - 1;
			if (minute == 60) {
				minute = 0;
				stunde++;
			}
			//Die Stunden laufen rückwärts, falls die Wochen-Arbeitszeit noch nicht erreicht ist.
			if (!wochenZeitErreicht && arbeitsMinuten == -1) {
				arbeitsStunden--;
				arbeitsMinuten = 59;
			}
			//Wenn die Wochen-Arbeitszeit erreicht ist, werden die Überstunden vorwärts gezählt.
			else if (wochenZeitErreicht && arbeitsMinuten == 60) {
				arbeitsStunden++;
				arbeitsMinuten = 0;
			}
		}

		arbeitszeitLbl->Text = uhrzeitString(sekunde, minute, stunde);
		nochWochenstundenLbl->Text = uhrzeitString(arbeitsMinuten, arbeitsStunden) + " Stunden";

		//Regelmäßige Überprüfung, ob sich etwas an den Anträgen oder AntragsInfos geändert hat:
		Int32 interval = 1; //In welchem Rhythmus wird geprüft (Minuten 0 bis 59)
		if (sekunde == 0 && minute % interval == 0) {
			this->pruefeAntraege();
			this->pruefeInfos();
		}
	}

	//TIMER UHR
	private: System::Void timerUhr_Tick(System::Object^  sender, System::EventArgs^  e) {
		uhrzeitLbl->Text = DateTime::Now.ToString("HH:mm:ss");
		datumLbl->Text = DateTime::Now.ToString("dddd, dd. MMMM yyyy");
	}

	//TIMER PAUSE
	private: System::Void timerPause_Tick(System::Object^  sender, System::EventArgs^  e) {

		pauseSekunde++;
		if (pauseSekunde == 60) {
			pauseSekunde = 0;
			pauseMinute++;
			if (pauseMinute == 60) {
				pauseMinute = 0;
				pauseStunde++;
			}
		}

		pauseLbl->Text = uhrzeitString(pauseSekunde, pauseMinute, pauseStunde);

	}

	private: String^ uhrzeitString(Int32 sekunde, Int32 minute, Int32 stunde) {
		String^ sek;
		if (sekunde < 10) {
			sek = "0" + Convert::ToString(sekunde);
		}
		else {
			sek = Convert::ToString(sekunde);
		}

		String^ min;
		if (minute < 10) {
			min = "0" + Convert::ToString(minute);
		}
		else {
			min = Convert::ToString(minute);
		}

		String^ std;
		if (stunde < 10) {
			std = "0" + Convert::ToString(stunde);
		}
		else {
			std = Convert::ToString(stunde);
		}

		return std + ":" + min + ":" + sek;
	}

	private: String^ uhrzeitString(Int32 minute, Int32 stunde) {

		String^ min;
		if (minute < 10) {
			min = "0" + Convert::ToString(minute);
		}
		else {
			min = Convert::ToString(minute);
		}

		String^ std;
		if (stunde < 10) {
			std = "0" + Convert::ToString(stunde);
		}
		else {
			std =  Convert::ToString(stunde);
		}

		return std + ":" + min;
	}

	private: void pruefeInfos() {
		//Es wird geprüft, ob zu den gestellten Anträgen neue Informationen vorhanden sind. Diese werden ggf. als MessageBox ausgegeben.
		Int32 anzAntragsInfos = angestellterAkt->getAntragsInfos()->Count;
		while (anzAntragsInfos > 0) {
			String^ antragString = angestellterAkt->getAntragsInfos()[anzAntragsInfos - 1];
			angestellterAkt->removeAntragsInfo(--anzAntragsInfos);
			MessageBox::Show(antragString, "Ihr Antrag", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}

	private: void pruefeAntraege() {

		//Es wird geprüft, ob die Liste der Urlaubsanträge Anträge beinhaltet. 
		//Wenn Anträge vorhanden sind, können sie bestätigt werden.
		//Eine Überflutung mit Fenstern wird durch die Prüfung, ob diese bereits offen sind, verhindert
		if (!urlaubsbearbeitungsfenster->getIstOffen()) {
			Int32 anzUrlaubsantraege = angestellterAkt->getUrlaubsantraege()->Count;
			while (anzUrlaubsantraege > 0) {
				urlaubsbearbeitungsfenster->setUrlaubsantrag(angestellterAkt->getUrlaubsantraege()[anzUrlaubsantraege - 1]);
				System::Windows::Forms::DialogResult result = urlaubsbearbeitungsfenster->ShowDialog(this);
				//Nur, wenn einer der beiden Buttons gedrückt wurde, wird der Antrag aus der Liste entfernt. Wird das Fenster einfach über das "X" geschlossen, bleibt der Antrag in der Liste
				//und erscheint bei der nächsten Überprüfung wieder.
				if (result == System::Windows::Forms::DialogResult::OK) {
					angestellterAkt->removeUrlaubsantrag(anzUrlaubsantraege - 1);
					urlaubsbearbeitungsfenster->clear();
				}
				anzUrlaubsantraege--;
			}
		}

		//Es wird geprüft, ob die Liste der Änderungsanträge Anträge beinhaltet. 
		//Wenn Anträge vorhanden sind, können sie bestätigt werden.
		//Eine Überflutung mit Fenstern wird durch die Prüfung, ob diese bereits offen sind, verhindert
		if (!aenderungsfenster->getIstOffen()) {
			Int32 anzAenderungsantraege = angestellterAkt->getAenderungsantraege()->Count;
			while (anzAenderungsantraege > 0) {
				aenderungsfenster->setAenderungsantrag(angestellterAkt->getAenderungsantraege()[anzAenderungsantraege - 1]);
				System::Windows::Forms::DialogResult result = aenderungsfenster->ShowDialog(this);
				//Nur, wenn einer der beiden Buttons gedrückt wurde, wird der Antrag aus der Liste entfernt. Wird das Fenster einfach über das "X" geschlossen, bleibt der Antrag in der Liste
				//und erscheint bei der nächsten Überprüfung wieder.
				if (result == System::Windows::Forms::DialogResult::OK) {
					angestellterAkt->removeAenderungsantrag(anzAenderungsantraege - 1);
					aenderungsfenster->clear();
				}
				anzAenderungsantraege--;
			}
		}
	}
	
	// Wenn eine neue Woche startet, wird die Arbeitszeit zurueckgesetzt
	private: void neueWoche() 
	{
		//Dafür müssen die Kalenderwochen des letzten Arbeitstags mit der KW von heute verglichen werden
		CultureInfo^ meinCI = gcnew CultureInfo("de");
		Calendar^ meinKalender = meinCI->Calendar;
		CalendarWeekRule^ meineCWR = meinCI->DateTimeFormat->CalendarWeekRule;
		DayOfWeek^ meinErsterWochentag = meinCI->DateTimeFormat->FirstDayOfWeek;

		//Kalenderwoche von heute berechnen
		DateTime^ heute = DateTime::Today;
		int kWHeute = meinKalender->GetWeekOfYear(*heute, *meineCWR, *meinErsterWochentag);

		//Kalenderwoche vom letzten Arbeitstag berechnen
		int kWLetzterTag;
		try {
			DateTime^ letzterTag = angestellterAkt->getLetzterArbeitstag();
			kWLetzterTag = meinKalender->GetWeekOfYear(*letzterTag, *meineCWR, *meinErsterWochentag);
		}
		catch (System::NullReferenceException ^e) {
			DateTime^ letzterTag = DateTime::Today;
			kWLetzterTag = meinKalender->GetWeekOfYear(*letzterTag, *meineCWR, *meinErsterWochentag);
		}

		//Kalenderwochen vergleichen und evtl. notwendige Werte zurücksetzen
		if (kWHeute > kWLetzterTag) {
			//Wenn der Mitarbeiter in der letzten Woche seine Arbeitszeit nicht erreicht hat, wird ihm das von seinen Überstunden wieder abgezogen
			if (!angestellterAkt->getWochenZeitErreicht()) {
				angestellterAkt->setUeberstundenGesamt(-(angestellterAkt->getArbeitsStunden()), -(angestellterAkt->getArbeitsMinuten()));
			}
			else {
				angestellterAkt->setUeberstundenGesamt(angestellterAkt->getUeberStunden(), angestellterAkt->getUeberStunden());
			}
			//Wochenarbeitszeit wird wieder auf ihre Anfangswerte zurückgesetzt
			angestellterAkt->setWochenZeitErreicht(false);
			angestellterAkt->setArbeitsStunden(angestellterAkt->getWochensstunden());
			angestellterAkt->setArbeitsMinuten(0);
			angestellterAkt->setUeberStunden(0);
			angestellterAkt->setUeberMinuten(0);
		}
	}

	// Wenn eine neues Jahr startet, werden die Urlaubstage zurueckgesetzt
	private: void neuesJahr() {

		DateTime^ letzterTag = angestellterAkt->getLetzterArbeitstag();
		DateTime^ heute = DateTime::Today;

		//Wenn seit dem letzten Arbeitstag ein neues Jahr angefangen hat
		if (letzterTag != nullptr && letzterTag->Year > heute->Year) {
			//Urlaubstage verfallen nach 3 Monaten
			angestellterAkt->setUrlaubstageGespart(angestellterAkt->getRestUrlaub());
			angestellterAkt->setUrlaubstageGenommen(0);
			//Angestellter wird informiert
			MessageBox::Show("Sie haben noch " + angestellterAkt->getUrlaubstageGespart() + " Resturlaub aus dem vergangenen Jahr nicht genommen!\nDieser verfällt nach 3 Monaten!",
				"Achtung: Ihr Resturlaub verfällt", MessageBoxButtons::OK, MessageBoxIcon::Information);

			//Gespeicherte Arbeitszeiten verfallen nach drei Jahren
			Int32 i = 0;
			//Kein Exception-Handling notwendig, da letzterArbeitstag kein Nullpointer sein kann (siehe oben) und daher auch schon mindesten ein Ereignis existieren muss.
			while (heute->Year - angestellterAkt->getEreignis(i)->getTimestamp()->Year > 3) {
				angestellterAkt->removeEreignis(i);
				i++;
			}
		}

		//Urlaubstage, die aus dem letzten Jahr stammen, verfallen, wenn sie nicht bis März genommen wurden
		if (angestellterAkt->getUrlaubstageGespart() != 0 && heute->Month >= 4) {
			angestellterAkt->setUrlaubstageGespart(0);
		}
	}
};
}