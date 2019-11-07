#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 4000;
int n,m,ans;
int fa[N];
int find(int x){
	return x==fa[x] ? x : fa[x]=find(fa[x]);
}
int main(){
	freopen("18.in", "r", stdin);
	freopen("18.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		fa[i]=i;
	}
	for(int i=1; i<=m; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int fx=find(x),fy=find(y);
		if(fx!=fy){
			fa[fy]=fx;
		}
	}
	sort(fa+1, fa+1+n);
	for(int i=1; i<=n; i++){
		if(fa[i]!=fa[i-1]){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}

