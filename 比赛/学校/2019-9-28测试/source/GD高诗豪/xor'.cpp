#include<bits/stdc++.h>
using namespace std;
const int N = 100020;
const int M = 200020;
int nex[M],to[M],head[M],weight[M];
int T;
int d[N],vis[N];
int n,m,cnt = 0;;
void ae(int x,int y,int w)
{
	nex[++cnt] = head[x];
	to[cnt] = y;
	head[x] = cnt;
	weight[cnt]= w;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		cnt = 0;
		memset(head,0,sizeof(head));
		memset(to,0,sizeof(to));
		memset(weight,0,sizeof(weight));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
		  	int x,y,w;
		  	scanf("%d%d%d",&x,&y,&w);
		  	ae(x-1,y,w);
		}
		memset(d,0,sizeof(d));	
		d[0] = 1;
		bool flag = 1;
		for(int i=0;i<=n && flag;i++)if(d[i])
		{
			for(int j=head[i];j;j=nex[j])
			{
				int v = to[j];
				if(!d[v])vis[v] = vis[i] ^ weight[j],d[v] = 1;
				else 
				{
					if(vis[v]!=(vis[i]^weight[j])) 
					{
						printf("No\n");						
						flag = 0;
						break;
					}
				}
			}
		}
		if(flag) printf("Yes\n");
	}
}
