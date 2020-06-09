#ifndef AngleFilter_h
#define AngleFilter_h
#include <math.h>

class AngleFilter
{
    private:
        float _sysangle, _gyroaxis, _dt, _accangle;
    public:
        AngleFilter(float, float, float, float);
        int FilteredPitch(float sysangle, float gyroaxis, float dt, float accangle);
        int FilteredRoll(float sysangle, float gyroaxis, float dt, float accangle);
};

#endif