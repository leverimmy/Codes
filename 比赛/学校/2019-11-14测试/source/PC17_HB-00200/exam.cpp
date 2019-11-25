#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node{
	int x,y;
}in[1000010];
map<int,int> m;
map<int,int > to;
int back[2000010];
bool cmp(node a,node b){
	if(a.x==b.x) return a.y>b.y; 
	else return a.x<b.x;
} 
int cnt; 
int res=0;
int pp;
int fa[1000010];
int find(int x){
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("exam.in","r",stdin);
	freopen("exam.out","w",stdin);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&in[i].x,&in[i].y);
		if(in[i].y<in[i].x) swap(in[i].x,in[i].y);
	}
	sort(in+1,in+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(!to[in[i].x]){
			to[in[i].x]=++cnt;
			back[cnt]=in[i].x;
		}
		if(!to[in[i].y]){
			to[in[i].y]=++cnt;
			back[cnt]=in[i].y;
		}
		in[i].x=to[in[i].x];
		in[i].y=to[in[i].y];
	}
	for(int i=1;i<=cnt;i++){
		fa[i]=i;
	}
	if(cnt<n){
		printf("-1");
		return 0;
	}
//	if(n<=20){
//		dfs(1);
//		printf("%d\n",pp);
//	}
//	else{
	for(int i=1;i<=n;i++){
		int eu=find(in[i].x);
		int ev=find(in[i].y);	
		if(back[eu]>back[ev]) swap(eu,ev);	
		if(fa[eu]==0 && fa[ev]==0){
			printf("-1");
			return 0;
		}
		if(eu==ev){
			fa[ev]=0;
			pp=max(pp,back[eu]);
		} 
		if(fa[eu]!=0 && fa[ev]!=0){
			pp=max(pp,back[eu]);
			fa[eu]=ev;			
		}
		else if(fa[eu]!=0){
			pp=max(pp,back[eu]);
			fa[eu]=0;
		}
		else if(fa[ev]!=0){
			fa[ev]=0;
			pp=max(pp,back[ev]);
		}
	}
	printf("%lld\n",pp);
//	}
}
