#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1000000;
int n;
char s[N];
void dfs(int l,int r){
	printf("%s\n", s+1);
	if(r-l<=1){
		return;
	}
	swap(s[l], s[r]);
	dfs(l+1, r-1);
}
int main(){
	freopen("17.in", "r", stdin);
	freopen("17.out", "w", stdout);
	scanf("%d",&n);
	scanf("%s", s+1);
	dfs(1, n);
	return 0;
}

