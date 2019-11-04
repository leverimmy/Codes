#include <bits/stdc++.h>
#define maxn 100005
int ans[maxn][400],n,q,a[maxn],p,k;

int main(){
	freopen("in.txt","r",stdin);
//	freopen("sample3.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;++i)scanf("%d",&a[i]);
	scanf("%d",&q);
	while (q--){
		scanf("%d%d",&p,&k);
		int cnt=0;
		while (p<=n){
			cnt++;p+=a[p]+k;
		}printf("%d\n",cnt);
	}
	return 0;
}
