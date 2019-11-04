#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 4010
#define maxm 25010

using namespace std;

int T, V, tot;
int v[maxm], w[maxm], f[maxm];
int e[maxn][maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	T = read(), V = read();
	for(rgi i = 1; i <= T; ++i)
	{
		e[i][0] = read();
		for(rgi j = 1; j <= e[i][0]; ++j)
		{
			e[i][j] = ++tot;
			v[tot] = read();
			w[tot] = read();
		}
	}
	for(rgi i = 1; i <= T; ++i)
		for(rgi j = V; j >= 0; --j)
			for(rgi k = 1; k <= e[i][0]; ++k)
				if(j - v[e[i][k]] >= 0)
					f[j] = max(f[j], f[j - v[e[i][k]]] + w[e[i][k]]);
	printf("%d", f[V]);
	return 0;
}

