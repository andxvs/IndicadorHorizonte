#include "Arduino.h"
#include "AccelerometerAngle.h"
#include "math.h"

AccelerometerAngle::AccelerometerAngle(float firstaxis, float secondaxis)
{
    _firstaxis = firstaxis;
    _secondaxis = secondaxis;
}

//Methods
int AccelerometerAngle::pitch_acc(float xmeasure, float zmeasure)
{
    // Ecuacion de grados normalizada en la gravedad
    int angle = 0;
    xmeasure = xmeasure/9.8;
    zmeasure = zmeasure/9.8;
    angle = -atan2(xmeasure,zmeasure)/2/3.1415926*360;
    return angle;
}

int AccelerometerAngle::roll_acc(float ymeasure, float zmeasure)
{
    int angle = 0;
    ymeasure = ymeasure/9.8;
    zmeasure = zmeasure/9.8;
    angle = atan2(ymeasure,zmeasure)/2/3.1415926*360;
    return angle;
}