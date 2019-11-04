#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<time.h>
#define M 1010000
#define rgi register int
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const int mod=998244353;
inline int read(){
	int x=0,f=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while(isdigit(s)){x=(x<<1)+(x<<3)+(s^48),s=getchar();}
	return x*f;
}
int n,x[M],y[M],fa[M],dis[1200][1200];
inline int find(int a){
	return fa[a]==a?fa[a]:find(fa[a]);
}
inline int judge(int x){
	int cnte=n;
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=n;i++){
		for (int j=1;j<i;j++){
			if (dis[i][j]>x) continue;
			int X=find(i),Y=find(j);
			if (X!=Y) cnte--,fa[X]=Y;
			if (cnte==1) return 1;
		}
	}
	return cnte==1;
}
signed main(void){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	int l=1,r=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			dis[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]),r=max(r,dis[i][j]);
	while (l<r){
		int mid=(l+r)>>1;
		if (judge(mid)) r=mid;
		else l=mid+1;
	}
	printf("%lld",l);
	return 0;
}
