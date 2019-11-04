#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define il inline
#define ll long long
#define rgi register ll
#define maxn 110
#define maxm 10010

using namespace std;

ll N, V;
ll v[maxn], f[maxn][maxm];

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	N = read(), V = read();
	for(rgi i = 1; i <= N; i++)
		v[i] = read();
	f[0][0] = 1;
	for(rgi i = 1; i <= N; i++)
	{
		for(rgi j = 0; j <= V; j++)
		{
			f[i][j] = f[i - 1][j];
			if(j >= v[i])
				f[i][j] += f[i - 1][j - v[i]];
		}
	}
	printf("%lld", f[N][V]);
	return 0;
}

