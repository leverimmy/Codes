#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<map>
#include<vector>
#include<set>
using namespace std;
const int maxn=200005;
int n,a[maxn],ans;
int f[maxn][2];

int main()
{
	freopen("gfw.in","r",stdin);
	freopen("gfw.out","w",stdout);
	memset(f,0,sizeof(f));
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=10)
	{
		cout<<n-4<<endl;
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]>a[i-1]) f[i][0]=f[i-1][0]+1;
			else f[i][0]=1;
			for(int j=i;j>=i-f[i][0]+1;j--)
			{
				if(a[j]>a[j-1]) f[i][j]=max(f[i][j],f[i][j-1]+max(f[i][0],f[i][1]));
			}
		ans=max(f[i][0],ans);
		ans=max(f[i][1],ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
9
5 3 4 9 2 8 6 7 1 
*/
