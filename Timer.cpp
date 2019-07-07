//
// Created by vittorio on 12/07/17.
//

#include "Timer.h"

void Timer::reset(bool toZero) {
    if (toZero)
        Set(0,0,0,0);
    playing = false;
    stopped = false;
    restarted = true;
    timerView->Show(true);
    timerView->SetForegroundColour("black");
}

void Timer::switchStartPause() {
    playing = !playing;
}

void Timer::display() {
    timerView->SetLabel(Format("%X"));
}

void Timer::setVariables() {
    *this-=wxTimeSpan(0,0,0,100);
}

void Timer::blink(unsigned short int ds) {
    if (dseccount != ds)
        dseccount++;
    else{
        dseccount = 0;
        showON = !showON;
        timerView->Show(showON);
    }
}

void Timer::stop() {
    stopped = true;
    restarted = true;
    display();
    switchStartPause();
}

bool Timer::hasStopped() const {
    return stopped;
}

bool Timer::isRestarted() const {
    return restarted;
}
