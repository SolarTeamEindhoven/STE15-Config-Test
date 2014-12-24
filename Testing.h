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
void testTextLogger();
void testPostOffice();
void testAbstractSensor();
void testAbstractActuator();
void testBaseSensor();
void testBaseActuator();
void testSensorStateBuffer();
void testCanClasses();
void testActuators();

#endif /* TESTING_H_ */
