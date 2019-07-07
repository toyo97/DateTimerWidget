//
// Created by vittorio on 12/07/17.
//

#ifndef DATETIMERWIDGET_TIMER_H
#define DATETIMERWIDGET_TIMER_H

#include <wx/stattext.h>

class Timer : public wxDateTime {
    bool playing;
    bool stopped;
    bool showON;
    bool restarted;
    unsigned short int dseccount;
    wxStaticText* timerView;

public:
    explicit Timer(wxStaticText* t) : wxDateTime(0,0,0,0), timerView(t), playing(false), dseccount(0), showON(true), stopped(false) {}
    bool isRestarted() const;
    void setRestarted(bool r) { restarted = r; }
    bool hasStopped() const;
    void reset(bool);
    void switchStartPause();
    void display();
    void setVariables();
    bool isPlaying() const { return playing; }
    void blink(unsigned short int ds);
    void stop();
    void setStopped(bool s) { stopped = s; }
};


#endif //DATETIMERWIDGET_TIMER_H
