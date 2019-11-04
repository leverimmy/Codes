#include <bits/stdc++.h>
#define maxn 100005
int ans[400][maxn],n,q,a[maxn],p,k;

int main(){
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;++i)scanf("%d",&a[i]);
	int lim=(int)std::sqrt(n)+1;
	for (int i=0;i<=lim;++i){
		for (int j=n;j>=1;j--){
			int p=j+a[j]+i;
			if (p>n)ans[i][j]=1;
			else ans[i][j]=ans[i][p]+1;
		}
	}scanf("%d",&q);
	while (q--){
		scanf("%d%d",&p,&k);
		if (k<=lim){
			printf("%d\n",ans[k][p]);
		}
		else {
			int cnt=0;
			while (p<=n){
				cnt++;p+=a[p]+k;
			}printf("%d\n",cnt);
		}
	}
	return 0;
}
