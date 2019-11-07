#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll maxn = 205,inf = 0x7fffffff;
ll n,t[maxn],d[maxn],f[maxn][maxn];
ll sumt[maxn],sumd[maxn];

int main()
{
	freopen("product.in","r",stdin);
	freopen("product.out","w",stdout);
	scanf("%lld",&n);
	for (ll i = 1; i <= n; i++)
	{
		scanf("%lld%lld",&t[i],&d[i]);
		sumt[i] = sumt[i - 1] + t[i];
		sumd[i] = sumd[i - 1] + d[i];
	}
	for (ll i = 1; i <= n; i++)
		for (ll j = i; j <= n; j++)
			f[i][j] = inf;
	for (ll i = 1; i <= n; i++)
		f[i][i] = t[i] * d[i];
	for (ll i = 1; i < n; i++)
		f[i][i + 1] = min(t[i] * d[i] + (t[i] + t[i + 1]) * d[i + 1],t[i + 1] * d[i + 1] + (t[i] + t[i + 1]) * d[i]);
	for (ll len = 3; len <= n; len++)
		for (ll i = 1; i + len - 1 <= n; i++)
		{
			ll j = i + len - 1;
			f[i][j] = f[i][i] + t[i] * (sumd[j] - sumd[i]) + f[i + 1][j]; //l第一个出栈
			f[i][j] = min(f[i][j],f[i][i] + (sumt[j] - sumt[i]) * d[i] + f[i + 1][j]); //l最后一个出栈
			for (ll k = i + 1; k <= j - 1; k++)
				f[i][j] = min(f[i][j],f[i + 1][k] + (sumt[k] - sumt[i - 1]) * (d[i] + sumd[j] - sumd[k]) + f[k + 1][j]); 
		}
	printf("%lld\n",f[1][n]);
	
	return 0;
}
