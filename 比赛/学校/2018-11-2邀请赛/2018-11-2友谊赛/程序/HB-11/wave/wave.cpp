#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#define NO 50005
#define INF 0x3f3f3f3f
#define p pair<int, pair<int, int> >
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
typedef long long ll;
//bu Oliver
using namespace std;
ll read()
{
	char ch = ' ', last;
	ll ans = 0;
	while(ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while(ch >= '0' && ch <= '9')
		ans *= 10, ans += ch - '0', ch = getchar();
	if(last == '-')
		return -ans;
	return ans;
}
//head

int n, ans;
p x[NO], y[NO];
//variable

void init()
{
	freopen("wave.in", "r", stdin);
	freopen("wave.out", "w", stdout);
	n = read();
}
//functions

int main()
{
	init();
	for(int i = 1; i <= n; i++)
	{
		int a = read(), b = read();
		ans += a + b;
		x[i].fi = b, x[i].se.fi = 0, x[i].se.se = a, y[i].fi = a, y[i].se.fi = 0, y[i].se.se = b;
		for(int j = 1; j < i; j++)
		{
			if(x[j].se.fi < a && x[j].fi < b)
				ans -= min(a, x[j].se.se) - x[j].se.fi, x[j].se.fi = min(a, x[j].se.se);
			if(y[j].se.fi < b && y[j].fi < a)
				ans -= min(b, y[j].se.se) - y[j].se.fi, y[j].se.fi = min(b, y[j].se.se);
		}
		//cout<<i<<' '<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
//main
