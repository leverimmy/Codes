#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
int n,m;
int a[N];
int f[325][N];
int main(){
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=0;i<=320;i++){
		for(int j=n;j>=1;j--)
			if(j+a[j]+i>n) f[i][j]=1;
			else f[i][j]=f[i][j+a[j]+i]+1;
	}
	m=read();
	for(int i=1;i<=m;i++){
		int p=read(),k=read();
		if(k<=320) printf("%d\n",f[k][p]);
		else {
			int ans=0;
			while(p<=n) p=p+a[p]+k,ans++;
			printf("%d\n",ans);
		}
	}
	return 0;
}
