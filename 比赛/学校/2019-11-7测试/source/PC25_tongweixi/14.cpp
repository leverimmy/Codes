#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define D1 (ans[5]==1)
#define D2 (ans[2]==2)
#define D3 (ans[1]==5)
#define D4 (ans[3]!=1)
#define D5 (ans[4]==1)
using namespace std;
int ans[6];
bool vis[6];
int rk[6];
bool f[6];
bool check(){
	if(ans[5]==2 || ans[5]==3){
		return 0;
	}
	memset(f, 0, sizeof f);
	for(int i=1; i<=5; i++){
		rk[ans[i]]=i;
	}
	f[rk[3]]=1;
	f[rk[4]]=1;
	f[rk[5]]=1;
	if((D1^f[1]) && (D2^f[2]) && (D3^f[3]) && (D4^f[4]) && (D5^f[5])){
		return 1;
	}
	return 0;
}
void dfs(int now){
	if(now==5){
		if(check()){
			for(int i=1; i<=5; i++){
				printf("%d ",ans[i]);
			}
		}
		return;
	}
	for(int i=1; i<=5; i++){
		if(!vis[i]){
			vis[i]=1;
			ans[now+1]=i;
			dfs(now+1);
			ans[now+1]=0;
			vis[i]=0;
		}
	}
}
int main(){
	freopen("14.in", "r", stdin);
	freopen("14.out", "w", stdout);
	dfs(0);
	return 0;
}

