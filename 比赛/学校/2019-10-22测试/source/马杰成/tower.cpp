#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x;
	int y;
}in[1010];
int n;
int fa[1010];
int find(int x){
	if(fa[x]==x) return fa[x];
	else return fa[x]=find(fa[x]);
}
int a[1010][1010];
void merge(int u,int v){
	int eu=find(u);
	int ev=find(v);
	fa[ev]=eu;
}
int check(int k){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]<=k && i!=j){
				merge(i,j);
			}
		}
	}
	int t=find(1);
	for(int i=1;i<=n;i++){
		if(find(i)!=t) return 0;
	}
	return 1;
}
int cal(int i,int j){
	return (in[i].x-in[j].x)*(in[i].x-in[j].x)+(in[i].y-in[j].y)*(in[i].y-in[j].y);
}
signed main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&in[i].x,&in[i].y);
	}		
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=cal(i,j);
		}
	}
	int l=0,r=12500000000;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%lld\n",l);
}
