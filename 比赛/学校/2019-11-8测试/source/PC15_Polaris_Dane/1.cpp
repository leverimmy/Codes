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
#define int long long
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
int a,b,c,ans;
inline void qpow(int b){
	ans=1;
	while (b){
		if (b&1) ans*=a,ans%=c;
		a*=a,a%=c,b>>=1;
	}
}
signed main(void){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	a=read(),b=read(),c=read();
	qpow(b);
	printf("%lld",ans%c);
	return 0;	
}

