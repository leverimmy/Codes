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
#define INF 1000000009 
using namespace std;
const int maxn=200005,maxm=205;
int n,w,h[maxn],sum[maxn];
double p[maxn];
int f[maxm][maxm];

int get_sum(int i,int j)
{
	int sum;
	for(int k=i;k<=j;k++)
		sum+=h[i];
	return sum;
}

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("pb.in","r",stdin);
	freopen("pb.out","w",stdout);
	memset(f,INF,sizeof(f));
	scanf("%d %d\n",&n,&w);
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	sort(h+1,h+n+1,cmp);
	sum[0]=0;
	for(int i=1;i<=n;i++)
		sum[i]+=sum[i-1]+h[i];
	f[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=w;j++)
			for(int k=0;k<i;k++)
			{
				f[i][j]=min(f[i][j],f[k][j-1]+i*(sum[i]-sum[k]));
			}
	printf("%.4f\n",f[n][w]/(double)sum[n]);
	return 0;
}
/*
5 2
30 5 10 30 25
*/ 
