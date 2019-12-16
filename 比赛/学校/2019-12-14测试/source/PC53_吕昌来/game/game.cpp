#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[1005];
void dfs (int rleft,int num)
{
	if (num>n)
	    return;
	if (rleft==1)
	{
		if (num%2==0)
		    ans=1;
		return;
	}
	for (int i=1;i<=a[num];i++)
	{
		cout<<rleft<<endl;
		if (rleft-a[num]<1)
		    break;
		rleft-=i;
		int j=i;
		dfs(rleft,++num);
		i=j;
		if (ans)
		    return;
		num--;
		rleft+=i;
	}
	return;
}
int main ()
{
	freopen ("game.in","r",stdin);
	freopen ("game.out","w",stdout);
	cin>>n;
	while (n)
	{
		cin>>m;
		n*=2;
		for (int i=1;i<=n;i++)
		    cin>>a[i];
		dfs (m,1);
		cout<<ans<<endl;
		cin>>n;
	}
	return 0;
}
