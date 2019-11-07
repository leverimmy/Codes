#include<bits/stdc++.h>
using namespace std;
const int S=34;
int k;
int a[5][5];
int vis[20];
inline bool check(){
	int s=0;
	for(int i=1;i<=4;i++) s+=a[i][i];
	if(s!=S) return 0;
	return 1;
}
void dfs(int x,int y){
	if(x>4) {
		if(check()){
			k--;
			if(k==0) {
				for(int i=1;i<=4;i++){
					for(int j=1;j<=4;j++)
						printf("%d ",a[i][j]);
					puts("");
				}
				exit(0);
			}
		}
		return;
	}
	int tx=x,ty=y+1;
	if(ty>4) tx++,ty=1;
	for(int i=1;i<=16;i++) {
		if(!vis[i]){
			vis[i]=1,a[x][y]=i;
			if(ty==1) {
				int s=0;
				for(int j=1;j<=4;j++) s+=a[x][j];
				if(s!=S) {
					vis[i]=0;
					continue;
				}
			}
			if(x==4){
				int s=0;
				for(int j=1;j<=4;j++) s+=a[j][y];
				if(s!=S) {
					vis[i]=0;
					continue;
				}
				if(y==1) {
					s=0;
					for(int j=1;j<=4;j++) s+=a[j][4-j+1];
					if(s!=S) {
						vis[i]=0;continue;
					}
				}
			}
			dfs(tx,ty); 
			vis[i]=0;
		}
	}
}
int main(){
	freopen("20.in","r",stdin);
	freopen("20.out","w",stdout);
	scanf("%d",&k);
	dfs(1,1);
	return 0;
}
