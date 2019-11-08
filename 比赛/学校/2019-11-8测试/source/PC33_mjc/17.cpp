#include<bits/stdc++.h>
#define int long long
using namespace std;
int c[200010];
map<int,int> p;
int to[200010];
int lowbit(int x){
	return x&(-x);
}
int n,cnt;
void update(int x,int v){
	while(x<=n){
		c[x]+=v;
		x+=lowbit(x);
	}
}
int ask(int x){
	int ret=0;
	while(x>0){
		ret+=c[x];
		x-=lowbit(x);
	}
	return ret;
}
int ans[200010]; 
struct node{
	int x,y,ind;
}in[200010];
bool cmp(node a,node b){
	if(a.x==b.x){
		return a.y<b.y;
	}
	else 
		return a.x<b.x;
}
vector<node > now; 
void go(){
	for(int i=0;i<now.size();i++){
		ans[now[i].ind]+=ask(p[now[i].y]);
		update(p[now[i].y],1);
	}
}
int mjc[200010];
signed main(){
	freopen("17.in","r",stdin);
	freopen("17.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&in[i].x,&in[i].y);
		if(!p[in[i].y]){
			p[in[i].y]=++cnt;
		}
		in[i].ind=i;		
	}
	sort(in+1,in+n+1,cmp);
	int p=0;
	for(int i=1;i<=n;i++){
		now.clear();
		int t=in[i].x;
		int j=i;
		while(1){
			if(j==n || in[j].x!=t){
				if(j==n){
					now.push_back(in[j]); 
					i=j;
					break;
				}
				else{
					i=j-1;
					break;
				}
			}
			now.push_back(in[j]);
			j++; 
		}
		go();
	}
	for(int i=1;i<=n;i++){
		mjc[ans[i]]++;
	}
	for(int i=0;i<n;i++){
		printf("%lld\n",mjc[i]);
	}
}
