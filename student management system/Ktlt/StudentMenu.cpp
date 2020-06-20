#include "StudentMenu.h"
#include "lecturerMenu.h"
#include "account.h"
void StudentMenu(string *Menu, int * MenuLines) 
{
	string line;
	*MenuLines = 0;
	ifstream file("StudentMenu.txt");
	if (file.is_open()) 
	{
		while (getline(file, line)) 
		{
			Menu[*MenuLines] = line;
			*MenuLines = *MenuLines + 1;
		}
		file.close();
	}
}
void showStudentMenu(string *splashData, int * lines, string * mainMenu, int * mainMenuLines, int * menuCurrent) 
{
	int b = 0, maxLength = 0;
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
				printXY(">>>  " + mainMenu[i] + "   ", (CONSOLE_WIDTH + 1) / 2 - 15, 10 + *lines + i * 2);
				setColor(7);
			}
			else printXY("        " + mainMenu[i], (CONSOLE_WIDTH + 1) / 2 - 15, 10 + *lines + i * 2);
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
void Schedules(string *TKB, int * TKBLines) 
{
	string line;
	*TKBLines = 0;
	ifstream file("Schedules.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			TKB[*TKBLines] = line;
			*TKBLines = *TKBLines + 1;
		}
		file.close();
	}
}
void showSchedules(string *TKB, int * TKBLines) 
{
	system("cls");
	string 	str = "Press any key to return...";
	for (int i = 0; i < *TKBLines; i++) 
	{
		printXY(TKB[i], (CONSOLE_WIDTH + 1) / 2 - 43, -2 + *TKBLines + i * 2);
	}
	printXY(str, (CONSOLE_WIDTH - str.size() + 1) / 2, 25 + *TKBLines);
	system("pause > nul");
}
int loadCheckin(checkin check[], int &max) 
{
	system("cls");
	ifstream file("Checkin.csv");
	if (file.is_open()) {
		int i = 0;
		while (file.good()) {
			getline(file, check[i].No, ',');
			getline(file, check[i].id, ',');
			getline(file, check[i].w1, ',');
			getline(file, check[i].w2, ',');
			getline(file, check[i].w3, ',');
			getline(file, check[i].w4, ',');
			getline(file, check[i].w5, ',');
			getline(file, check[i].w6, '\n');
			i++;
		}
		max = i;
		file.close();
	}
	return max;
}
void showCheckin(checkin check[], string mssv, int max) 
{
	system("cls");
	
	string fline = "No\t   ID\t\tWeek 1\tWeek 2\tWeek 3\tWeek 4\tWeek 5\tWeek 6",
		str = "Press any key to return ...",
		in = "ID Student : ";
	printXY(in, (CONSOLE_WIDTH - str.size() + 1) / 2, 4 + 8);
	cin >> mssv;
	for (int k = 0; k <= max; k++) {
		if (check[k].id == mssv) {
	printXY(fline, (CONSOLE_WIDTH + 1) / 2 - 43, 7 + 5 * 2);
	printXY(check[k].No + '\t' + check[k].id + "\t   " + check[k].w1 + "\t   " + check[k].w2 + "\t   " + check[k].w3 + "\t   " + check[k].w4 + "\t   " + check[k].w5 + "\t   " + check[k].w6, (CONSOLE_WIDTH + 1) / 2 - 43, 10 + 5 * 2); //5 = k
			break;
		}
	}
	printXY(str, (CONSOLE_WIDTH - str.size() + 1) / 2, 25 + 8);
	system("pause>nul");		
}
void saveCheckin(checkin check[], string mssv, int max) 
{
	system("cls");
	time_t now = time(0);
	tm *ltm = localtime(&now);
	int	min_cal_now, min_cal_start1, min_cal_end1, min_cal_start2, min_cal_end2;
	min_cal_now = 60 * ltm->tm_hour + 1 + ltm->tm_min;
	min_cal_start1 = 7 * 60 + 1 + 30;
	min_cal_start2 = 13 * 60 + 1 + 30;
	min_cal_end1 = 11 * 60 + 1 + 30;
	min_cal_end2 = 17 * 60 + 1 + 30;
	string str = "Check-in successfully.", in = "ID Student : ", out = "Can't check-in now, please come back later.";
	printXY(in, (CONSOLE_WIDTH - str.size() + 1) / 2, 10 + 8);
	cin >> mssv;
	printXY(asctime(ltm), (CONSOLE_WIDTH - str.size() + 1) / 2, 10);
	ofstream file("Checkin.csv");
	if (file.is_open()) 
	{
		int i = 0, flag = 0;
		for (i; i <= max; i++) 
		{
			if (check[i].id == mssv) 
			{
				if (min_cal_start1 <= min_cal_now && min_cal_now <= min_cal_end1) 
				{
					if (check[i].w1 == "") 
					{
						check[i].w1 = "X";
					}
					else if (check[i].w2 == "") 
					{
						check[i].w2 = "X";
					}
					else if (check[i].w3 == "") 
					{
						check[i].w3 = "X";
					}
					else if (check[i].w4 == "") 
					{
						check[i].w4 = "X";
					}
					else if (check[i].w5 == "") 
					{
						check[i].w5 = "X";
					}
					else if (check[i].w6 == "")
					{
						check[i].w6 = "X";
					}
					else 
					{
						flag = 1;
					}
				}
				else if (min_cal_start2 <= min_cal_now && min_cal_now <= min_cal_end2) 
				{
					if (check[i].w1 == "") 
					{
						check[i].w1 = "X";
					}
					else if (check[i].w2 == "") 
					{
						check[i].w2 = "X";
					}
					else if (check[i].w3 == "") 
					{
						check[i].w3 = "X";
					}
					else if (check[i].w4 == "") 
					{
						check[i].w4 = "X";
					}
					else if (check[i].w5 == "") 
					{
						check[i].w5 = "X";
					}
					else if (check[i].w6 == "") 
					{
						check[i].w6 = "X";
					}
					else 
					{
						flag = 1;
					}
				}
				else 
				{
					flag = 1;
				}
				/*check[i].w1 = "X";
				check[i].w2 = "X";
				check[i].w3 = "X";
				check[i].w4 = "X";
				check[i].w5 = "X";
				check[i].w6 = "X";*/
				//file << check[i].No << "," << check[i].id << "," << check[i].w1 << ',' << check[i].w2 << ',' << check[i].w3 << ',' << check[i].w4 << ',' << check[i].w5 << ',' << check[i].w6 << '\n';
			}
			file << check[i].No << "," << check[i].id << "," << check[i].w1 << ',' << check[i].w2 << ',' << check[i].w3 << ',' << check[i].w4 << ',' << check[i].w5 << ',' << check[i].w6 << '\n';
		}
		if (flag == 1) 
		{
			printXY(out, (CONSOLE_WIDTH - str.size() + 1) / 2 - 10, 15 + 8);
		}
		else 
		{
			printXY(str, (CONSOLE_WIDTH - str.size() + 1) / 2, 25 + 8);
		}
	}
	file.close();
	system("pause>nul");
}
void loadScore(scores s[], int &max) 
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
void showScore(scores s[], string mssv, int max) 
{
	system("cls");
	string fline = "No\t   ID\t\tMid-term\tFinal\t   Lab\tBonus", str = "Press any key to return ...", in = "ID Student : ";
	printXY(in, (CONSOLE_WIDTH - str.size() + 1) / 2, 5 + 8);
	cin >> mssv;
	for (int k = 0; k <= max; k++) 
	{
		if (s[k].id == mssv) 
		{
			printXY(fline, (CONSOLE_WIDTH + 1) / 2 - 43, 7 + 5 * 2);
			printXY(s[k].No + '\t' + s[k].id + "\t   " + s[k].mid + "\t\t  " + s[k].fin + "\t   " + s[k].lab + "\t   " + s[k].bonus, (CONSOLE_WIDTH + 1) / 2 - 43, 10 + 5 * 2); //5 = k
			break;
		}
	}
	printXY(str, (CONSOLE_WIDTH - str.size() + 1) / 2, 25 + 8);
	system("pause>nul");
}
int StudentMenu() 
{
	setConsoleSize(CONSOLE_WIDTH, CONSOLE_HEIGHT);
	checkin check[X];
	scores s[X];
	string 	*splashData = NULL, *Menu = NULL, *TKB = NULL, mssv, *ScoreBoard = NULL;
	TKB = new string[CONSOLE_HEIGHT];
	splashData = new string[CONSOLE_HEIGHT];
	Menu = new string[CONSOLE_HEIGHT];
	ScoreBoard = new string[CONSOLE_HEIGHT];
	int splashLines = 0, MenuLines = 0, menuCurrent = 0, SBLines = 0, TKBLines, max;
	StudentMenu(Menu, &MenuLines);
	loadCheckin(check, max);
	loadScore(s, max);
	while (true) 
	{
		showStudentMenu(splashData, &splashLines, Menu, &MenuLines, &menuCurrent);
		switch (menuCurrent) 
		{
		case 0:
			saveCheckin(check, mssv, max);
			break;
		case 1:
			showCheckin(check, mssv, max);
			break;
		case 2:
			Schedules(TKB, &TKBLines);
			showSchedules(TKB, &TKBLines);
			break;
		case 3:
			showScore(s, mssv, max);
			break;
		case 4: 
			return 4;
		case 5:
			return 5;
		case 6:
			return 6;// 1 logout
		}
	}
	return 0;
}