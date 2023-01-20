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
* <file with functions for applying a new direction>
*
*/
#include "moveInDirection.h"
#include "constants.h"
void mergeTwoTiles(int& tile1, int& tile2) 
{
	tile1 = 0;
	tile2 *= 2;
}
void moveUp(int** gameBoard, int dimension)
{
	for (int i = 0; i < dimension; i++) 
	{
		int previousElementIndex = 0;
		for (int j = 1; j < dimension; j++) 
		{
			if (gameBoard[j][i] != 0)
			{
				if (gameBoard[j][i] == gameBoard[previousElementIndex][i])
				{
					mergeTwoTiles(gameBoard[j][i], gameBoard[previousElementIndex][i]);
					previousElementIndex++;
				}
				else
				{
					if (gameBoard[previousElementIndex][i] != 0)
					{
						previousElementIndex++;
					}
					gameBoard[previousElementIndex][i] = gameBoard[j][i];
					if (previousElementIndex != j)
					{
						gameBoard[j][i] = 0;
					}
				}
			}
		}
	}
}
void moveDown(int** gameBoard, int dimension)
{
	for (size_t i = 0; i < dimension; i++)  
	{
		int previousElementIndex = dimension - 1;
		for (int j = dimension - 2; j >= 0; j--) 
		{
			if (gameBoard[j][i] != 0)
			{
				if (gameBoard[j][i] == gameBoard[previousElementIndex][i])
				{
					mergeTwoTiles(gameBoard[j][i], gameBoard[previousElementIndex][i]);
					previousElementIndex--;
				}
				else
				{
					if (gameBoard[previousElementIndex][i] != 0)
					{
						previousElementIndex--;
					}
					gameBoard[previousElementIndex][i] = gameBoard[j][i];
					if (previousElementIndex != j)
					{
						gameBoard[j][i] = 0;
					}
				}
			}
		}
	}
}
void moveRight(int** gameBoard, int dimension)
{
	for (size_t i = 0; i < dimension; i++)  
	{
		int previousElementIndex = dimension - 1;
		for (int j = dimension - 2; j >= 0; j--) 
		{
			if (gameBoard[i][j] != 0)
			{
				if (gameBoard[i][j] == gameBoard[i][previousElementIndex])
				{
					mergeTwoTiles(gameBoard[i][j], gameBoard[i][previousElementIndex]);
					previousElementIndex--;
				}
				else
				{
					if (gameBoard[i][previousElementIndex] != 0)
					{
						previousElementIndex--;
					}
					gameBoard[i][previousElementIndex] = gameBoard[i][j];
					if (previousElementIndex != j)
					{
						gameBoard[i][j] = 0;
					}
				}
			}
		}
	}
}
void moveLeft(int** gameBoard, int dimension)
{
	for (size_t i = 0; i < dimension; i++) 
	{ 
		int previousElementIndex = 0;
		for (size_t j = 1; j < dimension; j++) 
		{
			if (gameBoard[i][j] != 0)
			{
				if (gameBoard[i][j] == gameBoard[i][previousElementIndex])
				{
					mergeTwoTiles(gameBoard[i][j], gameBoard[i][previousElementIndex]);
					previousElementIndex++;
				}
				else
				{
					if (gameBoard[i][previousElementIndex] != 0)
					{
						previousElementIndex++;
					}
					gameBoard[i][previousElementIndex] = gameBoard[i][j];
					if (previousElementIndex != j)
					{
						gameBoard[i][j] = 0;
					}
				}
			}
		}
	}
}
void applyDirection(int** gameBoard, int dimension, char direction)
{
	switch (direction)
	{
	case UP: moveUp(gameBoard, dimension); break;
	case DOWN: moveDown(gameBoard, dimension); break;
	case RIGHT: moveRight(gameBoard, dimension); break;
	case LEFT: moveLeft(gameBoard, dimension); break;
	}
}