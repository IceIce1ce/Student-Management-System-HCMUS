#ifndef _Header_file_h
#define _Header_file_h
#include <windows.h>
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<fstream>
#include<vector>
#include<string.h>
#include<string>
#include<iomanip>
#include<cstdlib>
#include"console.h"
using namespace std;
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
#define MAX 100
struct COURSE 
{
	string Case, time, mon, tues, wed, thur, fri, satur;
};
//--------------------------------------------------------
//end----------------------Screen----------------------end
// VIEW OF COURSES OF THE CURRENT SEMESTER
void Course(int n, COURSE s1[], COURSE s2[], COURSE s3[], COURSE s4[], COURSE s5[], COURSE s6[]);
void returnmenu(COURSE s1[], COURSE s2[], COURSE s3[], COURSE s4[], COURSE s5[], COURSE s6[]);
void hide();
int loadCourse(const char *path, COURSE s[]);
void saveCourse(const char *path, COURSE s[], int n);
void showCourse(const char *path, COURSE s[]);
// VIEW STUDENT OF THE COURSE
struct STUDENT 
{
	string stt, id, name, sb1, sb2, sb3, sb4, sb5, sb6;
};
void Studentofcourse(int n, STUDENT st1[], STUDENT st2[], STUDENT st3[], STUDENT st4[], STUDENT st5[], STUDENT st6[]);
int loadStudent(const char *path, STUDENT st[]);
void saveStudent(const char *path, STUDENT st[], int n);
void showStudent(const char *path, STUDENT st[], int n);
void returnstudent(STUDENT st1[], STUDENT st2[], STUDENT st3[], STUDENT st4[], STUDENT st5[], STUDENT st6[]);
void addStudent(const char *path, STUDENT st[], int &n);
void addSt(STUDENT st1[], STUDENT st2[], STUDENT st3[], STUDENT st4[], STUDENT st5[], STUDENT st6[]);
void deleteStudent(const char *path, STUDENT st[], int &n);
void delSt(STUDENT st1[], STUDENT st2[], STUDENT st3[], STUDENT st4[], STUDENT st5[], STUDENT st6[]);
struct LECTURE 
{
	string name, email, major, officehour, id;
};
int loadLecture(const char *path, LECTURE lt[]);
void saveLecture(const char *path, LECTURE lt[], int n);
void addLecture(const char *path, LECTURE lt[], int &n);
void addLec(LECTURE lt[]);
void viewAllLecture(const char *path, LECTURE lt[], int n);
void deleteLecture(const char *path, LECTURE lt[], int &n);
void deleteLec(LECTURE lt[]);
//VIEW ATTENDANCE OF COURSE
struct ATTENDANCE 
{
	string stt, id, name, sb1, sb2, sb3, sb4, sb5, sb6;
};
int loadAttendance(const char *path, ATTENDANCE at[]);
void saveAttendance(const char *path, ATTENDANCE at[], int n);
void showAttendance(const char *path, ATTENDANCE at[], int n);
void Attendance(int n, ATTENDANCE at1[], ATTENDANCE at2[], ATTENDANCE at3[], ATTENDANCE at4[], ATTENDANCE at5[], ATTENDANCE at6[]);
void returnAttendance(ATTENDANCE at1[], ATTENDANCE at2[], ATTENDANCE at3[], ATTENDANCE at4[], ATTENDANCE at5[], ATTENDANCE at6[]);
//SEARCH AND VIEW SCOREBOARD
void showScore(const char *path, STUDENT st[], int n);
void ScoreBoard(int n, STUDENT st1[], STUDENT st2[], STUDENT st3[], STUDENT st4[], STUDENT st5[], STUDENT st6[]);
void returnscore(STUDENT st1[], STUDENT st2[], STUDENT st3[], STUDENT st4[], STUDENT st5[], STUDENT st6[]);
////Chi
struct Course1
{
	string stt, id, name, classSV, lecAcc, startDate, endDate, dayOfweek, startHour, endHour, room;
};
struct dataCourse1
{
	string stt, id, name, classSV, lecAcc, startDate, endDate, dayOfweek, startHour, endHour, room;
};
struct checkin 
{
	string No, id, w1, w2, w3, w4, w5, w6;
};
int loadCourse1(const char* path, Course1 s[]);
void saveCourse1(const char* path, Course1 s[], int n);
void showCourse1(const char* path, Course1 s[], int n);
Course1 loaddata1(const char* path);
void addCourse1(const char* path, Course1 s[], int& n);
void addCo1(Course1 s1_1[], Course1 s2_2[], Course1 s3_3[], Course1 s4_4[], Course1 s5_5[]);
int deleteCourse1(const char* path, Course1 s[], int& n);
void delCo1(Course1 s1_1[], Course1 s2_2[], Course1 s3_3[], Course1 s4_4[], Course1 s5_5[]);
int editCourse1(const char* path, Course1 s[], int& n);
void ediCo1(Course1 s1_1[], Course1 s2_1[], Course1 s3_3[], Course1 s4_4[], Course1 s5_5[]);
//Luc
//void showScore(const char *path, STUDENT st[], int n);
//void ScoreBoard(STUDENT st1[], STUDENT st2[], STUDENT st3[], STUDENT st4[], STUDENT st5[], STUDENT st6[]); // goi ra dau z
///
struct scores 
{
	string No, id, mid, fin, lab, bonus;
};
void InputnExportScore(scores sc[], int n);
int loadScore(const char *path, scores sc[]);
/////
#define CONSOLE_WIDTH 120
#define CONSOLE_HEIGHT 45
void StaffCMenu(string *Menu, int * MenuLines);
void showStaffCMenu(string *splashData, int * lines, string * mainMenu, int * mainMenuLines, int * menuCurrent);
int StaffMenuC();
//Lecturer
void editAttendance(checkin s[], int n);//
#endif