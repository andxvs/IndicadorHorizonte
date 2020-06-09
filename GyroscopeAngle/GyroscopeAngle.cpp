#include "Arduino.h"
#include "GyroscopeAngle.h"

GyroscopeAngle::GyroscopeAngle(float axis, float dt, float ang)
{
    _axis = axis;
    _dt = dt;
    _ang = ang;
}

int GyroscopeAngle::pitch_gyro(float axis, float dt, float ang)
{   
    int angle = 0;
    angle = ang + axis*dt;
    return angle;
}
int GyroscopeAngle::roll_gyro(float axis, float dt, float ang)
{   
    int angle = 0;
    angle = ang - axis*dt;
    return angle;
}