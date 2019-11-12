#include<bits/stdc++.h>
using namespace std;
int n,a[100010],cnt[100010],tmp[100010],maxx;
int main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]),cnt[a[i]]++;
	for(int i=2;i<=n;++i)
		if(cnt[i]>cnt[i-1]){
			printf("-1");
			return 0;
		}
	for(int i=1;i<=n;++i){
		a[i]=++tmp[a[i]];
	}
	for(int i=1;i<=n;++i)
		maxx=max(maxx,a[i]);
	printf("%d\n",maxx);
	for(int i=1;i<=n;++i)
		printf("%d ",a[i]);
	return 0;
}
