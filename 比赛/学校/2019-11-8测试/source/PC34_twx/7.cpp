#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1000010;
int n;
bool vis[N];
void init(){
	for(int i=2; i<=n; i++){
		if(!vis[i]){
			vis[i]=1;
			printf("%d ",i);
			for(int j=1; i*j<=n; j++){
				vis[i*j]=1;
			}
		}
	}
}
int main(){
	freopen("7.in", "r", stdin);
	freopen("7.out", "w", stdout);
	scanf("%d",&n);
	init();
	return 0;
}

