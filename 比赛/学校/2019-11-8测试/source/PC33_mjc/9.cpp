#include<bits/stdc++.h>
using namespace std;
priority_queue<int > pq;
int n;
int main(){
	freopen("9.in","r",stdin);
	freopen("9.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int op;
		scanf("%d",&op);
		if(op==1){
			int x;
			scanf("%d",&x);
			pq.push(x);
		}
		else{
			int u=pq.top();
			printf("%d\n",u);
			pq.pop();
		}
	}
}
