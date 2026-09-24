#include <iostream>
#include<cstdlib>
#include<ctime>
#include"janken.cpp.h"
using namespace std;

void playjanken()
{
	const char* hand[] = { "グー","チョキ","パー" };

	cout << "\n　ーーー じゃんけんゲーム　ーーー" << endl;
	cout << "0:グー、１：チョキ、２：パーから選んでください";

	int playerInput;
	cin >> playerInput;

	if (playerInput < 0 || playerInput >= static_cast<int>(ZyankenHand::MAX))
	{

	}
}