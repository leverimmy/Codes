#include<cstdio>
#include<algorithm>
#define ri register int
#define rc register char
#define in inline
#define gc getchar
#define maxi(a,b) ((a)>(b)?(a):(b))
#define N 200005
in int read()
{
	ri x=0;
	rc ch=gc();
	while(ch<'0' || ch>'9')
	{
		ch=gc();
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0',ch=gc();
	}
	return x;
}
int n,h[N],f[N][2],len,ans;
int main()
{
	freopen("gfw.in","r",stdin);
	freopen("gfw.out","w",stdout);
	n=read();
	for(ri i=1;i<=n;++i)
	{
		h[i]=read();
	}
	for(ri i=1;i<=n;++i)
	{
		f[i][0]=1;
	}
	for(ri i=1;i<=n;++i)
	{
		if(h[i-1]<h[i])
		{
			f[i][0]=maxi(f[i][0],f[i-1][0]+1),f[i][1]=maxi(f[i][1],f[i-1][1]+1);
		}
		for(ri j=1;j<i;++j)
		{
			if(h[j]<h[i])
			{
				f[i][1]=maxi(f[i][1],f[j][0]+1);	
			}
		}
		ans=maxi(ans,f[i][0]),ans=maxi(ans,f[i][1]);
	}
	printf("%d",ans);
	return 0;
}
