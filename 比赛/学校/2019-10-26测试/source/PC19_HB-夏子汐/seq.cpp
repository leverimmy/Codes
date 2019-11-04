#include<cstdio>
#include<cmath>
#define ri register ll
#define ll long long
inline ll read()
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
inline ll gcd(ri a,ri b)
{
	return b?gcd(b,a%b):a;
}
inline int work(ri a1,ri a2)
{
	if(a2==0)
	{
		return 1;
	}
	if(a1<a2)
	{
		ri t=a1;
		a1=a2;
		a2=t;
	}
	if(a2==1)
	{
		return a1+1;
	}
	if(a1==a2 || !a2)
	{
		return 2;
	}
	return work(a2,a1%a2)+a1/a2;
}
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	ri a1=read(),a2=read();
	if(!a1)
	{
		if(a2)
		{
			printf("2");
		}
		else
		{
			printf("1");
		}
		return 0;
	}
	else
	{
		if(!a2)
		{
			printf("2");
			return 0;
		}
	}
	if(a1==a2)
	{
		printf("2");
		return 0;
	}
	printf("%d",work(a1,a2));
	return 0;
}
