#pragma once

#include <ctime>
#include "Vorgesetzter.h"
#include "Unternehmen.h"
#include "RegistrierungsFenster.h"
#include "Ereignis.h"
#include "UrlaubsbearbeitungsFenster.h"
#include "PersonalFensterMitarbeiter.h"
#include "StundenStatistikFenster.h"
#include "BearbeitungsFenster.h"
#include "KalenderFenster.h"
#include "UrlaubsFenster.h"
#include "AenderungsantragsFenster.h"
#include "Kalender.h"

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
	public ref class StartseiteMitarbeiter : public System::Windows::Forms::Form
	{
	private:
		//Beteiligte Personen/Unternehmen
		Unternehmen ^ unternehmen;
		Mitarbeiter^ angestellterAkt;
		Vorgesetzter^ vorgesetzter;

		//Unterfenster
		StundenStatistikFenster^ statistik;
		BearbeitungsFenster^ bearbeitungsfenster;
		UrlaubsFenster^ urlaubsfenster;
		KalenderFenster^ kalenderfenster;
		AenderungsantragsFenster^ aenderungsfenster;
		PersonalFensterMitarbeiter^ personalfenster;

		//Für den Arbeitszeit-Timer:
		Int32 sekunde;
		Int32 minute;
		Int32 stunde;
		//Für den Pausentimer:
		Int32 pauseSekunde;
		Int32 pauseMinute;
		Int32 pauseStunde;
		//Für den Noch-Wochenstunden-Timer:
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
	private: System::Windows::Forms::Button^  personalBtn;
	private: System::Windows::Forms::Label^  nameLbl;
	private: System::Windows::Forms::Label^  lbl_Status;
	private: System::Windows::Forms::Button^  logOutBtn;
	private: System::Windows::Forms::Label^  ueberstundenSchriftLbl;
	private: System::Windows::Forms::Label^  ueberstundenLbl;
	private: System::Windows::Forms::Button^  IntroductionBtn;

	private: System::Windows::Forms::Label^  uhrzeitLbl;

	public:
		StartseiteMitarbeiter(void)
		{
			InitializeComponent();
			statistik = gcnew StundenStatistikFenster;
			bearbeitungsfenster = gcnew BearbeitungsFenster;
			kalenderfenster = gcnew KalenderFenster;
			urlaubsfenster = gcnew UrlaubsFenster;
			aenderungsfenster = gcnew AenderungsantragsFenster;
			kalender = gcnew Kalender();
			personalfenster = gcnew PersonalFensterMitarbeiter;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(StartseiteMitarbeiter::typeid));
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
			this->kommenBtn->Location = System::Drawing::Point(36, 272);
			this->kommenBtn->Name = L"kommenBtn";
			this->kommenBtn->Size = System::Drawing::Size(200, 130);
			this->kommenBtn->TabIndex = 0;
			this->kommenBtn->UseVisualStyleBackColor = true;
			this->kommenBtn->Click += gcnew System::EventHandler(this, &StartseiteMitarbeiter::kommenBtn_Click);
			// 
			// gehenBtn
			// 
			this->gehenBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->gehenBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gehenBtn.Image")));
			this->gehenBtn->Location = System::Drawing::Point(581, 272);
			this->gehenBtn->Name = L"gehenBtn";
			this->gehenBtn->Size = System::Drawing::Size(200, 130);
			this->gehenBtn->TabIndex = 2;
			this->gehenBtn->UseVisualStyleBackColor = true;
			this->gehenBtn->Click += gcnew System::EventHandler(this, &StartseiteMitarbeiter::gehenBtn_Click);
			// 
			// halloLbl
			// 
			this->halloLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->halloLbl->AutoSize = true;
			this->halloLbl->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->halloLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->halloLbl->Location = System::Drawing::Point(369, 21);
			this->halloLbl->Name = L"halloLbl";
			this->halloLbl->Size = System::Drawing::Size(81, 31);
			this->halloLbl->TabIndex = 3;
			this->halloLbl->Text = L"Hallo";
			this->halloLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timerArbeitszeit
			// 
			this->timerArbeitszeit->Interval = 1000;
			this->timerArbeitszeit->Tick += gcnew System::EventHandler(this, &StartseiteMitarbeiter::timerArbeitszeit_Tick);
			// 
			// arbeitszeitLbl
			// 
			this->arbeitszeitLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->arbeitszeitLbl->AutoSize = true;
			this->arbeitszeitLbl->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->arbeitszeitLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->arbeitszeitLbl->ForeColor = System::Drawing::Color::White;
			this->arbeitszeitLbl->Location = System::Drawing::Point(306, 445);
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
			this->timerUhr->Tick += gcnew System::EventHandler(this, &StartseiteMitarbeiter::timerUhr_Tick);
			// 
			// uhrzeitLbl
			// 
			this->uhrzeitLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->uhrzeitLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 56));
			this->uhrzeitLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->uhrzeitLbl->Location = System::Drawing::Point(2, 176);
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
			this->arbeitszeitSchriftLbl->Location = System::Drawing::Point(338, 414);
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
			this->resturlaubSchriftLbl->Location = System::Drawing::Point(613, 621);
			this->resturlaubSchriftLbl->Name = L"resturlaubSchriftLbl";
			this->resturlaubSchriftLbl->Size = System::Drawing::Size(185, 25);
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
			this->PausenSchriftLbl->Location = System::Drawing::Point(216, 621);
			this->PausenSchriftLbl->Name = L"PausenSchriftLbl";
			this->PausenSchriftLbl->Size = System::Drawing::Size(185, 25);
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
			this->nochWochenstundenSchriftLbl->Location = System::Drawing::Point(21, 621);
			this->nochWochenstundenSchriftLbl->Name = L"nochWochenstundenSchriftLbl";
			this->nochWochenstundenSchriftLbl->Size = System::Drawing::Size(180, 25);
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
			this->statistikBtn->Location = System::Drawing::Point(21, 530);
			this->statistikBtn->Name = L"statistikBtn";
			this->statistikBtn->Size = System::Drawing::Size(180, 65);
			this->statistikBtn->TabIndex = 3;
			this->statistikBtn->UseVisualStyleBackColor = false;
			this->statistikBtn->Click += gcnew System::EventHandler(this, &StartseiteMitarbeiter::statistikBtn_Click);
			// 
			// urlaubBtn
			// 
			this->urlaubBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->urlaubBtn->BackColor = System::Drawing::SystemColors::HighlightText;
			this->urlaubBtn->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->urlaubBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->urlaubBtn->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->urlaubBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"urlaubBtn.Image")));
			this->urlaubBtn->Location = System::Drawing::Point(618, 530);
			this->urlaubBtn->Name = L"urlaubBtn";
			this->urlaubBtn->Size = System::Drawing::Size(180, 65);
			this->urlaubBtn->TabIndex = 6;
			this->urlaubBtn->UseVisualStyleBackColor = false;
			this->urlaubBtn->Click += gcnew System::EventHandler(this, &StartseiteMitarbeiter::urlaubBtn_Click);
			// 
			// kalenderBtn
			// 
			this->kalenderBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->kalenderBtn->BackColor = System::Drawing::SystemColors::HighlightText;
			this->kalenderBtn->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->kalenderBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->kalenderBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"kalenderBtn.Image")));
			this->kalenderBtn->Location = System::Drawing::Point(221, 530);
			this->kalenderBtn->Name = L"kalenderBtn";
			this->kalenderBtn->Size = System::Drawing::Size(180, 65);
			this->kalenderBtn->TabIndex = 4;
			this->kalenderBtn->UseVisualStyleBackColor = false;
			this->kalenderBtn->Click += gcnew System::EventHandler(this, &StartseiteMitarbeiter::kalenderBtn_Click);
			// 
			// nochWochenstundenLbl
			// 
			this->nochWochenstundenLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->nochWochenstundenLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->nochWochenstundenLbl->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->nochWochenstundenLbl->Location = System::Drawing::Point(22, 655);
			this->nochWochenstundenLbl->Name = L"nochWochenstundenLbl";
			this->nochWochenstundenLbl->Size = System::Drawing::Size(180, 25);
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
			this->pauseLbl->Location = System::Drawing::Point(221, 655);
			this->pauseLbl->Name = L"pauseLbl";
			this->pauseLbl->Size = System::Drawing::Size(180, 25);
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
			this->resturlaubLbl->Location = System::Drawing::Point(618, 655);
			this->resturlaubLbl->Name = L"resturlaubLbl";
			this->resturlaubLbl->Size = System::Drawing::Size(180, 25);
			this->resturlaubLbl->TabIndex = 17;
			this->resturlaubLbl->Text = L"0 Tage";
			this->resturlaubLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pauseCbox
			// 
			this->pauseCbox->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pauseCbox->Appearance = System::Windows::Forms::Appearance::Button;
			this->pauseCbox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pauseCbox.Image")));
			this->pauseCbox->Location = System::Drawing::Point(293, 297);
			this->pauseCbox->Name = L"pauseCbox";
			this->pauseCbox->Size = System::Drawing::Size(235, 80);
			this->pauseCbox->TabIndex = 1;
			this->pauseCbox->UseVisualStyleBackColor = true;
			this->pauseCbox->CheckedChanged += gcnew System::EventHandler(this, &StartseiteMitarbeiter::pauseCbox_CheckedChanged);
			// 
			// timerPause
			// 
			this->timerPause->Interval = 1000;
			this->timerPause->Tick += gcnew System::EventHandler(this, &StartseiteMitarbeiter::timerPause_Tick);
			// 
			// personalBtn
			// 
			this->personalBtn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->personalBtn->BackColor = System::Drawing::SystemColors::HighlightText;
			this->personalBtn->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->personalBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->personalBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"personalBtn.Image")));
			this->personalBtn->Location = System::Drawing::Point(421, 530);
			this->personalBtn->Name = L"personalBtn";
			this->personalBtn->Size = System::Drawing::Size(180, 65);
			this->personalBtn->TabIndex = 5;
			this->personalBtn->UseVisualStyleBackColor = false;
			this->personalBtn->Click += gcnew System::EventHandler(this, &StartseiteMitarbeiter::personalBtn_Click);
			// 
			// nameLbl
			// 
			this->nameLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->nameLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nameLbl->Location = System::Drawing::Point(3, 52);
			this->nameLbl->Name = L"nameLbl";
			this->nameLbl->Size = System::Drawing::Size(823, 46);
			this->nameLbl->TabIndex = 4;
			this->nameLbl->Text = L"Beispiel-Name eines MA";
			this->nameLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbl_Status
			// 
			this->lbl_Status->Anchor = System::Windows::Forms::AnchorStyles::Top;
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
			this->logOutBtn->Location = System::Drawing::Point(26, 12);
			this->logOutBtn->Name = L"logOutBtn";
			this->logOutBtn->Size = System::Drawing::Size(122, 44);
			this->logOutBtn->TabIndex = 7;
			this->logOutBtn->UseVisualStyleBackColor = true;
			this->logOutBtn->Click += gcnew System::EventHandler(this, &StartseiteMitarbeiter::logOutBtn_Click);
			// 
			// ueberstundenSchriftLbl
			// 
			this->ueberstundenSchriftLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ueberstundenSchriftLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ueberstundenSchriftLbl->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ueberstundenSchriftLbl->Location = System::Drawing::Point(416, 621);
			this->ueberstundenSchriftLbl->Name = L"ueberstundenSchriftLbl";
			this->ueberstundenSchriftLbl->Size = System::Drawing::Size(185, 25);
			this->ueberstundenSchriftLbl->TabIndex = 24;
			this->ueberstundenSchriftLbl->Text = L"Überstunden";
			this->ueberstundenSchriftLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ueberstundenLbl
			// 
			this->ueberstundenLbl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ueberstundenLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ueberstundenLbl->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ueberstundenLbl->Location = System::Drawing::Point(417, 655);
			this->ueberstundenLbl->Name = L"ueberstundenLbl";
			this->ueberstundenLbl->Size = System::Drawing::Size(180, 25);
			this->ueberstundenLbl->TabIndex = 25;
			this->ueberstundenLbl->Text = L"0,0 Stunden";
			this->ueberstundenLbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// IntroductionBtn
			// 
			this->IntroductionBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->IntroductionBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->IntroductionBtn->Location = System::Drawing::Point(751, 14);
			this->IntroductionBtn->Name = L"IntroductionBtn";
			this->IntroductionBtn->Size = System::Drawing::Size(47, 44);
			this->IntroductionBtn->TabIndex = 26;
			this->IntroductionBtn->Text = L"\?";
			this->IntroductionBtn->UseVisualStyleBackColor = true;
			this->IntroductionBtn->Click += gcnew System::EventHandler(this, &StartseiteMitarbeiter::IntroductionBtn_Click);
			// 
			// StartseiteMitarbeiter
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->ClientSize = System::Drawing::Size(826, 691);
			this->Controls->Add(this->IntroductionBtn);
			this->Controls->Add(this->ueberstundenLbl);
			this->Controls->Add(this->ueberstundenSchriftLbl);
			this->Controls->Add(this->logOutBtn);
			this->Controls->Add(this->lbl_Status);
			this->Controls->Add(this->personalBtn);
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
			this->Name = L"StartseiteMitarbeiter";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Zeiterfassung Startseite Mitarbeiter";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &StartseiteMitarbeiter::StartseiteMitarbeiter_FormClosing);
			this->Load += gcnew System::EventHandler(this, &StartseiteMitarbeiter::StartseiteMitarbeiter_Load);
			this->Shown += gcnew System::EventHandler(this, &StartseiteMitarbeiter::StartseiteMitarbeiter_Shown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	//Setter für die Personen / Unternehmen:

	public: void setUnternehmen(Unternehmen^ unternehmen)
	{
		this->unternehmen = unternehmen;
	}

	public: void setAngemeldeterAngestellter(Mitarbeiter^ angestellter) {
		this->angestellterAkt = angestellter;
		this->vorgesetzter = angestellter->getVorgesetzter();
	}

	/*KOMMEN-BUTTON
	Es wird ein Ereignis ARBEIT-START mit der aktuellen DateTime erstellt, der Status gesetzt und der Arbeitszeit-Timer gesartet.*/
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

	/*PAUSE-BUTTON
	Die Pause wird gestartet oder beendet, je nachdem, ob schon eine Pause läuft. Dafür werden die Timer entsprechend gestartet bzw. beendet.
	Außerdem wird ein PAUSE-START oder ein PAUSE_ENDE Ereignis erstellt und es werden die Farben der Darstellung geändert.*/
	private: System::Void pauseCbox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		//Wenn der Arbeitstag schon läuft
		if (angestellterAkt->getArbeitsAnfang() != nullptr) {
			//Wenn schon eine Pause läuft
			if (angestellterAkt->getPauseAnfang() == nullptr) {
				//Timer werden gestartet bzw. gestoppt
				timerArbeitszeit->Stop();
				timerPause->Start();
				//Ereignis erstellen
				Ereignis^ pausenanfang = gcnew Ereignis(PAUSE_START, DateTime::Now);
				angestellterAkt->fuegeEreignisHinzu(pausenanfang);
				//Wenn jetzt eine Pause gestartet wurde:
				if (angestellterAkt->getPauseAnfang() != nullptr) {
					//Farben der Timer-Darstellungen werden geändert. Der Pause-Button wird grau
					this->pauseCbox->Image = Image::FromFile("Images/pauseIcon3.jpg");
					this->pauseLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
					this->PausenSchriftLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
					this->arbeitszeitLbl->ForeColor = System::Drawing::Color::Gray;
					this->arbeitszeitSchriftLbl->ForeColor = System::Drawing::Color::Gray;
					//Status wird geändert
					lbl_Status->Text = "Geniessen Sie Ihre Pause!";
					angestellterAkt->setAktuellenStatus("Geniessen Sie Ihre Pause!");
				}
			}
			//Wenn die Pause schon läuft:
			else {
				//Timer werden gestoppt bzw. gestartet:
				timerArbeitszeit->Start();
				timerPause->Stop();
				//Ereignis PAUSE_ENDE wird erstellt:
				Ereignis^ pausenende = gcnew Ereignis(PAUSE_ENDE, DateTime::Now);
				angestellterAkt->fuegeEreignisHinzu(pausenende);
				//Farben der Timer Darstellung werden wieder zurückgesetzt und Pause-Button wird wieder blau
				this->pauseCbox->Image = Image::FromFile("Images/pauseIcon.jpg");
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
			MessageBox::Show("Bitte beginnen Sie zuerst Ihre Arbeitszeit, bevor Sie eine Pause starten!", "Keine Pause möglich",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	
	/*GEHEN-BUTTON
	Der Arbeitstag wird beendet und so abgespeichert*/
	private: System::Void gehenBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		//Fall: Wenn noch eine Pause läuft
		if (angestellterAkt->getPauseAnfang() != nullptr) {
			//Kein Beenden eines Arbeitstags möglich, während noch eine Pause läuft
			MessageBox::Show("Bitte beenden Sie zuerst Ihre Pause, bevor Sie gehen!", "Kein Ende möglich",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		//Fall: Ein Arbeitstag wurde begonnen
		if (angestellterAkt->getArbeitsAnfang() != nullptr) {
			//Sicherheitsabfrage, ob der Mitarbeiter wirklich gehen moechte
			if (MessageBox::Show("Sind Sie sicher, dass Sie Ihren Arbeitstag beenden möchten?", "Wirklich gehen?", MessageBoxButtons::YesNo,
				MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				//Timer stoppen
				timerArbeitszeit->Stop();
				timerPause->Stop();
				String^ arbeitsEndeText = "Ihr Arbeitstag wurde erfolgreich beendet!\nSie haben heute " + stunde + " Stunden und " + minute + " Minuten gearbeitet.";

				//Zurückstellen der Timer Anzeigen von Pause und Arbeitszeit
				pauseSekunde = 0;
				pauseMinute = 0;
				pauseStunde = 0;
				sekunde = 0;
				minute = 0;
				stunde = 0;
				arbeitszeitLbl->Text = uhrzeitString(sekunde, minute, stunde);
				pauseLbl->Text = uhrzeitString(pauseSekunde, pauseMinute, pauseStunde);
				//Status setzen
				lbl_Status->Text = "Schönen Feierabend!";
				angestellterAkt->setAktuellenStatus("Schönen Feierabend!");
				//Ereignis ARBEIT_ENDE erstellen
				Ereignis^ arbeitsende = gcnew Ereignis(ARBEIT_ENDE, DateTime::Now);
				angestellterAkt->fuegeEreignisHinzu(arbeitsende);
				//Noch-Wochenzeit speichern
				angestellterAkt->speichereArbeitszeit();
				//Falls zu wenig Pause gemacht wurde, wird eine Information angezeigt
				if (*angestellterAkt->genugPause() > *(gcnew TimeSpan(0, 0, 0))) {
					String^ pauseNachricht = "Sie haben heute " + Convert::ToString(angestellterAkt->genugPause()->Minutes) + " Minuten zu wenig Pause gemacht.\n\nBitte beachten Sie, dass sie "
						+ "\n\nab 6 Stunden Arbeit 30 min und\nab 9 Stunden Arbeit 45 min\n\nPause machen müssen! Vielen Dank!";
					MessageBox::Show(pauseNachricht, "Zu wenig Pause", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				//Bestätigungsnachricht ausgeben
				MessageBox::Show(arbeitsEndeText, "Arbeitstag beendet", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
		//Fall: Es wurde noch gar kein Arbeitstag begonnen
		else {
			MessageBox::Show("Bitte beginnen Sie zuerst Ihre Arbeitszeit, bevor Sie gehen!", "Kein Ende möglich",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	//STATISTIKFENSTER-BUTTON
	private: System::Void statistikBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		//Das Statistikfenster wird geöffnet und die notwendigen Attribute werden gesetzt.
		statistik->setAktuellenAngestellten(angestellterAkt);
		statistik->setVorgesetzter(angestellterAkt->getVorgesetzter());
		statistik->ShowDialog(this);
	}

	//KALENDERFENSTER-BUTTON
	private: System::Void kalenderBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		//Der Kalender wird geöffnet
		kalenderfenster->ShowDialog(this);
	}

	/*URLAUB-BUTTON
	Öffnet ein Urlaubs-Fenster mit einem Antrag auf Urlaub, der ausgefüllt werden kann. Wenn dieser in Ordnung ist und bestätigt wird,
	wird ein Objekt vom Typ Urlaubsantrag erstellt und dem Vorgesetzten in seine Liste von Urlaubsanträgen hinzugefügt.*/
	private: System::Void urlaubBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		//Urlaubsfenster wird geöffnet und die notwendigen Attribute werden gesetzt
		urlaubsfenster->setAngestellter(angestellterAkt);
		urlaubsfenster->setUnternehmen(unternehmen);
		System::Windows::Forms::DialogResult result = urlaubsfenster->ShowDialog(this);

		//Wenn vom Urlaubsfenster OK gegeben wird, wir zunächst eine Abfrage erzeugt, ob der Antrag so in Ordnung ist. Wenn der Mitarbeiter mit "Ja" bestätigt, wird ein neues Objekt vom Typ
		//Urlaubsantrag erstellt. Bei "Nein" wird abgebrochen.
		if (result == System::Windows::Forms::DialogResult::OK) {

			//Der Urlaubsantrag als String
			String^ urlaubString = "Beginn: " + urlaubsfenster->p_Anfang.ToString("dddd, dd. MMMM yyyy") + "\nEnde: " + urlaubsfenster->p_Ende.ToString("dddd, dd. MMMM yyyy") +
				"\nUrlaubstage: " + urlaubsfenster->p_Tage.ToString() + "\nKommentar: " + urlaubsfenster->p_Kommentar + "\n";
			
			//Sicherheitsabfrage mit Zusammenfassung des Antrags
			//Fall: Mit Ja geantwortet
			if (MessageBox::Show("Sie wollen folgenden Urlaub beantragen:\n\n" + urlaubString + "\nWollen Sie diesen Antrag einreichen?", "Antrag einreichen?", MessageBoxButtons::YesNo,
				MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				//Neuen Urlaubsantrag aus Werten aus dem Urlaubsfenster erstellen
				Urlaubsantrag^ u = gcnew Urlaubsantrag(angestellterAkt, urlaubsfenster->p_Anfang, urlaubsfenster->p_Ende, urlaubsfenster->p_Tage, urlaubsfenster->p_Kommentar);
				vorgesetzter->addUrlaubsantrag(u);
				MessageBox::Show("Urlaubsantrag erfolgreich eingereicht!", "Antrag erfolgreich!",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			//Fall: Mit Nein geantwortet
			else {
				MessageBox::Show("Ihr Urlaubsantrag wurde nicht eingereicht!", "Antrag abgebrochen!",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		//Falls das Urlaubsfenster kein OK zurückgibt:
		else {
			MessageBox::Show("Urlaubsantrag konnte nicht erstellt werden!", "Erstellen fehlgeschlagen",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		
		//Textfelder wieder leeren
		urlaubsfenster->clear(); 
	}

	//PERSONAL-BUTTON
	private: System::Void personalBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		//Personalfenster wird geöffnet und Unternehmen wird als Attribut übergeben
		personalfenster->setUnternehmen(unternehmen);
		System::Windows::Forms::DialogResult result = personalfenster->ShowDialog(this);
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

	/*?-BUTTON
	Startet den PDF-Reader des Systems und öffnet die Anleitung zum Programm*/
	private: System::Void IntroductionBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		Diagnostics::ProcessStartInfo^ startInfo = gcnew Diagnostics::ProcessStartInfo("BenutzerhandbuchTimeUp.pdf");
		Diagnostics::Process::Start(startInfo);
	}

	//WÄHREND SEITE LÄD
	private: System::Void StartseiteMitarbeiter_Load(System::Object^  sender, System::EventArgs^  e) {

		//Es wird geprüft, ob ein neues Jahr oder eine neue Woche angefangen hat
		this->neuesJahr();
		angestellterAkt->neueWoche();
		//Falls in dieser Woche freie Tage vorhanden sind (Urlaub, Feiertage) wird die Arbeitszeit dieser Woche entsprechend angepasst.
		angestellterAkt->freieTagePruefen(unternehmen);
		//Wurde die Wochen-Arbeitszeit bereits erreicht
		wochenZeitErreicht = angestellterAkt->getWochenZeitErreicht();
		//Anzeige Noch-Arbeitszeit bzw. Überstunden wird gesetzt
		this->setAnzeigeArbeitszeit();

		//Fall: Wenn der Arbeitstag noch läuft, gibt es KEINEN Arbeitsanfang, der noch nicht beendet wurde.
		if (angestellterAkt->getArbeitsAnfang() == nullptr) {

			//Timer-Zeiten werden auf 0 gesetzt
			sekunde = 0;
			minute = 0;
			stunde = 0;
			pauseSekunde = 0;
			pauseMinute = 0;
			pauseStunde = 0;
			//Status wird gesetzt
			angestellterAkt->setAktuellenStatus("Schön, dass Sie da sind!");

		}
		//Fall, dass der Timer nicht beendet wurde, bevor das Fenster geschlossen wurde, also der Timer im Hintergrund lief:
		else {
			//Fall: Letzter Login war heute:
			if (angestellterAkt->getLetzterLogin().Date == DateTime::Now.Date) {
				//Anzeigen werden so gesetzt, dass der Arbeitstag weiter läuft und nicht beendet wurde
				this->nochEingeloggt();
			}
			//Fall: Letzter Login ist länger her
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
	private: System::Void StartseiteMitarbeiter_Shown(System::Object^  sender, System::EventArgs^  e) {
		//Login-Zeitpunkt speichern
		angestellterAkt->setLetzterLogin(DateTime::Now);
		//Prüfen, ob es neue Info-Nachrichten gibt
		this->pruefeInfos();
	}

	//SEITE WIRD GESCHLOSSEN
	private: System::Void StartseiteMitarbeiter_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		//Es wird gespeichert, ob die Wochen-Arbeitszeit bereits erreicht wurde.
		angestellterAkt->setWochenZeitErreicht(wochenZeitErreicht);
		//Unternehmen wird gespeichert
		unternehmen->speichern(); 
		Application::Exit();
	}

	/*TIMER ARBEITSZEIT
	Gibt die Arbeitszeit Sekundengenau aus. Lässt außerdem die Noch-Wochen-Arbeitszeit minutengenau rückwärts laufen*/
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

		//Umschalten: Wenn 60 Sekunden erreicht sind, wird eine Minute gezählt und die Sekunde auf 0 gesetzt. Analoger Ablauf für Minuten und Stunden
		if (sekunde == 60) {
			sekunde = 0;
			minute++;
			//Falls die Wochenzeit erreicht wurde, läuft der Noch-Timer vorwärts (zählt Überstunden) ansonsten rückwärts
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

		//Zeiten auf dem Labels anzeigen
		arbeitszeitLbl->Text = uhrzeitString(sekunde, minute, stunde);
		nochWochenstundenLbl->Text = uhrzeitString(arbeitsMinuten, arbeitsStunden) + " Stunden";

		//Regelmäßige Überprüfung, ob sich etwas an den Anträgen oder AntragsInfos geändert hat:
		Int32 interval = 1; //In welchem Rhythmus wird geprüft (Minuten 0-59)
		if (DateTime::Now.Second == 0 && DateTime::Now.Minute % interval == 0) {
			this->pruefeInfos();
		}

		//Überprüfung, ob es 23:59:59 Uhr ist. Wenn ja, wird der Arbeitstag beendet.
		if (DateTime::Now.Second == 59 && DateTime::Now.Minute == 59 && DateTime::Now.Hour == 23) {
			//Falls noch eine Pause läuft
			if (angestellterAkt->getPauseAnfang() != nullptr) {
				Ereignis^ pausenende = gcnew Ereignis(PAUSE_ENDE, DateTime::Now);
				angestellterAkt->fuegeEreignisHinzu(pausenende);
				this->pauseCbox->Image = Image::FromFile("Images/pauseIcon.jpg");
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
			lbl_Status->Text = "Schönen Feierabend!";
			angestellterAkt->setAktuellenStatus("Schönen Feierabend!");
			//Ereignis ARBEIT_ENDE erstellen
			Ereignis^ arbeitsende = gcnew Ereignis(ARBEIT_ENDE, DateTime::Now);
			angestellterAkt->fuegeEreignisHinzu(arbeitsende);
			//Noch-Wochenzeit speichern
			angestellterAkt->speichereArbeitszeit();
			//Falls zu wenig Pause gemacht wurde, wird eine Information angezeigt
			if (*angestellterAkt->genugPause() > *(gcnew TimeSpan(0, 0, 0))) {
				String^ pauseNachricht = "Sie haben heute " + Convert::ToString(angestellterAkt->genugPause()->Minutes) + " Minuten zu wenig Pause gemacht.\n\nBitte beachten Sie, dass sie "
					+ "\n\nab 6 Stunden Arbeit 30 min und\nab 9 Stunden Arbeit 45 min\n\nPause machen müssen! Vielen Dank!";
				MessageBox::Show(pauseNachricht, "Zu wenig Pause", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			//Bestätigungsnachricht ausgeben
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

		//Umschalten: Wenn 60 Sekunden erreicht sind, wird eine Minute gezählt und die Sekunde auf 0 gesetzt. Analoger Ablauf für Minuten und Stunde
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

	//Gibt Sekunden, Minuten und Sekunden in Format HH:MM:SS als String^ zurück
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

		//Falls Stundenzahl einstellig, wird eine 0 davor gesetztstd;
		String^ std;
		if (stunde < 10) {
			std = "0" + Convert::ToString(stunde);
		}
		else {
			std = Convert::ToString(stunde);
		}

		//Rückgabe im gewünschten Format
		return std + ":" + min + ":" + sek;
	}

	//Gibt Minuten und Sekunden in Format HH:MM als String^ zurück
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
			std = Convert::ToString(stunde);
		}

		//Rückgabe im gewünschten Format
		return std + ":" + min;
	}

	//Prüft, ob Liste mit Info-Nachrichten leer ist. Falls nicht, werden die Nachrichten als MessageBox ausgegeben
	private: void pruefeInfos() {
		//Es wird geprüft, ob zu den gestellten Anträgen neue Informationen vorhanden sind (!=0)
		Int32 anzAntragsInfos = angestellterAkt->getAntragsInfos()->Count;
		//Ausführen, solange noch Nachrichten vorhanden sind
		while (anzAntragsInfos > 0) {
			//Info ausgeben und aus Liste entfernen
			String^ antragString = angestellterAkt->getAntragsInfos()[anzAntragsInfos - 1];
			angestellterAkt->removeAntragsInfo(--anzAntragsInfos);
			resturlaubLbl->Text = angestellterAkt->getRestUrlaub() + " Tage";
			MessageBox::Show(antragString, "Ihr Antrag", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}

	// Wenn eine neues Jahr startet, werden die Urlaubstage zurueckgesetzt
	private: void neuesJahr() {
		//Wenn seit dem letzten Arbeitstag ein neues Jahr angefangen hat
		if (angestellterAkt->getLetzterLogin().Year > DateTime::Today.Year) {
			//Urlaubstage werden zurueckgestellt
			angestellterAkt->stelleUraubstageZurueck(3);
			//Feiertage werden für das neue Jahr gesetzt
			unternehmen->stelleFeiertageZurueck(3);
			//Angestellter wird über seine verbliebenen Urlaubstage Informiert.
			MessageBox::Show("Sie haben noch " + angestellterAkt->getUrlaubstageGespart() + " Resturlaub aus dem vergangenen Jahr nicht genommen!\nDieser verfällt nach 3 Monaten!",
				"Achtung: Ihr Resturlaub verfällt", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

	}

	//Werte für die Anzeige der Noch-Arbeitszeit werden aus dem Angestellten-Objekt gelesen und für die Darstellung des Timers gesetzt
	void setAnzeigeArbeitszeit()
	{
		//Fall: Wochenzeit schon erreicht: Überstunden vorwärts zählen
		if (wochenZeitErreicht) {
			arbeitsStunden = angestellterAkt->getUeberStunden();
			arbeitsMinuten = angestellterAkt->getUeberMinuten();
			this->nochWochenstundenLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->nochWochenstundenSchriftLbl->Text = L"Überstunden";
			this->nochWochenstundenSchriftLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		}
		//Fall: Wochenzeit noch nicht erreicht: Arbeitszeit rückwärts zählen
		else {
			arbeitsStunden = angestellterAkt->getArbeitsStunden();
			arbeitsMinuten = angestellterAkt->getArbeitsMinuten();
		}
	}

	//Setzt Werte für die Darstellung der Timer so, dass der Arbeitstag weiterläuft, als wäre die Seite immer geöffnet gewesen
	void nochEingeloggt() {

		//Arbeitszeit wird aus dem Angestellten-Objekt gelesen (als Differenz des Arbeitsanfangs mit der aktuellen Zeit abzüglich der Pausen)
		TimeSpan^ arbeitszeit = angestellterAkt->getAktuelleArbeitszeit();
		sekunde = arbeitszeit->Seconds;
		minute = arbeitszeit->Minutes;
		stunde = arbeitszeit->Hours;

		//Pausenzeit wird aus Objekt gelesen
		TimeSpan^ pausenzeit = angestellterAkt->getPausezeit(false);
		pauseSekunde = pausenzeit->Seconds;
		pauseMinute = pausenzeit->Minutes;
		pauseStunde = pausenzeit->Hours;

		//Werte für Noch-Arbeitszeit-Timer werden gesetzte
		//TimeSpan gibt die Noch-Wochen-Arbeitszeit um die aktuelle Arbeitszeit reduziert an
		TimeSpan abgelaufeneZeit = angestellterAkt->getReduzierteZeit(stunde, minute);
		arbeitsStunden = abgelaufeneZeit.Hours + 24 * abgelaufeneZeit.Days;
		arbeitsMinuten = abgelaufeneZeit.Minutes;
		//Der Sekundenwert des TimeSpans gibt mit 1 oder 0 an, ob die Wochenzeit erreicht wurde
		wochenZeitErreicht = abgelaufeneZeit.Seconds;

		//Farben der Timer-Darstellungen ändern, falls schon Überstunden gezählt werden
		if (wochenZeitErreicht) {
			this->nochWochenstundenLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->nochWochenstundenSchriftLbl->Text = L"Überstunden";
			this->nochWochenstundenSchriftLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		}

		//Timer wird gestartet
		//Fall: Es läuft gerade eine Pause
		if (angestellterAkt->getPauseAnfang() != nullptr) {
			//Pausentimer-Starten
			timerPause->Start();
			//Farben des Pausebuttons und der Anzeigen anders setzen
			this->pauseCbox->Image = Image::FromFile("Images/pauseIcon3.jpg");
			this->pauseLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->PausenSchriftLbl->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->arbeitszeitLbl->ForeColor = System::Drawing::Color::Gray;
			this->arbeitszeitSchriftLbl->ForeColor = System::Drawing::Color::Gray;
		}
		//Fall: Es läuft keine Pause
		else {
			timerArbeitszeit->Start();
		}
	}

	//Führt ein Zwangs-Ende eines Arbeitstages wegen Überschreitung der 23:59-Uhr-Grenze durch
	void neuerTag() {

		//Beendet den Arbeitstag um 23:59 Uhr des Tages, an dem er begonnen wurde
		TimeSpan^ richtigeArbeitszeit = angestellterAkt->neuerTag();
		//Gibt eine Nachricht aus
		String^ text = "Ihr Arbeitstag wurde nach dem letzten Start leider nicht beendet. Er endete daher automatisch um 23:59 Uhr.\nSie haben daher " + richtigeArbeitszeit->Hours + " Stunden und " + richtigeArbeitszeit->Minutes + " Minuten gearbeitet.";
		MessageBox::Show(text, "Arbeitstag auomatisch beendet", MessageBoxButtons::OK, MessageBoxIcon::Information);

		//Werte für die Anzeigen werden zurückgesetzt
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