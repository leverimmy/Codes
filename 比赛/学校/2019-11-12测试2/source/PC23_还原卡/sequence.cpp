#include<bits/stdc++.h>
#define int long long
using namespace std;
priority_queue<int > pq;
int sum[100010],n,k;
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%lld",&x);
		sum[i]=sum[i-1]+x;
	}
	 for(int i=1;i<=n;i++){
	 	for(int j=0;j<i;j++){
	 		pq.push(sum[i]-sum[j]);
		 }
	 }
	 int c=0;
	 while(!pq.empty()){
	 	c++;
	 	if(c==k){
			printf("%lld\n",pq.top());
		}
		pq.pop();
	 }
}
