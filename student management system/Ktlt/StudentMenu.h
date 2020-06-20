#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <ctime>
#include "honganh.h"
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#define CONSOLE_WIDTH 120
#define CONSOLE_HEIGHT 40
#define X 100
/*struct checkin 
{
	string No, id, w1, w2, w3, w4, w5, w6;
};*/
void StudentMenu(string *Menu, int * MenuLines);
void showStudentMenu(string *splashData, int * lines, string * mainMenu, int * mainMenuLines, int * menuCurrent);
void Schedules(string *TKB, int * TKBLines);
void showSchedules(string *TKB, int * TKBLines);
int loadCheckin(checkin check[], int &max);
void showCheckin(checkin check[],string mssv, int max);
void saveCheckin(checkin check[], string mssv, int max);
void loadScore(scores s[], int &max);
void showScore(scores s[], string mssv, int max);
//void editGrade(scores s[], int max, string mssv);
//void showScoreBoard(scores s[], int max);
int StudentMenu();