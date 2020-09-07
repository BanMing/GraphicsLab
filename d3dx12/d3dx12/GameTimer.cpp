#include "GameTimer.h"
GameTimer::GameTimer()
	:mSecondsPerCount(0.f), mDeltaTime(-1.f), mBaseTime(0.f),
	mPausedTime(0.f), mPrevTime(0.f), mCurrTime(0.f), mStopped(false)
{
	__int64 countsPerSec;
	//QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
	mSecondsPerCount = 1.0 / (double)countsPerSec;}