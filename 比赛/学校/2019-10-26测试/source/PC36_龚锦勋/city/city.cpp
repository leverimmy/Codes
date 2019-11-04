#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <stack>

using namespace std;

#define N 300
#define NM 44860
#define MNS 100000000

int n,sn;
int ss[NM];
//set<int> ss;
int lis[N];
int mxsum;
//n>=3
int c;
set<int*> qs;
//set<char*> qs;

inline void dfs(int lvl,int mxsum,int cso)
{
	if(lvl==n)
	{
		int *qx = new int[N];
		
		for(int i=0;i<n;i++)
		{
			qx[i] = lis[i];
		}
		
		sort(qx,qx+n);
		
//		char *qxs = new char[4*N];
//		for(int i=0;i<n;i++)
//		{
//			sprintf(qxs+i*2,"%d ",qx[i]);
//		}
		
		for(set<int*>::iterator it=qs.begin();it!=qs.end();it++)
//		for(set<char*>::iterator it=qs.begin();it!=qs.end();it++)
		{
			int fd=0;
//			for(int i=0;i<n*2;i++)
//			{
//				if((*it)[i]!=qxs[i])
//				{
//					fd=1;
//					
//				}
//			}
			for(int i=0;i<n;i++)
			{
				if((*it)[i]!=qx[i])
				{
					fd=1;
					
				}
			}
			if(!fd)
				return;
		}
		qs.insert(qx);
		//qs.insert(qxs);
		c++;
		return ;
	}
	for(int i=1;i<mxsum;i++)
	{
		bool lf=0;
		for(int j=0;j<lvl;j++)
		{
			if(ss[cso+j]!=lis[j]+i)
			{
				lf=1;
				break;
			}
		}
		if(lf)
			continue;
		lis[lvl]=i;
		dfs(lvl+1,mxsum,cso+lvl);
		lis[lvl]=0;
	} 
}
 
//数从小到大 解从大到小 
int main()
{
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	
	scanf("%d",&n);
	sn = n*(n-1)/2;
	for(int i=0;i<sn;i++)
	{
		scanf("%d",&ss[i]);
		mxsum = max(mxsum,ss[i]);
	}
	sort(ss,ss+n);
	do
	{
		dfs(0,mxsum,0);
	}
	while(next_permutation(ss,ss+n));
	
	cout << c << endl;
	
	stack<int*> st;
	
	for(set<int*>::iterator it = qs.begin();it!=qs.end();it++)
//	for(set<char*>::iterator it = qs.begin();it!=qs.end();it++)
	{
	//	sort(*it,(*it)+n);
		//printf("%s",(*it));
		//printf("\n");
		st.push(*it);
	}
	while(!st.empty())
	{
		for(int i=0;i<n;i++)
		{
			printf("%d ",st.top()[i]);
		}
		printf("\n");
		st.pop();
	}
	return 0;
}
