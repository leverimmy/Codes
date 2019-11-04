//dij pre 40
#include<bits/stdc++.h>
using namespace std;
int n,m;
int r[30001];
int dis[30001];
int vis[30001];
struct edge{
	int to;
	int val;
};
struct key{
	int d;
	int node;
};
key make_key(int a,int b){
	key temp;
	temp.d=a;
	temp.node=b;
	return temp;
}
bool operator<(key a,key b){
	return a.d==b.d?r[a.node]<r[b.node]:a.d>b.d;
}
edge add_edge(int a,int b){
	edge temp;
	temp.to=a;
	temp.val=b;
	return temp;
}
priority_queue<key>q;
vector<edge>a[30001];
key tmp[30001];
int sum;
int main(){
	freopen("serves.in","r",stdin);
	freopen("serves.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back(add_edge(v,w));
		a[v].push_back(add_edge(u,w));
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[j]=19260817;
			vis[j]=0;
		}
		dis[i]=0;
		q.push(make_key(0,i));
		while(!q.empty()){
			key temp=q.top();
			q.pop();
			if(!vis[temp.node]){
				for(int j=0;j<a[temp.node].size();j++){
					if(dis[temp.node]+a[temp.node][j].val<dis[a[temp.node][j].to]){
						dis[a[temp.node][j].to]=dis[temp.node]+a[temp.node][j].val;
						q.push(make_key(dis[a[temp.node][j].to],a[temp.node][j].to));
					}
				}
			}
		}
		for(int j=1;j<=n;j++){
			tmp[j].d=dis[j];
			tmp[j].node=j;
		}
		sort(tmp+1,tmp+n+1);
		int maxr=r[i];
		for(int j=n;j>0;j--){
			if(r[tmp[j].node]>=maxr){
				maxr=r[tmp[j].node];
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
