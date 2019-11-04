#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <iostream>
#include <string>
#define il inline
#define rgi register int
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1000 + 10;

int n, len0;
string name, info[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	string str = "1991-04-19 18:08:01 1 F%Ro$RC1v5w(1";
	cout << str.find("1 ");
	return 0;
}
