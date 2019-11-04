#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<climits>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
#define S 320
#define MAXN 100000
#define NUM 10000
#define lb(p) t[p].lb
#define rb(p) t[p].rb
#define l(p) t[p].l
#define r(p) t[p].r
#define val(p,x) t[p].val[x]
#define sum(p,x) t[p].sum[x]
#define siz(p) (t[p].r-t[p].l)+1
#define gets(p,x,y) t[p].gets[x][y]
#define sums(p,x,y) t[p].sums[x][y]
#define SNUM 100
int v[MAXN+10],bl[MAXN+10],bS;
struct node
{
	int lb,rb,l,r;
	int val[NUM+5],sum[NUM+5];
	int gets[SNUM+2][SNUM+2],sums[SNUM+2][SNUM+2];
}t[S+5];
void build_block(int n)
{
	for(int i=1;i<=n;i++)
	{
		bl[i]=(i-1)/S+1;
		val(bl[i],v[i])++;
		for(int p=1;p<=SNUM;p++)
			gets(bl[i],p,v[i]%p)++;
	}
	bS=bl[n];
	for(int i=1;i<=n;i++)
		r(bl[i])=i;
	for(int i=n;i>=1;i--)
		l(bl[i])=i;
	for(int i=1;i<=bS;i++)
	{
		lb(i)=i-1;
		rb(i)=i+1;
		if(i==1)
			lb(i)=i;
		if(i==bS)
			rb(i)=i;
		for(int p=0;p<=NUM;p++)
			sum(i,p)=sum(i-1,p)+val(i,p);
		for(int k=1;k<=SNUM;k++)
			for(int p=0;p<=SNUM;p++)
				sums(i,k,p)=sums(i-1,k,p)+gets(i,k,p);
	}
}
int query(int l,int r,int p,int k)
{
	int lp=bl[l],rp=bl[r],ans(0);
	if(rp-lp<=1)
	{
		for(int i=l;i<=r;i++)
			if(v[i]%p==k)
				ans++;
		return ans;
	}
	lp=rb(lp),rp=lb(rp);
	for(int i=l;i<=l(lp)-1;i++)
		if(v[i]%p==k)
			ans++;
	for(int i=r(rp)+1;i<=r;i++)
		if(v[i]%p==k)
			ans++;
	if(p>=SNUM)
		for(int i=0;i*p+k<=NUM;i++)
			ans+=sum(rp,i*p+k)-sum(lp-1,i*p+k);
	else
		ans+=sums(rp,p,k)-sums(lp-1,p,k);
	return ans;
}
signed main()
{
	/*
		int ❄,😀;
		scanf("%d%d",&❄,😀);
		return!printf("%d\n",❄+😀);
	*/
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	build_block(n);
	while(m--)
	{
		int l,r,p,v;
		scanf("%d%d%d%d",&l,&r,&p,&v);
		printf("%d\n",query(l,r,p,v));
	}
	return 0;
}
