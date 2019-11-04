#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
struct node
{
	int l,r,q,c;
	int ans1,ans2,id;
}q[100001];
vector<int>v[100001];
vector<int>rem[100001];
int res[101][101];
int a[100001];
signed main()
{
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),v[a[i]].push_back(i);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&q[i].l,&q[i].r,&q[i].q,&q[i].c),q[i].id=i;
		if(q[i].q<=100)
		{
			rem[q[i].l-1].push_back(q[i].id);
			rem[q[i].r].push_back(q[i].id);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=100;j++)
			res[j][a[i]%j]++;
		for(int j=0;j<rem[i].size();j++)
		{
			int id=q[rem[i][j]].id;
			if(i==q[id].l-1)
				q[id].ans1=res[q[id].q][q[id].c];
			else
				q[id].ans2=res[q[id].q][q[id].c];
		}
	}
	for(int i=1;i<=m;i++)
		if(q[i].q>100)
		{
			for(int k=0;;k++)
			{
				int j=k*q[i].q+q[i].c;
				if(j>10000) break;
				q[i].ans2+=upper_bound(v[j].begin(),v[j].end(),q[i].r)-upper_bound(v[j].begin(),v[j].end(),q[i].l-1);
			}
		}
	for(int i=1;i<=m;i++)
		printf("%d\n",q[i].ans2-q[i].ans1);
	return 0;
}
/*
5 2
1 5 2 3 7
1 3 2 1
2 5 3 0
*/