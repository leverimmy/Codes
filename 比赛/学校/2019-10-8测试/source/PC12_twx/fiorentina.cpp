#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
 
using namespace std;
const int N = 2010;
const int mod = 998244353;
int f[N];
int n,p;
int main(){
	freopen("fiorentina.in","r",stdin);
	freopen("fiorentina.out","w",stdout);
		scanf("%d%d",&n,&p);
	f[0]=1;
	for(int i=1; i<=n; i++){
		for(int j=p; j>=i; j--){
			f[j]=(f[j]+f[j-i])%mod;
		}
	}
	printf("%d\n",f[p]);
	return 0;
}

