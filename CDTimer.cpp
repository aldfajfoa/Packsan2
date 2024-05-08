#include "CDTimer.h"

const int DEF_TIMER_TIME{ 5 };

CDTimer::CDTimer(GameObject* parent)
    :TIMER_INIT_TIME_(DEF_TIMER_TIME),
    CountDownTimer_(DEF_TIMER_TIME),
    isTimerRun_(true)
{
    oldTime_ = timeGetTime();
};


CDTimer::CDTimer(GameObject* parent, double _initTime)
    :TIMER_INIT_TIME_(_initTime),
    CountDownTimer_(_initTime),
    isTimerRun_(true)
{
    oldTime_ = timeGetTime();
};

bool CDTimer::IsTimeOver()
{
    return(CountDownTimer_ <= 0);
}

void CDTimer::ResetTimer()
{
    CountDownTimer_ = TIMER_INIT_TIME_;
    StartTimer();
}

void CDTimer::StartTimer()
{
    isTimerRun_ = true;
}

void CDTimer::StopTimer()
{
    isTimerRun_ = false;
}

void CDTimer::Initialize()
{

}

void CDTimer::Update()
{
    DWORD nowTime = timeGetTime();
    int deltaTime = nowTime - oldTime_;
    if (isTimerRun_)
        CountDownTimer_ = CountDownTimer_ - (float)deltaTime / 1000.0f;
    oldTime_ = nowTime;
}

void CDTimer::Draw()
{
}

void CDTimer::Release()
{
}