#include <bits/stdc++.h>
int n;
int G[100][100],v[100];
int check(int s){
	for(int i=1;i<=n;++i)v[i]=(s>>(i-1))&1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if (i==j)continue;
			if (v[i]&&G[i][j]!=v[j])return 0;
		}
	}return 1;
}
int main(){
	freopen("7.in","r",stdin);
	freopen("7.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)scanf("%d",&G[i][j]);
	for(int s=0;s<(1<<n);++s){
		int c=__builtin_popcount(s);
		if (c<=(n-c))continue;
		if (check(s)){
			//printf("!");
			for(int i=1;i<=n;++i){if((s>>(i-1))&1)printf("%d ",i);}
			return 0;
		}
	}
	return 0;
}
