#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
const int N = 1010;
const int maxx = 1250000001;
int n;
int dis[N][N];
pair<int, int> a[N];
int fa[N];
int find(int x){
	return x==fa[x] ? x : fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		fa[fy]=fx;
	}
}
bool check(int x){
	for(int i=1; i<=n; i++){
		fa[i]=i;
	}
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			if(dis[i][j]<=x){
				merge(i, j);
			}
		}
	}
	for(int i=2; i<=n; i++){
		if(find(i)!=find(i-1)){
			return 0;
		}
	}
	return 1;
}
signed main(){
	freopen("tower.in", "r", stdin);
	freopen("tower.out", "w", stdout);
	scanf("%lld",&n);
	for(int i=1; i<=n; i++){
		scanf("%lld%lld",&a[i].first,&a[i].second);
	}
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			dis[i][j]=dis[j][i]=(a[i].first-a[j].first)*(a[i].first-a[j].first)+(a[i].second-a[j].second)*(a[i].second-a[j].second);
		}
	}
	int l=0,r=maxx;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	printf("%d\n",l);
	return 0;
}

