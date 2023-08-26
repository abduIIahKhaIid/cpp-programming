#pragma once
#include<iostream>
#include<fstream>
#include"ControlConsole.h"
#include"Human.h"
#include"Computer.h"
using namespace std;
class Player
{
	string player1;
	string player2;
	Human* h1;
	Computer* C;
public:
	Player();
	void setPlayer1();
	void setPlayer2();
	string getPlayer1(int);
	string getPlayer2(int);
	void playerTurn(int,int);
};

