#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1000 + 10;

int n, ans;
int a[N], b[N], f[4][4];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
//	freopen("sort.in", "r", stdin);
//	freopen("sort.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i)	a[i] = b[i] = read();
	sort(b + 1, b + n + 1);
	for(rgi i = 1; i <= n; ++i) f[a[i]][b[i]]++;
	ans = min(f[1][2], f[2][1]) + min(f[1][3], f[3][1]) + min(f[2][3], f[3][2]);
	printf("%d", ans + abs(f[1][2] - f[2][1]) * 2);
	return 0;
}
/*
9
2 2 1 3 3 3 2 3 1

5
5 8 1 2 10

5
1 3 2 1 3

6
1 2 3 2 3 1

*/
