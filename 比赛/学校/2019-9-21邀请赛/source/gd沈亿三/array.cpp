#include<bits/stdc++.h>
using namespace std;
const int nx=1e5+5;
int num[nx];
int n,m;
int main()
{
	freopen("array.in","r",stdin);
	freopen("array.in","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&num[i]);
	scanf("%d",&m);
	int p,k;
	long long cnt;
	for(int i=1;i<=m;++i)
	{
		cnt=0;
		scanf("%d%d",&p,&k);
		while(n>=p)
		{
			p=p+num[p]+k;
			cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
