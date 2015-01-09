/*
 * Testing.cpp
 *
 *  Created on: Dec 24, 2014
 *      Author: Xander Houtman
 */

#define LOGLEVEL 4

#include "Testing.h"
#include "test/WDTTest.h"
#include "test/ActuatorListTest.h"
#include "TextLogger.h"
#include "test/SensorStateBufferTest.h"
#include "test/PostOfficeTest.h"

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
	ActuatorListTest::test();
	INFO("ActuatorList tests are finished");
}

void testPostOffice()
{
	PostOfficeTest::testPostOffice();
	INFO("PostOffice tests are finished");
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
	//:TODO: call tests
}

void testCanClasses()
{
	//:TODO: call tests
}

