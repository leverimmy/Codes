#include<bits/stdc++.h>
using namespace std;

int n,r,m;
int num[10010];
int t[100010]; 
int cnt;
int main(){
	freopen("13.in","r",stdin);
	freopen("13.out","w",stdout);
	scanf("%d",&n);
	printf("%d=",n);
	for(int i=2;i<=n;i++){
		if(n%i==0){
			num[++cnt]=i;
			while(1){
				if(n%i!=0){
					break;
				}
				n=n/i;
				t[cnt]++;				
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		if(i==1){
			if(t[i]>1){
				printf("%d^%d",num[i],t[i]);
			}
			else{
				printf("%d",num[i]);
			}
		}
		else{
			if(t[i]>1){
				printf("*%d^%d",num[i],t[i]);
			}
			else{
				printf("*%d",num[i]);
			}			
		}
	}
}
