#pragma once
class ClTimer
{
public:
    ClTimer();
    ~ClTimer();

    //=============
    // Functions
    //=============

    //----------------
    // Level's Timer
    //----------------
    void LvlTimer();

    //-------------------
    // Spawn's Timer
    //-------------------
    //........................
    // ON
    //........................
    void startSpawnTimer();
    void stopSpawnTimer();
    //........................
    // OFF
    //........................
    void startNoSpawnTimer();
    void stopNoSpawnTimer();

    //---------------
    // Status Check
    //---------------
    //........................
    // ON
    //........................
    bool LvlTimerisOn;
    bool SpawnTimerisOn;
    bool NoSpawnTimerOn;
    //........................
    // OFF
    //........................
    bool LvlTimerisOff;
    bool SpawnTimerisOff;
    bool NoSpawnTimerOff;

private:
    //------------------------
    // Storage of the Ticks
    //------------------------
    Uint32 mStartTicksLvl;
    Uint32 mPausedTicksLvl;

    Uint32 mStartTicksOnSpawn;
    Uint32 mPausedTicksOnSpawn;

    Uint32 mStartTickOffSpawn;
    Uint32 mPausedTickOffSpawn;

    //---------------------
    // Level Timer Status
    //---------------------
    bool mLvlPaused;
    bool mLvlStarted;

    //----------------------
    // Spawn Timer Status
    //----------------------
    //........................
    // ON
    //........................
    bool mOnSpawnedStarted;
    bool mOffSpawnedStarted;
    //........................
    // OFF
    //........................
    bool mOnSpawnedPaused;
    bool mOffSpawnedPaused;
};

