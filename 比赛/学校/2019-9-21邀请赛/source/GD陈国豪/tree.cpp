# include <bits/stdc++.h>
# define imax(a,b) ((a)>(b))?(a):(b)
# define imin(a,b) ((a)<(b))?(a):(b)
# define LL long long
# define is(a) (a>='0'&&a<='9')
using namespace std;
const int maxn=1e5+5,oo=1e9;
struct data
{
	int to,val;
};
struct note
{
	int s,p;
}t[maxn<<4];
vector<data> G[maxn];
int n,m,f[maxn],pa[maxn];
inline void read(int &x)
{
	x=0;
	int f=0;
	char ch=getchar();
	for (; !is(ch); ch=getchar()) f|=(ch=='-');
	for (; is(ch); ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
	x=(f)?-x:x;
}
inline up(int ro)
{
	t[ro].s=imin(t[ro<<1].s,t[ro<<1|1].s);
	t[ro].p=t[ro<<1|1].p;
	if (t[ro<<1].s<t[ro<<1|1].s)t[ro].p=t[ro<<1].p;
}
void build(int ro,int l,int r)
{
	if (l==r)
	{
		t[ro].s=f[l];
		t[ro].p=l;
		return;
	}
	int mid=(l+r)>>1;
	build(ro<<1,l,mid);
	build(ro<<1|1,mid+1,r);
	up(ro);
}
void update(int ro,int l,int r,int li,int ri,int val)
{
	if (l>ri||r<li) return;
	if (l>=li&&r<=ri)
	{
		t[ro].s=val;
		return;
	}
	int mid=(l+r)>>1;
	update(ro<<1,l,mid,li,ri,val);
	update(ro<<1|1,mid+1,r,li,ri,val);
	up(ro);
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	read(n);
	read(m);
	for (int i=1; i<=m; i++)
	{
		int x,y,val;
		read(x);
		read(y);
		read(val);
		data tmp;
		tmp.to=y;
		tmp.val=val;
		G[x].push_back(tmp);
		tmp.to=x;
		G[y].push_back(tmp);
	}
	for (int i=0; i<=n; i++) f[i]=1e7;
	f[1]=0;
	build(1,1,n);
	for (int i=1; i<=n; i++)
	{
		int b=0;
		 b=t[1].p;
	     update(1,1,n,b,b,oo);
		 for (int j=0; j<=G[b].size(); j++)
		 {
		 	int com=imax(G[b][j].val,f[b]);
		 	if (f[G[b][j].to]>com) update(1,1,n,G[b][j].to,G[b][j].to,com),f[G[b][j].to]=com;
		 }
	}
	LL ans=0;
	for (int i=2; i<=n;i++)
	ans+=f[i];
	printf("%lld",ans);
	return 0;
}
