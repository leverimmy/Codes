#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
#include<cctype>
#include<stack>
#include<queue>
#define int long long
using namespace std;
const int M=4000000;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
inline int read(){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
struct edge{
	int to,from,nxt;	
}e[M];
int cnt,head[M],heads[M];
inline void add_edge(int u,int v,int s,int t){
	e[++cnt].nxt=head[s+1],head[s+1]=cnt,e[cnt].from=u,e[cnt].to=v;
	e[++cnt].nxt=heads[t+1],heads[t+1]=cnt,e[cnt].from=u,e[cnt].to=v; 
}
int n,m,t,color[M],cnte[M];
signed main(void){
	freopen("grape.in","r",stdin);
	freopen("grape.out","w",stdout);
	n=read(),m=read(),t=read();
	for (int i=1;i<=m;i++){
		int u=read(),v=read(),s=read(),t=read();
		add_edge(u,v,s,t);
	}
	memset(color,-1,sizeof(color));
	for (int i=1;i<=t;i++){
		for (int j=heads[i];j;j=e[j].nxt){
			cnte[e[j].from]--,cnte[e[j].to]--;
			if (!cnte[e[j].from]) color[e[j].from]=-1;
			if (!cnte[e[j].to]) color[e[j].to]=-1;
		}
		int ans=1;
		for (int j=head[i];j;j=e[j].nxt){
			cnte[e[j].from]++,cnte[e[j].to]++;
			if (~color[e[j].from]){
				if (color[e[j].to]==-1)
					color[e[j].to]=color[e[j].from]^1;
				else if (color[e[j].from]==color[e[j].to])
					ans=0;
			}
			else if (~color[e[j].to]){
				if (color[e[j].from]==-1)
					color[e[j].from]=color[e[j].to]^1;
				else if (color[e[j].from]==color[e[j].to])
					ans=0;
			}
			else
				color[e[j].from]=1,color[e[j].to]=0;
		}
		if (ans) printf("Yes");
		else printf("No");
		puts("");
	}
	return 0;
}

