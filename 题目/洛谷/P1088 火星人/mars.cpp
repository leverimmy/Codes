#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 10010

using namespace std;

int n, m;
int a[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read();
	m = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	for(; m; --m)
		next_permutation(a + 1, a + n + 1);
	for(rgi i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	return 0;
}

