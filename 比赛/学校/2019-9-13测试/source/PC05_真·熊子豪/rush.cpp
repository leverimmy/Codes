#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[100001];
int b[100001];
int main(){
	freopen("rush.in","r",stdin);
	freopen("rush.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=b[i]=1;
	}
	while(m--){
		int u,v;
		cin>>u>>v;
		a[u]=0;
		b[v]=0;
	}
	for(int i=1;i<=n;i++){
		ans+=b[i]+a[i];
	}
	cout<<ans;
	return 0;
}

