#include<bits/stdc++.h>
using namespace std;

int n,r,m;
char ch;
int cnt;
int ans[1000010];
int main(){
	freopen("9.in","r",stdin);
	freopen("9.out","w",stdout);
	scanf("%d",&m);
	cin>>ch;
	scanf("%d",&n);
	cin>>ch;
	scanf("%d",&r);
	for(int i=1;i<=m;i++){
		if(i%n==r){
			ans[++cnt]=i;
		}
	}
	int t=0;
	for(int i=1;i<=cnt;i++){
		printf("%d",ans[i]);
		if(i%10==0){
			printf("\n");
		}
		else if(i!=cnt){
			printf(",");
		}
	}
}
