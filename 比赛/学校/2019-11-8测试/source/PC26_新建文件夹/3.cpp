#include <bits/stdc++.h>
using namespace std;
const int MAXN=200005;
struct EDGE
{
	int _next,to;
};
EDGE edge[MAXN];
int dfn[MAXN],low[MAXN],_count,head[MAXN];
int _clock,ans;
void Add_Line(const int &a,const int &b)
{
	_count++;
	edge[_count]._next=head[a];
	edge[_count].to=b;
	head[a]=_count;
}
void Tarjan(int NowNode,int fa)
{
	_clock++;
	dfn[NowNode]=low[NowNode]=_clock;
	for(int i=head[NowNode];i;i=edge[i]._next)
	{
		int NextNode=edge[i].to;
		if(!dfn[NextNode])
		{
			Tarjan(NextNode,NowNode);
			low[NowNode]=min(low[NowNode],low[NextNode]);
		}
		else if(NextNode!=fa)
		{
			low[NowNode]=min(low[NowNode],dfn[NextNode]);
		}
	}
	for(int i=head[NowNode];i;i=edge[i]._next)
	{
		int NextNode=edge[i].to;
		if(low[NextNode]>dfn[NowNode])
		{
			ans++;
		}
	}
}
void _Init()
{
	_count=0;
	memset(head,0,sizeof(head));
	_clock=0;
	ans=0;
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
}
int main()
{
	freopen("3.in","w",stdin);
	freopen("3.out","r",stdout);
	int N,M;
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		_Init();
		for(int i=1;i<=M;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			Add_Line(a,b);
		}
		for(int i=1;i<=N;i++)
		{
			if(!dfn[i])
			{
				Tarjan(i,0);
			}
		}
		for(int i=1;i<=N;i++)
		{
			printf("dfn:%d low:%d\n",dfn[i],low[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}

