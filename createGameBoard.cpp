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
* <file with a function for creating 2D dynamic array>
*
*/
#include "createGameBoard.h"
int** createGridForTheGame(size_t rows, size_t columns)
{
	int** gameBoard = new int* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		gameBoard[i] = new int[columns];
	}
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			gameBoard[i][j] = 0;
		}
	}
	return gameBoard;
}