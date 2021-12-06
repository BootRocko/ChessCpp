#include <iostream>
#include "Board.h"
#include "Input.h"
#include "Movement.h"

using namespace std;

int main()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	DrawBoard();
	SetupPieces();

	while (true)
	{
		DrawBoard();
		DrawPieces();

		MoveInput();
		
		if (MoveValid(moveInput))
		{
			MovePiece(intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2);
		}
		else CoutInvalidMove();

		CleanSide();
	}

	system("PAUSE");
}