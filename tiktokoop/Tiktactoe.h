#pragma once
#include<iostream>
#include<string>
#include<windows.h>
#include"Player.h"
#include"Board.h"

using namespace std;

class Tiktactoe
{
	Player P;
	Board B;
public:
	Tiktactoe(Player,Board);
	void menu();
	void playGame1();
	void playGame2();
};

