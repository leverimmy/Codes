#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
struct node{
	int num[5][5];
}I,g1,g2,ori1,ori2;

node operator * (const node &a,const node &b){
	node ans;
	for(int i=1;i<=2;i++){
		for(int j=1;j<=2;j++){
				ans.num[i][j]=0;
			for(int k=1;k<=2;k++){
				ans.num[i][j]=(ans.num[i][j]+a.num[i][k]*b.num[k][j]%mod)%mod;	
			}
		}
	}
	return ans;
} 

node qpow(node a,int y){
	node ans=I;
	while(y){
		if(y&1){
			ans=ans*a;
		}
		a=a*a;
		y>>=1; 
	}
	return ans;
}
int t,n,tp;
signed main(){
	freopen("puzzle.in", "r", stdin);
	freopen("puzzle.out", "w", stdout); 
	g1.num[1][1]=0;
	g1.num[1][2]=1;
	g1.num[2][1]=-3;
	g1.num[2][2]=5;
	ori1.num[1][1]=2;
	ori1.num[2][1]=7;
	g2.num[1][1]=0;
	g2.num[1][2]=1;
	g2.num[2][1]=1;
	g2.num[2][2]=1;
	ori2.num[1][1]=1;
	ori2.num[2][1]=2;
	scanf("%lld%lld",&t,&tp);
	I.num[1][1]=I.num[2][2]=1;
	if(tp==1){
		while(t--){
			scanf("%lld",&n);
			node p=qpow(g2,n-1)*ori2;
			printf("%lld\n",(p.num[1][1]+mod)%mod);
		}
	}
	else{
		while(t--){
			scanf("%lld",&n);
			node p=qpow(g1,n-1)*ori1;
			printf("%lld\n",(p.num[1][1]+mod)%mod);
		}
	}
	
}
