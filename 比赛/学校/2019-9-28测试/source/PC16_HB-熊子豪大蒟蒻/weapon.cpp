//±©Á¦Ï¹¸ã pre 60
#include<bits/stdc++.h>
using namespace std;
int n,f;
int a[100001];
int ans;
int main(){
	freopen("weapon.in","r",stdin);
	freopen("weapon.out","w",stdout);
	cin>>n>>f;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int len=1;2*len+f-1<=n;len++){
		int com=0;
		for(int i=1;i+len+f<=n;i++){
			if(a[i]==a[i+len+f]){
				com++;
				if(com>=len){
					ans++;
				}
			}
			else com=0;
		}
	}
	cout<<ans;
	return 0;
}

