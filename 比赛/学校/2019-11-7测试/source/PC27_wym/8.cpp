#include<bits/stdc++.h>
using namespace std;
int a,b,m;
int main(){
	freopen("8.in","r",stdin);
	freopen("8.out","w",stdout);	
	scanf("%d%*c%d%*c%d",&a,&b,&m);
	for(int i=1;i<=m/a+1;++i){
		for(int j=i;j<=m/b+1;++j){
			if(a*i+b*j<=m){
				printf("%d,%d\n",i,j);
			}
			else
				break;
		}
	}
	return 0;
}
