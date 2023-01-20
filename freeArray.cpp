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
* <file with a function to free 2D dynamic array>
*
*/
#include "freeArray.h"
void free(int** gameBoard, size_t rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		delete[] gameBoard[i];
	}
	delete[] gameBoard;
}