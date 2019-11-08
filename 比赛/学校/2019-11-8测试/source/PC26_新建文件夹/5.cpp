#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
struct EDGE
{
	int from,to,w;
};
EDGE edge[MAXN];

bool cmp(const EDGE &a,const EDGE &b)
{
	return a.w<b.w;
}
int father[MAXN];
int Find(int x)
{
	return father[x]==x?x:father[x]=Find(father[x]);
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
	freopen("5.in","w",stdin);
	freopen("5.out","r",stdout);
	int N,M;
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		int book=0;
		int ans=0;
		for(int i=1;i<=N;i++)
		{
			father[i]=i;
		}
		for(int i=1;i<=M;i++)
		{
			scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].w);
		}
		sort(edge+1,edge+1+N,cmp);
		for(int i=1;i<=N;i++)
		{
			int a=edge[i].from;
			int b=edge[i].to;
			int r1=Find(a),r2=Find(b);
			if(r1!=r2)
			{
				book++;
				ans+=edge[i].w;
				Merge(a,b);
			}
			else
			{
				continue;
			}
			if(book==N-1)
			{
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

