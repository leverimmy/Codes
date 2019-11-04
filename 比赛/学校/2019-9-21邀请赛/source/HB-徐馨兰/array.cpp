#include <bits/stdc++.h>
using namespace std;

int n,m,a[100010],cnt[100010];
long long b[100010];

inline long long read()
{
	int res=0,f=1;char ch=getchar();
	while(ch<'0' || '9'<ch){if(ch=='-')f=-1; ch=getchar();}
	while('0'<=ch && ch<='9')res=res*10+ch-'0',ch=getchar();
	return res*f;
}

int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		long long p=read(),k=read(),ans=0;
		while(p<=n) p=p+a[p]+k,ans++;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
3
1 1 1
3
1 1
2 1
3 1
*/
