#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<cctype>
#include<map>
#include<vector>
using namespace std;
const int mod=1e9+7;
const double eps=1e-6;
const int inf=0x3f3f3f3f;
const int M=100010;
inline int read(){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if (s=='-') f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<3)+(x<<1)+(s^48);s=getchar();}
	return x*f;
}
inline void write(int x){
	if (!x) return;
	write(x/10);
	putchar(x%10+48);
}
int n,m,a[M],maxx;
vector<int>t[10010];
signed main(void){
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read(),t[a[i]].push_back(i),maxx=max(maxx,a[i]);
	for (int i=1;i<=m;i++){
		int l=read(),r=read(),p=read(),v=read(),ans=0;
		for (int j=v;j<=maxx;j+=p){
			int ml=lower_bound(t[j].begin(),t[j].end(),l)-t[j].begin();
			int mr=upper_bound(t[j].begin(),t[j].end(),r)-t[j].begin();
			ans+=mr-ml;
		}
		if (!ans){
			puts("0");continue;
		}
		write(ans),puts("");
	}
	return 0;
}
