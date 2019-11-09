#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
const int N=1e5+5,mx=1e7;
int n;
int fa[N],np[mx+5],pri[mx+5],min_fac[mx+5];
int tot=0;
int L[N],R[N],a[N];
int mp[mx+5];
inline bool check(int x,int l,int r){
	return L[x]<=l&&R[x]>=r;
}
void dfs(int l,int r,int f){
	if(l>r) return;
	if(l==r) {
		fa[l]=f;
		return;
	}
	int x=l,y=r;
	while(1){
		if(check(x,l,r)){
			fa[x]=f;
			dfs(l,x-1,x);dfs(x+1,r,x);
			return;
		}
		x++;
		if(x>y) return;
		if(check(y,l,r)) {
			fa[y]=f;
			dfs(l,y-1,x);dfs(y+1,r,x);
			return;
		}
		y--;
		if(x>y) return;
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	min_fac[1]=1;
	for(int i=2;i<=mx;i++){
		if(!np[i]) pri[++tot]=i,min_fac[i]=i;
		for(int j=1;j<=tot&&1ll*pri[j]*i<=mx;j++){
			int to=pri[j]*i;
			np[to]=1,min_fac[to]=pri[j];
			if(i%pri[j]==0) break;
		}
	}
	int T=read();
	while(T--){
		n=read(); 
		for(int i=1;i<=n;i++) a[i]=read(),L[i]=1,R[i]=n;
		memset(mp,0,sizeof(mp));
		for(int i=1;i<=n;i++) {
			int x=a[i];
			while(x!=1) {
				int t=min_fac[x];
				L[i]=max(L[i],mp[t]+1);
				mp[t]=i;
				while(x%t==0) x/=t;
			}
		}
		memset(mp,0x3f,sizeof(mp));
		for(int i=n;i>=1;i--) {
			int x=a[i];
			while(x!=1) {
				int t=min_fac[x];
				R[i]=min(R[i],mp[t]-1);
				mp[t]=i;
				while(x%t==0) x/=t;
			}
		}
		dfs(1,n,0);
		for(int i=1;i<=n;i++) printf("%d ",fa[i]);
		puts("");
	}
	return 0;
}
