#include "Stealth.h"
#include <windows.h>
#include <iostream>

Stealth::Stealth()
{
	std::cout << "Stealth invoked" << std::endl;
}


Stealth::~Stealth()
{
	std::cout << "Stealth switched off" << std::endl;
}

void Stealth::init() {
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("consoleWindowClass", NULL);
	ShowWindow(stealth, 0);
}
