#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdlib>
#define int long long
using namespace std;
const int M=21480000;
const int inf=0x7f7f7f7f;
const int mod=1e9+7;
const double eps=1e-6;
const int limit=21480000;
inline int read(){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if (s=='-') f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x;
}
int n;
inline int isprime(int r){
	for (int i=2;i<=sqrt(r);i++)
		if (r%i==0)	return 0;
	return 1;
}
signed main(void){
	freopen("5.in","r",stdin);
	freopen("5.out","w",stdout);
	n=read();
	for (int i=n+1;i;i++)
		if (isprime(i)){
			printf("%lld",i);
			return 0;
		}
	return 0;
}

