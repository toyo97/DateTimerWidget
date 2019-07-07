//
// Created by vittorio on 12/07/17.
//

#ifndef DATETIMERWIDGET_DATETIMERMAIN_H
#define DATETIMERWIDGET_DATETIMERMAIN_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/frame.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/stattext.h>
#include <wx/statline.h>
#include <wx/gbsizer.h>
#include <wx/spinctrl.h>
#include <wx/button.h>
#include <wx/timer.h>
#include "Date.h"
#include "Timer.h"
#include "Time.h"
#include <wx/msgdlg.h>

class DateTimerMain : public wxFrame
{
protected:
    wxMenuBar* menuBar;
    wxMenu* editMenu;
    wxMenuItem* preferencesMenu;
    wxMenu* helpMenu;
    wxMenuItem* aboutMenu;
    wxStaticText* timeText;
    wxStaticText* dateText;
    wxStaticLine* separator;
    wxSpinCtrl* hourSpin;
    wxSpinCtrl* minSpin;
    wxSpinCtrl* secSpin;
    wxStaticText* timerText;
    wxButton* startPauseButton;
    wxButton* resetButton;
    wxTimer* mainTimer;
    wxBoxSizer* mainSizer;
    Date* date;
    Time* time;
    Timer* timer;

protected:
    virtual void OnPreferencesMenuSelected(wxCommandEvent& event);
    virtual void OnAboutMenuSelected(wxCommandEvent& event);
    virtual void OnMainTimer(wxTimerEvent& event);
    virtual void OnStartPauseButtonClicked(wxCommandEvent& event);
    virtual void OnResetButtonClicked(wxCommandEvent &event);
    virtual void OnHourspinTextUpdated(wxCommandEvent& event);
    virtual void OnMinspinTextUpdated(wxCommandEvent& event);
    virtual void OnSecspinTextUpdated(wxCommandEvent& event);

public:
    wxMenuBar* GetMenuBar() { return menuBar; }
    wxStaticText* GetTimeText() { return timeText; }
    wxStaticText* GetDateText() { return dateText; }
    wxStaticLine* GetSeparator() { return separator; }
    wxStaticText* GetTimerText() { return timerText; }
    wxButton* GetStartPauseButton() { return startPauseButton; }
    wxButton* GetResetButton() { return resetButton; }
    wxTimer* GetMainTimer() { return mainTimer; }
    wxSpinCtrl* GetHourSpin() { return hourSpin; }
    wxSpinCtrl* GetMinSpin() { return minSpin; }
    wxSpinCtrl* GetSecSpin() { return secSpin; }
    Date *getDate() const { return date; }
    Time *getTime() const { return time; }
    Timer *getTimer() const { return timer; }

    DateTimerMain(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Date&Timer Widget"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(350,400), long style = wxDEFAULT_FRAME_STYLE);
    virtual ~DateTimerMain();
};



#endif //DATETIMERWIDGET_DATETIMERMAIN_H
