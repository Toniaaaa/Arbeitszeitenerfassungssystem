#pragma once

#include <ctime>
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
#include "AuswahlFenster.h"
#include "FeiertagsFenster.h"
#include "UrlaubLoeschenFenster.h"
#include "Kalender.h"
#include "AbteilungLoeschenFenster.h"

namespace Zeiterfassungssystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//zum lesen und schreiben
	using namespace System::Runtime::Serialization::Formatters::Binary;
	using namespace System::IO;
	using namespace System::Media;
	/// <summary>
	/// Zusammenfassung f�r VorgesetztenSeite
	/// </summary>
	public ref class StartseiteVorgesetzte : public System::Windows::Forms::Form
	{
	private:
		//Beteiligte Personen/Unternehmen:
		Unternehmen^ unternehmen;
		Vorgesetzter^ angestellterAkt;

		//F�r die Soundeffekte
		SoundPlayer^ sound;

		//Unterfenster:
		RegistrierungsFenster^ registrierungsfenster;
		UrlaubsanfragenbearbeitungsFenster^ urlaubsbearbeitungsfenster;
		PersonalFenster^ personalfenster;
		StundenStatistikFenster^ statistik;
		BearbeitungsFenster^ bearbeitungsfenster;
		UrlaubsFenster^ urlaubsfenster;
		KalenderFenster^ kalenderfenster;
		AenderungsbearbeitungsFenster^ aenderungsfenster;
		AuswahlFenster^ auswahlfenster;
		FeiertagsFenster^ feiertagsfenster;
		UrlaubLoeschenFenster^ urlaubLoeschenFenster;
		AbteilungLoeschenFenster^ abteilungFenster;

		//F�r den Arbeitszeit-Timer:
		Int32 sekunde;
		Int32 minute;
		Int32 stunde;
		//F�r den Pausentimer:
		Int32 pauseSekunde;
		Int32 pauseMinute;
		Int32 pauseStunde;
		//F�r den Noch-Wochenstunden-Timer:
		Int32 arbeitsStunden;
		Int32 arbeitsMinuten;
		//Zum Berechnen von Zeitspannen:
		TimeSpan^ arbeitszeit;
		TimeSpan^ pausenzeit;
		Boolean wochenZeitErreicht;
		//Zum Berechnen von Kalenderwochen:
		Kalender^ kalender;

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
	private: System::Windows::Forms::Label^  ueberstundenSchriftLbl;
	private: System::Windows::Forms::Label^  ueberstundenLbl;
	private: System::Windows::Forms::Button^  IntroductionBtn;
	private: System::Windows::Forms::Label^  uhrzeitLbl;

	public:
		StartseiteVorgesetzte(void)
		{
			InitializeComponent();
			registrierungsfenster = gcnew RegistrierungsFenster;
			urlaubsbearbeitungsfenster = gcnew UrlaubsanfragenbearbeitungsFenster;
			personalfenster = gcnew PersonalFenster;
			statistik = gcnew StundenStatistikFenster;
			bearbeitungsfenster = gcnew BearbeitungsFenster;
			kalenderfenster = gcnew KalenderFenster;
			urlaubsfenster = gcnew UrlaubsFenster;
			aenderungsfenster = gcnew AenderungsbearbeitungsFenster;
			auswahlfenster = gcnew AuswahlFenster;
			feiertagsfenster = gcnew FeiertagsFenster;
			urlaubLoeschenFenster = gcnew UrlaubLoeschenFenster;
			abteilungFenster = gcnew AbteilungLoeschenFenster;
			kalender = gcnew Kalender();
			sound = gcnew SoundPlayer();
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
		/// Erforderliche Methode f�r die Designerunterst�tzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor ge�ndert werden.
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
			this->ueberstundenSchriftLbl = (gcnew System::Windows::Forms::Label());
			this->ueberstundenLbl = (gcnew System::Windows::Forms::Label());
			this->IntroductionBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// kommenBtn
			// 
			this->kommenBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->kommenBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"kommenBtn.Image")));
			this->kommenBtn->Location = System::Drawing::Point(46, 271);
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
			this->gehenBtn->Location = System::Drawing::Point(588, 271);
			this->gehenBtn->Name = L"gehenBtn";
			this->gehenBtn->Size = System::Drawing::Size(200, 130);
			this->gehenBtn->TabIndex = 2;
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
			this->halloLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->halloLbl->Location = System::Drawing::Point(373, 24);
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
			this->arbeitszeitLbl->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->arbeitszeitLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->arbeitszeitLbl->ForeColor = System::Drawing::Color::White;
			this->arbeitszeitLbl->Location = System::Drawing::Point(3, 444);
			this->arbeitszeitLbl->Name = L"arbeitszeitLbl";
			this->arbeitszeitLbl->Size = System::Drawing::Size(827, 55);
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
			this->uhrzeitLbl->Location = System::Drawing::Point(3, 175);
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
			this->datumLbl->Location = System::Drawing::Point(4, 136);
			this->datumLbl->Name = L"datumLbl";
			this->datumLbl->Size = System::Drawing::Size(826, 50);
			this->datumLbl->TabIndex = 7;
			this->datumLbl->Text = L"1. Januar 1900";
			this->datumLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// arbeitszeitSchriftLbl
			// 
			this->arbeitszeitSchriftLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->arbeitszeitSchriftLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->arbeitszeitSchriftLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->arbeitszeitSchriftLbl->Location = System::Drawing::Point(3, 404);
			this->arbeitszeitSchriftLbl->Name = L"arbeitszeitSchriftLbl";
			this->arbeitszeitSchriftLbl->Size = System::Drawing::Size(827, 31);
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
			this->resturlaubSchriftLbl->Location = System::Drawing::Point(623, 725);
			this->resturlaubSchriftLbl->Name = L"resturlaubSchriftLbl";
			this->resturlaubSchriftLbl->Size = System::Drawing::Size(180, 24);
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
			this->PausenSchriftLbl->Location = System::Drawing::Point(227, 725);
			this->PausenSchriftLbl->Name = L"PausenSchriftLbl";
			this->PausenSchriftLbl->Size = System::Drawing::Size(180, 24);
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
			this->nochWochenstundenSchriftLbl->Location = System::Drawing::Point(21, 725);
			this->nochWochenstundenSchriftLbl->Name = L"nochWochenstundenSchriftLbl";
			this->nochWochenstundenSchriftLbl->Size = System::Drawing::Size(180, 24);
			this->nochWochenstundenSchriftLbl->TabIndex = 11;
			this->nochWochenstundenSchriftLbl->Text = L"Wochenstunden";
			this->nochWochenstundenSchriftLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// statistikBtn
			// 
			this->statistikBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->statistikBtn->BackColor = System::Drawing::SystemColors::HighlightText;
			this->statistikBtn->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->statistikBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->statistikBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"statistikBtn.Image")));
			this->statistikBtn->Location = System::Drawing::Point(26, 535);
			this->statistikBtn->Name = L"statistikBtn";
			this->statistikBtn->Size = System::Drawing::Size(235, 76);
			this->statistikBtn->TabIndex = 3;
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
			this->urlaubBtn->Location = System::Drawing::Point(568, 535);
			this->urlaubBtn->Name = L"urlaubBtn";
			this->urlaubBtn->Size = System::Drawing::Size(235, 76);
			this->urlaubBtn->TabIndex = 5;
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
			this->kalenderBtn->Location = System::Drawing::Point(294, 535);
			this->kalenderBtn->Name = L"kalenderBtn";
			this->kalenderBtn->Size = System::Drawing::Size(235, 76);
			this->kalenderBtn->TabIndex = 4;
			this->kalenderBtn->UseVisualStyleBackColor = false;
			this->kalenderBtn->Click += gcnew System::EventHandler(this, &StartseiteVorgesetzte::kalenderBtn_Click);
			// 
			// nochWochenstundenLbl
			// 
			this->nochWochenstundenLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->nochWochenstundenLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->nochWochenstundenLbl->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->nochWochenstundenLbl->Location = System::Drawing::Point(21, 759);
			this->nochWochenstundenLbl->Name = L"nochWochenstundenLbl";
			this->nochWochenstundenLbl->Size = System::Drawing::Size(180, 24);
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
			this->pauseLbl->Location = System::Drawing::Point(232, 759);
			this->pauseLbl->Name = L"pauseLbl";
			this->pauseLbl->Size = System::Drawing::Size(180, 24);
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
			this->resturlaubLbl->Location = System::Drawing::Point(623, 759);
			this->resturlaubLbl->Name = L"resturlaubLbl";
			this->resturlaubLbl->Size = System::Drawing::Size(180, 24);
			this->resturlaubLbl->TabIndex = 17;
			this->resturlaubLbl->Text = L"0 Tage";
			this->resturlaubLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pauseCbox
			// 
			this->pauseCbox->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pauseCbox->Appearance = System::Windows::Forms::Appearance::Button;
			this->pauseCbox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pauseCbox.Image")));
			this->pauseCbox->Location = System::Drawing::Point(294, 296);
			this->pauseCbox->Name = L"pauseCbox";
			this->pauseCbox->Size = System::Drawing::Size(235, 80);
			this->pauseCbox->TabIndex = 1;
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
			this->addBtn->Location = System::Drawing::Point(26, 629);
			this->addBtn->Name = L"addBtn";
			this->addBtn->Size = System::Drawing::Size(235, 76);
			this->addBtn->TabIndex = 6;
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
			this->editBtn->Location = System::Drawing::Point(294, 629);
			this->editBtn->Name = L"editBtn";
			this->editBtn->Size = System::Drawing::Size(235, 76);
			this->editBtn->TabIndex = 7;
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
			this->personalBtn->Location = System::Drawing::Point(568, 629);
			this->personalBtn->Name = L"personalBtn";
			this->personalBtn->Size = System::Drawing::Size(235, 76);
			this->personalBtn->TabIndex = 8;
			this->personalBtn->UseVisualStyleBackColor = false;
			this->personalBtn->Click += gcnew System::EventHandler(this, &StartseiteVorgesetzte::personalBtn_Click);
			// 
			// nameLbl
			// 
			this->nameLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->nameLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nameLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->nameLbl->Location = System::Drawing::Point(0, 58);
			this->nameLbl->Name = L"nameLbl";
			this->nameLbl->Size = System::Drawing::Size(830, 46);
			this->nameLbl->TabIndex = 4;
			this->nameLbl->Text = L"Beispiel-Name eines MA";
			this->nameLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbl_Status
			// 
			this->lbl_Status->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Status->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Status->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lbl_Status->Location = System::Drawing::Point(1, 108);
			this->lbl_Status->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Status->Name = L"lbl_Status";
			this->lbl_Status->Size = System::Drawing::Size(829, 28);
			this->lbl_Status->TabIndex = 23;
			this->lbl_Status->Text = L"Status";
			this->lbl_Status->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// logOutBtn
			// 
			this->logOutBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logOutBtn.Image")));
			this->logOutBtn->Location = System::Drawing::Point(25, 12);
			this->logOutBtn->Name = L"logOutBtn";
			this->logOutBtn->Size = System::Drawing::Size(122, 44);
			this->logOutBtn->TabIndex = 9;
			this->logOutBtn->UseVisualStyleBackColor = true;
			this->logOutBtn->Click += gcnew System::EventHandler(this, &StartseiteVorgesetzte::logOutBtn_Click);
			// 
			// ueberstundenSchriftLbl
			// 
			this->ueberstundenSchriftLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ueberstundenSchriftLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ueberstundenSchriftLbl->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ueberstundenSchriftLbl->Location = System::Drawing::Point(432, 725);
			this->ueberstundenSchriftLbl->Name = L"ueberstundenSchriftLbl";
			this->ueberstundenSchriftLbl->Size = System::Drawing::Size(185, 24);
			this->ueberstundenSchriftLbl->TabIndex = 25;
			this->ueberstundenSchriftLbl->Text = L"�berstunden";
			this->ueberstundenSchriftLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ueberstundenLbl
			// 
			this->ueberstundenLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ueberstundenLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ueberstundenLbl->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ueberstundenLbl->Location = System::Drawing::Point(433, 759);
			this->ueberstundenLbl->Name = L"ueberstundenLbl";
			this->ueberstundenLbl->Size = System::Drawing::Size(180, 24);
			this->ueberstundenLbl->TabIndex = 26;
			this->ueberstundenLbl->Text = L"0,0 Stunden";
			this->ueberstundenLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// IntroductionBtn
			// 
			this->IntroductionBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->IntroductionBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->IntroductionBtn->Location = System::Drawing::Point(756, 12);
			this->IntroductionBtn->Name = L"IntroductionBtn";
			this->IntroductionBtn->Size = System::Drawing::Size(47, 44);
			this->IntroductionBtn->TabIndex = 27;
			this->IntroductionBtn->Text = L"\?";
			this->IntroductionBtn->UseVisualStyleBackColor = true;
			this->IntroductionBtn->Click += gcnew System::EventHandler(this, &StartseiteVorgesetzte::IntroductionBtn_Click);
			// 
			// StartseiteVorgesetzte
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->ClientSize = System::Drawing::Size(831, 799);
			this->Controls->Add(this->IntroductionBtn);
			this->Controls->Add(this->ueberstundenLbl);
			this->Controls->Add(this->ueberstundenSchriftLbl);
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
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"StartseiteVorgesetzte";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Show;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Zeiterfassung TimeUp Vorgesetzte";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &StartseiteVorgesetzte::StartseiteVorgesetzte_FormClosing);
			this->Load += gcnew System::EventHandler(this, &StartseiteVorgesetzte::StartseiteVorgesetzte_Load);
			this->Shown += gcnew System::EventHandler(this, &StartseiteVorgesetzte::StartseiteVorgesetzte_Shown);
			this->ResumeLayout(false);
			this->PerformLayout();
		}
	
#pragma endregion

		//Setter f�r die Personen / Unternehmen:
		public: void setUnternehmen(Unternehmen^ unternehmen)
		{
			this->unternehmen = unternehmen;
		}

		public: void  setAngemeldeterAngestellter(Vorgesetzter^ angestellter) {
			this->angestellterAkt = angestellter;
		}

	/*KOMMEN-BUTTON
	Es wird ein Ereignis ARBEIT-START mit der aktuellen DateTime erstellt, der Status gesetzt und der Arbeitszeit-Timer gesartet.*/
	private: System::Void kommenBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		if (angestellterAkt->getArbeitsAnfang() == nullptr) {
			//Soundeffekt wird abgespielt
			try {
				sound->SoundLocation = "Sounds/zeitStarten.wav";
				sound->Load();
				sound->Play();
			}
			catch (FileNotFoundException ^) {
				//Kein Sound, wenn die Datei nicht existiert
			}
			Ereignis^ arbeitsanfang = gcnew Ereignis(ARBEIT_START, DateTime::Now);
			angestellterAkt->fuegeEreignisHinzu(arbeitsanfang);
			timerArbeitszeit->Start();
			lbl_Status->Text = "Viel Erfolg beim Erledigen Ihrer Aufgaben!";
			angestellterAkt->setAktuellenStatus("Viel Erfolg beim Erledigen Ihrer Aufgaben!");
		} 
		else {
			MessageBox::Show("Bitte beenden Sie Ihren Arbeitstag, bevor Sie einen neuen beginnen!", "Kein Start m�glich",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	/*PAUSE-BUTTON
	Die Pause wird gestartet oder beendet, je nachdem, ob schon eine Pause l�uft. Daf�r werden die Timer entsprechend gestartet bzw. beendet.
	Au�erdem wird ein PAUSE-START oder ein PAUSE_ENDE Ereignis erstellt und es werden die Farben der Darstellung ge�ndert.*/
	private: System::Void pauseCbox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		
		//Wenn der Arbeitstag schon l�uft
		if (angestellterAkt->getArbeitsAnfang() != nullptr) {
			//Soundeffekt wird abgespielt
			try {
				sound->SoundLocation = "Sounds/klack.wav";
				sound->Load();
				sound->Play();
			}
			catch (FileNotFoundException ^) {
				//Kein Sound, wenn die Datei nicht existiert
			}
			//Wenn schon eine Pause l�uft
			if(angestellterAkt->getPauseAnfang() == nullptr) {
				//Timer werden gestartet bzw. gestoppt
				timerArbeitszeit->Stop();
				timerPause->Start();
				//Ereignis erstellen
				Ereignis^ pausenanfang = gcnew Ereignis(PAUSE_START, DateTime::Now);
				angestellterAkt->fuegeEreignisHinzu(pausenanfang);
				//Wenn jetzt eine Pause gestartet wurde:
				if (angestellterAkt->getPauseAnfang() != nullptr) {
					//Farben der Timer-Darstellungen werden ge�ndert. Der Pause-Button wird grau
					try {
						this->pauseCbox->Text = "";
						this->pauseCbox->Image = Image::FromFile("Images/pauseIcon2.jpg");
					}
					catch (FileNotFoundException ^) {
						this->pauseCbox->Image = nullptr;
						this->pauseCbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
							static_cast<System::Byte>(0)));
						this->pauseCbox->TextAlign = ContentAlignment::MiddleCenter;
						this->pauseCbox->Text = L"Pause beenden";
					}
					this->pauseLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
					this->PausenSchriftLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
					this->arbeitszeitLbl->ForeColor = System::Drawing::Color::Gray;
					this->arbeitszeitSchriftLbl->ForeColor = System::Drawing::Color::Gray;
					//Status wird ge�ndert
					lbl_Status->Text = "Geniessen Sie Ihre Pause!";
					angestellterAkt->setAktuellenStatus("Geniessen Sie Ihre Pause!");
				}
			}
			//Wenn die Pause schon l�uft:
			else {
				//Timer werden gestoppt bzw. gestartet:
				timerArbeitszeit->Start();
				timerPause->Stop();
				//Ereignis PAUSE_ENDE wird erstellt:
				Ereignis^ pausenende = gcnew Ereignis(PAUSE_ENDE, DateTime::Now);
				angestellterAkt->fuegeEreignisHinzu(pausenende);
				//Farben der Timer Darstellung werden wieder zur�ckgesetzt und Pause-Button wird wieder blau
				try {
					this->pauseCbox->Text = "";
					this->pauseCbox->Image = Image::FromFile("Images/pauseIcon.jpg");
				}
				catch (FileNotFoundException ^) {
					this->pauseCbox->Image = nullptr;
					this->pauseCbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					this->pauseCbox->TextAlign = ContentAlignment::MiddleCenter;
					this->pauseCbox->Text = L"Pause starten";
				}
				this->pauseLbl->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
				this->PausenSchriftLbl->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
				this->arbeitszeitLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				this->arbeitszeitSchriftLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				//Status wird wieder gesetzt
				lbl_Status->Text = "Viel Erfolg beim Erledigen Ihrer Aufgaben!";
				angestellterAkt->setAktuellenStatus("Viel Erfolg beim Erledigen Ihrer Aufgaben!");
			}
		}
		//Fall:Arbeitszeit noch gar nicht gestartet:
		else {
			//Info-Nachricht: Wenn keine Arbeitszeit gestartet wurde, kann auch keine Pause begonnen werden.
			MessageBox::Show("Bitte beginnen Sie zuerst Ihre Arbeitszeit, bevor Sie eine Pause starten!", "Keine Pause m�glich",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	/*GEHEN-BUTTON
	Der Arbeitstag wird beendet und so abgespeichert*/
	private: System::Void gehenBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		//Fall: Wenn noch eine Pause l�uft
		if (angestellterAkt->getPauseAnfang() != nullptr) {
			//Kein Beenden eines Arbeitstags m�glich, w�hrend noch eine Pause l�uft
			MessageBox::Show("Bitte beenden Sie zuerst Ihre Pause, bevor Sie gehen!", "Kein Ende m�glich",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		//Fall: Ein Arbeitstag wurde begonnen
		if (angestellterAkt->getArbeitsAnfang() != nullptr) {
			//Sicherheitsabfrage, ob der Mitarbeiter wirklich gehen moechte
			if (MessageBox::Show("Sind Sie sicher, dass Sie Ihren Arbeitstag beenden m�chten?", "Wirklich gehen?", MessageBoxButtons::YesNo,
				MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				//Soundeffekt wird abgespielt
				try {
					sound->SoundLocation = "Sounds/zeitBeenden.wav";
					sound->Load();
					sound->Play();
				}
				catch (FileNotFoundException ^) {
					//Kein Sound, wenn die Datei nicht existiert
				}
				//Timer stoppen
				timerArbeitszeit->Stop();
				timerPause->Stop();
				String^ text = "Ihr Arbeitstag wurde erfolgreich beendet!\nSie haben heute " + stunde + " Stunden und " + minute + " Minuten gearbeitet.";
				
				//Zur�ckstellen der Timer Anzeigen von Pause und Arbeitszeit
				pauseSekunde = 0;
				pauseMinute = 0;
				pauseStunde = 0;
				sekunde = 0;
				minute = 0;
				stunde = 0;
				arbeitszeitLbl->Text = uhrzeitString(sekunde, minute, stunde);
				pauseLbl->Text = uhrzeitString(pauseSekunde, pauseMinute, pauseStunde);
				//Status setzen
				lbl_Status->Text = "Sch�nen Feierabend!";
				angestellterAkt->setAktuellenStatus("Sch�nen Feierabend!");
				//Ereignis ARBEIT_ENDE erstellen
				Ereignis^ arbeitsende = gcnew Ereignis(ARBEIT_ENDE, DateTime::Now);
				angestellterAkt->fuegeEreignisHinzu(arbeitsende);
				//Noch-Wochenzeit speichern
				angestellterAkt->speichereArbeitszeit();
				//Falls zu wenig Pause gemacht wurde, wird eine Information angezeigt
				if (*angestellterAkt->genugPause() > *(gcnew TimeSpan(0, 0, 0))) {
					String^ pauseNachricht = "Sie haben heute " + Convert::ToString(angestellterAkt->genugPause()->Minutes) + " Minuten zu wenig Pause gemacht.\n\nBitte beachten Sie, dass sie " 
						+ "\n\nab 6 Stunden Arbeit 30 min und\nab 9 Stunden Arbeit 45 min\n\nPause machen m�ssen! Vielen Dank!";
					MessageBox::Show(pauseNachricht, "Zu wenig Pause", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				//Best�tigungsnachricht ausgeben
				MessageBox::Show(text, "Arbeitstag beendet", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
		//Fall: Es wurde noch gar kein Arbeitstag begonnen
		else {
			MessageBox::Show("Bitte beginnen Sie zuerst Ihre Arbeitszeit, bevor Sie gehen!", "Kein Ende m�glich",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	//STATISTIKFENSTER-BUTTON
	private: System::Void statistikBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		//Das Statistikfenster wird ge�ffnet und die notwendigen Attribute werden gesetzt.
		statistik->setAktuellenAngestellten(angestellterAkt);
		statistik->setVorgesetzter(angestellterAkt);
		statistik->ShowDialog(this);
	}

	//KALENDERFENSTER-BUTTON
	private: System::Void kalenderBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		//Der Kalender wird ge�ffnet
		kalenderfenster->ShowDialog(this);
	}

	/*URLAUB-BUTTON
	�ffnet ein Urlaubs-Fenster mit einem Antrag auf Urlaub, der ausgef�llt werden kann. Wenn dieser in Ordnung ist und best�tigt wird,
	wird ein Objekt vom Typ Urlaubsantrag erstellt und dem Vorgesetzten in seine Liste von Urlaubsantr�gen hinzugef�gt (in diesem Fall ist
	ein Vorgesetzter sein eigener Vorgesetzter.*/
	private: System::Void urlaubBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		//Urlaubsfenster wird ge�ffnet und die notwendigen Attribute werden gesetzt
		urlaubsfenster->setAngestellter(angestellterAkt);
		urlaubsfenster->setUnternehmen(unternehmen);
		System::Windows::Forms::DialogResult result = urlaubsfenster->ShowDialog(this);

		//Wenn vom Urlaubsfenster OK gegeben wird, wir zun�chst eine Abfrage erzeugt, ob der Antrag so in Ordnung ist. Wenn der Mitarbeiter mit "Ja" best�tigt, wird ein neues Objekt vom Typ
		//Urlaubsantrag erstellt. Bei "Nein" wird abgebrochen.
		if (result == System::Windows::Forms::DialogResult::OK) {

			//Der Urlaubsantrag als String
			String^ urlaubString = "Beginn: " + urlaubsfenster->p_Anfang.ToString("dddd, dd. MMMM yyyy") + "\nEnde: " + urlaubsfenster->p_Ende.ToString("dddd, dd. MMMM yyyy")
				+ "\nUrlaubstage: " + urlaubsfenster->p_Tage.ToString() + "\nKommentar: " + urlaubsfenster->p_Kommentar + "\n";

			//Sicherheitsabfrage mit Zusammenfassung des Antrags
			//Fall: Mit Ja geantwortet
			if (MessageBox::Show("Sie wollen folgenden Urlaub beantragen:\n" + urlaubString + "\nWollen Sie diesen Antrag einreichen?", "Antrag einreichen?", MessageBoxButtons::YesNo,
				MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				//Neuen Urlaubsantrag aus Werten aus dem Urlaubsfenster erstellen
				Urlaubsantrag ^u = gcnew Urlaubsantrag(angestellterAkt, urlaubsfenster->p_Anfang, urlaubsfenster->p_Ende, urlaubsfenster->p_Tage, urlaubsfenster->p_Kommentar);
				angestellterAkt->addUrlaubsantrag(u);
				MessageBox::Show("Urlaubsantrag erfolgreich eingereicht!", "Antrag erfolgreich!",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			//Fall: Mit Nein geantwortet
			else {
				MessageBox::Show("Ihr Urlaubsantrag wurde nicht eingereicht!", "Antrag abgebrochen!",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		//Textfelder wieder leeren
		urlaubsfenster->clear(); 
	}

	/*�NDERN-BUTTON
	�ffnet ein Auswahlfenster, in dem der Nutzer w�hlen kann, was genau er �ndern m�chte*/
	private: System::Void editBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		//Unterfenster werden an das Auswahlfenster �bergeben und Attribute werden gesetzt
		bearbeitungsfenster->setUnternehmen(unternehmen);
		bearbeitungsfenster->setAdminRechte(angestellterAkt->getIstAdmin());
		urlaubLoeschenFenster->setUnternehmen(unternehmen);
		urlaubLoeschenFenster->setAdminRechte(angestellterAkt->getIstAdmin());
		feiertagsfenster->setUnternehmen(unternehmen);
		abteilungFenster->setUnternehmen(unternehmen);
		abteilungFenster->setUser(angestellterAkt);
		auswahlfenster->setAdminRechte(angestellterAkt->getIstAdmin());
		auswahlfenster->setUrlaubLoeschenfenster(urlaubLoeschenFenster);
		auswahlfenster->setFeiertagsfenster(feiertagsfenster);;
		auswahlfenster->setBearbeitungsfenster(bearbeitungsfenster);
		auswahlfenster->setAbteilungLoeschenFenster(abteilungFenster);
		auswahlfenster->ShowDialog(this);

	}

	//HINZUF�GEN-BUTTON
	private: System::Void addBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		//Das Registrierungsfenster wird ge�ffnet und die Attribute werden gesetzt
		registrierungsfenster->setUnternehmen(unternehmen);
		registrierungsfenster->setErsteller(angestellterAkt);
		registrierungsfenster->ShowDialog(this);
	}

	//PERSONAL-BUTTON
	private: System::Void personalBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		//Personalfenster wird ge�ffnet und Unternehmen wird als Attribut �bergeben
		personalfenster->setUnternehmen(unternehmen);
		personalfenster->ShowDialog(this);
	}

	//LOGOUT-BUTTON
	private: System::Void logOutBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		//Es wird eine Sicherheitsfrage gestellt, ob wirklich ausgeloggt werden soll
		if (MessageBox::Show("Wollen Sie sich wirklich ausloggen?", "Wirklich ausloggen?", MessageBoxButtons::YesNo,
			MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			//Das LogIn-Fenster wird wieder neu gestartet, falls mit Ja geantwortet wird
			Application::Restart();
		}
	}

	/*HILFE-BUTTON "?"
	Startet den PDF-Reader des Systems und �ffnet die Anleitung zum Programm*/
	private: System::Void IntroductionBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		try {
			Diagnostics::ProcessStartInfo^ startInfo = gcnew Diagnostics::ProcessStartInfo("BenutzerhandbuchTimeUp.pdf");
			Diagnostics::Process::Start(startInfo);
		}
		catch (System::ComponentModel::Win32Exception ^) {
			MessageBox::Show("Das Benutzerhandbuch konnte leider nicht gefunden werden.\nBitte wenden Sie sich an Ihren Administrator!", "Datei nicht gefunden",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	//W�HREND SEITE L�DT
	private: System::Void StartseiteVorgesetzte_Load(System::Object^  sender, System::EventArgs^  e) {
	
		//Spiele Musik
		try {
			sound->SoundLocation = "Sounds/start.wav";
			sound->Load();
			sound->Play();
		}
		catch (FileNotFoundException ^) {
			//Kein Sound, wenn die Datei nicht existiert
		}
		//Es wird gepr�ft, ob ein neues Jahr oder eine neue Woche angefangen hat
		this->neuesJahr();
		//Falls in dieser Woche freie Tage vorhanden sind (Urlaub, Feiertage) wird die Arbeitszeit dieser Woche entsprechend angepasst.
		angestellterAkt->freieTagePruefen(unternehmen);
		//Wurde die Wochen-Arbeitszeit bereits erreicht
		wochenZeitErreicht = angestellterAkt->getWochenZeitErreicht();
		//Anzeige Noch-Arbeitszeit bzw. �berstunden wird gesetzt
		this->setAnzeigeArbeitszeit();

		//Fall: Wenn der Arbeitstag noch l�uft, gibt es KEINEN Arbeitsanfang, der noch nicht beendet wurde.
		if (angestellterAkt->getArbeitsAnfang() == nullptr) {
			//Timer-Zeiten werden auf 0 gesetzt
			sekunde = 0;
			minute = 0;
			stunde = 0;
			pauseSekunde = 0;
			pauseMinute = 0;
			pauseStunde = 0;
			//Status wird gesetzt
			angestellterAkt->setAktuellenStatus("Sch�n, dass Sie da sind!");

		}
		//Fall, dass der Timer nicht beendet wurde, bevor das Fenster geschlossen wurde, also der Timer im Hintergrund lief:
		else {
			//Fall: Letzter Login war heute:
			if (angestellterAkt->getLetzterLogin().Date == DateTime::Now.Date) {
				//Anzeigen werden so gesetzt, dass der Arbeitstag weiter l�uft und nicht beendet wurde
				this->nochEingeloggt();
			}
			//Fall: Letzter Login ist l�nger her
			else {
				//Es hat ein neuer Tag angefangen: Zwangslogout um 23:59:59 Uhr
				this->neuerTag();
			}
		}

		//Labels setzen:
		ueberstundenLbl->Text = angestellterAkt->getUeberstundenGesamt() + " Stunden";
		nochWochenstundenLbl->Text = uhrzeitString(arbeitsMinuten, arbeitsStunden) + " Stunden";
		lbl_Status->Text = angestellterAkt->getStatus();
		arbeitszeitLbl->Text = uhrzeitString(sekunde, minute, stunde);
		pauseLbl->Text = uhrzeitString(pauseSekunde, pauseMinute, pauseStunde);
		nameLbl->Text = angestellterAkt->getVorname() + " " + angestellterAkt->getNachname();
		resturlaubLbl->Text = angestellterAkt->getRestUrlaub() + " Tage";
	}

	//WENN DIE SEITE FERTIG GELADEN WURDE
	private: System::Void StartseiteVorgesetzte_Shown(System::Object^  sender, System::EventArgs^  e) {
		//Login-Zeitpunkt speichern
		angestellterAkt->setLetzterLogin(DateTime::Now);
		//Pr�fen, ob es neue Antr�ge oder Info-Nachrichten gibt
		this->pruefeAntraege();
		this->pruefeInfos();
	}

	//SEITE WIRD GESCHLOSSEN
	private: System::Void StartseiteVorgesetzte_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		//Unternehmen wird gespeichert
		unternehmen->speichern(); 
		Application::Exit();
	}

	/*TIMER ARBEITSZEIT
	Gibt die Arbeitszeit Sekundengenau aus. L�sst au�erdem die Noch-Wochen-Arbeitszeit minutengenau r�ckw�rts laufen*/
	private: System::Void timerArbeitszeit_Tick(System::Object^  sender, System::EventArgs^  e) {
		
		sekunde++;

		//Wenn die Wochen-Arbeitszeit �berschritten wird, wird der Wert auf True gesetzt. 
		//Dadurch l�uft der Abeitszeit-Timer vorw�rts und �ndert die Farbe.
		if (arbeitsStunden == 0 && arbeitsMinuten == 0 && sekunde == 60) {
			wochenZeitErreicht = true;
			this->nochWochenstundenLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->nochWochenstundenSchriftLbl->Text = L"�berstunden";
			this->nochWochenstundenSchriftLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		}

		//Umschalten: Wenn 60 Sekunden erreicht sind, wird eine Minute gez�hlt und die Sekunde auf 0 gesetzt. Analoger Ablauf f�r Minuten und Stunden
		if (sekunde == 60) {
			sekunde = 0;
			minute++;
			//Falls die Wochenzeit erreicht wurde, l�uft der Noch-Timer vorw�rts (z�hlt �berstunden) ansonsten r�ckw�rts
			arbeitsMinuten = wochenZeitErreicht ? arbeitsMinuten + 1 : arbeitsMinuten - 1;
			if (minute == 60) {
				minute = 0;
				stunde++;
			}
			//Die Stunden laufen r�ckw�rts, falls die Wochen-Arbeitszeit noch nicht erreicht ist.
			if (!wochenZeitErreicht && arbeitsMinuten == -1) {
				arbeitsStunden--;
				arbeitsMinuten = 59;
			}
			//Wenn die Wochen-Arbeitszeit erreicht ist, werden die �berstunden vorw�rts gez�hlt.
			else if (wochenZeitErreicht && arbeitsMinuten == 60) {
				arbeitsStunden++;
				arbeitsMinuten = 0;
			}
		}

		//Zeiten auf dem Labels anzeigen
		arbeitszeitLbl->Text = uhrzeitString(sekunde, minute, stunde);
		nochWochenstundenLbl->Text = uhrzeitString(arbeitsMinuten, arbeitsStunden) + " Stunden";

		//Regelm��ige �berpr�fung, ob sich etwas an den Antr�gen oder AntragsInfos ge�ndert hat:
		Int32 interval = 1; //In welchem Rhythmus wird gepr�ft (Minuten 0 bis 59)
		if (sekunde == 0 && minute % interval == 0) {
			this->pruefeAntraege();
			this->pruefeInfos();
		}

		//�berpr�fung, ob es 23:59:59 Uhr ist. Wenn ja, wird der Arbeitstag beendet.
		if (DateTime::Now.Second == 59 && DateTime::Now.Minute == 59 && DateTime::Now.Hour == 23) {
			//Falls noch eine Pause l�uft
			if (angestellterAkt->getPauseAnfang() != nullptr) {
				Ereignis^ pausenende = gcnew Ereignis(PAUSE_ENDE, DateTime::Now);
				angestellterAkt->fuegeEreignisHinzu(pausenende);
				try {
					this->pauseCbox->Text = "";
					this->pauseCbox->Image = Image::FromFile("Images/pauseIcon.jpg");
				}
				catch (FileNotFoundException ^) {
					this->pauseCbox->Image = nullptr;
					this->pauseCbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					this->pauseCbox->TextAlign = ContentAlignment::MiddleCenter;
					this->pauseCbox->Text = L"Pause starten";
				}
				this->pauseLbl->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
				this->PausenSchriftLbl->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
				this->arbeitszeitLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				this->arbeitszeitSchriftLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			}
			//Timer stoppen
			timerArbeitszeit->Stop();
			timerPause->Stop();
			String^ arbeitsEndeText = "Sie wurden an Ende des Tages automatisch ausgeloggt!\nSie haben heute " + stunde + " Stunden und " + minute + " Minuten gearbeitet.";

			//Werte und Anzeigen werden wieder auf 0 gestellt
			pauseSekunde = 0;
			pauseMinute = 0;
			pauseStunde = 0;
			sekunde = 0;
			minute = 0;
			stunde = 0;
			arbeitszeitLbl->Text = uhrzeitString(sekunde, minute, stunde);
			pauseLbl->Text = uhrzeitString(pauseSekunde, pauseMinute, pauseStunde);
			//Status setzen
			lbl_Status->Text = "Sch�nen Feierabend!";
			angestellterAkt->setAktuellenStatus("Sch�nen Feierabend!");
			//Ereignis ARBEIT_ENDE erstellen
			Ereignis^ arbeitsende = gcnew Ereignis(ARBEIT_ENDE, DateTime::Now);
			angestellterAkt->fuegeEreignisHinzu(arbeitsende);
			//Noch-Wochenzeit speichern
			angestellterAkt->speichereArbeitszeit();
			//Falls zu wenig Pause gemacht wurde, wird eine Information angezeigt
			if (*angestellterAkt->genugPause() > *(gcnew TimeSpan(0, 0, 0))) {
				String^ pauseNachricht = "Sie haben heute " + Convert::ToString(angestellterAkt->genugPause()->Minutes) + " Minuten zu wenig Pause gemacht.\n\nBitte beachten Sie, dass sie "
					+ "\n\nab 6 Stunden Arbeit 30 min und\nab 9 Stunden Arbeit 45 min\n\nPause machen m�ssen! Vielen Dank!";
				MessageBox::Show(pauseNachricht, "Zu wenig Pause", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			//Best�tigungsnachricht ausgeben
			MessageBox::Show(arbeitsEndeText, "Arbeitstag beendet", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}

	//TIMER UHR
	private: System::Void timerUhr_Tick(System::Object^  sender, System::EventArgs^  e) {
		//Datum und Uhrzeit werden Sekundengenau angeigt
		uhrzeitLbl->Text = DateTime::Now.ToString("HH:mm:ss");
		datumLbl->Text = DateTime::Now.ToString("dddd, dd. MMMM yyyy");
	}

	/*TIMER ARBEITSZEIT
	Gibt die Pausenzeit des Tages Sekundengenau aus.*/
	private: System::Void timerPause_Tick(System::Object^  sender, System::EventArgs^  e) {

		//Umschalten: Wenn 60 Sekunden erreicht sind, wird eine Minute gez�hlt und die Sekunde auf 0 gesetzt. Analoger Ablauf f�r Minuten und Stunde
		pauseSekunde++;
		if (pauseSekunde == 60) {
			pauseSekunde = 0;
			pauseMinute++;
			if (pauseMinute == 60) {
				pauseMinute = 0;
				pauseStunde++;
			}
		}

		//Ausgabe auf Label
		pauseLbl->Text = uhrzeitString(pauseSekunde, pauseMinute, pauseStunde);
	}

	//Gibt Sekunden, Minuten und Sekunden in Format HH:MM:SS als String^ zur�ck
	private: String^ uhrzeitString(Int32 sekunde, Int32 minute, Int32 stunde) {
		String^ sek;
		//Falls Sekundenzahl einstellig, wird eine 0 davor gesetzt
		if (sekunde < 10) {
			sek = "0" + Convert::ToString(sekunde);
		}
		else {
			sek = Convert::ToString(sekunde);
		}

		//Falls Minutenzahl einstellig, wird eine 0 davor gesetzt
		String^ min;
		if (minute < 10) {
			min = "0" + Convert::ToString(minute);
		}
		else {
			min = Convert::ToString(minute);
		}

		//Falls Stundenzahl einstellig, wird eine 0 davor gesetzt
		String^ std;
		if (stunde < 10) {
			std = "0" + Convert::ToString(stunde);
		}
		else {
			std = Convert::ToString(stunde);
		}

		//R�ckgabe im gew�nschten Format
		return std + ":" + min + ":" + sek;
	}

	//Gibt Minuten und Sekunden in Format HH:MM als String^ zur�ck
	private: String^ uhrzeitString(Int32 minute, Int32 stunde) {

		//Falls Minutenzahl einstellig, wird eine 0 davor gesetzt
		String^ min;
		if (minute < 10) {
			min = "0" + Convert::ToString(minute);
		}
		else {
			min = Convert::ToString(minute);
		}

		//Falls Stundenzahl einstellig, wird eine 0 davor gesetzt
		String^ std;
		if (stunde < 10) {
			std = "0" + Convert::ToString(stunde);
		}
		else {
			std =  Convert::ToString(stunde);
		}

		//R�ckgabe im gew�nschten Format
		return std + ":" + min;
	}

	//Pr�ft, ob Liste mit Info-Nachrichten leer ist. Falls nicht, werden die Nachrichten als MessageBox ausgegeben
	private: void pruefeInfos() {
		//Es wird gepr�ft, ob zu den gestellten Antr�gen neue Informationen vorhanden sind (!=0)
		Int32 anzAntragsInfos = angestellterAkt->getAntragsInfos()->Count;
		//Ausf�hren, solange noch Nachrichten vorhanden sind
		while (anzAntragsInfos > 0) {
			//Info ausgeben und aus Liste entfernen
			String^ antragString = angestellterAkt->getAntragsInfos()[anzAntragsInfos - 1];
			angestellterAkt->removeAntragsInfo(--anzAntragsInfos);
			resturlaubLbl->Text = angestellterAkt->getRestUrlaub() + " Tage";
			MessageBox::Show(antragString, "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}

	//Pr�ft, ob Antr�ge (Urlaub- oder �nderungsantrag) in der Liste vorhanden sind und gibt sie ggf. in dem passenden Fenster aus
	private: void pruefeAntraege() {

		//Es wird gepr�ft, ob die Liste der Urlaubsantr�ge Antr�ge beinhaltet. 
		//Wenn Antr�ge vorhanden sind, k�nnen sie best�tigt werden.
		//Eine �berflutung mit Fenstern wird durch die Pr�fung, ob diese bereits offen sind, verhindert
		if (!urlaubsbearbeitungsfenster->getIstOffen()) {
			Int32 anzUrlaubsantraege = angestellterAkt->getUrlaubsantraege()->Count;
			while (anzUrlaubsantraege > 0) {
				urlaubsbearbeitungsfenster->setUrlaubsantrag(angestellterAkt->getUrlaubsantraege()[anzUrlaubsantraege - 1]);
				urlaubsbearbeitungsfenster->setUnternehmen(unternehmen);
				System::Windows::Forms::DialogResult result = urlaubsbearbeitungsfenster->ShowDialog(this);
				//Nur, wenn einer der beiden Buttons gedr�ckt wurde, wird der Antrag aus der Liste entfernt. Wird das Fenster einfach �ber das "X" geschlossen, bleibt der Antrag in der Liste
				//und erscheint bei der n�chsten �berpr�fung wieder.
				if (result == System::Windows::Forms::DialogResult::OK) {
					angestellterAkt->removeUrlaubsantrag(anzUrlaubsantraege - 1);
					urlaubsbearbeitungsfenster->clear();
				}
				anzUrlaubsantraege--;
			}
		}

		//Es wird gepr�ft, ob die Liste der �nderungsantr�ge Antr�ge beinhaltet. 
		//Wenn Antr�ge vorhanden sind, k�nnen sie best�tigt werden.
		//Eine �berflutung mit Fenstern wird durch die Pr�fung, ob diese bereits offen sind, verhindert
		if (!aenderungsfenster->getIstOffen()) {
			Int32 anzAenderungsantraege = angestellterAkt->getAenderungsantraege()->Count;
			while (anzAenderungsantraege > 0) {
				aenderungsfenster->setAenderungsantrag(angestellterAkt->getAenderungsantraege()[anzAenderungsantraege - 1]);
				System::Windows::Forms::DialogResult result = aenderungsfenster->ShowDialog(this);
				//Nur, wenn einer der beiden Buttons gedr�ckt wurde, wird der Antrag aus der Liste entfernt. Wird das Fenster einfach �ber das "X" geschlossen, bleibt der Antrag in der Liste
				//und erscheint bei der n�chsten �berpr�fung wieder.
				if (result == System::Windows::Forms::DialogResult::OK) {
					angestellterAkt->removeAenderungsantrag(anzAenderungsantraege - 1);
					aenderungsfenster->clear();
				}
				anzAenderungsantraege--;
			}
		}
	}

	// Wenn eine neues Jahr startet, werden die Urlaubstage und Feiertage zurueckgesetzt
	private: void neuesJahr() {
		//Wenn seit dem letzten Arbeitstag ein neues Jahr angefangen hat
		if (angestellterAkt->getLetzterLogin().Year > DateTime::Today.Year) {
			//Urlaubstage werden zurueckgestellt
			angestellterAkt->stelleUraubstageZurueck(3);
			//Feiertage werden f�r das neue Jahr gesetzt
			unternehmen->stelleFeiertageZurueck(3);
			//Angestellter wird �ber seine verbliebenen Urlaubstage Informiert.
			MessageBox::Show("Sie haben noch " + angestellterAkt->getUrlaubstageGespart() + " Resturlaub aus dem vergangenen Jahr nicht genommen!\nDieser verf�llt nach 3 Monaten!",
				"Achtung: Ihr Resturlaub verf�llt", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}

	//Werte f�r die Anzeige der Noch-Arbeitszeit werden aus dem Angestellten-Objekt gelesen und f�r die Darstellung des Timers gesetzt
	void setAnzeigeArbeitszeit() 
	{
		//Fall: Wochenzeit schon erreicht: �berstunden vorw�rts z�hlen
		if (wochenZeitErreicht) {
			arbeitsStunden = angestellterAkt->getUeberStunden();
			arbeitsMinuten = angestellterAkt->getUeberMinuten();
			this->nochWochenstundenLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->nochWochenstundenSchriftLbl->Text = L"�berstunden";
			this->nochWochenstundenSchriftLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		}
		//Fall: Wochenzeit noch nicht erreicht: Arbeitszeit r�ckw�rts z�hlen
		else {
			arbeitsStunden = angestellterAkt->getArbeitsStunden();
			arbeitsMinuten = angestellterAkt->getArbeitsMinuten();
		}
	}

	//Setzt Werte f�r die Darstellung der Timer so, dass der Arbeitstag weiterl�uft, als w�re die Seite immer ge�ffnet gewesen
	void nochEingeloggt() {
		
		//Arbeitszeit wird aus dem Angestellten-Objekt gelesen (als Differenz des Arbeitsanfangs mit der aktuellen Zeit abz�glich der Pausen) 
		TimeSpan^ arbeitszeit = angestellterAkt->getAktuelleArbeitszeit();
		sekunde = arbeitszeit->Seconds;
		minute = arbeitszeit->Minutes;
		stunde = arbeitszeit->Hours;

		//Pausenzeit wird aus Objekt gelesen
		TimeSpan^ pausenzeit = angestellterAkt->getPausezeit(false);
		pauseSekunde = pausenzeit->Seconds;
		pauseMinute = pausenzeit->Minutes;
		pauseStunde = pausenzeit->Hours;

		//Werte f�r Noch-Arbeitszeit-Timer werden gesetzte
		//TimeSpan gibt die Noch-Wochen-Arbeitszeit um die aktuelle Arbeitszeit reduziert an
		TimeSpan abgelaufeneZeit = angestellterAkt->getReduzierteZeit(stunde, minute);
		arbeitsStunden = abgelaufeneZeit.Hours + 24 * abgelaufeneZeit.Days;
		arbeitsMinuten = abgelaufeneZeit.Minutes;
		//Der Sekundenwert des TimeSpans gibt mit 1 oder 0 an, ob die Wochenzeit erreicht wurde
		wochenZeitErreicht = abgelaufeneZeit.Seconds;

		//Farben der Timer-Darstellungen �ndern, falls schon �berstunden gez�hlt werden
		if (wochenZeitErreicht) {
			this->nochWochenstundenLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->nochWochenstundenSchriftLbl->Text = L"�berstunden";
			this->nochWochenstundenSchriftLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		}

		//Timer wird gestartet
		//Fall: Es l�uft gerade eine Pause
		if (angestellterAkt->getPauseAnfang() != nullptr) {
			//Pausentimer-Starten
			timerPause->Start();
			//Farben des Pausebuttons und der Anzeigen anders setzen
			try {
				this->pauseCbox->Text = "";
				this->pauseCbox->Image = Image::FromFile("Images/pauseIcon2.jpg");
			}
			catch (FileNotFoundException ^) {
				this->pauseCbox->Image = nullptr;
				this->pauseCbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->pauseCbox->TextAlign = ContentAlignment::MiddleCenter;
				this->pauseCbox->Text = L"Pause beenden";
			}
			this->pauseLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->PausenSchriftLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->arbeitszeitLbl->ForeColor = System::Drawing::Color::Gray;
			this->arbeitszeitSchriftLbl->ForeColor = System::Drawing::Color::Gray;
		}
		//Fall: Es l�uft keine Pause
		else {
			timerArbeitszeit->Start();
		}
	}

	//F�hrt ein Zwangs-Ende eines Arbeitstages wegen �berschreitung der 23:59-Uhr-Grenze durch
	void neuerTag() {

		//Beendet den Arbeitstag um 23:59 Uhr des Tages, an dem er begonnen wurde
		TimeSpan^ richtigeArbeitszeit = angestellterAkt->neuerTag();
		//Gibt eine Nachricht aus
		String^ text = "Ihr Arbeitstag wurde nach dem letzten Start leider nicht beendet. Er endete daher automatisch um 23:59 Uhr.\nSie haben daher " + richtigeArbeitszeit->Hours + " Stunden und " + richtigeArbeitszeit->Minutes + " Minuten gearbeitet.";
		MessageBox::Show(text, "Arbeitstag auomatisch beendet", MessageBoxButtons::OK, MessageBoxIcon::Information);

		//Werte f�r die Anzeigen werden zur�ckgesetzt
		sekunde = 0;
		minute = 0;
		stunde = 0;
		pauseSekunde = 0;
		pauseMinute = 0;
		pauseStunde = 0;
		this->setAnzeigeArbeitszeit();
	}
};
}