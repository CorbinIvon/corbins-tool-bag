#ifndef _FILE_TIMER_
#define _FILE_TIMER_

#define CLOCKS_PER_MSEC (CLOCKS_PER_SEC/1000)

#include <ctime>

// --------------------------- Timer ---------------------------

clock_t timer(int mSecs_);

class Timer
{
public:
    explicit Timer(int tMSecs = 2000);

private:
    // Times
    clock_t startTime;
    clock_t outTime;

    // MSecs
    int mSecs;
public:

    bool started();
    bool finished();

    // Control
    void start(int mSecs_);
    void restart();
    void stop();

    // --------------------------- Encapsulation ---------------------------

    // MSecs
    int getMSecs();
    void setMSecs(int mSecs_);

    // Times

    // Start
    clock_t getStartTime();
    void setStartTime(clock_t startTime_);

    // Out
    clock_t getOutTime();
    void setOutTime(clock_t outTime_);
};

#endif // _FILE_TIMER_
