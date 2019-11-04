#include<bits/stdc++.h>

const int MAXN = 1000500;

long long D[MAXN][4],F[MAXN][4];

signed main(void)
{
	freopen("jx.in","r",stdin);
	freopen("jx.out","w",stdout);
	
	int totNums; long long val,ans;
	
	scanf("%d", &totNums);
	for(int i=1;i<=totNums;i++){
		scanf("%lld", &val);
		for(int j=1;j<=3;j++) F[i][j] = std::max(F[i-1][j], std::max(D[i-1][j]+val,F[i-1][j-1]+val));
		for(int j=1;j<=3;j++) D[i][j] = std::max(F[i-1][j-1]+val, D[i-1][j]+val);
		ans = std::max(ans, D[i][3]);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
