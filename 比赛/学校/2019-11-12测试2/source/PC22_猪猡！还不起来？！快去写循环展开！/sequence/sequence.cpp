#include <bits/stdc++.h>
#define rgi register int
#define ll long long
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
const int maxn=100005;
const int maxm=5005;
int n,m,a[maxn],indx;
ll s[maxm],b[maxm*maxm];
inline void do1()
{//最大子段和 
	cout<<"wsdd"<<endl;
}
inline void do2()
{
	for(rgi i=1;i<=n;++i)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	for(rgi i=1;i<=n;++i)
		for(rgi j=i;j<=n;++j)
			b[++indx]=s[j]-s[i-1];
	sort(b+1,b+indx+1,greater<ll>());
	cout<<b[m]<<endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	//freopen("sequence.in","r",stdin);
	//freopen("sequence.out","w",stdout);
	cin>>n>>m;
	if(m==1)
		do1();
	else if(n<=5004)
		do2();
	else
		cout<<"Free Hong Kong"<<endl;
	return 0;
}

