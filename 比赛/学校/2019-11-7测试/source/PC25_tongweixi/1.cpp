#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int n,m;
int main(){
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	scanf("%d%d",&n,&m);
	int tmp=n/m+(bool)n%m;
	printf("%d\n",(1<<tmp)-1);
	return 0;
}
