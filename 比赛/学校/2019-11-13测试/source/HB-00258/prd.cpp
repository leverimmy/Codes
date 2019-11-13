#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> v;
void dfs(int sum){
	if(sum*10+4<=1000){
		v.push_back(sum*10+4);
		dfs(sum*10+4);
	}
	if(sum*10+7<=1000){
		v.push_back(sum*10+7);
		dfs(sum*10+7);
	}
}
int T;
signed main(){
	freopen("prd.in", "r", stdin);
	freopen("prd.out", "w", stdout);
	dfs(0);
	int siz=v.size();
	for(int i=0; i<siz; i++){
		for(int j=0; j<=siz; j++){
			if(v[i]*v[j]<=1000){
				v.push_back(v[i]*v[j]);
			}
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	scanf("%lld",&T);
	while(T--){
		int l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",upper_bound(v.begin(), v.end(), r)-lower_bound(v.begin(), v.end(), l));
	}
	return 0;
}

