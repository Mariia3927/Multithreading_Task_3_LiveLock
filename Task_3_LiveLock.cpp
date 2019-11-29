    // Task_3_LiveLock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	LiveLockSample sample;

	std::thread threadA(&LiveLockSample::doA, &sample);
	std::thread threadB(&LiveLockSample::doB, &sample);

	threadA.join();
	threadB.join();
}