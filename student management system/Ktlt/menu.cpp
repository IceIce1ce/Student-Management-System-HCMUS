#include "menu.h"
#include "account.h"
void menu()
{
	TextColor(2);
	for (int j = 1; j <= 15; j++)
	{
		gotoXY(25, j + 8);
		if (j == 1)
			for (int i = 0; i < 60; i++)
				printf("%c", 220);
		else if (j == 15)
			for (int i = 0; i < 60; i++)
				printf("%c", 223);
		else
		{
			printf("%c", 178);
			gotoXY(84, j + 8);
			printf("%c", 178);
		}
	}
	TextColor(2);
	for (int j = 5; j <= 10; j++)
	{
		gotoXY(40, j + 8);
		if (j == 5)
			for (int i = 0; i <= 30; i++)
				printf("%c", 220);
		else if (j == 10)
			for (int i = 0; i <= 30; i++)
				printf("%c", 223);
		else
		{
			printf("%c", 178);
			gotoXY(70, j + 8);
			printf("%c", 178);
		}
	}
	gotoXY(42,15);
	TextColor(5);
	printf("Username : ");
	gotoXY(42, 16);
	printf("Password : ");
}
int menuStudent()
{
	clrscr();
	TextColor(2);
	for (int j = 1; j <= 15; j++)
	{
		gotoXY(25, j + 8);
		if (j == 1)
			for (int i = 0; i < 60; i++)
				printf("%c", 220);
		else if (j == 15)
			for (int i = 0; i < 60; i++)
				printf("%c", 223);
		else
		{
			printf("%c", 178);
			gotoXY(84, j + 8);
			printf("%c", 178);
		}
	}
	int x;
	gotoXY(40, 14);
	printf("1. Profile Info");
	gotoXY(40, 15);
	printf("2. Change Password");
	gotoXY(40, 16);
	printf("3. Log Out");
	gotoXY(40, 18);
	printf("Choose : ");
	cin >> x;
	if (x >= 1 && x <= 3)
	{
		clrscr();
		return x;
	}


}
void menuprofile()
{
	clrscr();
	TextColor(2);
	gotoXY(20, 5);
	printf("ID : ");
	gotoXY(20, 6);
	printf("Class : ");
	gotoXY(20, 7);
	printf("Name : ");
	gotoXY(20, 8);
	printf("Gender : ");
	gotoXY(20, 9);
	printf("Birthday : ");
}
int menuStaff()
{
	int x;
	clrscr();
	TextColor(2);
	for (int j = 1; j <= 15; j++)
	{
		gotoXY(25, j + 8);
		if (j == 1)
			for (int i = 0; i < 60; i++)
				printf("%c", 220);
		else if (j == 15)
			for (int i = 0; i < 60; i++)
				printf("%c", 223);
		else
		{
			printf("%c", 178);
			gotoXY(84, j + 8);
			printf("%c", 178);
		}
	}
	gotoXY(50, 12);
	cout << "1.List Class";
	gotoXY(50, 13);
	cout << "2. Change";
	gotoXY(50, 14);
	cout << "3. Add";
	gotoXY(50, 15);
	cout << "4. Remove";
	gotoXY(50, 16);
	cout << "5. Edit";
	gotoXY(50, 17);
	cout <<"6. Log Out";
	gotoXY(50, 18);
	cout << "Choose : ";
	cin >> x;
	return x;
}
void menuAdd()
{
	TextColor(2);
	clrscr();
	gotoXY(50, 8);
	cout << "ID : ";
	gotoXY(50, 9);
	cout << "BoD : ";
	gotoXY(55, 10);
	cout << "Day : ";
	gotoXY(55, 11);
	cout << "Month : ";
	gotoXY(55, 12);
	cout << "Year : ";
	gotoXY(50, 13);
	cout << "Last Name : ";
	gotoXY(50, 14);
	cout << "First Name : ";
	gotoXY(50, 15);
	cout << "Class : ";
	gotoXY(50, 16);
	cout << "Gender : ";
}