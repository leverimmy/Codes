#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<cctype>
#include<stack>
using namespace std;
const int M=101000;
const int inf=0x3f3f3f3f;
int n,m,map[30][30],px,py,hx,hy,ans,vis[30][30][30][30];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int ddx[4];
int ddy[4];
struct state{
	int hx,hy,px,py,time;
};
queue<state>q;
inline int read()
{
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)) {if (s=='-') f=-1; s=getchar();}
	while (isdigit(s)) {x=(x<<1)+(x<<3)+(s^48); s=getchar();}
	return x*f;
}
inline bool judge(int x,int y,int tx,int ty)
{
	if (map[y][x]==1||map[y][x]==2||map[ty][tx]==2||x>m||x<1||y>n||y<1||tx>m||tx<1||ty>n||ty<1)
		return false;
	return true;
}
inline void bfs()
{
	q.push(state{hx,hy,px,py,0});
	vis[py][px][hy][hx]=1;
	while (!q.empty())
	{
		state x=q.front();
		q.pop();
		for (int i=0;i<4;i++)
		{
			int tmpx1=x.px+dx[i],tmpy1=x.py+dy[i];
			int tmpx2=x.hx+ddx[i],tmpy2=x.hy+ddy[i];
			if (map[tmpy2][tmpx2]==1)
			{
				tmpx2=x.hx;
				tmpy2=x.hy;
			}
			if (judge(tmpx1,tmpy1,tmpx2,tmpy2)&&!vis[tmpy1][tmpx1][tmpy2][tmpx2])
			{
				if (tmpx1==tmpx2&&tmpy1==tmpy2)
				{
					ans=x.time+1;
					return;
				}
				vis[tmpy1][tmpx1][tmpy2][tmpx2]=1;
				q.push(state{tmpx2,tmpy2,tmpx1,tmpy1,x.time+1});
			}
		}
	}
}
int main()
{
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			char s;
			cin>>s;
			if (s=='.')
			{
				map[i][j]=0;
			}
			if (s=='#')
			{
				map[i][j]=1;
			}
			if (s=='!')
			{
				map[i][j]=2;
			}
			if (s=='H')
			{
				hx=j,hy=i;
			}
			if (s=='P')
			{
				px=j,py=i;
			}
		}
	}
	for (int i=0;i<=3;i++)
	{
		char s;
		cin>>s;
		if (s=='N')
		{
			ddx[i]=0,ddy[i]=-1;
		}
		if (s=='S')
		{
			ddx[i]=0,ddy[i]=1;
		}
		if (s=='W')
		{
			ddx[i]=-1,ddy[i]=0;
		}
		if (s=='E')
		{
			ddx[i]=1,ddy[i]=0;
		}
	}
	bfs();
	printf("%d",ans);
	return 0;
}
