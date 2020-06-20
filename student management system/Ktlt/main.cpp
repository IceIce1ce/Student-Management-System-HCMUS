#include <iostream>
#include "menu.h"
#include "account.h"
#include "courses.h"
#include "honganh.h"
#include "lecturerMenu.h"
#include"StudentMenu.h"
#include <dos.h>
int main()
{
	/*SinhVien s[100];
	int i = loadaccount("18CLC1.csv", s);
	saveaccount("account.txt", s, i,1);
	savedata("data.txt", s, i, 1,"18CLC1");
	int a1 = loadaccount("18CLC2.csv", s);
	saveaccount("account.txt", s, a1,0); // load data from file csv
	savedata("data.txt", s, a1,0,"18CLC2");
	int b1 = loadaccount("18CLC3.csv", s);
	saveaccount("account.txt", s, b1, 0); // load data from file csv
	savedata("data.txt", s, b1, 0, "18CLC3");
	int c = loadaccount("18CLC4.csv", s);
	saveaccount("account.txt", s, c, 0); // load data from file csv
	savedata("data.txt", s, c, 0, "18CLC4");
	int d = loadaccount("18CLC5.csv", s);
	saveaccount("account.txt", s, d, 0); // load data from file csv
	savedata("data.txt", s, d, 0, "18CLC5");
	/*int z = loadaccount("lecture.csv",s);
	saveaccount("account_gv.txt", s, z, 0);
	savedata("data_gv.txt", s, z, 0, "Lecture");*////Lecture?
	system("color 0a");
	cout << "\n\n\n\t\t\t\tPlease wait while loading\n\n";
	char a = 177, b = 219;
	cout << "\t\t\t\t";
	for (int i = 0; i <= 15; i++)
	cout << a;
	cout << "\r";
	cout << "\t\t\t\t";
	for (int i = 0; i <= 15; i++)
	{
		cout << b;
		for (int j = 0; j <= 1e8; j++); 
	}
	cout << "\n\n\t\t\t\tCompleted";
	Sleep(100);
	cout << "!";
	Sleep(100);
	cout << "!";
	Sleep(100);
	cout << "!";
	clrscr();
	int z;
	system("color 06");
	cout << "\t\t\t\t\t\t\t\t____    __    ____  _______  __        ______   ______  .___  ___. _______ " << endl;
	cout << "\t\t\t\t\t\t\t\t\\   \\  /  \\  /   / |   ____||  |      /      | /  __  \\ |   \\/   ||   ____|" << endl;
	cout << "\t\t\t\t\t\t\t\t \\   \\/    \\/   /  |  |__   |  |     |  ,----'|  |  |  ||  \\  /  ||  |__   " << endl;
	cout << "\t\t\t\t\t\t\t\t  \\            /   |   __|  |  |     |  |     |  |  |  ||  |\\/|  ||   __|  " << endl;
	cout << "\t\t\t\t\t\t\t\t   \\    /\\    /    |  |____ |  `----.|  `----.|  `--'  ||  |  |  ||  |____ " << endl;
	cout << "\t\t\t\t\t\t\t\t    \\__/  \\__/     |_______||_______| \\______| \\______/ |__|  |__||_______|" << endl;
	cout << "" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t.___________.  ______  " << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t|           | /  __  \\ " << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t`---|  |----`|  |  |  |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t    |  |     |  |  |  |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t    |  |     |  `--'  |" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t    |__|      \\______/ " << endl;
	cout << "" << endl;
	cout << "\n\n\t\t     _______..___________. __    __     _______   _______ .__   __..___________.     .___  ___.     ___     .__   __.     ___       _______  _______ .___  ___. _______ .__   __..___________." << endl;
	cout << "\t\t    /       ||           ||  |  |  ||       \\ |   ____||  \\ |  ||           |     |   \\/   |    /   \\    |  \\ |  |    /   \\     /  _____||   ____||   \\/   ||   ____||  \\ |  ||           |" << endl;
	cout << "\t\t   |   (----``---|  |----`|  |  |  ||  .--.  ||  |__   |   \\|  |`---|  |----`     |  \\  /  |   /  ^  \\   |   \\|  |   /  ^  \\   |  |  __  |  |__   |  \\  /  ||  |__   |   \\|  |`---|  |----`" << endl;
	cout << "\t\t    \\   \\        |  |     |  |  |  ||  |  |  ||   __|  |  . `  |    |  |          |  |\\/|  |  /  /_\\  \\  |  . `  |  /  /_\\  \\  |  | |_ | |   __|  |  |\\/|  ||   __|  |  . `  |    |  |     " << endl;
	cout << "\t\t.----)   |       |  |     |  `--'  ||  '--'  ||  |____ |  |\\   |    |  |          |  |  |  | /  _____  \\ |  |\\   | /  _____  \\ |  |__| | |  |____ |  |  |  ||  |____ |  |\\   |    |  |     " << endl;
	cout << "\t\t|_______/        |__|      \\______/ |_______/ |_______||__| \\__|    |__|          |__|  |__|/__/     \\__\\|__| \\__|/__/     \\__\\ \\______| |_______||__|  |__||_______||__| \\__|    |__|     " << endl;
	cout << "\n\n\t\t\t\t\t\t\t\t     _______.____    ____     _______..___________. _______ .___  ___." << endl;
	cout << "\t\t\t\t\t\t\t\t    /       |\\   \\  /   /    /       ||           ||   ____||   \\/   |" << endl;
	cout << "\t\t\t\t\t\t\t\t   |   (----` \\   \\/   /    |   (----``---|  |----`|  |__   |  \\  /  |" << endl;
	cout << "\t\t\t\t\t\t\t\t    \\   \\      \\_    _/      \\   \\        |  |     |   __|  |  |\\/|  |" << endl;
	cout << "\t\t\t\t\t\t\t\t.----)   |       |  |    .----)   |       |  |     |  |____ |  |  |  |" << endl;
	cout << "\t\t\t\t\t\t\t\t|_______/        |__|    |_______/        |__|     |_______||__|  |__|" << endl;
	cout << "" << endl;
	cout << " \n\n\n\t\t\t\t\t\t\t\t\t\t     Press any key and 'ENTER' to continue: ";
	cin >> z;
	while (1)
	{
		clrscr();
		setConsoleSize(CONSOLE_WIDTH, CONSOLE_HEIGHT);
		menu();
		int kiemtra;
		int check; // if check = 0 you are teacher else you are student
		string sosanh = login();
		
		//StudentMenu() //menu Student t ghep vo
		//StaffMenuC() //menu Staff ghep
		//menuLecturer(); // menu Lect ghep
		if (sosanh.compare("admin") == 0)
		{
		check = 0;
		kiemtra = StaffMenuC();
		}
		else if (sosanh.compare("dbtien") == 0 || sosanh.compare("htthanh") == 0 || sosanh.compare("tploc") == 0)
		{
			check = 2;
			kiemtra = menuLecturer();
		}
		else if (sosanh.compare("false") != 0)
		{
			check = 1;
			kiemtra = StudentMenu();
		}
		else continue;

		while (check == 0)
		{
			if (kiemtra == 9) break; //logout
			else if (kiemtra == 4) listClass();
			else if (kiemtra == 5) addSV();
			else if (kiemtra == 6) change();
			else if (kiemtra == 7) removeStudent1();
			else if (kiemtra == 8) EditStudent1();
			kiemtra = StaffMenuC();
		}
		while (check == 1)
		{
			Data s = loaddata("data.txt",sosanh,1);
			if (kiemtra == 6) break;
			else if (kiemtra == 5) viewProfile(s);
			else if (kiemtra == 4) doimk(sosanh);
			kiemtra = StudentMenu();
		}
	}
	return 0;
}