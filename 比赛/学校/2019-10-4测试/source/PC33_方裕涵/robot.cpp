#include<iostream>
#include<cstdio>
#include<cstdlib>
#define MAXn 50002
using namespace std;
int n,m1,m2,cnt1,cnt2,ans1,ans2,maxl,mint,h[MAXn],t;
struct note {
	int u,v;
} a[MAXn];
int main() {
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1; i<=n; i++) cin>>a[i].u;
	for(int i=1; i<=n; i++) {
		maxl=0;
		for(int j=1; j<=i-1; j++)
			if(a[j].u>=a[i].u&&a[j].v>maxl)
				maxl=a[j].v;
			else ans1+=m1;
		a[i].v=maxl+1;
		if(cnt1<a[i].v) cnt1=a[i].v;
	}
	for(int i=1; i<=n; i++) {
		maxl=0;
		for(int j=1; j<=i-1; j++)
			if(a[j].u<=a[i].u&&a[j].v>maxl)
				maxl=a[j].v;
			else ans2+=m2;
		a[i].v=maxl+1;
		if(cnt2<a[i].v) cnt2=a[i].v;
	}
	cout<<cnt1<<" "<<cnt2<<endl;
	cout<<ans1<<" "<<ans2<<endl;
	cout<<min(ans1,ans2);
	return 0;
}
/*
5 2 3
1 2 3 5 4
*/
