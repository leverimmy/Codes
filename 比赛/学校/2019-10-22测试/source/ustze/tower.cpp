#include<bits/stdc++.h>
using namespace std;
const int N=1005;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
typedef long long ll;
#define sqr(x) ((x)*(x))
int n;
int x[N],y[N],fa[N];
inline int findf(int x){
	return fa[x]==x?x:fa[x]=findf(fa[x]);
}
inline bool in(int i,int j,int p){
	return (sqr(x[i]-x[j])+sqr(y[i]-y[j]))<=p;
}
inline bool check(int p){
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++)	
		for(int j=i+1;j<=n;j++)
			if(in(i,j,p)){
				int fx=findf(i),fy=findf(j);
				if(fx==fy) continue;
				fa[fx]=fy;
			}
	for(int i=1;i<=n;i++) if(findf(i)!=findf(1)) return 0;
	return 1;
}
int main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	int l=0,r=1e9,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d",ans);
	return 0;
}
