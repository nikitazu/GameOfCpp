#include "stdafx.h"
#include "Timer.h"


// Init
// ====

Timer::Timer() {
    _startTicks = 0;
    _pausedTicks = 0;
    _isStarted = false;
    _isPaused = false;
}

Timer::~Timer() {
}


// Public
// ======

void Timer::Start() {
    _isStarted = true;
    _isPaused = false;
    _startTicks = SDL_GetTicks();
}

void Timer::Stop() {
    _isStarted = false;
    _isPaused = false;
}

void Timer::Pause() {
    if (_isStarted && !_isPaused) {
        _isPaused = true;
        _pausedTicks = SDL_GetTicks() - _startTicks;
    }
}

void Timer::Unpause() {
    if (_isPaused) {
        _isPaused = false;
        _startTicks = SDL_GetTicks() - _pausedTicks;
        _pausedTicks = 0;
    }
}

int Timer::GetTicks() {
    return !_isStarted ? 0 : _isPaused ? _pausedTicks : SDL_GetTicks() - _startTicks;
}

