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
vector <int> a;
int main()
{
	freopen("unhappy.in","r",stdin);
	freopen("unhappy.out","w",stdout);
	int cnt=0;
	int r=0;
	int N=Sonoda::read<int>();
	int ming=Sonoda::read<int>();
	for(int i=1;i<=N;i++)
	{
		char opt;
		cin>>opt;
		int k=Sonoda::read<int>();
		if(opt=='I')
		{
			if(k<ming)
			{
				continue;
			}
			vector <int>::iterator now=lower_bound(a.begin(),a.end(),k);
			a.insert(now,k);
			r++;
		}
		if(opt=='A')
		{
			for(vector<int>::iterator i=a.begin();i!=a.end();i++)
			{
				*i+=k;
			}
		}
		if(opt=='S')
		{
			vector<int>::iterator n=a.end();
			for(vector<int>::iterator i=a.begin();i!=n;i++)
			{
				*i-=k;
				if(*i<ming)
				{
					a.erase(i);
					i--;
					cnt++;
					r--;
				}
			}
		}
		if(opt=='F')
		{
			if(k>r)
			{
				printf("-1\n");
				continue;
			}
			k=a.size()-k;
			printf("%d\n",a[k]);
		}
	}
	printf("%d",cnt);
	return 0;
}

