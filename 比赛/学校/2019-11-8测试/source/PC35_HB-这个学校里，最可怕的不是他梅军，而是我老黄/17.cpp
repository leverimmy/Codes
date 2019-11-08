#include<cstdio>
#include<cstring>
#include<climits>
#include<cassert>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
#define lowbit(x) x&-x
struct node
{
	int x,y;
}a[15005];
bool operator <(node x,node y)
{
	return x.x<y.x;
}
int n,C[15005];
void add(int x,int p)
{
	while(p<=n)
	{
		C[p]+=x;
		p+=lowbit(p);
	}
}
int query(int p)
{
	int ans(0);
	while(p)
	{
		ans+=C[p];
		p-=lowbit(p);
	}
	return ans;
}
signed main()
{
	freopen("17.in","r",stdin);
	freopen("17.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		
	}
}
