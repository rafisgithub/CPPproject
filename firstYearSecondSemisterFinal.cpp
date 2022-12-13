#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include  <bits/stdc++.h>
using namespace std;
class EverytingAboutSemisterFinalExam{
	public:
		string name;
		string roll;
		int subject;
	void SetColor(int ForgC)
{
     WORD wColor;
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

void ClearColor(){
    SetColor(15);
}

void ClearConsoleToColors(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD coord = {0, 0};
     DWORD count;
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
	    FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
        SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}
void SetColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}
void Print()
{
   printf("\t\tWelcome to exam preparation system made by Rafi ahmed.(double press any key to continue)\n");
  getch();
   system("cls");
   if(getch()==27)
   exit(0);
}
void checkExamRoutine(){
	system("color A0");
	cout<<"Enter your name:\n";
	cin.ignore();
	getline(cin, name);
	cout<<"Enter your roll:\n";
	cin.ignore();
	getline(cin,roll);
	cout<<"\n\n";
	cout<<"\t\t\t"<<name<<" Welcome to Semister final exam routine.\n\n";
	cout<<"\tSubject\t\t\t Exam Date \t\t\t Exam time \t\t\t Exam type\n\n";
	cout<<"\tEnglish\t\t\t 12/19/2022 \t\t\t 11:30-1:30\t\t\t theory.\n";
	cout<<"\tMath   \t\t\t 12/21/2022 \t\t\t 11:30-1:30\t\t\t theory.\n";
	cout<<"\tOOPS   \t\t\t 12/24/2022 \t\t\t 11:30-1:30\t\t\t theory.\n";
	cout<<"\tPhysics\t\t\t 12/26/2022 \t\t\t 11:30-1:30\t\t\t theory.\n";
}
 void english(){
 	cout<<"Enter your name:\n";
	cin.ignore();
	getline(cin, name);
	cout<<"Enter your roll:\n";
	cin.ignore();
	getline(cin,roll);
	cout<<"Welcome to "<<name<<endl;
	cout<<"I hope you will get A+.\n";
	cout<<"In English exam you will find 5 questions.\n";
	cout<<"1)write a paragraph.\t marks ->10\n";
	cout<<"2)write a cv.\t marks ->10\n";
	cout<<"3)write a cover letter.\t marks ->10\n";
	cout<<"4)write a Notice or Agenda\t marks ->10\n";
	cout<<"5)write a cover Email or minutes.\t marks ->10\n";
	cout<<"\n you have answer only four questions.\n";

}
void math(){
	cout<<"Enter your name:\n";
	cin.ignore();
	getline(cin, name);
	cout<<"Enter your roll:\n";
	cin.ignore();
	getline(cin,roll);
	system("color 0A");
	cout<<"I hope you will get A+.\n";
	cout<<"Topics Vector,General discussion of vector,and Line integral.\n";
	cout<<"\nFrom vector.\n 1)Curl\n 2)Divergence\n 3)Gradient\n";
	cout<<"From General discussion of vectory.\n 1)The scalar triple product.\n 2)The vector triple product.\n";
	cout<<"from line integral \n 1)calculate/evaluate a triangle or square or rectangle a  close integral equation.\n";
}
void oop(){
	cout<<"Enter your name:\n";
	cin.ignore();
	getline(cin, name);
	cout<<"Enter your roll:\n";
	cin.ignore();
	getline(cin,roll);
	system("color 02");
	cout<<"I hope yo1u will get A+.\n";
	cout<<"Topics.\n";
	cout<<"1) What is oop?\n2) Polymorphism \n3) Encapsulation \n4) Abstruction \n5)And the most important for exam is Inheritance and it's classification.\n";
	
}
void physic(){
	cout<<"Enter your name:\n";
	cin.ignore();
	getline(cin, name);
	cout<<"Enter your roll:\n";
	cin.ignore();
	getline(cin,roll);
	system("color B5");
	cout<<"Topics:\n";
	cout<<"1) Culomb's law.\n";
	cout<<"2) Electric intensity and potential.\n";
	cout<<"3)Gauss's law.\n 4) ellectric diple \n5) Register \n6) Capacitor and Parallel capaciotor of capacitance.\n";
	cout<<"7) Biot-Savart law\n8) Apmperes law \n9) capacitor and capacitance math exercise \n10) electric field and electric field intensity exercise.\n";
	cout<<"11)Magnetic Metarials.\n";
}
};

int main(){
	EverytingAboutSemisterFinalExam obj;
	obj.SetColorAndBackground(15,1);
    obj.ClearConsoleToColors(15, 1);
    obj.Print();
	int choice;
	cout<<"Please choose an option:\n";
	cout<<"1)see exam routine.\n";
	cout<<"2)Check exam result in advance.\n";
	cout<<"Enter which subject questions wanna see?\n";
	cout<<"(121 for English) (122 for Math )(123 for OPP) (124 Physics).\n";
	cout<<"3)exit.\n";
	cout<<"Enter 1 or 2 or 121 or 122 or 123 or 124.\n";
	cin>>choice;
	switch(choice){
		case 1:
			obj.checkExamRoutine();
			break;
		case 121:
			obj.english();
			break;
		case 122:
		     obj.math();
		     break;
	    case 123:
	    	obj.oop();
	    	break;
	    case 124:
	    	obj.physic();
	    	break;
	    default:
	    	cout<<"Are you blind?\n";
	}
	
	getch();
	return 0;
}
