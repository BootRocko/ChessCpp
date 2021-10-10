#pragma once
#include <iostream>
#include <vector>

//cout << "\u25A0" BLACK
//cout << "\u25A1" WHITE

using namespace std;

char BoardLetter = 'A';
int BoardNumber = 8;

void DrawBoard()
{
	cout << "\n\n";

	cout << "     ";

	for (int p = 0; p < 24; p++)
	{
		if (p % 3 == 1)
		{
			cout << BoardLetter << "  ";
			BoardLetter++;
			
		}
	}

	cout << "\n";

	for (int i = 0; i < 24; i++)
	{
		cout << "  ";
		
		if (i % 3 == 1)
		{
			cout << BoardNumber << " ";
			BoardNumber--;
		}
		else cout << "  ";

		for (int k = 0; k < 24; k++)
		{
			if (k % 3 == 1 && i % 3 == 1)
			{
				cout << " ";
				//Basically morn narejit, da se pozicija figur shranjuje glede na 24x24 grid, mogoče narejit funkcijo da spremeni npr A8 v k = 1, i = 1
			}

			else if (i % 6 < 3 && k % 6 < 3) cout << (char)254u;

			else if (i % 6 >= 3 && k % 6 >= 3) cout << (char)254u;

			else cout << " ";

		}
		
		cout << "\n";
	}
}