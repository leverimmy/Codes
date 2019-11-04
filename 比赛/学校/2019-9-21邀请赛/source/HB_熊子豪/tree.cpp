#include<bits/stdc++.h>
using namespace std;
int n,m;
struct edge{
	int to;
	int val;
	edge(int x,int y){
		to=x;
		val=y;
	}
};
struct node{
	int st;
	int ed;
	int val;
}e[500001];
int fa[100001];
vector<edge>a[100001];
bool cmp(node x,node y){
	return x.val<y.val;
}
int find(int x){
	return fa[x]==x?x:find(fa[x]);
}
int ans;
bool visit[100001];
void dfs(int x,int v){
	visit[x]=1;
	ans+=v;
	for(int i=0;i<a[x].size();i++){
		if(!visit[a[x][i].to]){
			dfs(a[x][i].to,max(a[x][i].val,v));
		}
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>e[i].st>>e[i].ed>>e[i].val;
	}
	sort(e,e+m,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=0;i<m;i++){
		if(find(e[i].st)!=find(e[i].ed)){
			fa[e[i].st]=find(fa[e[i].ed]);
			a[e[i].st].push_back(edge(e[i].ed,e[i].val));
			a[e[i].ed].push_back(edge(e[i].st,e[i].val));
		}
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}

