#include <bits/stdc++.h>
#define rgi register int
#define ll long long
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
const int maxn=2e6+11;
int n,b[maxn<<1],indx,match[maxn],book[maxn],tim=1;
vector<int> e[maxn];
struct poi
{
	int l,r;
}a[maxn];
bool dfs(int x)
{
	if(book[x]==tim)
		return false;
	book[x]=tim;
	for(register unsigned i=0;i<e[x].size();++i)
		if(!match[e[x][i]])
		{
			match[e[x][i]]=x;
			return true;
		}
	for(register unsigned i=0;i<e[x].size();++i)
		if(dfs(match[e[x][i]]))
		{
			match[e[x][i]]=x;
			return true;
		}
	return false;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("exam.in","r",stdin);
	freopen("exam.out","w",stdout);
	cin>>n;
	for(rgi i=1;i<=n;++i)
	{
		cin>>a[i].l>>a[i].r;
		b[++indx]=a[i].l,b[++indx]=a[i].r;
	}
	sort(b+1,b+indx+1);
	indx=unique(b+1,b+indx+1)-(b+1);
	for(rgi i=1;i<=n;++i)
	{
		a[i].l=lower_bound(b+1,b+indx+1,a[i].l)-b;
		a[i].r=lower_bound(b+1,b+indx+1,a[i].r)-b;
	}
	for(rgi i=1;i<=n;++i)
		e[a[i].l].pb(i),e[a[i].r].pb(i);
	int mt=0;
	for(rgi i=1;i<=indx;++i)
		if(dfs(i))
		{
			++tim,++mt;
			if(mt==n)
			{
				cout<<b[i]<<endl;
				return 0;
			}
		}
	puts("-1");
	return 0;
}

