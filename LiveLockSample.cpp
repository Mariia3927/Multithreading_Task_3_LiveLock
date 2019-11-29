#include "pch.h"
#include "LiveLockSample.h"


void LiveLockSample::doA() {

	while (!m_first.try_lock()) {

		std::cout << std::this_thread::get_id() << " : waits for lock 1"<<'\n';
		Sleep(100);
	}
		
	std::cout << std::this_thread::get_id() << " : holds lock 1"<< '\n';

	while (!m_second.try_lock()) {
		std::cout << std::this_thread::get_id() << " : waits for lock 2" << '\n';
		Sleep(100);
	}
	std::cout << std::this_thread::get_id() << " : holds lock 2" << '\n';
			
	std::cout << std::this_thread::get_id() << " : critical section of doA()" << '\n';
			
	m_second.unlock();
	std::cout << std::this_thread::get_id() << " : does not hold lock 2 any longer" << '\n';
		
	m_first.unlock();
	std::cout << std::this_thread::get_id() << " : does not hold lock 1 any longer" << '\n';
}

void LiveLockSample::doB() 
{
	while (!m_second.try_lock()) 
	{
		std::cout << std::this_thread::get_id() << " : waits for lock 2" << '\n';
		Sleep(100);
	}
	std::cout << std::this_thread::get_id() << " : holds lock 2" << '\n';

	while (!m_first.try_lock()) {

		std::cout << std::this_thread::get_id() << " : waits for lock 1" << '\n';
		Sleep(100);
	}

	std::cout << std::this_thread::get_id() << " : critical section of doB()" << '\n';
			
	m_first.unlock();
	std::cout << std::this_thread::get_id() << " : does not hold lock 1 any longer" << '\n';

	m_second.unlock();
	std::cout << std::this_thread::get_id() << " : does not hold lock 2 any longer" << '\n';
}