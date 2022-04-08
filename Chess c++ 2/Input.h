#pragma once

#include <iostream>
#include <string.h>


string moveInput;
int intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2;
char charPos[5];

//Takes user input and saves it into moveInput
void MoveInput()
{
	setxy(32, 20);
	cout << "Input move: ";
	cin >> moveInput;
}

//Have to add error definitions into the Movement.h piece movements and print them into the game board for easier identification why a move is invalid
void ErrorDetection()
{
	string x = "";
}

//Prints why a move is invalid with reason given as a parameter
void CoutInvalidMove(string Reason)
{
	setxy(32, 19);
	cout << "Move invalid: " << Reason;
}

//Divides the moveInput string into four useful variables for the current and wanted positions
void GetWantedMove()
{

	if (moveInput.length() == 5 && (moveInput[4] != '9'))
	{

		for (int i = 0; i < 5; i++)
		{
			charPos[i] = moveInput[i];
		}

		intCurrentPos1 = charPos[0] - ('A' - 1);
		intCurrentPos2 = charPos[1] - '0';

		intWantedPos1 = charPos[3] - ('A' - 1);
		intWantedPos2 = charPos[4] - '0';

		
		intCurrentPos2 = InvertNumber(intCurrentPos2, 8);
		intWantedPos2 = InvertNumber(intWantedPos2, 8);


		setxy(32, 19);
		cout << "                                                           ";
	}


	else
	{
		CoutInvalidMove("User input string is not valid");
	}

}
