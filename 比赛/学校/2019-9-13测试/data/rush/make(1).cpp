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
double mod=60013;
int lim;
int n,m;

int main()
{
    freopen("make.req","r",stdin);
    freopen("rush.in","w",stdout);
    srand(time(0));
    rand();
    rand();
    rand();
    n=lim=getint();
    if (lim==5) m=rand()%25;
    else m=lim/2+rand()%(lim/2);
    m+=!(m&1);
    printf("%d %d\n",n,m);
    int x,y;
    while (m--) {
		do {
        	if (lim<=1000) {
            	x=rand()%(lim-1)+1;
            	y=rand()%(lim-1)+1;
        	}
        	else {
	            x=1+(rand()%MOD)/mod*lim;
    	        y=1+(rand()%MOD)/mod*lim;
	        }
	    }while (x==n/2+1 || y==n/2+1);
        printf("%d %d\n",x,y);
    }
    return 0;
}
