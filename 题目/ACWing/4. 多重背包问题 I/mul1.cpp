#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 1010

using namespace std;

int N, V;
int v[maxn], w[maxn], s[maxn];
int f[maxn][maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	N = read(), V = read();
	for(rgi i = 1; i <= N; ++i)
	{
		v[i] = read();
		w[i] = read();
		s[i] = read();
	}
	for(rgi i = 1; i <= N; ++i)
		for(rgi j = 1; j <= V; ++j)
			for(rgi k = 0; k <= min(j / v[i], s[i]); ++k)
				f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
	printf("%d", f[N][V]);
	return 0;
}

