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

ll gcd(rgl x,rgl y)
{
	return y==0?x:gcd(y,x%y);
}
struct fun{
	ll up,down;
	void del()
	{
		rgl t=gcd(up,down);
		up/=t,down/=t;
	}
}st[maxn];
//fun maxf(fun x,fun y)
//{
//	return x.up*y.down<x.down*y.up?x:y; 
//}
bool cmp(fun x,fun y)
{
	return x.up*y.down<x.down*y.up; 
}

int n;
//int lowbit(rgi x)
//{
//	return x&-x;
//}
//
//void updatef(rgi x,fun t)
//{
//	for(;x<=n;x+=lowbit(x))
//		st[x]=maxf(st[x],t);
//}
//fun queryf(rgi x)
//{
//	fun res;
//	res.up=-1;
//	res.down=1;
//	for(;x>0;x-=lowbit(x))
//		res=maxf(res,st[x]);
//	return res;
//}
//
//int kill[maxn];
//void update1(rgi x,rgi t)
//{
//	for(;x<=n;x+=lowbit(x))
//		kill[x]+=t;
//}
//int query1(rgi x)
//{
//	rgi res
//	for(;x>0;x-=lowbit(x))
//		res+=kill[x];
//	return res;
//}

int main()
{
	freopen("noon.in","r",stdin);
	freopen("noon.out","w",stdout);
	rgi m,a,b,ans;
	read(n),read(m);
	for(rgi i=1;i<=n;i++)
	{
		st[i].up=-1;
		st[i].down=i;
	}
	fun tt;
	for(;m;--m)
	{
		read(a),read(b);
		ans=0;
		st[a].up=b;
		st[a].del();
		tt.up=-1;
		tt.down=maxn;
		for(rgi i=1;i<=n;++i)
			if(cmp(tt,st[i]))
			{
				++ans;
				tt=st[i]; 
			}
		write(ans);
		putchar('\n');
	}
	return 0;
}
