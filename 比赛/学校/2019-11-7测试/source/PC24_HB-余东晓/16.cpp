#include<cstdio>
#include<cstring>
#include<cassert>
#include<climits>
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
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int a[1010][1010];
char ch[10];
signed main()
{
	freopen("16.in","r",stdin);
	freopen("16.out","w",stdout);
	int id;
	while(~scanf("%s%d",ch,&id))
	{
		memset(a,0,sizeof(a));
		int n,s;
		scanf("%d%d",&n,&s);
		int p(0),x(1),y(1);
		while(!a[x][y])
		{
			a[x][y]=n;
			n++;
			if(!(x+dx[p])||x+dx[p]>s||!(y+dy[p])||y+dy[p]>s)
				(p+=1)%=4;
			x+=dx[p];
			y+=dy[p];
		}
		for(int i=1;i<=s;i++)
		{
			for(int j=1;j<=s;j++)
				if(a[i][j])
					printf("%d ",a[i][j]);
				else
					printf("   ");
			puts("");
		}
	}
	return 0;
}
