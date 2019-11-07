#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 10010;
int n,cntp;
bool vis[N];
int pri[N];
int cntans;
int ans[N],cnt[N];
void init(){
	for(int i=2; i<=n; i++){
		if(!vis[i]){
			pri[++cntp]=i;
			for(int j=1; i*j<=n; j++){
				vis[i*j]=1;
			}
		}
	}
}
int main(){
	freopen("13.in", "r", stdin);
	freopen("13.out", "w", stdout);
	scanf("%d",&n);
	printf("%d=",n);
	init();
	for(int i=1; i<=cntp; i++){
		if((n%pri[i])==0){
			ans[++cntans]=pri[i];
			while((n%pri[i])==0){
				cnt[cntans]++;
				n/=pri[i];
			}
		}
	}
	for(int i=1; i<=cntans; i++){
		if(cnt[i]==1){
			printf("%d",ans[i]);
		}
		else{
			printf("%d^%d",ans[i],cnt[i]);
		}
		if(i!=cntans){
			printf("*");
		}
	}
	return 0;
}

