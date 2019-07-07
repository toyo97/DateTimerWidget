//
// Created by vittorio on 13/07/17.
//

#include "FormatDialog.h"

FormatDialog::FormatDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
        : wxDialog(parent, id, title, pos, size, style)
{
    wxIcon icn;
    if (icn.LoadFile(wxT("../icons/preferences_16.png"), wxBITMAP_TYPE_PNG ))
        SetIcon(icn);

    parentFrame = static_cast<DateTimerMain*>(parent);
    wxGridBagSizer* gridBagSizer77 = new wxGridBagSizer(0, 0);
    this->SetSizer(gridBagSizer77);

    wxBoxSizer* boxSizer74 = new wxBoxSizer(wxVERTICAL);

    gridBagSizer77->Add(boxSizer74, wxGBPosition(0,0), wxGBSpan(1,1), wxALL|wxALIGN_CENTER_HORIZONTAL, 5);

    wxArrayString timeRadioArr;
    timeRadioArr.Add(_("24h"));
    timeRadioArr.Add(_("12h"));
    timeRadio = new wxRadioBox(this, wxID_ANY, _("Time Format"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), timeRadioArr, 1, 0);
    timeRadio->SetSelection(0);

    boxSizer74->Add(timeRadio, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);

    wxBoxSizer* boxSizer75 = new wxBoxSizer(wxVERTICAL);

    gridBagSizer77->Add(boxSizer75, wxGBPosition(0,1), wxGBSpan(1,1), wxLEFT|wxRIGHT|wxTOP|wxALIGN_CENTER_HORIZONTAL, 5);

    dateFormatText = new wxStaticText(this, wxID_ANY, _("Date Format"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);

    boxSizer75->Add(dateFormatText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);

    wxArrayString dateChoiceArr;
    dateChoiceArr.Add(wxT("23 February 2017"));
    dateChoiceArr.Add(wxT("23/02/2017"));
    dateChoiceArr.Add(wxT("02/23/2017"));
    dateChoiceArr.Add(wxT("Thu 23 February"));
    dateChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), dateChoiceArr, 0);
    dateChoice->SetSelection(0);

    boxSizer75->Add(dateChoice, 0, wxRIGHT|wxTOP|wxBOTTOM, 5);

    OKButton = new wxButton(this, wxID_OK, _("OK"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);

    gridBagSizer77->Add(OKButton, wxGBPosition(1,1), wxGBSpan(1,1), wxALL|wxALIGN_RIGHT, 10);

    SetName(wxT("FormatDialog"));
    SetSize(300,220);
    if (GetSizer()) {
        GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }

    // Connect events
    timeRadio->Connect(wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler(FormatDialog::OnTimeRadioboxSelected), NULL, this);
    dateChoice->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(FormatDialog::OnDateChoiceSelected), NULL, this);
    OKButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FormatDialog::OnOkButtonClicked), NULL, this);

}

FormatDialog::~FormatDialog()
{
    timeRadio->Disconnect(wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler(FormatDialog::OnTimeRadioboxSelected), NULL, this);
    dateChoice->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(FormatDialog::OnDateChoiceSelected), NULL, this);
    OKButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FormatDialog::OnOkButtonClicked), NULL, this);

}

void FormatDialog::OnOkButtonClicked(wxCommandEvent &event) {
    if(timeRadio->GetSelection())
        parentFrame->getTime()->setTimeFormat(false);
    else
        parentFrame->getTime()->setTimeFormat(true);

    parentFrame->getDate()->setFormat(dateChoice->GetSelection());

    delete this;
}
