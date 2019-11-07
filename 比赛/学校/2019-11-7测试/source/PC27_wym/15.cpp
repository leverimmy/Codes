#include<bits/stdc++.h>
using namespace std;
long long n;
struct mbr{
	int val,pos;
	const bool operator <(const mbr &b)const{
		return val<b.val;
	}
}a[10010];
int main(){
	freopen("15.in","r",stdin);
	freopen("15.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i].val,a[i].pos=i-1;
	sort(a+1,a+n+1);
	cout<<a[n].val<<' '<<a[n].pos;
	return 0;
}
