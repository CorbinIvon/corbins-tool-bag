#include "timer.h"

clock_t timer(int mSecs_)
{
    // Get timer

    return clock() + (mSecs_ * CLOCKS_PER_MSEC);
}

Timer::Timer(int tMSecs)
{
    // Start
    start(tMSecs);
}

bool Timer::started()
{
    // Started

    if(clock() > startTime)
    {
        return true;
    }
    return false;
}

bool Timer::finished()
{
    // Finished

    if(clock() >= outTime)
    {
        return true;
    }
    return false;
}

void Timer::start(int mSecs_)
{
    // Start

    // Set

    // Start time
    startTime = clock();

    // MSecs
    mSecs = mSecs_;

    // Out time
    outTime = timer(mSecs_);
}

void Timer::restart()
{
    // Restart

    start(mSecs);
}

void Timer::stop()
{
    // Stop

    // Set

    // Out time
    outTime = clock();
}

// --------------------------- Encapsulation ---------------------------

// MSecs

int Timer::getMSecs()
{
    // Get
    return mSecs;
}
void Timer::setMSecs(int mSecs_)
{
    // Set
    mSecs = mSecs_;
}

// Times

// Start

clock_t Timer::getStartTime()
{
    // Get
    return startTime;
}
void Timer::setStartTime(clock_t startTime_)
{
    // Set
    startTime = startTime_;
}

// Out

clock_t Timer::getOutTime()
{
    // Get
    return outTime;
}
void Timer::setOutTime(clock_t outTime_)
{
    // Set
    outTime = outTime_;
}
