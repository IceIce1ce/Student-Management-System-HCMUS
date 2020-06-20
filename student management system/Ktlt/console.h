#ifndef _console_header
#define _console_header
#include <windows.h>
#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15
#define default_ColorCode		7
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_SPACE 32
#define KEY_ESC 27
#define key_none -1
int inputKey();
void gotoXY(int column, int line);
void TextColor(int color);
int whereX();
int whereY();
void clrscr();
//void Course(int n);
void courseofclc1();
void courseofclc2();
void courseofclc3();
void courseofclc4();
void courseofclc5();
void courseofclc6();
#endif
#pragma once