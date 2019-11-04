#include <bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int col[MAXN],lin[MAXN];
int ans;
int main()
{
	freopen("rush.in","r",stdin);
	freopen("rush.out","w",stdout);
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		col[a]=col[2*N-a+1]=1;
		lin[b]=lin[2*N-b+1]=1;
	}
	for(int i=1;i<=N;i++)
	{
		ans+=!col[i];
		ans+=!lin[i];
	}
	if(N%2==1)
	{
		if((!col[N/2+1])&&(!lin[N/2+1]))
		{
			ans--;
		}
	}
	printf("%d",ans);
	return 0;
}
