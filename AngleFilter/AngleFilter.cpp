#include "Arduino.h"
#include "AngleFilter.h"

//Constructor
AngleFilter::AngleFilter(float sysangle, float gyroaxis, float dt, float accangle)
{
    _sysangle = sysangle;
    _gyroaxis = gyroaxis;
    _dt = dt;
    _accangle = accangle; 
}

int AngleFilter::FilteredPitch(float sysangle, float gyroaxis, float dt, float accangle)
{   
    int result = 0;
    result = ((sysangle+gyroaxis*dt)*.95+accangle*0.05);
    return result;
}

int AngleFilter::FilteredRoll(float sysangle, float gyroaxis, float dt, float accangle)
{
    int result = 0;
    result = ((sysangle-gyroaxis*dt)*.95+accangle*0.05);
    return result;
}