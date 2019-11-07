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
const int M=100000;
const int inf=0x7f7f7f7f;
const int mod=1e9+7;
const double eps=1e-6;
inline int read(){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if (s=='-') f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x;
}
double x;
signed main(void){
	freopen("11.in","r",stdin);
	freopen("11.out","w",stdout);
	while (1){
		scanf("%lf",&x);
		double cnt=0.0;
		int i;
		if (abs(x-0)<=eps) break;
		for (i=2;i;i++)
			if (cnt+1.0/i>x) break;
			else cnt+=1.0/i;
		printf("%d card(s)",i-1);
	}
	return 0;
}

