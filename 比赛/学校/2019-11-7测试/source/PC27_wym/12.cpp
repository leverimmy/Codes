#include<bits/stdc++.h>
using namespace std;
long long qwq;
int main(){
	freopen("12.in","r",stdin);
	freopen("12.out","w",stdout);
	cin>>qwq;
	long long ans=0;
	for(int i=1;i<=qwq;++i){
		if(qwq%i==0)
			++ans;
	}
	cout<<ans;
	return 0;
}
