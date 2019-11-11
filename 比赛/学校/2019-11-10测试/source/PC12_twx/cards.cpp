#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 60;
const int INF = -2147483644;
int a[N],d[N];
int tmp[N];
int out[N];
int o,x,ans=INF;
void dfs(int ol,int xl,int pts,int last,int k){
	if(pts+ol*ol<=ans){
		return;
	}
	if(ol==0 && xl==0){
		if(ans<pts){
			ans=pts;
			memcpy(out, tmp, sizeof tmp);
		}
		return;
	}
	if(ol>0){
		if(last==0){
			tmp[o+x-(ol-1)-xl]=0;
			dfs(ol-1, xl, pts+d[k+1], 0, k+1);
		}
		else{
			tmp[o+x-(ol-1)-xl]=0;
			dfs(ol-1, xl, pts+1, 0, 1);
		}
	}
	if(xl>0){
		if(last==1){
			tmp[o+x-(ol-1)-xl]=1;
			dfs(ol, xl-1, pts-d[k+1], 1, k+1);
		}
		else{
			tmp[o+x-(ol-1)-xl]=1;
			dfs(ol, xl-1, pts-1, 1, 1);
		}
	}
}
int main(){
	freopen("cards.in", "r", stdin);
	freopen("cards.out", "w", stdout);
	scanf("%d%d",&o,&x);
	for(int i=1; i<=o+x; i++){
		d[i]=i*i-(i-1)*(i-1);
	}
	if(o>0){
		tmp[1]=0;
		dfs(o-1, x, 1, 0, 1);
	}
	if(x>0){
		tmp[1]=1;
		dfs(o, x-1, -1, 1, 1);
	}
	printf("%d\n",ans);
	for(int i=1; i<=o+x; i++){
		if(out[i]==0){
			printf("o");
		}
		else{
			printf("x");
		}
	}
	return 0;
}

