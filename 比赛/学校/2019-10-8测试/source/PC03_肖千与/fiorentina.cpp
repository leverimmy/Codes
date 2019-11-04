#include<bits/stdc++.h>
using namespace std;
const int N=100005,mod=998244353;
int n,p;
int f[N];
int main(){
	freopen("fiorentina.in","r",stdin);
	freopen("fiorentina.out","w",stdout);
	scanf("%d%d",&n,&p);
	f[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=p;j>=i;j--){
			f[j]+=f[j-i];
			if(f[j]>=mod) f[j]-=mod;
		}
	printf("%d",f[p]);
	return 0;
}

