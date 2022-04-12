#pragma once

#include "Input.h"
#include "Board.h"
#include "Game.h"

char piece;

char checkPiece;

int kingUPos1 = D, kingUPos2 = x1;

int kingLPos1 = E, kingLPos2 = x8;

int c_kingUPos1, c_kingUPos2, c_kingLPos1, c_kingLPos2;


//Moves the piece from the current position to the wanted position
void MovePiece(int intCurrentPos1, int intCurrentPos2, int intWantedPos1, int intWantedPos2)
{

	Coor[intWantedPos1][intWantedPos2] = Coor[intCurrentPos1][intCurrentPos2];

	Coor[intCurrentPos1][intCurrentPos2] = '\0';

}

//Checks if the move is in the same row
bool SameRow(int& intCurrentPos1, int& intWantedPos1)
{
	if (intCurrentPos1 == intWantedPos1) return true;
	else return false;
}

//Checks if the move is in the same column
bool SameColumn(int& intCurrentPos2, int& intWantedPos2)
{
	if (intCurrentPos2 == intWantedPos2) return true;
	else return false;
}

//Checks if the piece is uppercase
bool CharIsUppercase(char(&Coor)[9][9], int& intWantedPos1, int& intWantedPos2)
{
	if (((int)Coor[intWantedPos1][intWantedPos2] > (int)'A') && ((int)Coor[intWantedPos1][intWantedPos2] < (int)'Z')) return true;
	else return false;
}

//Checks if piece being taken is an enemy piece
bool UppercaseDiff(char(&Coor)[9][9], int& intCurrentPos1, int& intCurrentPos2, int& intWantedPos1, int& intWantedPos2)
{
	if ((CharIsUppercase(Coor, intCurrentPos1, intCurrentPos2)) != (CharIsUppercase(Coor, intWantedPos1, intWantedPos2))) return true;
	else return false;
}

//Checks if wanted position is empty
bool IsEmpty(char(&Coor)[9][9], int& intWantedPos1, int& intWantedPos2)
{
	if ((int)Coor[intWantedPos1][intWantedPos2] == '\0') return true;

	//-------
	if ((int)Coor[intWantedPos1][intWantedPos2] == 'O') return true;
	//-------

	else return false;
}

//Checks if a piece wants to move diagonally
bool IsDiagonal(char(&Coor)[9][9], int& intCurrentPos1, int& intCurrentPos2, int& intWantedPos1, int& intWantedPos2)
{
	if (abs(intCurrentPos1 - intWantedPos1) == abs(intCurrentPos2 - intWantedPos2)) return true;

	else return false;
}

//Checks in which quadrant the piece wants to move in
int Quadrant(char(&Coor)[9][9], int& intCurrentPos1, int& intCurrentPos2, int& intWantedPos1, int& intWantedPos2)
{
	if ((intCurrentPos1 - intWantedPos1) > 0 && (intCurrentPos2 - intWantedPos2) < 0) return 1;	// x-, y+
	else if ((intCurrentPos1 - intWantedPos1) < 0 && (intCurrentPos2 - intWantedPos2) < 0) return 2;	// x+, y+
	else if ((intCurrentPos1 - intWantedPos1) > 0 && (intCurrentPos2 - intWantedPos2) > 0) return 3;	// x-, y-
	else if ((intCurrentPos1 - intWantedPos1) < 0 && (intCurrentPos2 - intWantedPos2) > 0) return 4;	// x+, y-
}

//Checks if a straight path is clear
bool PathIsFree(char(&Coor)[9][9], int& intCurrentPos1, int& intCurrentPos2, int& intWantedPos1, int& intWantedPos2)
{
	int k = 0;
	int i = 0;

	int m = 0;

	if (intCurrentPos2 == intWantedPos2)
	{

		for (i; abs(i) < (abs(intCurrentPos1 - intWantedPos1) - 1); i)
		{

			if (intWantedPos1 - intCurrentPos1 > 0) i++;
			else i--;

			if (Coor[(i + intCurrentPos1)][intCurrentPos2] == '\0') m++;
		}

		if (m == abs(intCurrentPos1 - intWantedPos1) - 1) return true;
	}

	if (intCurrentPos1 == intWantedPos1)
	{
		for (k; abs(k) < (abs(intCurrentPos2 - intWantedPos2) - 1); k)
		{
			if (intWantedPos2 - intCurrentPos2 > 0) k++;
			else k--;

			if (Coor[(intCurrentPos1)][k + intCurrentPos2] == '\0') m++;
		}

		if (m == abs(intCurrentPos2 - intWantedPos2) - 1) return true;
	}

	return false;
}


//Checks if the diagonal to the wanted position is clear
bool IsDiagonalClear(char(&Coor)[9][9], int& intCurrentPos1, int& intCurrentPos2, int& intWantedPos1, int& intWantedPos2)
{

	int k = intCurrentPos2;

	int m = 0;

	for (int i = 0; abs(i) < (abs(intCurrentPos1 - intWantedPos1) - 1); i)
	{

		switch (Quadrant(Coor, intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2))
		{
		case 1:
		{
			i--; k++; break;
		}
		case 2:
		{
			i++; k++; break;
		}
		case 3:
		{
			i--; k--; break;
		}
		case 4:
		{
			i++; k--; break;
		}
		}

		if (Coor[(i + intCurrentPos1)][k] == '\0') m++;

	}

	if (m == abs(intCurrentPos1 - intWantedPos1) - 1) return true;
	return false;
}

//Checks if there are any threats, which move in straight lines
bool IsStraightSafe(int& intCurrentPos1, int& intCurrentPos2)
{
	int i, p;
	int a, b;

	a = intCurrentPos1;
	b = intCurrentPos2;

	for (int c = 1; c <= 4; c++)
	{
		p = 0;

		a = intCurrentPos1;
		b = intCurrentPos2;

		for (i = 1; i < 8; i++)
		{

			switch (c)
			{
			case 1:
			{
				a = intCurrentPos1 + i;
				break;
			}

			case 2:
			{
				a = intCurrentPos1 - i;
				break;
			}

			case 3:
			{
				b = intCurrentPos2 + i;
				break;
			}

			case 4:
			{
				b = intCurrentPos2 - i;
				break;
			}
			}

			if (a == 9 || b == 9 || a == 0 || b == 0) break;


			switch (Coor[a][b])
			{
			case '\0':
			{
				break;
			}

			case 'r':
			case 'R':
			case 'Q':
			case 'q':
			{
				if (UppercaseDiff(Coor, intCurrentPos1, intCurrentPos2, a, b))
				{
					checkPiece = Coor[a][b]; //------------------
					return false;
				}
			}

			default:
			{
				p++;
				break;
			}

			}

			if (p) break;
		}

	}

	return true;
}

//Checks if there are any threats, which move in diagonals
bool IsDiagonalSafe(int& intCurrentPos1, int& intCurrentPos2)
{
	int k, p;
	int ix, kx;

	//Cycles through the chain 4 times, to check all 4 diagonals based on the piece's current position
	for (int c = 1; c <= 4; c++)
	{
		switch (c)
		{
		case 1:
		{
			ix = -1;
			kx = 1;

			break;
		}
		case 2:
		{
			ix = 1;
			kx = 1;

			break;
		}
		case 3:
		{
			ix = -1;
			kx = -1;

			break;
		}
		case 4:
		{
			ix = 1;
			kx = -1;

			break;
		}
		}

		p = 0;

		//Goes through every square and checks if there is a piece there that would threaten the diagonal (Queen and Bishop)
		for (int i = 1; i < 8; i++)
		{

			k = i;

			k *= kx;
			i *= ix;

			int a = intCurrentPos1 + i;
			int b = intCurrentPos2 + k;

			if (a == 9 || b == 9 || a == 0 || b == 0) break;

			switch (Coor[a][b])
			{
			case '\0':
			{
				break;
			}

			case 'B':
			case 'b':
			case 'Q':
			case 'q':
			{
				if (UppercaseDiff(Coor, intCurrentPos1, intCurrentPos2, a, b)) return false;
			}

			default:
			{
				p++;
				break;
			}

			}

			if (p) break;

			i = abs(i);

		}

	}

	return true;

}
 
//Checks if there are any threats, which move like knights
bool IsKnightSafe(int& intCurrentPos1, int& intCurrentPos2)
{
	int a, b;
	int e, d;
	bool aMain;

	for (int c = 1; c <= 4; c++)
	{
		a = 0;
		b = 0;
		aMain = 0;


		switch (c)
		{
		case 1:
		{
			a += 2;
			b += 1;
			aMain++;
			break;
		}

		case 2:
		{
			b += 2;
			a += 1;
			break;
		}

		case 3:
		{
			a -= 2;
			b += 1;
			aMain++;
			break;
		}

		case 4:
		{
			b -= 2;
			a += 1;
			break;
		}
		}

		for (int i = 0; i < 2; i++)
		{
			if (aMain) b += (2 * b * (i * -1));
			else a += (2 * a * (i * -1));

			e = intCurrentPos1 + a;
			d = intCurrentPos2 + b;

			if (e <= 0 || e >= 9 || d <= 0 || d >= 9) continue;

			switch (Coor[e][d])
			{
			case 'n':
			case 'N':
			{
				if (UppercaseDiff(Coor, intCurrentPos1, intCurrentPos2, e, d)) return false;
			}

			default: break;
			}

		}

	}

	return  true;
}

//Checks if the king would be in range of the opposite king
bool IsKingSafe(int& kingUPos1, int& kingUPos2, int& kingLPos1, int& kingLPos2)
{
	int a, b;

	if (TurnColor == white)
	{
		a = abs(kingUPos1 - kingLPos1);
		b = abs(kingUPos2 - kingLPos2);
	}

	else
	{
		a = abs(kingLPos1 - kingUPos1);
		b = abs(kingLPos2 - kingUPos2);
	}

	if ((a == 1 || a == 0) && (b == 1 || b == 0)) return false;

	return true;
}

//Moves the king's coordinates to a new position, as these are needed for checking if the king is in check
void KingMove(char(&Coor)[9][9], int& intCurrentPos1, int& intCurrentPos2, int& intWantedPos1, int& intWantedPos2)
{
	if (Coor[intCurrentPos1][intCurrentPos2] == 'K')
	{
		kingUPos1 = intWantedPos1;
		kingUPos2 = intWantedPos2;
	}

	else
	{
		kingLPos1 = intWantedPos1;
		kingLPos2 = intWantedPos2;
	}
}

//Copies the coordiantes of the king for use in checking for checks before a move is made
void CopyKing(int& kingUPos1, int& kingUPos2, int& kingLPos1, int& kingLPos2,   int& c_kingUPos1, int& c_kingUPos2, int& c_kingLPos1, int& c_kingLPos2)
{
	c_kingUPos1 = kingUPos1;
	c_kingUPos2 = kingUPos2;

	c_kingLPos1 = kingLPos1;
	c_kingLPos2 = kingLPos2;
}

//Checks if the king is in check based on which player's turn it is
bool InCheck(int& kingUPos1, int& kingUPos2, int& kingLPos1, int& kingLPos2)
{
	string penis;

	int a, b, c, d;

	if (TurnColor)
	{
		a = kingUPos1;
		b = kingUPos2;
		c = kingLPos1;
		d = kingLPos2;
	}

	else
	{
		a = kingLPos1,
		b = kingLPos2;
		c = kingUPos1;
		d = kingUPos2;

	}

	if (!IsDiagonalSafe(a, b)) penis += "D";

	if (!IsStraightSafe(a, b)) penis += "S";

	if (!IsKnightSafe(a, b))   penis += "N";

	setxy(32, 15);
	cout << penis;

	if (!IsDiagonalSafe(a, b)
		|| !IsStraightSafe(a, b)
		|| !IsKnightSafe(a, b)
		|| !IsKingSafe(a, b, c, d))  return true;
		

	return false;
}

//Checks if move is valid based on the piece being moved and where it's being moved to
bool MoveValid(string MoveInput)
{
	GetWantedMove();

	piece = Coor[intCurrentPos1][intCurrentPos2];


	//Checks if the piece being taken is an enemy piece, otherwise it just makes the move invalid
	if (Coor[intWantedPos1][intWantedPos2] != '\0')
	{
		if (!UppercaseDiff(Coor, intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2)) return false;
	}

	//Checks if the piece is being moved to the same position it is on, which would make the move invalid
	if (intCurrentPos1 == intWantedPos1 && intCurrentPos2 == intWantedPos2) return false;

	//Checks piece logic, depending on the piece being moved
	switch (piece) {

		//---------------PAWN---------------//
	case 'P':
	case 'p':

	{
		//Only lets pawns move forward
		if (CharIsUppercase(Coor, intCurrentPos1, intCurrentPos2) && (intWantedPos2 - intCurrentPos2 > 0)) return false;
		if (!CharIsUppercase(Coor, intCurrentPos1, intCurrentPos2) && (intWantedPos2 - intCurrentPos2 < 0)) return false;

		//Normal one space movement
		if (abs(intCurrentPos2 - intWantedPos2) == 1
			&& SameRow(intCurrentPos1, intWantedPos1)
			&& IsEmpty(Coor, intWantedPos1, intWantedPos2)) return true;

		//First move two space movement
		if (abs(intCurrentPos2 - intWantedPos2) == 2
			&& (   (CharIsUppercase(Coor, intCurrentPos1, intCurrentPos2) && intCurrentPos2 == x2)
				|| (!CharIsUppercase(Coor, intCurrentPos1, intCurrentPos2) && intCurrentPos2 == x7)   )
			&& SameRow(intCurrentPos1, intWantedPos1)
			&& IsEmpty(Coor, intWantedPos1, intWantedPos2)) return true;


		//Taking piece
		else if (//UppercaseDiff(Coor,intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2)
			(abs(intCurrentPos2 - intWantedPos2)) == 1
			&& (abs(intCurrentPos1 - intWantedPos1)) == 1
			&& !IsEmpty(Coor, intWantedPos1, intWantedPos2)) return true;

		break;
	}

	//---------------ROOK---------------//
	case 'R':
	case 'r':
	{
		//Movement
		if (((SameRow(intCurrentPos1, intWantedPos1) && !SameColumn(intCurrentPos2, intWantedPos2))
			|| (!SameRow(intCurrentPos1, intWantedPos1) && SameColumn(intCurrentPos2, intWantedPos2)))
			&& PathIsFree(Coor, intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2)) return true;

		break;
	}
	//---------------BISHOP---------------//
	case 'B':
	case 'b':
	{
		//Movement
		if (IsDiagonal(Coor, intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2)
			&& IsDiagonalClear(Coor, intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2)) return true;


		break;
	}

	//---------------QUEEN---------------//
	case 'Q':
	case 'q':
	{
		//Movement
		if (IsDiagonal(Coor, intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2)
			&& IsDiagonalClear(Coor, intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2)) return true;

		else if ( (    (SameRow(intCurrentPos1, intWantedPos1) && !SameColumn(intCurrentPos2, intWantedPos2))
					|| (!SameRow(intCurrentPos1, intWantedPos1) && SameColumn(intCurrentPos2, intWantedPos2))
				  )
				&& PathIsFree(Coor, intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2)) return true;

		break;
	}


	//---------------KING---------------//

	//Have to define "InCheck" function to check if the king is in check (/would be in check) before any piece can move
	//Should save the position of king on every king move for easier checks
	case 'K':
	case 'k':
	{
		//Movement
		if  ( (abs(intCurrentPos1 - intWantedPos1) == 1 && abs(intCurrentPos2 - intWantedPos2) <= 1)
			|| ((abs(intCurrentPos2 - intWantedPos2) == 1) && abs(intCurrentPos1 - intWantedPos1) <= 1)
			) return true;
			
		break;
	}

	//---------------KNIGHT---------------//
	case 'N':
	case 'n':
	{
		//Movement
		if ((abs(intCurrentPos1 - intWantedPos1) == 2 && abs(intCurrentPos2 - intWantedPos2) == 1)
			|| (abs(intCurrentPos1 - intWantedPos1) == 1 && abs(intCurrentPos2 - intWantedPos2) == 2)) return true;

		break;
	}

	}


	return false;
}

