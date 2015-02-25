/*
 * Pong.cpp
 *
 *  Created on: Jan 13, 2015
 *      Author: Xander Houtman
 */

#include "Pong.h"

namespace STE2015
{

CAN Pong::mCAN1(P0_0, P0_1);
CAN Pong::mCAN2(P2_7, P2_8);
int Pong::mLedCount = 0;
DigitalOut* Pong::mLeds = (DigitalOut*) 0;

void Pong::initPong(DigitalOut* leds, int ledCount)
{
	mLeds = leds;
	mLedCount = ledCount;
	mCAN1.attach(Pong::pongFromCan1);
	mCAN2.attach(Pong::pongFromCan2);
}

void Pong::pongFromCan1()
{
	CANMessage ping;
	mCAN1.read(ping);
	executePong(ping);
}

void Pong::pongFromCan2()
{
	CANMessage ping;
	mCAN2.read(ping);
	executePong(ping);

}

void Pong::executePong(CANMessage& ping)
{
	mCAN1.write(ping);
	mCAN2.write(ping);
	for(int i = 0; i < mLedCount; i++)
	{
		mLeds[i] = 1;
	}
}

}


