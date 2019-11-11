#include <bits/stdc++.h>
#define rgi register int
using namespace std;
const int maxn=5005;
int n,m,ans;
string a[maxn];
inline bool check(int u,int d,int l,int r)
{
	for(rgi i=u;i<=d;++i)
		for(rgi j=l;j<=r;++j)
			if(a[i][j]!='1')
				return 0;
	return 1;
}
signed main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(rgi i=0;i<n;++i)
		cin>>a[i];
	do
	{
		for(rgi u=0;u<n;++u)
			for(rgi l=0;l<m;++l)
				for(rgi d=u;d<n;++d)
					for(rgi r=l;r<m;++r)
						if(check(u,d,l,r))
							ans=max(ans,(d-u+1)*(r-l+1));
	}while(next_permutation(a,a+n));
	cout<<ans<<endl;
	return 0;
}

