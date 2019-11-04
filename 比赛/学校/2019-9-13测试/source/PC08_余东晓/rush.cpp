#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<cassert>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<vector>
#include<queue>
#include<list>
#define ll long long
#define INF 0x7fffffff
int a[200020];
signed main(){freopen("rush.in","r",stdin);freopen("rush.out","w",stdout);int n,m;scanf("%d%d",&n,&m);for(int i=1;i<=n<<1;i++)a[i]=1;for(int i=1;i<=m;i++){int x,y;scanf("%d%d",&x,&y);a[x]=0;a[y+n]=0;}int ans(0);for(int i=1;i<=n<<1;i++)ans+=a[i];return printf("%d\n",ans),0;}
