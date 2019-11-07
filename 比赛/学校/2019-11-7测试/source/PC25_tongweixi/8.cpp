#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int a,b,m;
int main(){
	freopen("8.in", "r", stdin);
	freopen("8.out", "w", stdout);
	scanf("%d,%d,%d",&a,&b,&m);
	for(int i=1; i<=1000; i++){
		for(int j=i; j<=1000; j++){
			if(a*i+b*j<=m){
				printf("%d,%d\n",i,j);
			}
		}
	}
	return 0;
}

