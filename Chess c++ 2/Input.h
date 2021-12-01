#pragma once

#include <iostream>
#include <string.h>


string moveInput;
int intCurrentPos1, intCurrentPos2, intWantedPos1, intWantedPos2;
char charPos[5];

void MoveInput()
{
	setxy(32, 20);
	cout << "Input move: ";
	cin >> moveInput;
}


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
		cout << "                            ";
	}


	else
	{
		setxy(32, 19);
		cout << "Please input a valid move!";
	}

}
