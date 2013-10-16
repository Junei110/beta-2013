#include "DriveTrain.h"
#include "../Robotmap.h"
#include "WPIlib.h"
static SpeedController* multiplexJags(int id, int idMini)
{
    Jaguar jagMini(idMini);
    Jaguar jag(id);
    Jaguar jaguars[2] = {jag, jagMini};
    return new SpeedControllerMultiplexer(jaguars);
}
 
DriveTrain::DriverTrain(int frontLeft,  int frontLeftMini,
                        int frontRight, int frontRightMini,
                        int backLeft,   int backLeftMini,
                        int backRight,  int backRightMini)
    : Subsystem("Drive Train"),
      drive(multiplexJags(frontLeft, frontLeftMini),
            multiplexJags(frontRight, frontRightMini),
            multiplexJags(backLeft, backLeftMini),
            multiplexJags(backRight, backRightMini)),
      magnitude(0.0),
      direction(0.0),
      rotation(0.0) 
{
    drive.setInvertedMotor(RobotDrive::MotorType::kFrontRight, true);
    drive.setInvertedMotor(RobotDrive::MotorType::kFrontLeft,  false);
    drive.setInvertedMotor(RobotDrive::MotorType::kRearRight,  true);
    drive.setInvertedMotor(RobotDrive::MotorType::kRearLeft,   false);
}
    
void DriveTrain::InitDefaultCommand() {
    //TODO: Add maintain state
	SetDefaultCommand(new MySpecialCommand());
}

   
void Drive::strafe(double mag, double direct){
    magnitude = mag;
    direction = direct;
    update();
}
    
void DriveTrain::rotate(double rot){
        rotation = rot;
        update();
}

void DriveTrain::update(){
    drive.MecanumDrive_Polar(magnitude, direction, rotation);
}
