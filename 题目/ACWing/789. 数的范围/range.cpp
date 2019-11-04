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
#define maxn 100010

using namespace std;

int n, q;
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
	n = read(), q = read();
	for(rgi i = 0; i < n; ++i)
		a[i] = read();
	for(rgi i = 1; i <= q; ++i)
	{
		int x = read();
		int l = 0;
		int r = n - 1;
		while(l < r)
		{
			int mid = l + r >> 1;
			if(a[mid] >= x)
				r = mid;
			else
				l = mid + 1;
		}
		if(a[l] != x)
			printf("%d ", -1);
		else
			printf("%d ", l);
		l = 0;
		r = n - 1;
		while(l < r)
		{
			int mid = l + r + 1 >> 1;
			if(a[mid] <= x)
				l = mid;
			else
				r = mid - 1;
		}
		if(a[l] != x)
			printf("%d\n", -1);
		else
			printf("%d\n", l);
	}
	return 0;
}

