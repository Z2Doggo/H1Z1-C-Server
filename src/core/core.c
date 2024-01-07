typedef struct Timer
{
    HANDLE timer;
    i32 timer_seconds;
} Timer;

void CALLBACK TimerCallback(PVOID lpParam, BOOLEAN TimerOrWaitFired)
{
    (void)TimerOrWaitFired;
    Timer *timer = (Timer *)lpParam;
    (void)timer;

    printf_s("Timer expired!\n");
}

Timer *createTimer(int seconds)
{
    Timer *timer = (Timer *)malloc(sizeof(Timer));
    if (timer)
    {
        timer->timer_seconds = seconds;
        timer->timer = CreateWaitableTimer(NULL, TRUE, NULL);
    }
    return timer;
}

void startTimer(Timer *timer)
{
    if (timer)
    {
        LARGE_INTEGER dueTime;
        dueTime.QuadPart = -(timer->timer_seconds * 10000000LL);
        SetWaitableTimer(timer->timer, &dueTime, 0, (PTIMERAPCROUTINE)TimerCallback, timer, FALSE);
    }
}

void stopTimer(Timer *timer)
{
    if (timer)
    {
        CancelWaitableTimer(timer->timer);
        free(timer);
    }
}

u64 generateRandomGuid()
{
    u64 part1 = ((u64)rand() << 32) | rand();
    u64 part2 = ((u64)rand() << 32) | rand();

    u64 result = part1 ^ part2;

    return result;
}

u32 createSessionId()
{
    return (u32)(rand() % 0xffffffff);
}

i64 getServerTime()
{
    i64 _startTime = 0;
    i64 _serverTime = 0;

    i64 delta = (i64)(time(0) * 1000) - _startTime;
    return _serverTime + delta;
}
