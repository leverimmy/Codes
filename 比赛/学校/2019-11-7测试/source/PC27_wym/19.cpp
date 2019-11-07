#include<bits/stdc++.h>
using namespace std;
long long s,t,a,b,c,d;
struct mbr{
	long long amod,bmod,cmod,dmod;
}qwq[10010];
mbr add(mbr x,mbr y){
	return (mbr){(x.amod+y.amod)%a,(x.bmod+y.bmod)%b,(x.cmod+y.cmod)%c,(x.dmod+y.dmod)%d};
}
int main(){
	freopen("19.in","r",stdin);
	freopen("19.out","w",stdout);
	cin>>s>>t>>a>>b>>c>>d;
	qwq[1]=(mbr){1,1,1,1};
	qwq[2]=(mbr){1,1,1,1};
	for(int i=3;i<=t;++i){
		qwq[i]=add(qwq[i-1],qwq[i-2]);
	}
	for(int i=s;i<=t;++i){
		if(qwq[i].amod&&qwq[i].bmod&&qwq[i].cmod&&qwq[i].dmod)
			cout<<i<<' ';
	}
	return 0;
}
