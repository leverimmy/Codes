#include <bits/stdc++.h>
using namespace std;
int n,s,a[25];
bool ans;
bool vis[9000][2][25];
bool book[9000][2];
struct node
{
	int sum,type,now;//1ох0╨С 
};
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	while(scanf("%d%d",&n,&s)&&n)
	{
		ans=false;
		memset(vis,0,sizeof(vis));
		memset(book,0,sizeof(book));
		queue<node> Q;
		for(int i=0;i<n<<1;i++) scanf("%d",&a[i]),Q.push()
		while(!Q.empty())
		{
			node cur=Q.front();Q.pop();
			//printf("%d %d %d\n",cur.sum,cur.type,cur.now);
			if(cur.sum>s) continue;
			book[cur.sum][cur.type]=1;
			if(!cur.type){
				for(int i=1;i<=a[cur.now];i++)
				{
					if(!vis[cur.sum+i][1][(cur.now+2*n-1)%(n<<1)]){
						Q.push((node){cur.sum+i,1,(cur.now+2*n-1)%(n<<1)});
						vis[cur.sum+i][1][(cur.now+2*n-1)%(n<<1)]=1;
					}
				}
			} else {
				for(int i=1;i<=a[cur.now];i++)
				{
					if(!vis[cur.sum+i][0][(cur.now+2*n-1)%(n<<1)]){
						Q.push((node){cur.sum+i,0,(cur.now+2*n-1)%(n<<1)});
						vis[cur.sum+i][0][(cur.now+2*n-1)%(n<<1)]=1;
					}
				}
			}
		}
		if(!book[])
	}
	return 0;
}
