#include<bits/stdc++.h>
using namespace std;
int edcnt,n,head[100010],t1,t2,t3,degin[100010],tmp[100010];
struct edge{
	int to,nxt;
}ed[300010];
inline void addedge(int from,int to){
	ed[++edcnt].nxt=head[from],
	ed[edcnt].to=to,
	degin[to]++,
	head[from]=edcnt;
}
inline int fun(int x){
	queue<int>q;
	for(int i=1;i<=n;++i)
		tmp[i]=degin[i];
	q.push(x);
	int now=0,ans=0;
	while(!q.empty()){
		now=q.front(),
		q.pop();
		for(int i=head[now];i;i=ed[i].nxt){
			tmp[ed[i].to]--;
			if(!tmp[ed[i].to])
				ans++,q.push(ed[i].to);
		}
	}
	return ans;
}//this name sounds fun
int main(){
	freopen("catas.in","r",stdin);
	freopen("catas.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		while(true){
			scanf("%d",&t1);
			if(!t1)
				break;
			addedge(t1,i);
		}
	}
	for(int i=1;i<=n;++i){
		printf("%d\n",fun(i));
	}
}
