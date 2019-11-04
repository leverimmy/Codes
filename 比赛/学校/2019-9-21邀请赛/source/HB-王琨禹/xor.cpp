#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN=1000005;
int father[MAXN];
int N,M;
int Find(int x)
{
	return father[x]==x?x:father[x]=Find(father[x]);
}
void _Init()
{
	for(int i=1;i<=N+5;i++)
	{
		father[i]=i;
		father[i+N]=i+N;
	}
}
void Union(int x,int y)
{
	int r1=Find(x);
	int r2=Find(y);
	if(r1!=r2)
	{
		father[r1]=r2;
	}
}
int x[MAXN],y[MAXN],k[MAXN];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int T;
	scanf("%d", &T);
	while(T--)
	{
		_Init(); 
		bool flag;
		scanf("%d%d", &N,&M); 
		flag = true;
		for(int i=1;i<=M;i++)
		{
			scanf("%d%d%d",x+i,y+i,k+i);
		}
		for(int i=0;i<=30;i++)
		{
			_Init();
			for(int j=0;j<M;j++)
			{
				int now = (k[j]>>i) & 1;
				if(now)
				{
					if(Find(x[j])==Find(y[j]))
					{
					 	flag = false;
					}
					Union(x[j], y[j]+N); 
					Union(x[j]+N, y[j]);
				}
				else
				{
					if(Find(x[j]+N)==Find(y[j]))
					{
						flag = false;
					}
					Union(x[j],y[j]);
					Union(x[j]+N,y[j]+N);
				}
			}
			if(!flag)
			{
				break;
			}
		}
		if(flag)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
