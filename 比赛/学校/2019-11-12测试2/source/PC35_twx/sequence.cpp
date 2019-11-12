#include <bits/stdc++.h>

using namespace std;
const int N = 10010;
int n,k;
int a[N],s[N];
priority_queue<int, vector<int>, greater<int> > q;
int main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	for(int l=1; l<=n; l++){
		for(int r=l; r<=n; r++){
			q.push(s[r]-s[l-1]);
			if(q.size()>k){
				q.pop();
			}
//			printf("l=%d r=%d %d\n",l,r,s[r]-s[l-1]);
		}
	}
	printf("%d\n",q.top());
	return 0;
}

