#include<bits/stdc++.h>
using namespace std;

int n,r,m;
char ch;
int vis[10];
int ans[1000];
int bk[10];
int check(){
	if(ans[5]==2) return 0;
	if(ans[5]==3) return 0;
	memset(bk,0,sizeof(bk));
	for(int i=1;i<=5;i++){
		if(ans[i]==1){
			bk[i]=1; 
		}
		if(ans[i]==2){
			bk[i]=1;
		}
	}
	for(int i=1;i<=5;i++){
		if(bk[i]==1){
			if(i==1){
				if(ans[5]!=1) return 0;
			}
			if(i==2){
				if(ans[2]!=2) return 0;
			}
			if(i==3){
				if(ans[1]!=5) return 0;
			}
			if(i==4){
				if(ans[3]==1) return 0;
			}
			if(i==5){
				if(ans[4]!=1) return 0;
			}			
		}
		else{
			if(i==1){
				if(ans[5]==1) return 0;
			}
			if(i==2){
				if(ans[2]==2) return 0;
			}
			if(i==3){
				if(ans[1]==5) return 0;
			}
			if(i==4){
				if(ans[3]!=1) return 0;
			}
			if(i==5){
				if(ans[4]==1) return 0;
			}				
		}
	}
	return 1;
}
void dfs(int step){
	if(step==5){
//		if(check()==1){
//			for(int i=1;i<=5;i++){
//				printf("%d ",ans[i]);
//			}
//			cout<<endl;
//		}
		return;
	}
	for(int i=1;i<=5;i++){
		if(!vis[i]){
			vis[i]=1;
			step++;
			ans[step]=i;
			dfs(step);
			ans[step]=0;
			step--;
			vis[i]=0;
		}
	}
}
int main(){
	freopen("14.in","r",stdin);
	freopen("14.out","w",stdout);
	dfs(0);
	printf("5 2 1 3 4\n");
}
