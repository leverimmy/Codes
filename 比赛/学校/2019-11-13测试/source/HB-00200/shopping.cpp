#include<bits/stdc++.h>
#define int long long
using namespace std;
int n; 
int ans[20];
int vis[20];
int bk[200000];
int mjc,m;
int a[100010]; 
int l[100010],r[100010];
void check(){
	int as=0;
	memset(bk,0,sizeof(bk));
	for(int i=1;i<=m;i++){
		int res=0;
		for(int j=l[ans[i]];j<=r[ans[i]];j++){
			if(bk[j]){
				as+=res*res;		
				res=0;
			}
			else{
				bk[j]=1;
				res+=a[j];
				if(j==r[ans[i]]){
					as+=res*res;
				}
			}
		}
	}
	mjc=max(mjc,as);
	return;
}
void dfs(int step){
	if(step==m){
		check();
		return;
	}	
	for(int i=1;i<=m;i++){
		if(!vis[i]){
			vis[i]=1;
			step++;
			ans[step]=i;
			dfs(step);
			ans[step]=0;
			step--;
			vis[i]=0;
		}
	}
}
int sum[1000010]; 
struct node{
	int l,r;
}in[1000010];
bool cmp(node a,node b){
	return (sum[a.r]-sum[a.l-1])<(sum[b.r]-sum[b.l-1]);
}
signed main(){
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=m;i++){
		scanf("%lld%lld",&l[i],&r[i]);
		in[i].l=l[i];in[i].r=r[i];
	}
	if(n<=10){ 
		dfs(0);
		printf("%lld\n",mjc);
	}
	else{
		sort(in+1,in+m+1,cmp);
		int as=0;
		for(int i=1;i<=m;i++){
			int res=0;
			for(int j=l[ans[i]];j<=r[ans[i]];j++){
				if(bk[j]){
					as+=res*res;		
					res=0;
				}
				else{
					bk[j]=1;
					res+=a[j];
					if(j==r[ans[i]]){
						as+=res*res;
					}
				}
			}
		}
		printf("%lld\n",ans);		
	}
}
