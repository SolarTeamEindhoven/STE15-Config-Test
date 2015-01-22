
#define LOGLEVEL 4

#include <mbed.h>
#include "ESLib.h"
#include "PotentioMeter.h"
#include "Led.h"
#include "CANReader.h"
#include "CANSensor.h"
#include "FIRFilter.h"
#include "SDFileSystem.h"

// Uncomment to use hardware sensors on this board instead of CAN sensors
#define IMPLEMENT_SENSOR_HARDWARE

using namespace STE2015;

static osThreadId mainThreadId;

int main()
{
	mainThreadId = rtos::Thread::gettid();

	SDFileSystem local("sd");
	//Initialize text loggerLocalFileSystem local("local");
	FILE* file = fopen("/sd/output.log", "a");
	STE2015::Debugger::setLogFile(file);
	INFO("\nNEW LOG\n");

	// Create dummy list
	STE2015::LED0 l0;
	STE2015::LED1 l1;
	STE2015::LED2 l2;
	STE2015::LED3 l3;
	STE2015::LED4 l4;
	STE2015::LED5 l5;
	STE2015::LED6 l6;
	STE2015::LED7 l7;

	AbstractActuator* listAbst[8] = {&l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7};
	ActuatorList actuators(listAbst, (size_t) 8);

	mbed::CAN CANBus(PinName::P0_0, PinName::P0_1);
	CANBus.frequency(10000);

	// Initialize post office
	PostOffice po(CANBus, actuators);

	// Create sensors
#ifdef IMPLEMENT_SENSOR_HARDWARE
	JoyStickUp joystickUp(NULL, po);
	PotentioMeter potentio(NULL, po);

	AbstractCANSensor* listSens[0] = {};
	CanSensorList canSensors(listSens, (size_t) 0);
#else
	CANSensor<JoyUpSensorData> joystickSensor(NULL, 500, po);
	CANSensor<PotentioData> potentioSensor(NULL, 500, po);

	AbstractCANSensor* listSens[2] = {static_cast<AbstractCANSensor*>(&joystickSensor), static_cast<AbstractCANSensor*>(&potentioSensor)};
	CanSensorList canSensors(listSens, (size_t) 2);
#endif

	CANReader reader(CANBus, canSensors, 2);

	rtos::Thread::signal_wait(SIGNAL_TERMINATE);
}

void signalMainThread(MainThreadSignalList signal)
{
	osSignalSet(mainThreadId, signal);
}
