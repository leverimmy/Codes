#include<iostream>
#include<cmath>
#define MAXn 10000005
#define ll long long
using namespace std;
ll a,b,cnt1,cnt;
//int book[MAXn];
int main() {
	freopen("sep.in","r",stdin);
	freopen("sep.out","w",stdout);
	cin>>a>>b;

	ll kmin=min(a,b);
	ll kmax=max(a,b);
	while(1) {
		ll x=kmax/kmin;
		ll y=kmax%kmin;
		cnt1+=x;
//		cout<<x<<" ";
		kmax=kmin-y;
		kmin=y;
		if(y!=0) cnt1++;
//		cout<<kmax<<" "<<kmin<<" ";
		if(kmin>kmax) swap(kmin,kmax);
		if(y==0) break;
	}
//	cout<<endl;
	cout<<cnt1+1<<endl;

//	book[a]=book[b]=1;
//	ll c;
//	while(c) {
//		c=abs(a-b);
//		if(book[c]==0) {
//			cnt++;
//			cout<<c<<" ";
//			book[c]=1;
//		}
//		a=b;
//		b=c;
//		if(c==0) break;
//	}
//	cout<<endl;
//	cout<<cnt+2<<endl;
	return 0;
}
