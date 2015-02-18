/*
 * Testing.cpp
 *
 *  Created on: Dec 24, 2014
 *      Author: Xander Houtman
 */

#define LOGLEVEL 4

// Related header
#include "Testing.h"
// Logging
#include "logging/TextLogger.h"
// Global
#include "test/WDTTest.h"
#include "test/PostOfficeTest.h"
// Actuator
#include "test/actuator/ActuatorListTest.h"
#include "test/actuator/AbstractActuatorTest.h"
// Sensor
#include "test/sensor/SensorStateBufferTest.h"
#include "test/sensor/AbstractSensorTest.h"
// CAN
#include "test/can/AcceptanceFilterTest.h"
#include "test/PbValueQueueTest.h"
#include "test/can/CANTest.h"

#include "test/IntegrationTest.h"

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
	AbstractActuatorTest().test();
	INFO("AbstractActuator tests are finished.");
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
	AbstractSensorTest().test();
	INFO("AbstractSensor tests are finished.");
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
	CANTest::test();
	INFO("CAN tests finished");
}

void testPBValueQueue()
{
	PbValueQueueTest::test();
	INFO("PBValueQueue tests are finished");
}

void integrationTest()
{
	IntegrationTest::test();
	INFO("Integration test finished");
}
