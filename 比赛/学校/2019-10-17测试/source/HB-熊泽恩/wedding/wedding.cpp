#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int N = 2e5 + 50;

ll n, g, r, q;
ll l[N], t[N], f[N];

map<ll, ll> to[N];

int main() {
//	freopen("wedding.in", "r", stdin);
//	freopen("wedding.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &g, &r);
	for(rgi i = 1; i <= n + 1; ++i)	scanf("%lld", &l[i]);
	scanf("%lld", &q);
	for(rgi i = 1; i <= q; ++i)	scanf("%lld", &t[i]);
	for(rgi i = 1; i <= q; ++i) {
		int flag = 1; ll ans = 0;
		
		/*if(i == 12)	{
			puts("here:");
		}*/
		
		f[0] = t[i];
		for(rgi j = 1; j <= n && flag; ++j) {
			f[j] = ((f[j - 1] + l[j]) % (g + r) < g) ? (f[j - 1] + l[j]) : (f[j - 1] + l[j] + g + r - (f[j - 1] + l[j]) % (g + r));
			ll cur = to[j][f[j]];
			if(cur)	{
				flag = 0;
				ans = to[j][f[j]];
			}
			/*if(j == 2 && f[j] == 2284342842LL) {
				puts("here: ");
			}*/
		}
		
		if(!flag) {
			printf("%lld\n", ans);
			for(rgi j = 1; j <= n + 1 && !to[j][f[j]]; ++j)
				to[j][f[j]] = ans;
		}
		else {
			printf("%lld\n", f[n] + l[n + 1]);
			for(rgi j = 1; j <= n + 1 && !to[j][f[j]]; ++j)
				to[j][f[j]] = f[n] + l[n + 1];
		}
		
	}
	return 0;
}
/*
4 5 1
12 18 4 6 7
5
4
11
5
3
2

*/
