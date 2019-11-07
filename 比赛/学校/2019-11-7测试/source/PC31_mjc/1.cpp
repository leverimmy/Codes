#include<bits/stdc++.h>
using namespace std;
int n,m;
int qpow(int x,int y){
	int ret=1;
	while(y){
		if(y&1){
			ret=ret*x;
		}
		x=x*x;
		y>>=1;
	}
	return ret;
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x=(n+m-1)/2;
	printf("%d\n",qpow(2,x)-1);
}
