#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
string a,b;
int n;
int main(){
	freopen("6.in", "r", stdin);
	freopen("6.out", "w", stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		a+=(char)(i+'A'-1)+a;
	}
	cout<<a;
	return 0;
}

