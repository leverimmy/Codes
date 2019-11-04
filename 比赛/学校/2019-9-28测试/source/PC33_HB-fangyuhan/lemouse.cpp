#include<iostream>
#include<cstdio>
#include<cstdlib>
#define ll long long
#define MAXn 1002
#define MAXm 1002
using namespace std;
int n,m,a[MAXn][MAXm],b[MAXn][MAXm];
int main() {
	freopen("lemouse.in","r",stdin);
	freopen("lemouse.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++) {
			int x;
			cin>>x;
			a[i][j]=x;
//			b[i][j]+=x;
			b[i-1][j]+=x;
//			b[i+1][j]+=x;
//			b[i][j+1]+=x;
			b[i][j-1]+=x;
		}
	cout<<endl;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++)
			cout<<b[i][j]<<" ";
		cout<<endl;
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++) {
			if(i==1) b[i][j]+=b[i][j-1];
			else if(j==1) b[i][j]+=b[i-1][j];
			else b[i][j]+=min(b[i-1][j],b[i][j-1]);
		}
	cout<<endl;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++)
			cout<<b[i][j]<<" ";
		cout<<endl;
	}
	int ans=max(b[n-1][m],b[n][m-1]);
	cout<<ans;
	return 0;
}
/*
3 9
0 0 1 0 0 0 0 0 1
1 1 1 1 1 1 0 1 0
1 0 0 1 0 0 1 0 0
*/

