#include <cstdio>
#include <cstring>
#include <iostream>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register ll

using namespace std;

const  N = 100000 + 10;

ll n, m, ans;
ll atk[N], def[N], x[N];

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
//	freopen("testdata.in", "r", stdin);
//	freopen("testdata.out", "w", stdout);
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
	{
		char op[5];
		ll val;
		scanf("%s %lld", op, &val);
		if(op[0] == 'A')
			atk[++atk[0]] = val;
		else if(op[0] == 'D')
			def[++def[0]] = val;
	}
	for(rgi i = 1; i <= m; ++i)
		x[i] = read();
	sort(atk + 1, atk + atk[0] + 1, greater <ll> ());
	sort(def + 1, def + def[0] + 1, greater <ll> ());
	sort(x + 1, x + m + 1, less <ll> ());
	for(rgi i = m; i >= 1; --i)
		if(atk[0] != 0 && x[i] >= atk[atk[0]])
		{
			ans += x[i] - atk[atk[0]];
			atk[0]--;
			m--;
			continue;
		}
	sort(x + 1, x + m + 1, greater <ll> ());
	for(rgi i = m; i >= 1; --i)
		if(def[0] != 0 && x[i] > def[def[0]])
		{
			def[0]--;
			m--;
		}
	if(atk[0] == 0 && def[0] == 0)
		for(rgi i = 1; i <= m; ++i)
			ans += x[i];
	printf("%lld", ans);
	return 0;
}
/*
HACK:
4 6
DEF 100
DEF 100
ATK 1000
ATK 1001
1002
1002
1001
1001
1000
101
*/
