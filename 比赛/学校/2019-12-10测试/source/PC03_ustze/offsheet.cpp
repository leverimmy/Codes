#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
typedef long long ll;
const int N=4005,M=N*N,inf=0x3f3f3f3f;
typedef pair<int,int> pii;
#define X first
#define Y second
int n,s,t;
pii a[N],b[N];
int prevv[N],preve[N];
int to[M],cap[M],nt[M],cost[M],p[N];
int num=1;
ll d[N];int flag[N];
queue<int> q;
ll ans;
inline void add(int u,int v,int c,int co){
	num++;
	to[num]=v,cap[num]=c,cost[num]=co,nt[num]=p[u],p[u]=num;
	num++;
	to[num]=u,cap[num]=0,cost[num]=-co,nt[num]=p[v],p[v]=num;
}
inline void mcmf(){
	while(1){
		memset(d,0x3f,sizeof(d));
		q.push(s);d[s]=0;
		while(!q.empty()) {
			int u=q.front();q.pop();
			flag[u]=0;
			for(int i=p[u];i;i=nt[i]) {
				if(cap[i]&&d[to[i]]>d[u]+cost[i]) {
					d[to[i]]=d[u]+cost[i];
					prevv[to[i]]=u,preve[to[i]]=i;
					if(!flag[to[i]]) flag[to[i]]=1,q.push(to[i]); 
				}
			}
		}
		if(d[t]==d[t+1]) break;
		int f=inf;
		for(int v=t;v!=s;v=prevv[v]) f=min(f,cap[preve[v]]);
		ans+=f*d[t];
		for(int v=t;v!=s;v=prevv[v]) {
			cap[preve[v]]-=f,cap[preve[v]^1]+=f;
		}
	}
}
int main(){
	freopen("offsheet.in","r",stdin);
	freopen("offsheet.out","w",stdout);
	n=read();s=0,t=2*n+1;
	for(int i=1;i<=n;i++) {
		a[i].X=read(),a[i].Y=read();
		int c=read();
		add(s,i,c,0);
	}
	for(int i=1;i<=n;i++) {
		b[i].X=read(),b[i].Y=read();
		int c=read();
		add(i+n,t,c,0);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			add(i,j+n,inf,-(abs(a[i].X-b[j].X)+abs(a[i].Y-b[j].Y)));
	mcmf();
	printf("%lld",-ans);
	return 0;
}
