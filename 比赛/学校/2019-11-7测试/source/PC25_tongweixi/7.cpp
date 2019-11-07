#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 30;
int n;
int a[N][N];
bool good[N];
bool check(int sta){
	int cnt=0;
	for(int i=0; i<n; i++){
		good[i+1]=sta & (1<<i);
		if(good[i+1]){
			cnt++;
		}
	}
	int bad=n-cnt;
	if(cnt<=bad){
		return 0;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(good[i] && i!=j){
				if(a[i][j] && !good[j]){
					return 0;
				}
			}
		}
	}
	return 1;
}
void print(){
	for(int i=1; i<=n; i++){
		if(good[i]){
			printf("%d ",i);
		}
	}
}
int main(){
	freopen("7.in", "r", stdin);
	freopen("7.out", "w", stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int sta=0; sta<(1<<n); sta++){
		if(check(sta)){
			print();
			return 0;
		}
	}
	return 0;
}

