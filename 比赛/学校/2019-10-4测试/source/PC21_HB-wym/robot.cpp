#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
    long long x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
	{
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void outp(long long o1)
{
	if(o1<0)
		putchar('-'),o1=-o1;
	long long o2=o1/10;
	if(o2)
		outp(o2);
	putchar((o1-(o2<<1)-(o2<<3))^48);
}
long long n,m1,m2,h[50010],ans,now,fd[50010],fu[50010],idx1,idx2;
bool flag;
void _50pts()
{
	fd[++idx1]=h[1];
	fu[++idx2]=h[1];
	for(int i=2;i<=n;i++)
	{
		int kd=upper_bound(fd+1,fd+idx1+1,h[i])-fd;
		fd[kd]=h[i];
		if(kd>idx1)
			++idx1;
		int ku=upper_bound(fu+1,fu+idx2+1,h[i],greater<int>())-fu;
		fu[ku]=h[i];
		if(ku>idx2)
			++idx2;
	}
	outp(min(n-idx1,n-idx2));
	return;
}
bitset<50010>b;
void _25pts()
{
	bitset<50010>f[50010],e[50010],t;
	for(int i=1;i<=n;i++)
	{
		b[i-1]=(bool)--h[i];
	}
	for(int i=0;i<n;i++)
		e[i+1][i]=1;
	int ans=50010/4;
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1]|e[i];
		t=f[i]^b;
		ans=min(ans,(int)t.count());
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1]|e[n-i+1];
		t=f[i]^b;
		ans=min(ans,(int)t.count());
	}
	outp(ans);
	return;
}
int main()
{
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	n=read(),m1=read(),m2=read();
	if(n==1||n==2)
	{
		outp(0);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		h[i]=read();
		if(h[i]>2)
			flag=true;
	}
	if(flag)
	{
		_50pts();
		return 0;
	}
	_25pts();
	return 0;
}
