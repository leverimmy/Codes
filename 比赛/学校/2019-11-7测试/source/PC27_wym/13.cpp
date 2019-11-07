#include<bits/stdc++.h>
using namespace std;
int qwq;
int pri[10010],top;
bool fir=true;
inline bool isprime(int bas){
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
	freopen("13.in","r",stdin);
	freopen("13.out","w",stdout);
	for(int i=2;i<=10010;++i){
		if(isprime(i))
			pri[++top]=i;
	}
	cin>>qwq;
	cout<<qwq<<"=";
	for(int i=1;i<=top;++i){
		if(pri[i]>qwq)
			break;
		int cnt=0;
		while(qwq%pri[i]==0){
			cnt++;
			qwq/=pri[i];
		}
		if(fir&&cnt){
			if(cnt==1)
				cout<<pri[i];
			else
				cout<<pri[i]<<"^"<<cnt;
			fir=false;
		}
		else if(cnt){
			if(cnt==1)
				cout<<"*"<<pri[i];
			else
				cout<<"*"<<pri[i]<<"^"<<cnt;
		}
	}
}
