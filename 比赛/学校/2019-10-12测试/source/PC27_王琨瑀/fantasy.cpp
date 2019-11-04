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
const int MAXN=50005;
int from[MAXN],to1[MAXN],to2[MAXN];
int N,M;
int ind[MAXN],outd[MAXN];
bool dto1[MAXN];
void DFS(int now)
{
	if(now==M)
	{
		memset(ind,0,sizeof(ind));
		memset(outd,0,sizeof(outd));
		for(int i=1;i<=M;i++)
		{
			outd[from[i]]++;
			if(dto1[i])
			{
				ind[to1[i]]++;
			}
			else
			{
				ind[to2[i]]++;
			}
		}
		for(int i=1;i<=N;i++)
		{
			if(ind[i]!=outd[i])
			{
				return;
			}
		}
		for(int i=1;i<=M;i++)
		{
			printf("%d",!dto1[i]);
		}
		exit(0);
	}
	dto1[now+1]=1;
	DFS(now+1);
	dto1[now+1]=0;
	DFS(now+1);
}


int main()
{
	freopen("fantasy.in","r",stdin);
	freopen("fantasy.out","w",stdout);
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++)
	{
		scanf("%d%d%d",from+i,to1+i,to2+i);		
	}
	DFS(0);
	return 0;
}

