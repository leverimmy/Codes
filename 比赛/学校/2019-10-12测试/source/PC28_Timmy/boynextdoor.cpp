#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	freopen("boynextdoor.in","r",stdin);
	freopen("boynextdoor.out","w",stdout);
	int t;
	cin >> t;
	int a[t+5],b[t+5],ans[t+5];
	for(int i=1;i<=t;i++)
	{
		cin >> a[i] >> b[i];
		if(a[i]!=b[i]&&a[i]!=0&&b[i]!=0)
		{
			ans[i]=a[i]-2-b[i];
		}
		if(a[i]==0)
		{
			ans[i]=-b[i];
		}
		if(b[i]==0)
		{
			ans[i]=a[i];
		}
	} 
	for(int i=1;i<=t;i++)
	{
		cout << ans[i];
	}
	return 0;
}
