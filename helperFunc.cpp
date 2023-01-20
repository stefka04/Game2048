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
* <file with helper functions>
*
*/
#include "helperFunc.h"
#include "constants.h"
#include <iostream>
using namespace std;
int getCountOfDigits(int num)
{
	int digits = 1;
	while (num / 10 != 0)
	{
		digits++;
		num /= 10;
	}
	return digits;
}
void mySetW(int num)
{
	cout << num;
	int numDigits = getCountOfDigits(num);
	int i = MAX_SPACES - numDigits;
	while (i > 0)
	{
		cout << SPACE;
		i--;
	}
}
int powerOfTen(int exp)
{
	int result = 1;
	for (int i = 0; i < exp; i++)
	{
		result *= 10;
	}
	return result;
}
void convertIntToString(int num, char* str)
{
	int indexStr = 0;
	int digits = getCountOfDigits(num);
	while (digits > 0)
	{
		digits--;
		str[indexStr++] = (num / powerOfTen(digits)) + '0';
		num = num % powerOfTen(digits);
	}
}