#include<iostream>
#include<cstdio>
#include<cstdlib>
#define ll long long
#define MAXn 100002
#define MAXm 100002
using namespace std;
int n,m,cnt,a[MAXn],b[MAXm];
int main() {
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	cin>>m;
	for(int i=1; i<=m; i++) {
		int p,k;
		cnt=0;
		cin>>p>>k;
		while(p<=n) {
			p=p+a[p]+k;
			cnt++;
		}
		b[i]=cnt;
	}
	for(int i=1; i<=m; i++) {
		cout<<b[i]<<endl;
	}
	return 0;
}
/*
put in:

3
1 1 1
3
1 1
2 1
3 1

*/
/*
ans:
2
1
1
*/
