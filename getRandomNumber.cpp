#include "getRandomNumber.h"
#include <stdlib.h> 
#include <ctime>
int getNumberOfUnoccupiedPositions(int** gameBoard, int dimension)
{
	int unoccupiedPositions = 0;
	for (size_t i = 0; i < dimension; i++)
	{
		for (size_t j = 0; j < dimension; j++)
		{
			if (gameBoard[i][j] == 0)
			{
				unoccupiedPositions++;
			}
		}
	}
	return unoccupiedPositions;
}
void getRandomElement(int** gameBoard, int dimension)
{
	int unoccupiedPositions = getNumberOfUnoccupiedPositions(gameBoard, dimension);
	if (unoccupiedPositions == 0)
	{
		return;
	}
	int randRow, randColumn;
	srand(time(0));  //Use current time as seed for random generator
	do
	{
		randRow = rand() % dimension;
		randColumn = rand() % dimension;
	} while (gameBoard[randRow][randColumn] != 0);  
	gameBoard[randRow][randColumn] =((rand() % 2) + 1) * 2;  // [0,1] + 1 *2
	bool isTheGameCloseToEnding = unoccupiedPositions <= dimension + 2;
	if (isTheGameCloseToEnding)
	{
		gameBoard[randRow][randColumn] *= (rand() % 2) + 1; 
    }
}