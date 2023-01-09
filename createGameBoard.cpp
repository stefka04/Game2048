#include "createGameBoard.h";
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