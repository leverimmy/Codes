#include<cstdio>
#include<algorithm>
#define ri register int
#define rc register char
#define g() getchar()
inline int read(){
	ri x=0;
	rc ch=g();
	while(ch>'9' || ch<'0')ch=g();
	while(ch<='9' && ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=g();
	return x;}
int all,num[110],sum=1000000000,n,m;
int map[110][40];
inline void dfs(ri now,ri ans,ri step)
{
	if(ans>=sum)
	{
		return;
	}
	if(step==m)
	{
		if(now!=n+1)
		{
			return;
		}
		if(sum>ans)
		{
			sum=ans;
		}
		return;
	}
	if(map[now][step]<ans)
	{
		return;
	}
	map[now][step]=ans;
	if(now>n)
	{
		return;
	}
	ri mul=n-now,al=0;
	for(ri i=now;i<=n;++i)
	{
		al+=num[i];
		if(n-i>=m-step-1)
		{
			dfs(i+1,ans+mul*al,step+1);
		}
	}
	return;
}
int main()
{
	freopen("pb.in","r",stdin);
	freopen("pb.out","w",stdout);
	n=read(),m=read();
	for(ri i=0;i<n;++i)
	{
		all+=(num[i]=read());
		for(ri j=0;j<m;++j)
		{
			map[i][j]=1000000000;
		}
	}
	std::sort(num,num+n);
	dfs(0,0,0);
	printf("%.4lf",(double)sum/(double)all);
}
