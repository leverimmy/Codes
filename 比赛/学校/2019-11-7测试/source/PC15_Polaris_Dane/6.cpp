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
int n,len1,len2;
char s[30][M];
signed main(void){
	freopen("6.in","r",stdin);
	freopen("6.out","w",stdout);
	n=read();
	s[1][1]='A';len2=1;
	for (int i=2;i<=n;i++){
		len1=len2*2+1;
		for (int j=1;j<=len2;j++) s[i][j]=s[i-1][j];
		s[i][len2+1]='A'+i-1;
		for (int j=len1;j>=len1-len2+1;j--) s[i][j]=s[i-1][len1-j+1];
		len2=len1;
	}
	for (int i=1;i<=len1;i++)
		printf("%c",s[n][i]);
	return 0;
}

