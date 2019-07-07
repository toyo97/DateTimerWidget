//
// Created by vittorio on 12/07/17.
//

#include "DateTimerMain.h"
#include "FormatDialog.h"

DateTimerMain::DateTimerMain(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
        : wxFrame(parent, id, title, pos, size, style)
{
    wxIcon icn;
    if (icn.LoadFile(wxT("../icons/clock_16.png"), wxBITMAP_TYPE_PNG ))
        SetIcon(icn);

    menuBar = new wxMenuBar(0);
    this->SetMenuBar(menuBar);

    editMenu = new wxMenu();
    menuBar->Append(editMenu, _("&Edit"));

    preferencesMenu = new wxMenuItem(editMenu, wxID_PREFERENCES, _("&Format... \tCTRL+F"), wxT("Choose date and time format"), wxITEM_NORMAL);
    editMenu->Append(preferencesMenu);

    helpMenu = new wxMenu();
    menuBar->Append(helpMenu, _("Help"));

    aboutMenu = new wxMenuItem(helpMenu, wxID_ABOUT, _("About..."), wxT("About info"), wxITEM_NORMAL);
    helpMenu->Append(aboutMenu);

    mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    wxBoxSizer* boxSizer79 = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(boxSizer79, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10);

    timeText = new wxStaticText(this, wxID_ANY, _("00:00:00"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxALIGN_CENTER);
    wxFont timeTextFont(22, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Myriad Hebrew"));
    timeText->SetFont(timeTextFont);

    boxSizer79->Add(timeText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);

    dateText = new wxStaticText(this, wxID_ANY, _("January 1 2017"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxALIGN_CENTER);
    wxFont dateTextFont(14, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Myriad Hebrew"));
    dateText->SetFont(dateTextFont);

    boxSizer79->Add(dateText, 0, wxLEFT|wxRIGHT|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL, 10);

    separator = new wxStaticLine(this, wxID_ANY, wxDefaultPosition , wxDLG_UNIT(this, wxSize(-1,-1)), wxLI_HORIZONTAL);

    mainSizer->Add(separator, 0, wxALL | wxEXPAND, 5);

    wxGridBagSizer* gridBagSizer78 = new wxGridBagSizer(0, 0);
    mainSizer->Add(gridBagSizer78, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 20);
    wxBoxSizer* boxSizer86 = new wxBoxSizer(wxHORIZONTAL);

    gridBagSizer78->Add(boxSizer86, wxGBPosition(1,0), wxGBSpan(1,1), wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

    hourSpin = new wxSpinCtrl(this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(20,-1)), wxSP_ARROW_KEYS);
    hourSpin->SetRange(0, 23);
    hourSpin->SetValue(0);

    boxSizer86->Add(hourSpin, 0, wxALL, 5);

    minSpin = new wxSpinCtrl(this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(20,-1)), wxSP_ARROW_KEYS);
    minSpin->SetRange(0, 59);
    minSpin->SetValue(0);

    boxSizer86->Add(minSpin, 0, wxALL, 5);

    secSpin = new wxSpinCtrl(this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(20,-1)), wxSP_ARROW_KEYS);
    secSpin->SetRange(0, 59);
    secSpin->SetValue(0);

    boxSizer86->Add(secSpin, 0, wxALL, 5);

    timerText = new wxStaticText(this, wxID_ANY, _("00:00:00"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxALIGN_CENTRE);
    wxFont timerTextFont(24, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("OCR A Std"));
    timerText->SetFont(timerTextFont);

    gridBagSizer78->Add(timerText, wxGBPosition(0,0), wxGBSpan(1,1), wxLEFT|wxRIGHT|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL, 10);

    wxBoxSizer* boxSizer81 = new wxBoxSizer(wxHORIZONTAL);

    gridBagSizer78->Add(boxSizer81, wxGBPosition(2,0), wxGBSpan(1,1), wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL, 70);

    startPauseButton = new wxButton(this, wxID_ANY, _("Start"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);

    boxSizer81->Add(startPauseButton, 0, wxRIGHT, 5);

    resetButton = new wxButton(this, wxID_ANY, _("Reset"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);

    boxSizer81->Add(resetButton, 0, wxLEFT, 5);
    gridBagSizer78->AddGrowableCol(0);
    gridBagSizer78->AddGrowableRow(1);

    mainTimer = new wxTimer;
    mainTimer->Start(100, false);

    time = new Time;
    date = new Date;
    timer = new Timer(timerText);

    CreateStatusBar();
    SetStatusText("Welcome the Date&Timer Widget v3.0");

    SetName(wxT("DateTimerMain"));
    SetSize(350,400);

    if (GetSizer()) {
        GetSizer()->Fit(this);
    }

    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }

    // Connect events
    this->Connect(preferencesMenu->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(DateTimerMain::OnPreferencesMenuSelected), NULL, this);
    this->Connect(aboutMenu->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(DateTimerMain::OnAboutMenuSelected), NULL, this);
    hourSpin->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(DateTimerMain::OnHourspinTextUpdated), NULL, this);
    minSpin->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(DateTimerMain::OnMinspinTextUpdated), NULL, this);
    secSpin->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(DateTimerMain::OnSecspinTextUpdated), NULL, this);
    startPauseButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DateTimerMain::OnStartPauseButtonClicked), NULL, this);
    resetButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DateTimerMain::OnResetButtonClicked), NULL, this);
    mainTimer->Connect(wxEVT_TIMER, wxTimerEventHandler(DateTimerMain::OnMainTimer), NULL, this);

}

DateTimerMain::~DateTimerMain()
{
    this->Disconnect(preferencesMenu->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(DateTimerMain::OnPreferencesMenuSelected), NULL, this);
    this->Disconnect(aboutMenu->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(DateTimerMain::OnAboutMenuSelected), NULL, this);
    hourSpin->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(DateTimerMain::OnHourspinTextUpdated), NULL, this);
    minSpin->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(DateTimerMain::OnMinspinTextUpdated), NULL, this);
    secSpin->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(DateTimerMain::OnSecspinTextUpdated), NULL, this);
    startPauseButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DateTimerMain::OnStartPauseButtonClicked), NULL, this);
    resetButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(DateTimerMain::OnResetButtonClicked), NULL, this);
    mainTimer->Disconnect(wxEVT_TIMER, wxTimerEventHandler(DateTimerMain::OnMainTimer), NULL, this);

    mainTimer->Stop();
    wxDELETE( mainTimer );

}

void DateTimerMain::OnMainTimer(wxTimerEvent &event) {
    dateText->SetLabel(date->getDate());
    timeText->SetLabel(time->getTime());
    if (timer->isPlaying()){
        if (timer->GetHour() != 0 || timer->GetMinute()!=0 || timer->GetSecond() != 0 || timer->GetMillisecond() != 0){
            timer->setVariables();
            timer->display();
        }
        else{
            timer->stop();
            startPauseButton->SetLabel(wxT("Start"));
            timerText->SetForegroundColour(wxColour("red"));
        }
    }
    if (timer->hasStopped())
        timer->blink(5);
}

void DateTimerMain::OnStartPauseButtonClicked(wxCommandEvent &event) {
    if(timer->isPlaying())
        startPauseButton->SetLabel(wxT("Start"));
    else {
        startPauseButton->SetLabel(wxT("Pause"));
        if (timer->isRestarted()) {
            timer->reset(false);
            timer->Set(hourSpin->GetValue(), minSpin->GetValue(), secSpin->GetValue());
            timer->setRestarted(false);
        }
    }
    timer->switchStartPause();
}

void DateTimerMain::OnResetButtonClicked(wxCommandEvent &event) {
    timer->reset(true);
    startPauseButton->SetLabel(wxT("Start"));
    timer->display();
}

void DateTimerMain::OnAboutMenuSelected(wxCommandEvent &event) {
    wxMessageBox("This is a wxWidgets' timer with current time and date. \nCredits to Vittorio Zampinetti", "About DateTimer Widget", wxOK | wxICON_INFORMATION);
}

void DateTimerMain::OnPreferencesMenuSelected(wxCommandEvent &event) {
    FormatDialog* dialog = new FormatDialog(this);
    dialog->Show(true);
}

void DateTimerMain::OnHourspinTextUpdated(wxCommandEvent &event) {
    if(timer->hasStopped())
        timer->reset(false);
    if(!timer->isPlaying()) {
        timer->SetHour(hourSpin->GetValue());
        timer->display();
    }
}

void DateTimerMain::OnMinspinTextUpdated(wxCommandEvent &event) {
    if (timer->hasStopped())
        timer->reset(false);
    if (!timer->isPlaying()) {
        timer->SetMinute(minSpin->GetValue());
        timer->display();
    }
}

void DateTimerMain::OnSecspinTextUpdated(wxCommandEvent &event) {
    if (timer->hasStopped())
        timer->reset(false);
    if (!timer->isPlaying()) {
        timer->SetSecond(secSpin->GetValue());
        timer->display();
    }
}
