#include <bits/stdc++.h>
#define maxn 100008
const int block=35;
int n,q,a[maxn],ans[maxn],vis[maxn]={0},l,r,p,v,size,tl=0,tl2=0;
struct BIT{
	int sum[maxn]={0};
	inline void add(int p,int v){
		while (p<=n){sum[p]+=v;p+=p&-p;}
	}inline int query(int p){
		if (p==0)return 0;int ans=0;
		while (p>0){ans+=sum[p];p-=p&-p;}return ans;
	}inline int Query(int l,int r){return query(r)-query(l-1);}
}bit[block+1];
struct query{int l,r,p,v,id;}qry[maxn],qry2[maxn];
int cmp2(query a,query b){return a.p<b.p;}
int cmp(query a,query b){if (a.l/size!=b.l/size)return a.l/size<b.l/size;return a.r<b.r;}
inline void extend(int x){vis[a[x]]++;}
inline void remove(int x){vis[a[x]]--;}

int main(){
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	scanf("%d%d",&n,&q);size=300;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=q;++i){
		scanf("%d%d%d%d",&l,&r,&p,&v);
		if (p<=block){
			qry2[++tl2].l=l;qry2[tl2].r=r;qry2[tl2].p=p;qry2[tl2].v=v;qry2[tl2].id=i;
		} else {qry[++tl].l=l;qry[tl].r=r;qry[tl].p=p;qry[tl].v=v;qry[tl].id=i;}
	}std::sort(qry+1,qry+tl+1,cmp);std::sort(qry2+1,qry2+tl2+1,cmp2);
	for(int i=block;i>=1;i--){
		if (!tl2||qry2[tl2].p!=i)continue;
		for(int j=1;j<=n;++j)bit[a[j]%i].add(j,1);
		while (tl2>0&&qry2[tl2].p==i){ans[qry2[tl2].id]=bit[qry2[tl2].v].Query(qry2[tl2].l,qry2[tl2].r);tl2--;}
		for(int j=1;j<=n;++j)bit[a[j]%i].add(j,-1);
	}int l=1,r=0;
	for(int i=1;i<=tl;++i){
		while (r<qry[i].r)extend(++r);
		while (l>qry[i].l)extend(--l);
		while (l<qry[i].l)remove(l++);
		while (r>qry[i].r)remove(r--);
		for (register int j=qry[i].v;j<=1e4;j+=qry[i].p)ans[qry[i].id]+=vis[j];
	}for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
	return 0;
} 
