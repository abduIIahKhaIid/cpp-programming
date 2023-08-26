#pragma once
#include"ControlConsole.h"
#include<fstream>
class Board
{
	char board[3][3];
	int turn;
	ControlConsole C;
public:
	int scoreA;
	int scoreB;
	string player1;
	string player2;
	Board();
	void load(int);
	void save(int);
	void draw(int);
	void designFirst(int, int, int, int);
	void fill(int);
	int getTurn();
	bool check();
	bool see();
	void gameWin(string,int);
	void gameDraw(string);
	void newFile();
};

