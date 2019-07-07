//
// Created by vittorio on 13/07/17.
//

#ifndef DATETIMERWIDGET_FORMATDIALOG_H
#define DATETIMERWIDGET_FORMATDIALOG_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/gbsizer.h>
#include <wx/radiobox.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/arrstr.h>
#include <wx/button.h>
#include "DateTimerMain.h"

class FormatDialog : public wxDialog
{
protected:
    wxRadioBox* timeRadio;
    wxStaticText* dateFormatText;
    wxChoice* dateChoice;
    wxButton* OKButton;
    DateTimerMain* parentFrame;

protected:
    virtual void OnTimeRadioboxSelected(wxCommandEvent& event) { event.Skip(); }
    virtual void OnDateChoiceSelected(wxCommandEvent& event) { event.Skip(); }
    virtual void OnOkButtonClicked(wxCommandEvent& event);

public:
    wxRadioBox* GetTimeRadio() { return timeRadio; }
    wxStaticText* GetDateFormatText() { return dateFormatText; }
    wxChoice* GetDateChoice() { return dateChoice; }
    wxButton* GetOKButton() { return OKButton; }
    FormatDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Format Preferences"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(300,220), long style = wxDEFAULT_DIALOG_STYLE);
    virtual ~FormatDialog();
};

#endif //DATETIMERWIDGET_FORMATDIALOG_H
