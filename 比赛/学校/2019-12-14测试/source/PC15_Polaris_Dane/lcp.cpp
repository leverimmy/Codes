#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cctype>
#include<map>
#include<queue>
#include<set>
#include<stack>
#define ull unsigned long long
const int M=300010;
const int mod=998244353;
const int inf=0x7f7f7f7f;
const int base=197;
using namespace std;
inline int read(void){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<3)+(x<<1)+(s^48),s=getchar();}
	return x*f;	
}
int n,m
ull hash[M];
char s[M];
inline ull qpow(int a,int b){
	ull ans=1;
	while (b){
		if (b&1) ans*=a;
		b>>=1,a*=a;
	}
	return ans;
}
inline int comp(int x,int y){
	ull hasha=hash[n]-hash[x-1]*qpow(base,n-x);
	int l=1,r=min(n-x+1,n-y+1);
	while (){
		
	}
}
signed main(void){
//	freopen("lcp.in","r",stdin);
//	freopen("lcp.out","w",stdout);
	n=read(),m=read();
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) hash[i]=hash[i-1]*base+s[i];
	for (int i=1;i<=m;i++){
		int a=read(),b=read();
		printf("%d\n",comp(a,b));
	}
	return 0;
}
