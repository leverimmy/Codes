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

int n,m;
vector <int> pro[3050];
int main()
{
    freopen("landcraft.in","r",stdin);
    freopen("bomb.in","w",stdout);
    n=getint();
    m=getint();
    printf("%d %d\n",n,m);
    int i,k,u,v,w;
    for (i=1;i<=m;i++) {
    	u=getint();
    	v=getint();
    	w=getint();
    	printf("%d %d %d\n",u,v,w);
	}
	for (i=1;i<=n;i++) {
		k=getint();
		while (k--) {
			u=getint();
			if (u==n) u=i;
			pro[u].push_back(i);
		}
	}
	for (i=2;i<n;i++) {
		printf("%d ",pro[i].size());
		for (k=0;k<pro[i].size();k++) printf("%d ",pro[i][k]);
		printf("\n");
	}
    return 0;
}
