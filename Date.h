//
// Created by vittorio on 12/07/17.
//

#ifndef DATETIMERWIDGET_DATE_H
#define DATETIMERWIDGET_DATE_H

#include <wx/stattext.h>

enum{ DEFAULT_FORMAT=0, EU_FORMAT, US_FORMAT, WEEK_FORMAT };

class Date : public wxDateTime {
    unsigned short int format;
public:
    explicit Date() : format(DEFAULT_FORMAT) {}
    void setFormat(unsigned short int f) { format = f; };
    wxString getDate() const;
};


#endif //DATETIMERWIDGET_DATE_H
