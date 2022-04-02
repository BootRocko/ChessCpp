#pragma once

#define white true  //Uppercase
#define black false	//Lowercase

int CurrentTurn;
bool TurnColor;
int TurnNumber;

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

void IncreaseTurnTimer()
{
	TurnNumber++;
}