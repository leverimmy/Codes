#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int read()
{
	int x=0,y=1;char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')y=-1;
		c = getchar();
	}
	while(c>='0'&&c<='9')
		x = x*10+c-'0',c=getchar();
	return (x*y);
}

int n,w,u[100];
long double au;
long double ux[100];
vector<int> group[100];
long double mans=2147483647.0f;

void dfs(int nw)
{
	if(nw>=n)
	{
		long double ges=0;
		long double bs=0;
		for(int i=0;i<w;i++)
		{
			if(group[i].size()==0)
				return;
			bs+=group[i].size();
			for(int j=0;j<group[i].size();j++)
			{
				ges+=bs*ux[group[i][j]];
			}
		}
		mans = min(mans,ges);
		return;
	}
	for(int i=0;i<w;i++)
	{
		group[i].push_back(nw);
		dfs(nw+1);
		group[i].pop_back();
	}
}

void pfs(int nw,int ng)
{
	if(nw>=n)
	{
		long double ges=0;
		long double bs=0;
		for(int i=0;i<w;i++)
		{
			if(group[i].size()==0)
				return;
			bs+=group[i].size();
			for(int j=0;j<group[i].size();j++)
			{
				ges+=bs*ux[group[i][j]];
			}
		}
		mans = min(mans,ges);
		return;
	}
	
	if(ng<w-1)
	{
		//nng
		group[ng+1].push_back(nw);
		pfs(nw+1,ng+1);
		group[ng+1].pop_back();
	}
	
	//not nng -> nnng
	group[ng].push_back(nw);
	pfs(nw+1,ng);
	group[ng].pop_back();
}

int main()
{
	freopen("pb.in","r",stdin);
	freopen("pb.out","w",stdout);
	
	au = 0;
	n = read(),w=read();
	for(int i=0;i<n;i++)
	{
		u[i] = read();
		au+=u[i];
	}
	for(int i=0;i<n;i++)
	{
		ux[i] = u[i]/au;
	}
//	if(n>10)
//	{
		sort(ux,ux+n,greater<double>());
		pfs(0,0);
//	}
//	else
//		dfs(0);
	printf("%.4lf",(double)mans);
	return 0;
}
/*
5 2
30 5 10 30 25
*/
