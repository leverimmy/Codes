#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxm=1000010;
const int maxn=100010;
int read(){
	int f=1,ans=0;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*f;
}
struct node{
	int to;
	int next;
	int w;
}e[maxm];
int head[maxn],cnt;
void add(int u,int v,int ww){
	e[++cnt].next=head[u];
	e[cnt].to=v;
	e[cnt].w=ww;
	head[u]=cnt;
} 
int n,m;
int dis[maxn],inq[maxn];
int spfa(int s){
	for(int i=1;i<=n;i++){
		dis[i]=inf;
	}
	memset(inq,0,sizeof(inq));
	queue<int > q;
	q.push(s);
	inq[s]=1;
	dis[s]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			if(dis[v]==inf){
				dis[v]=dis[u]^(e[i].w);
				if(!inq[v]){
					q.push(v);
					inq[v]=1;
				}
			}
			else{
				if(dis[v]!=(dis[u]^e[i].w)){
					return 1;				
				}
			}
		}
	}
	return 0;
}

int ans=0;
int t;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	t=read();
	while(t--){
		memset(head,0,sizeof(head));
		cnt=0;
		n=read();m=read();
		for(int i=1;i<=m;i++){
			int u,v,w;
			u=read();v=read();w=read(); 
			add(u-1,v,w);
		} 
		if(spfa(0)==1){
			printf("No\n");
		}
		else
			printf("Yes\n");
	}
}
