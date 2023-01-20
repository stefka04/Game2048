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
#pragma once
void mergeTwoTiles(int& tile1, int& tile2);
void moveUp(int** gameBoard, int dimension);
void moveDown(int** gameBoard, int dimension);
void moveRight(int** gameBoard, int dimension);
void moveLeft(int** gameBoard, int dimension);
void applyDirection(int** gameBoard, int dimension, char direction);