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
* < main file>
*
*/

#include <iostream>
#include "clear.h"
#include "createGameBoard.h"
#include "freeArray.h"
#include "getRandomNumber.h"
#include "moveInDirection.h"
#include "validation.h"
#include "myStrFunc.h"
#include "menu.h"
#include "constants.h"
#include "printFunc.h"
#include "helperFunc.h"
#include <fstream>  
using namespace std;


char currentFile[MAX_FILE_NAME_LENGHT];
char leaderboardArr[MAX_LINES][MAX_LENGHT];
int bestFiveScores[MAX_LINES];
int bestScoreIndex = 0;

//Make move (apply direction) if it is possible
bool isGameOver(int** gameBoard, int dimension)
{
	for (size_t i = 0; i < dimension; i++)
	{
		for (size_t j = 0; j < dimension; j++)
		{
			if (gameBoard[i][j] == 0)
			{
				return false;
			}
			if (i != dimension - 1 && gameBoard[i][j] == gameBoard[i + 1][j])
			{
				return false;
			}
			if (j != dimension - 1 && gameBoard[i][j] == gameBoard[i][j + 1])
			{
				return false;
			}
		}
	}
	return true;
}
//get the sum of all numbers on the board, which is our current score
int getCurrentScore(int** gameBoard, int dimension)
{
	int score = 0;
	for (size_t i = 0; i < dimension; i++)
	{
		for (size_t j = 0; j < dimension; j++)
		{
			score += gameBoard[i][j];
		}
	}
	return score;
}
void readLeaderboardFile(const char* currentFile)
{
	ifstream in(currentFile);
	if (!in.is_open())
	{
		return;  //Error opening file
	}
	int line = 0, rowElement = 0;
	while (!in.eof())
	{
		in.getline(leaderboardArr[line], MAX_LENGHT);
		bestFiveScores[bestScoreIndex] = 0;
		rowElement = myStrLenght(leaderboardArr[line]) - 1; // get the index before the terminator
		int i = 0;
		while (leaderboardArr[line][rowElement] != ' ')
		{
			bestFiveScores[bestScoreIndex] = bestFiveScores[bestScoreIndex]
				+ (leaderboardArr[line][rowElement] - '0') * powerOfTen(i);
			rowElement--;
			i++;
		}
		if (!in.eof())
		{
			bestScoreIndex++;
		}
		line++;
	}
	in.close();
}
//find leaderboard file for the selected dimension
void findCurrentFile(int dimension)
{
	switch (dimension)
	{
	case 4: myStrCopy(currentFile, DIMENSION4_FILE); break;
	case 5: myStrCopy(currentFile, DIMENSION5_FILE); break;
	case 6: myStrCopy(currentFile, DIMENSION6_FILE); break;
	case 7: myStrCopy(currentFile, DIMENSION7_FILE); break;
	case 8: myStrCopy(currentFile, DIMENSION8_FILE); break;
	case 9: myStrCopy(currentFile, DIMENSION9_FILE); break;
	case 10: myStrCopy(currentFile, DIMENSION10_FILE); break;
	}
}
//update the leaderboard file
void changeCurrentLeaderboard(const char* currentFile, int betterScoreRrow, const char* nickname, int score)
{
	int digits = getCountOfDigits(score);
	char* scoreStr = new char[digits + 1];
	convertIntToString(score, scoreStr);
	scoreStr[digits] = '\0';
	for (int i = bestScoreIndex + 1; i > betterScoreRrow; i--)
	{
		if (i == 5)
		{
			i--;
		}
		myStrCopy(leaderboardArr[i], leaderboardArr[i - 1]);
	}
	myStrCopy(leaderboardArr[betterScoreRrow], nickname);
	myStrConcat(leaderboardArr[betterScoreRrow], "  Score: ");
	myStrConcat(leaderboardArr[betterScoreRrow], scoreStr);
	ofstream out(currentFile, ofstream::trunc);
	for (int i = 0; i <= bestScoreIndex + 1 && i <= 4; i++)
	{
		out << leaderboardArr[i];
		if (i != 4 && leaderboardArr[i + 1][0] != '\0')
		{
			out << endl;
		}
	}
	out.close();
	delete[] scoreStr;
}
void start()
{
	clearConsole();
	clearInputBuffer();
	cout << "Enter your nickname:" << endl;
	char nickname[MAX_NICKNAME_LENGTH];
	cin.getline(nickname, MAX_NICKNAME_LENGTH);
	checkForIncorrectNickname(nickname, MAX_NICKNAME_LENGTH);
	cout << "Enter dimension: ";
	int dimension;
	cin >> dimension;
	checkForIncorrectDimension(dimension);
	int** gameBoard = createGridForTheGame(dimension, dimension);
	findCurrentFile(dimension);
	printGameboard(gameBoard, dimension);
	cout << "Enter direction:" << endl;
	char direction;
	cin >> direction;
	int score = 0;
	while (true)
	{
		checkForIncorrectDirection(direction);
		applyDirection(gameBoard, dimension, direction);
		printGameboard(gameBoard, dimension);
		score = getCurrentScore(gameBoard, dimension);
		bool isTheGameOver = isGameOver(gameBoard, dimension);
		if (isTheGameOver)
		{
			score = getCurrentScore(gameBoard, dimension);
			cout << "Game Over!" << endl << "Total score : " << score << endl;
			readLeaderboardFile(currentFile);
			for (int i = 0; i <= bestScoreIndex + 1 && i != 5; i++)
			{
				if (score > bestFiveScores[i])
				{
					changeCurrentLeaderboard(currentFile, i, nickname, score);
					break;
				}
			}
			free(gameBoard, dimension);
			break;
		}
		cout << "Score: " << score << endl;
		cout << "Enter direction:" << endl;
		cin >> direction;
	}
}
void printLeaderboard(int dimension, char* currentFile)
{
	readLeaderboardFile(currentFile);
	for (size_t i = 0; i < 5; i++)
	{
		cout << i + 1 << ". " << leaderboardArr[i] << endl;
	}
	cout << endl;
}
void leaderboard()
{
	clearConsole();
	clearInputBuffer();
	cout << "Enter dimension: ";
	int dimension;
	cin >> dimension;
	checkForIncorrectDimension(dimension);
	findCurrentFile(dimension);
	printLeaderboard(dimension, currentFile);
}
int main()
{
	bool inGame = true;
	while (inGame)
	{
		inGame = checkMenuCommand();
	}
	return 0;
}