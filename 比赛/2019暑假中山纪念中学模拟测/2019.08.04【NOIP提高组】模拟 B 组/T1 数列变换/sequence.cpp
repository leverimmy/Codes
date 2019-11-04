#include <cstdio>
#include <cstring>
#include <cctype>
#include <list>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 100000 + 10;

int n;
int l[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void debug()
{
	for(rgi i = 1; i <= n; ++i)
		printf("%d ", l[i]);
	puts("");
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
		l[i] = i;
	for(rgi k = 2; k <= n; ++k)
	{
		for(rgi i = 1; i <= n; i += k)
		{
			int cur = l[i];
			for(rgi j = i; j <= min(n, (i / k + 1) * k) - 1; ++j)
				l[j] = l[j + 1];
			l[min(n, (i / k + 1) * k)] = cur;
		}
//		debug();
	}
	for(rgi i = 1; i <= n; ++i)
		printf("%d ", l[i]);
	return 0;
}

