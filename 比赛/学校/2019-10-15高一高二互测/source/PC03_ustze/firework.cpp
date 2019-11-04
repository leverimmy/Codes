#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
const int N=100005;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
int n,m,L;
typedef long long ll;
struct node{
	int t,p;
}a[N];
int b[N];ll f[N];
vector<int> G[N];
int main(){
	freopen("firework.in","r",stdin);
	freopen("firework.out","w",stdout);
	n=read(),L=read();
	for(int i=1;i<=n;i++) {
		a[i].t=read(),a[i].p=read();
		b[i]=a[i].t;
	}
	sort(b+1,b+n+1); m=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++){
		a[i].t=lower_bound(b+1,b+m+1,a[i].t)-b;
		G[a[i].t].push_back(a[i].p);
	}
	for(int i=1;i<=m;i++){
		
		for(int j=2;j<=L;j++){
			f[j]=min(f[j],f[j-1]);
		}
		for(int j=1;j<=L;j++)
			for(int k=0;k<G[i].size();k++)
				f[j]+=abs(j-G[i][k]);
		//for(int j=1;j<=L;j++) printf("%d")
	}
	printf("%lld",*min_element(f+1,f+L+1));
	return 0;
}
