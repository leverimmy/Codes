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

set <int> s[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
//	freopen("pudding.in", "r", stdin);
//	freopen("pudding.out", "w", stdout);
	n = read(), m = read();
	//input
	
	for(rgi i = 1; i <= n; ++i)
	{
		a[i] = read();
		num[++tot] = a[i];
	}
	sort(num + 1, num + tot + 1);
	tot = unique(num + 1, num + tot + 1) - num;
	for(rgi i = 1; i <= n; ++i)
		a[i] = lower_bound(num + 1, num + tot + 1, a[i]) - num;
	//discrete
	
	for(rgi i = 1; i <= n; ++i)
		s[a[i]].insert(i);
	
	for(rgi i = 1; i <= m; ++i)
	{
		int op = read();
		if(op == 1)
		{
			int x = read(), y = read();
			x = lower_bound(num + 1, num + tot + 1, x) - num;
			y = lower_bound(num + 1, num + tot + 1, y) - num;
			if(s[x].size() >= s[y].size())
			{
				for(set <int> :: iterator it = s[y].begin(); it != s[y].end(); ++it)
					s[x].insert(*it);
				s[y].clear();
			}
			else
			{
				for(set <int> :: iterator it = s[x].begin(); it != s[x].end(); ++it)
					s[y].insert(*it);
				s[x].clear();
			}
		}
		else if(op == 2)
		{
			int cnt = 0;
			for(rgi j = 1; j <= tot; ++j)
			{
				for(set <int> :: iterator it = s[j].begin() + 1; it != s[j].end(); ++it)
				{
					if(*it != *(it - 1) + 1)
						cnt++;
				}
			}
			printf("%d\n", cnt + 1);
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

