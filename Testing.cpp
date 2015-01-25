/*
 * Testing.cpp
 *
 *  Created on: Dec 24, 2014
 *      Author: Xander Houtman
 */

#define LOGLEVEL 4

#include "Testing.h"
#include "test/WDTTest.h"
#include "test/actuator/ActuatorListTest.h"
#include "TextLogger.h"
#include "test/sensor/SensorStateBufferTest.h"
#include "test/PostOfficeTest.h"
#include "test/can/AcceptanceFilterTest.h"

using namespace STE2015;

void testWDT()
{
	//Failure of it returns (different from other tests)
	WDTTest::testTimer();
	INFO("WDT test Failed. Should have generated hardfault.");
}

void testSensorStateBuffer()
{
	SensorStateBufferTest().SensorStateBufferTests();
	INFO("SensorStateBuffer tests are finished");
}

void testAbstractActuator()
{
	//:TODO: call tests
}

void testActuatorList()
{
#ifdef COMPILE_ACTUATOR_TESTS
	ActuatorListTest::test();
	INFO("ActuatorList tests are finished");
#endif
}

void testPostOffice()
{
#ifdef COMPILE_ACTUATOR_TESTS
	PostOfficeTest::testPostOffice();
	INFO("PostOffice tests are finished");
#endif
}

void testAbstractSensor()

{
	//:TODO: call tests
}

void testBaseSensor()

{
	//:TODO: call tests
}

void testBaseActuator()
{
	//:TODO: call tests
}

void testAcceptanceFilter()
{
	AcceptanceFilterTest::test();
}

void testCanClasses()
{
	//:TODO: call tests
}

