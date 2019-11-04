#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
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
	freopen("pool.in", "w", stdout);
	int T = 1000, k = 1;
	printf("%d %d\n", T, k);
	for(rgi i = 1; i <= T; ++i)
	{
		int l = random(1, 1000);
		int r = random(1, 1000);
		if(l > r)
			swap(l, r);
		printf("%d %d\n", l, r);
	}
	return 0;
}

