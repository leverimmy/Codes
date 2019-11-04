#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct node{
	long long to;
	long long val;
};
struct node2{
	long long p;
	long long tim;
};
vector<node>a[5010];
set<long long>s[5010];
bool visit[5010];
long long ans=9999999999999;
deque<node2>q;
int main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	cin>>n>>m;
	while(m--){
		long long u,v,w;
		cin>>u>>v>>w;
		node k;
		k.to=v;
		k.val=w;
		a[u].push_back(k);
		k.to=u;
		a[v].push_back(k);
	}
	for(long long i=2;i<=n-1;i++){
		long long k;
		cin>>k;
		while(k--){
			long long u;
			cin>>u;
			s[i].insert(u);
		}
	}
	for(long long i=0;i<a[1].size();i++){
		if(s[a[1][i].to].empty()){
			node2 k;
			k.p=a[1][i].to;
			k.tim=a[1][i].val;
			q.push_back(k);
			visit[a[1][i].to]=1;
			for(int j=1;j<=n;j++){
				s[j].erase(a[1][i].to);
			}
		}
	}
	visit[1]=1;
	while(!q.empty()){
		node2 now=q.front();
		q.pop_front();
		if(now.p==n){
			ans=min(ans,(long long)now.tim);
			continue;
		}
		long long fl=0;
		for(long long i=0;i<a[now.p].size();i++){
			if(!s[a[now.p][i].to].empty()){
				fl=1;
			}
			if(s[a[now.p][i].to].empty()&&!visit[a[now.p][i].to]){
				node2 k=now;
				k.p=a[now.p][i].to;
				k.tim+=a[now.p][i].val;
				q.push_back(k);
				visit[a[now.p][i].to]=1;
				for(int j=1;j<=n;j++){
					s[j].erase(a[now.p][i].to);
				}
			}
		}
		if(fl){
			q.push_back(now);
		}
	}
	if(ans==9999999999999){
		cout<<"Mission Failed";
	}
	else cout<<ans;
	return 0;
}
/*
6 6
1 2 1
1 4 3
2 3 1
2 5 2
4 6 2
5 3 2
0
1 6
0
2 4 6
*/
