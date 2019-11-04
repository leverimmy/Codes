#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100001];
int main(){
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		int l,r,p,v;
		cin>>l>>r>>p>>v;
		int ans=0;
		for(int j=l;j<=r;j++){
			ans+=a[j]%p==v;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
