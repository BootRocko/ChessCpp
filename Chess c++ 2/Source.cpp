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

		//Check if the piece can be moved by the player
		if ( IsPlayersPiece() )
		{
			//Check if the move is even valid
			if (MoveValid(moveInput))
			{
				//Copies the board incase it needs to be reverted
				CopyBoard(Coor, CoorCopy);

				//Copies the king's positions incase they need to be reverted
				CopyKing(kingUPos1, kingUPos2, kingLPos1, kingLPos2, c_kingUPos1, c_kingUPos2, c_kingLPos1, c_kingLPos2);

				//If the moved piece is the king, it moves it's saved coordinates
				if (IsKing(Coor, intCurrentPos1, intCurrentPos2)) KingMove(Coor, intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2);

				//Moves the piece
				MovePiece(intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2);

				//Checks if the king would be in check
				if (InCheck(kingUPos1, kingUPos2, kingLPos1, kingLPos2))
				{
					//Copies the old board back to revert the move
					CopyBoard(CoorCopy, Coor);

					//Copies the old king's positions back to revert the move
					CopyKing(c_kingUPos1, c_kingUPos2, c_kingLPos1, c_kingLPos2, kingUPos1, kingUPos2, kingLPos1, kingLPos2);

					CoutInvalidMove("King would be in check");
				}
				else
				{
					//Leaves the current board in play and advances the turn
					ChangePlayer();
					IncreaseTurnTimer();
				}

			}
			else CoutInvalidMove("Move is not legal");

		}
		else CoutInvalidMove("Player cannot move opponent's piece");

		CleanSide();
		
	}

}