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
const int inf=0x7f7f7f7f;
const int mod=1e9+7;
const double eps=1e-6;
inline int read(){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if (s=='-') f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x;
}
inline int solve(int x){
	if (x==0) return 0;
	else return 2*solve(x-1)+1;
}
signed main(void){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int n=read(),m=read();
	n=n/m+(n%m!=0);
	printf("%lld",solve(n));
	return 0;
}

