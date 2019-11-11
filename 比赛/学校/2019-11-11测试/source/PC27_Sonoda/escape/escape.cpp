#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
namespace Sonoda
{
	template<typename T> void swap(T &a,T &b)
	{
		T t;
		t=a;
		a=b;
		b=t;
	}
	template<typename T> T GCD(T a,T b)
	{
		if(b==0)
		{
			return a;
		}
		return GCD(b,a%b);
	}
	template<typename T>T Qpow(T a,T b,T p)
	{
		T res=1;
		while(b)
		{
			if(b&1)
			{
				res*=a;
				res%=p;
				b--;
			}
			else
			{
				a*=a;
				a%=p;
				b>>=1;
			}
		}
		return res;
	}
	template <typename T> void Ex_GCD(T a,T b,T &x,T &y)
	{
		if(b==0)
		{
			x=1;
			y=0;
			return;
		}
		Ex_GCD(b,a%b,x,y);
		T t=x;
		x=y;
		y=t-a/b*y;
	}
	template<typename T> inline T read()
	{
		T num = 0, w = 1;
		char c = 0;
		while (c != '-' && !isdigit(c)) c = getchar();
		if (c == '-') w = -1, c = getchar();
		while (isdigit(c)) num = num * 10 + c - '0', c = getchar();
		return num * w;
	}
	template<typename T> inline void write(T x)
	{
		if (x < 0) putchar('-'), x = -x;
		if (x / 10) write(x / 10);
		putchar(x % 10 + '0');
	}
}
const int MAXN=505;
struct NODE
{
	int x,y;
};
NODE _array[MAXN*MAXN<<4];
int l,r;
int ans;
int _map[MAXN][MAXN];
int dis[MAXN][MAXN];
bool vis[MAXN][MAXN];
char a;
int sx,sy,tx,ty;
int N,M;
void BFS()
{
	while(l<r)
	{
		l++;
		int Nowx=_array[l].x;
		int Nowy=_array[l].y;
		if(Nowx+1<=N&&dis[Nowx+1][Nowy]>dis[Nowx][Nowy]+1)
		{
			dis[Nowx+1][Nowy]=dis[Nowx][Nowy]+1;
			r++;
			_array[r].x=Nowx+1;_array[r].y=Nowy;
		}
		if(Nowx-1>=1&&dis[Nowx-1][Nowy]>dis[Nowx][Nowy]+1)
		{
			dis[Nowx-1][Nowy]=dis[Nowx][Nowy]+1;
			r++;
			_array[r].x=Nowx-1;_array[r].y=Nowy;
		}
		if(Nowy+1<=M&&dis[Nowx][Nowy+1]>dis[Nowx][Nowy]+1)
		{
			dis[Nowx][Nowy+1]=dis[Nowx][Nowy]+1;
			r++;
			_array[r].x=Nowx;_array[r].y=Nowy+1;
		}
		if(Nowy-1>=1&&dis[Nowx][Nowy-1]>dis[Nowx][Nowy]+1)
		{
			dis[Nowx][Nowy-1]=dis[Nowx][Nowy]+1;
			r++;
			_array[r].x=Nowx;_array[r].y=Nowy-1;
		}
	}
}
bool Check(int x)
{
	while(l<r)
	{
		l++;
		int Nowx=_array[l].x;
		int Nowy=_array[l].y;
		if(Nowx==tx&&Nowy==ty)
		{
			return true;
		}
		if(Nowx+1<=N&&dis[Nowx+1][Nowy]>=x&&(!vis[Nowx+1][Nowy]))
		{
			r++;
			_array[r].x=Nowx+1;_array[r].y=Nowy;
			vis[Nowx+1][Nowy]=1;
		}
		if(Nowx-1>=1&&dis[Nowx-1][Nowy]>=x&&(!vis[Nowx-1][Nowy]))
		{
			r++;
			_array[r].x=Nowx-1;_array[r].y=Nowy;
			vis[Nowx-1][Nowy]=1;
		}
		if(Nowy+1<=M&&dis[Nowx][Nowy+1]>=x&&(!vis[Nowx][Nowy+1]))
		{
			r++;
			_array[r].x=Nowx;_array[r].y=Nowy+1;
			vis[Nowx][Nowy+1]=1;
		}
		if(Nowy-1>=1&&dis[Nowx][Nowy-1]>=x&&(!vis[Nowx][Nowy-1]))
		{
			r++;
			_array[r].x=Nowx;_array[r].y=Nowy-1;
			vis[Nowx][Nowy-1]=1;
		}
	}
	return false;
}
int main()
{
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	memset(dis,INF,sizeof(dis));
	N=Sonoda::read<int>();
	M=Sonoda::read<int>();
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			cin>>a;
			if(a=='+')
			{
				_map[i][j]=2;
				dis[i][j]=0;
				r++;
				_array[r].x=i;
				_array[r].y=j;
			}
			if(a=='.')
			{
				_map[i][j]=1;
			}
			if(a=='V')
			{
				sx=i;
				sy=j;
			}
			if(a=='J')
			{
				tx=i;
				ty=j;
			}
		}
	}
	BFS();
	int le=0,ri=max(N,M);
	while(le<ri)
	{
		int mid=(le+ri)>>1;
		l=0,r=0;
		r++;
		_array[r].x=sx;
		_array[r].y=sy;
		memset(vis,false,sizeof(vis));
		if(Check(mid))
		{
			le=mid+1;
			ans=max(ans,mid);
		}
		else
		{
			ri=mid-1;
		}
	}
	printf("%d",ans);
	return 0;
}

