#include"honganh.h"
#include"lecturerMenu.h"
using namespace std;
typedef char str[30];
str manipulate[7] = { "Course of clc1","Course of clc2","Course of clc3", "Course of clc4","Course of clc5","Course of clc6","Exit" };
str studentcourse[7] = { "CLC1", "CLC2", "CLC3", "CLC4", "CLC5", "CLC6", "Exit" };
str AttendanceOfCourse[7] = { "Attendance of CLC1", "Attendance of CLC2", "Attendance of CLC3", "Attendance of CLC4", "Attendance of CLC5", "Attendance of CLC6", "Exit" };
void hide()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}
// VIEW LIST OF COURSE OF CURRENT SEMESTER
void Course(int n, COURSE s1[], COURSE s2[], COURSE s3[], COURSE s4[], COURSE s5[], COURSE s6[])
{
	hide();
	int state = 0, color[10];// vi tri la noi con cho o menu
	for (int i = 0; i < n; i++)
	{
		color[i] = 15;
	}
	color[state] = 10;
	while (1)
	{
		system("cls");
		for (int i = 0; i < n; i++)
		{
			TextColor(color[i]);
			gotoXY(50, 10 + i);
			cout << manipulate[i];
		}
		char key = _getch();
		if (key == 72) state--;
		else if (key == 80) state++;
		if (state == -1) state = 6;
		if (state == 7) state = 0; // Thay doi vi tri neu qua menu

		if (key == 13 && state == 0)//PVP
		{
			system("cls");
			showCourse("courseclc1.txt", s1);
			returnmenu(s1, s2, s3, s4, s5, s6);
		}
		else if (key == 13 && state == 1)
		{
			system("cls");
			showCourse("courseclc2.txt", s2);
			returnmenu(s1, s2, s3, s4, s5, s6);
		}
		else if (key == 13 && state == 2)
		{
			system("cls");
			showCourse("courseclc3.txt", s3);
			returnmenu(s1, s2, s3, s4, s5, s6);
		}
		else if (key == 13 && state == 3)
		{
			system("cls");
			showCourse("courseclc4.txt", s4);
			returnmenu(s1, s2, s3, s4, s5, s6);
		}
		else if (key == 13 && state == 4)
		{
			system("cls");
			showCourse("courseclc5.txt", s5);
			returnmenu(s1, s2, s3, s4, s5, s6);
		}
		else if (key == 13 && state == 5)
		{
			system("cls");
			showCourse("courseclc6.txt", s6);
			returnmenu(s1, s2, s3, s4, s5, s6);
		}

		else if (key == 13 && state == 6)
		{
			system("cls");
			break;
		}
		//khoi tao lai mau
		for (int i = 0; i < n; i++)
		{
			color[i] = 15;
		}
		color[state] = 10;

	}
}
int loadCourse(const char *path, COURSE s[]) 
{
	ifstream fin;
	fin.open(path);
	if (!fin.is_open()) 
	{
		cout << "Error";
		return 0;
	}
	int i = 0;
	while (!fin.eof())
	{
		getline(fin, s[i].Case, ',');
		getline(fin, s[i].time, ',');
		getline(fin, s[i].mon, ',');
		getline(fin, s[i].tues, ',');
		getline(fin, s[i].wed, ',');
		getline(fin, s[i].thur, ',');
		getline(fin, s[i].fri, ',');
		getline(fin, s[i].satur, '\n');
		i++;
	}
	fin.close();
	return i;
}
void saveCourse(const char *path, COURSE s[], int n)
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "Error";
	}
	for (int i = 0; i < n; i++)
	{
		fout << s[i].Case << " " << s[i].time << " " << s[i].mon << " " << s[i].tues << " " << s[i].wed << " " << s[i].thur << " " << s[i].fri << " " << s[i].satur << "\n";
	}
	fout.close();
}
void showCourse(const char *path, COURSE s[])
{
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Error";
		return;
	}
	for (int i = 0; i < 5; i++)
	{
		gotoXY(5, 5 + i + i);
		cout << "\t" << s[i].Case << "\t" << s[i].time << "\t" << s[i].mon << "\t\t" << s[i].tues << "\t\t" << s[i].wed << "\t\t" << s[i].thur << "\t\t" << s[i].fri << "\t\t" << s[i].satur << "\n" << endl;
	}
	fin.close();
}
void returnmenu(COURSE s1[], COURSE s2[], COURSE s3[], COURSE s4[], COURSE s5[], COURSE s6[])
{
	gotoXY(50, 20);
	cout << "Press enter to return";
	system("pause>nul");
	char key = _getch();
	if (key == 13)
	{
		system("cls");
		Course(7, s1, s2, s3, s4, s5, s6);
	}
}
// VIEW STUDENTS OF THE COURSE
int loadStudent(const char *path, STUDENT st[])
{
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Error!";
		return 0;
	}
	int i = 0;
	while (!fin.eof())
	{
		getline(fin, st[i].stt, ',');
		getline(fin, st[i].id, ',');
		getline(fin, st[i].name, ',');
		getline(fin, st[i].sb1, ',');
		getline(fin, st[i].sb2, ',');
		getline(fin, st[i].sb3, ',');
		getline(fin, st[i].sb4, ',');
		getline(fin, st[i].sb5, ',');
		getline(fin, st[i].sb6, '\n');
		i++;
	}
	fin.close();
	return i;
}
void saveStudent(const char *path, STUDENT st[], int n)
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "Error!";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		fout << st[i].stt << " " << st[i].id << " " << st[i].name << " " << st[i].sb1 << " " << st[i].sb2 << " " << st[i].sb3 << " " << st[i].sb4 << " " << st[i].sb5 << " " << st[i].sb6 << endl;
	}
	fout.close();
}
void showStudent(const char *path, STUDENT st[], int n)
{
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Error!";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		cout << st[i].id << "\t" << st[i].name << endl;
	}
	fin.close();
}
void Studentofcourse(int n, STUDENT st1[], STUDENT st2[], STUDENT st3[], STUDENT st4[], STUDENT st5[], STUDENT st6[])
{
	hide();
	int state = 0, color[10];
	for (int i = 0; i < n; i++)
	{
		color[i] = 15;
	}
	color[state] = 10;
	while (1)
	{
		system("cls");
		for (int i = 0; i < n; i++)
		{
			TextColor(color[i]);
			gotoXY(50, 10 + i);
			cout << studentcourse[i];
		}
		char key = _getch();
		if (key == 72) state--;
		else if (key == 80) state++;
		if (state == -1) state = 6;
		if (state == 7) state = 0;

		if (key == 13 && state == 0)
		{
			system("cls");
			int stdclc1 = loadStudent("stdclc1.csv", st1);
			showStudent("stdclc1.txt", st1, stdclc1);
			returnstudent(st1, st2, st3, st4, st5, st6);
		}
		else if (key == 13 && state == 1)
		{
			system("cls");
			int stdclc2 = loadStudent("stdclc2.csv", st2);
			showStudent("stdclc2.txt", st2, stdclc2);
			returnstudent(st1, st2, st3, st4, st5, st6);
		}
		else if (key == 13 && state == 2)
		{
			system("cls");
			int stdclc3 = loadStudent("stdclc3.csv", st3);
			showStudent("stdclc3.txt", st3, stdclc3);
			returnstudent(st1, st2, st3, st4, st5, st6);
		}
		else if (key == 13 && state == 3)
		{
			system("cls");
			int stdclc4 = loadStudent("stdclc4.csv", st4);
			showStudent("stdclc4.txt", st4, stdclc4);
			returnstudent(st1, st2, st3, st4, st5, st6);
		}
		else if (key == 13 && state == 4)
		{
			system("cls");
			int stdclc5 = loadStudent("stdclc5.csv", st5);
			showStudent("stdclc5.txt", st5, stdclc5);
			returnstudent(st1, st2, st3, st4, st5, st6);
		}
		else if (key == 13 && state == 5)
		{
			system("cls");
			int stdclc6 = loadStudent("stdclc6.csv", st6);
			showStudent("stdclc6.txt", st6, stdclc6);
			returnstudent(st1, st2, st3, st4, st5, st6);
		}

		else if (key == 13 && state == 6)
		{
			system("cls");
			break;
		}
		//khoi tao lai mau
		for (int i = 0; i < n; i++)
		{
			color[i] = 15;
		}
		color[state] = 10;
	}
}
void returnstudent(STUDENT st1[], STUDENT st2[], STUDENT st3[], STUDENT st4[], STUDENT st5[], STUDENT st6[])
{
	char key = _getch();
	cout << "Enter any key to back list of student of course: ";
	system("pause>nul");
	if (key == 27)
	{
		system("cls");
	
		Studentofcourse(7, st1, st2, st3, st4, st5, st6);
	}
}
void addStudent(const char *path, STUDENT st[], int &n)
{
	ofstream fout;
	fout.open(path, ios::app);
	if (!fout.is_open())
	{
		cout << "error";
	}
	st[n].stt = n;
	st[n].sb1 = " ";
	st[n].sb2 = " ";
	st[n].sb3 = " ";
	st[n].sb4 = " ";
	st[n].sb5 = " ";
	st[n].sb6 = " ";
	cout << "New ID: "; cin >> st[n].id;
	cout << "New name: "; cin.ignore(); getline(cin, st[n].name, '\n');
	fout << st[n].stt << ',' << st[n].id << ',' << st[n].name << ',' << st[n].sb1 << ',' << st[n].sb2 << ',' << st[n].sb3 << ',' << st[n].sb4 << ',' << st[n].sb5 << ',' << st[n].sb6 << '\n';
	n++;
	fout.close();
}
void addSt(STUDENT st1[], STUDENT st2[], STUDENT st3[], STUDENT st4[], STUDENT st5[], STUDENT st6[])
{
	int check;
	cout << "1. CLC1 " << endl;
	cout << "2. CLC2 " << endl;
	cout << "3. CLC3 " << endl;
	cout << "4. CLC4 " << endl;
	cout << "5. CLC5 " << endl;
	cout << "6. CLC6 " << endl;
	cout << "Your choice 1 - 6: ";
	cin >> check;
	switch (check) {
	case 1:
	{
		system("cls");
		int add1 = loadStudent("stdclc1.csv", st1);
		add1++;
		addStudent("stdclc1.csv", st1, add1);
		break;
	}
	case 2:
	{
		system("cls");
		int add2 = loadStudent("stdclc2.csv", st2);
		add2++;
		addStudent("stdclc2.csv", st2, add2);
		break;
	}
	case 3:
	{
		system("cls");
		int add3 = loadStudent("stdclc3.csv", st3);
		add3++;
		addStudent("stdclc3.csv", st3, add3);
		break;
	}
	case 4:
	{
		system("cls");
		int add4 = loadStudent("stdclc4.csv", st4);
		add4++;
		addStudent("stdclc2.csv", st4, add4);
		break;
	}
	case 5:
	{
		system("cls");
		int add5 = loadStudent("stdclc5.csv", st5);
		add5++;
		addStudent("stdclc5.csv", st5, add5);
		break;
	}
	case 6:
	{
		system("cls");
		int add6 = loadStudent("stdclc.csv", st6);
		add6++;
		addStudent("stdclc6.csv", st6, add6);
		break;
	}
	}
}
void deleteStudent(const char *path, STUDENT st[], int &n)
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "Error";
	}
	string id;
	cout << "Enter ID of student to delete: ";
	cin >> id;
	for (int i = 0; i < n; i++)
	{
		if (st[i].id != id)
		{
			fout << st[i].stt << ',' << st[i].id << ',' << st[i].name << ',' << st[i].sb1 << ',' << st[i].sb2 << ',' << st[i].sb3 << ',' << st[i].sb4 << ',' << st[i].sb5 << ',' << st[i].sb6 << '\n';
		}
		if (st[i].id == id)
		{
			st[i] = st[i - 1];
		}
	}
	n--;
	fout.close();
}
void delSt(STUDENT st1[], STUDENT st2[], STUDENT st3[], STUDENT st4[], STUDENT st5[], STUDENT st6[])
{
	int check;
	cout << "1. CLC1 " << endl;
	cout << "2. CLC2 " << endl;
	cout << "3. CLC3 " << endl;
	cout << "4. CLC4 " << endl;
	cout << "5. CLC5 " << endl;
	cout << "6. CLC6 " << endl;
	cout << "Your choice 1 - 6: ";
	cin >> check;
	switch (check) {
	case 1:
	{
		system("cls");
		int del1 = loadStudent("stdclc1.csv", st1);
		deleteStudent("stdclc1.csv", st1, del1);
		break;
	}
	case 2:
	{
		system("cls");
		int del2 = loadStudent("stdclc2.csv", st2);
		deleteStudent("stdclc2.csv", st2, del2);
		break;
	}
	case 3:
	{
		system("cls");
		int del3 = loadStudent("stdclc3.csv", st3);
		deleteStudent("stdclc3.csv", st3, del3);
		break;
	}
	case 4:
	{
		system("cls");
		int del4 = loadStudent("stdclc4.csv", st4);
		deleteStudent("stdclc2.csv", st4, del4);
		break;
	}
	case 5:
	{
		system("cls");
		int del5 = loadStudent("stdclc5.csv", st5);
		deleteStudent("stdclc5.csv", st5, del5);
		break;
	}
	case 6:
	{
		system("cls");
		int del6 = loadStudent("stdclc.csv", st6);
		deleteStudent("stdclc6.csv", st6, del6);
		break;
	}
	}
}
// VIEW ALL LECTURES
int loadLecture(const char *path, LECTURE lt[])
{
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Cannot access to data";
		return 0;
	}
	int i = 0;
	while (!fin.eof())
	{
		getline(fin, lt[i].id, ',');
		getline(fin, lt[i].name, ',');
		getline(fin, lt[i].email, ',');
		getline(fin, lt[i].officehour, ',');
		getline(fin, lt[i].major, '\n');
		i++;
	}
	fin.close();
	return i;
}
void saveLecture(const char *path, LECTURE lt[], int n)
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "Cannot access to data";
	}
	int i = 0;
	for (int i = 0; i < n; i++)
	{
		fout << lt[i].id << " " << lt[i].name << " " << lt[i].email << " " << lt[i].officehour << " " << lt[i].major << endl;
	}
	fout.close();
}
void viewAllLecture(const char *path, LECTURE lt[], int n)
{
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Cannot access to data";
		return;
	}
	int i;
	for (i = 0; i < n; i++)
	{
		cout << lt[i].id << "\t " << lt[i].name << "\t\t" << lt[i].email << "\t\t" << lt[i].officehour << "\t\t" << lt[i].major << endl;
	}
	fin.close();
	system("pause>nul");                       
}
void addLecture(const char *path, LECTURE lt[], int &n)
{                               
	ofstream fout;
	fout.open(path, ios::app);
	if (!fout.is_open())
	{
		cout << "error";
	}
	cout << "Enter new id of new lecture: "; cin >> lt[n].id;
	cout << "Enter name of new lecture: "; cin.ignore(); getline(cin, lt[n].name, '\n');
	cout << "Enter email of new lecture: "; cin >> lt[n].email;
	cout << "Enter office hour of new lecture: "; cin >> lt[n].officehour;
	cout << "Enter major of new lecture: "; cin.ignore(); getline(cin, lt[n].major, '\n');
	fout << lt[n].id << ',' << lt[n].name << ',' << lt[n].email << ',' << lt[n].officehour << ',' << lt[n].major << '\n';
	n++;
	fout.close();
	system("pause>nul");
}
void addLec(LECTURE lt[])
{
	int lecture = loadLecture("lecture.csv", lt);
	lecture++;
	addLecture("lecture.csv", lt, lecture);
}
void deleteLecture(const char *path, LECTURE lt[], int &n)
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "Error";
		return;
	}
	int i;
	string id;
	cout << "Enter the id of lecture to delete: ";
	cin >> id;
	for (i = 0; i < n; i++)
	{
		if (lt[i].id != id)
		{
			fout << lt[i].id << ',' << lt[i].name << ',' << lt[i].email << ',' << lt[i].officehour << ',' << lt[i].major << '\n';
		}
		if (lt[i].id == id)
		{
			lt[i] = lt[i - 1];
		}
	}
	n--;
	fout.close();
}
void deleteLec(LECTURE lt[])
{
	int lecture = loadLecture("lecture.csv", lt);
	deleteLecture("lecture.csv", lt, lecture);
}
//VIEW ATTENDANCE
int loadAttendance(const char *path, ATTENDANCE at[])
{
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Error!";
		return 0;
	}
	int i = 0;
	while (!fin.eof())
	{
		getline(fin, at[i].stt, ',');
		getline(fin, at[i].id, ',');
		getline(fin, at[i].name, ',');
		getline(fin, at[i].sb1, ',');
		getline(fin, at[i].sb2, ',');
		getline(fin, at[i].sb3, ',');
		getline(fin, at[i].sb4, ',');
		getline(fin, at[i].sb5, ',');
		getline(fin, at[i].sb6, '\n');
		i++;
	}
	fin.close();
	return i;
}
void saveAttendance(const char *path, ATTENDANCE at[], int n)
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "Error!";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		fout << at[i].stt << " " << at[i].id << " " << at[i].name << " " << at[i].sb1 << " " << at[i].sb2 << " " << at[i].sb3 << " " << at[i].sb4 << " " << at[i].sb5 << at[i].sb6 << endl;
	}
	fout.close();
}
void showAttendance(const char *path, ATTENDANCE at[], int n)
{
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Error!";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		cout << at[i].stt << "\t" << at[i].id << "\t" << at[i].name << endl;
	}
	fin.close();
}

void Attendance(int n, ATTENDANCE at1[], ATTENDANCE at2[], ATTENDANCE at3[], ATTENDANCE at4[], ATTENDANCE at5[], ATTENDANCE at6[])
{
	hide();
	int state = 0, color[10];
	for (int i = 0; i < n; i++)
	{
		color[i] = 15;
	}
	color[state] = 10;
	while (1)
	{
		system("cls");
		for (int i = 0; i < n; i++)
		{
			TextColor(color[i]);
			gotoXY(50, 10 + i);
			cout << studentcourse[i];
		}
		char key = _getch();
		if (key == 72) state--;
		else if (key == 80) state++;
		if (state == -1) state = 6;
		if (state == 7) state = 0;

		if (key == 13 && state == 0)
		{
			system("cls");
			int stdclc1 = loadAttendance("stdclc1.csv", at1);
			showAttendance("stdclc1.txt", at1, stdclc1);
			returnAttendance(at1, at2, at3, at4, at5, at6);
		}
		else if (key == 13 && state == 1)
		{
			system("cls");
			int stdclc2 = loadAttendance("stdclc2.csv", at2);
			showAttendance("stdclc2.txt", at2, stdclc2);
			returnAttendance(at1, at2, at3, at4, at5, at6);
		}
		else if (key == 13 && state == 2)
		{
			system("cls");
			int stdclc3 = loadAttendance("stdclc3.csv", at3);
			showAttendance("stdclc3.txt", at3, stdclc3);
			returnAttendance(at1, at2, at3, at4, at5, at6);
		}
		else if (key == 13 && state == 3)
		{
			system("cls");
			int stdclc4 = loadAttendance("stdclc4.csv", at4);
			showAttendance("stdclc4.txt", at4, stdclc4);
			returnAttendance(at1, at2, at3, at4, at5, at6);
		}
		else if (key == 13 && state == 4)
		{
			system("cls");
			int stdclc5 = loadAttendance("stdclc5.csv", at5);
			showAttendance("stdclc5.txt", at5, stdclc5);
			returnAttendance(at1, at2, at3, at4, at5, at6);
		}
		else if (key == 13 && state == 5)
		{
			system("cls");
			int stdclc6 = loadAttendance("stdclc6.csv", at6);
			showAttendance("stdclc6.txt", at6, stdclc6);
			returnAttendance(at1, at2, at3, at4, at5, at6);
		}

		else if (key == 13 && state == 6)
		{
			system("cls");
			break;
		}
		//khoi tao lai mau
		for (int i = 0; i < n; i++)
		{
			color[i] = 15;
		}
		color[state] = 10;
	}
}
void returnAttendance(ATTENDANCE at1[], ATTENDANCE at2[], ATTENDANCE at3[], ATTENDANCE at4[], ATTENDANCE at5[], ATTENDANCE at6[])
{
	gotoXY(50, 50);
	cout << "Press enter to back menu attendance";
	char key = _getch();
	system("pause>nul");
	if (key == 13)
	{
		system("cls");
		Attendance(7, at1, at2, at3, at4, at5, at6);
	}
}
//SEARCH AND VIEW SCOREBOARD
void showScore(const char *path, STUDENT st[], int n)
{
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Error!";
		return;
	}
	string check;
	cout << "Enter the course: ";
	cin >> check;
	system("cls");
	if (check == st[0].sb1)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "\t" << st[i].stt << "\t\t" << st[i].id;
			gotoXY(40, i);
			cout << st[i].name;
			gotoXY(70, i);
			cout << st[i].sb1 << endl;
		}
	}
	else if (check == st[0].sb2)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "\t" << st[i].stt << "\t\t" << st[i].id;
			gotoXY(40, i);
			cout << st[i].name;
			gotoXY(70, i);
			cout << st[i].sb2 << endl;
		}
	}
	else if (check == st[0].sb3)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "\t" << st[i].stt << "\t\t" << st[i].id;
			gotoXY(40, i);
			cout << st[i].name;
			gotoXY(70, i);
			cout << st[i].sb3 << endl;
		}
	}
	else if (check == st[0].sb4)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "\t" << st[i].stt << "\t\t" << st[i].id;
			gotoXY(40, i);
			cout << st[i].name;
			gotoXY(70, i);
			cout << st[i].sb4 << endl;
		}
	}
	else if (check == st[0].sb5)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "\t" << st[i].stt << "\t\t" << st[i].id;
			gotoXY(40, i);
			cout << st[i].name;
			gotoXY(70, i);
			cout << st[i].sb5 << endl;
		}
	}
	else if (check == st[0].sb6)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "\t" << st[i].stt << "\t\t" << st[i].id;
			gotoXY(40, i);
			cout << st[i].name;
			gotoXY(70, i);
			cout << st[i].sb6 << endl;
		}
	}
	else
	{
		cout << "Name of course is wrong";
	}
}
void ScoreBoard(int n, STUDENT st1[], STUDENT st2[], STUDENT st3[], STUDENT st4[], STUDENT st5[], STUDENT st6[]) /// sssss2
{
	hide();
	int state = 0, color[10];
	for (int i = 0; i < n; i++)
	{
		color[i] = 15;
	}
	color[state] = 10;
	while (1)
	{
		system("cls");
		for (int i = 0; i < n; i++)
		{
			TextColor(color[i]);
			gotoXY(50, 10 + i);
			cout << studentcourse[i];
		}
		char key = _getch();
		if (key == 72) state--;
		else if (key == 80) state++;
		if (state == -1) state = 6;
		if (state == 7) state = 0;

		if (key == 13 && state == 0)
		{
			system("cls");
			int stdclc1 = loadStudent("stdclc1.csv", st1);
			showScore("stdclc1.txt", st1, stdclc1);
			returnscore(st1, st2, st3, st4, st5, st6);
		}
		else if (key == 13 && state == 1)
		{
			system("cls");
			int stdclc2 = loadStudent("stdclc2.csv", st2);
			showStudent("stdclc2.txt", st2, stdclc2);
			returnscore(st1, st2, st3, st4, st5, st6);
		}
		else if (key == 13 && state == 2)
		{
			system("cls");
			int stdclc3 = loadStudent("stdclc3.csv", st3);
			showStudent("stdclc3.txt", st3, stdclc3);
			returnscore(st1, st2, st3, st4, st5, st6);
		}
		else if (key == 13 && state == 3)
		{
			system("cls");
			int stdclc4 = loadStudent("stdclc4.csv", st4);
			showStudent("stdclc4.txt", st4, stdclc4);
			returnscore(st1, st2, st3, st4, st5, st6);
		}
		else if (key == 13 && state == 4)
		{
			system("cls");
			int stdclc5 = loadStudent("stdclc5.csv", st5);
			showStudent("stdclc5.txt", st5, stdclc5);
			returnscore(st1, st2, st3, st4, st5, st6);
		}
		else if (key == 13 && state == 5)
		{
			system("cls");
			int stdclc6 = loadStudent("stdclc6.csv", st6);
			showStudent("stdclc6.txt", st6, stdclc6);
			returnscore(st1, st2, st3, st4, st5, st6);
		}

		else if (key == 13 && state == 6)
		{
			system("cls");
			break;
		}
		//khoi tao lai mau
		for (int i = 0; i < n; i++)
		{
			color[i] = 15;
		}
		color[state] = 10;
	}
}
void returnscore(STUDENT st1[], STUDENT st2[], STUDENT st3[], STUDENT st4[], STUDENT st5[], STUDENT st6[])
{
	char key = _getch();
	cout << "Press enter to back the scoreboard menu";
	system("pause>nul");
	if (key == 13)
	{
		system("cls");
		ScoreBoard(7, st1, st2, st3, st4, st5, st6);
	}
}
///////tu tren tro len, thay het
void StaffCMenu(string *Menu, int * MenuLines) {
	string line;
	*MenuLines = 0;
	ifstream file("StaffMenu.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			Menu[*MenuLines] = line;
			*MenuLines = *MenuLines + 1;
		}
		file.close();
	}
}
void showStaffCMenu(string *splashData, int * lines, string * mainMenu, int * mainMenuLines, int * menuCurrent) {
	int 	b = 0,
		maxLength = 0;
	setConsoleSize(CONSOLE_WIDTH, 50);
	for (int i = 0; i < *lines; i++)
		if (splashData[i].size() > maxLength) maxLength = splashData[i].size();

	system("cls");
	for (int i = 0; i < *lines; i++)
		printXY(splashData[i], (CONSOLE_WIDTH - maxLength + 1) / 2, 6 + i);

	while (true) {

		for (int i = 0; i < *mainMenuLines; i++) {
			if (i == *menuCurrent) {
				setColor(14);
				printXY(">>>  " + mainMenu[i] + "   ", (CONSOLE_WIDTH + 1) / 2 - 30, 6 +*lines + i * 2);
				setColor(7);
			}
			else printXY("        " + mainMenu[i], (CONSOLE_WIDTH + 1) / 2 - 30, 6 + *lines + i * 2);
		}
		while (!_kbhit()) {}
		b = getInput();
		if (b == 224) {
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
		else {
			if (b == 13)
				return;
		}
	}
}
int loadCourse1(const char* path, Course1 s[])
{
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Error" << endl;
		return 0;
	}
	int i = 0;
	while (fin.good())
	{
		getline(fin, s[i].stt, ',');
		getline(fin, s[i].id, ',');
		getline(fin, s[i].name, ',');
		getline(fin, s[i].classSV, ',');
		getline(fin, s[i].lecAcc, ',');
		getline(fin, s[i].startDate, ',');
		getline(fin, s[i].endDate, ',');
		getline(fin, s[i].dayOfweek, ',');
		getline(fin, s[i].startHour, ',');
		getline(fin, s[i].endHour, ',');
		getline(fin, s[i].room, '\n');
		i++;
	}
	fin.close();
	return i;
}
void saveCourse1(const char* path, Course1 s[], int n)
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "Error" << endl;
		return;
	}
	int t;
	for (t = 0; t < n; t++)
	{
		fout << s[t].stt << " " << s[t].id << " " << s[t].name << " " << s[t].classSV << " " << s[t].lecAcc << " " << s[t].startDate << " " << s[t].endDate << " " << s[t].dayOfweek << " " << s[t].startHour << " " << s[t].endHour << " " << s[t].room << endl;
	}
	fout.close();
}
void showCourse1(const char* path, Course1 s[], int n)
{
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Error";
		return;
	}
	for (int t = 0; t < n; t++)
	{
		cout << s[t].stt << "\t " << s[t].id << "\t " << s[t].name << "\t " << s[t].classSV << "\t " << s[t].lecAcc << "\t " << s[t].startDate << "\t " << s[t].endDate << "\t " << s[t].dayOfweek << "\t " << s[t].startHour << "\t " << s[t].endHour << "\t " << s[t].room << endl;
	}
}
Course1 loaddata1(const char* path)
{
	Course1 s;
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Error" << endl;
	}
	while (fin.good())
	{
		getline(fin, s.stt, ',');
		getline(fin, s.id, ',');
		getline(fin, s.name, ',');
		getline(fin, s.classSV, ',');
		getline(fin, s.lecAcc, ',');
		getline(fin, s.startDate, ',');
		getline(fin, s.endDate, ',');
		getline(fin, s.dayOfweek, ',');
		getline(fin, s.startHour, ',');
		getline(fin, s.endHour, ',');
		getline(fin, s.room, '\n');
	}
	fin.close();
	return s;
}
void addCourse1(const char* path, Course1 s[], int& n)
{
	ofstream fout;
	fout.open(path, ios::app);
	if (!fout.is_open())
	{
		cout << "error";
	}
	cout << "No: ";
	cin >> s[n].stt;
	cout << "ID: ";
	cin >> s[n].id;
	cout << "Name of course: ";
	cin.ignore();
	getline(cin, s[n].name, '\n');
	cout << "Class: ";
	cin >> s[n].classSV;
	cout << "Lecture account: ";
	cin >> s[n].lecAcc;
	cout << "Start date: ";
	cin >> s[n].startDate;
	cout << "End date: ";
	cin >> s[n].endDate;
	cout << "Date of week: ";
	cin >> s[n].dayOfweek;
	cout << "Start hour: ";
	cin >> s[n].startHour;
	cout << "End hour: ";
	cin >> s[n].endHour;
	cout << "Room: ";
	cin >> s[n].room;
	fout << s[n].stt << ',' << s[n].id << ',' << s[n].name << ',' << s[n].classSV << ',' << s[n].lecAcc << ',' << s[n].startDate << ',' << s[n].endDate << ',' << s[n].dayOfweek << ',' << s[n].startHour << ',' << s[n].endHour << ',' << s[n].room << endl;
	n++;
	fout.close();
}
void addCo1(Course1 s1_1[], Course1 s2_2[], Course1 s3_3[], Course1 s4_4[], Course1 s5_5[])
{
	system("cls");
	int check;
	cout << "1. Course CLC1" << endl;
	cout << "2. Course CLC2" << endl;
	cout << "3. Course CLC3" << endl;
	cout << "4. Course CLC4" << endl;
	cout << "5. Course CLC5" << endl;
	cout << "6. Exit" << endl;
	cout << "Enter your choice: ";
	cin >> check;
	if (check == 1)
	{
		system("cls");
		int addco1 = loadCourse1("tkb1.csv", s1_1);
		addco1++;
		addCourse1("tkb1.csv", s1_1, addco1);
	}
	else if (check == 2)
	{
		system("cls");
		int addco2 = loadCourse1("tkb2.csv", s2_2);
		addco2++;
		addCourse1("tkb2.csv", s2_2, addco2);
	}
	else if (check == 3)
	{
		system("cls");
		int addco3 = loadCourse1("tkb3.csv", s3_3);
		addco3++;
		addCourse1("tkb3.csv", s3_3, addco3);
	}
	else if (check == 4)
	{
		system("cls");
		int addco4 = loadCourse1("tkb4.csv", s4_4);
		addco4++;
		addCourse1("tkb4.csv", s4_4, addco4);
	}
	else if (check == 5)
	{
		system("cls");
		int addco5 = loadCourse1("tkb5.csv", s5_5);
		addco5++;
		addCourse1("tkb5.csv", s5_5, addco5);
	}
	else if (check == 6)
	{
		exit(0);
	}
}
int deleteCourse1(const char* path, Course1 s[], int& n)
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "Error";
	}
	string id;
	cout << "Enter ID of course to delete: ";
	cin >> id;
	for (int i = 0; i < n; i++)
	{
		if (s[i].id != id)
		{
			fout << s[i].stt << ',' << s[i].id << ',' << s[i].name << ',' << s[i].classSV << ',' << s[i].lecAcc << ',' << s[i].startDate << ',' << s[i].endDate << ',' << s[i].dayOfweek << ',' << s[i].startHour << ',' << s[i].endHour << ',' << s[i].room << '\n';
		}
	}
	n--;
	fout.close();
	return n;
}
void delCo1(Course1 s1_1[], Course1 s2_2[], Course1 s3_3[], Course1 s4_4[], Course1 s5_5[])
{
	system("cls");
	int check;
	cout << "1. Course CLC1 " << endl;
	cout << "2. Course CLC2 " << endl;
	cout << "3. Course CLC3 " << endl;
	cout << "4. Course CLC4 " << endl;
	cout << "5. Course CLC5 " << endl;
	cout << "6. Exit: " << endl;
	cout << "Enter your choice: ";
	cin >> check;
	if (check == 1)
	{
		system("cls");
		int del1 = loadCourse1("tkb1.csv", s1_1);
		int de1 = deleteCourse1("tkb1.csv", s1_1, del1);
		int deA = loadCourse1("tkb1.csv", s1_1);
		saveCourse1("tkb1.txt", s1_1, de1);
	}
	else if (check == 2)
	{
		system("cls");
		int del2 = loadCourse1("tkb2.csv", s2_2);
		int de2 = deleteCourse1("tkb2.csv", s2_2, del2);
		int deB = loadCourse1("tkb2.csv", s2_2);
		saveCourse1("tkb2.txt", s2_2, de2);
	}
	else if (check == 3)
	{
		system("cls");
		int del3 = loadCourse1("tkb3.csv", s3_3);
		int de3 = deleteCourse1("tkb3.csv", s3_3, del3);
		int deC = loadCourse1("tkb3.csv", s3_3);
		saveCourse1("tkb3.txt", s3_3, de3);
	}
	else if (check == 4)
	{
		system("cls");
		int del4 = loadCourse1("tkb4.csv", s4_4);
		int de4 = deleteCourse1("tkb4.csv", s4_4, del4);
		int deD = loadCourse1("tkb4.csv", s4_4);
		saveCourse1("tkb4.txt", s4_4, de4);
	}
	else if (check == 5)
	{
		system("cls");
		int del5 = loadCourse1("tkb5.csv", s5_5);
		int de5 = deleteCourse1("tkb5.csv", s5_5, del5);
		int deE = loadCourse1("tkb5.csv", s5_5);
		saveCourse1("tkb5.txt", s5_5, de5);
	}
	else if (check == 6)
	{
		exit(0);
	}
}
int editCourse1(const char* path, Course1 s[], int& n)
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "Error";
	}
	string id;
	cout << "Enter ID of course to edit: ";
	cin >> id;
	for (int i = 0; i < n; i++)
	{
		if (s[i].id != id)
		{
			fout << s[i].stt << ',' << s[i].id << ',' << s[i].name << ',' << s[i].classSV << ',' << s[i].lecAcc << ',' << s[i].startDate << ',' << s[i].endDate << ',' << s[i].dayOfweek << ',' << s[i].startHour << ',' << s[i].endHour << ',' << s[i].room << '\n';
		}
		if (s[i].id == id)
		{
			cout << "ID: ";
			cin >> s[i].id;
			cout << "Name of course: ";
			cin.ignore();
			getline(cin, s[i].name, '\n');
			cout << "Class: ";
			cin >> s[i].classSV;
			cout << "Lecture account: ";
			cin.ignore();
			getline(cin, s[i].lecAcc, '\n');
			cout << "Start date: ";
			cin >> s[i].startDate;
			cout << "End date: ";
			cin >> s[i].endDate;
			cout << "Date of week: ";
			cin >> s[i].dayOfweek;
			cout << "Start hour: ";
			cin >> s[i].startHour;
			cout << "End hour: ";
			cin >> s[i].endHour;
			cout << "Room: ";
			cin >> s[i].room;
			fout << s[i].stt << ',' << s[i].id << ',' << s[i].name << ',' << s[i].classSV << ',' << s[i].lecAcc << ',' << s[i].startDate << ',' << s[i].endDate << ',' << s[i].dayOfweek << ',' << s[i].startHour << ',' << s[i].endHour << ',' << s[i].room << '\n';
		}
	}
	fout.close();
	return n;
}
void ediCo1(Course1 s1_1[], Course1 s2_2[], Course1 s3_3[], Course1 s4_4[], Course1 s5_5[])
{
	system("cls");
	int check;
	cout << "1. Course CLC1 " << endl;
	cout << "2. Course CLC2 " << endl;
	cout << "3. Course CLC3 " << endl;
	cout << "4. Course CLC4 " << endl;
	cout << "5. Course CLC5 " << endl;
	cout << "6. Exit: " << endl;
	cout << "Enter your choice: ";
	cin >> check;
	if (check == 1)
	{
		system("cls");
		int edico1 = loadCourse1("tkb1.csv", s1_1);
		int edi1 = editCourse1("tkb1.csv", s1_1, edico1);
		int ediA = loadCourse1("tkb1.csv", s1_1);
		saveCourse1("tkb1.txt", s1_1, edi1);
	}
	else if (check == 2)
	{
		system("cls");
		int edico2 = loadCourse1("tkb2.csv", s2_2);
		int edi2 = editCourse1("tkb2.csv", s2_2, edico2);
		int ediB = loadCourse1("tkb2.csv", s2_2);
		saveCourse1("tkb2.txt", s2_2, edi2);
	}
	else if (check == 3)
	{
		system("cls");
		int edico3 = loadCourse1("tkb3.csv", s3_3);
		int edi3 = editCourse1("tkb3.csv", s3_3, edico3);
		int ediC = loadCourse1("tkb3.csv", s3_3);
		saveCourse1("tkb3.txt", s3_3, edi3);
	}
	else if (check == 4)
	{
		system("cls");
		int edico4 = loadCourse1("tkb4.csv", s4_4);
		int edi4 = editCourse1("tkb4.csv", s4_4, edico4);
		int ediD = loadCourse1("tkb4.csv", s4_4);
		saveCourse1("tkb4.txt", s4_4, edi4);
	}
	else if (check == 5)
	{
		system("cls");
		int edico5 = loadCourse1("tkb5.csv", s5_5);
		int edi5 = editCourse1("tkb5.csv", s5_5, edico5);
		int ediE = loadCourse1("tkb5.csv", s5_5);
		saveCourse1("tkb5.txt", s5_5, edi5);
	}
	else if (check == 6)
	{
		exit(0);
	}
}
//Feature 25
void InputnExportScore(scores sc[], int n) 
{
	system("cls");
	string mssv;
	cout << "ID Student :";
	cin >> mssv;
	ofstream file("ScoreBoard-Copy.csv");
	cout << "Umbla dung hinh";
	if (file.is_open()) 
	{
		int i = 0;
		cout << "AAa";
		for (i; i < n; i++) 
		{
			cout << "Hiiiii";
			//if (sc[i].id != mssv)
			//{ 
			//	cout << "aaaa";
			//	//file << sc[i].No << ',' << sc[i].id << ',' << sc[i].mid << ',' << sc[i].fin << ',' << sc[i].lab << ',' << sc[i].bonus << '\n';
			//}
			if (sc[i].id == mssv) { 
				cout << "Luc Lich Lam";
				cout << "Enter mid-term score : ";
				cin >> sc[i].mid;
				cout << "Enter final-term score : ";
				cin >> sc[i].fin;
				cout << "Enter lab score : ";
				cin >> sc[i].lab;
				cout << "Enter bonus score : ";
				cin >> sc[i].bonus;
			}
			file << sc[i].No << ',' << sc[i].id << ',' << sc[i].mid << ',' << sc[i].fin << ',' << sc[i].lab << ',' << sc[i].bonus << '\n';
		}
		cout << "Edit successfully.";
	}
	else {
		cout << "Can't open.";
	}
	file.close();
	system("pause>nul");
}
//void loadScore(scores sc[], int &max) {
//	system("cls");
//	ifstream file("ScoreBoard.csv");
//	if (file.is_open()) {
//		int i = 0;
//		while (file.good()) {
//			getline(file, sc[i].No, ',');
//			getline(file, sc[i].id, ',');
//			getline(file, sc[i].mid, ',');
//			getline(file, sc[i].fin, ',');
//			getline(file, sc[i].lab, ',');
//			getline(file, sc[i].bonus, '\n');
//			i++;
//		}
//		max = i;
//		file.close();
//	}
int loadScore(const char *path, scores sc[])
{
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Error!";
		return 0;
	}
	int i = 0;
	while (!fin.eof())
	{
		getline(fin, sc[i].No, ',');
		getline(fin, sc[i].id, ',');
		getline(fin, sc[i].mid, ',');
		getline(fin, sc[i].fin, ',');
		getline(fin, sc[i].lab, ',');
		getline(fin, sc[i].bonus, '\n');
		i++;
	}
	fin.close();
	return i;
}