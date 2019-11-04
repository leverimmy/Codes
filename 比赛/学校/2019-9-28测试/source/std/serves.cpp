#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<ctime>

using namespace std;

const int INF=0x3f3f3f3f;
const int N=30010,M=300100;
int n,m,nowRank;
int head[N],key[M],Next[M],len[M],cnt;
int Rank[N],dis[N],lim[N],minr[N];
int stack[N],tp;
int top,ans;

struct Heap
{
	int x,w;
	Heap(void){}
	Heap(int _x,int _w):x(_x),w(_w){}
}heap[10*M];

void add(int x,int y,int z)
{
	Next[++cnt]=head[x];
	key[cnt]=y;
	len[cnt]=z;
	head[x]=cnt;	
}

inline bool cmp(const Heap &a,const Heap &b)
{
	if(a.w!=b.w) return a.w>b.w;
	else return Rank[a.x]<Rank[b.x];
}

void dijk()
{
	while(top)
	{
		Heap sta=heap[1];
		pop_heap(heap+1,heap+top+1,cmp);
		top--;
		if(sta.w!=dis[sta.x]) continue;
		stack[++tp]=sta.x;
		for(int i=head[sta.x];~i;i=Next[i])
		{
			if(Rank[key[i]]>nowRank) continue;
			if(dis[key[i]]>sta.w+len[i]&&lim[key[i]]>sta.w+len[i])
			{
				dis[key[i]]=sta.w+len[i];
				heap[++top]=Heap(key[i],dis[key[i]]);
				push_heap(heap+1,heap+top+1,cmp);
			}
		}
	}
}

int main()
{
//	freopen("serves.in","r",stdin);
//	freopen("serves.out","w",stdout);
	memset(head,-1,sizeof head);
	memset(dis,0x3f,sizeof dis);
	memset(lim,0x3f,sizeof lim);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&Rank[i]);
	for(int i=1,x,y,z;i<=m;i++)
		scanf("%d%d%d",&x,&y,&z),add(x,y,z),add(y,x,z);
	for(int i=10;i>=1;i--)
	{
		nowRank=i;
		memset(minr,0x3f,sizeof minr);
		for(int j=1;j<=n;j++)
			if(Rank[j]==i)
			{
				heap[++top]=Heap(j,0);
				dis[j]=0;
				dijk();
				for(;tp;tp--)
				{
					int k=stack[tp];
					if(lim[k]>dis[k]) ans++;
					minr[k]=min(minr[k],dis[k]);
					dis[k]=INF;
				}
			}
		for(int j=1;j<=n;j++)
			lim[j]=min(minr[j],lim[j]);
	}
	cout<<ans<<endl;
	return 0;
}
