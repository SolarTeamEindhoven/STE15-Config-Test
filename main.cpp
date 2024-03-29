/**
 * Testing configuration main file.
 */

#define LOGLEVEL 4

#include "Testing.h"
#include "mbed.h"
#include "WDT.h"
#include "rtos.h"
#include "logging/TextLogger.h"
//#define USE_CONSOLE_DEBUGGING
#ifdef USE_CONSOLE_DEBUGGING
#include "SemihostSTDStreams.h"
#else
#include "LocalFileSystem.h"
#endif

#include "SDFileSystem.h"

DigitalOut leds[8] =
{
		DigitalOut(P1_28),
		DigitalOut(P1_29),
		DigitalOut(P1_31),
		DigitalOut(P2_2),
		DigitalOut(P2_3),
		DigitalOut(P2_4),
		DigitalOut(P2_5),
		DigitalOut(P2_6)
};
DigitalIn joyup(P1_23);

/**
 * Set the leds on the debug board such that the represent the given number
 * as a binary number. P1.28 being the least significant bit.
 */
void setLedsToNumber(uint8_t number)
{
	for(int index = 0; index < 8; index++)
	if(number & (0x00000001 << index)){
		leds[index] = 1;
	}
	else
	{
		leds[index] = 0;
	}
}

#define RUSH

/**
 * Function that will block until the joystick is pushed up.
 */
void waitForUser()
{
#ifndef RUSH
	while(joyup)
	{
		//empty body
	}
	while(!joyup)
	{
		//empty body
	}
#endif
}

int main() {
    /**
     * Testing the ESLib is done in several phases.
     *
     * The leds indicate the current state of the testing progress.
     * After the tests of a module are finished, the leds change to the next state.
     * When this happens the user has to push the joystick up to continue the testing.
     * This allows the detection of a hardfault, since that will cause the testing
     * progress to be reset.
     *
     * When the testing starts or is reset, all of the leds are turned off.
     */
	setLedsToNumber(0);
	bool resetByWDT = STE2015::WatchDogTimer::causedReset();

#ifdef USE_CONSOLE_DEBUGGING
	STE2015::SemihostSTDStreams stream(true);
	STE2015::Debugger::setLogFile(stdout);
#else
	LocalFileSystem fs("local");
	FILE* logFile = fopen("/local/output.log", "a");
	if(logFile != NULL)
	{
		STE2015::Debugger::setLogFile(logFile);
	}
#endif

	INFO("\n\n");

	ERROR("ERROR method of Text logger is working if you see this message");
	WARN ( "WARN method of Text logger is working if you see this message");
	DBG  (  "DBG method of Text logger is working if you see this message");
	INFO ( "INFO method of Text logger is working if you see this message");

	if (!resetByWDT) {
//		testSensorStateBuffer();
//		setLedsToNumber(1);
//		waitForUser();
//		testAbstractActuator();
//		setLedsToNumber(2);
//		waitForUser();
//		testActuatorList();
//		setLedsToNumber(3);
//		waitForUser();
//		testPostOffice();
//		setLedsToNumber(4);
//		waitForUser();
//		testAbstractSensor();
//		setLedsToNumber(5);
//		waitForUser();
//		testBaseSensor();
//		setLedsToNumber(6);
//		waitForUser();
//		testBaseActuator();
//		setLedsToNumber(7);
//		waitForUser();
//		sdlTest();
//		setLedsToNumber(8);
//		waitForUser();
//		testAcceptanceFilter();
//		setLedsToNumber(9);
//		waitForUser();
//		testCanClasses();
//		setLedsToNumber(10);
//		waitForUser();
//		testPBValueQueue();
//		setLedsToNumber(11);
		waitForUser();
		integrationTest();
		setLedsToNumber(12);

		//WDT timer may have caused the reset. It's a bit special regarding the testing!
		waitForUser();
		//testWDT();
		setLedsToNumber(255);
	}
	else
	{
		//Will never get logged due to hardfault disconnecting the debugger
		INFO("WDT test succeeded");

		setLedsToNumber(10);
		waitForUser();
	}

	int number = 0;
	while(true)
	{
		//Victory dance
		setLedsToNumber(number);
		rtos::Thread::wait_ms(10);
		number++;
	}
}
