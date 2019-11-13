#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define ll long long
ll lim=1e12,list[15005],arr[400005],l,r;
std::set<ll>table;
int tl=0,tl2=0,t;
void dfs(ll x,int p){
	if (x>lim)return;
	if (p==0)list[++tl]=x;
	dfs(x*10+4,p-1);dfs(x*10+7,p-1);
}

void dfs2(ll x,int p){
	if (x>lim)return;
	if (x!=1){
		if (table.count(x))return;
		table.insert(x);
	}
	for(int i=1;i<=tl;++i){
		if (x*list[i]>lim)break;
		dfs2(x*list[i],i);
	}
}

int calc(ll x){
	int l=0,r=tl2,ans=0;
	while (l<=r){
		int mid=(l+r)>>1;
		if (arr[mid]<=x){ans=mid;l=mid+1;}
		else r=mid-1;
	}return ans;
}

int main(){
	freopen("prd.in","r",stdin);
	freopen("prd.out","w",stdout);
	for(int i=1;i<=12;++i)
		dfs(0,i);
	dfs2(1,1);
	std::set<ll>::iterator it;
	for(it=table.begin();it!=table.end();++it)
		arr[++tl2]=*it;
	std::sort(arr+1,arr+tl2+1);
	scanf("%d",&t);
	while (t--){
		scanf("%lld%lld",&l,&r);
		printf("%d\n",calc(r)-calc(l-1));
	}
	return 0;
}





