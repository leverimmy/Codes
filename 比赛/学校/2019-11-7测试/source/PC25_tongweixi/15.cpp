#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1000000;
int n;
int a[N];
int main(){
	freopen("15.in", "r", stdin);
	freopen("15.out", "w", stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	int maxx=0,mark=0;
	for(int i=1; i<=n; i++){
		if(a[i]>maxx){
			maxx=a[i];
			mark=i;
		}
	}
	printf("%d %d\n", a[mark], mark-1);
	return 0;
}

