#include<bits/stdc++.h>
using namespace std;
int t,n,m;
struct node{
	int to;
	int val;
	node(int x,int y){
		to=x;
		val=y;
	}
};
vector<node>a[100001];
deque<node>q;
bool visit[100001];
bool dfs(int x){
	visit[x]=1;
	for(int i=0;i<a[x].size();i++){
		if(!visit[a[x][i].to]){
			q.push_back(node(a[x][i].to,a[x][i].val));
			bool fl=dfs(a[x][i].to);
			q.pop_back();
			if(!fl){
				return 1;
			}
		}
		else if(a[x][i].to!=q.back().to){
			deque<node>q1=q;
			int res=a[x][i].val;
			while(!q1.empty()||q1.back().to!=a[x][i].to){
				res^=q.back().val;
				q1.pop_back();
			}
			return res==0;
		}
	}
	visit[x]=0;
	return 0;
}
string ans[2]={"Yes","No"};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<=n;i++){
			a[i].clear();
			visit[i]=0;
		}
		for(int i=0;i<m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			u--;
			a[u].push_back(node(v,w));
			a[v].push_back(node(u,w));
		}
		q.push_back(node(0,0));
		cout<<ans[dfs(0)]<<'\n';
		q.clear();
	}
	return 0;
}
