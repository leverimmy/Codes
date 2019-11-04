#include<bits/stdc++.h>
using namespace std;
long long n,f,p[100010],ans,s[100010];
int main()
{
	freopen("weapon.in","r",stdin);
	freopen("weapon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>f;
	for(int i=1;i<=n;i++)
		cin>>p[i],s[i]=s[i-1]+p[i];
	for(int a=1;a<=n;a++)
		for(int len=1;a+len*2+f-1<=n;len++)
		{
			++ans;
			if(s[a+len-1]-s[a-1]!=s[a+len*2+f-1]-s[a+len+f-1])
			{
				ans--;
				continue;
			}
			for(int i=0;i<len;i++)
				if(p[a+i]!=p[a+len+f+i])
				{
					ans--;
					break;
				}
		}
	cout<<ans;
	return 0;
}
