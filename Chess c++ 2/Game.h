#pragma once

#include "Input.h"
#include "Board.h"
#include "Movement.h"

#define white true  //Uppercase
#define black false	//Lowercase

int CurrentTurn;
bool TurnColor;
int TurnNumber;
bool WouldCheck;

void ChangePlayer()
{
	TurnColor = !TurnColor;
}

bool CheckTurn()
{
	return TurnColor;
}

void CoutTurnColor()
{
	setxy(32, 10);
	cout << "Player's turn: ";

	if (TurnColor == white) cout << "White";
	else cout << "Black";
}

void CoutTurnNumber()
{
	setxy(32, 11);
	cout << "Turns: " << TurnNumber;
}

void CoutDebug(char cancer)
{
	setxy(32, 13);
	cout << "Cancer:" << cancer;
}

void IncreaseTurnTimer()
{
	TurnNumber++;
}

void CoutCheck(bool CheckCondition)
{
	if (CheckCondition)
	{
		setxy(32, 28);
		cout << "In check!";
	}
	else
	{
		setxy(32, 28);
		cout << "          ";
	}
}

bool IsKing(char(&Coor)[9][9], int& intCurrentPos1, int& intCurrentPos2)
{
	if (Coor[intCurrentPos1][intCurrentPos2] == 'K' || Coor[intCurrentPos1][intCurrentPos2] == 'k') return true;
	else return false;
}

bool CharIsUppercase(char(&Coor)[9][9], int& intWantedPos1, int& intWantedPos2);

bool IsPlayersPiece()
{
	if  (  (TurnColor == white && CharIsUppercase(Coor, intCurrentPos1, intCurrentPos2))
		|| (TurnColor == black && !CharIsUppercase(Coor, intCurrentPos1, intCurrentPos2))
		) return true;

	else return false;
}