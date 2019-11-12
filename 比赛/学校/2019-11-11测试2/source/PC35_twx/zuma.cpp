#include <bits/stdc++.h>

using namespace std;
const int N = 110;
int n,k,ans;
vector<int> a,b;
int cnt[N];
int main(){
	freopen("zuma.in", "r", stdin);
	freopen("zuma.out", "w", stdout);
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++){
		int num;
		scanf("%d",&num);
		a.push_back(num);
		b.push_back(num);
	}
//	for(int i=0; i<a.size(); i++){
//		printf("%d ",a[i]);
//	}
//	puts("");
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	for(int i=1; i<=n; i++){
		a[i]=lower_bound(b.begin(), b.end(), a[i])-b.begin()+1;
	}
//	for(int i=0; i<a.size(); i++){
//		printf("%d ",a[i]);
//	}
//	puts("");
	if(k==1){
		printf("0\n");
		return 0;
	}
	for(int i=0; i<n; i++){
		cnt[a[i]]++;
	}
//	for(int i=1; i<=n; i++){
//		printf("%d ",cnt[i]);
//	}
	for(int i=1; i<=b.size(); i++){
		if(cnt[i]<k){
			ans+=(k-cnt[i]);
		}
	}
	printf("%d\n",ans);
	return 0;
}

