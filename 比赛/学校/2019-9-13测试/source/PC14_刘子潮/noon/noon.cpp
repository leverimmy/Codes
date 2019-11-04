#include<cstdio>
#include<cstring>
inline int read()
{
	register int x=0;
	register char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+ch-'0',ch=getchar();
	}
	return x;
}
const int N=100005;
int n,m;
long long int high[N];
inline int getnum()
{
	register int ans=0,maxm=1;
	register long long int maxz=high[1];
	if(maxz>0)
	{
		ans++;
	}
	for(register int i=2;i<=n;++i)
	{
		if(high[i]>0 && maxz*i<maxm*high[i])
		{
			maxz=high[i],maxm=i,++ans;
		}
	}
	return ans;
}
int main()
{
	freopen("noon.in","r",stdin);
	freopen("noon.out","w",stdout);
	memset(high,-1,sizeof(high));
	n=read(),m=read();
	register int x,y;
	for(register int i=1;i<=m;++i)
	{
		x=read(),y=read();
		high[x]=y;
		printf("%d\n",getnum());
	}
	return 0;
}
