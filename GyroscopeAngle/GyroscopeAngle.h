#ifndef GyroscopeAngle_h
#define GyroscopeAngle_h

class GyroscopeAngle 
{
    private:
        float _axis, _dt, _ang;
    public:
        GyroscopeAngle(float,float,float);
        int pitch_gyro(float axis, float dt, float pitch);
        int roll_gyro(float axis, float dt, float roll);
};

#endif