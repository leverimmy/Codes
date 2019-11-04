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
	int n = 5, k = 5;
	printf("%d %d\n", n, k);
	for(rgi i = 1; i <= k; ++i)
	{
		int val = random(1, n * n);
		int to_x = random(1, n);
		int to_y = random(1, n);
		printf("%d %d %d\n", val, to_x, to_y);
	}
	return 0;
}

