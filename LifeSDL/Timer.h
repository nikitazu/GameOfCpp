#pragma once
class Timer
{
public:
    Timer();
    ~Timer();
    
    void Start();
    void Stop();
    void Pause();
    void Unpause();

    int GetTicks();

    bool GetIsStarted() { return _isStarted; }
    bool GetIsPaused() { return _isPaused; }
private:
    int _startTicks;
    int _pausedTicks;

    bool _isStarted;
    bool _isPaused;
};

