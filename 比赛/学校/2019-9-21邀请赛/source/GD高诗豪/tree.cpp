#include<bits/stdc++.h>
using namespace std;
struct data{
	int x,y,w;
};
const int M=500020;
data e[M];
const int N=100020;
int f[N],cnt[N];
bool cmp(data a,data b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(f[x]!=x) f[x] = find(f[x]);
	return f[x];
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	  	scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
	for(int i=1;i<=n;i++) f[i] = i,cnt[i] = 1;
	sort(e+1,e+m+1,cmp);
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int x = e[i].x,y=e[i].y;
		int fx = find(x),fy=find(y);
		if(fx==fy)continue;
		if(fx>fy)swap(fx,fy);
		if(fx==1)
			ans = ans + cnt[fy] * e[i].w;  			
		f[fy] = fx;
		cnt[fx] = cnt[fx] + cnt[fy];
	}
	printf("%d\n",ans);
}
/*
5 8
1 2 3
1 5 2
3 5 4
2 5 1
2 3 7
1 4 4
3 4 3
4 5 6

*/
