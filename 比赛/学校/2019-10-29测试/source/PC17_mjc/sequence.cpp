#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,l,r;
vector<int > ans;
int a[500010];
int sum[500010];
bool cmp(int a,int b){
	return a>b;
}
int mjc;
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&k,&l,&r);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=l;j<=r;j++){
			if(i+j-1>n) break;
			ans.push_back(sum[i+j-1]-sum[i-1]);
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	for(int i=0;i<k;i++){
		mjc+=ans[i]; 
	}
	printf("%lld\n",mjc);
}

