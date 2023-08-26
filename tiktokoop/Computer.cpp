#include "Computer.h"

Computer::Computer()
{

}


void Computer::computerTurn()
{
	C.setcolor(7);
	C.gotoxy(5, 21);
	cout << "Computer " << " Turns " << endl;
	char b[3][3];
	int a = 0;
	int c = 0;
	ifstream file("singleState.txt");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			file >> b[i][j];
		}
	}
	file.close();
	do
	{
		a = rand() % 3;
		c = rand() % 3;
	} while (b[a][c]!='_');
	b[a][c] = 'X';
	fstream file1("singleState.txt");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			file1 << b[i][j];
		}
	}
	file1.close();
}