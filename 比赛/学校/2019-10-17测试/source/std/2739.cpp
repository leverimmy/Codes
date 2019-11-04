#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define LL long long
#define ls rt<<1
#define rs rt<<1|1
using namespace std;

const int maxn = 2e5+100;

LL a[maxn],ge,re,t,mod,mp[maxn],mp1[maxn],h[maxn],lst,bs[maxn],ans;
int n,q,ps[maxn];
struct node
{
	LL val;
	int rk,id;
};
node b[maxn];

bool cmp(node a,node b)
{
	return a.val < b.val;
}
bool cmp1(node a,node b)
{
	return a.id < b.id;
}
int T[maxn*4];
void update(int rt,int l,int r,int x,int val)
{
	if(l==r)
	{
		T[rt] = val;
		return ;
	}
	int mid = (l+r)>>1;
	if(x<=mid) update(ls,l,mid,x,val);
	else update(rs,mid+1,r,x,val);
	T[rt] = min(T[ls],T[rs]);
}

int query(int rt,int l,int r,int L,int R)
{
	if(L<=l&&r<=R)
	{
		return T[rt];
	}
	int mid =(l+r)>>1,res=1e9+100;
	if(L<=mid) res = min(res,query(ls,l,mid,L,R));
	if(R>mid) res = min(res,query(rs,mid+1,r,L,R));
	return res;
}
int get_pos(LL L,LL R)
{
	LL posl = lower_bound(h+1,h+1+n,L) - h;
	LL posr = lower_bound(h+1,h+1+n,R) - h;
	LL posr1 = upper_bound(h+1,h+1+n,R) - h;
	if(posr==posr1) posr--;
	else posr = posr1-1;
	if(posr>n) posr = n;
	if(posl<1) posl = 1;
	//cout<<posl<<" PPP "<<posr<<endl;
	if(posl>posr) return 1e9+100;
	else return query(1,1,n,posl,posr);
}
int main()
{
	freopen("2739.in","r",stdin);
		freopen("2739.out","w",stdout);
	memset(T,0x3f,sizeof(T));
	scanf("%d%lld%lld",&n,&ge,&re);
	mod =ge+re;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		mp[i] = a[i];
		mp[i] += mp[i-1];
		b[i].val=mp[i]%mod;
		//out<<b[i].val<<" ";
		b[i].id = i;
		h[i]=b[i].val;
	}
	//cout<<endl;
	scanf("%lld",&lst);
	sort(h+1,h+1+n);
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;i++) b[i].rk=i;
	sort(b+1,b+1+n,cmp1);
	for(int i=n;i>=1;i--)
	{
		LL xi = mp[i];
		xi%=mod;
		int res=1e9+100;
		LL L = (ge+xi)%mod,R=(ge+re+xi-1)%mod; 
		if(R<L)
		{
			int res1 = get_pos(L,mod);
			int res2 = get_pos(0,R);
			res = min(res1,res2); 
		}
		else res = get_pos(L,R); 
		//cout<<"pos:: "<<res<<endl;
		if(res<1e9)
		{
			LL cur = mp[res]-mp[i];
			bs[i] = bs[res] + cur +(mod-cur%mod); 
		}
		else bs[i] = mp[n]-mp[i];
		//cout<<b[i].rk<<endl;
		update(1,1,n,b[i].rk,i);
	}
	//cout<<mp[n]<<endl;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%lld",&t);
		LL pt = t%mod;
		LL L = (ge-pt+mod)%mod,R=(ge+re-pt-1)%mod; 
		int res = 1e9+100; 
		if(R<L)
		{
			int res1 = get_pos(L,mod);
			int res2 = get_pos(0,R);
			res = min(res1,res2); 
		}
		else res = get_pos(L,R); 
		if(res>1e9)
		{
			ans = t+lst+mp[n];
		}
		else 
		{
			LL cur = t + mp[res];
			ans = cur + lst + bs[res] + (mod-cur%mod)%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
