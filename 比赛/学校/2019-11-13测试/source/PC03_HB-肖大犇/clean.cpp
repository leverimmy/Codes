#include<bits/stdc++.h>
using namespace std;
const int N=500005;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s; 
}
int n,m;
int a[N];
int main(){
	freopen("clean.in","r",stdin);
	freopen("clean.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++) {
		int l=read(),r=read();
		a[r+1]--;a[l]++;
	} 
	int res=0;
	for(int i=1;i<=n;i++) {
		a[i]+=a[i-1];
		if(!a[i]) res++;
	}
	printf("%d",res);
	return 0;
}
