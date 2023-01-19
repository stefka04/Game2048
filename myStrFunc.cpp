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