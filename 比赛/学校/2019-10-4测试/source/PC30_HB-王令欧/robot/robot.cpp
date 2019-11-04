#include <cstdio>
#include <iostream>
using namespace std;
int n,m1,m2;
const int maxn=50001;
int a[maxn],d[maxn];
inline int read()
{
    register int x=0,f=0;
    register char ch=getchar();
    while(ch<'0' || ch>'9')
        f|=ch=='-',ch=getchar();
    while(ch>='0' && ch<='9')
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
int min(int x, int y)
{
    return x<y?x:y;
}
int main()
{
    freopen("robot.in","r",stdin);
    freopen("robot.out","w",stdout);
    n=read(),m1=read(),m2=read();
    for(register int i=1;i<=n;i++)
        a[i]=read();
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    if(n==2)
    {
        cout<<0;
        return 0;
    }
	int ans1=0,ans2=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i]<a[i-1])
		{
			a[i]=a[i-1];
			ans1+=m1;
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]>a[i-1])
		{
			a[i]=a[i-1];
			ans2+=m2;
		}
	}
	cout<<min(ans1,ans2);
	return 0;
}