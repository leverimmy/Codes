#include <iostream>
#include <cmath>
#include <cstring>
#define rgi register int
using namespace std;
const int maxn=1e5+5;
const int inf=1e9+9;
int n,m,a[maxn],f[maxn][20];
int main()
{
	ios::sync_with_stdio(false);
	memset(f,-1,sizeof(f));
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	cin>>n;
	for(rgi i=1;i<=n;++i)
		cin>>a[i],f[i][0]=i+a[i];
	cin>>m;
	if(n*m<=10000000)
	{
		for(;m;--m)
		{
			rgi i,k,ans=0;
			cin>>i>>k;
			for(;i<=n;i+=a[i]+k)
				++ans;
			cout<<ans<<endl;
		}
	}
	else
	{
		int l=log(n)/log(2)+1;
		for(rgi i=1;i<=l;++i)
		{
			for(rgi j=1;f[j][i-1]<=n;++j)
				f[j][i]=f[f[j][i-1]][i-1];
		}
		for(;m;--m)
		{
			rgi i,k,ans=0;
			cin>>i>>k;
			if(k)
			{
				cout<<"AFO and go to Class 9"<<endl;
				return 0;
			}
			for(rgi j=l;j>=0;--j)
			{
				if(f[i][j]>=n)
					continue;
				++ans;
				i=f[i][j];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
