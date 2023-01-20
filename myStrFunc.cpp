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
* <file with helper functions for working with strings>
*
*/
#include "myStrFunc.h"
int myStrLenght(const char* str)
{
	int length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return length;
}
void myStrCopy(char* dest, const char* source)
{
	size_t index = 0;
	while (source[index] != '\0')
	{
		dest[index] = source[index];
		index++;
	}
	dest[index] = '\0';
}
void myStrConcat(char* dest, const char* source)
{
	size_t destLength = myStrLenght(dest);
	size_t sourceLength = myStrLenght(source);
	for (size_t i = 0; i < sourceLength; i++)
	{
		dest[destLength + i] = source[i];
	}
	dest[destLength + sourceLength] = '\0';
}