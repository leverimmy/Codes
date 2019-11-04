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
int a[N];

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
	for(rgi i = 1; i <= n; ++i)	a[i] = read();
	for(rgi i = 1; i <= n; ++i)
	{
		int cur = a[i], pos = i;
		for(rgi j = i + 1; j <= n; ++j)
			if(a[j] < cur)
			{
				cur = a[j];
				pos = j;
			}
		if(pos != i) ans++, swap(a[i], a[pos]);
	}
	printf("%d", ans);
	return 0;
}
/*
9
2 2 1 3 3 3 2 3 1

5
5 8 1 2 10

5
1 3 2 1 3

*/
