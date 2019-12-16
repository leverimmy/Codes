#include<bits/stdc++.h>
using namespace std;
const int N=12;
int n,s;
int a[2*N];
int f[2*N][8200];
int dfs(int i,int s){
	if(f[i][s]!=-1) return f[i][s];
	if(s==1) return f[i][s]=0;
	f[i][s]=0;
	for(int j=1;j<=a[i];j++) {
		if(s-j<=0) break;
		f[i][s]|=(dfs(i%(2*n)+1,s-j)^1);
	} 
	return f[i][s];
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	while(scanf("%d",&n)&&n>0){
		scanf("%d",&s);
		for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
		memset(f,-1,sizeof(f));
		printf("%d\n",dfs(1,s));
	}
	return 0;
}
/*
1 9 4 4 
1 101 4 4 
1 100 4 4 
3 97 8 7 6 5 4 3 
0
*/


