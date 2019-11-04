/*
  Program: make
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
    while ((ch<'0'||ch>'9') && ch!='-') ch = getchar();
    if (ch=='-') p=-1,ch=getchar();
    while (ch>='0'&&ch<='9') res=res*10+ch-'0',ch=getchar();
    return res*p;
}

LL MOD=60013;
double mod=60017;
int lim,typ,x,y;
int L=1000000000;
int n,m;
int main()
{
    freopen("make.req","r",stdin);
    freopen("noon.in","w",stdout);
    srand(time(0));
    rand();
    rand();
    rand();
    lim=getint();
    typ=getint();
    n=m=lim;
    printf("%d %d\n",n,m);
    x=0;
    int k=1;
    while (m--) {
        if (typ) x=n-m;
        else {
            x=x+1+rand()%1000;
            if (x>n) x-=n,k++;
        }
        y=k*(x)/(double)100000*(rand()%20000+90000);
        printf("%d %d\n",x,y);
    }
    return 0;
}
