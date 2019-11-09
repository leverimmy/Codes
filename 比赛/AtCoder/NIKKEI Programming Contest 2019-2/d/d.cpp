#include <stdio.h>
#include <string.h>
#include <queue>
#define int long long
#define rep(i,st,ed) for (int i=st;i<=ed;++i)
#define fill(x,t) memset(x,t,sizeof(x))
#define fi first
#define se second

const int INF=0x3f3f3f3f3f3f3f3fLL;
const int N=500005;
const int E=3000005;

struct edge {int y,w,next;} e[E*10];
struct data {
    int x,v;
    bool operator <(const data &b) const {
        return v>b.v;
    }
} ;
struct treeNode {int l,r;} t[N*10];

std:: priority_queue <data> heap;

bool vis[E];

int dis[E],pos[N],tot,rec;
int ls[E],edCnt;

int read() {
    int x=0,v=1; char ch=getchar();
    for (;ch<'0'||ch>'9';v=(ch=='-')?(-1):(v),ch=getchar());
    for (;ch<='9'&&ch>='0';x=x*10+ch-'0',ch=getchar());
    return x*v;
}

void add_edge(int x,int y,int w) {
    e[++edCnt]=(edge) {y,w,ls[x]}; ls[x]=edCnt;
}

void dijkstra(int st) {
    fill(dis,63); dis[st]=0;
    heap.push((data){st,dis[st]});
    rep(i,1,tot) {
        if (heap.empty()) return ;
        data now=heap.top(); heap.pop();
        while (!heap.empty()&&vis[now.x]) now=heap.top(),heap.pop();
        if (vis[now.x]) return ;
        vis[now.x]=1;
        for (int i=ls[now.x];i;i=e[i].next) {
            if (!vis[e[i].y]&&now.v+e[i].w<dis[e[i].y]) {
                dis[e[i].y]=now.v+e[i].w;
                heap.push((data){e[i].y,dis[e[i].y]});
            }
        }
    }
}

void dij(int p)
{
    for (int i=1;i<=tot;i++) dis[i]=INF;
    dis[pos[p]]=0;
    data u;u.x=pos[p];u.v=0;
    heap.push(u);
    for (int j=1;j<=tot;j++)
    {
        if (heap.empty()) break;
        data u=heap.top();
        heap.pop();
        while (!heap.empty()&&vis[u.x]) u=heap.top(),heap.pop();
        if (vis[u.x]) break;
        int x=u.x;vis[x]=1;
        for (int i=ls[x];i;i=e[i].next)
            if (!vis[e[i].y]&&dis[x]+e[i].w<dis[e[i].y])
            {
                dis[e[i].y]=dis[x]+e[i].w;
                u.x=e[i].y;u.v=dis[e[i].y];
                heap.push(u);
            }
    }
}

void modify(int now,int tl,int tr,int l,int r,int neww,int opt,int w) {
    if (l>r) return ;
    if (tl==l&&tr==r) {
        if (opt) add_edge(now,neww,w);
        else add_edge(neww,now,w);
        return ;
    }
    int mid=(tl+tr)>>1;
    if (r<=mid) modify(t[now].l,tl,mid,l,r,neww,opt,w);
    else if (l>mid) modify(t[now].r,mid+1,tr,l,r,neww,opt,w);
    else {
        modify(t[now].l,tl,mid,l,mid,neww,opt,w);
        modify(t[now].r,mid+1,tr,mid+1,r,neww,opt,w);
    }
}

void build_tree(int &now,int tl,int tr,int opt) {
    t[now=++tot]=(treeNode) {0,0};
    if (!opt) add_edge(now,now-rec,0);
    if (tl==tr) {
        if (opt) pos[tl]=now;
        return ;
    }
    int mid=(tl+tr)>>1;
    build_tree(t[now].l,tl,mid,opt);
    build_tree(t[now].r,mid+1,tr,opt);
    if (opt) {
        add_edge(t[now].l,now,0);
        add_edge(t[now].r,now,0);
    } else {
        add_edge(now,t[now].l,0);
        add_edge(now,t[now].r,0);
    }
}

signed main(void) {
    int n=read(),m=read(),st=1;
    int root1,root2;
    build_tree(root1,1,n,1); rec=tot;
    build_tree(root2,1,n,0);
    rep(i,1,m) {
        int a=read(),b=read(),c=a,d=b,w=read();
        modify(root1,1,n,a,b,++tot,1,w);
        modify(root2,1,n,c,d,tot,0,w);
        modify(root1,1,n,c,d,++tot,1,w);
        modify(root2,1,n,a,b,tot,0,w);
    }
    dij(st);
    if(dis[pos[n]] == INF)
    	puts("-1");
	else
    	printf("%lld\n", dis[pos[n]]/2);
    return 0;
}

