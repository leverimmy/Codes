#include<bits/stdc++.h>
using namespace std;
long long n,a[100010],m;
long long p,k,ans;
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
int main()
{
 	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		ans=0;
		p=read(),k=read();
		while(p<=n)
			p=p+a[p]+k,ans++;
		printf("%lld\n",ans);
	}
}
