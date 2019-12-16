#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int n,m,p;

map<int,int> e[100001];

int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	int u,v,w;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		if((!e[u].count(v)) || e[u][v]>w)
		{
			e[u][v] = w;
			e[v][u] = w;
			for(map<int,int>::iterator it = e[u].begin();it!=e[u].end();it++)
			{
				int ka=it->first,va=it->second;
				if(ka==v)
				{
					continue;
				}
				if(e[ka].count(v))//找到和v的联系 
				{
					if(max(va,w) < e[ka][v])
					{
						e[ka][v] = max(va,w);
					}
				}
				else
				{
					e[ka][v] = max(va,w);
				}
			}
			for(map<int,int>::iterator it = e[v].begin();it!=e[v].end();it++)
			{
				int ka=it->first,va=it->second;
				if(ka==u)
				{
					continue;
				}
				if(e[ka].count(u))//找到和v的联系 
				{
					if(max(va,w) < e[ka][u])
					{
						e[ka][u] = max(va,w);
					}
				}
				else
				{
					e[ka][u] = max(va,w);
				}
			}
		}
	}
	scanf("%d",&p);
	
	int a,b;
	for(int i=0;i<p;i++)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",e[a][b]);
	}
	
	return 0;
}
