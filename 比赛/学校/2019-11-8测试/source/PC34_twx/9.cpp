#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int q;
priority_queue<int> Q;
int main(){
	freopen("9.in", "r", stdin);
	freopen("9.out", "w", stdout);
	scanf("%d",&q);
	for(int i=1; i<=q; i++){
		int opt;
		scanf("%d",&opt);
		if(opt==1){
			int k;
			scanf("%d",&k);
			Q.push(k);
		}
		else if(opt==2){
			if(Q.empty()){
				puts("-1");
			}
			else{
				printf("%d\n",Q.top());
				Q.pop();
			}
		}
	}
	return 0;
}

