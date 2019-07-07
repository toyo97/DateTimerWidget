//
// Created by vittorio on 12/07/17.
//

#include "DateTimerMain.h"
#include "DateTimerApp.h"


IMPLEMENT_APP(DateTimerApp)

bool DateTimerApp::OnInit()
{

    DateTimerMain *mainFrame = new DateTimerMain(0);
    mainFrame->Show(true);

    return true;
}