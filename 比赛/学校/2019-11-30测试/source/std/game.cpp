#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
int father[100100],small[100100],order[100100],post[100100];
int n,q,e,root,tot,now,del,aaaa;
struct edge{
	int from,to,n;
}a[200200];
int head[100100],vis[100100],d[100100];
int num[100100][20],power[20];
struct compare{
	bool operator () (const int a,const int b) {
		return ( order[a] < order[b]);
	}
};
multiset < int,compare > heap;
void addedge(int x,int y){
	a[++e] = (edge){y,x,head[y]};head[y] = e;
}
int cmp(const int &a,const int &b){
	return (small[a] > small[b]);
}
void dfs(int p){
	vis[p] = 1;
	num[p][0] = father[p];int i = 1;
	while (num[p][i-1])
		num[p][i] = num[num[p][i-1]][i-1],i++;
	for (i = head[p];i;i = a[i].n)
		if (!vis[a[i].to]) dfs(a[i].to);
	post[++aaaa] = p;
	vis[p] = 0;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i = 1;i<=n;i++)
		scanf("%d",&father[i]);
	for (int i = 1;i<=n;i++){
		int j = i;
		while (j && !small[j]){
			small[j] = i;j = father[j];}
	}
	for (int i = 1;i<=n;i++)order[i] = i;
	sort(order+1,order+n+1,cmp);
	for (int j = 1;j<=n;j++){
		int i = order[j];
		if (father[i] != 0)
			addedge(i,father[i]);
		else root = i;
	}
	dfs(root);
	for (int i = 1;i<=n;i++) order[post[i]] = i;
	power[0] = 1;
	for (int i = 1;i<=18;i++)
		power[i] = power[i-1]*2;
	for (int i = 1;i<=n;i++) heap.insert(i);
	for (int i = 1;i<=q;++i){
		int o = 0;scanf("%d",&o);
		if (o == 1){
			scanf("%d",&tot);now = 0;
			for (int i = 1;i<=tot;i++){
				now = *heap.begin();
				d[now] = 1;heap.erase(now);
			}
			printf("%d\n",now);
		}else {
			scanf("%d",&del);tot = 0;
			int j = 18;while (j >= 0){
				if (d[num[del][j]]) tot += power[j],del = num[del][j];
				j--;
			}
			printf("%d\n",tot);d[del] =0;heap.insert(del);
		}
	}
	return 0;
}
