#include<iostream>
#include<cstdio>
#include<cstdlib>
#define ll long long
#define MAXn 100002
using namespace std;
ll n,dp[MAXn],ans;
struct node {
	ll x,y,z;
} a[MAXn];
inline int read() {
	int sum=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) sum=(sum<<1)+(sum<<3)+(ch^'0'),ch=getchar();
	return sum*f;
}
int main() {
	freopen("function.in","r",stdin);
	freopen("function.out","w",stdout);
	n=read();
	for(int i=1; i<=n; i++) a[i].x=read(),a[i].y=read(),a[i].z=i;
	for(int i=1; i<=n; i++) {
		dp[i]=1;
		for(int j=1; j<=i-1; j++) if(a[j].y<a[i].y&&a[j].x<a[i].x) dp[i]=max(dp[i],dp[j]+1);
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}
/*
8
1 3
3 2
1 1
4 5
6 3
9 9
8 7
7 6
*/
