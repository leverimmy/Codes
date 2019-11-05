#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAXN 100005

int min(int a,int b) { return a<b?a:b; }

struct Edge { int num,u,v,t; } a[MAXN];

const int x=10,n=20,m=10000;
long long tott;
int vis[MAXN],b[MAXN];

int main()
{
	srand(time(NULL));
	freopen("journey7.in","w",stdout);
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
			a[i]=(Edge){i,a[i-1].v,t,(rand()%200+1)*(rand()%200+1)};
		}
		int l=rand()%2500+1,r=rand()%2500+3000;
		for (int i=l;i<=r;i++) b[i]=a[i].v;
		random_shuffle(a+1,a+m+1);
		for (int i=1;i<=m;i++) printf("%d %d %d %d\n",a[i].num,a[i].u,a[i].v,a[i].t),tott+=a[i].t;
		printf("%d\n",r-l+1);
		for (int i=l;i<=r;i++) printf("%d ",b[i]);
		printf("\n%I64d\n",tott);
	}
	return 0;
}
