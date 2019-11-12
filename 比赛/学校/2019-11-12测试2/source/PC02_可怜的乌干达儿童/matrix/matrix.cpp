#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define ll long long

inline int read(){
	char c=getchar();int x=0;
	while (c>'9'||c<'0')c=getchar();
	while ('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x;
}

int a[805][805],b[805][805],c[805][805],n,l1,l2,r1,r2,m;
ll sum[805][805];

void mul(){
	for(register int k=1;k<=n;++k)
	for(register int i=1;i<=n;++i)
	for(register int j=1;j<=n;++j)
		c[i][j]+=a[i][k]*b[k][j];
}

int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n;++i)
	for(register int j=1;j<=n;++j)a[i][j]=read();
	for(register int i=1;i<=n;++i)
	for(register int j=1;j<=n;++j)b[i][j]=read();
	mul();
	for(register int i=1;i<=n;++i)
	for(register int j=1;j<=n;++j)
		sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+c[i][j];
	while (m--){
		l1=read();l2=read();r1=read();r2=read();
		if (l1>r1)std::swap(l1,r1);
		if (l2>r2)std::swap(l2,r2);
		printf("%lld\n",sum[r1][r2]-sum[l1-1][r2]-sum[r1][l2-1]+sum[l1-1][l2-1]);
	}
	return 0;
}
