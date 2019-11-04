#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int N = 100010;
int n,l,ans;
struct node{
	int t,p;
}a[N];
bool operator < (node x,node y){
	if(x.t==y.t){
		return x.p < y.p;
	}
	return x.t>y.t;
}
priority_queue<int> q;
signed main(){
	freopen("firework.in", "r", stdin);
	freopen("firework.out", "w", stdout);
	scanf("%lld%lld",&n,&l);
	for(int i=1; i<=n; i++){
		scanf("%lld%lld",&a[i].t,&a[i].p);
		ans+=a[i].p;
	}
	sort(a+1, a+1+n);
	for(int i=1; i<=n; i++){
		q.push(-a[i].p);
		q.push(-a[i].p);
		ans+=q.top();
		q.pop();
	}
	printf("%lld\n",ans);
	return 0;
}

