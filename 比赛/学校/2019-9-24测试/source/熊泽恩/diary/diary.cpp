#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#define ll long long
#define rgi int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e4 + 10;

int T, n, k;
int tot, vis[N], primes[N], s[N];

set <int> sum[10000 + 10];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

signed main()
{
//	freopen("diary.in", "r", stdin);
//	freopen("diary.out", "w", stdout);
	for(rgi i = 2; i < N; ++i)
	{
		if(!vis[i])	primes[++tot] = i;
		for(rgi j = 2; j <= N / i && i * j < N; ++j)
			vis[i * j] = 1;
	} //sieve
	for(rgi i = 1; i <= tot; ++i) s[i] = s[i - 1] + primes[i];
	//prefix sum
	for(rgi len = 1; len <= tot; ++len)
		for(rgi l = 1, r = l + len - 1; r <= tot; ++l, r = l + len - 1)
			sum[len].insert(- s[r] + s[l - 1]);
	T = read();
	while(T--)
	{
		n = read(), k = read();
		set <int> :: iterator it = lower_bound(sum[k].begin(), sum[k].end(), -n);
		if(it == sum[k].end())	puts("-1");
		else	printf("%d\n", -*it);
	}
	//upper : >
	//lower : >=
	return 0;
}
/*
3
20 2
20 3
20 4

3
18 2
20 3
20 4

1
997831 10

*/
