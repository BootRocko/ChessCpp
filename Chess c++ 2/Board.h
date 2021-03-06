#pragma once

#include <iostream>
#include <vector>
#include <Windows.h>
#include "Functions.h"
#include "Pieces.h"

//cout << "\u25A0" BLACK
//cout << "\u25A1" WHITE

using namespace std;

//Defining board spaces for better readability
#define A 1
#define B 2
#define C 3
#define D 4
#define E 5
#define F 6
#define G 7
#define H 8

#define x8 1
#define x7 2
#define x6 3
#define x5 4
#define x4 5
#define x3 6
#define x2 7
#define x1 8

//Main board char array
char Coor[9][9];

char CoorCopy[9][9];


//Draws board into the command line
void DrawBoard()
{
	char BoardLetter = 'A';
	int BoardNumber = 8;

	setxy(0, 3);

	for (int i = 0; i < 24; i++)
	{
		cout << "  ";
		
		if (i % 3 == 1)
		{
			cout << BoardNumber << "  ";
			BoardNumber--;
		}
		else cout << "   ";

		for (int k = 0; k < 24; k++)
		{

			if (i % 6 < 3 && k % 6 < 3)
			{
				WhiteBackground();
				cout << " ";
				WhiteText();
			}

			else if (i % 6 >= 3 && k % 6 >= 3)
			{
				WhiteBackground();
				cout << " ";
				WhiteText();
			}

			else
			{
				cout << " ";
			}

		}
		
		cout << "\n";
	}

	for (int p = 0; p < 8; p++)
	{
		setxy(6+(p*3), 1);
		cout << BoardLetter;
		BoardLetter++;
	}

	BoardLetter = 'A';

}

//Places the pieces to their proper place on the board
void SetupPieces()
{
	Coor[A][x8] = 'r';
	Coor[B][x8] = 'n';
	Coor[C][x8] = 'b';
	Coor[D][x8] = 'q';
	Coor[E][x8] = 'k';
	Coor[F][x8] = 'b';
	Coor[G][x8] = 'n';
	Coor[H][x8] = 'r';

	for (int a = 0; a < 8; a++) Coor[a + 1][x7] = 'p';


	Coor[A][x1] = 'R';
	Coor[B][x1] = 'N';
	Coor[C][x1] = 'B';
	Coor[D][x1] = 'Q';
	Coor[E][x1] = 'K';
	Coor[F][x1] = 'B';
	Coor[G][x1] = 'N';
	Coor[H][x1] = 'R';

	for (int a = 0; a < 8; a++) Coor[a + 1][x2] = 'P';

}

//Draws the pieces onto the board
void DrawPieces()
{
	
	for (int a = 0; a < 8; a++)
	{
		for (int b = 0; b < 8; b++)
		{
			if (Coor[a+1][b+1] == 0);
			else
			{
				setxyboard( 2 + (3 * a) , 2 + (3 * b) );
				cout << Coor[a+1][b+1];
			}
		}
	}

}

//Cleans the side of the board
void CleanSide()
{
	for (int i = 20; i < 25; i++)
	{
		setxy(32, i);
		cout << "                                              ";
	}
}

//Copies the board into a board copy for use in checking for future king checks
void CopyBoard(char CoorUsed[9][9], char CoorCopy[9][9])
{
	for (int a = 0; a < 9; a++)
	{
		for (int b = 0; b < 9; b++)
		{
			CoorCopy[a][b] = CoorUsed[a][b];
		}
	}
}
