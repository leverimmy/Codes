#include<cstdio>
#define ri register int
inline int read()
{
	ri x=0;
	register char ch=getchar();
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
int t[105],num[55],cnt,pri[100][55],n,l;
inline void dfs(ri step,ri max,ri left)
{
	if(step==n+1)
	{
		++cnt;
		for(ri i=1;i<=n;++i)
		{
			pri[cnt][i]=num[i];
		}
	}
	for(ri i=left;i>=max;--i)
	{
		bool flag=true;
		for(ri j=1;j<step;++j)
		{
			if(t[i+num[j]]==0)
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			num[step]=i;
			for(ri j=1;j<step;++j)
			{
				--t[i+num[j]];
			}
			dfs(step+1,i,left-i);
			num[step]=0;
			for(ri j=1;j<step;++j)
			{
				++t[i+num[j]];
			}
		}
	}
	return;
}
int main()
{
	freopen("city.in","r",stdin); 
	freopen("city.out","w",stdout); 
	n=read(),l=0;
	if(n==3)
	{
		ri a=read(),b=read(),c=read(),all=(a+b+c)>>1,t;
		if(a<b)
		{
			t=b,b=a,a=t;
		}
		if(a<c)
		{
			t=c,c=a,a=t;
		}
		if(b<c)
		{
			t=c,c=b,b=t;
		}
		printf("1\n%d %d %d",all-a,all-b,all-c);
		return 0;
	}
	for(ri i=1,j;i<=n*(n-1)/2;++i)
	{
		j=read();
		++t[j];
		l+=j;
	}
	dfs(1,0,l/(n-1));
	printf("%d\n",cnt);
	for(ri i=1;i<=cnt;++i)
	{
		for(ri j=1;j<=n;++j)
		{
			printf("%d ",pri[i][j]);
		}
		puts("");
	}
}
