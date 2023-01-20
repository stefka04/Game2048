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
* <file with functions to clear console>
*
*/
#include <iostream>
#include "clear.h"
using namespace std;
// Clear console
void clearConsole()
{
    cout << "\033[;H"; // Moves cursor to the top left
	cout << "\033[J"; // Clears the console
}
// Remove all error flags and characters from the input buffer
void clearInputBuffer()
{
	// because of using both getline and cin we have to cin.ignore;
	// cin leaves the newline character in the stream which will be read as input from the getline
	cin.clear();	// clears errors flags from the cin
	cin.sync();		// discard unread characters from the input buffer
	cin.ignore();	// discard characters from the input buffer
}