#include<bits/stdc++.h>

const int MAXN = 21;
const int MAXS = 10000;

int val[MAXN],totNums,memo[MAXS][MAXN];
bool Dfs(const int totSt, const int pos){
	if(memo[totSt][pos] != -1) return memo[totSt][pos];
	
	for(int i=std::min(val[pos], totSt-1);i>0;--i)
		if(!Dfs(totSt-i, (pos+1)%totNums)) return memo[totSt][pos] = true;
	return memo[totSt][pos] = false;
}

signed main(void)
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	int totPeo,totSt;
	while(true){
		scanf("%d", &totPeo); if(totPeo <= 0) break;
		
		scanf("%d", &totSt); totNums = totPeo<<1;
		for(int i=0;i<=totSt;i++) for(int j=0;j<=totNums;j++) memo[i][j] = -1;
		for(int i=0;i<totNums;i++) scanf("%d", val+i);
		
		if(Dfs(totSt,0)) puts("1");
		else puts("0");
	}
	
	return 0;
}
