#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100010;
const int INF = 0x3f3f3f3f;
int n,m,ans;
bool X[N],y1[N],y2[N];
int main(){
	freopen("rush.in", "r", stdin);
	freopen("rush.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		X[x]=1;
		y1[y]=1;
		y2[y]=1;
	}
	for(int i=1; i<=n; i++){
		if(X[i]){
			continue;
		}
		int tmp1=(y1[i]==0)+(y2[n-i+1]==0);
		int tmp2=(y2[i]==0)+(y1[n-i+1]==0);
		if(tmp1>tmp2){
			y2[i]=1;
			y1[n-i+1]=1;
		} 
		else{
			y1[i]=1;
			y2[n-i+1]=1;
		}
		ans++;
	}
	for(int i=1; i<=n; i++){
		ans+=(y1[i]==0 || y2[i]==0);
	}
	printf("%d\n",ans);
	return 0;
}

