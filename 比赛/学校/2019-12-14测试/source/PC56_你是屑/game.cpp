#include <bits/stdc++.h>

int f[22][10000],a[22],n,s;

int dfs(int p,int s){
	if (p>n*2)p=1;
	if (s==0)return 1;
	if (f[p][s]!=-1)return f[p][s];
	f[p][s]=0;
	for(int i=1;i<s&&i<=a[p];++i)
		if (!dfs(p+1,s-i)){f[p][s]=1;return 1;}
	return f[p][s];
}

int solve(){
	std::memset(f,-1,sizeof(f));
	scanf("%d",&n);
	if(n==0)return 0;
	scanf("%d",&s);
	for(int i=1;i<=n*2;++i)scanf("%d",&a[i]);
	printf("%d\n",dfs(1,s));
	return 1;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	while (solve()){;} 
	return 0;
}
