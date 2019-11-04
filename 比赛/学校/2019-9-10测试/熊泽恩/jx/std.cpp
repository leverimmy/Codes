#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	return 0;
}

