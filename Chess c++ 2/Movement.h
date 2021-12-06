#pragma once

#include "Input.h"
#include "Board.h"

char piece;

void MovePiece(int intCurrentPos1, int intCurrentPos2, int intWantedPos1, int intWantedPos2)
{

	Coor[intWantedPos1][intWantedPos2] = Coor[intCurrentPos1][intCurrentPos2];

	Coor[intCurrentPos1][intCurrentPos2] = '\0';

}

bool SameRow(int& intCurrentPos1, int& intWantedPos1)
{
	if (intCurrentPos1 == intWantedPos1) return true;
	else return false;
}

bool SameColumn(int& intCurrentPos2, int& intWantedPos2)
{
	if (intCurrentPos2 == intWantedPos2) return true;
	else return false;
}

bool CharIsUppercase(char(&Coor)[9][9], int& intWantedPos1, int& intWantedPos2)
{
	if (((int)Coor[intWantedPos1][intWantedPos2] > (int)'A') && ((int)Coor[intWantedPos1][intWantedPos2] < (int)'Z')) return true;
	else return false;
}

bool UppercaseDiff(char(&Coor)[9][9], int& intCurrentPos1, int& intCurrentPos2, int& intWantedPos1, int& intWantedPos2)
{
	if ((CharIsUppercase(Coor, intCurrentPos1, intCurrentPos2)) != (CharIsUppercase(Coor, intWantedPos1, intWantedPos2))) return true;
	else return false;
}

bool IsEmpty(char(&Coor)[9][9], int& intWantedPos1, int& intWantedPos2)
{
	if ((int)Coor[intWantedPos1][intWantedPos2] == '\0') return true;
	else return false;
}

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

bool IsDiagonal(char(&Coor)[9][9], int& intCurrentPos1, int& intCurrentPos2, int& intWantedPos1, int& intWantedPos2)
{
	if (abs(intCurrentPos1 - intWantedPos1) == abs(intCurrentPos2 - intWantedPos2)) return true;

	else return false;
}

int Quadrant(char(&Coor)[9][9], int& intCurrentPos1, int& intCurrentPos2, int& intWantedPos1, int& intWantedPos2)
{
	if		((intCurrentPos1 - intWantedPos1) > 0 && (intCurrentPos2 - intWantedPos2) < 0) return 1;	// x-, y+
	else if ((intCurrentPos1 - intWantedPos1) < 0 && (intCurrentPos2 - intWantedPos2) < 0) return 2;	// x+, y+
	else if ((intCurrentPos1 - intWantedPos1) > 0 && (intCurrentPos2 - intWantedPos2) > 0) return 3;	// x-, y-
	else if ((intCurrentPos1 - intWantedPos1) < 0 && (intCurrentPos2 - intWantedPos2) > 0) return 4;	// x+, y-
}

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
	
	//----------------PAWN-----------------
	case 'P':
	case 'p':
	
		{
			//Normal one space movement
			if (abs(intCurrentPos2 - intWantedPos2) == 1
				&& SameRow(intCurrentPos1, intWantedPos1)
				&& IsEmpty(Coor, intWantedPos1, intWantedPos2)) return true;


			//Taking piece
			else if (//UppercaseDiff(Coor,intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2)
				   (abs(intCurrentPos2 - intWantedPos2)) == 1
				&& (abs(intCurrentPos1 - intWantedPos1)) == 1
				&& !IsEmpty(Coor, intWantedPos1, intWantedPos2)) return true;

			break;
		}

	case 'R':
	case 'r':
		{
			//Movement
			if (((SameRow(intCurrentPos1, intWantedPos1) && !SameColumn(intCurrentPos2, intWantedPos2))
			|| (!SameRow(intCurrentPos1, intWantedPos1) && SameColumn(intCurrentPos2, intWantedPos2)))
			&& PathIsFree(Coor, intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2) ) return true;

			break;
		}

	case 'B':
	case 'b':
		{
			//Movement
		if (IsDiagonal(Coor, intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2)
		&& IsDiagonalClear(Coor, intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2)) return true;
			

			break;
		}

	}


	return false;
}

