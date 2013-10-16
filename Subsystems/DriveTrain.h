#ifndef EXAMPLE_SUBSYSTEM_H
#define EXAMPLE_SUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../UpdatableSubsystem.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class DriveTrain: public Subsystem, public UpdatableSubsystem {
private:
	RobotDrive drive;
	// NOTE: Not ramping as in java code
	double magnitude;
	double direction;
	double rotation;
public:
	DriveTrain(int frontLeft,  int frontLeftMini,
	           int frontRight, int frontRightMini,
	           int backLeft,   int backLeftMini,
	           int backRight,  int backRightMini);
	void InitDefaultCommand();
    virtual void update();
	void rotate(double magnitude);
	void strafe(double magnitude, double direction);
};

#endif
