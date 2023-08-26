#pragma once
#include"ControlConsole.h"
#include<fstream>
class Human
{
	ControlConsole C;
public:
	Human();
	void humanturn(string, unsigned short,int,int);
	void playerA(string,int,int);
	bool isLegalClick(int&, int&);
	bool valueCheck(int,int,int);
	void fillFile(int,int,int,char);
};

