#include <bits/stdc++.h>
int arr[100005];
int main(){
	freopen("pudding.in","r",stdin);
	int n,q;scanf("%d%d",&n,&q);
	for (int i=1;i<=n;++i)scanf("%d",&arr[i]);
	while (q--){
		int opt,x,y;
		scanf("%d",&opt);
		if (opt==2){
			int ans=1;
			for (int i=2;i<=n;++i)ans+=(arr[i]!=arr[i-1]);
			printf("%d\n",ans);
		}else {
			scanf("%d%d",&x,&y);
			for (int i=1;i<=n;++i)if (arr[i]==x)arr[i]=y;
		}
	}
	return 0;
}
