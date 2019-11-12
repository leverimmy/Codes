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
#define int long long
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
int n,m;
int a[600][600],sx,sy,ex,ey;
int go[600][600];
vector<int>x;
vector<int>y;
struct node{
	int tim,x,y;	
};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
inline void init(int maxtim){
	queue<node>q;
	memset(go,0,sizeof(go));
	for (int i=0;i<x.size();i++) q.push(node{1,x[i],y[i]});
	while (!q.empty()){
		node h=q.front();q.pop();
		int tx=h.x,ty=h.y;
		if (h.tim==maxtim+1) break;
		for (int i=0;i<4;i++)
			if (tx+dx[i]<1||tx+dx[i]>m||ty+dy[i]<1||ty+dy[i]>n||go[ty+dy[i]][tx+dx[i]])
				continue;
			else{
				go[ty+dy[i]][tx+dx[i]]=1;
				q.push(node{h.tim+1,tx+dx[i],ty+dy[i]});
			}
	}
}
int vis[600][600];
inline bool bfs(void){
	queue<node>q;memset(vis,0,sizeof(vis));
	q.push(node{1,sx,sy});
	while (!q.empty()){
		node h=q.front();q.pop();
		int tx=h.x,ty=h.y;
		if (tx==ex&&ty==ey) return true;
		for (int i=0;i<4;i++)
			if (tx+dx[i]<1||tx+dx[i]>m||ty+dy[i]<1||ty+dy[i]>n||go[ty+dy[i]][tx+dx[i]]||vis[ty+dy[i]][tx+dx[i]])
				continue;
			else{
				vis[ty+dy[i]][tx+dx[i]]=1;
				q.push(node{h.tim+1,tx+dx[i],ty+dy[i]});
			}
	}
	return false;
}
signed main(void){
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			char c;cin>>c;
			if (c=='+') x.push_back(j),y.push_back(i);
			if (c=='V') sx=j,sy=i;
			if (c=='J') ex=j,ey=i;
		}
	int l=0,r=n+m;
	while (l<r){
		int mid=(l+r)>>1;
		init(mid);
		if (bfs()) l=mid+1;
		else r=mid;
	}
	printf("%d",l);
	return 0;
}

