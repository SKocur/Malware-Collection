#include <windows.h>
#include <iostream>

void draw(int key) {
	if (key == 1) {
		POINT p;
		if (GetCursorPos(&p))
		{
			HDC screenDC = ::GetDC(0);
			Ellipse(screenDC, p.x - 50, p.y - 50, p.x + 50, p.y + 50);
		}
	}
}

void stealth() {
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("consoleWindowClass", NULL);
	ShowWindow(stealth, 0);
}

int main(void) {
	stealth();

	char i;
	while (1) {
		for (i = 8; i <= 190; i++) {
			if (GetAsyncKeyState(i))
				draw(i);
		}
	}
	return 0;
}
