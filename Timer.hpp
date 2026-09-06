#ifndef __TIMER_HPP__
#define __TIMER_HPP__

#include "raylib.h"

typedef struct Timer {
    double startTime;   // Start time (seconds)
    double lifeTime;    // Lifetime (seconds)
} Timer;

void StartTimer(Timer *timer, double lifetime);
double GetElapsed(Timer timer);

#endif
