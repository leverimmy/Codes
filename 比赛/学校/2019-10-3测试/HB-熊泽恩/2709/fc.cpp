#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	int st = clock();
	system("2709.exe");
	int ed = clock();
	if(system("fc /w 2709.out 2709.ans"))
		printf("WA, time = %dms", ed - st);
	else
		printf("AC, time = %dms", ed - st);
	return 0;
}

