#include<bits/stdc++.h>
using namespace std;
int n;
int ans[305];
int vis[505];
int cnt;
int ans_cnt; 
vector<int > mjc[10000];
int a[305];
int tot;
void check(){
	int f=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n*(n-1)/2;i++){
		vis[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((vis[ans[i]+ans[j]]==0)){
				f=1;
			}
			else{
				vis[ans[i]+ans[j]]--;
			}
		}
	} 
	for(int i=1;i<=n;i++){
		if(vis[a[i]]) f=1;
	}
	if(f) return;
	else{
		cnt++;
		sort(ans+1,ans+n+1);
		ans_cnt++;
		for(int i=1;i<=n;i++)
			mjc[ans_cnt].push_back(ans[i]);
	}
}
 
void dfs(int step){
	if(step==n){
		check();
		return;
	}
	for(int i=tot;i>=1;i--){
		if(step==0 || i<=ans[step]){
			step++;
			ans[step]=i;
			dfs(step);
			ans[step]=0;
			step--;
		}
	}	
}			
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n*(n-1)/2;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		tot+=a[i];
	}
	tot/=2;
	dfs(0);
	printf("%d\n",ans_cnt);
	for(int i=1;i<=ans_cnt;i++){
		for(int j=0;j<mjc[i].size();j++){
			printf("%d ",mjc[i][j]);
		}
		printf("\n");
	}
}
