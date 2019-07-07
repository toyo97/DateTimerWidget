//
// Created by vittorio on 13/07/17.
//

#ifndef DATETIMERWIDGET_TIME_H
#define DATETIMERWIDGET_TIME_H


#include <wx/datetime.h>

class Time : public wxDateTime {
    bool h24;
public:
    Time() : h24(true) {}
    void setTimeFormat(bool timeFormat);
    wxString getTime() const;
};


#endif //DATETIMERWIDGET_TIME_H
