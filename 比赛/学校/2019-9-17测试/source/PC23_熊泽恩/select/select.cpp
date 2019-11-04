#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define ll long long
#define rgi register int
#define il inline

using namespace std;

const int oo = 2147483647;
const int N = 100 + 10;

int n, m, ans;
int e[N][N];

struct POINTS
{
	int v, p;
} Point[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	freopen("select.in", "r", stdin);
	freopen("select.out", "w", stdout);
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
	{
		Point[i].v = read();
		Point[i].p = read();
	}
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read();
		e[u][v] = 1;
	}
	for(rgi i = 0; i <= (1LL << n) - 1; ++i)//枚举每个点是否被选 
	{
		int cur_ans = 0;
		for(rgi j = 1; j <= n; ++j)
			if((1LL << j - 1) & i)
			{
				cur_ans += Point[j].v;
				for(rgi k = 1; k <= n; ++k)
					if(e[k][j] && !((1LL << k - 1) & i))
					{
						cur_ans -= Point[j].p;
						break;
					}
			}
		if(cur_ans > ans)
			ans = cur_ans;
	}
	printf("%d", ans);
	return 0;

}
/*
3 2
5 10
-3 2
-1 7
2 1
3 1

*/

