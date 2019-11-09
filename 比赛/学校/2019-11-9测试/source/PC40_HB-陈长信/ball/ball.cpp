#pragma optimize (2)
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
int n;
double x[maxn],y[maxn],ans[maxn];

double dis(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)
	{
		ans[i]=y[i];
		for(int j=i-1;j>=1;j--)
		{
			if(dis(x[i],ans[i],x[j],ans[j])<ans[i]+ans[j])
				ans[i]=min(ans[i],((x[i]-x[j])*(x[i]-x[j]))/(4*ans[j]));
		}
	}
	for(int i=1;i<=n;i++)
		printf("%.3f\n",ans[i]);
	return 0;
}
/*
5
0 2962
5923 2962
11844 2962
17763 2962
23680 2962
*/
