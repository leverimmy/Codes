#include<cstdio>
#include<algorithm>
#define N 100005
#define ri register int
inline int read()
{
	register char ch=getchar();
	ri x=0;
	while(ch<'0' || ch>'9')
	{
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x;
}
int fa[N],dis[N];
inline int find(ri x)
{
	if(fa[x]==x)
	{
		return x;
	}
	ri f=find(fa[x]);
	dis[x]=dis[fa[x]]+1;
	return fa[x]=f;
}
int a[N];
struct que
{
	int p,k,num;
	inline bool operator<(register const que &a)const
	{
		if(k==a.k)
		{
			return p<a.p;
		}
		return k<a.k;
	}
}w[N];
int n,ans[N];
int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	n=read();
	for(ri i=1;i<=n;++i)
	{
		a[i]=read();
	}
	ri m=read();
	for(ri i=0,p,k;i<m;++i)
	{
		p=read(),k=read();
		w[i]=(que){p,k,i};
	}
	std::sort(w,w+m);
	for(ri i=0,p,k;i<m;++i)
	{
		p=w[i].p,k=w[i].k;
		if(p==w[i-1].p && k==w[i-1].k)
		{
			ans[w[i].num]=ans[w[i-1].num];
		}
		else
		{
			ri s=0;
			while(p<=n)
			{
				++s;
				p+=a[p]+k;
			}
			ans[w[i].num]=s;
		}
	}
	for(ri i=0;i<m;++i)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}
