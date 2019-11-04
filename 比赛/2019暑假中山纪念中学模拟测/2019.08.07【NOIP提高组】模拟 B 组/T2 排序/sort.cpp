#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 100000 + 10;

int n;
int a[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	freopen("testdata.in", "r", stdin);
	freopen("testdata.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	a[n + 1] = n + 1;
	for(rgi i = 1; i <= n; ++i)
	{
		int cnt = 0;
		if(i & 1)
		{
			int pos;
			for(rgi j = 1; j <= n; ++j)
				if(a[j] == i + 1 >> 1)
				{
					pos = j;
					break;
				}
			for(rgi j = pos; j >= 1; --j)
			{
				if(a[j] < a[j - 1])
				{
					cnt++;
					swap(a[j], a[j - 1]);
				}
				else
					break;
			}
		}
		else
		{
			int pos;
			for(rgi j = 1; j <= n; ++j)
				if(a[j] == n - (i >> 1) + 1)
				{
					pos = j;
					break;
				}
			for(rgi j = pos; j <= n; ++j)
			{
				if(a[j] > a[j + 1])
				{
					cnt++;
					swap(a[j], a[j + 1]);
				}
				else
					break;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}

