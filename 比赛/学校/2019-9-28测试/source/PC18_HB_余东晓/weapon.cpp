#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<climits>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
void get_next(int *s1,int *next,int len1)
{
	int i=0,j=-1;
	next[i]=j;
	while(i<=len1-1)
	{
		if(j==-1||s1[i]==s1[j])
		{
			i++;
			j++;
			next[i]=j;
		}
		else 
			j=next[j];
	}
}
void index_KMP(int *s1,int *s2,int *next,int len1,int len2)
{
	int i=0,j=0,ans(0);
	while(i<=len1-1)
	{
		if(j==-1||s1[i]==s2[j])
		{
			i++;
			j++;
		}
		else 
			j=next[j];
		if(j==len2)
		{
			printf("%d\n",i-len2+1);
			j=next[j];
		}
	}
}
int v[100010],next[100010];
signed main()
{
	freopen("weapon.in","r",stdin);
	freopen("weapon.out","w",stdout);
	int n,m;
	ll ans(0);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(int a=1;a<=n;a++)
	{
		get_next(v,next,4);
	}
}
