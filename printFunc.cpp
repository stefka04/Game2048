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
* <file with function for printing>
*
*/
#include "printFunc.h"
#include "clear.h"
#include "iostream"
#include "getRandomNumber.h"
#include "helperFunc.h"
using namespace std;
void printGameboard(int** gameBoard, int dimension)
{
	clearInputBuffer();
	clearConsole();
	cout << endl;
	getRandomElement(gameBoard, dimension);
	for (size_t i = 0; i < dimension; i++)
	{
		for (size_t j = 0; j < dimension; j++)
		{
			mySetW(gameBoard[i][j]);
		}
		cout << endl;
	}
}