#include "account.h"
#include "sha256.h"
int loadaccount(const char *path,SinhVien s[])
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
		getline(fin, s[i].lname, ',');
		getline(fin, s[i].fname, ',');
		getline(fin, s[i].gender, ',');
		getline(fin, s[i].year, '-');
		getline(fin, s[i].month, '-');
		getline(fin, s[i].day, '\n');
		i++;
	}
	fin.close();
	return i;
}
int saveaccount(const char *path, SinhVien s[], int n,int x)// x=0 viet them vao cuoi file
{
	fstream fout;
	if (x == 0)
		fout.open(path, ios::app);
	else fout.open(path);
	if (!fout.is_open())
	{
		cout << "Error" << endl;
		return 0;
	}
	int t = 0;
	while (t < n-1)
	{
		fout << "1"<<endl;
		fout << s[t].id << endl;
		fout << s[t].day << s[t].month << s[t].year;
		if (t < n - 1) fout << endl;
		t++;
	}
	fout.close();
	return 0;
}
void savedata(const char *path, SinhVien s[], int n, int x,string classSV)// x=0 viet them vao cuoi file
{
	fstream fout;
	if (x == 0)
		fout.open(path, ios::app);
	else fout.open(path);
	if (!fout.is_open())
	{
		cout << "Error" << endl;
		return;
	}
	int t = 0;
	while (t < n - 1)
	{
		fout << s[t].id << ",";
		fout << classSV << ",";
		fout << s[t].lname << " " << s[t].fname << ",";
		fout << s[t].gender << ",";
		fout << s[t].day<<"-" << s[t].month <<"-"<< s[t].year;
		if (t < n - 1) fout << endl;
		t++;
	}
	fout.close();
	return;
}
Data loaddata(const char *path,string tk,int kiemtra) // kiemtra = 1 la loaddata kiemtra=0 la kiem tra khi addsv
{
	Data s;
	int check=0;
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Error" << endl;
	}
	while (fin.good())
	{
		getline(fin, s.id, ',');
		getline(fin, s.classSV, ',');
		getline(fin, s.name, ',');
		getline(fin, s.gender, ',');
		getline(fin, s.BoD, '\n');
		if (s.id.compare(tk) == 0)
		{
			check = 1;
			break;
		}
	}
	fin.close();
	if (check == 1&& kiemtra==0) 
		s.id = "ERROR";
	else s.id = tk;
	return s;
}
string nhapmk(string pass)
{
	char a = '.';
	string input = pass;
	string output = sha256(input);
	while (a != 13)
	{
		if (_kbhit())
		{
			a = _getch();
			if (a == 13) break;
			if (a != 8)
			{
				cout << "*";
				//cout << output;
				pass.push_back(a);
			}
			else
			{
				cout << "\b \b";
				pass.pop_back();
			}
		}
	}
	return pass;
}
string login()
{
	string acc, pass,tk,mk,stt;
	gotoXY(55, 15);
	cin >> acc;
	gotoXY(55, 16);
	pass = nhapmk(pass);
	if ((acc.compare("admin") == 0 && pass.compare("admin") == 0)||
		(acc.compare("dbtien") == 0 && pass.compare("dbtien") == 0) 
		|| (acc.compare("htthanh") == 0 && pass.compare("htthanh") == 0)||
		(acc.compare("tploc") == 0 && pass.compare("tploc") == 0))
		return acc;
	ifstream fin;
	fin.open("account.txt");
	if (!fin.is_open())
	{
		cout << "Error" << endl;
		return "false";
	}
	int a = 0;
	while (fin.good())
	{
		getline(fin, stt, '\n');
		getline(fin, tk, '\n');
		getline(fin, mk, '\n');
		int x = acc.compare(tk), y = pass.compare(mk);
		if (x == 0 && y == 0)
		{
			if (stt.compare("1")==0)
			{
				clrscr();
				gotoXY(40, 10);
				cout << "MOI BAN DOI MAT KHAU KHI DANG NHAP LAN DAU";
				doimk(tk);
			}
			return tk;
		}
	}
	fin.close();
	return "false";
}
void hotroDoimk(string &mkcu, string &mkm1, string &mkm2)
{
	mkm1=mkm2=mkcu = "";
	gotoXY(40, 11);
	cout << "Moi ban nhap mat khau cu : ";
	mkcu = nhapmk(mkcu);
	gotoXY(40, 12);
	cout << "Moi ban nhap mat khau moi : ";
	mkm1 = nhapmk(mkm1);
	gotoXY(40, 13);
	cout << "Moi ban nhap mat khau moi lan thu 2 : ";
	mkm2 = nhapmk(mkm2);
}
bool doimk(string tkcu)
{
	string mkm1, mkm2,mkcu;
	string stt, tk,mk;
	account taikhoan[MAX];
	clrscr();
	hotroDoimk(mkcu, mkm1, mkm2);
	fstream fin;
	fin.open("account.txt");
	if (!fin.is_open())
	{
		cout << "Error" << endl;
		return false;
	}
	int a = 0;
	while (fin.good())
	{
		getline(fin, stt, '\n');
		getline(fin, tk, '\n');
		getline(fin, mk, '\n');
		if (tkcu.compare(tk) == 0)
		{
			while (1)
			{
				if ( mkcu.compare(mk)==0)
				{
					if (mkm1.compare(mkm2) == 0)
					{
						taikhoan[a].stt = "2";
						taikhoan[a].acc = tk;
						taikhoan[a].mk = mkm1;
						a++;
						break;
					}
					else
					{
						clrscr();
						gotoXY(50, 1);
						cout << "Ban da nhap sai. Vui long nhap lai";
						hotroDoimk(mkcu, mkm1, mkm2);
					}
				}
				else
				{
					clrscr();
					gotoXY(50, 1);
					cout << "Ban da nhap sai. Vui long nhap lai";
					hotroDoimk(mkcu, mkm1, mkm2);
				}
			}
			continue;
		}
		taikhoan[a].stt = stt;
		taikhoan[a].acc = tk;
		taikhoan[a].mk = mk;
		a++;
	}
	fin.close();
	ofstream fout;
	int i = 0;
	fout.open("account.txt");
	if (!fout.is_open())
	{
		cout << "Error" << endl;
		return false;
	}
	while (i<a-1)
	{
		fout << taikhoan[i].stt << endl;
		fout << taikhoan[i].acc << endl;
		fout << taikhoan[i].mk << endl;
		i++;
	}
	fout.close();
	return false;
}
void viewProfile(Data s)
{
	menuprofile();
	gotoXY(30, 5);
	cout << s.id;
	gotoXY(30, 6);
	cout << s.classSV;
	gotoXY(30, 7);
	cout << s.name;
	gotoXY(30, 8);
	cout << s.gender;
	gotoXY(30, 9);
	cout << s.BoD;
	gotoXY(30, 15);
	cout << "Press Enter to Continue.";
	char a = '.';
	while (a != 13)
	{
		a = _getch();
	}
}
void addSV()
{
	clrscr();
	SinhVien s;
	string classSV, midname;
	menuAdd();
	gotoXY(65, 8);
	cin >> s.id;
	gotoXY(65, 10);
	cin >> s.day;
	gotoXY(65, 11);
	cin >> s.month;
	gotoXY(65, 12);
	cin >> s.year;
	gotoXY(65, 13);
	cin >> s.lname;
	cin >> midname;
	gotoXY(65, 14);
	cin >> s.fname;
	gotoXY(65, 15);
	cin >> classSV;
	gotoXY(65, 16);
	cin >> s.gender;
	Data check = loaddata("data.txt", s.id, 0);
	if (check.id != s.id)
		return;
	fstream fout;
	fout.open("data.txt", ios::app);
	fout << s.id << ",";
	fout << classSV << ",";
	fout << s.lname << " "<<midname<<" " << s.fname << ",";
	fout << s.gender << ",";
	fout << s.day << "-" << s.month << "-" << s.year;
	fout.close();
	fout.open("account.txt", ios::app);
	fout  << "1" << endl;
	fout << s.id << endl;
	fout << s.day << s.month << s.year<<endl;
	fout.close();
}
void change()
{
	clrscr();
	Data s[MAX];
	string id, changeClass;
	gotoXY(40, 5);
	cout << "ID: ";
	cin >> id;
	gotoXY(40, 6);
	cout << "Class: ";
	cin >> changeClass;
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open())
	{
		cout << "Error" << endl;
		return;
	}
	int i = 0;
	while (fin.good())
	{
		getline(fin, s[i].id, ',');
		getline(fin, s[i].classSV, ',');
		getline(fin, s[i].name, ',');
		getline(fin, s[i].gender, ',');
		getline(fin, s[i].BoD, '\n');
		if (s[i].id == id) s[i].classSV = changeClass;
		i++;
	}
	ofstream fout;
	int t = 0;
	fout.open("data.txt");
	if (!fout.is_open())
	{
		cout << "Error" << endl;
		return;
	}
	while (t < i - 1)
	{
		fout << s[t].id << ",";
		fout << s[t].classSV << ",";
		fout << s[t].name << ",";
		fout << s[t].gender << ",";
		fout << s[t].BoD << endl;
		t++;
	}
	fout.close();
	return;
}
void listClass()
{
	clrscr();
	Data s[MAX];
	string classSV = "";
	string check[MAX];
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open())
	{
		cout << "Error" << endl;
		return;
	}
	int i = 0, a = 0;
	while (fin.good())
	{
		getline(fin, s[i].id, ',');
		getline(fin, s[i].classSV, ',');
		getline(fin, s[i].name, ',');
		getline(fin, s[i].gender, ',');
		getline(fin, s[i].BoD, '\n');
		if (s[i].classSV != classSV&&s[i].classSV!="")
		{
			check[a] = classSV = s[i].classSV;
			a++;
		}
		i++;
	}
	fin.close();
	int x;
	while (1)
	{
		int t = 0,j=10;
		while (t != a)
		{
			gotoXY(40, j);
			cout << t + 1 << "." << check[t];
			j++;
			t++;
		}
		gotoXY(40, j);
		cout << a + 1 << ". Exit.";
		gotoXY(40, j + 1);
		cout << "Choose : ";
		cin >> x;
		if (x <= a && x>0) svOfclass(check[x-1]);
		else if (x == (a + 1)) return;
		clrscr();
	}
}
void svOfclass(string classSv)
{
	clrscr();
	Data s[MAX];
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open())
	{
		cout << "Error" << endl;
		return;
	}
	int i = 0,j=0;
	while (fin.good())
	{
		getline(fin, s[i].id, ',');
		getline(fin, s[i].classSV, ',');
		getline(fin, s[i].name, ',');
		getline(fin, s[i].gender, ',');
		getline(fin, s[i].BoD, '\n');
		if (s[i].classSV == classSv)
		{
			gotoXY(0, j);
			cout << s[i].id;
			gotoXY(15, j);
			cout << s[i].name;
			j++;
		}
		i++;
	}
	fin.close();	
	gotoXY(30, 15);
	cout << "Press Enter to exit.";
	char a = '.';
	while (a != 13)
	{
		a = _getch();
	}
}
void removeacc(string tk)
{
	account acc[MAX];
	ifstream fin;
	fin.open("account.txt");
	if (!fin.is_open())
	{
		cout << "Error" << endl;
		return;
	}
	int a = 0;
	while (fin.good())
	{
		getline(fin, acc[a].stt, '\n');
		getline(fin, acc[a].acc, '\n');
		getline(fin, acc[a].mk, '\n');
		if (acc[a].acc == tk)
		{
			acc[a] = acc[a + 1];
			a--;
		}
		a++;
	}
	int t = 0;
	ofstream fout;
	fout.open("account.txt");
	if (!fout.is_open())
	{
		cout << "Error" << endl;
		return;
	}
	while (t < a - 1)
	{
		fout << acc[t].stt << "\n";
		fout << acc[t].acc << "\n";
		fout << acc[t].mk << "\n";
		t++;
	}
	fout.close();
}
void removeStudent1()
{
	clrscr();
	string id;
	gotoXY(50, 10);
	cout << "Enter ID of student to delete: ";
	cin >> id;
	Data s[MAX];
	gotoXY(40, 5);
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open())
	{
		cout << "Error" << endl;
		return;
	}
	int i = 0;
	while (fin.good())
	{
		getline(fin, s[i].id, ',');
		getline(fin, s[i].classSV, ',');
		getline(fin, s[i].name, ',');
		getline(fin, s[i].gender, ',');
		getline(fin, s[i].BoD, '\n');
		if (s[i].id == id)
		{
			s[i] = s[i + 1];
			i--;
		}
		i++;
	}
	ofstream fout;
	int t = 0;
	fout.open("data.txt");
	if (!fout.is_open())
	{
		cout << "Error" << endl;
		return;
	}
	while (t < i - 1)
	{
		fout << s[t].id << ",";
		fout << s[t].classSV << ",";
		fout << s[t].name << ",";
		fout << s[t].gender << ",";
		fout << s[t].BoD << endl;
		t++;
	}
	fout.close();
	removeacc(id);
	return;
}
void EditStudent1()
{
	clrscr();
	string id;
	gotoXY(50, 10);
	cout << "Enter ID of student to edit: ";
	cin >> id;
	Data s[MAX];
	gotoXY(40, 5);
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open())
	{
		cout << "Error" << endl;
		return;
	}
	int i = 0;
	string wantEdit;
	while (fin.good())
	{
		getline(fin, s[i].id, ',');
		getline(fin, s[i].classSV, ',');
		getline(fin, s[i].name, ',');
		getline(fin, s[i].gender, ',');
		getline(fin, s[i].BoD, '\n');
		if (s[i].id == id) {
			while (1)
			{
				viewProfile(s[i]);
				gotoXY(30, 14);
				cout << "Press 'exit' to exit ";
				gotoXY(30, 15);
				cout << "You want to edit(id/class/name/gender/BoD) : ";
				cin >> wantEdit;
				gotoXY(30, 16);
				if (wantEdit.compare("id") == 0)
				{
					cout << "Can't edit id (Please remove and add student)";
					Sleep(3000);
				}
				else if (wantEdit.compare("class") == 0)
				{
					cout << "Class : ";
					cin >> s[i].classSV;
				}
				else if (wantEdit.compare("name") == 0)
				{
					cout << "Can't edit name (Please remove and add student)";
					Sleep(3000);
				}
				else if (wantEdit.compare("gender") == 0)
				{
					cout << "Gender : ";
					cin >> s[i].gender;
				}
				else if (wantEdit.compare("BoD") == 0)
				{
					cout << "BoD(dd-mm-yyyy) : ";
					cin >> s[i].BoD;
				}
				else if (wantEdit.compare("exit") == 0)
				{
					break;
				}
				else
				{
					cout << "Error";
					Sleep(3000);
				}
			}
		}
		i++;
	}
	ofstream fout;
	int t = 0;
	fout.open("data.txt");
	if (!fout.is_open())
	{
		cout << "Error" << endl;
		return;
	}
	while (t < i - 1)
	{
		fout << s[t].id << ",";
		fout << s[t].classSV << ",";
		fout << s[t].name << ",";
		fout << s[t].gender << ",";
		fout << s[t].BoD << endl;
		t++;
	}
	fout.close();
	return;
}