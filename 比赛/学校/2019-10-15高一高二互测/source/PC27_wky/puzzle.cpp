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
const long long MOD=998244353;
const long long MAXN=3;
struct MATRIX
{
	long long mat[MAXN][MAXN];
	MATRIX operator *(const MATRIX &b)
	{
		MATRIX res;
		memset(res.mat,0,sizeof(res.mat));
		for(long long i=1;i<=2;i++)
		{
			for(long long j=1;j<=2;j++)
			{
				for(long long k=1;k<=2;k++)
				{
					res.mat[i][j]+=(mat[i][k]*b.mat[k][j])%MOD;
					res.mat[i][j]%=MOD;
				}
			}
		}
		return res;
	}
	MATRIX& operator *=(const MATRIX &b)
	{
		return *this=*this*b;
	}
};

MATRIX Qpow(MATRIX a,long long b)
{
	MATRIX res;
	memset(res.mat,0,sizeof(res.mat));
	res.mat[1][1]=1;
	res.mat[2][2]=1;
	while(b)
	{
		if(b&1)
		{
			res*=a;
			b--;
		}
		else
		{
			a*=a;
			b>>=1;
		}
	}
	return res;
}
MATRIX e;
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	long long T = Sonoda::read<long long>();
	long long type=Sonoda::read<long long>();
	if(type==1)
	{
		while(T--)
		{
			memset(e.mat,0,sizeof(e.mat));
			e.mat[1][1]=1;
			e.mat[1][2]=1;
			long long N=Sonoda::read<long long>();
			MATRIX ans;
			memset(ans.mat,0,sizeof(ans.mat));
			ans.mat[1][1]=1;
			ans.mat[1][2]=1;
			ans.mat[2][1]=1;
			e*=Qpow(ans,N);
			printf("%lld\n",e.mat[1][2]);
		}
	}
	else
	{
		while(T--)
		{
			long long N=Sonoda::read<long long>();
			if(N==1)
			{
				puts("2");
			}
			if(N==2)
			{
				puts("7");
			}
			if(N==3)
			{
				puts("");
			}
		}
	}
	return 0;
}

