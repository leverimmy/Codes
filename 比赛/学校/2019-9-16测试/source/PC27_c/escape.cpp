#include <bits/stdc++.h>
using namespace std;
const int MAXN=50;
int _map[MAXN][MAXN],vis[MAXN][MAXN];
int tail,head;
int ord[5];
struct NODE
{
	int x,y;
};
NODE _array[MAXN*MAXN*MAXN];
NODE Nxt(NODE a,int c)
{
	NODE b;
	if(ord[c]==1)
	{
		b.x=a.x-1;
		b.y=a.y;
	}
	if(ord[c]==2)
	{
		b.x=a.x+1;
		b.y=a.y;
	}
	if(ord[c]==3)
	{
		b.x=a.x;
		b.y=a.y+1;
	}
	if(ord[c]==4)
	{
		b.x=a.x;
		b.y=a.y-1;
	}
}
int hx,hy;
int px,py; 
NODE helen;
int main()
{
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		char a[30];
		scanf("%s",a);
		for(int j=1;j<=M;j++)
		{
			if(a[j-1]=='.')
			{
				_map[i][j]=1;
			}
			if(a[j-1]=='#')
			{
				_map[i][j]=2;
			}
			if(a[j-1]=='!')
			{
				_map[i][j]=0;
			}
			if(a[j-1]=='P')
			{
				tail++;
				_array[tail].x=i;
				_array[tail].y=j;
				px=i;
				py=j;
			}
			if(a[j-1]=='H')
			{
				hx=i;
				hy=j;
				helen.x=i;
				helen.y=j;
			}
		}
	}
	for(int i=1;i<=4;i++)
	{
		char opt;
		scanf("%c",&opt);
		if(opt=='N')
		{
			ord[i]=1;
		}
		if(opt=='S')
		{
			ord[i]=2;
		}
		if(opt=='E')
		{
			ord[i]=3;
		}
		if(opt=='W')
		{
			ord[i]=4;
		}
	}
	printf("%d",(abs(px-hx)+abs(py-hy))/2);
//	while(l<r)
//	{
//		head++;
//		if(_array[head].x==helen.x&&_array[head].y==helen.y)
//		int Nowx=_array[head].x;
//		int Nowy=_array[head].y;
//		if(vis[Nowx][Nowy])
//	}
	return 0;
}
