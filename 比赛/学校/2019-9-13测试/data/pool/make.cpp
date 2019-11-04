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
double mod=60259;
int lim;
int l1,l2,l,r;
int T,k;
int main()
{
    freopen("make.req","r",stdin);
    freopen("pool.in","w",stdout);
    srand(time(NULL));
    rand();
    rand();
    rand();
    lim=getint();
    T=(lim==10)?1:lim;
    l1=lim/10*3;
    l2=lim/10*5;
    k=l1+(rand()%MOD)/mod*l1;
    printf("%d %d\n",T,k);
    while (T--) {
        l=1+(rand()%MOD)/mod*l2;
        r=l2+1+(rand()%MOD)/mod*l2;
        printf("%d %d\n",l,r);
    }
    return 0;
}
