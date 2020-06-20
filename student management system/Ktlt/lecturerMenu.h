#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <fstream>
using namespace std;
#define CONSOLE_WIDTH 120
#define CONSOLE_HEIGHT 40
#define X 100
struct scores2 
{
	string No, id, mid, fin, lab, bonus;
};
void setConsoleSize(int width, int height);
void setColor(int color);
void printXY(string str, int x, int y);
int getInput();
void LecturerMenu(string *Menu, int * MenuLines);
void showLecturerMenu(string *splashData, int * lines, string * mainMenu, int * mainMenuLines, int * menuCurrent);
void loadScore(scores2 s[], int &max);
void showScoreBoard(scores2 s[], int max);
void editGrade(scores2 s[], int max, string mssv);
int menuLecturer();