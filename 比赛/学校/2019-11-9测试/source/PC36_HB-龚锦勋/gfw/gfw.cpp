#include <iostream>
#include <cstdio>

using namespace std;

long read()
{
	long x=0,y=1;char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')y=-1;
		c = getchar();
	}
	while(c>='0'&&c<='9')
		x = x*10+c-'0',c=getchar();
	return (x*y);
}

int n,dl,dr;
long h[200000],ans;

void ktl()
{
	long nm=0,nc=0,qs=0;
	for(int i=0;i<n;i++)
	{
		if(i>=dl && i<=dr)
			continue;
		if(nm<h[i])
		{
			nm = h[i];
			nc++;
			if(qs+nc+n-i <ans)
				return;
		}
		else
		{
			qs = max(qs,nc);
			nm = h[i];
			nc=1;
		}
	}
	qs = max(qs,nc);
	ans = max(ans,qs);
}

int main()
{
	freopen("gfw.in","r",stdin);
	freopen("gfw.out","w",stdout);
	
	n = read();
	for(int i=0;i<n;i++)
	{
		h[i] = read();
	}
	dl=dr=-1;
	ktl();
	for(dl=0;dl<n;dl++)
		for(dr=dl+1;dr<n;dr++)
			ktl();
	printf("%d",ans);
	return 0;
}

