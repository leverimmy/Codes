#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN=6005;
const int MAXM=500005;
int head[MAXN],dis[MAXN];
bool vis[MAXN];
int _count;
bool _map[MAXN][MAXN],book[MAXN];
int no[MAXN][MAXN];
int num[MAXN];
int ind[MAXN];
struct EDGE
{
	int _next,to,w;
};
EDGE edge[MAXM];
void Add_Line(int a,int b,int c)
{
	_count++;
	edge[_count]._next=head[a];
	edge[_count].to=b;
	edge[_count].w=c;
	head[a]=_count;
}
int _array[MAXM<<3];

void _Init()
{
	memset(dis,INF,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(_array,0,sizeof(_array));
}

void SPFA(int S,int T)
{
	_Init();
	int l=0,r=1;
	dis[S]=0;
	vis[S]=1;
	_array[r]=S;
	while(l<r)
	{
		l++;
		int NowNode=_array[l];
		if(book[NowNode])
		{
			if(ind[NowNode])
			{
				r++;
				_array[r]=NowNode;
				continue;
			}
			else
			{
				book[NowNode]=0;
			}
		}
//		printf("%d ",NowNode);
		for(int i=head[NowNode];i;i=edge[i]._next)
		{
			int NextNode=edge[i].to;
			if(ind[NextNode])
			{
				book[NextNode]=1;
				r++;
				_array[r]=NextNode;
				vis[NextNode]=true;
			}
			if(dis[NextNode]>dis[NowNode]+edge[i].w)
			{
				dis[NextNode]=dis[NowNode]+edge[i].w;
				for(int j=1;j<=T;j++)
				{
					if(_map[NextNode][j])
					{
						ind[j]--;
						if(ind[j]==0&&vis[j])
						{
							dis[j]=max(dis[j],dis[NowNode]);
						}
					}
				}
				if(!vis[NextNode])
				{
					r++;
					_array[r]=NextNode;
					vis[NextNode]=true;
				}
			}
		}
		vis[NowNode]=false;
	}
}


int main()
{
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		Add_Line(a,b,c);
		Add_Line(b,a,c);
	}
	SPFA(1,N);
	if(dis[N]==INF)
	{
		printf("Mission Failed");
		return 0;
	}
	for(int i=2;i<=N-1;i++)
	{
		int K;
		scanf("%d",&K);
		for(int j=1;j<=K;j++)
		{
			int a;
			scanf("%d",&a);
			_map[i][a]=1;
			ind[a]++;
			num[i]++;
			no[i][num[i]]=a;
			if(_map[a][i])
			{
				printf("Mission Failed");
				return 0;
			}
		}
	}
//	for(int i=1;i<=N;i++)
//	{
//		printf("%d ",ind[i]);
//	}
	SPFA(1,N);
	if(dis[N]==INF)
	{
		printf("Mission Failed");
		return 0;
	}
	printf("%d",dis[N]);
}
