#include<bits/stdc++.h>
using namespace std;
int no[1000010],pri[100010];
int cnt;
int n,m;
void init(){
	for(int i=2;i<=n;i++){
		if(!no[i]){
			pri[++cnt]=i;
		}
		for(int j=1;j<=cnt&&pri[j]*i<=n;j++){
			no[i*pri[j]]=1;
		}
	}
}

int main(){
	freopen("7.in","r",stdin);
	freopen("7.out","w",stdout);
	scanf("%d",&n);
	init();
	for(int i=2;i<=n;i++){
		if(!no[i]){
			printf("%d ",i);
		}
	}
}
