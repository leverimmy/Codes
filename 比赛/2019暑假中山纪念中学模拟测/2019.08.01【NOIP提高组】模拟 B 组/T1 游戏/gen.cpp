#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int random(int l, int r)
{
	if(l == r)
		return l;
	return rand() * rand() % (r - l) + l;
}

int main()
{
	freopen("testdata.in", "w", stdout);
	int T = 5;
	printf("%d\n", T);
	for(; T; T--)
	{
		int n = 1000;
		printf("%d\n", n);
		for(rgi i = 1; i <= n; ++i)
		{
			for(rgi j = 1; j <= n; ++j)
				printf("%d ", random(0, 2000000));
			puts("");
		}
		puts("");
	}
	return 0;
}

