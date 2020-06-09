#include <U8glib.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
// Created libraries
#include <Pixels.h>
#include <PrintLine.h>
#include <GyroscopeAngle.h>
#include <AngleFilter.h>
#include <AccelerometerAngle.h>
// Define variables for code
#define BNO055_SAMPLERATE_DELAY_MS (100)
#define SDO 11
#define SDI 4
#define SCLK 13
#define RST 5
#define CE 3

// Time variables for the Gyroscope, Accelerometer and, angles calculation
unsigned long system_time;
float dt,a,b,c;
uint8_t sys, accelerometer, gyroscope, magnetometer = 0;
float GyrPitch = 0;
float GyrRoll = 0;
float SystemRoll = 0;
float SystemPitch = 0;
float AccPitch = 0;
float AccRoll = 0;
int Yoffset, X0,Y0,X1,Y1;

//Objects declarataion (Instatiation)
Adafruit_BNO055 IMU = Adafruit_BNO055();
U8GLIB_PCD8544 LCD(SCLK,SDO,CE,SDI,RST);
AccelerometerAngle Pitch(a,b);
AccelerometerAngle Roll(a,b);
GyroscopeAngle GyroPitch(a,b,c);
GyroscopeAngle GyroRoll(a,b,c);
AngleFilter SysPitch(a,b,c,dt);
AngleFilter SysRoll(a,b,c,dt);
Pixels SysOffset(a);
Pixels A(a);
Pixels B(a);
Pixels C(a);
Pixels D(a);
PrintLine AA(X0,Y0,X1,Y1,Yoffset);
PrintLine BB(X0,Y0,X1,Y1,Yoffset);
PrintLine CC(X0,Y0,X1,Y1,Yoffset);
PrintLine DD(X0,Y0,X1,Y1,Yoffset);

void setup()
{
    // Established communication between the Arduino and the IMU with I2C protocolo
    IMU.begin();
    //Set LCD display font
    LCD.setFont(u8g_font_6x10);
    //Crystal use initialization for the LCD display 
    IMU.setExtCrystalUse(true);
    // capture the system time
    system_time= millis();
    // Draw the center point of in the LCD screen 
    LCD.drawPixel(42,42);
    
}

void loop()
{
    // System Calibration for the IMU, this method object will return the system calibration
    IMU.getCalibration(&sys, &accelerometer, &magnetometer, &gyroscope);

    // Request accelerometer data from the IMU
    imu::Vector<3> accel = IMU.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);

    // Request gyroscope data from the IMU
    imu::Vector<3> gyro = IMU.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);

    // Request magnetometer data from the IMU
    //imu::Vector<3> magnet = IMU.getVector(Adafruit_BNO055::VECTOR_MAGNETOMETER);

    // Save accelerometer angles in two variables
    AccPitch = Pitch.pitch_acc(accel.x(),accel.z());
    AccRoll = Roll.roll_acc(accel.y(),accel.z());
    
    //define the delta time in seconds to calculate the gyroscope
    dt = (millis()-system_time)/1000.;

    // Save gyroscope angles in two variables
    GyrPitch = GyroPitch.pitch_gyro(gyro.y(),dt,GyrPitch);
    GyrRoll = GyroRoll.roll_gyro(gyro.x(),dt,GyrRoll);

    // Complementary Filter to improve angle measurements

    // Filtered angle systems
    SystemPitch = SysPitch.FilteredPitch(SystemPitch,gyro.y(),dt,AccPitch);
    SystemRoll = SysRoll.FilteredRoll(SystemRoll,gyro.x(),dt,AccRoll);
    
    // Assign into variables the cardinal points for each of the angles lines
    Yoffset = SysOffset.yoffset(SystemPitch);
    int a = A.xvalue1(SystemRoll);
    int b = B.yvalue1(SystemRoll);
    int c = C.xvalue2(SystemRoll);
    int d = D.yvalue2(SystemRoll);

    // Assign the each of the 4 points of the line to be sent to the LCD Screen print
    X0 = AA.x0_val(a,b,c,d,Yoffset);
    Y0 = BB.y0_val(a,b,c,d,Yoffset);
    X1 = CC.x1_val(a,b,c,d,Yoffset);
    Y1 = DD.y1_val(a,b,c,d,Yoffset);

    LCD.firstPage(); // Beginning of the picture loop for the LCD print screen
    do  // Include all you want to show on the display:
    {
      LCD.drawLine(X0, Y0, X1, Y1);  // Draw a line (x0,y0,x1,y1)
      
    }while(LCD.nextPage());  // End of the picture loop

    // System delays and time new definition
    delay(BNO055_SAMPLERATE_DELAY_MS);
    
    // Define new time count to start with the new cycle
    system_time = millis();
    
}
