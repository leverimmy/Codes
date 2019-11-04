#include<cstdio>
#include<algorithm>
#define mini(a,b) ((a)<(b)?(a):(b))
#define in inline
#define ri register int
#define rc register char
#define N 50005
in int read()
{
	ri x=0,p=1;
	rc ch=getchar();
	while(ch<'0' || ch>'9')
	{
		ch=getchar();
		if(ch=='-')
		{
			p=-1;
		}
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	}
	return x*p;
}
int n,m1,m2,h[N],minl[N],num[N];
in bool cmp(const int &a,const int &b)
{
	return a>b;
}
int main()
{
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(ri i=1;i<=n;++i)
	{
		h[i]=read();
	}
	ri x,p1=0,p2=0;
	for(ri i=1;i<=n;++i)
	{
		if(h[i-1]<=h[i])
		{
			++minl[0],minl[minl[0]]=h[i];
		}
		else
		{
			x=std::upper_bound(minl+1,minl+minl[0]+1,h[i])-minl-1,minl[x]=h[i];
		}
	}
	p1=n-minl[0],minl[0]=0;
	for(ri i=n;i>=1;--i)
	{
		if(h[i+1]<=h[i])
		{
			++minl[0],minl[minl[0]]=h[i];
		}
		else
		{
			x=std::upper_bound(minl+1,minl+minl[0]+1,h[i])-minl,minl[x]=h[i];
		}
	}
	p2=n-minl[0],printf("%d\n",mini(p1,p2));
	return 0;
}
