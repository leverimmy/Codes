#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100010;
int n,m;
int a[N];
int main(){
	freopen("pudding.in", "r", stdin);
	freopen("pudding.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	for(int i=1; i<=m; i++){
		int opt;
		scanf("%d",&opt);
		if(opt==1){
			int x,y;
			scanf("%d%d",&x,&y);
			if(x==y){
				continue;
			}
			for(int i=1; i<=n; i++){
				if(a[i]==x){
					a[i]=y;
				}
			}
		}
		else if(opt==2){
			int ans=0; 
			for(int i=1; i<=n; i++){
				ans++;
				while(i+1<=n && a[i+1]==a[i]){
					i++;
				}
			} 
			printf("%d\n",ans); 
		}
	}
	return 0;
}

