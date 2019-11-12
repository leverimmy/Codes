#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int read(){
	int f=1,ans=0;
	char ch=getchar();
	while(ch>'9' || ch<'0'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch<='9' && ch>='0'){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*f;
} 
int n;
struct cmp{
	bool operator()(int a,int b){
		return a>b;
	}
}; 
int cnt;
int ans=0;
priority_queue<int > pq;
signed main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	scanf("%lld",&n);
	if(n==1){
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;i++){
		int x;
		x=read();
		pq.push(x);
	}
	while(1){
		int u=pq.top();
		pq.pop();
		int v=pq.top();
		pq.pop();
		cnt++;
		ans+=u*v;
		pq.push(v+u);
		if(cnt==n-1){
			break;
		}
	}
	printf("%lld\n",ans);
}
