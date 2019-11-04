#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAXn 100002
#define MAXm 100002
#define ll long long
using namespace std;
int n,m,fa[MAXn],pre[MAXn],next[MAXn],a[1000][1000],ans2,maxl,maxs,ans3;
struct edge {
	int x,y,k;
} e[MAXm];
int cmp(const edge &a,const edge &b) {
	if(a.k<b.k) return 1;
	else return 0;
}
int find(int x) {
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void join(int x,int y) {
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy) fa[fy]=fx;
}
bool judge(int x,int y) {
	int fx=find(x);
	int fy=find(y);
	if(fx==fy) return 1;
	else return 0;
}
int dfs(int k) {
	if(k==0) return ans2;
	if(a[k][next[k]]>maxl) maxl=a[k][next[k]];
	ans2+=maxl;
	dfs(next[k]);
}
int dfs2(int k) {
	if(k==0) return ans3;
	if(a[k][pre[k]]>maxs) maxs=a[k][pre[k]];
	ans3+=maxs;
	dfs(pre[k]);
}
int main() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		int x,y,w;
		cin>>x>>y>>w;
		e[i].x=x;
		e[i].y=y;
		e[i].k=w;
		a[x][y]=w;
		a[y][x]=w;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1; i<=n; i++)
		fa[i]=i;
	int maxl=0;
	for(int i=1; i<=m; i++) {
		int x=e[i].x;
		int y=e[i].y;
		if(!judge(x,y)) {
			if(maxl<e[i].k) maxl=e[i].k;
			join(x,y);
			pre[y]=x;
			next[x]=y;
		}
	}
	ll ans1=maxl*(n-1);
//	for(int i=1; i<=n; i++) {
//		cout<<pre[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1; i<=n; i++) {
//		cout<<next[i]<<' ';
//	}
//	ans2=dfs(1);
//	ans3=dfs2(1);
//	cout<<endl;
	cout<<ans1; 
	return 0;
}
/*
3 3
1 2 1
2 3 1
1 3 2
*/
//2

/*
3 3
1 2 5
2 3 1
3 1 2
*/
//4
