#include<cstdio>
#include<algorithm>
#define ri register int
#define rc register char
#define g() getchar()
inline int max(ri const &a,ri const &b){return a>b?a:b;}
inline int read(){
	ri x=0;rc ch=g();
	while(ch>'9' || ch<'0')ch=g();
	while(ch<='9' && ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=g();
	return x;}
int h[200010],l[200010],pre[200010],ans;
int main()
{
	freopen("gfw.in","r",stdin);
	freopen("gfw.out","w",stdout);
	ri n=read();
	for(ri i=1;i<=n;++i)
	{
		h[i]=read();
		if(h[i]>h[i-1])
		{
			l[i]=l[i-1]+1;
			pre[i]=pre[i-1];
		}
		else
		{
			l[i]=1;
			pre[i]=i;
		}
		ans=max(ans,l[i]);
	}
	for(ri i=2;i<=n;++i)
	{
		for(ri j=1;j<pre[i];++j)
		{
			if(h[j]<h[pre[i]])
			{
				ans=max(ans,l[i]+l[j]);
			}
		}
	}
	printf("%d",ans);
	return 0;
}
