#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<ctime>
using namespace std;
typedef long long ll;
typedef unsigned int ull;

const int N=1000010;

const ull mul=133331; 

ll ans;
int n,m,k;
int b[N],a[N];
int X[N];
ull Hash[N];
ull f[N]={1};

inline int bin(int x)
{
	int l=1,r=k;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(b[mid]<=x) l=mid+1;
		else r=mid-1;
	}
	return r;
}

inline ull getHash(const int &l,const int &r)
{
    return Hash[r]-Hash[l-1]*f[r-l+1];
}

inline int lcp(int x,int y)
{
    int l=0,r=min(n-x+1,n-y+1);
    while(l<=r)
    {
        int mid=l+r>>1;
        if(getHash(x,x+mid-1)==getHash(y,y+mid-1)) l=mid+1;
        else r=mid-1;
    }
    return r;
}

inline int anti_lcp(int x,int y)
{
    int l=0,r=min(x,y);
    while(l<=r)
    {
        int mid=l+r>>1;
        if(getHash(x-mid+1,x)==getHash(y-mid+1,y)) l=mid+1;
        else r=mid-1;
    }
    return r;
}
int main()
{
	freopen("weapon.in","r",stdin);
	freopen("weapon.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		X[i]=a[i];
	}
	sort(X+1,X+n+1);
	X[0]=~0U>>1;
	for(int i=1;i<=n;i++)
		if(X[i]!=X[i-1])
			b[++k]=X[i];
	for(int i=1;i<=n;i++)
		a[i]=bin(a[i]);
	for(int i=1;i<=n;i++) f[i]=f[i-1]*mul;
	for(int i=1;i<=n;i++) Hash[i]=Hash[i-1]*mul+a[i];
	for(int i=1;2*i+m<=n;i++)
	{
		int nowl=0;
		for(int j=1;;)
		{
			int len=min(i,n-(j+i+m-1));
			if(!len) break;
			int frontl=lcp(j,j+i+m);
			int backl=anti_lcp(j+len-1,j+m+i+len-1);
			frontl=min(frontl,len);
			backl=min(backl,len);
			if(frontl==len)
			{
				if(nowl>=i) ans+=len;
				else ans+=max(0,nowl+frontl-i+1);
				nowl+=len;
			}
			else
			{
				if(nowl>=i) ans+=frontl;
				else ans+=max(0,nowl+frontl-i+1);
				nowl=backl;
			}
			j+=len;
		}
	}
	cout<<ans<<endl;
	return 0;
}
