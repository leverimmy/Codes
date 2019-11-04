#include <iostream>
#include <cstdio>
#define mymax(p,q) ((p)>=(q)?(p):(q))
#define lowbit(p) ((p)&(-p))
#define rgi register long long
#define int long long
using namespace std;
const int maxn=1000005;
int n,a,ans,c[maxn];
inline void change(int i,int x)
{
	for(;i<=n;i+=lowbit(i))
		c[i]+=x;
}
inline int sum(int i)
{
	int ret=0;
	for(;i;i-=lowbit(i))
		ret+=c[i];
	return ret;
}
inline int check(int l,int r)
{
	return sum(r)-sum(l-1);
}
inline int doit()
{
	int tans=-2147483647,ti,tj;
	for(rgi i=1;i<=n;++i)
		for(rgi j=i;j<=n;++j)
		{
			int pp=check(i,j);
			if(pp>tans)
				tans=pp,ti=i,tj=j;
		}
	if(tans==-2147483647)
		return 0;
	for(rgi i=ti;i<=tj;++i)
	{
		int ppo=check(i,i);
		change(i,-2147483647-ppo);
	}
	return tans;
}
signed main()
{
	ios::sync_with_stdio(false);
	freopen("jx.in","r",stdin);
	freopen("jx.out","w",stdout);
	cin>>n;
	for(rgi i=1;i<=n;++i)
	{
		cin>>a;
		change(i,a);
	}
	ans+=doit(),ans+=doit(),ans+=doit();
	cout<<ans<<endl;
	return 0; 
}

