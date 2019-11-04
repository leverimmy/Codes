#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<cmath>
#define MAXn 30002
#define MAXm 150010
#define oo 0x7fffffff/3
#define ll long long
using namespace std;
int n,m,head[MAXn],times,cnt,s,t,r[MAXn],b[MAXn];
ll dis[MAXn];
bool book[MAXn];
struct ed {
	int next,to,w;
} edge[MAXm];

void add(int u,int v,int w) {
	edge[cnt].w=w;
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt;
	cnt++;
}

void spfa(int s) {
	queue<int> q;
	q.push(s);
	book[s]=1;
	for(int i=1; i<=n; i++) dis[i]=oo;
	dis[s]=0;
	while(!q.empty()) {
		int u=q.front();
		book[u]=0;
		q.pop();
		for(int i=head[u]; i!=-1; i=edge[i].next) {
			int v=edge[i].to;
			if(dis[v]>dis[u]+edge[i].w) {
				dis[v]=dis[u]+edge[i].w;
				if(book[v]==0) {
					q.push(v);
					book[v]=1;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	freopen("serves.in","r",stdin);
	freopen("serves.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<=n; i++) {
		edge[i].next=-1;
		head[i]=-1;
	}
	for(int i=1; i<=n; i++) cin>>r[i];
	for(int i=1; i<=m; i++) {
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	int count;
	for(int i=1; i<=n; i++) {
		spfa(i);
		for(int j=1; j<=n; j++) {
			count=0;
			int k=dis[j];
			for(int t=1; t<=n; t++)
				if(dis[t]<=k&&r[t]>r[j]) count++;
			if(count==0) b[i]++;
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
//		cout<<b[i]<<" ";
		ans+=b[i];
	}
//	cout<<endl;
	cout<<ans;
	return 0;
}
/*
4 3
2
3
1
1
1 4 30
2 3 20
3 4 20
*/

