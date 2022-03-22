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
			
			
			//Tells the user their king is in check
			if (InCheck(kingUPos1, kingUPos2, kingLPos1, kingLPos2))
			{
				setxy(32, 28);
				cout << "In check!";
			}
			else
			{
				setxy(32, 28);
				cout << "         ";
			}
		}
		else CoutInvalidMove();

		CleanSide();
	}

	system("PAUSE");
}