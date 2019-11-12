#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 210;
const int M = 50010;
int read(){
	char ch=getchar();
	int res=0;
	while(ch<'0' || ch>'9'){
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res;
}
int INF;
int n,m,G,D;
int maxg,maxd,markg,markd;
int cnte,head[N];
struct edge{
	int u,v,g,d;
}e[M];
int fa[N];
int find(int x){
	return fa[x]==x ? x : fa[x]=find(fa[x]);
}
bool judge(int x_g,int x_d){
	for(int i=1; i<=n; i++){
		fa[i]=i;
	}
	for(int i=1; i<=m; i++){
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu!=fv && x_g>=e[i].g && x_d>=e[i].d){
			fa[fv]=fu;
		}
	}
	for(int i=2; i<=n; i++){
		if(find(i)!=find(i-1)){
			return 0;
		}
	}
	return 1;
}
int workd(int x_g,int l,int r){
	bool flag=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(judge(x_g, mid)){
			flag=1;
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	if(flag==0){
		return -1;
	}
	else{
		return l;
	}
}
int workg(int l,int r){
	int ans=INF;
	while(l<r){
		int mid=(l+r)>>1;
		int x_d=workd(mid, 0, maxd+1);
		if(x_d!=-1){
			ans=min(ans, x_d*D+mid*G);
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	if(ans==INF){
		return -1;
	}
	else{
		return ans;
	}
}
signed main(){
	freopen("pay.in", "r", stdin);
	freopen("pay.out", "w", stdout);
	memset(&INF, 0x3f, sizeof (long long));
	n=read();
	m=read();
	G=read();
	D=read();
	for(int i=1; i<=m; i++){
		e[i].u=read();
		e[i].v=read();
		e[i].g=read();
		e[i].d=read();
		maxg=max(maxg, e[i].g);
		maxd=max(maxd, e[i].d);
	}
//	int ans=workg(0, maxg+1);
	int ans=INF;
	for(int i=1; i<=maxg; i++){
		int k=workd(i, 0, maxd+1);
		if(k!=-1){
			ans=min(ans, i*G+D*workd(i, 0, maxd+1));
		}
	}
	printf("%lld\n",ans);
	return 0;
}
