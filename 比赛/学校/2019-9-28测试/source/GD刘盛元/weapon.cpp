#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<cstdlib>
#include<map>
#include<cmath>
#include<vector>
using namespace std;
const int N=100005;
int n,f;
long long a[N];
long long sum[N],ans;
int main()
{
	freopen("weapon.in","r",stdin);
	freopen("weapon.out","w",stdout);
	cin>>n>>f;
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		sum[i]+=sum[i-1]+a[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int len=1;i+len*2+f-1<=n;len++)
		{
			if (sum[i+len-1]-sum[i-1]==sum[i+len*2+f-1]-sum[i+len+f-1])
			{
				bool flag=true;
				for (int k=0;k<len;k++) if (a[i+k]!=a[i+len+f+k]) {flag=false;break;
				}
				if (flag==true) ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

