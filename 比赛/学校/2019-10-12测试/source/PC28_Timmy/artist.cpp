#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	freopen("artist.in","r",stdin);
	freopen("artist.out","w",stdout);
	int n;
	cin >> n;
	double a[n+5],b[n+5],t,mnya=0,mnyb=0,mny,min=999999999;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> b[i];
	}
	cin >> t;
	for(int change1=1;change1<=n-1;change1++)
	{
		for(int rate=0;rate<=t;rate+=0.001)
		{
			mnya+=a[change1]*rate;
			mnyb+=b[change1]*(t-rate);
		}
		for(int change2=change1+1;change2<=n;change2++)
		{
			for(int rate=0;rate<=t;rate+=0.001)
			{
				mnya+=a[change2]*rate;
				mnyb+=b[change2]*(t-rate);
				if(mnya<mnyb)
				{
					mny=mnyb;
				}
				else
				{
					mny=mnya;
				}
				if(mny<min)
				{
					min=mny;
				}
			}
		}
	}
	cout << min;
	return 0;
}
