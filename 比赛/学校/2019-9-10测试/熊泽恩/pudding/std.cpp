#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <set>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e6 + 10;

int n, m, ans;
int a[N], f[N];

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
	n = read(), m = read();
	for(rgi i = 1; i <= n ; ++i)
	{
		a[i] = read();
		ans += a[i] != a[i - 1];
		f[a[i]] = a[i];//记录属于的颜色 
		s[a[i]].insert(i);//记录每个颜色再哪些位置 
	}
	for(rgi i = 1; i <= m; ++i)
	{
		int op = read();
		if(op == 1)
		{
			int x = read(), y = read();
			if(x == y)	continue;
			if(s[f[x]].size() > s[f[y]].size())//合并，交换 
				swap(f[x], f[y]);
			//x ->into-> y
			for(set <int> :: iterator it = s[x].begin(); it != s[x].end(); ++it)
			{
				ans -= (a[*it - 1] == y);
				ans -= (a[*it + 1] == y);
				s[y].insert(*it); 
			}
			for(set <int> :: iterator it = s[x].begin(); it != s[x].end(); ++it)
				a[*it] = y;
			s[x].clear();
		}
		else if(op == 2)
			printf("%d\n", ans);
	}
	return 0;
}

