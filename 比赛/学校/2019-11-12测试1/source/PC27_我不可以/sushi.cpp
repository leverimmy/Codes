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
const int MAXN=2000005;
char a[MAXN];
int sum,num,ans;
int main()
{
	freopen("sushi.in","r",stdin);
	freopen("sushi.out","w",stdout);
	int T=Sonoda::read<int>();
	while(T--)
	{
		sum=0;
		num=0;
		scanf("%s",a);
		int len=strlen(a);
		int out=INF;
		for(int i=0;i<len;i++)
		{
			a[i+len]=a[i];
			if(a[i]=='B')
			{		
				sum+=i;	
				num++;
			}
		}
		if(sum==0)
		{
			printf("0");
			continue;
		}
		int div=len/2;
		for(int pos=div+1;pos<=div+len;pos++)
		{
			if(pos<div)
			{
				pos+=len;
			}
			int k=0,e=0;
			ans=0;
			if(a[pos]=='B')
			{
				k=1;
			}
			for(int now=0;now<div;now++)
			{
				if(a[pos-now-1]=='B')
				{
					ans+=now+1-k;
					k++;
				}
			}
			e=k;
			k=1;
			for(int now=0;now<div;now++)
			{
				if(a[pos+now+1]=='B')
				{
					ans+=now+1-k;
					k++;
				}
			}
			e=max(e,k);
			if(len%2==0)
			{
				if(a[pos+div]=='B')
				{
					ans+=div-e;
				}
			}
			out=min(ans,out);
		}
		printf("%d\n",out);
	}
	return 0;
}

