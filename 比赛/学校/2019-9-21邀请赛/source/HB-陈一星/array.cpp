#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<cctype>
#define M 602000
using namespace std;
const int inf=0x3f3f3f3f;
inline int read()
{
	int x=0,f=1;char s=getchar();
	while (!isdigit(s))
	{
		if(s=='-') f=-1;
		s=getchar();
	}
	while (isdigit(s))
	{
		x=(x<<1)+(x<<3)+(s^48);
		s=getchar();
	}
	return x*f;
}

int n,m,pos[M],a[M],k,p;

inline void dfs(int a,int step)
{
	if (a>n)
	{
		printf("%d\n",step);
		return;
	}
	dfs(pos[a]+k,step+1);
}

signed main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		pos[i]=a[i]+i;
	}
	m=read();
	for (int i=1;i<=m;i++)
	{
		p=read(),k=read();
		dfs(p,0);
	}
	return 0;
}
