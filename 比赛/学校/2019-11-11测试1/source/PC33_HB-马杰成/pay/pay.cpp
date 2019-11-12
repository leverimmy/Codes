#include<bits/stdc++.h>
#define R register 
#define int long long
using namespace std;
inline int read(){
	char ch=getchar();
	int ans=0,f=1;
	while(ch<'0' || ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*f;
}
struct node{
	 int u,v,g,d;
}in[50010];
int fa[205];
inline int find(int x){
	if(fa[x]==x) return fa[x];
	else return fa[x]=find(fa[x]);
}
int G,D;
int minn;
int n,m;
bool cmp_init(node a,node b){
	return a.d<b.d;
}
bool cmp(node a,node b){
	return a.g<b.g;
}
void init(){
	sort(in+1,in+m+1,cmp_init);
	int cnt=0;
	for(R int i=1;i<=n;i++)
		fa[i]=i;
	for(R int i=1;i<=m;i++){
		R int eu=find(in[i].u);
		R int ev=find(in[i].v);
		if(eu!=ev){
			fa[ev]=eu;
			cnt++;
			if(cnt==n-1){
				minn=in[i].d;
				return;
			}
		}
	}	
} 
map<int ,int > to;
int f[1000010];
int c=0;
int b[1000010];
int result=1e16;

void run(int k){
	int cnt=0;
	for(R int i=1;i<=n;i++)
		fa[i]=i;
	for(R int i=1;i<=m;i++){
		R int eu=find(in[i].u);
		R int ev=find(in[i].v);
		if(in[i].d>k) continue;
		if(eu!=ev){
			fa[ev]=eu;
			cnt++;
			if(cnt==n-1){
				result=min(result,k*D+in[i].g*G);
				return;
			}
		}
	}	
}
signed main(){
	freopen("pay.in","r",stdin);
	freopen("pay.out","w",stdout);
	n=read();m=read();
	G=read();D=read();
	for(R int i=1;i<=m;i++){
		in[i].u=read();in[i].v=read();in[i].g=read();in[i].d=read();
		b[i]=in[i].d;
	}
	sort(b+1,b+m+1);
	for(R int i=1;i<=m;i++){
		if(!to[b[i]]){
			to[b[i]]=++c;
			f[c]=b[i];
		}
	}
	init();
	minn=to[minn];
	sort(in+1,in+m+1,cmp);
	for(R int i=minn;i<=c;i++){
		run(f[i]);
	}
	if(result==1e16){
		printf("-1\n");
	}
	else
		printf("%lld\n",result); 
}
