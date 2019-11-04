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
const int N = 1e6 + 10;

int T, n, k;
int tot, vis[N], primes[N], s[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
//	freopen("diary.in", "r", stdin);
//	freopen("diary.out", "w", stdout);
	for(rgi i = 2; i < N; ++i)
	{
		if(!vis[i])	primes[++tot] = i;
		for(rgi j = 2; j <= N / i && i * j < N; ++j)
			vis[i * j] = 1;
	}
	for(rgi i = 1; i <= tot; ++i) s[i] = s[i - 1] + primes[i];
	T = read();
	while(T--)
	{
		n = read(), k = read();
		if(k > tot || s[k] > n)	puts("-1");
		else
		{
			int l = k, r = tot + 1;
			for(; l < r; )
			{
				int mid = l + r + 1 >> 1;
				if(s[mid] - s[mid - k] <= n)
					l = mid;
				else
					r = mid - 1;
			}
			printf("%d\n", s[l] - s[l - k]);
		}
	}
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
