#include<bits/stdc++.h>
using namespace std;
long long qwq;
inline bool isprime(long long bas){
	if(bas==2)
		return true;
	long long lim=sqrt(bas)+1;
	for(int i=2;i<=lim;++i){
		if(!(bas%i))
			return false;
	}
	return true;
}
int main(){
	freopen("5.in","r",stdin);
	freopen("5.out","w",stdout);
	cin>>qwq;
	while(1){
		qwq++;
		if(isprime(qwq)){
			cout<<qwq;
			return 0;
		}
	}
}
