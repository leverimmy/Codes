#include<bits/stdc++.h>
#define ll long long
#define rgi register int 
#define rgl register ll
#define maxn 100005
#define mod 998244353
using namespace std;

void read(rgi&x)
{
	x=0;
	rgi f=1;
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
	x*=f;
}

int a[maxn],ans[maxn][101];
int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	rgi n,m,p,k,ansn;
	read(n);
	for(rgi i=1;i<=n;++i)
		read(a[i]);
	for(rgi i=0;i<=100;++i)
		for(rgi j=n;j>0;--j)
			ans[j][i]=(j+a[j]+i>n) ? 1 : ans[j+a[j]+i][i]+1;
	read(m);
	for(;m;--m)
	{
		read(p),read(k);
		if(k<=100)
			printf("%d\n",ans[p][k]);
		else
		{
			ansn=0;
			while(p<=n)
				p+=a[p]+k,++ansn;
			printf("%d\n",ansn);
		}
	}
	return 0;
}
