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
const int M=1000000;
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
char s[M];
signed main(void){
	freopen("17.in","r",stdin);
	freopen("17.out","w",stdout);
	n=read(),scanf("%s",s);
	for (int i=0;(i+1)<<1<n;i++){
		swap(s[i],s[len-i-1]);
		printf("%s\n",s);
	}
	printf("%s\n",s);
	return 0;
}

