#include<bits/stdc++.h>
using namespace std;

int a,b,m;
char ch;
int main(){
	freopen("8.in","r",stdin);
	freopen("8.out","w",stdout);
	scanf("%d",&a);
	cin>>ch;
	scanf("%d",&b);
	cin>>ch;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			if(i*a+j*b<=m){
				printf("%d,%d\n",i,j);
			}
		}
	}
}
