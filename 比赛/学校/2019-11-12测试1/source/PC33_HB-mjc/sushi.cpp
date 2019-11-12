#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int t;
char s[1000010];
int cnt;
int l[1000010];
int r[1000010];
struct node{
	int len;
	int ind;
}a[1000010];
int sum1[1000010];
int sum2[1000010];
int ans;
struct cmp{
	bool operator () (node a,node b){
		int u=a.ind;int v=b.ind;
		return a.len*min(r[u]-u,u-l[u])<b.len*min(r[v]-v,v-l[v]);
	}
}; 
priority_queue<node ,vector<node> ,cmp > pq;
signed main(){
	freopen("sushi.in","r",stdin);
	freopen("sushi.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		cnt=0;
		scanf("%s",s);
		int len=strlen(s);
		ans=0;
		for(int i=0;i<len;i++){
			int j=i;
			int c=s[i];
			while(1){
				if(s[j]!=c){
					a[++cnt].ind=cnt;
					a[cnt].len=j-i;
					i=j-1;
					break;
				}
				j++;
			}
		}
		for(int i=1;i<=cnt;i++){
			if(i==1){
				l[i]=cnt;
				r[i]=i+1;
			}
			if(i==cnt){
				r[i]=1;
				l[i]=cnt-1;
			}
			else{
				l[i]=i-1;
				r[i]=i+1;
			}
			pq.push(a[i]); 
		} 
		for(int i=1;i<cnt;i++){
			node u=pq.top();
			ans+=u.len*min(r[u.ind]-u.ind,u.ind-l[u.ind]);
			pq.pop();
			int now=u.ind;
			if(r[u.ind]-u.ind>u.ind-l[u.ind]){
				r[u.ind]=r[r[u.ind]];
				l[r[u.ind]]=l[u.ind];
			}
			else{
				l[u.ind]=l[l[u.ind]];
				r[l[u.ind]]=r[u.ind];
			}
		}
		printf("%lld\n",ans);
	}
} 
