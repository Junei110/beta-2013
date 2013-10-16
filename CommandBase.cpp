#include "CommandBase.h"
#include "Subsystems/DriveTrain.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
DriveTrain* CommandBase::driveTrain = NULL;
OI* CommandBase::oi = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	driveTrain = new DriveTrain(0,0,0,0,0,0,0,0);
	
	oi = new OI();
}
