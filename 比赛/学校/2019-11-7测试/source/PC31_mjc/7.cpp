#include<bits/stdc++.h>
using namespace std;
int n,r,m;
char ch;
int vis[10];
int ans[1000];
int a[30][30];
int ct=0;
int check(){
	int c=0;
	for(int i=1;i<=n;i++){
		if(ans[i]==1) c++;
	}
	if(c<=(n-c)) return 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(ans[i]==1 && ans[j]==1){
				if(a[i][j]==0){
					return 0;
				} 
			}
		}
	}
	return 1;
} 
void dfs(int step){
	if(step==n+1){
		ct++;
		if(ct%2==1) return;
		if(check()==1){
			for(int i=1;i<=n;i++){
				if(ans[i]) printf("%d ",i);
			}
			cout<<endl;	
		}
		return;
	}
	for(int i=0;i<=1;i++){
		step++;
		ans[step]=i;
		dfs(step);
		ans[step]=0;
		step--;
	}
}
int main(){
	freopen("7.in","r",stdin);
	freopen("7.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	dfs(0);
}
