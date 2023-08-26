#include "Human.h"

Human::Human()
{
}

void Human::humanturn(string a, unsigned short b,int c,int d)
{
	C.setcolor(7); //turn  color;
	C.gotoxy(5, 21);
	cout << a << " Turns " << endl;
	playerA(a,c,d);
}

bool Human::isLegalClick(int& sri, int& sci)
{
	if ((sci >= 4 && sci <= 7) && (sri >= 45 && sri <= 51))
	{
		sri = 0; sci = 0;
		return true;
	}
	else if ((sci >= 4 && sci <= 7) && (sri >= 52 && sri <= 58))
	{
		sri = 0; sci = 1;
		return true;
	}
	else if ((sci >= 4 && sci <= 7) && (sri >= 59 && sri <= 65))
	{
		sri = 0; sci = 2;
		return true;
	}
	else if ((sci >= 8 && sci <= 12) && (sri >= 45 && sri <= 51))
	{
		sri = 1; sci = 0;
		return true;
	}
	else if ((sci >= 8 && sci <= 12) && (sri >= 52 && sri <= 58))
	{
		sri = 1; sci = 1;
		return true;
	}
	else if ((sci >= 8 && sci <= 12) && (sri >= 59 && sri <= 65))
	{
		sri = 1; sci = 2;
		return true;
	}
	else if ((sci >= 13 && sci <= 18) && (sri >= 45 && sri <= 51))
	{
		sri = 2; sci = 0;
		return true;
	}
	else if ((sci >= 13 && sci <= 18) && (sri >= 52 && sri <= 58))
	{
		sri = 2; sci = 1;
		return true;
	}
	else if ((sci >= 13 && sci <= 18) && (sri >= 59 && sri <= 65))
	{
		sri = 2; sci = 2;
		return true;
	}
	else
	{
		return false;
	}
}

bool Human::valueCheck(int a,int X,int Y)
{
	char b[3][3];
	if (a == 1)
	{
		ifstream file("singleState.txt");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				file >> b[i][j];
			}
		}
		file.close();
		if (b[X][Y] == 'T' || b[X][Y] == 'X')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else 
	{
		ifstream file("doubleState.txt");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				file >> b[i][j];
			}
		}
		file.close();
		if (b[X][Y] == 'T' || b[X][Y] == 'X')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
}

void Human::playerA(string a,int b,int e)
{
	int sci = 0, sri = 0;
	bool c = true, d = false;
	do
	{
		C.getRowColbyLeftClick(sri, sci);
		c= isLegalClick(sri, sci);
		if (c != 1)
		{
			C.rightSideMessage("click on - sign on the block ", a);
			goto end;
		}
		d = valueCheck(e, sri, sci);
		if (d == 1)
		{
			C.rightSideMessage("Don't click on fill option ", a);
		}
	end:;
	} while (!c || d);
	if (b == 1)
	{
		fillFile(e, sri, sci, 'T');
	}
	else
	{
		fillFile(e, sri, sci, 'X');
	}
}

void Human::fillFile(int a,int X,int Y,char s)
{
	char b[3][3];
	if (a == 1)
	{
		ifstream file("singleState.txt");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				file >> b[i][j];
			}
		}
		file.close();
		b[X][Y] = s;
		ofstream file1("singleState.txt");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				file1 << b[i][j];
			}
			file1 << endl;
		}
		file1.close();
	}
	else
	{
		ifstream file("doubleState.txt");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				file >> b[i][j];
			}
		}
		file.close();
		b[X][Y] = s;
		ofstream file1("doubleState.txt");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				file1 << b[i][j];
			}
		}
		file1.close();
	}
}
