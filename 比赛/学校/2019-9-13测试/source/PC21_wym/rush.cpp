#include<bits/stdc++.h>
using namespace std;
int n,m,ans,t1,t2;
bool lt[100010],rt[100010],up[100010],dn[100010];
inline int read()
{
    int x=0,f=1;
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
	freopen("rush.in","r",stdin);
	freopen("rush.out","w",stdout);
	n=read();
	m=read();
	ans=4*n;
	for(int i=1;i<=m;i++)
	{
		t1=read(),t2=read();
		if(!up[t2])
			up[t2]=true,ans--;
		if(!dn[t2])
			dn[t2]=true,ans--;
		if(!lt[t1])
			lt[t1]=true,ans--;
		if(!rt[t1])
			rt[t1]=true,ans--;
	}
	if((n&1)&&(!dn[n/2+1])&&(!rt[n/2+1]))
	{
		cout<<ans/2-1;
		return 0;
	}
	cout<<ans/2;
	return 0;
}
