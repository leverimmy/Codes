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
int s,t,f[M][4],a,b,c,d;
signed main(void){
	freopen("19.in","r",stdin);
	freopen("19.out","w",stdout);
	s=read(),t=read();
	for (int i=0;i<=3;i++)
		for (int j=1;j<=2;j++)
			f[j][i]=1;
	a=read(),b=read(),c=read(),d=read();
	if (s<=1) printf("1 ");
	if (s<=2) printf("2 ");
	for (int i=3;i<=t;i++){
		f[i][0]=f[i-1][0]+f[i-2][0],f[i][0]%=a;
		f[i][1]=f[i-1][1]+f[i-2][1],f[i][1]%=b;
		f[i][2]=f[i-1][2]+f[i-2][2],f[i][2]%=c;
		f[i][3]=f[i-1][3]+f[i-2][3],f[i][3]%=d;
		if (f[i][0]&&f[i][1]&&f[i][2]&&f[i][3]&&i>=s) printf("%d ",i);
	}
	return 0;
}

