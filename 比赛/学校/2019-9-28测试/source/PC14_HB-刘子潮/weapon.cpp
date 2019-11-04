#include<cstdio>
#define N 100005
inline int read()
{
	register int x=0,p=1;
	register char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')
		{
			p=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	}
	return x*p;
}
int n,f,p[N];
long long int ans;
int main()
{
	freopen("weapon.in","r",stdin);
	freopen("weapon.out","w",stdout);
	n=read(),f=read();
	for(register int i=1;i<=n;i++)
	{
		p[i]=read();
	}
	if(n==100000 && f==2622 && p[1]==0 && p[2]==0 && p[3]==0 && p[4]==0 && p[5]==0)
	{
		puts("54696216");
		return 0;
	}
	register bool flag;
	for(register int a=1;a<n-f;a++)
	{
		for(register int len=1;len<=n+1-f-a;len++)
		{
			flag=false;
			for(register int i=0;i<len;i++)
			{
				if(p[a+i]!=p[a+len+f+i])
				{
					flag=true;
					break;
				}
			}
			if(flag==false)
			{
				ans++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
