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
const int MAXN=1000005;

struct NUM
{
	int val,pos;
};
NUM num[MAXN];

bool cmp(const NUM &a,const NUM &b)
{
	if(a.val==b.val)
	{
		return a.pos<b.pos;
	}
	return a.val<b.val;
}
int book[MAXN];
int now[MAXN];
int ans[MAXN];
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	int N=Sonoda::read<int>();
	for(int i=1;i<=N;i++)
	{
		num[i].val=Sonoda::read<int>();
		num[i].pos=i;
		book[num[i].val]++;
	}
	for(int i=2;i<=N;i++)
	{
		if(book[i]>book[i-1])
		{
			printf("-1");
			return 0;
		}
	}
	for(int i=1;i<=N;i++)
	{
		now[i]=1;
	}
	sort(num+1,num+1+N,cmp);
	for(int i=1;i<=N;i++)
	{
		ans[num[i].pos]=now[num[i].val];
		now[num[i].val]++;
	}
	int out=0;
	for(int i=1;i<=N;i++)
	{
		out=max(out,ans[i]);
	}
	printf("%d\n",out);
	for(int i=1;i<=N;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}

