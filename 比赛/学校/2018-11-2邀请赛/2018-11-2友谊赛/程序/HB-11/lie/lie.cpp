#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <map>
#define NO 50005
#define INF 0x3f3f3f3f
#define p pair<int, int>
#define mp(x, y) make_pair(x, y)
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
map<p, int> m;
//variable

void init()
{
	freopen("lie.in", "r", stdin);
	freopen("lie.out", "w", stdout);
	n = read();
}
//functions

int main()
{
	init();
	for(int i = 1; i <= n; i++)
	{
		int x = read(), y = read();
		if(x + y > n - 1)
			ans++;
		else if(m[mp(x, y)] == n - x - y)
			ans++;
		else
			m[mp(x, y)]++;
	}
	cout<<ans<<endl;
	return 0;
}
//main
