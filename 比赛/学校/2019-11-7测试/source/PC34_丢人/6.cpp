#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int main(){
	freopen("6.in","r",stdin);
	freopen("6.out","w",stdout);
	s="";
	int n;cin>>n;
	for(int i=1;i<=n;i++) s=s+(char)('A'+i-1)+s;
	cout<<s;
	return 0;
}
