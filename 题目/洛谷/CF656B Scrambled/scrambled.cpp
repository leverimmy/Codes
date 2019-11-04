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
#define maxx 720720
#define maxn 20

using namespace std;

int n, cnt;
int m[maxn], r[maxn];

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
	for(rgi i = 1; i <= n; ++i)
		m[i] = read();
	for(rgi i = 1; i <= n; ++i)
		r[i] = read();
	for(rgi i = 1; i <= maxx; ++i)
		for(rgi j = 1; j <= n; ++j)
			if(i % m[j] == r[j])
			{
				cnt++;
				break;
			}
	printf("%.6f", 1.0 * cnt / maxx);
	return 0;
}

