#include "ControlConsole.h"


ControlConsole::ControlConsole()
{
}

void ControlConsole::fontsize(int a, int b)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
	lpConsoleCurrentFontEx->dwFontSize.X = a;
	lpConsoleCurrentFontEx->dwFontSize.Y = b;
	SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
}

void ControlConsole::setcolor(unsigned short color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}

void ControlConsole::gotoxy(int x, int y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };

	SetConsoleCursorPosition(hStdout, position);
}

void ControlConsole::getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);                             //we see the position of the  clicking area X-axis and Y-axis
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}


void ControlConsole::rightSideMessage(string a, string b)
{
	gotoxy(70, 10);
	cout << a;
	turn_message(b, 3);
}

void ControlConsole::turn_message(string a, unsigned short b)
{
	setcolor(7); //turn  color;
	gotoxy(5, 21);
	cout << a << " Turns " << endl;
}