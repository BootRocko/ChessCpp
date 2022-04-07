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

		CoutCheck(InCheck(kingUPos1, kingUPos2, kingLPos1, kingLPos2));

		MoveInput();
		GetWantedMove();

		//TurnColor = black;
		
		if  (   (TurnColor == white &&  CharIsUppercase(Coor, intCurrentPos1, intCurrentPos2) )
			 || (TurnColor == black && !CharIsUppercase(Coor, intCurrentPos1, intCurrentPos2) )
			)
		{
			if (!InCheck(kingUPos1, kingUPos2, kingLPos1, kingLPos2))
			{
				if (MoveValid(moveInput))
				{
					//MovePiece(intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2);

					if (IsKing(Coor, intCurrentPos1, intCurrentPos2)) KingMove(Coor, intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2);

					MovePiece(intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2);

					ChangePlayer();
					IncreaseTurnTimer();
					
				}
				else CoutInvalidMove("Move is not legal");
			}

			else
			{
				// if (IsKing(Coor, intCurrentPos1, intCurrentPos2)) Coor copy check if it can move and no longer be in check

				CoutInvalidMove("King is in check");

				CoutDebug(checkPiece);

				Coor[kingUPos1][kingUPos2] = 'O';
				Coor[kingLPos1][kingLPos2] = 'o';
			}
		}
		else CoutInvalidMove("Player cannot move opponent's piece");

		CleanSide();
	}



}