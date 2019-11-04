#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<time.h>
#define M 1010000
#define rgi register int
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const int mod=998244353;
inline int read(){
	int x=0,f=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while(isdigit(s)){x=(x<<1)+(x<<3)+(s^48),s=getchar();}
	return x*f;
}
struct edge{
	int to,next;
}e[M];
int cnt,head[M];
inline void add_edge(int a,int b){
	e[++cnt].next=head[a],head[a]=cnt,e[cnt].to=b;
}
int n,m,cnte;
int fa[M],out[M],ans[M],tim[M],in[M];
inline int find(int a){
	return fa[a]==a?fa[a]:fa[a]=find(fa[a]);
} 
signed main(void){
	freopen("migration.in","r",stdin);
	freopen("migration.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=m;i++){
		int a=read(),b=read();
		add_edge(a,b),add_edge(b,a);
	}
	cnte=n;
	for (int i=1;i<=n;i++) fa[i]=i,out[i]=read();
	for (int i=n;i>=1;i--){
		in[out[i]]=1;
		for (int j=head[out[i]];j;j=e[j].next){
			if (in[e[j].to]){
				int X=find(e[j].to);
				if (X==out[i]) continue;
				fa[X]=out[i];
				cnte--;
			}
		}
		ans[i]=(cnte==i);
	}
	for (int i=1;i<=n;i++)
		if (ans[i]) printf("YES\n");
		else printf("NO\n");
	return 0;
}
