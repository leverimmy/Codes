#include<bits/stdc++.h>
using namespace std;

int vis[10];
int a[100][100];
int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};
int n,s;
void dfs(int x,int y,int op,int num){
	a[x][y]=num;
	x+=dx[op];
	y+=dy[op];
	if(x==s+1){
		op=1;
		x=s;
		y=2;
	}
	if(x==0){
		op=2;
		x=1;
		y=s-1;
	}
	if(y==0){
		op=3;
		x=2;
		y=1;
	}
	if(y==s+1){
		op=4;
		x=s-1;
		y=s;
	}
	if(a[x][y]!=0) return; 
	num++; 
	dfs(x,y,op,num);
}
int main(){
	freopen("16.in","r",stdin);
	freopen("16.out","w",stdout);
	scanf("%d%d",&n,&s);
	if(s==1){
		printf("%d",n);
		return 0;
	}
	dfs(1,1,3,n);
	for(int i=1;i<=s;i++){
		for(int j=1;j<=s;j++){
			if(a[i][j])
				printf("%d ",a[i][j]);
			else printf("   ");
		}
		printf("\n");
	}
}
