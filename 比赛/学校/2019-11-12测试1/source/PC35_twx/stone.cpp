#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4000010;
int read(){
	char ch=getchar();
	int res=0;
	while(ch<'0' || ch>'9'){
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res;
}
int n,ans;
priority_queue<int, vector<int>, greater<int> > q;
signed main(){
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
	n=read();
	for(int i=1; i<=n; i++){
		int num;
		num=read();
		q.push(num);
	}
	while(q.size()!=1){
		int tmp=q.top();
		q.pop();
		ans+=tmp*q.top();
		int tmp2=q.top();
		q.pop();
		q.push(tmp+tmp2);
	}
	printf("%lld\n",ans);
	return 0;
}

