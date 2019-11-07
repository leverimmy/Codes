#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v[1000];
int a,b;
int main(){
	freopen("10.in", "r", stdin);
	freopen("10.out", "w", stdout);
	scanf("%d%d",&a,&b);
	int cnt=0,k=1;
	for(int i=a; i<=b; i++){
		cnt++;
		v[k].push_back(i);
		if(cnt==5){
			cnt=0;
			k++;
		}
	}
	for(int i=1; i<=k; i++){
		if((i & 1)==0){
			reverse(v[i].begin(), v[i].end());
		}
		int len=v[i].size();
		for(int j=0; j<len; j++){
			printf("%d ",v[i][j]);
		}
		printf("\n");
	}
	return 0;
}

