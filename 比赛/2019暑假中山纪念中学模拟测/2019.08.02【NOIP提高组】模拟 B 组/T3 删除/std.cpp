#include <cstdio>
#include <cstring>
#include <vector>
#include <cctype>
#define ll long long
#define il inline
#define rgi register int
#define maxn 100010
#define max_num 110

using namespace std;

int n, ok, ans;
int a[maxn],b[maxn],c[maxn];
int cntb[maxn], cntc[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	//freopen("game10.in", "r", stdin);
	//freopen("game10.ans", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	for(rgi i = 1; i <= n; ++i)
	{
		b[i] = read();
		cntb[b[i]]++;
	}
	for(rgi i = 1; i <= n; ++i)
	{
		c[i] = read();
		cntc[c[i]]++;
	}
	while(1)
	{
		if(ok)
			break;
		ok = 1;
		for(rgi i = 1; i <= n; ++i)
		{
			if(a[i] && (cntb[a[i]] == 0 || cntc[a[i]] == 0))
			{
				ok = 0;
				ans++;
				cntb[b[i]]--;
				cntc[c[i]]--;
				a[i] = 0;
			}
		}
	}
	printf("%d", ans);
	return 0;
}

