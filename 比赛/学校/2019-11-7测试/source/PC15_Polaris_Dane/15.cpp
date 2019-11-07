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
int n,pos,num;
signed main(void){
	freopen("15.in","r",stdin);
	freopen("15.out","w",stdout);
	n=read();
	for (int i=0;i<n;i++){
		int x=read();
		if (x>num) num=x,pos=i;
	}
	printf("%d %d",num,pos);
	return 0;
}

