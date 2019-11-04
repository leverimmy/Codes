#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define mo 1000000000000000000LL
using namespace std;
long long n, i, son[150005], vis[150005], x, y, f[150005][205], book[150005], g[150005], ans;
long long top, nex[150005], to[150005], fir[150005], sd[150005], book2[150005], son2[150005];
void lj(int u, int v)
{
	top++;
	to[top] = v;
	nex[top] = fir[u];
	fir[u] = top;
	return ;
}
void ss(int u, int v, int w)
{
	book[w] = 1;
	son[w] = son2[v];
	for(int top1 = fir[v]; top1; top1 = nex[top1])
		if(to[top1] != u)
		{
			if(book[top1] == 0)
				ss(v, to[top1], top1);
			son[w] += son[top1];
			vis[w] += son[top1] + vis[top1];
			sd[w] = max(sd[w], sd[top1] + 1);
		}
	return ;
}
void ss2(int u, int v, int w)
{
	book2[w] = 1;
	for(int j = 1; j <= sd[w]; j++)
		f[w][j] = mo;
	f[w][0] = vis[w];
	for(int top1 = fir[v]; top1; top1 = nex[top1])
		if(to[top1] != u)
		{
			if(book2[top1] == 0)
				ss2(v, to[top1], top1);
			for(int j = 1; j - 1 <= sd[top1]; j++)
				f[w][j] = min(f[w][j], f[top1][j - 1] + vis[w] - vis[top1] + (son[w] - son[top1]) * j - son[top1]);
		}
	g[w] = f[w][0];
	for(int j = 1; j <= sd[w]; j++)
		g[w] = min(g[w], f[w][j]);
	return ;
}
int main()
{
	freopen("practice.in", "r", stdin);
	freopen("practice.out", "w", stdout);
	scanf("%lld", &n);
	if(n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	for(i = 1; i < n; i++)
	{
		scanf("%lld%lld", &x, &y);
		lj(x, y);
		lj(y, x);
	}
	for(i = 1; i <= n; i++)
		scanf("%lld", &son2[i]);
	for(i = 1; i <= n; i++)
		ss(i, i, i + top);
	ss(1, 1, 1 + top);
	for(i = 1; i <= n; i++)
		ss2(i, i, i + top);
	ans = mo;
	for(i = 1; i <= top; i += 2)
		ans = min(ans, g[i] + g[i + 1]);
	printf("%lld\n", ans);
	return 0;
}
