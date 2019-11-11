#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cctype>
#include<set>
#define LL long long
#define M 400100
#define N 50010
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const int mod=10000;
const double eps=1e-6;
inline int read(){
	int f=1,x=0;char s=getchar();
	while(!isdigit(s)){if (s=='-')f=-1;s=getchar();}
	while(isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
int a,b;
signed main(void){
	freopen("cards.in","r",stdin);
	freopen("cards.out","w",stdout);
	a=read(),b=read();
	if (a==0){
		printf("%lld\n",-b*b);
		for (int i=1;i<=b;i++) printf("x");
		return 0;
	}
	if (b==0){
		printf("%lld\n",a*a);
		for (int i=1;i<=a;i++) printf("o");
		return 0;
	}
	if (a==b){
		printf("0\n");
		for (int i=1;i<=a;i++) printf("o");
		for (int i=1;i<=b;i++) printf("x"); 
	}
	if (a>b){
		printf("%lld\n",a*a-b*b);
		for (int i=1;i<=a;i++) printf("o");
		for (int i=1;i<=b;i++) printf("x"); 
	}
	return 0;
}

