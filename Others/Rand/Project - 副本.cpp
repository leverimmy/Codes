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

const int Number = 18;

bool vis[Number + 1];
std::string e[10][10];
std::string Names[Number + 1];

void Input() {
	int tot = 0;
	freopen("Data.txt", "r", stdin);
	for(rgi i = 1; i <= 5; ++i) {
		if(i == 1) {
			for(rgi j = 1; j <= 2; ++j)
				std::cin >> e[i][j], Names[++tot] = e[i][j];
		}
		else {
			for(rgi j = 1; j <= 4; ++j)
				std::cin >> e[i][j], Names[++tot] = e[i][j];
		}
	}
	freopen("CON", "r", stdin);
}

void Print_Map() {
	for(rgi i = 1; i <= 5; ++i) {
		if(i == 1) {
			std::cout << "          ";
			for(rgi j = 1; j <= 2; ++j)
				std::cout << std::setw(10) << e[i][j];
			std::cout << "          ";
		}
		else {
			for(rgi j = 1; j <= 4; ++j)
				std::cout << std::setw(10) << e[i][j];
		}
		std::cout << std::endl;
	}
}

void Random() {
	std::vector <std::string> vec;
	for(int i = 1; i <= Number; ++i)	vec.push_back(Names[i]);
	random_shuffle(vec.begin(), vec.end());
	for(rgi i = 1; i <= 5; ++i) {
		if(i == 1) {
			for(rgi j = 1; j <= 2; ++j) {
				e[i][j] = vec.back();
				vec.pop_back();
			}
		}
		else {
			for(rgi j = 1; j <= 4; ++j) {
				e[i][j] = vec.back();
				vec.pop_back();
			}
		}
	}
}

void Change() {
//	std::string tmp[5][5];
//	for(rgi i = 2; i <= 4; ++i)
//		for(rgi j = 1; j <= 3; ++j)
//			tmp[i][j] = e[i][j + 6];
//	for(rgi i = 2; i <= 4; ++i)
//		for(rgi j = 9; j >= 1; --j) {
//			if(j >= 4)
//				e[i][j] = e[i][j - 3];
//			else
//				e[i][j] = tmp[i][j];
//		}
	for(rgi i = 1; i <= 5; ++i) {
		if(i == 1) std::swap(e[i][1], e[i][2]);
		else {
			for(rgi j = 1; j <= 2; ++j)
				std::swap(e[i][j], e[i][j + 2]);
		}
	}
}

void Output()
{
	freopen("Data.txt", "w", stdout);
	Print_Map();
	freopen("CON", "w", stdout);
}

void Modify() {
	while(1) {
		puts("Please input operator:");
		puts("1 : Random shuffle");
		puts("2 : Swap the left and the right");
		puts("3 : Print current map");
		puts("4 : Exit");
//		puts("NOTES : \" x \" means NOBODY");
		int op; scanf("%d", &op);
		if(op == 1)	Random();
		else if(op == 2) Change();
		else if(op == 3) Print_Map();
		else if(op == 4) break;
		else puts("Wrong Input!");
		system("pause");
		system("cls");
	}
}

int main() {
	srand(time(0));
	Input();
	Modify();
	Output();
	return 0;
}

