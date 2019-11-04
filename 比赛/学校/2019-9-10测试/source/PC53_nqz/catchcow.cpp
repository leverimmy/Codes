#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN=1000005;
int N,K;
int vis[MAXN],dis[MAXN],ans=INF;
int l,r,_array[MAXN<<2];

int main()
{
	freopen("catchcow.in","r",stdin);
	freopen("catchcow.out","w",stdout);
	memset(dis,INF,sizeof(dis));
	scanf("%d%d",&N,&K);
	l=0,r=1;
	_array[r]=N;
	dis[N]=0;
	while(l<r)
	{
		l++;
		int NowNode=_array[l];
		if(NowNode==K)
		{
			break;
		}
		if(!vis[NowNode+1]&&NowNode+1<=K+1)
		{
			r++;
			_array[r]=NowNode+1;
			dis[NowNode+1]=dis[NowNode]+1;
			vis[NowNode+1]=1;
		}
		if(!vis[NowNode-1]&&NowNode-1>=0)
		{
			r++;
			_array[r]=NowNode-1;
			dis[NowNode-1]=dis[NowNode]+1;
			vis[NowNode-1]=1;
		}
		if(!vis[NowNode*2]&&NowNode<=2*K)
		{
			r++;
			_array[r]=NowNode*2;
			dis[NowNode*2]=dis[NowNode]+1;
			vis[NowNode*2]=1;
		}
	}
	printf("%d",dis[K]);
	return 0;
}
