#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<climits>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<stack>
#include<map>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
struct node{int x,y;node(){}node(int x,int y):x(x),y(y){}};bool operator ==(node x,node y){return (x.x==y.x)&&(x.y==y.y);}int a[110][110];std::queue<node>q,f,t,g;int dx[5]={0,1,0,-1,0},dy[5]={0,0,1,0,-1};node ed;
int bfs(){int tm(0);while(!q.empty()||!t.empty()){tm++;while(!f.empty()){node u=f.front();f.pop();a[u.x][u.y]=1;for(int i=1;i<=4;i++)if(!a[u.x+dx[i]][u.y+dy[i]])g.push(node(u.x+dx[i],u.y+dy[i]));}while(!g.empty()){f.push(g.front());g.pop();}while(!q.empty()){node u=q.front();q.pop();for(int i=1;i<=4;i++){int nx=u.x+dx[i],ny=u.y+dy[i];if(nx==ed.x&&ny==ed.y)return tm;if(a[nx][ny]==1)continue;t.push(node(nx,ny));}}while(!t.empty()){q.push(t.front());t.pop();}}return -1;}
signed main(){freopen("slikar.in","r",stdin);freopen("slikar.out","w",stdout);int n,m;scanf("%d%d",&n,&m);for(int i=1;i<=n;i++)a[i][0]=a[i][m+1]=1;for(int i=1;i<=m;i++)a[0][i]=a[n+1][i]=1;for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){char ch;std::cin>>ch;if(ch=='.')continue;if(ch=='X')a[i][j]=1;if(ch=='S')q.push(node(i,j));if(ch=='*')f.push(node(i,j));if(ch=='D'){ed=node(i,j);a[i][j]=1;}}int ans(bfs());if(ans==-1)return puts("ORZ hzwer!!!");return printf("%d\n",ans),0;}
