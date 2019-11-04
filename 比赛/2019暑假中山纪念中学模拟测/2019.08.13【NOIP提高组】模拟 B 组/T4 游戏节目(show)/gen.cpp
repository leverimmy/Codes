#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int
#define rgl register ll

using namespace std;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	freopen("show.in", "w", stdout);
	int n = 22, k = 1;
	printf("%d %d\n", n, k);
	printf("%d ", 1000000001);
	for(rgi i = 2; i <= n; ++i)
		printf("%d ", 1000000000);
	puts("");
	for(rgi i = 1; i <= n; ++i)
		printf("%d ", 1000000000);
	puts("");
	for(rgi i = 1; i <= n; ++i)
		printf("%d ", 1000000000);
	puts("");
	return 0;
}

