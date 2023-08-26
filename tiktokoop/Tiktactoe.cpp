#include "Tiktactoe.h"

Tiktactoe::Tiktactoe(Player p,Board b)
{
	P = p;
	B= b;
}

void Tiktactoe::menu()
{
	top:
	int choice = 0;
	cout << "Press 1 for play the Player vs Computer \n";
	cout << "Press 2 for play the Player vs Player \n";
	cout << "Press 0 for exit \n";
	cin >> choice;
	if (choice == 1)
	{
		playGame1();
		system("cls");
		goto top;
	}
	else if (choice == 2)
	{
		playGame2();
		system("cls");
		goto top;
	}
	else
	{
		exit(0);
	}
}

void Tiktactoe::playGame1()
{
	system("cls");
	char e = 'a';
	bool c=true, d = true;
	cout << "are you want to play a new game ? (y/n): ";
	cin >> e;
	if (e == 'y' || e == 'Y')
	{
		system("cls");
		P.setPlayer1();
		B.scoreA = 0;
		B.scoreB = 0;
		B.player1 = P.getPlayer1(0);
	}
	else
	{
		B.load(1);
		B.player1 = P.getPlayer1(1);
		B.save(1);
	}
	int counts = B.getTurn();
startgame:
	B.draw(1);
	do
	{

		if (counts % 2 == 0 || counts == 0)
		{
			counts = 0;
			P.playerTurn(0,1);
			B.load(1);
			B.draw(1);
		}
		c = B.check();
		if (c == 1)
		{
			string a = P.getPlayer1(0);
			a += " ";
			a += "Win";
			B.scoreA++;
			B.draw(1);
			B.gameWin(a,0);
			B.newFile();
			B.save(1);
			break;
		}
		d = B.see();
		if (d == 0)
		{
			B.gameDraw("Match Draw");
			B.newFile();
			B.save(1);
			break;
		}
		if (counts % 2 != 0 || counts == 0)
		{
			counts = 0;
			P.playerTurn(1,1);
			B.load(1);
			B.draw(1);
		}
		c = B.check();
		if (c == 1)
		{
			string a = "Computer";
			a += " ";
			a += "Win";
			B.scoreB++;
			B.draw(1);
			B.gameWin(a,1);
			B.newFile();
			B.save(1);
			break;
		}
		d = B.see();
		if (d == 0)
		{
			B.gameDraw("Match Draw");
			B.newFile();
			B.save(1);
			break;
		}
	} while (!c);
	ControlConsole C;
	C.setcolor(9);
	C.gotoxy(1, 21);
	cout << "Press R for Rematch ";
	C.gotoxy(1, 22);
	cout << "Press Q for quit ";
	C.gotoxy(1, 23);
	cin >> e;
	if (e == 'R' || e == 'r')
	{
		goto startgame;
	}
	return;
}

void Tiktactoe::playGame2()
{
	system("cls");
	char e = 'a';
	bool c=true, d = true;
	cout << "are you want to play a new game ? (y/n): ";
	cin >> e;
	if (e == 'y' || e == 'Y')
	{
		system("cls");
		P.setPlayer2();
		B.scoreA = 0;
		B.scoreB = 0;
		B.player1 = P.getPlayer1(0);
		B.player2 = P.getPlayer2(0);
	}
	else
	{
		B.load(2);
		B.save(2);
		B.player1 = P.getPlayer1(2);
		B.player2 = P.getPlayer2(2);
		B.save(2);
	}
	int counts = B.getTurn();
	startgame2:
	B.draw(2);
	do
	{
		if (counts % 2 == 0 || counts == 0)
		{
			counts = 0;
			P.playerTurn(0,2);
			B.load(2);
			B.draw(2);
		}
		c = B.check();
		if (c == 1)
		{
			string a = P.getPlayer1(0);
			a += " ";
			a += "Win";
			B.scoreA++;
			B.draw(2);
			B.gameWin(a, 0);
			B.newFile();
			B.save(2);
			break;
		}
		d = B.see();
		if (d == 0)
		{
			B.gameDraw("Match Draw");
			B.newFile();
			B.save(2);
			break;
		}
		if (counts % 2 != 0 || counts == 0)
		{
			counts = 0;
			P.playerTurn(2, 2);
			B.load(2);
			B.draw(2);
		}
		c = B.check();
		if (c == 1)
		{
			string a = P.getPlayer2(0);
			a += " ";
			a += "Win";
			B.scoreB++;
			B.draw(2);
			B.gameWin(a, 1);
			B.newFile();
			B.save(2);
			break;
		}
		d = B.see();
		if (d == 0)
		{
			B.gameDraw("Match Draw");
			B.newFile();
			B.save(2);
			break;
		}
	} while (!c);
	ControlConsole C;
	C.setcolor(9);
	C.gotoxy(1, 21);
	cout << "Press R for Rematch ";
	C.gotoxy(1, 22);
	cout << "Press Q for quit ";
	C.gotoxy(1, 23);
	cin >> e;
	if (e == 'R' || e == 'r')
	{
		goto startgame2;
	}
	return;
}