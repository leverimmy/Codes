#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("12.in","r",stdin);
	freopen("12.out","w",stdout);
	int n;cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++) if(n%i==0) ans++;
	cout<<ans;
	return 0;
}
