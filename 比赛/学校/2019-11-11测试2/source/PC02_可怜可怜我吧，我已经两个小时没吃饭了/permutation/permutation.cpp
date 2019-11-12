#include <bits/stdc++.h>
int n,a[100005],sum[100005],vis[100005];
int main(){
	freopen("permutation.in","r",stdin);freopen("permutation.out","w",stdout);
	scanf("%d",&n);for(int i=1;i<=n;++i){scanf("%d",&a[i]);vis[a[i]]++;sum[a[i]]++;}
	for(int i=2;i<=n;++i)if(vis[i-1]<vis[i]){printf("-1");return 0;}
	printf("%d\n",vis[1]);
	for(int i=1;i<=n;++i)printf("%d ",vis[a[i]]-(--sum[a[i]]));
	return 0;
}
