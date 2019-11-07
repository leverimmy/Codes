#include<bits/stdc++.h>
using namespace std;
int m,n,r,cnt=1;
int main(){
	freopen("9.in","r",stdin);
	freopen("9.out","w",stdout);
	scanf("%d%*c%d%*c%d",&m,&n,&r);
	for(int i=1;i<=m;++i){
		if(i%n==r){
			if(cnt==1){
				printf("%d",i);
				cnt++;
			}
			else if(cnt>1&&cnt<10){
				printf(",%d",i);
				cnt++;
			}
			else{
				printf(",%d\n",i);
				cnt=1;
			}
		}
	}
	return 0;
}
