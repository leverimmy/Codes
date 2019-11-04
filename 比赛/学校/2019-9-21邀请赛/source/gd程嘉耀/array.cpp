#pragma GCC optime(2)
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+6;
int n,m,a[maxn],p,k;
int tot,pos;
int h[maxn][350];
void zhixing(int pp,int kk,int cs){
	if(pp>n){
		printf("%d\n",cs);
		return;
	}
	else{
		zhixing(pp+kk+a[pp],kk,cs+1);
	}
}
int main(){
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	scanf("%d",&n);
	for(register int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	
	if(n<=100&&m<=100){
		for(register int i=1;i<=m;i++){
			scanf("%d%d",&p,&k);
			zhixing(p,k,0);
		}
	}
	else{
		for(register int j=0;j<=312;j++){
			for(register int i=n;i>=1;i--){
				if(i+a[i]+j>n){
					h[i][j]=1;
				}
				else{
					h[i][j]=h[i+a[i]+j][j]+1;
				}
			}
		}
		
		for(register int i=1;i<=m;i++){
			scanf("%d%d",&p,&k);
			if(k>312){
				zhixing(p,k,0);
			}
			else{
				printf("%d\n",h[p][k]);
			}
			//cout<<h[p]<<endl;
		}
		
	}
}
