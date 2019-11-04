#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#define M 50100
#define LL long long
#define int long long
const int inf=0x3f3f3f3f;
const double eps=1e-9;
const int mod=998244353;
using namespace std;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while (!isdigit(s)){if (s=='-') f=-1; s=getchar();}
	while (isdigit(s)){x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	return x*f;
}
int n,m,t,type;
struct matrix{
	LL m[102][102];
	inline void build(){
		for (int i=1;i<=2;i++)
		{
			m[i][i]=1;
		} 
	};
	inline void in(){
		memset(m,0,sizeof(m));
	}
	inline void init(){
		m[1][1]=1,m[1][2]=1,m[2][1]=1,m[2][2]=0;
	}
};
matrix operator *(const matrix &x,const matrix &y)
{
	matrix c;
	c.in();
	for (int k=1;k<=2;k++)
	{
		for (int i=1;i<=2;i++)
		{
			for (int j=1;j<=2;j++)
			{
				c.m[i][j]=(c.m[i][j]+x.m[i][k]*y.m[k][j]%mod)%mod;
			}
		}
	}
	return c;
}
matrix a,e,ans;
namespace solve1{
	signed main(void){
		while(t--){
			n=read();
			int tmp=n;
			a.init();
			e.m[1][1]=1,e.m[2][1]=1;
			while (n!=0){
				if (n&1) e=e*a;
				a=a*a;
				n>>=1;
			}
			printf("%lld\n",e.m[1][1]);
		}
	}
}
namespace solve2{
	signed main(void){
		while (t--){
			n=read();
			int ans=(((n+1)%mod)*((n+1)%mod))%mod;
			printf("%lld\n",ans);
		}
	}
}
signed main(void)
{
	freopen("");
	t=read(),type=read();
	if (type==1) solve1::main();
	else solve2::main();
	return 0;
}


