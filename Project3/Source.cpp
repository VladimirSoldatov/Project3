#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <winbase.h>
#include<string>

using namespace std;

WIN32_FIND_DATA wfd;
HANDLE hFile;

HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO SCRN_INFO;

COORD pos;

void show(LPCWSTR z);
void clr();
void newf(LPCWSTR z);
LPCWSTR  folder = L"C:/*.*";
char text[30];
char fil[30];
char temp[30];
int i1 = 0;
int q = 1;
int main()
{
	int i = 0;
	cout << "\n\n";
	show(folder);
	show(folder);
	int x;
	while (q) {

		cin >> i;
		if (i < 7)
		{
			cin >> temp;
			folder = (LPCWSTR)temp;

		}
		switch (i)
		{
		case 1:show(folder); break;
		case 2:newf(folder); break;

		case 3:RemoveDirectory(folder); clr(); break;
		case 4:FILE * fp; fp = fopen((const char *)folder, "w"); fclose(fp); clr(); break;
		case 5:FILE * fp1; fp1 = fopen((const char *)folder, "r");
			x = fscanf(fp1, "%s", &fil);
			clr();
			pos.X = 5;
			pos.Y = 10;
			SetConsoleCursorPosition(hOutput, pos);
			SetConsoleTextAttribute(hOutput, 30);
			cout << fil;
			pos.X = 46;
			pos.Y = 23;
			fclose(fp1);
			fp1 = fopen((const char*)folder, "w");
			cin >> text;
			fprintf(fp1, "%s", fil);
			fprintf(fp1, "%s", text);
			SetConsoleCursorPosition(hOutput, pos);
			fclose(fp1);
			break;
		case 6:DeleteFile(folder); clr(); break;
		case 7:q = 0; break;
		}
	}


}


void show(LPCWSTR z)
{
	int z1 = 0;
	clr();
	//SetConsoleTextAttribute(hOutput, 30);
	hFile = FindFirstFile(folder, &wfd);
	wcout << wfd.cFileName << endl;
	int i = 0;
	for (i = 0; i < 17; i = i + 1)
	{
		z1 = FindNextFile(hFile, &wfd);
		pos.X = 3;
		pos.Y = (i + 3);
		//SetConsoleCursorPosition(hOutput, pos);
		if (z1 == 0) goto m3;
		wcout << wfd.cFileName << endl;
	m3:
		;
	}
	pos.X = 46;
	pos.Y = 23;
	SetConsoleCursorPosition(hOutput, pos);
	cout << " ";
	pos.X = 46;
	pos.Y = 23;
	SetConsoleCursorPosition(hOutput, pos);
}

void clr()
{
	system("cls");
	
	//SetConsoleTextAttribute(hOutput, 2);
	int j;
	cout << "____________________________ ___________________________________ _________________";
	//SetConsoleTextAttribute(hOutput, 30);
	for (j = 0; j < 19; j = j + 1)
		cout << " ";
	cout << "\n";
	//SetConsoleTextAttribute(hOutput, 3);
	//cout << "____________________________ ___________________________________ _________________";
	cout << "[1:show fldr][2:new fldr] [3el fldr][4:new doc] [5:ed doc][6el doc] [7:exit]\n";
	//SetConsoleTextAttribute(hOutput, 15);
	cout << "<enter command (command and way to a file)> >\n";
	wcout << "\n" << folder << endl;
}

void newf(LPCWSTR z)
{
	CreateDirectory(folder, 0);
	clr();
}