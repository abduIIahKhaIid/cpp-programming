#include "Board.h"

Board::Board()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = '_';
		}
	}
	turn = 0;
	scoreA = 0;
	scoreB = 0;
}

void Board::load(int a)
{
	if (a == 1)
	{
		ifstream infile("singleState.txt");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				infile >> board[i][j];
				if (board[i][j] == 'T' || board[i][j] == 'X')
				{
					turn++;
				}
			}
		}
		infile.close();
		ifstream file("singleScore.txt");
		file >> scoreA >> scoreB;
		file.close();
	}
	else
	{
		ifstream infile("doubleState.txt");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				infile >> board[i][j];
				if (board[i][j] == 'T' || board[i][j] == 'X')
				{
					turn++;
				}
			}
		}
		infile.close();
		ifstream file("dualScore.txt");
		file >> scoreA >> scoreB;
		file.close();
	}
}

void Board::save(int a)
{
	if (a == 1)
	{
		ofstream outfile("singleState.txt");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				outfile << board[i][j];
			}
			outfile << endl;
		}
		outfile.close();
		ofstream file("singleScore.txt");
		file << scoreA << " " << scoreB;
		file.close();
	}
	else
	{
		ofstream outfile("doubleState.txt");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				outfile << board[i][j];
			}
			outfile << endl;
		}
		outfile.close();
		ofstream file("dualScore.txt");
		file << scoreA << " " << scoreB;
		file.close();
	}
}

void Board::designFirst(int x, int y, int z, int g)
{
	int a, b, c, d;
	a = x; b = y; c = z, d = g;
	//We draw FRAME for the bar
	for (int i = x; i < y; i++)
	{
		C.gotoxy(i, z);
		cout << char(205);     // 2 horizontal lines
		C.gotoxy(i, g);
		cout << char(205);
	}
	for (int i = z + 1; i < g; i++)   //2 vertical lines
	{
		C.gotoxy(a, i);
		cout << char(186);
		C.gotoxy(b, i);
		cout << char(186);
	}
	C.setcolor(3);               //box edge color
	C.gotoxy(a, z);   //top left
	cout << char(201);
	C.gotoxy(b, z);   //top right
	cout << char(187);
	C.gotoxy(a, g);  // bottom left
	cout << char(200);
	C.gotoxy(b, g);    //bottom right
	cout << char(188);
}

void Board::draw(int a)
{
	system("cls");
	int color = 6;
	int multi = 3;
	C.setcolor(color); //box size color not include edges
	designFirst(45, 66, 3, 18);
	for (int i = 4; i < 18; i++)  //vertical lines
	{
		C.gotoxy(52, i);
		cout << char(179);
	}
	for (int i = 4; i < 18; i++) //vertical lines
	{
		C.gotoxy(59, i);
		cout << char(179);
	}
	for (int i = 46; i < 66; i++) //horizontal lines
	{

		C.gotoxy(i, 8);
		cout << char(196);
	}
	C.setcolor(color); // line crossing color
	C.gotoxy(52, 8);
	cout << char(197);
	C.gotoxy(59, 8);
	cout << char(197);

	for (int i = 46; i < 66; i++)   //horizontal lines
	{
		C.setcolor(multi); //horizontal line color
		C.gotoxy(i, 13);
		cout << char(196);
	}
	C.setcolor(color); //line crossing color;
	C.gotoxy(52, 13);
	cout << char(197);
	C.gotoxy(59, 13);
	cout << char(197);
	if (a == 1)
	{
		C.setcolor(6);
		C.gotoxy(70, 21);
		cout << "Score of " << player1 << " " << scoreA;
		C.gotoxy(70, 22);
		cout << "Score of " << "Computer " << " " << scoreB;
	}
	else
	{
		C.setcolor(6);
		C.gotoxy(70, 21);
		cout << "Score of " << player1 << " " << scoreA;
		C.gotoxy(70, 22);
		cout << "Score of " << player2 << " " << scoreB;
	}
	fill(a);
}

void Board::fill(int a)
{
	C.gotoxy(42, 1);
	C.setcolor(8);
	cout << "Welcome to Tic Tac Toe game  ";
	if (a == 1)
	{
		C.gotoxy(3, 3);
		cout << "Player " << player1 << " has " << 'T' << " sign ";
		C.gotoxy(3, 5);
		cout << "Player " << "Computer " << " has " << "X " << " sign ";
	}
	else
	{
		C.gotoxy(3, 3);
		cout << "Player " << player1 << " has " << 'T' << " sign ";
		C.gotoxy(3, 5);
		cout << "Player " << player2 << " has " << "X " << " sign ";
	}
	int colors = 6;  //dash color 
	int x = 0; int y = 0;
	for (int i = 48; i <= 62; i += 7)  //first line
	{
		C.gotoxy(i, 5);
		if (board[x][y] == 'T')
		{
			C.setcolor(4); //Tick color
			cout << board[x][y];
		}
		else  if (board[x][y] == 'X')
		{
			C.setcolor(2);  //cross color
			cout << board[x][y];
		}
		else
		{
			C.setcolor(colors); //dash color
			cout << board[x][y];
		}
		y++;
	}
	x = 1; y = 0;
	for (int i = 48; i <= 62; i += 7)  //second row  
	{
		C.gotoxy(i, 10);
		if (board[x][y] == 'T')
		{
			C.setcolor(4); //Tick color
			cout << board[x][y];
		}
		else  if (board[x][y] == 'X')
		{
			C.setcolor(2);  //cross color
			cout << board[x][y];
		}
		else
		{
			C.setcolor(colors); //dash color 
			cout << board[x][y];
		}
		y++;
	}
	x = 2; y = 0;
	for (int i = 48; i <= 62; i += 7)  //third row 
	{
		C.gotoxy(i, 15);
		if (board[x][y] == 'T')
		{
			C.setcolor(4);   //tick color
			cout << board[x][y];
		}
		else  if (board[x][y] == 'X')
		{
			C.setcolor(2);     //cross color
			cout << board[x][y];
		}
		else
		{
			C.setcolor(colors);    //dash color
			cout << board[x][y];
		}
		y++;
	}
	save(a);
}

bool Board::check()
{
	if ((board[0][0] == 'T' && board[0][1] == 'T' && board[0][2] == 'T') || (board[0][0] == 'X' &&
		board[0][1] == 'X' && board[0][2] == 'X')) //1 2 3 line 
	{
		return true;
	}
	else if ((board[0][0] == 'T' && board[1][0] == 'T' && board[2][0] == 'T') || (board[0][0] == 'X'
		&& board[1][0] == 'X' && board[2][0] == 'X')) // 1 4 7 line 
	{
		return true;
	}
	else if ((board[0][0] == 'T' && board[1][1] == 'T' && board[2][2] == 'T') || (board[0][0] == 'X' &&
		board[1][1] == 'X' && board[2][2] == 'X')) //1 5 9 line 
	{
		return true;
	}
	else if ((board[0][1] == 'T' && board[1][1] == 'T' && board[2][1] == 'T') || (board[0][1] == 'X' &&
		board[1][1] == 'X' && board[2][1] == 'X'))   //2 5 8 line 
	{
		return true;
	}
	else if ((board[0][2] == 'T' && board[1][2] == 'T' && board[2][2] == 'T') || (board[0][2] == 'X'
		&& board[1][2] == 'X' && board[2][2] == 'X'))  //3 6 9 line 
	{
		return true;
	}
	else if ((board[1][0] == 'T' && board[1][1] == 'T' && board[1][2] == 'T') || (board[1][0] == 'X'
		&& board[1][1] == 'X' && board[1][2] == 'X'))   //4 5 6 line 
	{
		return true;
	}
	else if ((board[2][0] == 'T' && board[2][1] == 'T' && board[2][2] == 'T') || (board[2][0] == 'X'
		&& board[2][1] == 'X' && board[2][2] == 'X'))
	{
		return true;
	}
	else if ((board[0][2] == 'T' && board[1][1] == 'T' && board[2][0] == 'T') || (board[0][2] == 'X'
		&& board[1][1] == 'X' && board[2][0] == 'X'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Board::getTurn()
{
	return turn;
}

void Board::gameWin(string a,int b)
{
	C.gotoxy(70, 10);
	C.fontsize(30, 20);
	C.setcolor(3);
	cout << a;
}

bool Board::see()
{
	int k = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == '_')
			{
				k = 1;
			}
		}
	}
	if (k == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Board::gameDraw(string a)
{
	C.gotoxy(70, 10);
	C.fontsize(30, 20);
	C.setcolor(3);
	cout << a;
}

void Board::newFile()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = '_';
		}
	}
}

