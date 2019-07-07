//
// Created by vittorio on 13/07/17.
//

#include "Time.h"

wxString Time::getTime() const {
    if (h24)
        return Now().Format("%X");
    else
        return Now().Format("%r");
}

void Time::setTimeFormat(bool timeFormat) {
    h24 = timeFormat;
}
