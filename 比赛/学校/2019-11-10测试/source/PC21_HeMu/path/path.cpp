#include <bits/stdc++.h>
using namespace std;
int ans=0x3f3f3f3f,n,edcnt,t1,t2,t3,head[100010],st[100010],siz,dis[100010];
struct edge{
	int to,nxt,val;
}ed[200010];
inline void addedge(int from,int to,int val){
	ed[++edcnt].nxt=head[from];
	ed[edcnt].to=to,
	ed[edcnt].val=val;
	head[from]=edcnt;
}
inline void fun(int now,int prev){
	for(int i=head[now];i;i=ed[i].nxt){
		if(ed[i].to==prev)
			continue;
		dis[ed[i].to]=dis[now]+ed[i].val;
//		siz+=ed[i].val;
		fun(ed[i].to,now);
	}
}
int main(){
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;++i)
		scanf("%d%d%d",&t1,&t2,&t3),addedge(t1,t2,t3),addedge(t2,t1,t3),siz+=t3;
	for(int i=1;i<=n;++i){
		scanf("%d",&st[i]);
	}
	for(int i=1;i<=n;++i){
		if(st[i]){
			dis[i]=0,fun(i,0);
			int maxx=0;
			for(int i=1;i<=n;++i){
				maxx=max(maxx,dis[i]);
			}
			maxx=2*siz-maxx;
			ans=min(ans,maxx);
		}
	}
	if(ans==0x3f3f3f3f){
		printf("-1");
		return 0;
	}
	printf("%d",ans);
	return 0;
}
/*


void dfs(int x, int p, int weight) {
	
	siz[x] = weight;
	
	std::multiset <int> s;
	
	for(rgi i = first[x], y = e[i].to; ~i; i = e[i]._next, y = e[i].to) {
		if(y == p)	continue;
		
		dfs(y, x, e[i].wt);
		
		s.insert(siz[y]);
	}
	
	MSET it = s.end();
	if(s.size())	tt--;q

}
int main() {
	n = read();
	for(rgi i = 1; i <= n - 1; ++i) {
		int u = read(), v = read(), w = read();
		Add_Edge(u, v, w);
		Add_Edge(v, u, w);
	}
	for(rgi i = 1; i <= n; ++i)	rt[i] = read();
	for(rgi i = 1; i <= n; ++i)	if(rt[i]) {
		memset(siz, 0, sizeof siz);
		dfs(i, 0, 0);
		ans = std::min(ans, siz[i]);
	}
	printf("%d", ans);
	return 0;
}*/
