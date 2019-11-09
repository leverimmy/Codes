#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAXn 200002
using namespace std;
int n;
int ans,h[MAXn],f[MAXn],g[MAXn];
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
	freopen("gfw.in","r",stdin);
	freopen("gfw.out","w",stdout);
	n=read();
	for(int i=1; i<=n; i++) h[i]=read();
	for(int i=1; i<=n; i++) {
		int x=0;
		f[i]=1;
		if(h[i]>h[i-1]) g[i]=g[i-1]+1;
		else g[i]=1;
		for(int j=1; j<=i-1; j++) if(h[j]<h[i]) f[i]=max(f[i],f[j]+1);
		for(int j=1; j<=i-1; j++) x=max(g[i-j],f[i]),ans=max(ans,x);
	}
	cout<<ans<<endl;
	return 0;
}
/*
9
5 3 4 9 2 8 6 7 1
*/
