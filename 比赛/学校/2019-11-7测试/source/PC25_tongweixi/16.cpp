#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int dx[5]={0, 1, 0, -1, 0};
const int dy[5]={0, 0, 1, 0, -1};
int n,s;
int ans[1000][1000];
void dfs(int x,int y,int now,int dir){
	ans[x][y]=now;
	if(x==1 && y==1 && dir==4){
		ans[x][y]=n;
		for(int i=1; i<=s; i++){
			for(int j=1; j<=s; j++){
				if(ans[i][j]==0){
					printf("   ");
				}
				else{
					printf("%d ",ans[i][j]);
				}
			}
			printf("\n");
		}
		exit(0);
	}
	if(x>s && y==1){
		dfs(x-1, y+1, now, 2);
	}
	if(x==s && y>s){
		dfs(x-1, y-1, now, 3);
	}
	if(x<1 && y==s){
		dfs(x+1, y-1, now, 4);
	}
	dfs(x+dx[dir], y+dy[dir], now+1, dir);
}
int main(){
	freopen("16.in", "r", stdin);
	freopen("16.out", "w", stdout);
	scanf("%d%d",&n,&s);
	dfs(1, 1, n, 1);
	return 0;
}

