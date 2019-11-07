#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int m,n,r;
vector <int> v;
int main(){
	freopen("9.in", "r", stdin);
	freopen("9.out", "w", stdout);
	scanf("%d,%d,%d",&m,&n,&r);
	for(int i=1; i<=m; i++){
		if(i%n==r){
			v.push_back(i);
		}
	}
	int len=v.size(),cnt=0;
	for(int i=0; i<len; i++){
		printf("%d",v[i]);
		if(i==len-1){
			break;
		}
		cnt++;
		if(cnt==10){
			cnt=0;
			printf("\n");
		}
		else{
			printf(",");
		}
	}
	return 0;
}

