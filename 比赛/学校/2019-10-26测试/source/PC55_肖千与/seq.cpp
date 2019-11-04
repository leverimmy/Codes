#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;
inline ll gcd(ll x,ll y){
	if(!y) return 1;
	return x/y+gcd(y,x%y);
}
int main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout); 
	cin>>a>>b;
	cout<<gcd(a,b);
	return 0;
} 
