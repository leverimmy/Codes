#include <bits/stdc++.h>
#define maxn 200005
int size[maxn]={0},depth[maxn]={0},anc[maxn][22]={0},n,s,degr[maxn]={0},u;
std::vector<int>conj[maxn],ch[maxn],rev[maxn];

void process(int x){
	for(int i=1;i<=19;++i)anc[x][i]=anc[anc[x][i-1]][i-1];
}

int lca(int u,int v){
	if (depth[u]<depth[v])std::swap(u,v);
	for(int i=19;i>=0;i--)if (depth[anc[u][i]]>=depth[v])u=anc[u][i];
	if (u==v)return u;
	for(int i=19;i>=0;i--)if (anc[u][i]!=anc[v][i]){u=anc[u][i];v=anc[v][i];}
	return anc[u][0];
}

void solve(){
	std::queue<int>q;
	for(int i=1;i<=n;++i)if (degr[i]==0){q.push(i);conj[i].push_back(s);}
	while (!q.empty()){
		int u=q.front();q.pop();
		int l=0;
		for(int i=0;i<conj[u].size();++i){
			int v=conj[u][i];
			if (!l)l=v;
			else l=lca(l,v);
		}for(int i=0;i<rev[u].size();++i){degr[rev[u][i]]--;if (degr[rev[u][i]]==0)q.push(rev[u][i]);}
	//	printf("%d->%d\n",l,u);
		ch[l].push_back(u);anc[u][0]=l;depth[u]=depth[l]+1;process(u);
	}
}

void dfs(int u){
	size[u]=1;
	for(int i=0;i<ch[u].size();++i){
		dfs(ch[u][i]);size[u]+=size[ch[u][i]];
	}
}

int main(){
	freopen("catas.in","r",stdin);
	freopen("catas.out","w",stdout);
	scanf("%d",&n);s=n+1;depth[s]=1;
	for(int i=1;i<=n;++i){
		int t;
		while (1){
			scanf("%d",&t);
			if (t==0)break;
			conj[i].push_back(t);
			rev[t].push_back(i);
			degr[i]++;
		}
	}solve();dfs(s);
	for(int i=1;i<=n;++i)printf("%d\n",size[i]-1);
//	printf("%d %d %d %d %d\n",anc[8197][0],anc[ 11102 ][0],anc[30359 ][0],anc[30361][0],anc[ 30364][0],anc[ 33585][0]);
	return 0;
}



