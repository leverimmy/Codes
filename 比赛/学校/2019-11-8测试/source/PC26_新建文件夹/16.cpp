#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN=1000005;
struct EDGE
{
	int _next,to,w;
};
EDGE edge[MAXN];
int head[MAXN],_count;
int cnt[MAXN];
void Add_Line(const int &a,const int &b,const int &c)
{
	_count++;
	edge[_count]._next=head[a];
	edge[_count].to=b;
	edge[_count].w=c;
	head[a]=_count;
}
int dis[MAXN],vis[MAXN],l,r,_array[MAXN];
void _Init()
{
	memset(cnt,0,sizeof(cnt));
	_count=0;
	memset(head,0,sizeof(head));
	memset(dis,INF,sizeof(dis));
	memset(vis,false,sizeof(vis));
	l=0,r=0;
}
bool SPFA(int N)
{
	dis[1]=0;
	vis[1]=1;
	cnt[1]=1;
	r++;
	_array[r]=1;
	while(l<r)
	{
		l++;
		int NowNode=_array[l];
		vis[NowNode]=false;
		for(int i=head[NowNode];i;i=edge[i]._next)
		{
			int NextNode=edge[i].to;
			if(dis[NextNode]>dis[NowNode]+edge[i].w)
			{
				dis[NextNode]=dis[NowNode]+edge[i].w;
				cnt[NextNode]++;
				if(cnt[NextNode]==N)
				{
					return false;
				}
				if(!vis[NextNode])
				{
					vis[NextNode]=1;
					r++;
					_array[r]=NextNode;
				}
			}
		}
	}
	return true;
}
int main()
{
	freopen("16.in","w",stdin);
	freopen("16.out","r",stdout);
	int N,M;
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		_Init();
		for(int i=1;i<=M;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			Add_Line(a,b,c);
		}
		bool flag=SPFA(N);
		if(!flag)
		{
			puts("yes");
		}
		else
		{
			puts("no");
		}
	}
	return 0;
}

