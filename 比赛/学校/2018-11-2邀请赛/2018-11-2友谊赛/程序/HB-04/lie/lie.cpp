#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<cstdlib>
#include<algorithm>
#include<complex>
#include<iostream>
#include<map>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
struct node
{
	int lw,hg;
}a[200020];
int n,len;
int x,y;
int c1[200020];
int c2[200020];
int c3[200020];
int dp[200020];
int loc[200020];
int now1(1),now2(1);
int solve()
{  
    for(int i=0;i<n;++i)dp[i]=INF;
    for(int i=0;i<n;++i) 
	{  
        *lower_bound(dp,dp+n,c3[i])=c3[i];  
    }  
	return lower_bound(dp,dp+n,INF)-dp;  
}
int main()
{
	freopen("lie.in","r",stdin);
	freopen("lie.out","w",stdout);
	scanf("%d",&n);
	len=n*2;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		int p1=len-x;
		int p2=y+1;
		while(a[p1].lw)p1--;
		a[p1].lw=i;
		while(a[p2].hg)p2++;
		a[p2].hg=i;
	}
	for(int i=1;i<=len;i++)if(a[i].lw)c1[now1++]=a[i].lw;
	for(int i=1;i<=len;i++)if(a[i].hg)c2[now2++]=a[i].hg;
	for(int i=1;i<=n;i++)loc[c2[i]]=i;
	for(int i=1;i<=n;i++)c3[i-1]=loc[c1[i]];
	printf("%d",n-solve());
	system("pause");
	return 0;
}


/*
in:
3
2 0
0 2
2 2

storge:
lw:0 0 3 1 0 2
hg:1 0 2 3 0 0
c1:3 1 2
c2:1 2 3

out:
1
*/


/*
in:
3
0 2
1 1
2 0

storge:
lw:0 0 0 3 2 1
hg:3 2 1 0 0 0
c1:3 2 1
c2:3 2 1

out:
0
*/
