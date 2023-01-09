#include "freeArray.h"
void free(int** gameBoard, size_t rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		delete[] gameBoard[i];
	}
	delete[] gameBoard;
}