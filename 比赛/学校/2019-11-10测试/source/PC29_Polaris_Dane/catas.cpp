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
#define M 400100
#define N 50010
using namespace std;
const int inf=0x3f3f3f3f;
const int mod=10000;
const double eps=1e-6;
inline int read(){
	int f=1,x=0;char s=getchar();
	while(!isdigit(s)){if (s=='-')f=-1;s=getchar();}
	while(isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
int n;
struct edge{
	int to,nxt;
}e[M];
int head[M],cnt,indgr[M];
inline void add_edge(int u,int v){
	e[++cnt].nxt=head[u],head[u]=cnt,e[cnt].to=v;
}
queue<int>q;
int ans;
inline void tp(void){
	ans=0;
	while (!q.empty()){
		int h=q.front();q.pop();
		ans++;
		for (int i=head[h];i;i=e[i].nxt){
			indgr[e[i].to]--;
			if (!indgr[e[i].to]) q.push(e[i].to);
		}
	}
}
signed main(void){
	freopen("catas.in","r",stdin);
	freopen("catas.out","w",stdout);
	n=read();
	for (int i=1,x;i<=n;i++){
		while (x=read())
			add_edge(x,i);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=cnt;j++) indgr[e[j].to]++;
		q.push(i);
		tp();
		printf("%d\n",ans-1);
	}
	return 0;
}

