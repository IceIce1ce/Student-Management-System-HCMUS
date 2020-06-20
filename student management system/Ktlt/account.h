#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "menu.h"
#include "console.h"
#include <conio.h>
#define MAX 100
using namespace std;
struct SinhVien 
{
	string fname, lname, gender,day,month,year,stt,id;
};
struct account 
{
	string stt, acc, mk;
};
struct Data 
{
	string id, name, BoD, gender,classSV;
};
void viewProfile(Data s);
int loadaccount(const char *path, SinhVien s[]);
int saveaccount(const char *path, SinhVien s[], int n,int x);
string login();
bool doimk(string tk); 
Data loaddata(const char *path,string tk,int kiemtra);
void savedata(const char *path, SinhVien s[], int n, int x,string classSV);
void addSV();
void change();
void listClass();
void svOfclass(string classSv);
void removeStudent1();
void EditStudent1();