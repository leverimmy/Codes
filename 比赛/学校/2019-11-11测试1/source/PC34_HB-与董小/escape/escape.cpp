#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<climits>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<stack>
#include<map>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
struct node
{
	int x,y,d;
	node(){}
	node(int x,int y,int d):x(x),y(y),d(d){}
};
bool operator <(node x,node y)
{
	return x.d<y.d;
}
int d[505][505],f[505][505],vis[505][505];
void dijkstra(int sx,int sy,int n,int m)
{
	memset(f,-INF,sizeof(f));
	memset(vis,0,sizeof(vis));
	std::priority_queue<node>q;
	q.push(node(sx,sy,0));
	f[sx][sy]=d[sx][sy];
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
		int x=t.x,y=t.y;
		if(vis[x][y])
			continue;
		for(int p=0;p<4;p++)
		{
			int vx=x+dx[p],vy=y+dy[p];
			if(!vx||!vy||vx>n||vy>m)
				continue;
			int w=std::min(f[x][y],d[vx][vy]);
			if(f[vx][vy]<w)
			{
				f[vx][vy]=w;
				q.push(node(vx,vy,w));
			}
		}
	}
}
struct point
{
	int x,y;
	point(){}
	point(int x,int y):x(x),y(y){}
};
std::queue<point>q;
signed main()
{
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	int n,m,sx,sy,tx,ty;
	memset(d,INF,sizeof(d));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			char ch;
			std::cin>>ch;
			if(ch=='V')
			{
				sx=i;
				sy=j;
			}
			if(ch=='J')
			{
				tx=i;
				ty=j;
			}
			if(ch=='+')
			{
				q.push(point(i,j));
				d[i][j]=0;
				vis[i][j]=1;
			}
		}
	while(!q.empty())
	{
		point u=q.front();
		q.pop();
		int x=u.x,y=u.y;
		for(int p=0;p<4;p++)
		{
			int vx=x+dx[p],vy=y+dy[p];
			if(!vx||!vy||vx>n||vy>m||vis[vx][vy])
				continue;
			vis[vx][vy]=1;
			d[vx][vy]=d[x][y]+1;
			q.push(point(vx,vy));
		}
	}
	dijkstra(sx,sy,n,m);
	return!printf("%d\n",f[tx][ty]);
}
