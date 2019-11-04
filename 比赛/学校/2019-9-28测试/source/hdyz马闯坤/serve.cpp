#include<cstdio>
#include<queue>
#include<algorithm>
#define maxn 50005
#define inf 100000000
#define re register
using namespace std;

inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=(s<<3)+(s<<1)+ch-'0';
		ch=getchar();
	}
	return s*f;
}

int n,m;

int R[maxn];

struct E{
	int x,y,nxt,w;
}edge[maxn];

int head[maxn],tot;

void add(int x,int y,int w){
	edge[++tot].x=x;
	edge[tot].y=y;
	edge[tot].w=w;
	edge[tot].nxt=head[x];
	head[x]=tot;
}

struct node{
	int x,w;
	friend bool operator < (node a,node b){
		return a.w>b.w;
	}
};

int dis[maxn];

void dij(int s){
	priority_queue<node>q;
	for(re int i=1;i<=n;++i){
		dis[i]=inf;
	}
	q.push((node){s,0});
	dis[s]=0;
	while(!q.empty()){
		node u=q.top();
		q.pop();
		int x=u.x;
		if(dis[x]!=u.w)continue;
		for(re int i=head[x];i;i=edge[i].nxt){
			int y=edge[i].y;
			if(dis[y]>dis[x]+edge[i].w){
				dis[y]=dis[x]+edge[i].w;
				q.push((node){y,dis[y]});
			}
		}
	}
}

struct CO{
	int dis,R,id;
	friend bool operator < (CO a,CO b){
		if(a.dis==b.dis)return a.R<b.R;
		return a.dis<b.dis;
	}
}cop[maxn];

int maxx,anss,cnt,ans2;

int max(int x,int y){
	return x>y?x:y;
}

int ans[maxn];

int main()
{
	freopen("serve.in","r",stdin);
	freopen("serve.out","w",stdout); 
	n=read();
	m=read();
	for(re int i=1;i<=n;++i){
		R[i]=read();
	}
	for(re int i=1;i<=m;++i){
		int x=read();
		int y=read();
		int w=read();
		add(x,y,w);
		add(y,x,w);
	}
	for(re int i=1;i<=n;++i){
		maxx=0;
		cnt=0;
		dij(i);
		for(re int j=1;j<=n;++j){
			if(i==j)continue;
			cop[++cnt].dis=dis[j];
			cop[cnt].R=R[j];
			cop[cnt].id=j;
		}
		sort(cop+1,cop+n);
		for(re int j=1;j<n;++j){
			maxx=max(cop[j].R,maxx);
			//printf("i=%d maxx=%d\n",i,maxx);
			//if(j==1)ans[cop[j].id]++,ans2++;
			if(j>=2&&cop[j].R==maxx){
				ans2++;
			}
		}
		//printf("i=%d %d\n",i,ans2);
	}
	/*for(re int i=1;i<=n;++i){
		anss+=ans[i];
	}*/
	printf("%d\n",ans2);
	return 0;
}
/*
4 3
2
3
1
1
1 4 30
2 3 20
3 4 20
*/
// 9
