#include<bits/stdc++.h>
using namespace std;

int a,b;
int cnt;
int ans[100010];
int out[100][100];
int main(){
	freopen("10.in","r",stdin);
	freopen("10.out","w",stdout);
	scanf("%d%d",&a,&b);
	for(int i=a;i<=b;i++){
		ans[++cnt]=i;
	}
	int c=0;
	int now=1;
	for(int i=1;i<=cnt;i++){
		out[now][++c]=ans[i];
		if(i%5==0){
			if(now%2==0){
				reverse(out[now]+1,out[now]+6);
			}
			now++;
			c=0;
		}
	}
	for(int i=1;i<=now;i++){
		for(int j=1;j<=5;j++){
			if(out[i][j]==0) return 0;
			printf("%d ",out[i][j]);
		}
		printf("\n");
	} 
}
