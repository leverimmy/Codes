#include<bits/stdc++.h>
#define endline putchar('\n')
#define whitespace putchar(' ')
using namespace std;
long long n,typ,t,matsiz;
const long long mod=998244353;
struct matrix
{
	long long cont[10][10];
	matrix operator * (matrix &b)
	{
		matrix ret;
		for(int i=1;i<=matsiz;++i)
			for(int j=1;j<=matsiz;++j)
				ret.cont[i][j]=0;
		for(int i=1;i<=matsiz;++i)
			for(int j=1;j<=matsiz;++j)
				for(int k=1;k<=matsiz;++k)
					ret.cont[i][j]=(ret.cont[i][j]+(cont[i][k]*b.cont[k][j])%mod)%mod;
		return ret;
	}
}bas,un,trans;
matrix __matrix_quickpow(matrix x,long long y)
{
	matrix tmp=un;
	while(y)
	{
		if(y bitand 1)
			tmp=x*tmp;
		x=x*x;
		y>>=1;
	}
	return tmp;
}
inline long long read()
{
    long long x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
	{
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void outp(long long o1)
{
	if(o1<0)
		putchar('-'),o1=-o1;
	long long o2=o1/10;
	if(o2)
		outp(o2);
	putchar((o1-(o2<<1)-(o2<<3))^48);
}
namespace __typ1
{
	void solve()
	{
		matsiz=2;
		for(int i=1;i<=matsiz;++i)
			un.cont[i][i]=1;
		bas.cont[1][1]=1,bas.cont[1][2]=1,bas.cont[2][1]=1;
		trans.cont[1][1]=2;
		trans.cont[2][1]=1;
		while(t--)
		{
			n=read();
			if(n==1)
			{
				putchar('1');
				endline;
				continue;
			}
			matrix ans=__matrix_quickpow(bas,n-2);
			ans=ans*trans;
//			for(int i=1;i<=matsiz;i++)
//			{
//				for(int j=1;j<=matsiz;j++)
//					outp(ans.cont[i][j]),whitespace;
//				endline;
//			}
			outp(ans.cont[1][1]);
			endline;
		}
	}
}
namespace __typ2
{
	
}
int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	t=read(),typ=read();
	if(typ==1)
		__typ1::solve();
//	else
//		__typ2::solve();
}
