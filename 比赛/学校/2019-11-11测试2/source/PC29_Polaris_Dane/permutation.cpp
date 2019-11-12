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
#define M 400000
#define N 50010
using namespace std;
const int inf=0x7f7f7f7f;
const int mod=1e9+7;
const double eps=1e-6;
inline int read(){
	int f=1,x=0;char s=getchar();
	while(!isdigit(s)){if (s=='-')f=-1;s=getchar();}
	while(isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
int n,a[M],cnt[M],maxx,t[M],ans;
vector<int>s[M];
signed main(void){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),cnt[a[i]]++,maxx=max(maxx,a[i]);
	for (int i=2;i<=maxx;i++)
		if (cnt[i]>cnt[i-1]){
			printf("-1");return 0;
		}
	for (int i=1;i<=n;i++){
		t[i]=s[a[i]].size()+1;
		s[a[i]].push_back(i);
		ans=max(ans,int(s[a[i]].size()));
	}
	printf("%d\n",ans);
	for (int i=1;i<=n;i++) printf("%d ",t[i]);
	return 0;
}

