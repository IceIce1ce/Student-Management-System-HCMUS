#include "lecturerMenu.h"
#include "honganh.h"
#include "account.h"
#include "StudentMenu.h"
int getInput() 
{
	int nextInput = 0;
	do nextInput = _getch(); while (nextInput == 0);
	return nextInput;
}
void setConsoleSize(int width, int height) 
{
	string cmd = "MODE CON COLS=" + to_string(width) + " LINES=" + to_string(height);
	system(cmd.c_str());
}
void setColor(int color) 
{
	static HANDLE handle = NULL;
	if (!handle) 
	{
		handle = GetStdHandle(STD_OUTPUT_HANDLE);
	}
	SetConsoleTextAttribute(handle, color);
}
void printXY(string str, int x, int y) 
{
	static HANDLE  handle = NULL;
	if (!handle)
		handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { (short)x, (short)y };
	SetConsoleCursorPosition(handle, c);
	cout << str;
}
void LecturerMenu(string *Menu, int * MenuLines) 
{
	string line;
	*MenuLines = 0;
	ifstream file("LecturerMenu.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			Menu[*MenuLines] = line;
			*MenuLines = *MenuLines + 1;
		}
		file.close();
	}
}
void showLecturerMenu(string *splashData, int * lines, string * mainMenu, int * mainMenuLines, int * menuCurrent) 
{
	int 	b = 0,
	maxLength = 0;
	for (int i = 0; i < *lines; i++)
	if (splashData[i].size() > maxLength) maxLength = splashData[i].size();
	system("cls");
	for (int i = 0; i < *lines; i++)
	printXY(splashData[i], (CONSOLE_WIDTH - maxLength + 1) / 2, 6 + i);
	while (true) 
	{
		for (int i = 0; i < *mainMenuLines; i++) 
		{
			if (i == *menuCurrent) 
			{
				setColor(14);
				printXY(">>>  " + mainMenu[i] + "   ", (CONSOLE_WIDTH + 1) / 2 - 25, 10 + *lines + i * 2);
				setColor(7);
			}
			else printXY("        " + mainMenu[i], (CONSOLE_WIDTH + 1) / 2 - 25, 10 + *lines + i * 2);
		}
		while (!_kbhit()) {}
		b = getInput();
		if (b == 224) 
		{
			switch ((b = getInput())) 
			{
			case 72:
				if (*menuCurrent > 0) *menuCurrent = *menuCurrent - 1;
				else *menuCurrent = *mainMenuLines - 1;
				break;
			case 80:
				if (*menuCurrent < *mainMenuLines - 1) *menuCurrent = *menuCurrent + 1;
				else *menuCurrent = 0;
				break;
			}
		}
		else 
		{
			if (b == 13)
				return;
		}
	}
}
void loadScore(scores2 s[], int &max) 
{
	system("cls");
	ifstream file("ScoreBoard.csv");
	if (file.is_open()) 
	{
		int i = 0;
		while (file.good()) 
		{
			getline(file, s[i].No, ',');
			getline(file, s[i].id, ',');
			getline(file, s[i].mid, ',');
			getline(file, s[i].fin, ',');
			getline(file, s[i].lab, ',');
			getline(file, s[i].bonus, '\n');
			i++;
		}
		max = i;
		file.close();
	}
}
void showScoreBoard(scores2 s[], int max) 
{
	system("cls");
	string fline = "No\t   ID\t\tMid-term\tFinal\t   Lab\tBonus",
	str = "Press any key to return ...";
	for (int k = 1; k <= max; k++) {
	printXY(fline, (CONSOLE_WIDTH + 1) / 2 - 36, 7 + 1 * 2);
	printXY(s[k].No + '\t' + s[k].id + "\t   " + s[k].mid + "\t\t  " + s[k].fin + "\t   " + s[k].lab + "\t   " + s[k].bonus, (CONSOLE_WIDTH + 1) / 2 - 36, 10 + k * 2);
	}
	printXY(str, (CONSOLE_WIDTH - str.size() + 1) / 2, 25 + 8);
	system("pause>nul");
}
void editGrade(scores2 s[], int max, string mssv) 
{
	system("cls");
	string str = "Edited successfully.",
		in = "ID Student : ";
	printXY(in, (CONSOLE_WIDTH - str.size() + 1) / 2, 3 + 8);
	cin >> mssv;
	ofstream file("ScoreBoard.csv");
	if (file.is_open()) 
	{
		int i = 0;
		string x;
		for (i; i <= max; i++) 
		{
			if (s[i].id == mssv) 
			{
				printXY("Mid-term : ", (CONSOLE_WIDTH - str.size() + 1) / 2, 5 + 8);
				cin >> x;
				s[i].mid = x;
				printXY("Final : ", (CONSOLE_WIDTH - str.size() + 1) / 2, 7 + 8);
				cin >> x;
				s[i].fin = x;
				printXY("Lab : ", (CONSOLE_WIDTH - str.size() + 1) / 2, 9 + 8);
				cin >> x;
				s[i].lab = x;
				printXY("Bonus : ", (CONSOLE_WIDTH - str.size() + 1) / 2, 11 + 8);
				cin >> x;
				s[i].bonus = x;
			}
			file << s[i].No << "," << s[i].id << "," << s[i].mid << ',' << s[i].fin << ',' << s[i].lab << ',' << s[i].bonus << '\n';
		}
		printXY(str, (CONSOLE_WIDTH - str.size() + 1) / 2, 25 + 8);
	}
	file.close();
	system("pause>nul");
}
void editAttendance(checkin s[], int n) 
{
	system("cls");
 	string mssv;
	cout << "ID Student :";
	cin >> mssv;
	ofstream file("Checkin.csv"); // ghi file
	if (file.is_open()) 
	{
		int i = 0;
		for (i; i < n; i++) 
		{
			if (mssv ==  s[i].id) 
			{ 
				cout << "Week 1 want to edit : ";
				cin >> s[i].w1;
				cout << "Week 2 want to edit : ";
				cin >> s[i].w2;
				cout << "Week 3 want to edit : ";
				cin >> s[i].w3;
				cout << "Week 4 want to edit : ";
				cin >> s[i].w4;
				cout << "Week 5 want to edit : ";
				cin >> s[i].w5;
				cout << "Week 6 want to edit : ";
				cin >> s[i].w6;
			}
			file << s[i].No << ',' << s[i].id << ',' << s[i].w1 << ',' << s[i].w2 << ',' << s[i].w3 << ',' << s[i].w4 << ',' << s[i].w5 << ',' << s[i].w6 << '\n';
		}
		cout << "Edit successfully.";
	}
	else {
		cout << "Can't open.";
	}
	file.close();
	system("pause>nul");
}
///////////////////////////// menu
int menuLecturer() 
{
	setConsoleSize(CONSOLE_WIDTH, CONSOLE_HEIGHT-5);
	checkin check[X];
	scores2 s[X];
	COURSE s1[MAX], s2[MAX], s3[MAX], s4[MAX], s5[MAX], s6[MAX];
	STUDENT st1[MAX], st2[MAX], st3[MAX], st4[MAX], st5[MAX], st6[MAX];
	ATTENDANCE at1[MAX], at2[MAX], at3[MAX], at4[MAX], at5[MAX], at6[MAX];
	string 	*splashData = NULL, *Menu = NULL, *TKB = NULL, mssv, *ScoreBoard = NULL;
	splashData = new string[CONSOLE_HEIGHT];
	Menu = new string[CONSOLE_HEIGHT];
	ScoreBoard = new string[CONSOLE_HEIGHT];
	int splashLines = 0, MenuLines = 0, menuCurrent = 0, max;
	int attt =  loadCheckin(check, max);
	int clc1, clc2, clc3, clc4, clc5, clc6;
	clc1 = loadCourse("courseclc1.csv", s1);
	saveCourse("courseclc1.txt", s1, clc1);
	clc2 = loadCourse("courseclc2.csv", s2);
	saveCourse("courseclc2.txt", s2, clc2);
	clc3 = loadCourse("courseclc3.csv", s3);
	saveCourse("courseclc3.txt", s3, clc3);
	clc4 = loadCourse("courseclc4.csv", s4);
	saveCourse("courseclc4.txt", s4, clc4);
	clc5 = loadCourse("courseclc5.csv", s5);
	saveCourse("courseclc5.txt", s5, clc5);
	clc6 = loadCourse("courseclc6.csv", s6);
	saveCourse("courseclc6.txt", s6, clc6);
	int stdclc1, stdclc2, stdclc3, stdclc4, stdclc5, stdclc6;
	stdclc1 = loadStudent("stdclc1.csv", st1);
	saveStudent("stdclc1.txt", st1, stdclc1);
	stdclc2 = loadStudent("stdclc2.csv", st2);
	saveStudent("stdclc2.txt", st2, stdclc2);
	stdclc3 = loadStudent("stdclc3.csv", st3);
	saveStudent("stdclc3.txt", st3, stdclc3);
	stdclc4 = loadStudent("stdclc4.csv", st4);
	saveStudent("stdclc4.txt", st4, stdclc4);
	stdclc5 = loadStudent("stdclc5.csv", st5);
	saveStudent("stdclc5.txt", st5, stdclc5);
	stdclc6 = loadStudent("stdclc6.csv", st6);
	saveStudent("stdclc6.txt", st6, stdclc6);
	LecturerMenu(Menu, &MenuLines);
	loadScore(s, max);
		while (true) 
		{
			showLecturerMenu(splashData, &splashLines, Menu, &MenuLines, &menuCurrent);
			switch (menuCurrent) 
			{
			case 0:
				Course(7, s1, s2, s3, s4, s5, s6);
				break;
			case 1:
				Studentofcourse(7, st1, st2, st3, st4, st5, st6);
				break;
			case 2:
				Attendance(7, at1, at2, at3, at4, at5, at6);
				break;
			case 3:
				editAttendance(check, attt); 
				
				break;
			case 4:
				showScoreBoard(s, max);
				break;
			case 5:
				editGrade(s, max, mssv);
				break;
			case 6:
				return 4;
			}
		}
	return 0;
}