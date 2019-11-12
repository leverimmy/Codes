#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int a[N],cnt[N],num[N];
int main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++,num[i]=1;
	for(int i=2;i<=n;i++) if(cnt[i]>cnt[i-1]){
		puts("-1");return 0;
	}
	printf("%d\n",cnt[1]);
	for(int i=1;i<=n;i++) printf("%d ",num[a[i]]++);
	return 0;
}
