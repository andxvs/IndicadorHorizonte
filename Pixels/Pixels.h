#ifndef Pixels_h
#define Pixels_h
#include "Arduino.h"


class Pixels 
{
    private:
        float _System;
    public:
        Pixels(float System);
        int xvalue1(float System);
        int xvalue2(float System);
        int yvalue1(float System);
        int yvalue2(float System);
        int yoffset(float System);
};

#endif



