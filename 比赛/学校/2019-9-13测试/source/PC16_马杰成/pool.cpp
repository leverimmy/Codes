#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int maxm=200010;
const int maxn=100010;
struct node{
	int next;
	int to;
}e[maxm];
int cnt,head[maxn];
void add(int u,int v){
	e[++cnt].next=head[u];
	e[cnt].to=v;
	head[u]=cnt;
} 
int t,k,n;
int l[maxn];
int r[maxn];
int du[maxn];
struct qq{
	int ind;
	int num;
}f[maxn];
struct cmp{
	bool operator ()(qq a ,qq b){
		return a.ind>b.ind;
	}
};
int sum[maxn];
signed main(){
	freopen("pool.in","r",stdin);
	freopen("pool.out","w",stdout);
	scanf("%lld%lld",&t,&k);
	for(int i=1;i<=t;i++){
		scanf("%lld%lld",&l[i],&r[i]);
		n=max(r[i],n);
	}
	for(int i=0;i<=n;i++){
		if(i+1<=n){ 
			add(i,i+1);
			du[i+1]++;
		}
		if(i+k<=n){
			add(i,i+k);
			du[i+k]++;
		}
	}
	priority_queue<qq,vector<qq>,cmp> pq;
	f[0].num=1;
	pq.push(f[0]);
	for(int i=1;i<=n;i++)
		f[i].ind=i;
	while(!pq.empty()){
		qq q=pq.top();
		int u=q.ind;
	//	cout<<u<<endl;
		pq.pop();
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			f[v].num=(f[v].num+f[u].num)%mod;	
			du[v]--;
			if(du[v]==0){
				pq.push(f[v]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i>=k*2){
			f[i].num-=(i-2*k+1);
		}
	} 
//	for(int i=1;i<=n;i++){
//		cout<<f[i].ind<<" "<<f[i].num<<endl;
//	}
	for(int i=1;i<=n;i++){
		sum[i]=(sum[i-1]+f[i].num)%mod;
	}
	for(int i=1;i<=t;i++){
		printf("%lld\n",((sum[r[i]]-sum[l[i]-1])+mod)%mod);
	}
}
