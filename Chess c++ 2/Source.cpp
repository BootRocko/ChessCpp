#include <iostream>
#include "Board.h"
#include "Input.h"
#include "Movement.h"
#include "Game.h"

using namespace std;

int main()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	DrawBoard();
	SetupPieces();

	TurnColor = white;

	while (true)
	{

		DrawBoard();
		DrawPieces();

		CoutTurnColor();
		CoutTurnNumber();

		MoveInput();
		GetWantedMove();
		
		if  (   (TurnColor == white &&  CharIsUppercase(Coor, intCurrentPos1, intCurrentPos2) )
			 || (TurnColor == black && !CharIsUppercase(Coor, intCurrentPos1, intCurrentPos2) )
			)
		{
				if (MoveValid(moveInput))
				{
					MovePiece(intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2);

					/*
					//Tells the user their king is in check
					if (InCheck(kingUPos1, kingUPos2, kingLPos1, kingLPos2))
					{
						CoutInvalidMove();

						setxy(32, 28);
						cout << "In check!";
					}
					else
					{
						MovePiece(intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2);

						setxy(32, 28);
						cout << "         ";
					}
					*/

					ChangePlayer();
					IncreaseTurnTimer();

				}
				else CoutInvalidMove("Move is not legal");
		}
		else CoutInvalidMove("Player cannot move opponent's piece");

		CleanSide();
	}



}