#include<bits/stdc++.h>
using namespace std;
const int M=1e5+7;
#define ll long long
int t, n, m, x[M], y[M], k[M], d[M], vis[M];
vector<pair<int,ll> > st[M];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=m;i++) {
			scanf("%d%d%d", &x[i], &y[i], &k[i]);
			st[x[i]].push_back(make_pair(y[i], k[i]));
		}
		int ok=0;
		for(int i=1;i<=m;i++){
			queue<pair<int,ll> > q;
			q.push(make_pair(x[i], 0));
			while(!q.empty()){
				pair<int,ll> u=q.front(); q.pop();
				vector<pair<int,ll> > ::iterator it;
				for(it=st[u.first].begin();it!=st[u.first].end();it++){
					pair<int,ll> v=*it;
					if(v.first==y[i]&&v.second^u.second!=k[i]) {
						ok=1;
						break;
					}
					if(v.first<y[i]) q.push(make_pair(v.first+1, v.second^u.second));
				}
			}
			if(ok) break;
		}
		if(ok) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
}
