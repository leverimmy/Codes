#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100010;
int n,m,ans;
int a[N];
typedef double db;
void work1(){
	for(int i=1; i<=m; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x]=y;
		db tmp=-1.0;
		int ans=0;
		for(int j=1; j<=m; j++){
			db k=(db)a[j]/(db)j;
			if(k<0){
				continue;
			}
			if(tmp<k){
				tmp=k;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
}
void work2(){
	db maxk=-1.0;
	int res=0;
	for(int i=1; i<=m; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		db k=(db)y/(db)x;
		if(maxk<k){
			maxk=k;
			res++;
		} 
		printf("%d\n",res);
	}
}
int main(){
	freopen("noon.in", "r", stdin);
	freopen("noon.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		a[i]=-1;
	}
	if(n<=4000){
		work1();
	}
	else{
		work2();
	}
	return 0;
}

