#include"Tiktactoe.h"
#include"Board.h"
#include"Player.h"


int main()
{
	Board b;
	Player p;
	Tiktactoe t1(p, b);
	t1.menu();

	system("pause");
}