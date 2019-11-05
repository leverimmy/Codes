#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>

#define MAXN 2000005

int min(int a,int b) { return a<b?a:b; }

struct Edge { int num,u,v,t; } a[MAXN];

const int x=10,n=100,m=200000,tt=200000;
long long tott;
int vis[MAXN];

int main()
{
	srand(time(NULL));
	//freopen("journey9.in","w",stdout);
	printf("%d\n",x);
	for (int k=1;k<=x;k++)
	{
		memset(vis,0,sizeof(vis)),tott=0;
		printf("%d %d\n",n,m);
		a[0].v=rand()%n+1;
		for (int i=1;i<=m;i++)
		{
			int t=rand()%n+1;
			while (t==a[i-1].v) t=rand()%n+1;
			a[i]=(Edge){i,a[i-1].v,t,rand()%tt+1};
		}
		for (int i=1;i<=m;i++)
		{
			int o=min(m,(rand()<<6)|(rand()>>9)+1);
			while (vis[o] || o>m) o=min(m,(rand()<<6)|(rand()>>9)+1);
			vis[o]=1,printf("%d %d %d %d %d\n",i,a[o].num,a[o].u,a[o].v,a[o].t),tott+=a[o].t;
		}
		int l=min(m,(rand()<<6)|(rand()>>9)+1),r=min(m,(rand()<<6)|(rand()>>9)+1);
		while (r<=l || l>m || r>m) l=(rand()%500+1)*(rand()%500+1),r=(rand()%500+1)*(rand()%500+1);
		printf("%d\n",r-l+1);
		for (int i=l;i<=r;i++) printf("%d ",a[i].v);
		printf("\n%I64d\n",tott);
	}
	return 0;
}
