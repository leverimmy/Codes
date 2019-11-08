#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1000010;
int n;
int a[N];
int main(){
	freopen("4.in", "r", stdin);
	freopen("4.out", "w", stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	sort(a+1, a+1+n);
	for(int i=1; i<=n; i++){
		printf("%d ",a[i]);
	}
	return 0;
}

