#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <string>
#include<fstream>
using namespace std;
struct Course
{
	string stt;
	string id;
	string name;
	string classSV;
	string lecAcc;
	string startDate;
	string endDate;
	string dayOfweek;
	string startHour;
	string endHour;
	string room;
};
//struct dataCourse
//{
//	string stt, id, name, classSV, lecAcc, startDate, endDate, dayOfweek, startHour, endHour, room;
//};
int loadCourse(const char *path, Course s[]);
void saveCourse(const char *path, Course s[], int n);
void showCourse(const char *path, Course s[], int n);
Course loaddata(const char *path);
void addCourse(const char *path, Course s[], int &n);
void addCo(Course s1[], Course s2[], Course s3[], Course s4[], Course s5[]);
int deleteCourse(const char *path, Course s[], int &n);
void delCo(Course s1[], Course s2[], Course s3[], Course s4[], Course s5[]);
int editCourse(const char *path, Course s[], int &n);
void ediCo(Course s1[], Course s2[], Course s3[], Course s4[], Course s5[]);