/*
 * Pong.h
 *
 *  Created on: Jan 13, 2015
 *      Author: Xander Houtman
 */

#ifndef PONG_H_
#define PONG_H_

#include "mbed.h"
#include "CAN.h"

namespace STE2015
{
class Pong
{
public:
	static void initPong(DigitalOut* leds, int ledCount);
	static DigitalOut* mLeds;
	static int mLedCount;
	static CAN mCAN1;
	static CAN mCAN2;
	static void pongFromCan1();
	static void pongFromCan2();
	static void executePong(CANMessage& ping);
};
}



#endif /* PONG_H_ */
