#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<stack> 
#include<queue>
#define M 400100
using namespace std;
struct line{
	int l,val,num;
	bool operator <(const line&a)const{
		return val<a.val;
	}
};
priority_queue<line>pq;
struct node
{
	int lc,rc;
	int cnt;
}t[M*4];
int n,k,s[M],root[M],cnte,a[M],ans,l,r,maxx;
int build(int x,int y)
{
	int rt=++cnte;
	int mid=(x+y)>>1;
	if (x<y)
		t[rt].lc=build(x,mid),t[rt].rc=build(mid+1,y);
	return rt;
}
int insert(int x,int y,int pre,int num)
{
	int rt=++cnte,mid=(x+y)>>1;
	t[rt].lc=t[pre].lc;
	t[rt].rc=t[pre].rc;
	t[rt].cnt=t[pre].cnt+1;
	if (x<y)
		if (num<=mid)
			t[rt].lc=insert(x,mid,t[pre].lc,num);
		else
			t[rt].rc=insert(mid+1,y,t[pre].rc,num);
	return rt;
}
int get_rank(int l,int r,int rank,int pos1,int pos2)
{
	if (l==r)return l;
	int mid=(l+r)>>1;
	int tmp=t[t[pos2].lc].cnt-t[t[pos1].lc].cnt;
	if (rank<=tmp) return get_rank(l,mid,rank,t[pos1].lc,t[pos2].lc);
	else return get_rank(mid+1,r,rank-tmp,t[pos1].rc,t[pos2].rc);
}
signed main(void)
{
//	freopen("sequence.in","r",stdin);
//	freopen("sequence.out","w",stdout);
	scanf("%d %d %d %d",&n,&k,&l,&r);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),s[i]=s[i-1]+a[i],maxx=max(maxx,s[i]);
	root[0]=build(1,maxx);
	for (int i=1;i<=n;i++)
		root[i]=insert(1,n,root[i-1],s[i]);
	for (int i=1;i<=n;i++){
		line tmp;tmp.l=i,tmp.num=1,tmp.val=s[get_rank(1,maxx,1,root[i+l-1],root[i+r])];
		pq.push(tmp);
	}
	for (int i=1;i<=k;i++){
		line h=pq.top();pq.pop();
		ans+=h.val;
		line tmp;tmp.l=h.l,tmp.num=h.num+1,tmp.val=s[get_rank(1,maxx,h.num+1,root[h.l+l-1],root[h.l+r])];
		pq.push(tmp);
	}
	printf("%d",ans);
	return 0;
}

