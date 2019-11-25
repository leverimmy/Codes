#include <bits/stdc++.h>
using namespace std;
const int N = 3010;
const int INF = 0x3f3f3f3f;
vector<int> v;
int n,ans=INF;
typedef pair<int, int> p;
p a[N];
bool vis[N<<1];
void dfs(int now,int maxx){
	if(maxx>=ans){
		return;
	}
	if(now==n){
		ans=maxx;
		return;
	}
	if(!vis[a[now+1].first]){
		vis[a[now+1].first]=1;
		dfs(now+1, max(maxx, a[now+1].first));
		vis[a[now+1].first]=0;
	}
	if(!vis[a[now+1].second]){
		vis[a[now+1].second]=1;
		dfs(now+1, max(maxx, a[now+1].second));
		vis[a[now+1].second]=0;
	}
	return;
}
int main(){
	freopen("exam.in", "r", stdin);
	freopen("exam.out", "w", stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d%d",&a[i].first,&a[i].second);
		v.push_back(a[i].first);
		v.push_back(a[i].second);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i=1; i<=n; i++){
		a[i].first=lower_bound(v.begin(), v.end(), a[i].first)-v.begin()+1;
		a[i].second=lower_bound(v.begin(), v.end(), a[i].second)-v.begin()+1;
		if(a[i].first>a[i].second){
			swap(a[i].first, a[i].second);
		}
	}
	sort(a+1, a+1+n);
	dfs(0, 0);
	if(ans==INF){
		puts("-1");
	}
	else{
		printf("%d\n",v[ans-1]);
	}
	return 0;
}

