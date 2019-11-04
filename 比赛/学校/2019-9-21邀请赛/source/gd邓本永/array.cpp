#include<bits/stdc++.h>
using namespace std;
int n, m, a[100005], f[100005][320];
int main(){
	freopen("array.in", "r", stdin);
	freopen("array.out", "w", stdout);
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	for(int i=0;i<=312;i++) {
		for(int j=n;j>=1;j--){
			if(j+a[j]+i>n) f[j][i]=1;
			else f[j][i]=f[j+a[j]+i][i]+1;
		}
	}
	cin>>m;
	while(m--){
		int p, k;
		scanf("%d%d", &p, &k);
		if(k>312) {
			int now=p, s=0;
			while(now<=n) now=now+a[now]+k, s++;
			printf("%d\n", s);
		}
		else printf("%d\n", f[p][k]);
	}
} 
