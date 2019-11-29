#pragma once
#include "pch.h"


class LiveLockSample
{
public:
	void doA();
	void doB();

private:
	std::mutex m_first, m_second;
};

