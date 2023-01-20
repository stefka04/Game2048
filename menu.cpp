/**
*
* Solution to course project # 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Stefka Lyaskalieva
* @idnumber 4MI0600158
* @compiler VC
*
* < menu functions>
*
*/
#include "menu.h"
void printTheOpeningMenu()
{
	cout << "1. Start game" << endl;
	cout << "2. Leaderboard" << endl;
	cout << "3. Quit" << endl;
	cout << "Enter command: ";
}
bool checkMenuCommand()
{
	int command;
	printTheOpeningMenu();
	cin >> command;
	switch (command)
	{
	case 1: start(); break;
	case 2: leaderboard(); break;
	case 3: return false;
	default: cout << "Incorrect input! Please, enter valid command." << endl;
	}
	return true;
}