#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<queue>
#include<vector>
#include<map>
#define ll long long
using namespace std;
inline ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
struct node
{
	ll t,s;
}a[100001];
bool b[100001];
int main()
{
	freopen("lie.in","r",stdin);
	freopen("lie.out","w",stdout);
	ll n=read();
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		a[i].t=read();
		a[i].s=read();
		if(a[i].s+a[i].t>=n)
		{
			ans++;
			b[i]=false;
		}
	}
	printf("%d\n",ans);
	return 0;
}

