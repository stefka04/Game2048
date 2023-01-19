#include "menu.h";
void printTheOpeningMenu()
{
	cout << "1. Start game" << endl;
	cout << "2. Leaderboard" << endl;
	cout << "3. Quit" << endl;
	cout << "Enter command: ";
}
void checkMenuCommand()
{
	int command;
	while (true)
	{
		printTheOpeningMenu();
		cin >> command;
		switch (command)
		{
		case 1: start(); break;
		case 2: leaderboard(); break;
		case 3: return;
		default: cout << "Incorrect input! Please, enter valid command." << endl; break;
		}
	}
}