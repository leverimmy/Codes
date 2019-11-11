#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
const int N=50005;
const ll inf=1e18;
int n,m;
ll c1,c2;
struct edge{
	int u,v,w,d;
}e[N],a[N],b[N];
int fa[N],ff[N];
ll ans=inf;
inline bool cmp(const edge &x,const edge &y){
	return x.d<y.d;
}
inline bool cmp2(const edge &x,const edge &y){
	return x.w<y.w;
}
inline int findf(int x){
	return fa[x]==x?x:fa[x]=findf(fa[x]);
}
inline int findff(int x){
	return ff[x]==x?x:ff[x]=findff(ff[x]);
}
int main(){
	freopen("pay.in","r",stdin);
	freopen("pay.out","w",stdout);
	n=read(),m=read(),c1=read(),c2=read();
	for(int i=1;i<=m;i++){
		e[i].u=read(),e[i].v=read(),e[i].w=read(),e[i].d=read();
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+m+1,cmp);
	int num=0,flag=0;
	for(int i=1;i<=m;i++){
		if(flag){
				for(int j=1;j<=n-1;j++) a[j]=b[j],ff[j]=j;a[n]=e[i],ff[n]=n;
				sort(a+1,a+n+1,cmp2);
				int cnt=0,mx=0;
				for(int j=1;j<=n;j++) ff[j]=j;
				for(int j=1;j<=n;j++) {
					int tx=findff(a[j].u),ty=findff(a[j].v);
					if(tx==ty) continue;
					ff[tx]=ty;mx=max(mx,a[j].w);b[++cnt]=a[j];
				}
				ans=min(ans,c1*mx+c2*e[i].d);
		}else {
			int fx=findf(e[i].u),fy=findf(e[i].v);
			a[i]=e[i];
			if(fx!=fy) {
				num++;
				fa[fx]=fy;
				if(num==n-1){
					sort(a+1,a+i+1,cmp2);
					int cnt=0,mx=0;
					for(int j=1;j<=n;j++) ff[j]=j;
					for(int j=1;j<=i;j++) {
						int tx=findff(a[j].u),ty=findff(a[j].v);
						if(tx==ty) continue;
						ff[tx]=ty;mx=max(mx,a[j].w);b[++cnt]=a[j];
					}
					flag=1;
					ans=min(ans,c1*mx+c2*e[i].d);
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
5 10
8 8
1 4 5 7
3 5 8 6
3 4 8 6
4 3 6 10
3 2 5 9
1 3 7 4
1 5 7 7
4 2 6 4
2 1 10 4
4 3 7 5

*/
