#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

const ll oo = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6 + 10;

int n; ll ans = -oo;
int a[N]; ll s[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	freopen("jx.in", "r", stdin);
	freopen("jx.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		a[i] = read();
		s[i] = s[i - 1] + a[i];
	}
	for(rgi i = 1; i <= n - 2; ++i){
		for(rgi j = i; j <= n - 2; ++j){
			for(rgi k = j + 1; k <= n - 1; ++k){
				for(rgi l = k; l <= n - 1; ++l){
					for(rgi o = l + 1; o <= n; ++o){
						for(rgi p = o; p <= n; ++p){
							ans = max(ans, s[j] - s[i] + s[l] - s[k] + s[p] - s[o]);}}}}}} 
	printf("%lld", ans);
	return 0;
}
/*
10
-1
2
3
-4
0
1
-6
-1
1
-2

*/

