#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<cctype>
#include<map>
#include<vector>
#define int long long
using namespace std;
const int mod=1e9+7;
const double eps=1e-6;
const int inf=0x3f3f3f3f;
const int M=202000;
inline int read(){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if (s=='-') f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<3)+(x<<1)+(s^48);s=getchar();}
	return x*f;
}
int ans=1;
inline void gcd(int a,int b){
	if (b==0) return;
	ans+=a/b;
	gcd(b,a%b);
}
int n,m;
signed main(void){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	n=read(),m=read();
	gcd(n,m);
	printf("%lld",ans);
	return 0;
}
