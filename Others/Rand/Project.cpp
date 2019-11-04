#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <windows.h>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <deque>
#define ll long long
#define rgi register int
#define il inline

using namespace std;

const string Names[] = {"", "Deft", "Eric.J", "David",
						"Tobia", "Gillbert", "Lavender", "Sunny", "Nicole", "Cherryl", "Emmy", "Nina", "x",
						"Trent", "Stanlee", "Eric.S", "Echo", "Moris", "Silvia", "Yuzine", "Olivia", "Anika",
						"Via", "Quentin", "Angela", "Chris", "Alex", "Zack", "Harry", "Nilson", "Sam"
						};
const int Number = 30;

bool vis[Number + 1];
string e[5][10];

void Input()
{
	freopen("Data.txt", "r", stdin);
	for(rgi i = 1; i <= 4; ++i)
	{
		if(i == 1)
		{
			for(rgi j = 1; j <= 3; ++j)
				cin >> e[i][j];
		}
		else
		{
			for(rgi j = 1; j <= 9; ++j)
				cin >> e[i][j];
		}
	}
	freopen("CON", "r", stdin);
}

void Print_Map()
{
	for(rgi i = 1; i <= 4; ++i)
	{
		if(i == 1)
		{
			for(rgi j = 1; j <= 3; ++j)
				cout << "          ";
			for(rgi j = 1; j <= 3; ++j)
				cout << setw(10) << e[i][j];
		}
		else
		{
			for(rgi j = 1; j <= 9; ++j)
				cout << setw(10) << e[i][j];
		}
		cout << endl;
	}
}

void Random()
{
	vector <string> vec;
	for(int i = 1; i <= Number; ++i)	vec.push_back(Names[i]);
	random_shuffle(vec.begin(), vec.end());
	for(rgi i = 1; i <= 4; ++i)
	{
		if(i == 1)
		{
			for(rgi j = 1; j <= 3; ++j)
			{
				e[i][j] = vec.back();
				vec.pop_back();
			}
		}
		else
		{
			for(rgi j = 1; j <= 9; ++j)
			{
				e[i][j] = vec.back();
				vec.pop_back();
			}
		}
	}
}

void Change()
{
	string tmp[5][5];
	for(rgi i = 2; i <= 4; ++i)
		for(rgi j = 1; j <= 3; ++j)
			tmp[i][j] = e[i][j + 6];
	for(rgi i = 2; i <= 4; ++i)
		for(rgi j = 9; j >= 1; --j)
		{
			if(j >= 4)
				e[i][j] = e[i][j - 3];
			else
				e[i][j] = tmp[i][j];
		}
}

void Output()
{
	freopen("Data.txt", "w", stdout);
	Print_Map();
	freopen("CON", "w", stdout);
}

void Modify()
{
	while(1)
	{
		puts("Please input operator:");
		puts("1 : Random shuffle");
		puts("2 : Change from left to right");
		puts("3 : Print current map");
		puts("4 : Exit");
		puts("NOTES : \" x \" means NOBODY");
		int op; scanf("%d", &op);
		if(op == 1)	Random();
		if(op == 2) Change();
		if(op == 3) Print_Map();
		if(op == 4) break;
		system("pause");
		system("cls");
	}
}

int main()
{
	srand(time(0)); 
	Input();
	Modify();
	Output();
	return 0;
}

