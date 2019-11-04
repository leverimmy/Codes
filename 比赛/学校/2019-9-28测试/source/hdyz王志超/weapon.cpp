#include<bits/stdc++.h>

#define int long long

using namespace std;

int n,f,p[100500],ans;

signed main()
{
	freopen("weapon.in","r",stdin);
	
	freopen("weapon.out","w",stdout);
	
	cin>>n>>f;
	
	for(int i=1;i<=n;i++) cin>>p[i];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n&&i+j*2+f-1<=n;j++)
		{
			int flag=0;
			
			for(int k=i;k<=i+j-1;k++)
			{
				if(p[k]!=p[k+j+f])
				{
					flag=1;
					
					break;
				} 
			}
			
			if(flag==1) continue;
			
			//cout<<i<<" "<<j<<'\n';
			
			ans++;
		}
	}
	
	cout<<ans;
	
	return 0;
	
}

