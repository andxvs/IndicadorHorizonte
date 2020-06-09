#ifndef AccelerometerAngle_h
#define AccelerometerAngle_h
#include <math.h>

class AccelerometerAngle
{
    private:
        float _firstaxis, _secondaxis;
    public:
        AccelerometerAngle(float,float);
        int pitch_acc(float xmeasure, float zmeasure);
        int roll_acc(float ymeasure, float zmeasure);
};

#endif