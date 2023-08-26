#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;
class ControlConsole
{
	int X;
	int Y;
public:
	ControlConsole();
	void fontsize(int, int);
	void setcolor(unsigned short);
	void gotoxy(int x, int y);
	void getRowColbyLeftClick(int&, int&);
	void rightSideMessage(string a, string b);
	void turn_message(string, unsigned short);
};

