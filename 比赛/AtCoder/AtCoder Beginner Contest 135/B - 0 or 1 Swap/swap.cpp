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
#define maxn 60

using namespace std;

int n;
int a[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool check()
{
	for(rgi i = 1; i <= n - 1; ++i)
		if(a[i] >= a[i + 1])
			return 0;
	return 1;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	if(check())
	{
		puts("YES");
		return 0;
	}
	for(rgi i = 1; i <= n; ++i)
	{
		for(rgi j = i + 1; j <= n; ++j)
		{
			swap(a[i], a[j]);
			if(check())
			{
				puts("YES");
				return 0;
			}
			swap(a[i], a[j]);
		}
	}
	puts("NO");
	return 0;
}

