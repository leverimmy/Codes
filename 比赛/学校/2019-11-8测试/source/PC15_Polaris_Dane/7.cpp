#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
#include<cctype>
#include<stack>
#include<queue>
using namespace std;
const int M=200200;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
inline int read(){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
int n;
int prime[M],tot,is[M];
inline void get_prime(void){
	for (int i=2;i<=n;i++){
		if (!is[i]) prime[++tot]=i;
		for (int j=1;j*i<=n;j++){
			is[i*j]=1;
			if (j%i==0) break;
		}
	}
}
signed main(void){
	freopen("7.in","r",stdin);
	freopen("7.out","w",stdout);
	n=read();
	get_prime();
	for (int i=1;i<=tot;i++)
		printf("%d ",prime[i]);
	return 0;
}
