#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 100010; 
int n,k;
int dis[N];
void bfs(){
	queue<int> q;
	q.push(n);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		int v=u-1;
		if(!dis[v]){
			dis[v]=dis[u]+1;
			if(v==k || v>100000){
				break;
			}
			q.push(v);
		}
		v=u+1;
		if(!dis[v]){
			dis[v]=dis[u]+1;
			if(v==k || v>100000){
				break;
			}
			q.push(v);
		}
		v=u<<1;
		if(!dis[v]){
			dis[v]=dis[u]+1;
			if(v==k || v>100000){
				break;
			}
			q.push(v);
		}
	} 
}
int main(){
	freopen("catchcow.in", "r", stdin);
	freopen("catchcow.out", "w", stdout);
	scanf("%d%d",&n,&k);
	bfs();
	printf("%d\n",dis[k]);
	return 0;
} 
