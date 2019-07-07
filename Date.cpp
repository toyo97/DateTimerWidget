//
// Created by vittorio on 12/07/17.
//

#include "Date.h"

wxString Date::getDate() const {
    wxString date;
    if (format == DEFAULT_FORMAT)
        date = Now().Format("%e %B %Y");
    else if (format == EU_FORMAT)
        date = Now().Format("%d/%m/%Y");
    else if (format == US_FORMAT)
        date = Now().Format("%m/%d/%Y");
    else if (format == WEEK_FORMAT)
        date = Now().Format("%a %e %B");
    else
        date = wxT("Invalid choice");
    return date;
}