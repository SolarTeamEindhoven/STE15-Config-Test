/*
 * Testing.h
 *
 *  Created on: Dec 24, 2014
 *      Author: Xander Houtman
 */

#ifndef TESTING_H_
#define TESTING_H_

#define LOGLEVEL 4

//:TODO: define a testing method for each component.
void testWDT();
void testActuatorList();
void testSensorStateBuffer();
void testAbstractActuator();
void testPostOffice();
void testAbstractSensor();
void testBaseSensor();
void testBaseActuator();
void testAcceptanceFilter();
void testCanClasses();
void testPBValueQueue();
void integrationTest();
void sdlTest();

#endif /* TESTING_H_ */
