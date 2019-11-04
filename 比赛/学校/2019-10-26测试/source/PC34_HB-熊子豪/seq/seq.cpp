#include<bits/stdc++.h>
using namespace std;
long long a,b;
long long gcd(long long x,long long y){
	if(x==y||y==0){
		return 1;
	}
	return gcd(y,x%y)+x/y;
}
int main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	cin>>a>>b;
	cout<<gcd(a,b);
	return 0;
}
