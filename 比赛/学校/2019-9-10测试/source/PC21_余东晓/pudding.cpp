#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<climits>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<stack>
#include<map>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
int cnt[100010],h[100010],nxt[100010],to[100010],t[1000010],siz[100010],p[100010];
int main()
{
	freopen("pudding.in","r",stdin);freopen("pudding.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);int tot(0),ans(0);for(int i=1;i<=n;i++){int x;scanf("%d",&x);if(!t[x])t[x]=++tot;cnt[i]=t[x],siz[t[x]]++;nxt[i]=h[t[x]];h[t[x]]=i;;if(cnt[i]!=cnt[i-1])ans++;}
	for(int i=1;i<=m;i++)
	{
		int k;scanf("%d",&k);if(k==2){printf("%d\n",ans);continue;}int x,y;scanf("%d%d",&x,&y);if(x==y)continue;if(!t[x])continue;if(!t[y]){t[y]=t[x],t[x]=0;continue;}int fx=x,fy=y;x=t[x];y=t[y];t[fx]=0;
		if(siz[x]>siz[y])std::swap(x,y);t[fy]=y;int q=h[x];for(p[0]=0;q;q=nxt[q]){p[++p[0]]=q;ans-=(cnt[q-1]==y)+(cnt[q+1]==y);}for(int j=1;j<=p[0];j++){nxt[p[j]]=h[y];h[y]=p[j];cnt[p[j]]=y;}h[x]=0;
	}
	return 0;
}
