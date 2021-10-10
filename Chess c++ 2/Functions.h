#pragma once

#include <Windows.h>

HANDLE hConsole;

bool setxy(short x, short y)
{
	COORD c = { x,y };
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

bool setxyboard(short x, short y)
{
	COORD c = { x + 4, y + 2 };
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void WhiteText()
{
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void WhiteBackground()
{
	SetConsoleTextAttribute
	(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
}