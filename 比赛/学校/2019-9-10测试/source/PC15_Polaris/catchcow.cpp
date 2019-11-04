#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<stack>
#include<cctype>
using namespace std;
const int inf=0x3f3f3f3f;
const int Maxn=202000;
int n,k,ans;
inline int read()
{
	int x=0,f=1;char s=getchar();
	while (!isdigit(s))
	{
		if (s=='-')
		{
			f=-1;
		}
		s=getchar();
	}
	while (isdigit(s))
	{
		x=(x<<1)+(x<<3)+(s^48);
		s=getchar();
	}
	return x*f;
}
int main()
{
	freopen("catchcow.in","r",stdin);
	freopen("catchcow.out","w",stdout);
	n=read();
	k=read();
	if (n>=k)
	{
		printf("%d",n-k);
		return 0;
	}
	int now=k;
	while (now>n)
	{
		if (now&1)
		{
			ans++;
		}
		now>>=1;
		ans++;
	}
	ans--;
	int t=now<<1;
	if (t-n>n-now+1)
	{
		ans+=(n-now+1);
	}
	else
	{
		ans+=t-n;
	}
	printf("%d",ans);
	return 0;
}
