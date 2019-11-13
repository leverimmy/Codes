#pragma GCC optimize("O2")
#include <bits/stdc++.h>
int n,q,l,r,det[500005],ans=0;
int main(){
	freopen("clean.in","r",stdin);
	freopen("clean.out","w",stdout);
	scanf("%d%d",&n,&q);
	while (q--){
		scanf("%d%d",&l,&r);
		det[l]++;det[r+1]--;
	}for(int i=1;i<=n;++i){
		det[i]+=det[i-1];
		if (det[i]==0)ans++;
	}printf("%d",ans);
	return 0;
}
