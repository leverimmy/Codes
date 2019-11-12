#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,T;
int row[801][801],col[801][801];
int a[801][801],b[801][801];
int get(int x,int y)
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=row[x][i]*col[i][y];
	}
	return ans;
}
signed main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%lld%lld",&n,&T);
    for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
			row[i][j]=row[i-1][j]+a[i][j];
		}
    for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&b[i][j]);
			col[i][j]=col[i][j-1]+b[i][j];
		}
	while(T--)
	{
		int a,b,c,d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(a>c)swap(a,c);
		if(b>d)swap(b,d);
		printf("%lld\n",get(c,d)-get(c,b-1)-get(a-1,d)+get(a-1,b-1));
	}
	return 0;
}
/*
3 2

1 9 8
3 2 0
1 8 3

9 8 4
0 5 15
1 9 6

1 1 3 3
2 3 1 2
*/