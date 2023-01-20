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
* <file with functions for validation>
*
*/
#include "validation.h"
#include "myStrFunc.h"
#include "constants.h"
void checkForIncorrectNickname(char* nickname, const int  MAX_LENGTH)
{
	int nicknameLenght = myStrLenght(nickname);
	while (nicknameLenght >= 101)
	{
		cout << "Your nickname is longer than necessary. Please, enter a shorter nickname." << endl;
		cin.ignore();
		cin.getline(nickname, MAX_LENGTH);
		nicknameLenght = myStrLenght(nickname);
	}
}
void checkForIncorrectDimension(int& dimension)  
{
	while (dimension < 4 || dimension > 10)
	{
		cout << "Incorrect input! Please, enter valid dimension between [4, 10]: ";
		cin.ignore();
		cin >> dimension;
	}
}
void checkForIncorrectDirection(char& direction)   
{
	while (direction != UP && direction != DOWN && direction != LEFT && direction != RIGHT)
	{
		cout << "Incorrect input! Please, enter correct direction [a, s, d or w]" << endl;
		cin.ignore();
		cin >> direction;
	}
}