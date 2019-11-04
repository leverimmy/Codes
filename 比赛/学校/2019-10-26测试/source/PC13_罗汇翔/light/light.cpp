#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mn=100010;
const int inf=2147483647/2-1;
int n,m;
int a[mn];
int l[mn],r[mn],p[mn],v[mn];
int sum[mn];
bool b;
struct nu
{
	int a;
	int n;
};
nu x[mn];
nu k;
int ll,rr,mid,ans1,ans2;
int ans;
int anss[mn]; 
bool operator < (const nu &a,const nu &b)
{
	if(a.a!=b.a)return a.a<b.a;
	else return a.n<b.n;
}
int main()
{
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	b=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>l[i]>>r[i]>>p[i]>>v[i];
		if(p[i]!=p[i-1] && i!=1)b=0;
	}
	if(b)
	{
		for(int i=1;i<=m;i++)
		{
			if(l[i]==r[i])
			{
				if(a[l[i]]%p[1]==v[i])anss[i]=-1;
				else anss[i]=-2;
			}
		}
		for(int i=1;i<=n;i++)
		{
			x[i].a=a[i]%p[1];
			x[i].n=i;
		}
		sort(x+1,x+n+1);
		for(int i=1;i<=m;i++)
		{
			if(anss[i]==-1)
			{
			    cout<<1<<endl;
			    continue;
			}
			if(anss[i]==-2)
			{
				cout<<0<<endl;
				continue;
			}
			b=1;
			k.a=v[i];
			k.n=l[i];
			ll=1;rr=n;
			ans1=inf;
			while(ll<=rr)
			{
				mid=(ll+rr)/2;	
				if(k<x[mid])
				{
				    rr=mid-1;
				    ans1=mid;
				}
				else ll=mid+1;
			}
			k.a=v[i];
			k.n=r[i];
			ll=1;rr=n;
			ans2=-inf;
			while(ll<=rr)
			{
				mid=(ll+rr)/2;
				if(k<x[mid])rr=mid-1;
				else 
				{
				    ll=mid+1;
				    ans2=mid;
				}
			}
			ans=ans2-ans1+1;
			if(ans<0 || ans>r[i]-l[i]+1)cout<<0;
			else cout<<ans;
			cout<<endl;
		}
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		ans=0;
		for(int j=l[i];j<=r[i];j++)
		{
			if(a[j]%p[i]==v[i])ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
