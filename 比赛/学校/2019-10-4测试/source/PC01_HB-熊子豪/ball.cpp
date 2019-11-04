#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int c[1000001][2];
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m>>k;
	c[0][0]=c[1][1]=c[0][1]=1;
	for(int i=2;i<=n-k;i++){
		for(int j=1;j<i;j++){
			c[j][i&1]=(c[j-1][!(i&1)]+c[j][!(i&1)])%1000000007;
		}
		c[i][i&1]=1;
	}
	cout<<c[m-1][(n-k)&1];
	return 0;
}

