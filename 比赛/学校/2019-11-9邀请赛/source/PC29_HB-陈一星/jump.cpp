#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cctype>
#include<set>
#include<stack>
#define LL long long
#define M 400100
#define N 50010
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const double eps=1e-6;
inline int read(){
	int f=1,x=0;char s=getchar();
	while(!isdigit(s)){if (s=='-')f=-1;s=getchar();}
	while(isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
int n,k;
struct edge{
	int to,nxt;	
}e[M];
int cnt,head[M];
inline void add_edge(int u,int v){
	e[++cnt].nxt=head[u],head[u]=cnt,e[cnt].to=v;
}
int ans[M],all;
multiset<int>s1,s2;
inline void init(int rt,int fa,int dis){
	ans[1]+=dis/k+(dis%k!=0);s2.insert(dis);
	for (int i=head[rt];i;i=e[i].nxt){
		if (e[i].to==fa) continue;
		init(e[i].to,rt,dis+1);	
	}
}
inline void dfs(int rt,int fa,int depth){
	ans[rt]=ans[fa];
	s2.erase(s2.find(depth));
	s1.insert(-depth);
	if (rt!=fa){
		for (int i=1;i<=n/k+1;i++){
			multiset<int>::iterator it=s2.lower_bound(i*k+depth);
			if (it==s2.end()) break;
			for (it;*it<(i+1)*k+depth&&it!=s2.end();it++)
				ans[rt]+=i;
		}
		for (int i=1;i<=n/k+1;i++){
			multiset<int>::iterator it=s1.lower_bound(i*k+depth);
			if (it==s1.end()) break;
			for (it;*it<(i+1)*k+depth&&it!=s1.end();it++)
				ans[rt]-=i;
		}
	}
	for (int i=head[rt];i;i=e[i].nxt){
		if (e[i].to==fa) continue;
		dfs(e[i].to,rt,depth+1);
	}
}
signed main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	n=read(),k=read();
	for (int i=1;i<=n-1;i++){
		int u=read(),v=read();
		add_edge(u,v),add_edge(v,u);
	}
	init(1,0,0);
	dfs(1,1,0);
	for (int i=1;i<=n;i++)
		all+=ans[i];
	printf("%lld",all/2);
	return 0;
}

