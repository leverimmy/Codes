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
int n;
signed main(void){
	freopen("7.in","r",stdin);
	freopen("7.out","w",stdout);
	int n=read();
	for (int i=1;i<=n;i++){
		int cnt=0;
		for (int j=1;j<=n;j++){
			int x=read();
			cnt+=x;
		}
		if (cnt>n/2) printf("%d ",i);
	}
	return 0;
}

