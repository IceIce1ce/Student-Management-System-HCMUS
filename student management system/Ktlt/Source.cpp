#include "courses.h"
int loadCourse(const char *path, Course s[])
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
void saveCourse(const char *path, Course s[], int n)
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
void showCourse(const char *path, Course s[], int n)
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
		cout<< s[t].stt << "\t " << s[t].id << "\t " << s[t].name << "\t " << s[t].classSV << "\t " << s[t].lecAcc << "\t " << s[t].startDate << "\t " << s[t].endDate << "\t " << s[t].dayOfweek << "\t " << s[t].startHour << "\t " << s[t].endHour << "\t " << s[t].room << endl;
	}
}
void addCourse(const char *path, Course s[], int &n)
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
void addCo(Course s1[], Course s2[], Course s3[], Course s4[], Course s5[])
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
		int addco1 = loadCourse("tkb1.csv", s1);
		addco1++;
		addCourse("tkb1.csv", s1, addco1);
	}
	else if (check == 2)
	{
		system("cls");
		int addco2 = loadCourse("tkb2.csv", s2);
		addco2++;
		addCourse("tkb2.csv", s2, addco2);
	}
	else if (check == 3)
	{
		system("cls");
		int addco3 = loadCourse("tkb3.csv", s3);
		addco3++;
		addCourse("tkb3.csv", s3, addco3);
	}
	else if(check == 4)
	{
		system("cls");
		int addco4 = loadCourse("tkb4.csv", s4);
		addco4++;
		addCourse("tkb4.csv", s4, addco4);
	}
	else if(check==5)
	{
		system("cls");
		int addco5 = loadCourse("tkb5.csv", s5);
		addco5++;
		addCourse("tkb5.csv", s5, addco5);
	}
	else if (check == 6)
	{
		exit(0);
	}
}
Course loaddata(const char *path)
{
	Course s;
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
int deleteCourse(const char *path, Course s[], int &n) 
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
void delCo(Course s1[], Course s2[], Course s3[], Course s4[], Course s5[])
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
	if(check==1)
	{
		system("cls");
		int del1 = loadCourse("tkb1.csv", s1);
		int de1 = deleteCourse("tkb1.csv", s1, del1);
		int deA = loadCourse("tkb1.csv", s1);
		saveCourse("tkb1.txt", s1, de1);
	}
	else if(check==2)
	{
		system("cls"); 
		int del2 = loadCourse("tkb2.csv", s2);
		int de2 = deleteCourse("tkb2.csv", s2, del2);
		int deB = loadCourse("tkb2.csv", s2);
		saveCourse("tkb2.txt", s2, de2);
	}
	else if(check==3)
	{
		system("cls");
		int del3 = loadCourse("tkb3.csv", s3);
		int de3 = deleteCourse("tkb3.csv", s3, del3);
		int deC = loadCourse("tkb3.csv", s3);
		saveCourse("tkb3.txt", s3, de3);
 	}
	else if(check==4)
	{
		system("cls");
		int del4 = loadCourse("tkb4.csv", s4);
		int de4 = deleteCourse("tkb4.csv", s4, del4);
		int deD = loadCourse("tkb4.csv", s4);
		saveCourse("tkb4.txt", s4, de4);
	}
	else if(check==5)
	{
		system("cls");
		int del5 = loadCourse("tkb5.csv", s5);
		int de5 = deleteCourse("tkb5.csv", s5, del5);
		int deE = loadCourse("tkb5.csv", s5);
		saveCourse("tkb5.txt", s5, de5);
	}
	else if(check==6)
	{
		exit(0);
	}
}
int editCourse(const char *path, Course s[], int &n)
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
void ediCo(Course s1[], Course s2[], Course s3[], Course s4[], Course s5[])
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
		int edico1 = loadCourse("tkb1.csv", s1);
		int edi1 = editCourse("tkb1.csv", s1, edico1);
		int ediA = loadCourse("tkb1.csv", s1);
		saveCourse("tkb1.txt", s1, edi1);
	}
	else if (check == 2)
	{
		system("cls");
		int edico2 = loadCourse("tkb2.csv", s2);
		int edi2 = editCourse("tkb2.csv", s2, edico2);
		int ediB = loadCourse("tkb2.csv", s2);
		saveCourse("tkb2.txt", s2, edi2);
	}
	else if (check == 3)
	{
		system("cls");
		int edico3 = loadCourse("tkb3.csv", s3);
		int edi3 = editCourse("tkb3.csv", s3, edico3);
		int ediC = loadCourse("tkb3.csv", s3);
		saveCourse("tkb3.txt", s3, edi3);
	}
	else if (check == 4)
	{
		system("cls");
		int edico4 = loadCourse("tkb4.csv", s4);
		int edi4 = editCourse("tkb4.csv", s4, edico4);
		int ediD = loadCourse("tkb4.csv", s4);
		saveCourse("tkb4.txt", s4, edi4);
	}
	else if (check == 5)
	{
		system("cls");
		int edico5 = loadCourse("tkb5.csv", s5);
		int edi5 = editCourse("tkb5.csv", s5, edico5);
		int ediE = loadCourse("tkb5.csv", s5);
		saveCourse("tkb5.txt", s5, edi5);
	}
	else if (check == 6)
	{
		exit(0);
	}
}