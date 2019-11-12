#include <bits/stdc++.h>

using namespace std;
const int N = 100010;
int n,m;
int a[N],ans[N];
vector<int> v[N];
int main(){
	freopen("permutation.in", "r", stdin);
	freopen("permutation.out", "w", stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		v[a[i]].push_back(i);
		m=max(m, a[i]);
	}
	for(int i=2; i<=m; i++){
		if(v[i].size()>v[i-1].size()){
			puts("-1");
			return 0;
		}
	}
	for(int i=1; i<=m; i++){
		int len=v[i].size();
		for(int j=0; j<len; j++){
			ans[v[i][j]]=j+1;
		}
	}
	printf("%d\n",v[1].size());
	for(int i=1; i<=n; i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
