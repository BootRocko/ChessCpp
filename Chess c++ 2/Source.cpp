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

		if (InCheck(kingUPos1, kingUPos2, kingLPos1, kingLPos2))
		{
			CoutCheck(true);

			CopyBoard(Coor, CoorCopy);
		}
		else CoutCheck(false);

		MoveInput();
		GetWantedMove();

		//Check if king will be in check

		
		if ( IsPlayersPiece() )
		{
			if (MoveValid(moveInput))
			{
				//MovePiece(intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2);
				CopyBoard(Coor, CoorCopy);

				CopyKing(kingUPos1, kingUPos2, kingLPos1, kingLPos2, c_kingUPos1, c_kingUPos2, c_kingLPos1, c_kingLPos2);

				if (IsKing(Coor, intCurrentPos1, intCurrentPos2)) KingMove(Coor, intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2);

				MovePiece(intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2);

				if (InCheck(kingUPos1, kingUPos2, kingLPos1, kingLPos2))
				{
					CopyBoard(CoorCopy, Coor);

					CopyKing(c_kingUPos1, c_kingUPos2, c_kingLPos1, c_kingLPos2, kingUPos1, kingUPos2, kingLPos1, kingLPos2);

					CoutInvalidMove("King would be in check");
				}
				else
				{
					ChangePlayer();
					IncreaseTurnTimer();
				}

			}
			else CoutInvalidMove("Move is not legal");

		}
		else CoutInvalidMove("Player cannot move opponent's piece");

		CleanSide();
		
		//TurnColor = black;

		/*
		if  (   (TurnColor == white &&  CharIsUppercase(Coor, intCurrentPos1, intCurrentPos2) )
			 || (TurnColor == black && !CharIsUppercase(Coor, intCurrentPos1, intCurrentPos2) )
			)
		*/
		 /*
		if  ( IsPlayersPiece() )
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
		*/
	}
	


}