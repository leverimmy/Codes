#include <bits/stdc++.h>
using namespace std;	
int father[1000],en[1000];
int siz[1000];
int _count;
int Find(int x)
{
	return father[x]==x?x:father[x]=Find(father[x]);
}
void Union(int x,int y)
{
	int r1=Find(x);
	int r2=Find(y);
	if(r1!=r2)
	{
		father[r1]=r2;
		siz[r2]+=siz[r1];
	}
}
int main()
{
	freopen("geometry.in","r",stdin);
	freopen("geometry.out","w",stdout);
	int N,M,Q;
	scanf("%d%d%d",&N,&M,&Q);
	for(int i=1;i<=N;i++)
	{
		siz[i]=1;
		father[i]=i;
		en[i]=0;
	}
	for(int i=1;i<=M;i++)
	{
		int a,b;
		char opt[5];
		char x[5],y[5];
		cin>>x>>opt>>y;
		a=x[1]-'0';
		b=y[1]-'0';
		if(opt[0]=='p')
		{
			if(en[a]==b||en[b]==a)
			{
				printf("There must be something wrong!");
				return 0;
			}
			else
			{
				Union(a,b);
				en[b]=en[a];
			}
		}
		if(opt[0]=='v')
		{
			if(father[a]==b||father[b]==a)
			{
				printf("There must be something wrong!");
				return 0;
			}
			else
			{
				Union(en[a],b);
				en[b]=a;
			}
		}
	}
	int ans=0;
//	for(int i=1;i<=N;i++)
//	{
//		printf("%d ",father[i]);
//	}putchar('\n');
//	for(int i=1;i<=N;i++)
//		printf("%d ",siz[i]);
//		putchar('\n');
	for(int i=1;i<=N;i++)
	{
		Find(i);
		if(father[i]==i)
		{
			ans+=(siz[i]-1)*siz[i]/2;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=Q;i++)
	{
		int a,b;
		char x[5],y[5];
		cin>>x>>y;
		a=x[1]-'0';
		b=y[1]-'0';
		if(Find(a)==Find(b))
		{
			printf("Parallel.\n");
		}
		else if(Find(a)==Find(en[b])||Find(en[a])==Find(b))
		{
			printf("Vertical.\n");
		}
		else 
		{
			printf("No idea.\n");
		}
	}
	return 0;
}
