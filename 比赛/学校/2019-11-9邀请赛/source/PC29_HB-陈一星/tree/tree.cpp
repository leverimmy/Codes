#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cctype>
#include<set>
#include<stack>
#define LL long long
#define M 400100
#define N 50010
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const double eps=1e-6;
inline int read(){
	int f=1,x=0;char s=getchar();
	while(!isdigit(s)){if (s=='-')f=-1;s=getchar();}
	while(isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
int t,n,a[M],ans[M];
inline int gcd(int x,int y){
	return y?gcd(y,x%y):x;	
}
inline void work(int l,int r,int fa){
	int go=1;
	for (int i=l;i<=r;i++){
		int flag=1;
		for (int j=l;j<=r;j++){
			if (j==i) continue;
			if (gcd(a[i],a[j])!=1){
				flag=0;break;
			}
		}
		if (flag) go=0,ans[i]=fa,work(l,i-1,i),work(i+1,r,i);
	}
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	t=read();
	while (t--){
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		work(1,n,0);
		for (int i=1;i<=n;i++) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}

