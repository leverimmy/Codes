#include<cstdio>
#include<cstring>
#include<cassert>
#include<climits>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
struct edge{int to,next,wa,wb;}a[20020];int head[10010],cnt(0);void addedge(int x,int y,int w1,int w2){a[cnt]=(edge){y,head[x],w1,w2};head[x]=cnt++;}
signed main()
{
	freopen("mst.in","r",stdin);freopen("mst.out","w",stdout);int n,m;scanf("%d%d",&n,&m);while(m--){int x,y,w1,w2;scanf("%d%d%d%d",&x,&y,&w1,&w2);addedge(x,y,w1,w2);addedge(y,x,w1,w2);}
}
