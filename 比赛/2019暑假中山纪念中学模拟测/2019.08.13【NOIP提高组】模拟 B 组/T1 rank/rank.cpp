#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 100000 + 10;

int n, k, cnt;
int book[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
//	freopen("data1.in", "r", stdin);
	n = read(), k = read();
//	k = n - k;
	for(rgi i = 1; i <= n; ++i)
	{
		int x = read();
		book[x]++;
	}
	for(rgi i = 0; i < N; ++i)
	{
		if(cnt + book[i] < k)
		{
			for(rgi j = 1; j <= book[i]; ++j)
				printf("%d ", i);
			cnt += book[i];
		}
		else
		{
			for(rgi j = 1; j <= k - cnt; ++j)
				printf("%d ", i);
			break;
		}
	}
	return 0;
}

