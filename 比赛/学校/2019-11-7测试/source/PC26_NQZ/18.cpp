#include <bits/stdc++.h>
using namespace std;
const int MAXN=10005;
int father[MAXN];
int Find(int x)
{
	father[x]==x?x:father[x]=Find(x);
}
void Merge(int x,int y)
{
	int r1=Find(x);
	int r2=Find(y);
	if(r1!=r2)
	{
		father[r1]=r2;
	}
}
int main()
{
	freopen("18.in","r",stdin);
	freopen("18.out","w",stdout);
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		father[i]=i;
	}
	for(int i=1;i<=M;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int r1=Find(a);
		int r2=Find(b);
		if(r1!=r2)
		{
			Merge(a,b);
		}
	}
	int ans=0;
	for(int i=1;i<=N;i++)
	{
		if(father[i]==i)
		{
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}

