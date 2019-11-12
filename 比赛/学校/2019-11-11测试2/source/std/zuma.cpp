#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;
struct Node{
	int col,tot;
}s[1010];
int n,K,a[1010],m,f[110][110][110];
bool vis[110][110][110];

int dfs(int l,int r,int tot)
{
	if (vis[l][r][tot] == 1)     return f[l][r][tot];
	vis[l][r][tot] = 1;
	if (l > r)    return 0;
	f[l][r][tot] = dfs(l,r - 1,0) + max(0,K - tot - s[r].tot);
	for (int i = l;i < r - 1;i++)
		if (s[i].col == s[r].col)
			f[l][r][tot] = min(f[l][r][tot],dfs(l,i,tot + s[r].tot) + dfs(i + 1,r - 1,0));
	return f[l][r][tot];
}

int main()
{
//	freopen("zuma.in","r",stdin);     freopen("zuma.out","w",stdout);
	cin >> n >> K;
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	int cnt = 1;
	for (int i = 1;i <= n;i++)
		{
			if (a[i] == a[i + 1])   cnt++;
			else {
				s[++m] = (Node){a[i],cnt};
				cnt = 1;
			}
		}
	cout << dfs(1,m,0);
}
