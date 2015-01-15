
#include <mbed.h>
#include "ESLib.h"
#include "PotentioMeter.h"
#include "Led.h"
#include "CANReader.h"
#include "CANSensor.h"

// Uncomment to use hardware sensors on this board instead of CAN sensors
//#define IMPLEMENT_SENSOR_HARDWARE

using namespace STE2015;

int main() {
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

	// Create joystick sensor
#ifdef IMPLEMENT_SENSOR_HARDWARE
	JoyStickUp joystickUp(NULL, po);
	PotentioMeter potentio(NULL, po);
#else
	CANSensor<JoystickUpData> joystickSensor(NULL, 500, po);
	CANSensor<PotentioData> potentioSensor(NULL, 500, po);
#endif

	AbstractCANSensor* listSens[2] = {static_cast<AbstractCANSensor*>(&joystickSensor), static_cast<AbstractCANSensor*>(&potentioSensor)};
	CanSensorList canSensors(listSens, (size_t) 2);

	CANReader reader(CANBus, canSensors, 2);

	while(1)
	{
		rtos::Thread::wait(1000);
		// Make sure we don't cut off the main thread
	}
}
