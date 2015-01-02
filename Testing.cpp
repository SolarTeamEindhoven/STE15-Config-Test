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

using namespace STE2015;

void testWDT()
{
	//Failure of it returns (different from other tests)
	WDTTest::testTimer();
	INFO("WDT test Failed. Should have generated hardfault.");
}

void testSensorStateBuffer()
{
	//:TODO: call tests
}

void testAbstractActuator()
{
	//:TODO: call tests
}

void testActuatorList()
{
	ActuatorListTest::test();
	int letMeAddABreakPointPlox;
	letMeAddABreakPointPlox = 0;
	INFO("ActuatorList tests are successful");
}

void testPostOffice()
{
	//:TODO: call tests
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

