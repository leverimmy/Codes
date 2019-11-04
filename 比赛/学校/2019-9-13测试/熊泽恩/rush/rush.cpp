#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <cstring>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;

int n, m, empty_hang, empty_lie;
int hang[N], lie[N]; 

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
//	freopen("rush.in", "r", stdin);
//	freopen("rush.out", "w", stdout);
	n = read(), m = read();
	for(rgi i = 1; i <= m; ++i)
	{
		int x = read(), y = read();
		hang[x] = 1;
		lie[y] = 1;
	}
	for(rgi i = 1; i <= n; ++i)
	{
		empty_hang += hang[i];
		empty_lie += lie[i];
	}
	if(hang[(n + 1) / 2] && lie[(n + 1) / 2])
		printf("%d", n - empty_hang + n - empty_lie);
	else
		printf("%d", n - empty_hang + n - empty_lie - 1);
	return 0;
}

