/*
  Program: noon
  Copyright by G10
  Please do not copy it
  Or Mr.Xiang will invite you with a cup of tee
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<ctime>
#include<vector>
#include<stack>
#include<set>
#include<map>
#define File(S) freopen(S".in","r",stdin);freopen(S".out","w",stdout);
#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
using namespace std;

typedef long long LL;

const int INF=2147483647;

LL getint()
{
    LL res=0,p=1;
    char ch=getchar();
    while ((ch<'0'||ch>'9') && ch!='-') ch=getchar();
    if (ch=='-') p=-1,ch=getchar();
    while (ch>='0'&&ch<='9') res=res*10+ch-'0',ch=getchar();
    return res*p;
}

inline LL gcd(LL a,LL b)
{
    LL r;
    while (b) { r=a%b;a=b;b=r; }
    return a;
}

struct Real
{
    LL p,q;
    Real():p(0),q(1){}
    Real(LL P,LL Q){ p=P,q=Q,p/=gcd(P,Q),q/=gcd(P,Q); }
    bool operator < (const Real b) const {
        return (p*b.q<b.p*q);
    }
};

struct Node
{
    int l,r,cnt;
    Real data;
}T[400050];

void build(int x,int l,int r)
{
    T[x].l=l;
    T[x].r=r;
    if (l==r) { T[x].cnt=0;return; }
    int mid=(T[x].l+T[x].r)>>1;
    build(x<<1,l,mid);
    build((x<<1)+1,mid+1,r);
    return;
}

int cal(Real Lim,int x)
{
    if (T[x].l==T[x].r) return Lim<T[x].data;
    if (!(Lim<T[x<<1].data)) return cal(Lim,(x<<1)+1);
    return T[x].cnt-T[x<<1].cnt+cal(Lim,x<<1);
}

void update(int x,int p,Real v)
{
    if (T[x].l==T[x].r) {
        T[x].cnt=1;
        T[x].data=v;
        return;
    }
    int mid=(T[x].l+T[x].r)>>1;
    if (p<=mid) update(x<<1,p,v);
    else update((x<<1)+1,p,v);
    T[x].data=max(T[x<<1].data,T[(x<<1)+1].data);
    T[x].cnt=T[x<<1].cnt+cal(T[x<<1].data,(x<<1)+1);
    return;
}

int n,m;

int main()
{
    File("noon");
    n=getint();
    m=getint();
    int x,y;
    Real now;
    build(1,1,n);
    while (m--) {
        x=getint();
        y=getint();
        now=Real(y,x);
        update(1,x,now);
        printf("%d\n",T[1].cnt);
    }
    return 0;
}
