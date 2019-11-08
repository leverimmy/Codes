#include <bits/stdc++.h>
using namespace std;
const int MAXN=200005;
struct EDGE
{
	int _next,to;
};
EDGE edge[MAXN];
int dfn[MAXN],low[MAXN],_count,head[MAXN];
int _clock,ans,col[MAXN],cnt;
int sta[MAXN],top,vis[MAXN];
void Add_Line(const int &a,const int &b)
{
	_count++;
	edge[_count]._next=head[a];
	edge[_count].to=b;
	head[a]=_count;
}
void _Init()
{
	cnt=0;
	memset(col,0,sizeof(col));
	memset(vis,0,sizeof(vis));
	_count=0;
	memset(head,0,sizeof(head));
	_clock=0;
	ans=0;
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
}
void Tarjan(int NowNode)
{
	_clock++;
	top++;sta[top]=NowNode;
	vis[NowNode]=1;
	dfn[NowNode]=low[NowNode]=_clock;
	for(int i=head[NowNode];i;i=edge[i]._next)
	{
		int NextNode=edge[i].to;
		if(!dfn[NextNode])
		{
			Tarjan(NextNode);
			low[NowNode]=min(low[NowNode],low[NextNode]);
		}
		else if(vis[NextNode])
		{
			low[NowNode]=min(low[NowNode],dfn[NextNode]);
		}
	}
	if(dfn[NowNode]==low[NowNode])
	{
		cnt++;
		int now=sta[top];
		while(1)
		{
			now=sta[top];
			vis[now]=0;
			col[now]=cnt;
			if(now==NowNode)
			{
				top--;
				break;
			}
			top--;
		}
	}
}



int main()
{
	
	freopen("10.in","w",stdin);
	freopen("10.out","r",stdout);
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
				Tarjan(i);
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}

