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

bool IsEmpty(char(&Coor)[9][9], int& intWantedPos1, int& intWantedPos2)
{
	if ((int)Coor[intWantedPos1][intWantedPos2] == '\0') return true;
	else return false;
}


bool MoveValid(string MoveInput)
{
	GetWantedMove();

	piece = Coor[intCurrentPos1][intCurrentPos2];


	switch (piece) {
	
	//----------------PAWN-----------------
	case 'p':
		{
			//Normal one space movement
			if (abs(intCurrentPos2 - intWantedPos2) == 1
				&& SameRow(intCurrentPos1, intWantedPos1)
				&& IsEmpty(Coor, intWantedPos1, intWantedPos2)) return true;


			//Taking piece
			else if (CharIsUppercase(Coor, intWantedPos1, intWantedPos2)
				&& (abs(intCurrentPos2 - intWantedPos2)) == 1
				&& (abs(intCurrentPos1 - intWantedPos1)) == 1
				&& !IsEmpty(Coor, intWantedPos1, intWantedPos2)) return true;
		}

	case 'P':
		{
			//Normal one space movement
			if (abs(intCurrentPos2 - intWantedPos2) == 1
				&& SameRow(intCurrentPos1, intWantedPos1)
				&& IsEmpty(Coor, intWantedPos1, intWantedPos2)) return true;


			//Taking piece
			else if (!CharIsUppercase(Coor, intWantedPos1, intWantedPos2)
				&& (abs(intCurrentPos2 - intWantedPos2)) == 1
				&& (abs(intCurrentPos1 - intWantedPos1)) == 1
				&& !IsEmpty(Coor, intWantedPos1, intWantedPos2)) return true;
		}



	}


	return false;
}

