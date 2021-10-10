#include <iostream>
#include "Board.h"

using namespace std;

int input1, input2;

int main()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	

	while (true)
	{
		DrawBoard();
		SetupPieces();
		DrawPieces();

		setxy(32, 20);

		cout << "Input current position of piece: ";
		cin >> input1;
		setxy(30, 21);
		cout << "Input wanted position of piece: ";
		cin >> input2;

		system("CLS");
	}

	system("PAUSE");
}