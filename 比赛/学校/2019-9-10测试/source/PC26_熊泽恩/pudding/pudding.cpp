#include <cstdio>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;

int n, m, tot;
int a[N], num[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	freopen("pudding.in", "r", stdin);
	freopen("pudding.out", "w", stdout);
	n = read(), m = read();
	//input
	
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
		
	for(rgi i = 1; i <= m; ++i)
	{
		int op = read();
		if(op == 1)
		{
			int x = read(), y = read();
			for(rgi j = 1; j <= n; ++j)
				if(a[j] == x)
					a[j] = y;
		}
		else if(op == 2)
		{
			int cnt = 0;
			for(rgi j = 1; j <= n; ++j)
			{
				if(a[j] != a[j - 1])
					cnt++;
			}
			printf("%d\n", cnt);
			/*cout << " hello" << endl;
			for(rgi j = 1; j <= n; ++j)
				cout << a[j] << " ";
			cout << endl;*/
		}
	}
	return 0;
}
/*
4 3
1 2 2 1
2
1 2 1
2

*/

