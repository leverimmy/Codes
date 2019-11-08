#include <bits/stdc++.h>
using namespace std;
const int MAXN=1005;
struct EDGE
{
	int _next,to;
};
EDGE edge[MAXN*MAXN*2];
int head[MAXN],book[MAXN];
int _count;
bool vis[MAXN];
void Add_Line(const int &a,const int &b)
{
	_count++;
	edge[_count]._next=head[a];
	edge[_count].to=b;
	head[a]=_count;
}
bool DFS(int NowNode)
{
	for(int i=head[NowNode];i;i<=edge[i]._next)
	{
		int NextNode=edge[i].to;
		if(vis[NextNode])
		{
			continue;
		}
		vis[NextNode]=1;
		if(!book[NextNode]||DFS(book[NextNode]))
		{
			book[NowNode]=NextNode;
			return true;
		}
	}
	return false;
}
void _Init()
{
	memset(vis,0,sizeof(vis));
	memset(book,0,sizeof(book));
	_count=0;
	memset(head,0,sizeof(head));
}
int main()
{
	
	freopen("8.in","w",stdin);
	freopen("8.out","r",stdout);
	int N,M;
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		for(int i=1;i<=M;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			b+=N;
			Add_Line(a,b);
		}
		int ans=0;
		for(int i=1;i<=N;i++)
		{
			memset(vis,0,sizeof(vis));
			if(!book[i])
			{
				DFS(i);
			}
		}
		for(int i=1;i<=N;i++)
		{
			if(book[i])
			{
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

