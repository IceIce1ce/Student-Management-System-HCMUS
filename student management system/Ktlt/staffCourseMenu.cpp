#include"honganh.h"
#include"lecturerMenu.h"
int StaffMenuC()
{
	COURSE s1[MAX], s2[MAX], s3[MAX], s4[MAX], s5[MAX], s6[MAX];
	STUDENT st1[MAX], st2[MAX], st3[MAX], st4[MAX], st5[MAX], st6[MAX];
	ATTENDANCE at1[MAX], at2[MAX], at3[MAX], at4[MAX], at5[MAX], at6[MAX];
	Course1 s1_1[100], s2_2[100], s3_3[100], s4_4[100], s5_5[100];
	scores sc[MAX];
	LECTURE lt[MAX];
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
	int lecture, lec;
	lecture = loadLecture("lecture.csv", lt);
	saveLecture("lecture.txt", lt, lecture);
	int clc1_1, clc2_2, clc3_3, clc4_4, clc5_5;
	clc1_1 = loadCourse1("tkb1.csv", s1_1);
	saveCourse1("tkb1.txt", s1_1, clc1_1);
	clc2_2 = loadCourse1("tkb2.csv", s2_2);
	saveCourse1("tkb2.txt", s2_2, clc2_2);
	clc3_3 = loadCourse1("tkb3.csv", s3_3);
	saveCourse1("tkb3.txt", s3_3, clc3_3);
	clc4_4 = loadCourse1("tkb4.csv", s4_4);
	saveCourse1("tkb4.txt", s4_4, clc4_4);
	clc5_5 = loadCourse1("tkb5.csv", s5_5);
	saveCourse1("tkb5.txt", s5_5, clc5_5);
	/*int choose;
	cout << "1. All courses of the current semester: " << endl;
	cout << "2. Student of the course: " << endl;
	cout << "3. Scoreboard of course: " << endl;
	cout << "4. Attendance list of course: " << endl;
	cout << "5. View list of lectures: " << endl;
	cout << "6. Add new lecture: " << endl;
	cout <<"7. Delete lecture: " << endl;
	cout << "8. Add new student: " << endl;
	cout << "9. Delete student: " << endl;
	cout << "10. Add course: " << endl;
	cout << "11. Edit course: " << endl;
	cout << "12.Delete course: " << endl;
	cout << "13. Exit: " << endl;
	cout << "Enter your choice: ";
	cin >> choose;
	switch (choose)
	{
	case 1:
		Course(7, s1, s2, s3, s4, s5, s6);
		break;
	case 2:
		Studentofcourse(7, st1, st2, st3, st4, st5, st6);
		break;
	case 3:
		ScoreBoard(7, st1, st2, st3, st4, st5, st6);
		break;
	case 4:
		Attendance(7, at1, at2, at3, at4, at5, at6);
		break;
	case 5:
		system("cls");
		viewAllLecture("lecture.txt", lt, lecture);
		break;
	case 6:
		system("cls");
		addLec(lt);
		break;
	case 7:
		system("cls");
		deleteLec(lt);
		break;
	case 8:
		system("cls");
		addSt(st1, st2, st3, st4, st5, st6);
		break;
	case 9:
		system("cls");
		delSt(st1, st2, st3, st4, st5, st6);
		break;
	case 10:
		system("cls");
		addCo1(s1_1, s2_2, s3_3, s4_4, s5_5); 
		break;
	case 11:
		system("cls");
		ediCo1(s1_1, s2_2, s3_3, s4_4, s5_5); 
		break;
	case 12:
		system("cls");
		delCo1(s1_1, s2_2, s3_3, s4_4, s5_5); 
		break;
	case 13:
		exit(0);
		break;
	default: cout << "wrong input, re-try again" << endl;
	}
	system("pause");
	return 0;*/
	setConsoleSize(CONSOLE_WIDTH-15, CONSOLE_HEIGHT-10);
	string 	*splashData = NULL, *Menu = NULL;
	splashData = new string[CONSOLE_HEIGHT];
	Menu = new string[CONSOLE_HEIGHT];
	int splashLines = 0, MenuLines = 0, menuCurrent = 0;
	int attt = loadAttendance("Checkin.csv", at1); // load thu no doc dc "id,..." ko
	int scr = loadScore("ScoreBoard.csv", sc);
	StaffCMenu(Menu, &MenuLines);
	while (true) 
	{
		showStaffCMenu(splashData, &splashLines, Menu, &MenuLines, &menuCurrent);
		switch (menuCurrent) 
		{
		case 0:
			Course(7, s1, s2, s3, s4, s5, s6);
			break;
		case 1:
			Studentofcourse(7, st1, st2, st3, st4, st5, st6);
			break;
		case 2:
			ScoreBoard(7, st1, st2, st3, st4, st5, st6);
			break;
		case 3:
			Attendance(7, at1, at2, at3, at4, at5, at6);
			break;
		case 4:
			system("cls");
			viewAllLecture("lecture.txt", lt, lecture);
			break;
		case 5:
			system("cls");
			addLec(lt);
			break;
		case 6:
			system("cls");
			deleteLec(lt);
			break;
		case 7:
			system("cls");
			addSt(st1, st2, st3, st4, st5, st6);
			break;
		case 8:
			system("cls");
			delSt(st1, st2, st3, st4, st5, st6);
			break;
		case 9:
			system("cls");
			addCo1(s1_1, s2_2, s3_3, s4_4, s5_5);
			break;
		case 10:
			system("cls");
			ediCo1(s1_1, s2_2, s3_3, s4_4, s5_5);
			break;
		case 11:
			system("cls");
			delCo1(s1_1, s2_2, s3_3, s4_4, s5_5);
			break;
		case 12: //26
			system("cls");
			Attendance(7,at1, at2, at3, at4, at5, at6);
			break;
		case 13:
			system("cls");
			InputnExportScore(sc, scr);
			break;
		case 14:
			return 4;
		case 15:
			return 5;
		case 16:
			return 6;
		case 17:
			return 7;
		case 18:
			return 8;
		case 19:
			return 9;
		//case 14:
		//	system("cls"); //26
		//	Attendance(7, at1, at2, at3, at4, at5, at6);
		//	break;
		//case 15:  //27
		//	system("cls");
		//	//editAttendance(at1, attt);
		//	break;
		//lecturer
		//case 16: //28
		//	system("cls");
		//	Course(7, s1, s2, s3, s4, s5, s6);
		//	break;
		//case 17: //29
		//	system("cls");  ///29
		//	Studentofcourse(st1, st2, st3, st4, st5, st6);
		//	break;
		//case 18: //30
		//	system("cls"); ///30
		//	Attendance(at1, at2, at3, at4, at5, at6);
		//	break;
		//case 19: //31
		//	system("cls");
		//	int attt = loadAttendance("Checkin.csv", at1); // load thu no doc dc "id,..." ko
		//	editAttendance(at1, attt);
		//	break;
		}
	}
	system("pause>nul");
	return 0;
}