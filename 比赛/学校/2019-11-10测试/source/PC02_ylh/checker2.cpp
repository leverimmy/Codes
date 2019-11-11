#include <bits/stdc++.h>
int ans[1000005],t;
int main(){
	int n=50000;
	freopen("catas1.out","r",stdin);
	for(int i=1;i<=n;++i)scanf("%d",&ans[i]);
	freopen("catas1.ans","r",stdin);
	for(int i=1;i<=n;++i){
		scanf("%d",&t);
		if (t!=ans[i])printf("%d ",i);
	}return 0;
}
