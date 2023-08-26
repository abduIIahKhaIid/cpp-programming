#include "Player.h"

Player::Player()
{
	player1 = "\0";
	player2 = "\0";
}

void Player::setPlayer1()
{
	cout << "Enter the player name \n";
	cin.ignore();
	getline(cin, player1);
	ofstream file("OnlyName.txt");
	file << player1;
	file.close();
}

void Player::setPlayer2()
{
	cout << "Enter the first player name \n";
	cin.ignore();
	getline(cin, player1);
	cout << "Enter the second player name \n";
	getline(cin, player2);
	ofstream file("DualName.txt");
	file << player1 << endl;
	file << player2 << endl;
	file.close();
}

string Player::getPlayer1(int a)
{
	if (a == 0)
	{
		return player1;
	}
	else if(a==1)
	{
		ifstream file("OnlyName.txt");
		getline(file, player1);
		file.close();
		return player1;
	}
	else if (a == 2)
	{
		ifstream file("dualName.txt");
		getline(file, player1);
		file.close();
		return player1;
	}
}

string Player::getPlayer2(int a)
{
	if (a == 0)
	{
		return player2;
	}
	else
	{
		ifstream file("dualName.txt");
		int i = 1;
		while (i!=3)
		{
			getline(file, player2);
			i++;
		}
		file.close();
		return player2;
	}
}

void Player::playerTurn(int a,int b)
{
	if (a == 0)
	{
		h1->humanturn(player1, 3,1,b);
		return;
	}
	else if (a == 1)
	{
		C->computerTurn();
		return;
	}
	else
	{
		h1->humanturn(player2, 3,2,b);
		return;
	}
}