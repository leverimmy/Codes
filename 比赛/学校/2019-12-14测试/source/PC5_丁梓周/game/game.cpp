#include<iostream>
#include<cstdio>
using namespace std;
int n,s,a[110];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int sum=0;
	while(1==1){
		sum=0;
		scanf("%d%d",&n,&s);
		if(n==0)return 0;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a[i*2-1],&a[i*2]);
			sum+=1+a[i*2];
		}
		s=(s-1)%sum;
		if(s==0){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i*2-1]>=s){
				cout<<1<<endl;
				break;
			}
			if(i==n)cout<<0<<endl;
		}
		
	}
	return 0;
}
