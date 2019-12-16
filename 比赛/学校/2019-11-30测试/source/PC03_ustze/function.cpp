#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
int n;
int x[N],y[N],xx[N],yy[N],f[N];
int rt[N],ls[N*105],rs[N*105],mx[N*105];
int tot=0;
inline void update(int &rt,int l,int r,int p,int v){
	if(!rt) rt=++tot;
	if(l==r) {mx[rt]=max(mx[rt],v);return;}
	int mid=(l+r)>>1;
	if(p<=mid) update(ls[rt],l,mid,p,v);
	else update(rs[rt],mid+1,r,p,v);
	mx[rt]=max(mx[ls[rt]],mx[rs[rt]]);
} 
inline int query(int rt,int l,int r,int p) {
	if(!rt) return 0;
	if(r<=p) return mx[rt];
	int mid=(l+r)>>1;
	if(p<=mid) return query(ls[rt],l,mid,p);
	else return max(mx[ls[rt]],query(rs[rt],mid+1,r,p));
}
int main(){
	freopen("function.in","r",stdin);
	freopen("function.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) {
		x[i]=read(),y[i]=read();
		xx[i]=x[i],yy[i]=y[i];
	}
	sort(xx+1,xx+n+1);sort(yy+1,yy+n+1);
	int c1=unique(xx+1,xx+n+1)-xx-1,c2=unique(yy+1,yy+n+1)-yy-1;
	int ans=0;
	for(int i=1;i<=n;i++) {
		x[i]=lower_bound(xx+1,xx+c1+1,x[i])-xx;
		y[i]=lower_bound(yy+1,yy+c2+1,y[i])-yy;
		for(int j=x[i]-1;j;j-=j&-j) f[i]=max(f[i],query(rt[j],1,c2,y[i]-1));
		f[i]++;
		for(int j=x[i];j<=c1;j+=j&-j) update(rt[j],1,c2,y[i],f[i]);
		ans=max(ans,f[i]);
	}
	printf("%d",ans);
	return 0;
} 
/*
8
1 3
3 2
1 1
4 5
6 3
9 9
8 7
7 6
*/
