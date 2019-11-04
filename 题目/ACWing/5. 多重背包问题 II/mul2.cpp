#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 20010

using namespace std;

int N, V, cnt;
int v[maxn], w[maxn], s[maxn];
int f[maxn];

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
		int a = read();
		int b = read();
		int s = read();
		for(rgi j = 1; j <= s; j <<= 1)
		{
			cnt++;
			s -= j;
			v[cnt] = j * a;
			w[cnt] = j * b;
		}
		if(s)
		{
			cnt++;
			v[cnt] = s * a;
			w[cnt] = s * b;
		}
	}
	N = cnt;
	for(rgi i = 1; i <= N; ++i)
		for(rgi j = V; j >= v[i]; --j)
			f[j] = max(f[j], f[j - v[i]] + w[i]);
	printf("%d", f[V]);
	return 0;
}

