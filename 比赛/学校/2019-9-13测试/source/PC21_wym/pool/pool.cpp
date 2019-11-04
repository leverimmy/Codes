#include<bits/stdc++.h>
using namespace std;
long long T,k,l,r,qwq[100010],mod=1e9+7,last[100010],lastk[100010],_max;
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
	freopen("pool.in","r",stdin);
	freopen("pool.out","w",stdout);
	T=read(),k=read();
	last[0]=1;
	for(int i=1;i<=100010;i++)
	{
		last[i]=last[i-1]+lastk[i-1];
		last[i]%=mod;
		if(i-k<0)
			continue;
		lastk[i]=last[i-k];
		lastk[i]%=mod;
	}
	for(int i=1;i<=100010;i++)
	{
		qwq[i]=qwq[i-1]+last[i]+lastk[i];
		qwq[i]%=mod;
	}
	for(int i=1;i<=T;i++)
	{
		l=read(),r=read();
		if(qwq[r]-qwq[l-1]<0)
			cout<<qwq[r]-qwq[l-1]+mod<<endl;
		else
			cout<<qwq[r]-qwq[l-1]<<endl;
	}
	return 0;
}
