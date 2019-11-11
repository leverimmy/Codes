#include<bits/stdc++.h>
using namespace std;
int n;
const int maxm=1000010;
const int maxn=1000010;
struct node{
	int to;
	int next;
}e[maxm];
int head[maxn],cnt;
void add(int u,int v){
	e[++cnt].next=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}
int ru[maxn];
int d[maxn];
int main(){
	freopen("catas.in","r",stdin);
	freopen("catas.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		while(1){
			scanf("%d",&x);
			//2 ¡‘ŒÔ->¡‘»À 
			if(x==0) break;
			ru[i]++;
			add(x,i); 
		}
	}
	for(int u=1;u<=n;u++){
		queue<int > q;
		for(int i=1;i<=n;i++){
			d[i]=ru[i];
		}
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			q.push(v);
			d[v]--;
		}
		int ans=0;
		while(!q.empty()){
			int u=q.front();
			if(!d[u])	
				ans++;
			q.pop();
			for(int i=head[u];i;i=e[i].next){
				int v=e[i].to;
				d[v]--;
				if(!d[v]){
					q.push(v);
				}
			}
		}
		printf("%d\n",ans);
	}	
}

 
