#include <bits/stdc++.h>

using namespace std;
const int N = 20;
typedef pair<int, int> p; 
int n,m;
int a[N];
p opt[N];
int ans[N];
bool vis[N],f[N];
int out;
int cal(){
	int res=0;
	memset(f, 0, sizeof f);
	for(int i=1; i<=m; i++){
		int x=ans[i];
		int l=opt[x].first,r=opt[x].second;
		int cnt=0;
		for(int k=l; k<=r; k++){
			if(f[k]){
				res+=cnt*cnt;
				cnt=0;
			}
			else{
				f[k]=1;
				cnt++;
			}
		}
		res+=cnt*cnt;
	}
	return res;
}
void dfs(int now){
	if(now==m){
		out=max(out, cal());
		return;
	}
	for(int i=1; i<=m; i++){
		if(!vis[i]){
			vis[i]=1;
			ans[now+1]=i;
			dfs(now+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("shopping.in", "r", stdin);
	freopen("shopping.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	for(int i=1; i<=m; i++){
		scanf("%d%d",&opt[i].first,&opt[i].second);
	}
	dfs(0);
	printf("%d\n",out);
	return 0;
}

