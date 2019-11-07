#include <bits/stdc++.h>

using namespace std;

const int maxn = 3010;
int n,m,fa[maxn],num;

int find(int x)
{
	if (x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}

int main()
{
	freopen("18.in","r",stdin);
	freopen("18.out","w",stdout);
	scanf("%d%d",&n,&m);
	num = n;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int fx = find(x),fy = find(y);
		if (fx != fy)
		{
			fa[fx] = fy;
			num--;
		}
	}
	printf("%d\n",num);
	
	return 0;
}
