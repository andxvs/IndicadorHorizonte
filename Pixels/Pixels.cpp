#include "Arduino.h"
#include "Pixels.h"


Pixels::Pixels(float System)
{
    _System = System;
}

int Pixels::yoffset(float System)
{
    if ((System > 90)&&(System > -90))
    {
        return 90;
    }
    if ((System <= 90) && (System >= -90))
    {   float pixrel = 2.14285;
        int result = System/pixrel;
        return result;
    }
    else
    {
        return 100;
    }
    return 100;
}

int Pixels::xvalue1(float System)
{
    if ((System >= 90) || (System <= -90))
    {
        return 42;
    }
    if ((System < 45) && (System >= -45))
    {
        return 0;
    }
    if (((System < 90) && (System > 45)) || ((System > -90) && (System < -45)))
    {
        int angle = 90 - abs(System);
        int px = 42*tan(angle);
        int x0 = 42 - px;
        return x0;
    }
    return 100;
}

int Pixels::xvalue2(float System)
{   
    if ((System >= 90)|| (System <= -90))
    {
        return 42;
    }
    if ((System <= 45) && (System >= -45))
    {
        return 84;
    }
    if (((System < 90) && (System > 45)) || ((System > -90) && (System < -45)))
    {
        int angle = 90 - System;
        int px = 42*tan(angle);
        int x = 42 - px;
        x = 84 - x;
        return x;
    }
    return 100;
}

int Pixels::yvalue1(float System)
{
    if ((System = 0))
    {
        return 42;
    }
    if ((System >= 90)|| (System <= -90))
    {
        return 84;
    }
    if ((System <= 45) && (System > 0))
    {
        int y0 = tan(System)*84;
        return y0;
    }
    if ((System <= -45) || (System < 0))
    {
        int y0 = tan(System)*42;
        y0 = 42 - y0;
        return y0;
    }
    if (((System < 90) && (System > 45)) || ((System > -90) && (System < -45)))
    {
        return 0;
    }
    return 100;
}

int Pixels::yvalue2(float System)
{
    if ((System = 0))
    {
        return 42;
    }
    if ((System >= 90) || (System <= -90))
    {
        return 0;
    }
    if ((System <= 45) && (System > 0))
    {
        int y2 = tan(System)*42;
        y2 = 42 - y2;
        return y2;
    }
    if ((System <= -45) || (System < 0))
    {
        int y2o = tan(System)*42;
        y2o = 42 - y2o;
        int y2 = 84 - y2o;
        return y2;
    }
    if (((System < 90) && (System > 45)) || ((System > -90) && (System < -45)))
    {
        return 84;
    }
    return 100;
}