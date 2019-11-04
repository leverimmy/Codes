#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int N = 100010;
const int M = 320;
const int K = 110;
const int J = 10010;
int n,m,blo;
int a[N],bel[N];
bool flag=1;
int P;
vector <int> V[M];
namespace type1{
	int query(int l,int r,int v){
		int res=0;
		for(int i=l; i<=bel[l]*blo; i++){
			res+=((a[i]%P)==v);
		}
		if(bel[l]!=bel[r]){
			for(int i=(bel[r]-1)*blo+1; i<=r; i++){
				res+=((a[i]%P)==v);
			}
		}
		for(int i=bel[l]+1; i<=bel[r]-1; i++){
			int posl=lower_bound(V[i].begin(), V[i].end(), P)-V[i].begin();
			int posr=upper_bound(V[i].begin(), V[i].end(), P)-V[i].begin();
			res+=posr-posl;
		}
		return res;
	}
}
//namespace type2{
//	int query(int l,int r,int p,int v){
//		int res=0;
//		for(int i=l; i<=bel[l]*blo; i++){
//			res+=((a[i]%p)==v);
//		}
//		if(bel[l]!=bel[r]){
//			for(int i=(bel[r]-1)*blo+1; i<=r; i++){
//				res+=((a[i]%p)==v);
//			}
//		}
//		for(int i=bel[l]+1; i<=bel[r]-1; i++){
//			for(int j=v; j<=10000; j+=p){
//				int posl=lower_bound(V[i].begin(), V[i].end(), j)-V[i].begin();
//				int posr=upper_bound(V[i].begin(), V[i].end(), j)-V[i].begin();
//				res+=posr-posl; 
//			}
//		}
//		return res;
//	}
//}
namespace type3{
	int pre[M][K][K],sump[M][K][K];
	int val[M][J],sum[M][J];
	void build(){
		for(int i=1; i<=n; i++){
			val[bel[i]][a[i]]++;
			for(int j=1; j<=100; j++){
				pre[bel[i]][j][a[i]%j]++;
			}
		}
		int siz=bel[n];
		for(int i=1; i<=siz; i++){
			for(int j=0; j<=10000; j++){
				sum[i][j]=sum[i-1][j]+val[i][j];
			}
			for(int j=1; j<=100; j++){
				for(int k=0; k<=100; k++){
					sump[i][j][k]=sump[i-1][j][k]+pre[i][j][k];
				}
			}
		}
	}
	int query(int l,int r,int p,int v){
		int res=0;
		if(bel[l]==bel[r]){
			for(int i=l; i<=r; i++){
				res+=((a[i]%p)==v);
			}
			return res;
		}
		for(int i=l; i<=bel[l]*blo; i++){
			res+=((a[i]%p)==v);
		}
		if(bel[l]!=bel[r]){
			for(int i=(bel[r]-1)*blo+1; i<=r; i++){
				res+=((a[i]%p)==v);
			}
		}
		if(p<=100){
			if(bel[r]-1<bel[l]){
				return res;
			}
			res+=sump[bel[r]-1][p][v]-sump[bel[l]][p][v];
		}
		else{
			if(bel[r]-1<bel[l]){
				return res;
			}
			for(int i=0; i*p+v<=10000; i++){
				res+=sum[bel[r]-1][i*p+v]-sum[bel[l]][i*p+v];
			} 
		}
		return res;
	}
}
struct q{
	int l,r,p,v;
}ask[N];
int main(){
	freopen("light.in", "r", stdin);
	freopen("light.out", "w", stdout);
	scanf("%d%d",&n,&m);
	blo=sqrt(n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	for(int i=1; i<=n; i++){
		bel[i]=(i-1)/blo+1;
	}
	for(int i=1; i<=m; i++){
		scanf("%d%d%d%d",&ask[i].l,&ask[i].r,&ask[i].p,&ask[i].v);
		if(P==0){
			P=ask[i].p;
		}
		else if(P!=ask[i].p){
			flag=0;
		}
	}
	if(flag){// not changed
		for(int i=1; i<=n; i++){
			V[bel[i]].push_back(a[i]%P); 
		}
		for(int i=1; i<=bel[n]; i++){
			sort(V[i].begin(), V[i].end());
		}
		for(int i=1; i<=m; i++){
			printf("%d\n",type1::query(ask[i].l, ask[i].r, ask[i].v));
		}
	}
//	else{
//		for(int i=1; i<=n; i++){
//			V[bel[i]].push_back(a[i]);
//		}
//		for(int i=1; i<=blo+1; i++){
//			sort(V[i].begin(), V[i].end());
//		}
//		for(int i=1; i<=m; i++){
//			printf("%d\n",type2::query(ask[i].l, ask[i].r, ask[i].p, ask[i].v));
//		}
//	}
	else{
		type3::build();
		for(int i=1; i<=m; i++){
			printf("%d\n",type3::query(ask[i].l, ask[i].r, ask[i].p, ask[i].v));
		}
	}
	return 0;
}
