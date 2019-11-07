#include <bits/stdc++.h>
using namespace std;
int f[1000];
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int N,M;
	int flag=0;
	scanf("%d%d",&N,&M);
	if(N%M!=0)
	{
		flag=1;
	}
	N=N/M;
	N+=flag;
	for(int i=1;i<=N;i++)
	{
		f[i]=2*f[i-1]+1;
	}
	printf("%d",f[N]);
	return 0;
}

