#include<bits/stdc++.h>
using namespace std;
int n;
char ch[100010];
void print(){
	for(int i=1;i<=n;i++){
		printf("%c",ch[i]);
	}
	printf("\n");
}
void dfs(int step){
	if(step==(n+1)/2){
		print();
		return;
	}
	int pos=n-step+1;
	char c1=ch[step];
	char c2=ch[pos];
	ch[step]=c2;ch[pos]=c1;
	print();
	dfs(step+1);
}
int main(){
	freopen("17.in","r",stdin);
	freopen("17.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",ch+1);
	dfs(1);
	return 0; 
}
