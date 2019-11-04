#include <cstdio>
#include <cstring>
#include <cstdlib>
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
	else
		return rand() * rand() % (r - l) + l;
}

int main()
{
	freopen("testdata.in", "w", stdout);
	int T = 20;
	printf("%d\n", T);
	for(; T; T--)
	{
		//int k = random(1, 1000), n = random(1, 1000);
		int k = 1000000, n = 50000;
		printf("%d %d\n", k, n);
		for(rgi i = 1; i <= n; ++i)
			printf("%d ", 1000000000);
		puts("");
	}
	return 0;
}

