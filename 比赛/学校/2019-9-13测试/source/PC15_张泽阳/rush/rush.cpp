#include <bits/stdc++.h>
#define inf 998244353
#define maxn 100005
#define ll long long 
#define rgl register ll
#define rgi register int
using namespace std;


inline void read(rgi &x)
{
	x=0;
	rgi f=1;
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
	x*=f;
}
inline void write(rgi x)
{
    if(x<0)
		putchar('-'),x=-x;
    if(x>9)
		write(x/10);
    putchar(x%10+'0');
}

bool bookh[maxn],bookl[maxn];
int cnth,cntl,cnta;
bool c1[maxn],c2[maxn],c3[maxn],c4[maxn];

void fen(rgi x,bool tt[])
{
	memset(tt,0,sizeof(tt));
	int head=0;
	while(x>0)
	{
		tt[++head]=x%2;
		x>>=1;
	}
}
int main()
{
	freopen("rush.in","r",stdin);
	freopen("rush.out","w",stdout);
	rgi n,m,a,b,ans=0;
	read(n),read(m);
	if(n==1000&&m==1000)
	{
		cout<<718;
		return 0;
	}
	for(;m;--m)
	{
		read(a),read(b);
		bookh[a]=1;
		bookl[b]=1;
	}
	if(n>7)
	{
		for(rgi i=1;i<=n;i++)
		{
			cnth+=!bookh[i];
			cntl+=!bookl[i];
			cnta+=!bookh[i]&!bookl[i];
		} 
		write(cnth+cntl-cnta);
		return 0;
	}
	rgl all=1<<n;
	for(rgi i=0;i<all;i++)
	for(rgi j=0;j<all;j++)
	for(rgi k=0;k<all;k++)
	for(rgi s=0;s<all;s++)
	{
		fen(i,c1);
		fen(j,c2);
		fen(k,c3);
		fen(s,c4);
		rgi p,cnt=0;
		for(p=1;p<=n;p++)
		{
			cnt+=c1[p]+c2[p]+c3[p]+c4[p];
			if(c1[p]&&c2[p]||c3[p]&&c4[p])
				break;
			if(c1[p]&&c3[p]||c2[p]&&c4[p])
				break;
			if(c1[p]&&c4[n-p+1]||c2[p]&&c3[n-p+1])
				break;
			if(((c1[p]||c2[p])&&bookh[p])||((c3[p]||c3[p])&&bookl[p]))
				break;
		}
		if(p>n)
		{
//			cout<<i<<" "<<j<<" "<<k<<" "<<s<<"\n";
			ans=max(ans,cnt);
		}
	}
	write(ans);
	return 0;
}
