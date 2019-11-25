#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cctype>
#include<set>
#define LL long long
#define M 4000100
#define N 50010
using namespace std;
const int inf=0x7f7f7f7f;
const int mod=1e9+7;
const double eps=1e-6;
inline int read(){
	int f=1,x=0;char s=getchar();
	while(!isdigit(s)){if (s=='-')f=-1;s=getchar();}
	while(isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
struct node{
	int a,b;
}p[M];
vector<int>que;
int n,to[M],maxtim,secmax;
int head[M],cnt;
struct edge{
	int to,nxt;	
}e[M];
inline void add_edge(int u,int v){
	e[++cnt].nxt=head[u],head[u]=cnt,e[cnt].to=v;	
}
int vis[M];
int totn,tote,ans;
inline void dfs(int rt){
	vis[rt]=1,totn++;
	if (rt>n)
		if (maxtim<rt-n) secmax=maxtim,maxtim=rt-n;
		else secmax=max(secmax,rt-n);
	for (int i=head[rt];i;i=e[i].nxt){
		tote++;
		if (vis[e[i].to]) continue;
		dfs(e[i].to);	
	}
}
signed main(void){
	freopen("exam.in","r",stdin);
	freopen("exam.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++){
		p[i].a=read(),p[i].b=read();
		que.push_back(p[i].a),que.push_back(p[i].b);
	}
	sort(que.begin(),que.end());
	for (int i=1;i<=n;i++){
		int pa=lower_bound(que.begin(),que.end(),p[i].a)-que.begin()+1;
		int pb=lower_bound(que.begin(),que.end(),p[i].b)-que.begin()+1;
		to[pa]=p[i].a,to[pb]=p[i].b;
		add_edge(i,pa+n),add_edge(pa+n,i),add_edge(i,pb+n),add_edge(pb+n,i);
	}
	for (int i=1;i<=n;i++){
		if (!vis[i]){
			maxtim=0,secmax=0,totn=0,tote=0;
			dfs(i);
			if (tote/2>totn){
				printf("-1");
				return 0;	
			}
			if (totn==tote/2) ans=max(ans,maxtim);
			else ans=max(ans,secmax);
		}
	}
	printf("%d",to[ans]);
	return 0;
}

