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
int l,r,cnt;
signed main(void){
	freopen("10.in","r",stdin);
	freopen("10.out","w",stdout);
	l=read(),r=read();
	for (int i=l;i<=r;i+=5){
		if (!cnt)
			for (int j=i;j<=min(i+4,r);j++)
				printf("%d ",j);
		else
			for (int j=min(r,i+4);j>=i;j--)
				printf("%d ",j);
		puts("");
		cnt^=1;
	}
	return 0;
}

