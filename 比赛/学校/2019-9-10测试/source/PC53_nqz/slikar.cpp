#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;

const int MAXN=250;

struct NODE
{
	int x,y;
};

int _map[MAXN][MAXN],f[MAXN][MAXN],p[MAXN][MAXN],visf[MAXN][MAXN],visp[MAXN][MAXN];
int fl,fr,pl,pr,sx,sy;
NODE _arrayf[MAXN*MAXN*MAXN],_arrayp[MAXN*MAXN*MAXN];
int main()
{
	freopen("slikar.in","r",stdin);
	freopen("slikar.out","w",stdout);
	memset(f,INF,sizeof(f));
	memset(p,INF,sizeof(p));
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		char a[MAXN];
		cin>>a;
		for(int j=1;j<=M;j++)
		{
			if(a[j-1]=='.')
			{
				_map[i][j]=1;
			}
			if(a[j-1]=='X')
			{
				_map[i][j]=0;
			}
			if(a[j-1]=='*')
			{
				_map[i][j]=2;
				visf[i][j]=1;
				f[i][j]=0;
				fr++;
				_arrayf[fr].x=i;
				_arrayf[fr].y=j;
			}
			if(a[j-1]=='D')
			{
				_map[i][j]=3;
				sx=i,sy=j;
			}
			if(a[j-1]=='S')
			{
				_map[i][j]=4;
				p[i][j]=0;
				visp[i][j]=1;
				pr++;
				_arrayp[pr].x=i;
				_arrayp[pr].y=j;
			}
		}
	}	
	while(fl<fr)
	{
		fl++;
		int x=_arrayf[fl].x;
		int y=_arrayf[fl].y;
		if(x+1<=N&&_map[x+1][y]!=0&&_map[x+1][y]!=3&&!visf[x+1][y])
		{
			f[x+1][y]=min(f[x+1][y],f[x][y]+1);
			fr++;
			_arrayf[fr].x=x+1;
			_arrayf[fr].y=y;
			visf[x+1][y]=1;
		}
		if(x-1>=1&&_map[x-1][y]!=0&&_map[x-1][y]!=3&&!visf[x-1][y])
		{
			f[x-1][y]=min(f[x-1][y],f[x][y]+1);
			fr++;
			_arrayf[fr].x=x-1;
			_arrayf[fr].y=y;
			visf[x-1][y]=1;
		}
		if(y+1<=M&&_map[x][y+1]!=0&&_map[x][y+1]!=3&&!visf[x][y+1])
		{
			f[x][y+1]=min(f[x][y+1],f[x][y]+1);
			fr++;
			_arrayf[fr].x=x;
			_arrayf[fr].y=y+1;
			visf[x][y+1]=1;
		}
		if(y-1>=1&&_map[x][y-1]!=0&&_map[x][y-1]!=3&&!visf[x][y-1])
		{
			f[x][y-1]=min(f[x][y-1],f[x][y]+1);
			fr++;
			_arrayf[fr].x=x;
			_arrayf[fr].y=y-1;
			visf[x][y-1]=1;
		}
	}
	while(pl<pr)
	{
		pl++;
		int x=_arrayp[pl].x;
		int y=_arrayp[pl].y;
		if(x+1<=N&&_map[x+1][y]&&!visp[x+1][y]&&p[x][y]+1<f[x+1][y])
		{
			p[x+1][y]=min(p[x+1][y],p[x][y]+1);
			pr++;
			_arrayp[pr].x=x+1;
			_arrayp[pr].y=y;
			visp[x+1][y]=1;
		}
		if(x-1>=1&&_map[x-1][y]&&!visp[x-1][y]&&p[x][y]+1<f[x-1][y])
		{
			p[x-1][y]=min(p[x-1][y],p[x][y]+1);
			pr++;
			_arrayp[pr].x=x-1;
			_arrayp[pr].y=y;
			visp[x-1][y]=1;
		}
		if(y+1<=M&&_map[x][y+1]&&!visp[x][y+1]&&p[x][y]+1<f[x][y+1])
		{
			p[x][y+1]=min(p[x][y+1],p[x][y]+1);
			pr++;
			_arrayp[pr].x=x;
			_arrayp[pr].y=y+1;
			visp[x][y+1]=1;
		}
		if(y-1>=1&&_map[x][y-1]&&!visp[x][y-1]&&p[x][y]+1<f[x][y-1])
		{
			p[x][y-1]=min(p[x][y-1],p[x][y]+1);
			pr++;
			_arrayp[pr].x=x;
			_arrayp[pr].y=y-1;
			visp[x][y-1]=1;
		}
	}
//	for(int i=1;i<=N;i++)
//	{
//		for(int j=1;j<=M;j++)
//		{
//			printf("%d ",_map[i][j]);
//		}
//		putchar('\n');
//	}
//	putchar('\n');
//	for(int i=1;i<=N;i++)
//	{
//		for(int j=1;j<=M;j++)
//		{
//			printf("%d ",f[i][j]);
//		}
//		putchar('\n');
//	}
//	putchar('\n');
//	for(int i=1;i<=N;i++)
//	{
//		for(int j=1;j<=M;j++)
//		{
//			printf("%d ",p[i][j]);
//		}
//		putchar('\n');
//	}
	if(p[sx][sy]==INF)
	{
		printf("ORZ hzwer!!!");
	}
	else
	{
		printf("%d",p[sx][sy]);
	}
	return 0;
}
