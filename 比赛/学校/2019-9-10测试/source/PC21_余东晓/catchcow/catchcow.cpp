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
struct node{int p,x;node(){}node(int p,int x):p(p),x(x){}};
int bfs(int s,int t){std::queue<node>q;while(!q.empty())q.pop();q.push(node(s,0));while(!q.empty()){node u=q.front();q.pop();if(u.p==t)return u.x;q.push(node(u.p+1,u.x+1));q.push(node(u.p-1,u.x+1));q.push(node(u.p<<1,u.x+1));}}
signed main(){freopen("catchcow.in","r",stdin);freopen("catchcow.out","w",stdout);int n,k;scanf("%d%d",&n,&k);return printf("%d\n",bfs(n,k)),0;}
