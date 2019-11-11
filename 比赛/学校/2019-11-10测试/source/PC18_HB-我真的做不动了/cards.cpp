#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<cassert>
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
ll opt[2020][2020];
struct node
{
	int x,y;
	node(){}
	node(int x,int y):x(x),y(y){}
};
node getox(int x,int y)
{
	int mx=0,my=0;
	if(x<y)
		for(int i=1;i<=x+1;i++)
			for(int p=1;p<=y;p++)
			{
				ll q=(ll)y-(ll)i*(ll)p;
				if(q<=0)
					continue;
				opt[i][p]=-((ll)i*(ll)p*(ll)p)+((ll)x-(ll)p-q)+((ll)p+q)*((ll)p+q);
				if(opt[mx][my]<opt[i][p])
				{
					mx=i;
					my=p;
				}
			}
	/*else
	{
		for(int i=1;i<=n;i++)
	}*/
	return node(mx,my);
}
signed main()
{
	freopen("cards.in","r",stdin);
	freopen("cards.out","w",stdout);
	int x,y;
	scanf("%d%d",&x,&y);
	node p=getox(x,y);
	printf("%lld\n",opt[p.x][p.y]);
	return puts(""),0;
}
